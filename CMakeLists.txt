cmake_minimum_required(VERSION 2.6)

project(pluma)

include_directories("include/")
include_directories("src/")
link_directories("lib/")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")
set(LIBRARY_OUTPUT_PATH  "lib/")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Wextra -DPLUMA_STATIC -DPLUMA_EXPORTS")

add_library(pluma STATIC src/Pluma/Dir.cpp src/Pluma/Dir.hpp src/Pluma/DLibrary.cpp src/Pluma/DLibrary.hpp src/Pluma/Host.cpp src/Pluma/PluginManager.cpp src/Pluma/Provider.cpp src/Pluma/uce-dirent.h)
target_link_libraries(pluma dl)
