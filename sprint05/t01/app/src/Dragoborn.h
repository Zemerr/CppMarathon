

class Draugr {
public:
    Draugr();
    Draugr(int resist);
    Draugr(double health, int resist);
    void shoutPhrase(int shoutNumber) const;

private:
    double m_health;
    const int m_frostResist;
};
