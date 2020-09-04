#pragma once

#include <thread>
#include <vector>

class Worker {
public:
    Worker() = default;
    ~Worker() {
        joinAllThreads();
    };
    template <typename Function, class... Args>
    void startNewThread(Function&& func, Args&&...args) {
        m_workerThreads.emplace_back(std::thread(func, args...));
    };
    void joinAllThreads() {
        for (auto& i : m_workerThreads)
            if (i.joinable())
                i.join();
    }; 
    
private:
    std::vector<std::thread> m_workerThreads;
};


