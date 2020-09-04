#pragma once

#include <string>
#include "Container.h"

//class Container;
//class LockpickDifficulty;

class Player {
private:
    LockpickDifficulty m_lockpickSkill{LockpickDifficulty::None};
    std::string m_name;
public:
    explicit Player(const std::string& name);
    void openContainer(Container* container);
    void setLockpickSkill(LockpickDifficulty skill);
};


