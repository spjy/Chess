// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include <iostream>
#include <string>
#include "Board.h"

using namespace std;

int main() {
  string current, move;
  Position currentPosition, nextPosition;

  Board board;

  board.printBoard();

  while (true) {
    std::cout << "Enter the piece you want to move (ex. a2):" << std::endl;
    std::cin >> current;

    current[0] = char_to_int(current[0]);

    currentPosition.column = char_to_int(current[0]);
    currentPosition.row = current[1];

    std::cout << "Enter the spot you want to move to (ex. a3):" << std::endl;
    std::cin >> move;

    nextPosition.column = char_to_int(move[0]);
    nextPosition.row = move[1];

    board.changeTurn();

    board.printBoard();
  }

  // get the piece that i want to move
  // get the spot that i want to move to
  // check whether it is a movement or attack. Movement is on an empty space, attack is on an enemy piece, prevent moving on piece with same color
  // check if gt 0 and lt 7

  // if eat, make a new open piece
  // if movement, do a move constructor

  return 0;
}
