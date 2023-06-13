cmake_minimum_required(VERSION 3.16)
project(openAUTOSAR)

set(PRJ_DIR ${PROJECT_SOURCE_DIR})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include cifuzz cmake package
find_package(cifuzz NO_SYSTEM_ENVIRONMENT_PATH)
enable_fuzz_testing()

# Apply compiler flags to every C files
file(GLOB_RECURSE C_FILES ${CMAKE_SOURCE_DIR}/*.c)
foreach(file ${C_FILES})
    set_source_files_properties(${file} PROPERTIES COMPILE_OPTIONS
        -fPIC
        -ggdb3
        -O0
        -m32
        -fshort-enums
    )
endforeach()

# Include all the different modules
add_subdirectory("system/Crc") # fuzz_crc
add_subdirectory("communication/CAN/CanIf") # fuzz_canif

