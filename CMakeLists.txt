cmake_minimum_required(VERSION 3.22)

# Setup compiler settings
set(CMAKE_TRY_COMPILE_TARGET_TYPE   "STATIC_LIBRARY")
set(CMAKE_C_STANDARD                11)
set(CMAKE_C_STANDARD_REQUIRED       ON)
set(CMAKE_C_EXTENSIONS              ON)
set(CMAKE_CXX_STANDARD              20)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)
set(CMAKE_CXX_EXTENSIONS            ON)
set(CMAKE_COLOR_DIAGNOSTICS         ON)
if(NOT ${CMAKE_HOST_SYSTEM_NAME} MATCHES "Linux")
    set(CMAKE_SYSTEM_NAME           Generic) # workaround for Windows
endif()


set_property(GLOBAL PROPERTY RULE_MESSAGES OFF)

project(bitarray VERSION 0.0.1 LANGUAGES C CXX ASM)

add_subdirectory(examples)
