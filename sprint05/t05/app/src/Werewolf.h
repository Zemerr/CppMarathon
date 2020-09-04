

class Creature {
public:
    Creature();
    ~Creature();
};

class Wolf : public virtual Creature {
public:
    Wolf() {};
};

class Human : public virtual Creature {
public:
    Human() {};
};

class Werewolf : public Wolf, public Human {
public:
    Werewolf();
    ~Werewolf();
};
