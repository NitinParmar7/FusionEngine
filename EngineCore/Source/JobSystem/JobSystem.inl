#pragma once
#include "JobSystem.h"

template<typename Func, typename... Args>
auto JobSystem::submit(Func&& func, Args&&... args) -> std::future<decltype(func(args...))> {
	using ReturnType = decltype(func(args...));
	auto taskPtr = std::make_shared<std::packaged_task<ReturnType()>>(
		std::bind(std::forward<Func>(func), std::forward<Args>(args)...)
	);
	std::future<ReturnType> res = taskPtr->get_future();
	{
		std::lock_guard clock(jobMutex);
		jobs.emplace([taskPtr]() { (*taskPtr)(); });
	}
	jobCV.notify_one();
	return res;
}
