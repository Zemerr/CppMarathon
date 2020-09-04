#include "Dragoborn.h"
#include <map>
#include <iostream>
#include <functional>

Draugr::Draugr() : Draugr::Draugr(100, 50) {};

Draugr::Draugr(int res) : Draugr::Draugr(100, res) {};

Draugr::Draugr(double health, int res) : m_health(health), m_frostResist(res) {
    std::cout << "Draugr with "<< m_health <<" health and "<< m_frostResist << "% frost resist was born\n";
};


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

    std::cout << "Draugr Lord (" << m_health << " health, " << m_frostResist << "% frost resist) shouts:\n" << str << "\n";
}

