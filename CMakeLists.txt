cmake_minimum_required(VERSION 3.10)

project(AsteroidsPthreads)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
add_executable(
  main
  src/main.cpp
  src/Ui/Ui.cpp
  src/GameObjects/MovableObjects/MovableObject.cpp
  src/GameObjects/MovableObjects/Ship.cpp
  src/Ui/Util/ScreenSettingsInit.cpp
  src/GameObjects/MovableObjects/Projectile.cpp
  src/GameObjects/MovableObjects/Asteroids.cpp
  src/GameManager/GameManager.cpp
  src/GameThreads/GameThreads.cpp
  src/Init/Init.cpp
  src/PlayerInputs/PlayerInputs.cpp)

target_link_libraries(main PRIVATE pthread)
target_link_libraries(main PRIVATE ncurses)
