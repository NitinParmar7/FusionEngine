#include "JobSystem.h"

JobSystem::JobSystem(size_t numThreads) {
	for (size_t i = 0; i < numThreads; ++i)
	{
		workers.emplace_back([this](std::stop_token st) {worker(st); });
	}
}

JobSystem::~JobSystem() {
	done = true;
	jobCV.notify_all();
}

void JobSystem::worker(std::stop_token stopToken) {
	while (!stopToken.stop_requested() && !done)
	{
		std::function<void()> job;
		{
			std::unique_lock lock(jobMutex);
			jobCV.wait(lock, [this, &stopToken]() {
				return !jobs.empty() || stopToken.stop_requested() || done;
			});
			if (jobs.empty())
				continue;
			job = std::move(jobs.front());
			jobs.pop();
		}
		if (job)
			job();
	}
}
