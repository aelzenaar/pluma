#include <Pluma/Connector.hpp>
#include "Eagle.hpp"
#include "Jaguar.hpp"

/////////////////////////////////////////////////////////
/// Plugin connects to hosts through this function
/// Add Eagle and Jaguar providers to the host, so that it
/// can create and use those kind of warriors
/////////////////////////////////////////////////////////
PLUMA_CONNECTOR
bool connect(pluma::Host& host){
    host.add( new EagleProvider() );
    host.add( new JaguarProvider() );
    return true;
}
