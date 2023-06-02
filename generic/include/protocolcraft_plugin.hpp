#pragma once
#include <string>

#include <functional>

namespace ProtocolCraft
{
    class PluginObject;
}

// Interface stuff
extern "C"
{
    ProtocolCraft::PluginObject* GetPluginObject(const char* type);
    void DestroyPluginObject(ProtocolCraft::PluginObject* a);
}

/// @brief Register a function to create an object from the plugin
/// @param identifier The identifier of the object
/// @param f The function constructing the object
void Register(const std::string& identifier, std::function<ProtocolCraft::PluginObject* ()> f);

// We need to add __LINE__ to make sure we don't define twice the same struct
// if we do register multiple times the same Name with different identifiers
// And to do so we need this weird double nested macro because of reasons
#define CONCAT_IMPL(a, b) register_a##b
#define CONCAT(a, b) CONCAT_IMPL(a, b)

// Register a class Name under a given identifier.
// Identifier must be a double quoted string, e.g. "minecraft:identifier"
#define REGISTER(Name, identifier)                                                          \
    static_assert(true, identifier " must be string litteral");                             \
    namespace                                                                               \
    {                                                                                       \
        struct CONCAT(Name, __LINE__)                                                       \
        {                                                                                   \
            CONCAT(Name, __LINE__)() { Register(identifier, []() { return new Name(); }); } \
        } CONCAT(Name, __LINE__);                                                           \
    }
