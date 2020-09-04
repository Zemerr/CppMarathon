#pragma once
#include <string>

enum class LockpickDifficulty {
    None = 0,
    Novice = 25,
    Apprentice = 40,
    Adept = 60,
    Expert = 80,
    Master = 100
};

class ILockable {
public:
    virtual LockpickDifficulty lockDifficulty() {
        return LockpickDifficulty::None;
    };
};

class IOpenable {
public:
    virtual bool tryToOpen(LockpickDifficulty) {
        return false;
    };
};

class Container : public ILockable, public IOpenable {
private:
    bool m_isLocked{false};
    LockpickDifficulty m_difficulty;

public:
    Container(bool isLocked, const LockpickDifficulty difficulty);
    LockpickDifficulty lockDifficulty() const;
    bool isLocked() const;
    bool tryToOpen(LockpickDifficulty skill);

    virtual std::string name() const = 0;
};

class Barrel : public Container {
public:
    Barrel();
    std::string name() const;
};

class Chest : public Container {
public:
    Chest(bool isLocked, const LockpickDifficulty difficulty);
    std::string name() const;
};

class Safe : public Container {
public:
    Safe(bool isLocked, const LockpickDifficulty difficulty);
    std::string name() const;
};
