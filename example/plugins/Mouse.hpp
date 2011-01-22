#ifndef MOUSE_HPP_INCLUDED
#define MOUSE_HPP_INCLUDED

#include <Pluma\PluginAPI.hpp>
#include "Device.hpp"

/////////////////////////////////////////////////////////
/// A Mouse is a specific Device
/////////////////////////////////////////////////////////
class Mouse: public Device{
public:
    std::string getDescription(){
        return "nice pointer";
    }
    // (...)
};

/////////////////////////////////////////////////////////
/// Generate class MouseProvider
/// It's a DeviceProvider, provide mouses
/////////////////////////////////////////////////////////
PLUMA_INHERIT_PROVIDER(Mouse,Device);


#endif // MOUSE_HPP_INCLUDED
