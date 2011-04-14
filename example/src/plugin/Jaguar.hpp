#ifndef JAGUAR_HPP
#define JAGUAR_HPP

#include "Warrior.hpp"

/////////////////////////////////////////////////////////
/// A Jaguar is a Warrior
/////////////////////////////////////////////////////////
class Jaguar: public Warrior{
public:
    std::string getDescription(){
        return "Jaguar Warrior: soldier of Tezcatlipoca";
    }
};


/////////////////////////////////////////////////////////
/// A JaguarProvider is a WarriorProvider,
/// provide warriors of type Jaguar
/////////////////////////////////////////////////////////
PLUMA_INHERIT_PROVIDER(Jaguar, Warrior);

#endif // JAGUAR_HPP
