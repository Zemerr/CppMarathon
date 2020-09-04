#pragma once


class Sword final {
    private:
        const int m_damage;
    public:
        Sword(int damage);
        int getDamage() const;
};
