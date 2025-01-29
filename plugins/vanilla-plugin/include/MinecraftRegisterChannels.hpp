#pragma once

#include "PluginObjectImpl.hpp"
#include "protocolCraft/Utilities/CustomType.hpp"

#include <string>
#include <vector>

class MinecraftRegisterChannels : public PluginObjectImpl
{
private:
    std::vector<std::string> ReadChannels(ReadIterator& iter, size_t& length) const
    {
        const std::string null_delimited_strings = ReadRawString(iter, length, length);
        std::vector<std::string> output;
        const char* ptr = null_delimited_strings.data();

        while (ptr - null_delimited_strings.data() < null_delimited_strings.size())
        {
            // std::string(char*) truncates at the first \0
            output.push_back(std::string(ptr));
            ptr += output.back().size() + 1;
        }
        return output;
    }

    void WriteChannels(const std::vector<std::string>& channels, WriteContainer& container) const
    {
        for (int i = 0; i < channels.size(); ++i)
        {
            WriteRawString(channels[i], container);
            if (i < channels.size() - 1)
            {
                WriteData<unsigned char>(0, container);
            }
        }
    }

    SERIALIZED_FIELD(Channels, Internal::CustomType<std::vector<std::string>, &MinecraftRegisterChannels::ReadChannels, &MinecraftRegisterChannels::WriteChannels>);

    DECLARE_READ_WRITE_SERIALIZE;
};
