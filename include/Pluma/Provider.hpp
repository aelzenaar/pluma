////////////////////////////////////////////////////////////
//
// Pluma - Plug-in Management Framework
// Copyright (C) 2011 Gil Costa (gsaurus@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef PLUMA_PROVIDER_HPP
#define PLUMA_PROVIDER_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <Pluma\Config.hpp>
#include <string>


namespace pluma{
class Host;

////////////////////////////////////////////////////////////
/// \brief Interface to provide applications with objects from plugins.
///
////////////////////////////////////////////////////////////
class PLUMA_API Provider{
friend class Host;


public:

    ////////////////////////////////////////////////////////////
    /// \brief Destructor.
    ///
    ////////////////////////////////////////////////////////////
    virtual ~Provider();

    ////////////////////////////////////////////////////////////
    /// \brief Get provider version.
    ///
    /// \return Version number.
    ///
    ////////////////////////////////////////////////////////////
    virtual unsigned int getVersion() const = 0;

    ////////////////////////////////////////////////////////////
    /// \brief Check compatibility with host.
    ///
    /// The same provider may be compiled with different versions
    /// on host side and on plugins side. This function checks if
    /// a plugin provider is compatible with the current version of
    /// the same provider type on the host side.
    ///
    /// \param host Host, proxy of host application.
    ///
    /// \return True if it's compatible with \a host.
    ///
    ////////////////////////////////////////////////////////////
    bool isCompatible(const Host& host) const;


private:

    ////////////////////////////////////////////////////////////
    /// \brief Get provider type.
    ///
    /// Each provider defined on the host application is identified by
    /// a unique type. Those types are automatically managed internally by
    /// pluma.
    ///
    /// \return Provider type id.
    ///
    ////////////////////////////////////////////////////////////
    virtual std::string getType() const = 0;

};

}   // namespace pluma


#endif // PLUMA_PROVIDER_HPP


////////////////////////////////////////////////////////////
/// \class pluma::Provider
///
/// A host application define shared interfaces that tells what
/// plugins should implement. Plugins implement them by inheriting from
/// those interfaces.
/// The plugin specific implementations are unknown at the host side,
/// only the interfaces are known. Then, host app needs a generic way
/// of create interface objects.
/// That's what provider classes are about. Those classes can also be
/// called factories, as this is the factory design pattern in action
/// (http://www.oodesign.com/factory-pattern.html)
///
/// Host applications define specific provider types (by inheriting from
/// pluma::Provider). Hosts then use those tipes to get objects from the
/// plugins.
/// Plugins derive providers from the types required by the host. When
/// a plugin is connected, it add specific providers to the host, so that
/// the host can use them to create the interface objects.
///
///
/// Example: A host app uses objects of type Device. A certain plugin
/// defines a Keyboard, witch is a Device.
/// The Host will use DeviceProviders to create objects of type Device.
/// The plugin will provide host specifically with a KeyboardProvider.
/// Other plugins may provide host with other derived DeviceProvider types.
///
/// Device code (shared):
/// \code
/// class Device{
/// public:
///     virtual std::string getDescription() = 0;
/// };
/// // create DevicedProvider with version 6, compatible with at least v.3
/// PLUMA_GEN_PROVIDER(Device, 6, 3);
/// \endcode
///
/// Host application code:
/// \code
/// pluma::Pluma plugins;
/// // Tell it to accept providers of the type DeviceProvider
/// plugins.acceptProviderType<DeviceProvider>();
/// // Load some dll
/// plugins.load("plugins", "standard_devices");
/// // Get device providers into a vector
/// std::vector<DeviceProvider*> providers;
/// plugins.getProviders(providers);
/// // create a Device from the first provider
/// if (!providers.empty()){
///     Device* myDevice = providers.first()->create();
///     // do something with myDevice
///     std::cout << device->getDescription() << std::endl;
///     // (...)
///     delete myDevice;
/// }
/// \endcode
///
///
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
///     // (...)
/// };
///
/// // create KeyboardProvider, it is a DeviceProvider implementation
/// PLUMA_INHERIT_PROVIDER(Keyboard, Device);
/// \endcode
///
/// plugin code:
/// \code
/// PLUMA_PLUGIN_CONNECTION
/// bool connect(pluma::Host& host){
///     host.add( new KeyboardProvider() );
///     return true;
/// }
/// \endcode
///
////////////////////////////////////////////////////////////
