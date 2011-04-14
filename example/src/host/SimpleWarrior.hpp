#ifndef SIMPLE_WARRIOR_HPP
#define SIMPLE_WARRIOR_HPP

#include "Warrior.hpp"

/////////////////////////////////////////////////////////
/// Default Warrior
/////////////////////////////////////////////////////////
class SimpleWarrior: public Warrior{
public:
    std::string getDescription(){
        return "Commoner: leaded by calpoleque";
    }
};

/////////////////////////////////////////////////////////
/// SimpleWarriorProvider provide default warriors
/////////////////////////////////////////////////////////
PLUMA_INHERIT_PROVIDER(SimpleWarrior, Warrior);

#endif // SIMPLE_WARRIOR_HPP
