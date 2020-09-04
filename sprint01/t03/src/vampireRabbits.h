#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <random>
#include <unistd.h>


using namespace std;

enum class Gender {
    Male,
    Female
};

struct Rabbit {
    Gender gender;
    bool isVampire;
    int age;
};
