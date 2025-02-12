#pragma once

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string_view>
#include <string>
#include <mutex>



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

	void SetLogLevel(LogLevel level)
	{
		currentLevel = level;
	}

	void Log(LogLevel level, std::string_view message)
	{
#ifdef ENABLE_LOGGING
		if (level < currentLevel) {
			return;
		}

		std::lock_guard<std::mutex> lock(mutex);
#endif // ENABLE_LOGGING

	}


private:

	LogLevel currentLevel;
	std::mutex mutex;
};

#endif // !LOGGER_H

