project (mycode)
cmake_minimum_required(VERSION 2.6)

include_directories($ENV{GMOCK_HOME}/include $ENV{GMOCK_HOME}/gtest/include)
link_directories($ENV{GMOCK_HOME}/mybuild $ENV{GMOCK_HOME}/gtest/mybuild)
add_definitions(-std=c++0x -v)


set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")


set(sources
   main.cpp
   Soundex.h
   SoundexTest.cpp)
add_executable(test ${sources})
target_link_libraries(test pthread)
target_link_libraries(test gmock)
target_link_libraries(test gtest)


