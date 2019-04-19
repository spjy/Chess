cmake_minimum_required (VERSION 3.14)
project("chess")

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH} C:/SFML-2.5.1/lib")
set(CMAKE_PREFIX_PATH "C:/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML COMPONENTS graphics window system main)

set(CMAKE_MAKE_PROGRAM "C:/Program Files (x86)/mingw-w64/i686-7.3.0-posix-dwarf-rt_v5-rev0/mingw32/bin/make.exe")
set(CMAKE_CXX_COMPILER "C:/Program Files (x86)/mingw-w64/i686-7.3.0-posix-dwarf-rt_v5-rev0/mingw32/bin/g++.exe")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -std=c++11 -Wno-invalid-offsetof")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

#./src/Bishop.cpp ./src/Board.cpp ./src/Constants.cpp ./src/King.cpp ./src/main.cpp ./src/Open.cpp ./src/Pawn.cpp ./src/Piece.cpp ./src/Player.cpp ./src/Queen.cpp ./src/Rook.cpp

add_executable(chess SFML.cpp)
target_link_libraries(chess sfml-graphics sfml-window sfml-system sfml-main)
