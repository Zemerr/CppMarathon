#pragma once
#include "Axe.h"
#include <iostream>

class ImperialSoldier;

class StormcloakSoldier final {
    private:
        int m_health = 100;
        Axe* m_weapon = nullptr;

    public:
        StormcloakSoldier();
        ~StormcloakSoldier();

        void setWeapon(Axe* sword);
        void attack(ImperialSoldier& enemy);
        void consumeDamage(int amount);
        int getHealth() const;
};
