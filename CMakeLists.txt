cmake_minimum_required(VERSION 3.31.0)
project(textadventure VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(textadventure textadventure-main.cc)

set_property(TARGET textadventure PROPERTY CXX_STANDARD 20)
