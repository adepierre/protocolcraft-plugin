#pragma once

#include "PluginObjectImpl.hpp"

#include <string>

class MinecraftBrand : public PluginObjectImpl
{
    SERIALIZED_FIELD(ServerBrand, std::string);

    DECLARE_READ_WRITE_SERIALIZE;
};
