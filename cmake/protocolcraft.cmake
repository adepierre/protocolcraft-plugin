function(_download_protocolcraft_file rel_path)
    file(DOWNLOAD "https://raw.githubusercontent.com/adepierre/Botcraft/master/protocolCraft/${rel_path}" "${CMAKE_CURRENT_BINARY_DIR}/protocolCraft/${rel_path}")
endfunction()

set(PROTOCOLCRAFT_PATH "${CMAKE_CURRENT_BINARY_DIR}/protocolCraft")

# Download only a few files from botcraft repo to avoid cloning all the repo
_download_protocolcraft_file(include/protocolCraft/BinaryReadWrite.hpp)
_download_protocolcraft_file(src/BinaryReadWrite.cpp)
_download_protocolcraft_file(include/protocolCraft/NetworkType.hpp)
_download_protocolcraft_file(include/protocolCraft/Utilities/Json.hpp)
_download_protocolcraft_file(src/Utilities/Json.cpp)
_download_protocolcraft_file(include/protocolCraft/Utilities/RecursiveWrapper.hpp)
_download_protocolcraft_file(include/protocolCraft/Utilities/Plugins/PluginObject.hpp)
