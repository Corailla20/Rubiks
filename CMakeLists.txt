CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(Rubiks)

FIND_PACKAGE(VTK REQUIRED)

INCLUDE(${VTK_USE_FILE} )

ADD_EXECUTABLE(Rubiks rubiks_source.cpp rubiks_source.h)

TARGET_LINK_LIBRARIES(Rubiks ${VTK_LIBRARIES} )