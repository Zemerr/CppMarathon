#include <iostream>
#include <algorithm>

template <class RandomAccessIterator>
RandomAccessIterator sortValues(RandomAccessIterator begin, RandomAccessIterator end) {
    for (auto i = begin; i != end; i++) {
        for (auto j = begin; j != end; j++)
            if (*i < *j)
                std::iter_swap(i,j);
    }
    return begin;
}
