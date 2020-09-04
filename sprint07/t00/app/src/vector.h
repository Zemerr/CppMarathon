#pragma once

#include <iostream>

namespace CBL {

template <class T>
class Vector {
public:
    using iterator = T *;

    Vector();
    explicit Vector(size_t size) : m_size(size), m_capacity(size) {
        if (size > 0)
            m_buffer = new T[size];
    };
    Vector(size_t size, const T &value) : Vector(size) {
        if (size > 0) {
            for (int i = 0; i < m_size; i++)
                m_buffer[i] = value;
        }
    };
    Vector(iterator first, iterator last) : Vector(std::distance(first, last)) {
        int j = 0;
        for (auto i = first; i != last; i++) {
            m_buffer[j] = *i;
            j++;
        }
    };
    Vector(const std::initializer_list<T> &lst) : Vector(lst.size()) {
        int j = 0;
        for (auto i = lst.begin(); i != lst.end(); i++) {
            m_buffer[j] = *i;
            j++;
        }
    };
    Vector(const Vector<T> &other) {
        m_size = other.size();
        m_capacity = other.capacity();
        m_buffer = new T[m_size];
        std::copy(other.begin(), other.end(), m_buffer);
    }
    ~Vector() {
        delete[] m_buffer;
    };

    Vector<T> &operator=(const Vector<T> &other) {
        delete[] m_buffer;
        m_size = other.size();
        m_capacity = other.capacity();
        m_buffer = new T(m_size);
        for (int i = 0; i < m_size; i++) {
            m_buffer[i] = other[i];
        }
        return *this;
    };
    bool operator==(const Vector<T> &other) const {
        int j = 0;
        auto i = other.size();
        if (i != m_size)
            return false;
        for (auto i = 0; i < other.size() && j < m_size; i++, j++) {
            if (m_buffer[j] != other[i])
                return false;
        }
        return true;
    };
    bool operator!=(const Vector<T> &other) const;
    bool operator<(const Vector<T> &other) const;
    bool operator>(const Vector<T> &other) const;
    bool operator<=(const Vector<T> &other) const;
    bool operator>=(const Vector<T> &other) const;
    // iterators
    iterator begin() const {
        return m_buffer;
    };
    iterator end() const {
        return m_buffer + m_size;
    };
    // capacity
    size_t size() const {
        return m_size;
    };
    size_t capacity() const {
        return m_capacity;
    };
    bool isEmpty() const;
    void resize(size_t size, const T &value = T()) {
        if (size > m_size) {
            T *buf = new T[size];
            for (int i = 0; i < m_size; i++)
                buf[i] = m_buffer[i];
            for (int i = size - m_size; i < size; i++)
                buf[i] = value;
            delete[] m_buffer;
            m_buffer = buf;
            m_size = size;
            m_capacity = m_size;
        } else {
            m_size = size;
        }
    };
    void reserve(size_t size) {
        if (size > m_capacity) {
            T *buf = new T[size];
            for (int i = 0; i < m_size; i++)
                buf[i] = m_buffer[i];
            delete[] m_buffer;
            m_buffer = buf;
            m_capacity = m_size;
        }
    };
    // element access
    T &operator[](size_t index) const {
        return *(m_buffer + index);
    };
    T &at(size_t index) const {
        if (index >= m_size)
            throw std::out_of_range("KYDA LEZISH");
        else
            return m_buffer[index];
    };
    T *data() const {
        return m_buffer;
    };
    // modifiers
    void push_back(const T &value) {
        if (m_size == m_capacity) {
            m_capacity = m_capacity * 2;
            T *buf = new T[m_capacity];
            for (int i = 0; i < m_size; i++)
                buf[i] = m_buffer[i];
            buf[m_size] = value;
            delete[] m_buffer;
            m_buffer = buf;
            m_size += 1;
        }
        else if (m_size < m_capacity) {
            m_buffer[m_size] = value;
            m_size += 1;

        }

    };
    void pop_back() {
        if (m_size != 0)
            m_size -= 1;
    };
    iterator insert(iterator pos, const T &value) {
        size_t size = 0;
        for (auto i = (*this).begin(); i != pos; i++)
            size++;
        // std::cout << (pos - (*this).begin()) << " LLLLL\n";
        
        if (size < m_capacity) {
            if (size < m_size) {
                    int count = m_size;
                    auto i = (*this).end() - 1;
                    for ( ; i != pos - 1; i--) {
                        m_buffer[count] = *i;
                        count--;
                    }
                    m_buffer[count] = value;
                    m_size++;
                    return  &(m_buffer[count]);
            }
            else {
                m_size = size;
                return  &(m_buffer[m_size]);
            }
        }
        else {
            T *buf = new T[size + 1];
            int i = 0;
                for (; i < m_size; i++)
                    buf[i] = m_buffer[i];
                buf[size] = value;
                delete[] m_buffer;
                m_buffer = buf;
                 m_size = size + 1 ;
                 m_capacity = m_size;
                 return  &(m_buffer[m_size]);
        }
        return  m_buffer;

    };
    iterator erase(iterator pos);
    iterator erase(iterator first, iterator last);
    void clear();
private:
    size_t m_size{0};
    size_t m_capacity{0};
    T *m_buffer{nullptr};
};
} // namespace CBL
