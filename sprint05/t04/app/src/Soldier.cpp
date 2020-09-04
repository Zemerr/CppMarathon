#include "Soldier.h"
#include "Weapon.h"
#include <iostream>




Soldier::Soldier(std::string&& name, int health): m_health(health), m_name(name) {};

Soldier::~Soldier() {
    delete m_weapon;
}

void Soldier::setWeapon(Weapon* weapon) {
    m_weapon = weapon;
}

void Soldier::attack(Soldier& enemy) {
    int damage = m_weapon->getDamage();
    enemy.m_health -= damage;
    std::cout << m_name << " attacks "<< enemy.m_name <<" and deals " << damage << " damage\n";
    // enemy.consumeDamage(damage);
}

// void Soldier::consumeDamage(int amount) {
//     m_health -= amount;
//     std::cout << "Imperial soldier consumes " << amount << " of damage\n";
// }

int Soldier::getHealth() const {
    return m_health;
}
