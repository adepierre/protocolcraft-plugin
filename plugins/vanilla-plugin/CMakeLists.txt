project(vanilla-plugin)

# List here specific options for your plugin (remove this entire section if you don't have any option)
################################################ EDIT ################################################
option(${PROJECT_NAME}_IS_FOR_1_12_2 "If ON, will create the default vanilla plugin for 1.12.2, if OFF it will be compatible with any >1.12.2 protocolcraft supported version" OFF)
################################################ EDIT ################################################



# Define all the source files specific to this plugin
# You **MUST** have at least one cpp file (usually containing the REGISTER calls)
# hpp files are optional, but required if you want them to show up in your IDE
set(${PROJECT_NAME}_SOURCE_FILES
################################################ EDIT ################################################
    ${CMAKE_CURRENT_SOURCE_DIR}/include/MinecraftBrand.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/MinecraftRegisterChannels.hpp

    ${CMAKE_CURRENT_SOURCE_DIR}/src/register.cpp
################################################ EDIT ################################################


)


# Define all include folders specific to this plugin
set(${PROJECT_NAME}_INCLUDE_FOLDERS
################################################ EDIT ################################################
    ${CMAKE_CURRENT_SOURCE_DIR}/include
################################################ EDIT ################################################
)


# Everything will be setup automatically using the define_plugin macro
define_plugin("${${PROJECT_NAME}_INCLUDE_FOLDERS}" "${${PROJECT_NAME}_SOURCE_FILES}")


# Add any plugin-specific configuration to the now defined generated ${PROJECT_NAME} plugin target
# (remove this entire section if you don't have any option)
################################################ EDIT ################################################
if (${PROJECT_NAME}_IS_FOR_1_12_2)
    target_compile_definitions(${PROJECT_NAME} PRIVATE IS_FOR_1_12_2=1)
endif()
################################################ EDIT ################################################
