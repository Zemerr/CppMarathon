#pragma once

#include <iostream>
#include <iterator>



template <typename T> 
bool IsInRange(const T& val, const T& from, const T& to) {
    if (val >= from && val <= to)
        return true;
    else
        return false;
}

template <typename T> 
bool IsInRange(const T& val, const std::pair<const T&, const T&>& minmax) {
    if (val >= minmax.first && val <= minmax.second)
        return true;
    else
        return false;
}

template <typename T> 
bool IsInsideRange(const T& val, const T& from, const T& to) {
    if (val > from && val < to)
        return true;
    else
        return false;
}

template <typename T> 
bool IsInsideRange(const T& val, const std::pair<const T&, const T&>&minmax) {
    if (val > minmax.first && val < minmax.second)
        return true;
    else
        return false;
}

template<class T, class U = T>
bool Modify(T& obj, U&& new_value) {
    if (obj == new_value)
        return false;
    obj = new_value;
    return true;
}

template <class Collection, class T>
void RemoveAll(Collection& c, const T& value) {
    auto a = std::remove(c.begin(), c.end(), value);
    c = {std::begin(c), a};
}

template<class Collection, class Pred>
void RemoveAllIf(Collection& c, Pred&& predicate) {
    auto a = std::remove_if(c.begin(), c.end(), predicate);
    c = {std::begin(c), a};
}

template<class Collection, class T>
auto Find(Collection& c, const T& value) {
    auto it = find(c.begin(), c.end(), value);
    return it;
}

template<class Collection, class Pred>
auto FindIf(Collection& c, Pred&& predicate) {
    auto it = find_if(c.begin(), c.end(), predicate);
    return it;
}

template<class Collection, class T>
bool Contains(const Collection& c, const T& value) {
    auto it = find(c.begin(), c.end(), value);
    if (it != c.end())
        return true;
    else
        return false;
}

template<class Collection, class Pred>
bool ContainsIf(const Collection& c, Pred&& predicate) {
        auto it = find_if(c.begin(), c.end(), predicate);
    if (it != c.end())
        return true;
    else
        return false;
}

template<class Collection, class Pred>
int CountIf(const Collection& c, Pred&& predicate) {
    int count = std::count_if(c.begin(), c.end(), predicate);
    return count;
}


template<class T>
const auto& Min(const T& arg) {
    return arg;
}

template<class T, class...Args>
const auto& Min(const T& arg, const Args&... args) {
    if (arg < Min(args...))
        return arg;
    else 
        return Min(args...);
}

template<class T>
const auto& Max(const T& arg) {
    return arg;
}

template<class T, class...Args>
const auto& Max(const T& arg, const Args&... args) {
    if (arg > Max(args...))
        return arg;
    else
        return Max(args...);
}


template<class Collection>
auto MaxElement(const Collection& c) {
    if (c.begin() == c.end())
        return c.begin();
    //auto iter = c.begin();
    typename Collection::const_iterator iter = c.begin();
    for (auto i = c.begin(); i != c.end(); i++) {
        if (*i > *iter)
            iter = i;
    }
    return iter;
}

template<class Collection>
auto MinElement(const Collection& c) {
    if (c.begin() == c.end())
        return c.begin();
    auto iter = c.begin();
    for (auto i = c.begin(); i != c.end(); i++) {
        if (*i <= *iter)
            iter = i;
    }
    return iter;
}

template<class Collection, class Comp>
auto MaxElement(const Collection& c, Comp&& comparator) {
    if (c.begin() == c.end())
        return c.begin();
    //auto iter = c.begin();
    typename Collection::const_iterator iter = c.begin();
    for (auto i = c.begin(); i != c.end(); i++) {
        if (comparator(*i, *iter))
            iter = i;
    }
    return iter;
}

template<class Collection, class Comp>
auto MinElement(const Collection& c, Comp&& comparator) {
    if (c.begin() == c.end())
        return c.begin();
    auto iter = c.begin();
    for (auto i = c.begin(); i != c.end(); i++) {
        if (comparator(*i, *iter))
            iter = i;
    }
    return iter;
}

template<class Collection>
void Sort(Collection& c) {
    auto begin = c.begin();
    typename Collection::iterator end = c.end();
    for (auto i = begin; i != end; i++) {
        for (auto j = begin; j != end; j++)
            if ((i != j) && (*i < *j))
                std::iter_swap(i,j);
    }
}

template<class Collection, class Comp>
void Sort(Collection& c, Comp&& comparator) {
    auto begin = c.begin();
    typename Collection::iterator end = c.end();
    for (auto i = begin; i != end; i++) {
        for (auto j = begin; j != end; j++)
            if (comparator(*i, *j))
                std::iter_swap(i,j);
    }
}

template<class Collection>
void Unique(Collection& c) {
    unique(c.begin(), c.end());
    // typename Collection::iterator iter = c.begin();
    // for (auto i = c.begin(); i != c.end(); i++) {
    //     if (*i != *iter) {
    //         iter = i;
    //     }
    //     else {
    //         c.erase
    //     }
        
    // }
}


template<class Collection, class Pred>
void Unique(Collection& c, Pred&& predicat) {
    for_each(c.begin(), c.end(), predicat);
}

template<class Collection, class T>
int IndexOf(const Collection& c, const T& value) {
    int index = 0;
    for (auto i = c.begin(); i != c.end(); ++i, ++index) {
        if (value == *i)
            return index;
    }
    return -1;
}

template<class Collection, class Pred>
int IndexOfIf(const Collection& c, Pred&& predicate) {
    int index = 0;
    for (auto i = c.begin(); i != c.end(); ++i, ++index) {
        if (predicate(*i))
            return index;
    }
    return -1;
}
