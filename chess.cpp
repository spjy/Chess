// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include <iostream>
#include <string>
#include "Board.h"

using namespace std;

int main() {
  char current[2], move[2];
  Position currentPosition, nextPosition;

  Board board;

  board.printBoard();

  while (true) {
    cout << "Enter the piece you want to move (ex. a2):" << endl;
    cin >> current;

    currentPosition = {
      char_to_int(current[0]),  // convert letter to integer
      static_cast<int>(current[1]) - 49  // convert from char number to integer
    };

    cout << "Enter the spot you want to move to (ex. a3):" << endl;
    cin >> move;

    nextPosition = {
      char_to_int(move[0]),
      static_cast<int>(move[1]) - 49
    };

    bool moved = board.movement(currentPosition, nextPosition);

    if (moved) {
      cout << "Moved." << endl;
      board.changeTurn();
    } else {
      cout << "Could not move" << endl;
    }

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
