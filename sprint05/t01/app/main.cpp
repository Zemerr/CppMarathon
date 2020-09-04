#include "src/Dragoborn.h"
#include <iostream>
#include <string>
#include <map>


void ender(char str) {
  if (str != 0)
    throw 1;
}

void parce_func(char **argv, int& num, double& health, int& resisit ) {

    try {
        size_t pointer;
        num = std::stoi(argv[1], &pointer, 10);
        ender(argv[1][pointer]);
        health = std::stod(argv[2], &pointer);
        ender(argv[2][pointer]);
        resisit = std::stoi(argv[3], &pointer, 10);
        ender(argv[3][pointer]);
    }
    catch(...) {
        std::cerr << "Invalid shoutNumber.\n";
        exit(1);
    }
}

void parce_func(char **argv, int& num, int& res) {

    try {
        auto pointer = 4ul;
        num = std::stoi(argv[1], &pointer, 10);
        ender(argv[1][pointer]);
        res = std::stoi(argv[2], &pointer);
        ender(argv[2][pointer]);
    }
    catch(...) {
        std::cerr << "Invalid shoutNumber.\n";
        exit(1);
    }
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

    if (argc < 2 || argc > 4) {
        std::cerr << "usage: ./draugr [shoutNumber]\n";
        exit(1);
    }
    else if (argc == 2) {
        Draugr drag;
        int num;
        parce_func(argv, num);
        drag.shoutPhrase(num);
    }
    else if (argc == 3) {
        int num;
        int res;
        parce_func(argv, num, res);
        Draugr drag(res);
        drag.shoutPhrase(num);
    }
        else if (argc == 4) {
        int num;
        double health;
        int resisit;
        parce_func(argv, num, health, resisit);
        Draugr drag(health, resisit);
        drag.shoutPhrase(num);
    }
}

