#pragma once

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string_view>
#include <string>
#include <mutex>
#include <fstream>



#ifndef ENABLE_LOGGING
#define ENABLE_LOGGING
#endif // 


// Log levels for controlling verbosity
enum class LogLevel
{
	Debug,
	Info,
	Warning,
	Error
};


class Logger
{
public:

	// retrieve the singleton instance
	static Logger& Instance() {
		static Logger instance;
		return instance;
	}

	void SetLogLevel(LogLevel level);

	void Log(LogLevel level, std::string_view message);

	void SetOutputFile(std::string_view filename);


private:

	Logger() : currentLevel(LogLevel::Debug) {}

	~Logger();

	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;

	std::string GetTimeStamp();

	constexpr std::string_view LogLevelToString(LogLevel level) const;

	LogLevel currentLevel;
	std::mutex mutex;
	std::ofstream fileStream;

};

#endif // !LOGGER_H

#ifdef ENABLE_LOGGING
#define LOG_DEBUG(msg) Logger::Instance().Log(LogLevel::Debug, msg);
#define LOG_INFO(msg) Logger::Instance().Log(LogLevel::Info, msg);
#define LOG_WARN(msg) Logger::Instance().Log(LogLevel::Warning, msg);
#define LOG_ERROR(msg) Logger::Instance().Log(LogLevel::Error, msg);
#else
#define LOG_DEBUG(msg) ((void)0)
#define LOG_INFO(msg)  ((void)0)
#define LOG_WARN(msg)  ((void)0)
#define LOG_ERROR(msg) ((void)0)
#endif // ENABLE_LOGGING


