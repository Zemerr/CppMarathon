#include "Dragoborn.h"
#include <map>
#include <iostream>
#include <functional>


Draugr::Draugr() : Draugr::Draugr(100, 50) {};

Draugr::Draugr(double health) : Draugr::Draugr(health, 50) {};

Draugr::Draugr(double health, int res) : m_health(health), m_frostResist(res) {
    std::cout << "Draugr with " << m_health <<" health and "<< m_frostResist << "% frost resist was born\n";
}; 

Draugr::Draugr(Draugr& other) : m_health(other.m_health), m_frostResist(other.m_frostResist) {
    std::cout << "Draugr with "<< m_health <<" health and "<< m_frostResist << "% frost resist was born\n";
    std::cout << "Copy constructor was called\n";
};
Draugr::Draugr(Draugr&& other) : m_health(other.m_health), m_frostResist(other.m_frostResist) { 
    std::cout << "Draugr with "<< m_health <<" health and "<< m_frostResist << "% frost resist was born\n";
    std::cout << "Move constructor was called\n";
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
    std::cout << "Draugr " << m_name << " (" << m_health << " health, " << m_frostResist << "% frost resist) shouts:\n" << str << "\n";
}

void Draugr::setName(const std::string&& name) {
    m_name = name;
}

