#include "Weapon.h"




Weapon::Weapon(int val) : m_damage(val) {}

int Weapon::getDamage() const {
    return m_damage;
}
