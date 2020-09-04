#include "castSpells.h"

int intcastFloatToInt(float number) {
    int a = static_cast<int>(number);
    return a;
}

int* castToNonConstIntPtr(const int* ptr) {
    int* arr = const_cast<int *>(ptr);
    return arr;
}
