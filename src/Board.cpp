// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include <iostream>
#include "Board.h"

void Board::initializePawns(Color color, int row) {
  for (int i = 0; i < 8; i++) {
    this->board[row].push_back(new Pawn(color, Position { i, row }));
  }
}

void Board::initializeOpenSpots(int row) {
  for (int i = 0; i < 8; i++) {
    this->board[row].push_back(new Open(Position { i, row }));
  }
}

void Board::initializeCapitals(Color color, int row) {
  this->board[row].push_back(new Rook(color, Position { 0, row }));
  this->board[row].push_back(new Knight(color, Position { 1, row }));
  this->board[row].push_back(new Bishop(color, Position { 2, row }));
  this->board[row].push_back(new King(color, Position { 3, row }));
  this->board[row].push_back(new Queen(color, Position { 4, row }));
  this->board[row].push_back(new Bishop(color, Position { 5, row }));
  this->board[row].push_back(new Knight(color, Position { 6, row }));
  this->board[row].push_back(new Rook(color, Position { 7, row }));
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
  for (size_t i = 0; i < this->board.size(); i++) {
    for (size_t j = 0; j < this->board[i].size(); j++) {
      std::cout << this->board[i][j]->getSymbol() << ' ';
      if (j == this->board[i].size() - 1) {
        std::cout << std::endl;
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

bool Board::movement(Position currentPosition, Position nextPosition) {
  Piece* movingPiece = this->board[nextPosition.row][nextPosition.column];

  if (movingPiece->getColor() == this->turn) { // Move on self's pieces
    return false;
  } else if (movingPiece->getColor() == Color::NONE) { // Move on empty piece
    return movingPiece->move(currentPosition, nextPosition);
    // convert current position to open, next position to piece that is being moved
  } else if (movingPiece->getColor() != Color::NONE && movingPiece->getColor() != this->turn) { // Move on opposing piece
    return movingPiece->eat(currentPosition, nextPosition);
  }
  return false;
}

Color Board::getTurn() {
  return this->turn;
}

void Board::setTurn(Color turn) {
  this->turn = turn;
}

void Board::changeTurn() {
  if (this->turn == Color::WHITE) {
    this->turn = Color::BLACK;
  } else {
    this->turn = Color::WHITE;
  }
}
