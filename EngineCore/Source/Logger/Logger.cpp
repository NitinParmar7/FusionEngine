#include "pch.h"
#include "Logger.h"
#include <format>

Logger::~Logger()
{
	if (fileStream.is_open())
	{
		fileStream.close();
	}
}

void Logger::SetLogLevel(LogLevel level)
{
	currentLevel = level;
}

void Logger::Log(LogLevel level, std::string_view message)
{
#ifdef ENABLE_LOGGING
	if (level < currentLevel)
	{
		return;
	}

	std::lock_guard<std::mutex> lock(mutex);
	std::string timestamp = GetTimeStamp();

	std::string logMessage = std::format("[{}] {}: {}\n", timestamp, LogLevelToString(level), message);;

	std::cout << logMessage;

	if (fileStream.is_open())
	{
		fileStream << logMessage;
		fileStream.flush();
	}
#endif // !ENABLE_LOGGING

}

void Logger::SetOutputFile(std::string_view filename)
{
	std::lock_guard<std::mutex> lock(mutex);
	if (fileStream.is_open())
	{
		fileStream.close();
	}
	fileStream.open(filename.data(), std::ios::out | std::ios::app);
}

std::string Logger::GetTimeStamp()
{
	auto now = std::chrono::system_clock::now();
	auto now_time_t = std::chrono::system_clock::to_time_t(now);
	std::tm localTime{};
#if defined(_MSC_VER) || defined(__MINGW32__)
	localtime_s(&localTime, &now_time_t);
#else
	localtime_s(&now_time_t, &localtime_s);
#endif // defined(_MSC_VER) || defined(__MINGW32__)

	char buffer[64];
	if (std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localTime))
		return std::string(buffer, std::strlen(buffer));
	else
		return "unknown time";
}

constexpr std::string_view Logger::LogLevelToString(LogLevel level) const
{
	switch (level)
	{
		case LogLevel::Debug: return "DEBUG";
		case LogLevel::Info: return "INFO";
		case LogLevel::Warning: return "WARN";
		case LogLevel::Error: return "ERROR";
		default: return "UNKNOWN";
	}
}
