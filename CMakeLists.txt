#********************************************************************
# (C) DaVinci Engineering GmbH 2022
#*******************************************************************/
cmake_minimum_required(VERSION 3.16)

# Export compile commands for use by other tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include cifuzz cmake package
find_package(cifuzz NO_SYSTEM_ENVIRONMENT_PATH)
enable_fuzz_testing()

project(openAUTOSAR)
message("CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")
if(CMAKE_CROSSCOMPILING)
    set (CMAKE_C_FLAGS "Options For Cross Compiling")

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

    set (CMAKE_C_FLAGS "-g -O0 -c -std=gnu99 -Wall")

    add_subdirectory(common)
    add_subdirectory(debug)
    add_subdirectory(diagnostic)
    add_subdirectory(rte)
    add_subdirectory(communication)
    add_subdirectory(memory)
    add_subdirectory(iohwabs)
    add_subdirectory(system)
    #add_subdirectory(arch/x64/drivers)
    #add_subdirectory(arch/arm/arm_cm3/scripts)
    #add_subdirectory(examples)
    add_subdirectory(boards/linuxOs)

endif()
