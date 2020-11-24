cmake_minimum_required(VERSION 3.0.0)
project(Vettore_ordinato VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB my_sources *.h *.cpp)

add_executable(Vettore_ordinato ${my_sources})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
