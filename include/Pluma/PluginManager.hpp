////////////////////////////////////////////////////////////
//
// Pluma - Plugin Minimal Architecture
// Copyright (C) 2010 Gil Costa (gsaurus@gmail.com)
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

#ifndef PLUMA_PLUGIN_MANAGER_HPP
#define PLUMA_PLUGIN_MANAGER_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <Pluma\Config.hpp>
#include <pluma\Host.hpp>

#include <string>
#include <map>

namespace pluma{
class DLibrary;

////////////////////////////////////////////////////////////
/// \brief Manages loaded plugins.
///
////////////////////////////////////////////////////////////
class PLUMA_API PluginManager{


public:

    ////////////////////////////////////////////////////////////
    /// \brief Destructor.
    ///
    ////////////////////////////////////////////////////////////
    ~PluginManager();

    ////////////////////////////////////////////////////////////
    /// \brief Load a plugin.
    ///
    /// \param path Path for the plugin.
    ///
    /// \return True if the plugin is successfully loaded.
    ///
    /// \see unload
    /// \see unloadAll
    ///
    ////////////////////////////////////////////////////////////
    bool load(const std::string& path);

    ////////////////////////////////////////////////////////////
    /// \brief Unload a plugin.
    ///
    /// \param pluginName Name or Path for the plugin.
    ///
    /// \return True if the plugin is successfully unloaded,
    /// false if no such plugin exists on the manager.
    ///
    /// \see load
    /// \see unloadAll
    ///
    ////////////////////////////////////////////////////////////
    bool unload(const std::string& pluginName);

    ////////////////////////////////////////////////////////////
    /// \brief Unload all loaded plugins.
    ///
    /// \see load
    /// \see unload
    ///
    ////////////////////////////////////////////////////////////
    void unloadAll();

    ////////////////////////////////////////////////////////////
    /// \brief Directly add a new provider.
    ///
    /// \param provider Provider.
    ///
    ////////////////////////////////////////////////////////////
    bool addProvider(Provider* provider);


protected:

    ////////////////////////////////////////////////////////////
    /// \brief Default constructor.
    ///
    /// PluginManager cannot be publicly instantiated.
    ///
    ////////////////////////////////////////////////////////////
    PluginManager();

    ////////////////////////////////////////////////////////////
    /// \brief Regist a provider type
    ///
    /// \param type Provider type.
    /// \param version Current version of thatprovider type.
    /// \param lowestVersion Lowest compatible version of that provider type.
    ///
    /// \see Host::registType
    ///
    ////////////////////////////////////////////////////////////
    void registType(const std::string& type, unsigned int version, unsigned int lowestVersion);

    ////////////////////////////////////////////////////////////
    /// \brief Get providers of a certain type.
    ///
    /// \param type Provider type.
    ///
    /// \return Pointer to the list of providers of that \a type,
    /// or NULL if \a type is not registered.
    ///
    /// \see Host::getProviders
    ///
    ////////////////////////////////////////////////////////////
    const std::list<Provider*>* getProviders(const std::string& type) const;


private:

    ////////////////////////////////////////////////////////////
    /// \brief Get the plugin name (without extension) from its path
    ///
    /// \param path Plugin path.
    ///
    /// \return Name of the plugin.
    ///
    /// \see load
    /// \see unload
    ///
    ////////////////////////////////////////////////////////////
    static std::string getPluginName(const std::string& path);


private:

    /// Signature for the plugin's registration function
    typedef bool fnRegisterPlugin(Host&);
    typedef std::map<std::string,DLibrary*> LibMap;

    LibMap libraries;   ///< Map containing the loaded libraries
    Host host;          ///< Host app proxy, holding all providers

};

}   // namespace pluma

#endif // PLUMA_PLUGIN_MANAGER_HPP
