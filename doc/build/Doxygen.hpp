////////////////////////////////////////////////////////////
/// \mainpage
///
/// \section welcome Welcome
/// Welcome to Pluma documentation. Here you will find a detailed
/// view of all Pluma <a href="./annotated.htm">classes</a>.<br>
/// The best way of understanding it is by following the <a href="./modules.htm">modules</a>
/// organization.<br>
/// If you are looking for support, you can visit the official website
/// at <a href="http://www.pluma.pt.vu">www.pluma.pt.vu</a>.<br><br>
///
///
/// \section example Short Example
/// A short example to demonstrate Pluma usage:<br>
/// A host application define a Device interface. A certain plugin
/// defines a Keyboard, witch is a Device.
/// The host will use DeviceProviders to create objects of type Device.
/// The plugin will provide host specifically with a KeyboardProvider.<br>
///
/// Device code (shared):
/// \code
/// class Device{
/// public:
///     virtual std::string getDescription() = 0;
/// };
/// // create DevicedProvider with version 6, and compatible with at least v.3
/// PLUMA_GEN_PROVIDER(Device, 6, 3);
/// \endcode
/// 
/// Host application code:
/// \code
/// #include <Pluma\HostAPI.hpp>
/// 
/// #include "Device.hpp"
/// #include <iostream>
/// #include <vector>
/// 
/// int main(){
///
///     pluma::Pluma plugins;
///     // Tell plugins manager to accept providers of the type DeviceProvider
///     plugins.acceptProviderType<DeviceProvider>();
///     // Load some dll
///     plugins.load("plugins\\standard_devices.dll");
///
///     // Get device providers into a vector
///     std::vector<DeviceProvider*> providers;
///     plugins.getProviders(providers);
///
///     // create a Device from the first provider
///     if (!providers.empty()){
///         Device* myDevice = providers.first()->create();
///         // do something with myDevice
///         std::cout << device->getDescription() << std::endl;
///         // and delete it in the end
///         delete myDevice;
///     }
///     return EXIT_SUCCESS;
/// }
/// \endcode
///
/// <br>
/// Keyboard code at plugin:
/// \code
/// #include <Pluma\PluginAPI.hpp>
/// #include "Device.hpp"
///
/// class Keyboard: public Device{
/// public:
///     std::string getDescription(){
///         return "keyboard";
///     }
/// };
///
/// // create KeyboardProvider, it implements DeviceProvider
/// PLUMA_INHERIT_PROVIDER(Keyboard, Device);
/// \endcode
///
/// plugin code:
/// \code
/// // Plugin registration function
/// PLUMA_PLUGIN_CONNECTION
/// bool connect(pluma::Host& host){
///     // add a keyboard provider to host
///     host.add( new KeyboardProvider() );
///     return true;
/// }
/// \endcode
///
////////////////////////////////////////////////////////////
