// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "Board.h"

Board::Board() {
  // [8][8] //columns first, rows second.
  // Reserve capacity for each row
  board.resize(8);

  int i;

  // Reserve capacity for each column
  for (i = 0; i < 8; i++) {
    board[i].resize(8);
  }

  this->initializeCapitals(Color::WHITE, 0);
  this->initializePawns(Color::WHITE, 1);
  this->initializePawns(Color::BLACK, 6);
  this->initializeCapitals(Color::BLACK, 7);

  // How the board looks.
  //[
  //  [0,1,2,3,4,5,6,7] // 0 black capitals/white touch down
  //  [0,1,2,3,4,5,6,7] // 1 black pawns
  //  [0,1,2,3,4,5,6,7] // 2 war zone
  //  [0,1,2,3,4,5,6,7] // 3 war zone
  //  [0,1,2,3,4,5,6,7] // 4 war zone
  //  [0,1,2,3,4,5,6,7] // 5 war zone
  //  [0,1,2,3,4,5,6,7] // 6 white pawns
  //  [0,1,2,3,4,5,6,7] // 7 white capitals/black touch down
  //]
}

void Board::initializePawns(Color color, int row) {
  for (int i = 0; i < 8; i++) {
    Pawn pawn(color, Position { row, i });

    Pawn *ptr = &pawn;

    this->board[row][i] = ptr;
  }
}

void Board::initializeCapitals(Color color, int row) {
  Rook rook(color, Position { row, 0 });
  Knight knight(color, Position { row, 1 });
  Bishop bishop(color, Position { row, 2 });
  King king(color, Position { row, 3 });
  Queen queen(color, Position { row, 4 });
  Bishop bishop1(color, Position { row, 5 });
  Knight knight1(color, Position { row, 6 });
  Rook rook1(color, Position { row, 7 });
}

// If movement isn't out off of the board, not if eaten

bool Board::checkIfOffBoard() {
}

bool Board::checkIfObstructed() {
}

bool Board::movement() {
}
