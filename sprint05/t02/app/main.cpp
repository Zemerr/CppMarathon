#include "src/Dragoborn.h"
#include <iostream>
#include <string>
#include <map>
#include  <regex>


void ender(char str) {
  if (str != 0)
    throw 1;
}

void parce_func(char **argv, int& num, std::string& firstname, std::string& secondname, double& health, int& resisit ) {

    try {
        size_t pointer;
        num = std::stoi(argv[1], &pointer, 10);
        ender(argv[1][pointer]);
        health = std::stod(argv[3], &pointer);
        ender(argv[3][pointer]);
        resisit = std::stoi(argv[4], &pointer, 10);
        ender(argv[4][pointer]);

    }
    catch(...) {
        std::cerr << "Invalid shoutNumber.\n";
        exit(1);
    }
    std::regex b ("([a-zA-Z]+),([a-zA-Z]+)");
    std::smatch sm;
    std::string str = (std::string)argv[2];

    if (std::regex_match(str, sm, b) != true) {
        std::cerr << "Invalid Name.\n";
        exit(1);
    }
    else {
        firstname = sm[1];
        secondname = sm[2];
    }
}

void parce_func(char **argv, int& num, std::string& firstname, std::string& secondname, double& health) {
    try {
        size_t pointer;
        num = std::stoi(argv[1], &pointer, 10);
        ender(argv[1][pointer]);
        health = std::stod(argv[3], &pointer);
        ender(argv[3][pointer]);


    }
    catch(...) {
        std::cerr << "Invalid shoutNumber.\n";
        exit(1);
    }

    std::regex b ("([a-zA-Z]+),([a-zA-Z]+)");
    std::smatch sm;
    std::string str = (std::string)argv[2];

    if (std::regex_match(str, sm, b) != true) {
        std::cerr << "Invalid Name.\n";
        exit(1);
    }
    else {
        firstname = sm[1];
        secondname = sm[2];
    }
}




int main(int argc, char **argv) {
    if (argc < 4 || argc > 5) {
        std::cerr << "usage: ./draugr [shoutNumber]\n";
        exit(1);
    }
    else if (argc == 4) {
        
        int num;
        std::string firstname;
        std::string secondname;
        double health;
        parce_func(argv, num, firstname, secondname, health);
        Draugr first(health);
        first.setName(std::move(firstname));
        first.shoutPhrase(num);
        Draugr second(first);
        second.setName(std::move(secondname));
        second.shoutPhrase(num);

    }
    else if (argc == 5) {
        int num;
        std::string firstname;
        std::string secondname;
        double health;
        int resisit;
        parce_func(argv, num, firstname, secondname, health, resisit);
        Draugr first(health, resisit);
        first.setName(std::move(firstname));
        first.shoutPhrase(num);
        Draugr second(std::move(first));
        second.setName(std::move(secondname));
        second.shoutPhrase(num);

    }
}

