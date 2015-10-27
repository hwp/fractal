# Author : Weipeng He <heweipeng@gmail.com>
# Copyright (c) 2015, All rights reserved.

cmake_minimum_required(VERSION 2.6)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

project(Fractal)

include(FindPkgConfig)

find_package(GSL REQUIRED)
include_directories(${GSL_INCLUDE_DIRS})

set(CMAKE_C_FLAGS "-Wall -D_GNU_SOURCE")

add_subdirectory(src)

