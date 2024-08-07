cmake_minimum_required(VERSION 3.20)
project(gtitem VERSION 1.0.0 LANGUAGES C)

include(GNUInstallDirs)

if(BUILD_SHARED_LIBS)
    add_library(${PROJECT_NAME} SHARED gtitem.c)
else()
    add_library(${PROJECT_NAME} STATIC gtitem.c)
endif()

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)