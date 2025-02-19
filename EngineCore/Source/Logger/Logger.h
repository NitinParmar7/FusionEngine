#pragma once

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string_view>
#include <string>
#include <mutex>
#include <fstream>
#include <format>
#include "EngineAPI.h"



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

	// Templated function to format a message and log it.
	template<typename... Args>
	void LogFormatted(LogLevel level, std::format_string<Args...> formatStr, Args&&... args) {
		std::string message = std::format(formatStr, std::forward<Args>(args)...);
		Log(level, message);
	}


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
#define LOG_DEBUG(...) Logger::Instance().LogFormatted(LogLevel::Debug, __VA_ARGS__);
#define LOG_INFO(...) Logger::Instance().LogFormatted(LogLevel::Info, __VA_ARGS__);
#define LOG_WARN(...) Logger::Instance().LogFormatted(LogLevel::Warning, __VA_ARGS__);
#define LOG_ERROR(...) Logger::Instance().LogFormatted(LogLevel::Error, __VA_ARGS__);
#else
#define LOG_DEBUG(msg) ((void)0)
#define LOG_INFO(msg)  ((void)0)
#define LOG_WARN(msg)  ((void)0)
#define LOG_ERROR(msg) ((void)0)
#endif // ENABLE_LOGGING


