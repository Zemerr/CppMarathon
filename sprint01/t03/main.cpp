#include "./src/vampireRabbits.h"

Rabbit creation() {
    Rabbit onerabbit;
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> distribution(1,100);


    int dice_roll = distribution(generator);

    if (dice_roll < 50)
        onerabbit.gender = Gender::Female;
    else 
        onerabbit.gender = Gender::Male;
    onerabbit.age = 0;
    if (dice_roll == 1)
        onerabbit.isVampire = true;
    else
        onerabbit.isVampire = false;
    return onerabbit;
}

bool count_male(Rabbit r) {
    return (r.isVampire == false && r.gender == Gender::Male);
}

bool count_female(Rabbit r) {
    return (r.isVampire == false && r.gender == Gender::Female);
}

bool count_vamp(Rabbit r) {
    return (r.isVampire == true);
}

void born(list<Rabbit>& game) {
    int male = count_if(game.begin(), game.end(), count_male);
    int female = count_if(game.begin(), game.end(), count_female);
    int pair = 0;


    if (male <= female)
        pair = male;
    else 
        pair = female;
    for (auto i = 0; i < pair; i++) {
        Rabbit onerabbit = creation();
        game.push_back(onerabbit);
    }

}

void increment(list<Rabbit>& game) {
    for (auto i = game.begin(); i != game.end(); i++) {
        (*i).age++;
    }
}

void die(list<Rabbit>& game) {
    for (auto i = game.begin(); i != game.end(); i++) {
        if ((*i).age > 3 && (*i).isVampire != true)
            game.erase(i);
        else if ((*i).age > 8 && (*i).isVampire == true)
            game.erase(i);
    }
}

void bite(list<Rabbit>& game) {
    int vampirs = count_if(game.begin(), game.end(), count_vamp);
    int j = 0;

    for (auto i = game.begin(); i != game.end() && j < vampirs; i++) {
        if ((*i).isVampire == false)
            (*i).isVampire = true;
        j++;
    }
}



int main() {
    list<Rabbit> game;
    int male = 0;
    int female = 0;
    int vampirs = 0;



    for (auto i = 0; i < 10; i++) {
        Rabbit onerabbit = creation();
        game.push_back(onerabbit);
    }
    male = count_if(game.begin(), game.end(), count_male);
    female = count_if(game.begin(), game.end(), count_female);
    vampirs = count_if(game.begin(), game.end(), count_vamp);
    cout << "Males: " << male << "\n";
    cout << "Females: " << female << "\n";
    cout << "Vampires: " << vampirs << "\n";
    sleep(1);
    
    while (true) {
        increment(game);
        die(game);
        born(game);
        bite(game);

        male = count_if(game.begin(), game.end(), count_male);
        female = count_if(game.begin(), game.end(), count_female);
        vampirs = count_if(game.begin(), game.end(), count_vamp);

        cout << "Males: " << male << "\n";
        cout << "Females: " << female << "\n";
        cout << "Vampires: " << vampirs << "\n";

        if ((male + female + vampirs > 1000) || (male + female + vampirs == 0))
            break;
        sleep(1);
    }



}
