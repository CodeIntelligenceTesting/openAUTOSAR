project(canif)

# Add source files
file(GLOB c_files
    "src/*.c"
    "test/stubs.c"
)

# Create static library
add_library(canif STATIC ${c_files})


set_target_properties(canif PROPERTIES CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Add headers
target_include_directories(canif PUBLIC
    "include"
    "${PRJ_DIR}/include"
    "${PRJ_DIR}/debug/Det/include"
    "${PRJ_DIR}/boards/linuxOs/MCAL/Mcu/include"
    "${PRJ_DIR}/boards/linuxOs/MCAL/Can/include"
    "${PRJ_DIR}/communication/ComServices/PDURouter/include"
    "${PRJ_DIR}/communication/ComServices/Com/include"
)

set_target_properties(canif PROPERTIES CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_definitions(USE_PDUR USE_DET)

# Add fuzz target
add_fuzz_test(fuzz_canif "test/fuzztest.cpp" "test/mocklib.cpp")

# Link fuzz target with sut
target_link_libraries(fuzz_canif PRIVATE canif)

