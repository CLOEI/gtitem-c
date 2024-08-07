cmake_minimum_required(VERSION 3.20)
project(gtitem-c)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_library(gtitem SHARED gtitem.c)