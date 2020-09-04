#include "Axe.h"

Axe::Axe(int val) : m_damage(val) {}

int Axe::getDamage() const {
    return m_damage;
}
