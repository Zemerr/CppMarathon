#include "src/MultithreadedClass.h"
#include "src/Worker.h"
#include <iostream>
#include <string>

void ender(char str) {
    if (str != 0)
        throw 1;
}

void parce_func(char **argv, int &addValue, int &subtractValue, int &count) {

    try {
        size_t pointer;
        addValue = std::stoi(argv[1], &pointer, 10);
        ender(argv[1][pointer]);
        subtractValue = std::stoi(argv[2], &pointer, 10);
        ender(argv[2][pointer]);
        count = std::stoi(argv[3], &pointer, 10);
        ender(argv[3][pointer]);
    } catch (...) {
        std::cerr << "Incorrect values\n";
        exit(1);
    }
    if (addValue < -2000 || addValue > 2000 || subtractValue < -2000 || subtractValue > 2000 || count < 5 || count > 10) {
        std::cerr << "Incorrect values\n";
        exit(1);
    }
}

int main(int argc, char **argv) {
    int count = 0;
    int addValue = 0;
    int subtractValue = 0;

    if (argc != 4) {
        std::cerr << "usage: ./simpleWorkerV2 [addValue] [subtractValue] [count]\n";
        exit(1);
    }

    parce_func(argv, addValue, subtractValue, count);
    MultithreadedClass obj;
    Worker worker;
    for (auto i = 0; i < count; ++i) {
        worker.startNewThread(&MultithreadedClass::add, &obj, addValue);
    }
    for (auto i = 0; i < count; ++i) {
        worker.startNewThread(&MultithreadedClass::subtract, &obj, subtractValue);
    }
    worker.joinAllThreads();
    std::cout << obj.getInt() << std::endl;
}
