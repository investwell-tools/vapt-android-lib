cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fstack-protector-all")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wl,-z,relro -Wl,-z,now")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fstack-protector-all")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,-z,relro -Wl,-z,now")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Include directories for header files
include_directories(src/main/cpp/emu)  # Adjust this path as necessary
#include_directories(src/main/cpp/emu/Include)  # Adjust this path as necessary

add_library(toolChecker SHARED
        toolChecker.cpp
        EmulatorDetection.cpp
)


target_link_libraries(toolChecker
        android
        log)
