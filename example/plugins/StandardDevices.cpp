// Pluma include needed for plugin side
#include <Pluma\PluginAPI.hpp>

#include "Keyboard.hpp"
#include "Mouse.hpp"


/////////////////////////////////////////////////////////
/// Plugin connects to hosts through this function
/// Add Keyboard and Mouse providers to the host, so that it
/// is able to create and use keyboard and mouse devices
/////////////////////////////////////////////////////////
PLUMA_PLUGIN_CONNECTION
bool connect(pluma::Host& host){
    // add new device providers to host
    host.add( new KeyboardProvider() );
    host.add( new MouseProvider() );
    return true;
}
