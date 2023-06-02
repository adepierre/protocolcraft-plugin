#include "protocolcraft_plugin.hpp"

#include "MinecraftBrand.hpp"
#include "MinecraftRegisterChannels.hpp"

#ifdef IS_FOR_1_12_2
REGISTER(MinecraftBrand, "MC|Brand");
REGISTER(MinecraftRegisterChannels, "REGISTER");
REGISTER(MinecraftRegisterChannels, "UNREGISTER");
#else
REGISTER(MinecraftBrand, "minecraft:brand");
REGISTER(MinecraftRegisterChannels, "minecraft:register");
REGISTER(MinecraftRegisterChannels, "minecraft:unregister");
#endif
