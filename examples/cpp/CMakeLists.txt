include(${PROJECT_SOURCE_DIR}/cmake/bitarray.cmake)

set(target "example_cpp")

# Buid target
add_executable(
    ${target}
    ${PROJECT_SOURCE_DIR}/examples/cpp/main.cpp
    ${bitarray_sources}
)

# Add includes
target_include_directories(${target}
    PRIVATE
    ${bitarray_includes}
)
