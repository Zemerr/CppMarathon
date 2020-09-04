#include <iostream>

class AbstractWizard {
public:
    virtual void deductFoodTyp();
};

enum class FoodType {
    ApplePie,
    HoneyNut,
    Sweetroll,
    PoisonedFood,
    Invalid
};

class FoodItem {
public:
    FoodType m_item;
    virtual void getFood() {
        m_item = FoodType::Invalid;
    };
};

class ApplePie : public FoodItem {
public:
    void getFood() {
        m_item = FoodType::ApplePie;
    };
};

class HoneyNut : public FoodItem {
public:
    void getFood() {
        m_item = FoodType::HoneyNut;
    }
};

class Sweetroll : public FoodItem {
public:
    void getFood() {
        m_item = FoodType::Sweetroll;
    }
};

class PoisonedFood : public FoodItem {
public:
    void getFood() {
        m_item = FoodType::PoisonedFood;
    }
};

class MightyWizard : public AbstractWizard {
private:
    std::string m_name;

public:
    MightyWizard(std::string name) : m_name(name){};
    void checkFood(FoodItem *ptr);
    void checkFood(FoodItem &ptr);
};
