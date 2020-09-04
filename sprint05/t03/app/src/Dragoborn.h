#include <iostream>

class Draugr {
public:
    Draugr();
    Draugr(double health);
    Draugr(double health, int resist);
    void shoutPhrase(int shoutNumber) const;

    Draugr(Draugr& other) = delete;
    Draugr(Draugr&& other) = delete;
    void setName(const std::string&& name);

private:
    double m_health;
    const int m_frostResist;
    std::string m_name;
};
