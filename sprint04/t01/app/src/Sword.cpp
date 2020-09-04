#include "Sword.h"

Sword::Sword(int val): m_damage(val) {}

int Sword::getDamage() const {
    return m_damage;
}
