#pragma once

class Axe final {
private:
    const int m_damage;

public:
    Axe(int damage);
    int getDamage() const;
};
