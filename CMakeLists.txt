cmake_minimum_required(VERSION 3.16)
project(MyGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Force use of MinGW
set(CMAKE_C_COMPILER "C:/msys64/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe")

set(SFML_DIR "C:/msys64/mingw64/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES FALSE)

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

add_executable(game 
    src/main.cpp
    src/board.cpp
    src/pawn.cpp
    src/bishop.cpp
    src/rook.cpp
    src/knight.cpp
)

target_link_libraries(game 
    sfml-graphics
    sfml-window
    sfml-system
)
