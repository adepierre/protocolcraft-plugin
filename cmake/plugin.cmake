macro(define_plugin include_folders source_files)

    set(BASE_FILES
        "${GENERIC_CODE_PATH}/src/protocolcraft_plugin.cpp"
        "${PROTOCOLCRAFT_PATH}/src/BinaryReadWrite.cpp"
        "${PROTOCOLCRAFT_PATH}/src/Utilities/Json.cpp"
    )

    # Add the generic files to a "DO NOT EDIT" folder for IDE like Visual Studio
    source_group("_DO_NOT_EDIT" FILES ${BASE_FILES})

    add_library(${PROJECT_NAME} SHARED
        ${source_files}
        ${BASE_FILES}
    )

    set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
    set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)
    set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "_d")
    set_target_properties(${PROJECT_NAME} PROPERTIES RELWITHDEBINFO_POSTFIX "_rd")

    # Add include folders
    target_include_directories(${PROJECT_NAME} PUBLIC
        ${include_folders}
        "${GENERIC_CODE_PATH}/include"
        "${PROTOCOLCRAFT_PATH}/include"
    )

    # Set output folder for the shared library
    if(MSVC)
        # To avoid having folder for each configuration when building with Visual
        set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${PLUGINS_OUTPUT_DIR}")
        set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE "${PLUGINS_OUTPUT_DIR}")
        set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${PLUGINS_OUTPUT_DIR}")
        set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${PLUGINS_OUTPUT_DIR}")
        set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_DEBUG "${PLUGINS_OUTPUT_DIR}")
        set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_RELEASE "${PLUGINS_OUTPUT_DIR}")
        set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO "${PLUGINS_OUTPUT_DIR}")
        set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_MINSIZEREL "${PLUGINS_OUTPUT_DIR}")
    else()
        set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PLUGINS_OUTPUT_DIR}")
        set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${PLUGINS_OUTPUT_DIR}")
    endif(MSVC)

endmacro()
