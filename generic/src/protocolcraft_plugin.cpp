#include "protocolcraft_plugin.hpp"
#include "protocolCraft/Utilities/Plugins/PluginObject.hpp"

#include <unordered_map>
#include <string>

std::unordered_map<std::string, std::function<ProtocolCraft::PluginObject* ()>>& known_types()
{
    static std::unordered_map<std::string, std::function<ProtocolCraft::PluginObject* ()>> types;
    return types;
}

ProtocolCraft::PluginObject* GetPluginObject(const char* type)
{
    auto it = known_types().find(type);
    if (it == known_types().end())
    {
        return nullptr;
    }

    return it->second();
}

void DestroyPluginObject(ProtocolCraft::PluginObject* a)
{
    if (a == nullptr)
    {
        return;
    }
    delete a;
}

void Register(const std::string& identifier, std::function<ProtocolCraft::PluginObject* ()> f)
{
    known_types()[identifier] = f;
}
