#include "Player.h"
#include <iostream>




Player::Player(const std::string& name): m_name(name){};



void Player::openContainer(Container* container) {
    std::string Cont_name = container->name();

    if (container->isLocked() == false)
        std::cout << m_name << " successfully opened " << Cont_name << "\n";
    else if (container->tryToOpen(m_lockpickSkill) == true)
        std::cout << m_name << " successfully opened " << Cont_name << "\n";
    else 
        std::cout << m_name << " skillis too low to open " << Cont_name << "\n";

}
void Player::setLockpickSkill(LockpickDifficulty skill) {
    m_lockpickSkill = skill;
}
