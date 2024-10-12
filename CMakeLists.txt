cmake_minimum_required(VERSION 3.10)

project(AsteroidsPthreads)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main src/main.cpp src/Ui/Ui.cpp)

target_link_libraries(main PRIVATE pthread)
target_link_libraries(main PRIVATE ncurses)
