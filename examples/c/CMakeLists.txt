include(${PROJECT_SOURCE_DIR}/cmake/bitarray.cmake)

set(target "example_c")

# Buid target
add_executable(
    ${target}
    ${PROJECT_SOURCE_DIR}/examples/c/main.c
    ${bitarray_sources}
)

# Add includes
target_include_directories(${target}
    PRIVATE
    ${bitarray_includes}
)
