#pragma once
#include <thread>
#include <future>
#include <queue>
#include "EngineAPI.h"


// A basic job system (thread pool) using C++20 features.
class ENGINE_API JobSystem {
public:

	// Construct with a given number of threads; defaults to hardware concurrency.
	JobSystem(size_t numThreads = std::thread::hardware_concurrency());
	~JobSystem();

	// Submit a job and get a future to its < result.
	template<typename Func, typename... Args>
	auto submit(Func&& func, Args&&... args) -> std::future<decltype(func(args...))>;


private:

	// The worker function executed by each thread.
	void worker(std::stop_token stopToken);

	std::vector<std::jthread> workers;
	std::queue<std::function<void()>> jobs;
	std::mutex jobMutex;
	std::condition_variable_any jobCV;
	std::atomic<bool> done{ false };
};


#include "JobSystem.inl"