#pragma once
#include <mutex>

class MultithreadedClass {
public:
    MultithreadedClass() = default;
    ~MultithreadedClass() = default;
    int getInt() const {
        return m_int;
    };
    void add(int addValue) {
         std::lock_guard<std::mutex> guard(m_mutex);
         m_int = m_int + addValue;
    }; 
    void subtract(int subtractValue) {
        std::lock_guard<std::mutex> guard(m_mutex);
        m_int = m_int - subtractValue;
    };
private:
    int m_int{0};
    std::mutex m_mutex;
};
