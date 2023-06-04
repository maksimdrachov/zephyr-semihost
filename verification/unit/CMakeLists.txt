# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

# Set flags for semihost
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-lrdimon")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --specs=rdimon.specs")

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(semihost)

if(CONFIG_CPP)
  message(STATUS "adding main.cpp")
  FILE(GLOB app_sources src/*.cpp src/*.hpp)
  target_sources(app PRIVATE ${app_sources})
else()
  message(STATUS "adding main.c")
  FILE(GLOB app_sources src/*.c src/*.h)
  target_sources(app PRIVATE ${app_sources})
endif()

# FILE(GLOB app_sources src/*.c src/*.h)
# target_sources(app PRIVATE ${app_sources})
zephyr_include_directories(include)
zephyr_sources(include/semihost_extra.c)