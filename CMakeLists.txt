cmake_minimum_required(VERSION 3.22)

set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    message(STATUS "Found CCACHE!")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
endif()

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

set(PROJECT_NAME fsae_pdm)

# CMAKE project name, languages and version
project(${PROJECT_NAME}
    LANGUAGES C CXX ASM
    VERSION 0.0.1
)

# To enable colored terminal
option(FORCE_COLORED_OUTPUT "Always produce ANSI-colored output (GNU/Clang only.)" TRUE)
if (${FORCE_COLORED_OUTPUT})
    if ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
        add_compile_options(-fdiagnostics-color=always)
    elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        add_compile_options(-fcolor-diagnostics)
    endif()
endif()

# Reduce binary size. Might be used to code to fit in the MCU
option(GARBAGE_COLLECT_SECTIONS "Use -f{function,data}-sections and -Wl,--gc-sections." TRUE)
if (${GARBAGE_COLLECT_SECTIONS})
    add_compile_options(-ffunction-sections -fdata-sections)
    add_link_options(-Wl,--gc-sections)
endif()

# Process library subdirectories
add_subdirectory(Firmware)

