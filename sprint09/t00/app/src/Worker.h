#pragma once

#include <thread>

class Worker {
public:
    Worker() = default;
    ~Worker() {
        joinThread();
    };
    template <typename Function, class... Args>
    void startWorker(Function &&func, Args &&... args) {
        m_thread = new std::thread(func, args...);
    };
    void joinThread() {
        if (m_thread != nullptr) {
            m_thread->join();
            delete m_thread;
            m_thread = nullptr;
        }
    };

private:
    std::thread *m_thread{nullptr};
};


