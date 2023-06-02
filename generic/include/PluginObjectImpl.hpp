#pragma once

#include "protocolCraft/Utilities/Plugins/PluginObject.hpp"
#include "protocolCraft/BinaryReadWrite.hpp"
#include "protocolCraft/Utilities/Json.hpp"

class PluginObjectImpl : public ProtocolCraft::PluginObject
{
public:
    virtual ~PluginObjectImpl() {}

    /// @brief Deserialize raw data into this object
    /// @param ptr Pointer to the start of the data
    /// @param length Available data, will be updated with data read
    void Read(const unsigned char* ptr, unsigned long long int& length) final
    {
        std::vector<unsigned char> data(ptr, ptr + length);
        auto data_it = data.begin();
        size_t data_length = data.size();
        ReadImpl(data_it, data_length);
        ptr += length - data_length;
        length = static_cast<unsigned long long int>(data_length);
    }

    /// @brief Write this object into raw data
    /// @param size Will be assigned to the data size
    /// @return A pointer to the serialized data
    const unsigned char* Write(unsigned long long int& size) final
    {
        serialized_data.clear();
        WriteImpl(serialized_data);
        size = static_cast<unsigned long long int>(serialized_data.size());
        return serialized_data.data();
    }

    /// @brief Serialize this object into a null terminated json string
    /// @return A pointer to the start of the string
    const char* Serialize() final
    {
        serialized_json = SerializeImpl().Dump();
        return serialized_json.c_str();
    }

protected:
    virtual void ReadImpl(ProtocolCraft::ReadIterator& iter, size_t& length) = 0;
    virtual void WriteImpl(ProtocolCraft::WriteContainer& container) const = 0;
    virtual ProtocolCraft::Json::Value SerializeImpl() const = 0;

private:
    std::vector<unsigned char> serialized_data;
    std::string serialized_json;
};
