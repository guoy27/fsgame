# Minimum CMake required
cmake_minimum_required(VERSION 2.8.12)

# Project
project(fsgame C CXX)

if (MSVC)
  # Add the "lib" prefix for generated .lib outputs.
  set(LIB_PREFIX lib)
else (MSVC)
  # When building with "make", "lib" prefix will be added automatically by
  # the build tool.
  set(LIB_PREFIX)
endif (MSVC)

set(DEBUG_POSTFIX "d"
  CACHE STRING "Default debug postfix")
mark_as_advanced(DEBUG_POSTFIX)

if (BUILD_SHARED_LIBS)
  set(SHARED_OR_STATIC "SHARED")
else (BUILD_SHARED_LIBS)
  set(SHARED_OR_STATIC "STATIC")
endif (BUILD_SHARED_LIBS)

get_filename_component( SOURCE_DIR ${fsgame_SOURCE_DIR} PATH)

message(STATUS "  SOURCE_DIR : ${SOURCE_DIR}")

message(STATUS "  Build Lib Type  : ${SHARED_OR_STATIC}")

set(BUILD_TEST ON)

include(libcommon.cmake)

include(libframesync.cmake)