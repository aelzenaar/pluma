#ifndef DEVICE_HPP_INCLUDED
#define DEVICE_HPP_INCLUDED

// Pluma include needed for host applications:
#include <Pluma\HostAPI.hpp>


/////////////////////////////////////////////////////////
/// Device Interface
/// That's the kind of objects that plugins will provide
/////////////////////////////////////////////////////////
class Device{
public:
    virtual std::string getDescription() = 0;
    // (...)
};

/////////////////////////////////////////////////////////
/// Generate DeviceProvider Interface
/// Plugins will provide host with new Devices throgh DeviceProvider objects
/// Host automatically check version compatibility
/// Parameters are: (Type, current version, lowest compatible version)
/////////////////////////////////////////////////////////
PLUMA_GEN_PROVIDER(Device, 6, 3);

#endif // DEVICE_HPP_INCLUDED
