#ifndef KEYBOARD_HPP_INCLUDED
#define KEYBOARD_HPP_INCLUDED

#include <Pluma\PluginAPI.hpp>
#include "Device.hpp"

/////////////////////////////////////////////////////////
/// A keyboard is a specific Device
/////////////////////////////////////////////////////////
class Keyboard: public Device{
public:
    std::string getDescription(){
        return "keyboard";
    }
    // (...)
};

/////////////////////////////////////////////////////////
/// Generate class KeyboardProvider
/// It's a DeviceProvider to provides hosts with Keyboard objects
/////////////////////////////////////////////////////////
PLUMA_INHERIT_PROVIDER(Keyboard, Device);


#endif // KEYBOARD_HPP_INCLUDED
