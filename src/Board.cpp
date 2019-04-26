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
  //  [A8,B8,C8,D8,E8,F8,G8,H8] // 0 black capitals/white touch down
  //  [0,1,2,3,4,5,6,7] // 1 black pawns
  //  [0,1,2,3,4,5,6,7] // 2 war zone
  //  [0,1,2,3,4,5,6,7] // 3 war zone
  //  [0,1,2,3,4,5,6,7] // 4 war zone
  //  [0,1,2,3,4,5,6,7] // 5 war zone
  //  [0,1,2,3,4,5,6,7] // 6 white pawns
  //  [A1,B1,C1,D1,E1,F1,G1,H1] // 7 white capitals/black touch down
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
  if (currentPosition.row > 0 && currentPosition.column > 0 && nextPosition.row < 8 && nextPosition.column < 8) { // If within board constraints
    Piece* currentPiece = this->board[currentPosition.row][currentPosition.column];
    Piece* nextPiece = this->board[nextPosition.row][nextPosition.column];
    
    if (this->turn == currentPiece->getColor()) { // Check if moving own piece
      if (nextPiece->getColor() == this->turn) { // Move on self's pieces
        return false;
      } else if (nextPiece->getColor() == Color::NONE) { // Move on empty piece
        bool move = currentPiece->move(currentPosition, nextPosition);

        if (move) { // If move is valid
          Piece* tempPiece = this->board[nextPosition.row][nextPosition.column];
          this->board[nextPosition.row][nextPosition.column] = this->board[currentPosition.row][currentPosition.column];
        
          this->board[currentPosition.row][currentPosition.column] = tempPiece;
        }

        return move;
        // convert current position to open, next position to piece that is being moved
      } else if (nextPiece->getColor() != Color::NONE && currentPiece->getColor() != this->turn) { // Move on opposing piece
        return currentPiece->eat(currentPosition, nextPosition);
      }
    }
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
    cout << "Black to move." << endl;
  } else {
    this->turn = Color::WHITE;
    cout << "White to move." << endl;
  }
}
