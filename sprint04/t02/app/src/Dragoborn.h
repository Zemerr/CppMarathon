


class Dragoborn {
private:
    void shoutThuum() const;
    void attackWithMagic() const;
    void attackWithWeapon() const;
public:
    enum class Actions {
        Shout,
        Magic,
        Weapon,
        Invalid
    };
    void executeAction(const Actions action);
};

