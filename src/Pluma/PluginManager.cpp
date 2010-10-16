////////////////////////////////////////////////////////////
//
// Pluma - Plug-in Management Framework
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


////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <Pluma\PluginManager.hpp>
#include <Pluma\DLibrary.hpp>
#include <cstdio>

namespace pluma{

////////////////////////////////////////////////////////////
PluginManager::PluginManager(){
    // Nothing to do
}


////////////////////////////////////////////////////////////
PluginManager::~PluginManager(){
    unloadAll();
}


////////////////////////////////////////////////////////////
bool PluginManager::load(const std::string& path){
    std::string plugName = getPluginName(path);
    DLibrary* lib = DLibrary::load(path);
    if (!lib) return false;

    fnRegisterPlugin* registFunction;
    registFunction = reinterpret_cast<fnRegisterPlugin*>(lib->getSymbol("connect"));

    if(!registFunction){
        fprintf(stderr, "Failed to initialize plugin \"%s\": connect function not found\n", plugName.c_str());
        delete lib;
        return false;
    }
    // try to initialize plugin:
    if (!registFunction(host)){
        // plugin decided to fail
        fprintf(stderr, "Self registry failed on plugin \"%s\".\n", plugName.c_str());
        host.cancelAddictions();
        delete lib;
        return false;
    }
    // Everything's fine, so store the library
    if (host.confirmAddictions())
        libraries[plugName] = lib;
    return true;
}


////////////////////////////////////////////////////////////
bool PluginManager::unload(const std::string& pluginName){
    std::string plugName = getPluginName(pluginName);
    LibMap::iterator it = libraries.find(plugName);
    if( it != libraries.end() ) {
        delete it->second;
        libraries.erase(it);
        return true;
    }
    return false;
}


////////////////////////////////////////////////////////////
void PluginManager::unloadAll(){

    host.clearProviders();
    LibMap::iterator it;
    for (it = libraries.begin() ; it != libraries.end() ; ++it){
        delete it->second;
    }
    libraries.clear();
}


////////////////////////////////////////////////////////////
std::string PluginManager::getPluginName(const std::string& path){
    size_t lastDash = path.find_last_of("/\\");
    size_t lastDot = path.find_last_of('.');
    if (lastDash == std::string::npos)lastDash = 0;
    else ++lastDash;
    if (lastDot == std::string::npos)lastDot = path.length();
    if (lastDot > lastDash) return path.substr(lastDash, lastDot-lastDash);
    else return path;
}


////////////////////////////////////////////////////////////
void PluginManager::registType(const std::string& type, unsigned int version, unsigned int lowestVersion){
    host.registType(type, version, lowestVersion);
}


////////////////////////////////////////////////////////////
bool PluginManager::addProvider(Provider* provider){
    if (provider == NULL){
        fprintf(stderr, "Trying to add null provider\n");
        return false;
    }
    return host.registProvider(provider);
}


////////////////////////////////////////////////////////////
const std::list<Provider*>* PluginManager::getProviders(const std::string& type) const{
    return host.getProviders(type);
}



}   // namespace pluma

