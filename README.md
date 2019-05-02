# Chess

## Requirements (Windows)

1. C++
2. CMake
3. SFML (GCC MinGW DW2) 2.5.1
4. MinGW 7.3.0

## Installing

```bash
git clone https://github.com/spjy/Chess.git
cd Chess
mkdir bin
cd bin
cmake -G "Unix Makefiles" ..
make
```

## Running

1. In /bin, the chess.exe file should be generated. Run it.

## Gotchas

Make sure you have compatible versions of SFML and MinGW. They must match exactly.

# Classes 

* Pieces
  * Parent class of Pawn, Rook, Knight, Bishop, Queen, King
  * Stores the piece color, symbol
  * Calculates the possible eat and move positions
* Board
  * Initializes the pieces on the board
  * Prints the board
  * Handles movement checking
  * Handles turn

# Features Implemented

* Movement constraints on all pieces
* Board user interface through text
* Turn based moves with another person (black and white sides)

# Challenges

* Stale, stalemate, checkmate checking
  * It was more complicated than we thought. There was much more logic and info we needed to store to implement the checking correctly.
* Checking for valid piece movements, especially those that had unlimited moves

# Cool Tools Used

* CMake
* Git
  
# OOP Concepts
  * Inheritance (between pieces)
  * Polymorphism (piece class function overloading)
  * Abstraction (public and private)
  * Encapsulation (classes)
