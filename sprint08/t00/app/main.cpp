#include "src/Map.h"
#include "src/MoveManager.h"
#include "src/Player.h"
#include <iostream>
#include <string>


void ender(char str) {
  if (str != 0)
    throw 1;
}

void parce_func(char **argv, int& width, int& height) {

    try {
        size_t pointer;
        width = std::stoi(argv[1], &pointer, 10);
        ender(argv[1][pointer]);
        height = std::stoi(argv[2], &pointer, 10);
        ender(argv[2][pointer]);
    }
    catch(...) {
        std::cerr << "Invalid map size\n";
        exit(1);
    }
    if (width != height) {
        std::cerr << "Invalid map size\n";
        exit(1);
    }
}




int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "usage: ./smartPointers [width] [height]\n";
        exit(1);
    }
    int width = 0;
    int height = 0;
    parce_func(argv, width, height);
    Player *player = new Player;
    std::shared_ptr<Player> ptr1(player);


    Map *map = new Map(width, height, ptr1);
    std::shared_ptr<Map> ptr2(map);


    MoveManager manger(ptr1, ptr2);
    std::string inputstr;
    (*map).outputMap();
    while (1) {
        std::cout << ":> ";
        getline(std::cin, inputstr, '\n');
        manger.processInputAndMove(inputstr);
    }
    return 0;
}


