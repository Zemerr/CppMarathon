#include "src/Dragoborn.h"
#include <iostream>
#include <string>
#include <map>


void ender(char str) {
  if (str != 0)
    throw 1;
}


void parce_func(char **argv, int& num) {

    try {
        auto pointer = 4ul;
        num = std::stoi(argv[1], &pointer, 10);
        ender(argv[1][pointer]);

    }
    catch(...) {
        std::cerr << "Invalid shoutNumber.\n";
        exit(1);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "usage: ./draugr [shoutNumber]\n";
        exit(1);
    }
    else {
        Draugr drag;
        int num;
        parce_func(argv, num);
        drag.shoutPhrase(num);
    }
}
