#pragma once

#include "PluginObjectImpl.hpp"

#include <string>

class MinecraftBrand : public PluginObjectImpl
{
public:
    virtual ~MinecraftBrand()
    {

    }


    void SetServerBrand(const std::string& server_brand_)
    {
        server_brand = server_brand_;
    }


    const std::string& GetServerBrand() const
    {
        return server_brand;
    }

protected:
    virtual void ReadImpl(ProtocolCraft::ReadIterator& iter, size_t& length) override
    {
        server_brand = ProtocolCraft::ReadData<std::string>(iter, length);
    }

    virtual void WriteImpl(ProtocolCraft::WriteContainer& container) const override
    {
        ProtocolCraft::WriteData<std::string>(server_brand, container);
    }

    virtual ProtocolCraft::Json::Value SerializeImpl() const override
    {
        ProtocolCraft::Json::Value output;

        output["server_brand"] = server_brand;

        return output;
    }

private:
    std::string server_brand;
};
