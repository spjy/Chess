cmake_minimum_required (VERSION 3.14)
project(chess)

find_program(CMAKE_MAKE_PROGRAM "C:/mingw32/bin/make.exe")
find_program(CMAKE_CXX_COMPILER "C:/mingw32/bin/g++.exe")

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH} C:/SFML-2.5.1/lib")
set(CMAKE_PREFIX_PATH "C:/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML COMPONENTS graphics window system main)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -std=c++11 -Wno-invalid-offsetof")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

include_directories("./include")

add_executable(chess ./src/Constants.cpp ./src/Piece.cpp ./src/Bishop.cpp ./src/King.cpp ./src/Knight.cpp ./src/Open.cpp ./src/Pawn.cpp ./src/Player.cpp ./src/Queen.cpp ./src/Rook.cpp ./src/Board.cpp chess.cpp)
target_link_libraries(chess sfml-graphics sfml-window sfml-system sfml-main)
