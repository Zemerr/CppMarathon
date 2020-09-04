#include <iostream>
#include "Werewolf.h"


Creature::Creature() {
    std::cout << "Creature was created\n";
}

Creature::~Creature() {
    std::cout << "Creature was deleted\n";
}

Werewolf::Werewolf() {
    std::cout << "Werewolf was created\n";
}


Werewolf::~Werewolf() {
    std::cout << "Werewolf was deleted\n";
}

