cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(Tetris)
set(SOURCES
 src/main.cpp
 src/Block.cpp
 src/Shape.cpp
 src/Zone.cpp)
set(HEADERS
 headers/Block.h
 headers/Shape.h
 headers/Zone.h
 headers/Globals.h)
 add_executable(tetris ${SOURCES} ${HEADERS})