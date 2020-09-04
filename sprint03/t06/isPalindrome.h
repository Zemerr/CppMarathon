#include <iostream>


template <class BidirectionalIterator>
bool isPalindrome(BidirectionalIterator begin, BidirectionalIterator end) {
    //--end;
    while (begin != end) {
        if (*begin != *end)
            return false;
        begin++;
        if (begin == end)
            return true;
        end--;
    }
    return true;
}
