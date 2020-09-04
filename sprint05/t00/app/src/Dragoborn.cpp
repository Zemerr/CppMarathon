#include "Dragoborn.h"
#include <map>
#include <iostream>
#include <functional>


Draugr::Draugr() : m_health(100), m_frostResist(50) {};


void Draugr::shoutPhrase(int shoutNumber) const {
    std::string str;
    std::map<int, std::string> map {
        {0, "Qiilaan Us Dilon!"},
        {1, "Bolog Aaz, Mal Lir!"},
        {2, "Kren Sosaal!"},
        {3, "Dir Volaan!"},
        {4, "Aar Vin Ok!"},
        {5, "Unslaad Krosis"},
        {6, "Faaz! Paak! Dinok!"},
        {7, "Aav Dilon!"},
        {8, "Sovngarde Saraan!"}
    };
    try {
        str = map.at(shoutNumber);
    }
    catch (...) {
        str = "Invalid shoutNumber";
        std::cerr << str << "\n";
        exit(1);
    }
    std::cout << "Draugr (100 health, 50% frost resist) shouts:\n" << str << "\n";
}
