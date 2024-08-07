cmake_minimum_required(VERSION 3.20)
project(gtitem VERSION 1.0.0 LANGUAGES C)

include(GNUInstallDirs)

if(BUILD_SHARED_LIBS)
    add_library(${PROJECT_NAME} SHARED gtitem.c)
else()
    add_library(${PROJECT_NAME} STATIC gtitem.c)
endif()

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1)

install(TARGETS ${PROJECT_NAME}
    EXPORT gtitemConfig
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})

install(EXPORT gtitemConfig
    DESTINATION share/gtitem/cmake)

export(TARGETS ${PROJECT_NAME}
    FILE ${CMAKE_BINARY_DIR}/gtitemConfig.cmake)