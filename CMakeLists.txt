cmake_minimum_required(VERSION 3.19)

project(protocolcraft-plugin)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(PLUGINS_OUTPUT_DIR "${CMAKE_SOURCE_DIR}/bin" CACHE PATH "All built plugins will be generated here")

# Include the macro to create plugin subprojects
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/plugin.cmake")

# Download only the part of protocolcraft we need
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/protocolcraft.cmake")

set(GENERIC_CODE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/generic")

# Add all plugin folders
add_subdirectory(plugins)
