////////////////////////////////////////////////////////////
/// \mainpage
///
/// \section welcome Welcome
/// Welcome to Pluma documentation. Here you will find a detailed
/// view of all Pluma <a href="./annotated.htm">classes</a>.<br>
/// If you are looking for support, you can visit the official website
/// at <a href="http://pluma-framework.sourceforge.net/">http://pluma-framework.sourceforge.net/</a>.<br><br>
///
/// CSS based on <a href="http://www.sfml-dev.org/documentation/1.6/">SFML1.6 documentation</a><br>
///
/// \section example Short Example
/// A short example to demonstrate Pluma usage:<br>
/// A host application define a Device interface. A certain plugin
/// defines a Keyboard, witch is a Device.
/// The host will use DeviceProviders to create objects of type Device.
/// The plugin will provide host specifically with a KeyboardProvider.<br>
///
/// Device hpp (shared):
/// \code
/// #include <Pluma/Pluma.hpp>
/// class Device{
/// public:
///     virtual std::string getDescription() const = 0;
/// };
/// // create DevicedProvider class
/// PLUMA_PROVIDER_HEADER(Device);
/// \endcode
///
/// Device cpp (shared):
/// \code
/// #include "Device.hpp"
/// generate DevicedProvider with version 6, and compatible with at least v.3
/// PLUMA_PROVIDER_SOURCE(Device, 6, 3);
/// \endcode
///
///
/// <br>
/// Keyboard code on the plugin side:
/// \code
/// #include <Pluma/Pluma.hpp>
/// #include "Device.hpp"
///
/// class Keyboard: public Device{
/// public:
///     std::string getDescription() const{
///         return "keyboard";
///     }
/// };
///
/// // create KeyboardProvider, it implements DeviceProvider
/// PLUMA_INHERIT_PROVIDER(Keyboard, Device);
/// \endcode
///
/// plugin connector:
/// \code
/// #include <Pluma/Connector.hpp>
/// #include "Keyboard.hpp"
///
/// PLUMA_CONNECTOR
/// bool connect(pluma::Host& host){
///     // add a keyboard provider to host
///     host.add( new KeyboardProvider() );
///     return true;
/// }
/// \endcode
///
///
/// Host application code:
/// \code
/// #include <Pluma/Pluma.hpp>
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
///     // Load library "standard_devices" from folder "plugins"
///     plugins.load("plugins", "standard_devices");
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
///     return 0;
/// }
/// \endcode
///
////////////////////////////////////////////////////////////
