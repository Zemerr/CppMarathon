#include "src/ImperialSoldier.h"
#include "src/StormcloakSoldier.h"
#include "src/Sword.h"
#include "src/Axe.h"


void ender(char str) {
  if (str != 0)
    throw 1;
}

void parce_func(int argc, char **argv, int& first_val, int&second_val) {
    if (argc != 3) {
        std::cerr << "usage: ./imperialVsStormcloak [dmgOfSword] [dmgOfAxe]\n";
        exit(1);
    }
    try {
        auto pointer = 4ul;
        first_val = std::stoi(argv[1], &pointer, 10);
        ender(argv[1][pointer]);
        second_val = std::stoi(argv[2], &pointer);
        ender(argv[2][pointer]);
    }
    catch(...) {
        std::cerr << "Damage has to be in a range of 10-20 points.\n";
        exit(1);
    }
    if ((first_val < 10 || first_val > 20) || (second_val < 10 || second_val > 20)) {
        std::cerr << "Damage has to be in a range of 10-20 points.\n";
        exit(1);
    }
}

int main(int argc, char **argv) {
    int first_val;
    int second_Val;


    ImperialSoldier impsol;
    StormcloakSoldier strormsol;
    
    parce_func(argc, argv, first_val, second_Val);
    impsol.setWeapon(new Sword(first_val));
    strormsol.setWeapon(new Axe(second_Val));

    std::cout << "Soldier Martin was created\n\
Imperial soldier was created\nSoldier Flynn was created\nStormcloak soldier was created\n\n***The battle has begun!***\n\n";

    while (impsol.getHealth() > 0 && strormsol.getHealth() > 0) {
        
        strormsol.attack(impsol);
        impsol.attack(strormsol);
        std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    }
    if (strormsol.getHealth() <= 0)
        std::cout << "Imperial has won!\n\n";
    else
        std::cout << "Stormcloack has won!\n\n";
    std::cout << "Stormcloak soldier was deleted\nSoldier Flynn was deleted\nImperial soldier was deleted\nSoldier Martin was deleted\n";

}
