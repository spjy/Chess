// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include <iostream>
#include "Board.h"

void Board::initializePawns(Color color, int row) {
  for (int i = 0; i < 8; i++) {
    this->board[row].push_back(new Pawn(color, Position { row, i }));
  }
}

void Board::initializeOpenSpots(int row) {
  for (int i = 0; i < 8; i++) {
    this->board[row].push_back(new Open(Position { row, i }));
  }
}

void Board::initializeCapitals(Color color, int row) {
  this->board[row].push_back(new Rook(color, Position { row, 0 }));
  this->board[row].push_back(new Knight(color, Position { row, 1 }));
  this->board[row].push_back(new Bishop(color, Position { row, 2 }));
  this->board[row].push_back(new King(color, Position { row, 3 }));
  this->board[row].push_back(new Queen(color, Position { row, 4 }));
  this->board[row].push_back(new Bishop(color, Position { row, 5 }));
  this->board[row].push_back(new Knight(color, Position { row, 6 }));
  this->board[row].push_back(new Rook(color, Position { row, 7 }));
}

Board::Board() {
  std::vector<Piece*> row;
  // [8][8] //columns first, rows second.
  // Reserve capacity for each row
  int i;

  for (i = 0; i < 8; i++) {
    this->board.push_back(row);
  }

  // Reserve capacity for each column
  // for (i = 0; i < 7; i++) {
  //   this->board[i].resize(8);
  // }

  this->initializeCapitals(Color::WHITE, 0);
  this->initializePawns(Color::WHITE, 1);
  this->initializeOpenSpots(2);
  this->initializeOpenSpots(3);
  this->initializeOpenSpots(4);
  this->initializeOpenSpots(5);
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

void Board::printBoard() {
  // std::cout << this->board[0][1]->getSymbol() << std::endl;
  // int row = 0;
  // for (std::vector<Piece*> r : this->board) {
  //   int col = 0;
  //   for (Piece* c : this->board[row]) {
  //     std::cout << c->getSymbol();

  //     if (col == 7) {
  //       std::cout << std::endl;
  //     }

  //     col++;
  //   }
  //   row++;
  // }

  for (size_t i = 0; i < this->board.size(); i++) {
    for (size_t j = 0; j < this->board[i].size(); j++) {
      std::cout << this->board[i][j]->getSymbol() << ' ';
      if (j == this->board[i].size() - 1) {
        std::cout << this->board[i][j]->getSymbol() << std::endl;
      }
    }
  }
}

// If movement isn't out off of the board, not if eaten

bool Board::checkIfOffBoard() {
  return true;
}

bool Board::checkIfObstructed() {
  return true;
}

bool Board::movement() {
  return true;
}
