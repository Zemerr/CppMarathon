#include <iostream>


template <class Container>
void squareValue(Container& container) {
    for (auto i = container.begin(); i != container.end(); i++) {
        *i *=  *i;
    }
}
