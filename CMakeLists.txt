cmake_minimum_required ( VERSION 3.1.0 )

project ( RayTracer
  VERSION 3.0.0
  LANGUAGES CXX
)

# Set to c++11
set ( CMAKE_CXX_STANDARD 11 )

set ( SRC
    src/vec3.h
    src/main.cpp
)

# Executables
add_executable(RayTracer ${SRC})

#include_directories(src/common)