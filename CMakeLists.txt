cmake_minimum_required ( VERSION 3.1.0 )

project ( RayTracer
  VERSION 3.0.0
  LANGUAGES CXX
)

# Set to c++11
set ( CMAKE_CXX_STANDARD 11 )

set ( SRC
    src/utility.h
    src/vec3.h
    src/ray.h
    src/color.h
    src/hittable.h
    src/sphere.h
    src/hittable_list.h
    src/camera.h
    src/main.cpp
)

# Executables
add_executable(RayTracer ${SRC})

#include_directories(src/common)