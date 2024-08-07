cmake_minimum_required(VERSION 3.20)
project(gtitem)

include_directories(include)

if(BUILD_SHARED_LIBS)
    add_library(${PROJECT_NAME} SHARED gtitem.c)
else()
    add_library(${PROJECT_NAME} STATIC gtitem.c)
endif()

install(TARGETS ${PROJECT_NAME} DESTINATION lib/${PROJECT_NAME})
install(FILES include/gtitem.h DESTINATION include/${PROJECT_NAME})