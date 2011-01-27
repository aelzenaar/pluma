#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include <Pluma\Pluma.hpp>

/////////////////////////////////////////////////////////
/// Warrior Interface
/// That's the kind of objects that plugins will provide
/////////////////////////////////////////////////////////
class Warrior{
public:
    virtual std::string getDescription() = 0;
    // (...)
};

/////////////////////////////////////////////////////////
/// WarriorProvider Interface
/// Plugins will provide host with new Warriors throgh WarriorProvider
/// implementations. Host automatically check version compatibility
/////////////////////////////////////////////////////////
// PLUMA_GEN_PROVIDER(Type, current_version, lowest_compatible_version)
PLUMA_GEN_PROVIDER(Warrior, 1, 1);
//PLUMA_GEN_PROVIDER_BEGIN(Warrior)
//    public:
//        virtual Warrior* create(int energy) = 0;
//        virtual void populate(std::vector<Warrior*>& army, int numSoldiers) = 0;
//PLUMA_GEN_PROVIDER_END(Warrior, 1, 1)


#endif // WARRIOR_HPP
