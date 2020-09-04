#include "Dragoborn.h"
#include <map>
#include <iostream>
#include <functional>

void Dragoborn::shoutThuum() const {
    std::cout << "Yol Toor Shul\n";
}

void Dragoborn::attackWithMagic() const {
    std::cout << "*attacks with magic spell*\n";
}

void Dragoborn::attackWithWeapon() const {
    std::cout << "*attacks with weapon*\n";
}

void Dragoborn::executeAction(const Dragoborn::Actions action) {
    std::map<Actions, void (Dragoborn::*)() const> map {
        {Actions::Shout, &Dragoborn::shoutThuum},
        {Actions::Magic, &Dragoborn::attackWithMagic},
        {Actions::Weapon, &Dragoborn::attackWithWeapon},
    };
    std::invoke(map.at(action), this);
}
