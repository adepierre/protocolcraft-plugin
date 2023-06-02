#pragma once

#include "PluginObjectImpl.hpp"

#include <string>
#include <vector>

class MinecraftRegisterChannels : public PluginObjectImpl
{
public:
    virtual ~MinecraftRegisterChannels()
    {

    }


    void SetChannels(const std::vector<std::string>& channels_)
    {
        channels = channels_;
    }


    const std::vector<std::string>& GetChannels() const
    {
        return channels;
    }

protected:
    virtual void ReadImpl(ProtocolCraft::ReadIterator& iter, size_t& length) override
    {
        const std::string null_delimited_strings = ProtocolCraft::ReadRawString(iter, length, length);

        channels.clear();
        const char* ptr = null_delimited_strings.data();

        while (ptr - null_delimited_strings.data() < null_delimited_strings.size())
        {
            // std::string(char*) truncates at the first \0
            channels.push_back(std::string(ptr));
            ptr += channels.back().size() + 1;
        }
    }

    virtual void WriteImpl(ProtocolCraft::WriteContainer& container) const override
    {
        for (int i = 0; i < channels.size(); ++i)
        {
            ProtocolCraft::WriteRawString(channels[i], container);
            if (i < channels.size() - 1)
            {
                ProtocolCraft::WriteData<unsigned char>(0, container);
            }
        }
    }

    virtual ProtocolCraft::Json::Value SerializeImpl() const override
    {
        ProtocolCraft::Json::Value output;

        output["channels"] = channels;

        return output;
    }

private:
    std::vector<std::string> channels;
};
