cmake_minimum_required(VERSION 3.5.0)
project(sort VERSION 0.1.0 LANGUAGES C CXX)

set(SOURCES main.cpp Sort.cpp RandomArray.cpp)
set(HEADERS Sort.h RandomArray.h)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})