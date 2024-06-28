cmake_minimum_required(VERSION 3.20)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
project(gtitem-c)

add_library(gtitem SHARED gtitem.c)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/items.dat DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(gtitem-test test.c)
target_link_libraries(gtitem-test gtitem)

enable_testing()
add_test(NAME gtitem-test COMMAND gtitem-test)  