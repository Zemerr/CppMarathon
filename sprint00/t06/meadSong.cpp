#include "meadSong.h"



void meadSong() {
    auto str1 = " bottles of mead";
    auto str2 = " on the wall";
    auto str3 = "Take one down and pass it around, ";
    auto str4 = "more";

    for (auto i = 99; i > 0; i--) {
        std::cout << i << str1 << str2 << ", " << i << str1 << ".\n";
        if (i != 1)
            std::cout << str3 << i-1 << str1 << str2 << ".\n\n";
    }
    std::cout << str3 << "no " << str4 << str1 << str2 << ".\n\n";
    std::cout << "No " << str4 << str1 << str2 << ", no " << str4 << str1 << ".\n";
    std::cout << "Go to the store and buy some more, 99" << str1 << str2 << "\n";
}
