#pragma once
#include "Sword.h"
#include <iostream>

class StormcloakSoldier;

class ImperialSoldier final {
    public:
        ImperialSoldier();
        ~ImperialSoldier();

        void setWeapon(Sword* sword);
        void attack(StormcloakSoldier& enemy);
        void consumeDamage(int amount);
        int getHealth() const;
    private:
        int m_health = 100;
        Sword* m_weapon = nullptr;
};
