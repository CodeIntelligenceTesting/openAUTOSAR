project(crc)

# Add source files
file(GLOB c_files
    "src/*.c"
)

# Create static library
add_library(crc STATIC ${c_files})

# Add headers
target_include_directories(crc PUBLIC
    "include"
    "${PRJ_DIR}/include"
)

# Add fuzz target
add_fuzz_test(fuzz_crc "test/fuzztest.cpp" "test/mocklib.cpp")

# Link fuzz target with sut
target_link_libraries(fuzz_crc PRIVATE crc)

