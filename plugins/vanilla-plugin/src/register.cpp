#include "protocolcraft_plugin.hpp"
using namespace ProtocolCraft;

#include "MinecraftBrand.hpp"
#include "MinecraftRegisterChannels.hpp"

// Each type needs to be defined once
DEFINE_NETWORK_TYPE(MinecraftBrand);
DEFINE_NETWORK_TYPE(MinecraftRegisterChannels);

// But can be registered multiple times with diffeerent keys
#ifdef IS_FOR_1_12_2
REGISTER(MinecraftBrand, "MC|Brand");
REGISTER(MinecraftRegisterChannels, "REGISTER");
REGISTER(MinecraftRegisterChannels, "UNREGISTER");
#else
REGISTER(MinecraftBrand, "minecraft:brand");
REGISTER(MinecraftRegisterChannels, "minecraft:register");
REGISTER(MinecraftRegisterChannels, "minecraft:unregister");
#endif
