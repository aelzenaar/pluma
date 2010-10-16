// Pluma include needed for host applications:
#include <Pluma\HostAPI.hpp>

#include "Device.hpp"
#include <iostream>
#include <vector>


int main(){

    // Create pluma plugins manager
    pluma::Pluma plugins;
    // Tell it to accept providers of the type DeviceProvider
    plugins.acceptProviderType<DeviceProvider>();

    // Load some dll
    plugins.load("plugins\\standard_devices.dll");

    // Get device providers into a vector
    std::vector<DeviceProvider*> providers;
    plugins.getProviders(providers);

    // Use those providers to create devices and do something with them
    // On this example, create an object from each provider
    // and print it's description. Don't forget to delete the device pointer
    std::vector<DeviceProvider*>::iterator it;
    for (it = providers.begin() ; it != providers.end() ; ++it){
        // Create a device
        Device* device = (*it)->create();
        // Do something with the device
        std::cout << device->getDescription() << std::endl;
        // (...)
        delete device;
    }

    std::cout << "Press any key to exit";
    std::cin.ignore(10000, '\n');
    return 0;
}
