#include "Container.h"
#include <iostream>

Container::Container(bool isLocked, const LockpickDifficulty difficulty) : m_isLocked(isLocked), m_difficulty(difficulty){};

LockpickDifficulty Container::lockDifficulty() const {
    return m_difficulty;
}
bool Container::isLocked() const {
    return m_isLocked;
}

bool Container::tryToOpen(LockpickDifficulty skill) {
    if (skill >= m_difficulty)
        return true;
    else
        return false;
}

Barrel::Barrel() : Container::Container(false, LockpickDifficulty::None) {};
Chest::Chest(bool isLocked, const LockpickDifficulty difficulty) : Container::Container(isLocked, difficulty) {};
Safe::Safe(bool isLocked, const LockpickDifficulty difficulty) : Container::Container(isLocked, difficulty) {};


std::string Barrel::name() const {
    return "Barel";
}
std::string Chest::name() const {
    return "Chest";
}
std::string Safe::name() const {
    return "Safe";
}
