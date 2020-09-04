#include "src/Dragoborn.h"
#include <iostream>
#include <string>
#include <map>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "usage: ./dragonborn [action]\n";
        exit(1);
    }
    else {

        std::map<std::string, Dragoborn::Actions> map {
            {"shout", Dragoborn::Actions::Shout},
            {"magic", Dragoborn::Actions::Magic},
            {"weapon", Dragoborn::Actions::Weapon},
        };
        Dragoborn::Actions act;
        try {
            act = map.at(argv[1]);
        }
        catch (...) {
            std::cerr << "Invalid action\n";
            exit(1);
        }

        Dragoborn darg;
        darg.executeAction(act);
    }
}
