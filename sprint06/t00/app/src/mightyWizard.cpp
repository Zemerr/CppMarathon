#include "mightyWizard.h"
#include <iostream>

void MightyWizard::checkFood(FoodItem *ptr) {
    if (ptr == nullptr) {
        std::cout << "<wtf>. Ugh, not again!\n";
        return;
    }
    ptr->getFood();
    if (ptr->m_item == FoodType::ApplePie)
        std::cout << "Apple pie. Ugh, not again!\n";
    if (ptr->m_item == FoodType::Sweetroll)
        std::cout << "Sweetroll. Mmm, tasty!\n";
    if (ptr->m_item == FoodType::HoneyNut)
        std::cout << "Honey nut. Mmm, tasty!\n";
    if (ptr->m_item == FoodType::PoisonedFood)
        std::cout << "Poison. Ugh, not again!\n";
    if (ptr->m_item == FoodType::Invalid)
        std::cout << "<wtf>. Ugh, not again!\n";
}

void MightyWizard::checkFood(FoodItem& ptr) {
    ptr.getFood();
    if (ptr.m_item == FoodType::ApplePie)
        std::cout << "Apple pie. Ugh, not again!\n";
    if (ptr.m_item == FoodType::Sweetroll)
        std::cout << "Sweetroll. Mmm, tasty!\n";
    if (ptr.m_item == FoodType::HoneyNut)
        std::cout << "Honey nut. Mmm, tasty!\n";
    if (ptr.m_item == FoodType::PoisonedFood)
        std::cout << "Poison. Ugh, not again!\n";
    if (ptr.m_item == FoodType::Invalid)
        std::cout << "<wtf>. Ugh, not again!\n";
}
