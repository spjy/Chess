// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include <iostream>
#include <cmath>
#include <algorithm>
#include "Board.h"

void Board::initializePawns(Color color, int row) {
  for (int i = 0; i < 8; i++) {
    this->board[row].push_back(new Pawn(color));
  }
}

void Board::initializeOpenSpots(int row) {
  for (int i = 0; i < 8; i++) {
    this->board[row].push_back(new Open());
  }
}

void Board::initializeCapitals(Color color, int row) {
  this->board[row].push_back(new Rook(color));
  this->board[row].push_back(new Knight(color));
  this->board[row].push_back(new Bishop(color));
  this->board[row].push_back(new King(color));
  this->board[row].push_back(new Queen(color));
  this->board[row].push_back(new Bishop(color));
  this->board[row].push_back(new Knight(color));
  this->board[row].push_back(new Rook(color));
}

Board::Board() {
  std::vector<Piece*> row;
  int i;

  for (i = 0; i < 8; i++) {
    this->board.push_back(row);
  }

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
  vector<vector<Piece*> > reversedBoard = this->board;

  // Reverse board so it is with respect to the white side.
  std::reverse(reversedBoard.begin(), reversedBoard.end());

  for (int i = 0; i < reversedBoard.size(); i++) {
    for (int j = 0; j < reversedBoard[i].size(); j++) {
      std::cout << reversedBoard[i][j]->getColorSymbol()
        << reversedBoard[i][j]->getSymbol() << ' ';
      if (j == reversedBoard[i].size() - 1) {
        std::cout << std::endl;
      }
    }
  }
}

// If movement isn't out off of the board, not if eaten

bool Board::checkIfOffBoard() {
  return true;
}

bool Board::movement(
  const Position &currentPosition,
  const Position &nextPosition) {
  // If within board constraints
  if (currentPosition.row >= 0 && currentPosition.row < 8
    && currentPosition.column >= 0 && currentPosition.column < 8
    && nextPosition.row >= 0 && nextPosition.row < 8
    && nextPosition.column >= 0 && nextPosition.column < 8) {
    Piece* currentPiece
      = this->board[currentPosition.row][currentPosition.column];

    this->board[currentPosition.row][currentPosition.column]
      ->clearPossibleMoves();

    Piece* nextPiece = this->board[nextPosition.row][nextPosition.column];

    // Check for moving, eating or invalid move.
    if (this->turn == currentPiece->getColor()) {  // Check if moving own piece
      if (nextPiece->getColor() == this->turn) {  // Move on self's pieces
        return false;
      } else if (nextPiece->getColor() == Color::NONE) {  // Move on empty piece
        bool move = currentPiece->move(board, currentPosition, nextPosition);

        if (move) {  // If move is valid
          Piece* tempPiece = this->board[nextPosition.row][nextPosition.column];
          this->board[nextPosition.row][nextPosition.column]
            = this->board[currentPosition.row][currentPosition.column];

          this->board[currentPosition.row][currentPosition.column] = tempPiece;
        }

        return move;
        // convert current position to open,
        // next position to piece that is being moved
      } else if (nextPiece->getColor() != Color::NONE
        && nextPiece->getColor() != this->turn) {  // Move on opposing piece
        bool eat = currentPiece->eat(board, currentPosition, nextPosition);

        if (eat) {
          this->board[nextPosition.row][nextPosition.column]
            = this->board[currentPosition.row][currentPosition.column];

          this->board[currentPosition.row][currentPosition.column]
            = new Open();
        }

        return eat;
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

std::string Board::endgameType() {
  // Loop through board
  // clear possible values
  // run get possible values move/eat
  // get king position and possible moves

  // first, check current turn things
  // check if king can move
  // check if nextPosition is threatened
  //

  for (int row = 0; row < this->board.size(); row++) {
    for (int column = 0; column < this->board[row].size(); column++) {
      std::cout << this->board[row][column]->getColorSymbol() << this->board[row][column]->getSymbol() << ' ';
      if (this->board[row][column]->getColor() != Color::NONE) {
        this->board[row][column]->clearPossibleMoves();
        this->board[row][column]->move(this->board, { row, column }, { 0, 0 });
        this->board[row][column]->eat(this->board, { row, column }, { 0, 0 });

        if (this->board[row][column]->getColor() == Color::WHITE) {
          if (this->board[row][column]->getSymbol() == 'k') {
            whiteKingMoves = this->board[row][column]->getPossibleMoves();
          }

          this->whiteMoves.insert(
            this->whiteMoves.end(),
            this->board[row][column]->getPossibleMoves().begin(),
            this->board[row][column]->getPossibleMoves().end());
        } else if (this->board[row][column]->getColor() == Color::BLACK) {
          if (this->board[row][column]->getSymbol() == 'k') {
            blackKingMoves = this->board[row][column]->getPossibleMoves();
          }

          this->blackMoves.insert(
            this->blackMoves.end(),
            this->board[row][column]->getPossibleMoves().begin(),
            this->board[row][column]->getPossibleMoves().end());
        }
      }
      if (column == this->board[row].size() - 1) {
        std::cout << std::endl;
      }
    }
  }

  // store threatening piece position

  // Check for check
}

void Board::clearWhiteMoves() {
  this->whiteMoves.clear();
}

void Board::clearBlackMoves() {
  this->blackMoves.clear();
}

bool Board::mate() {
  vector<Position> moves;

  if (this->turn == Color::WHITE) {  // black's turn after white went this turn
    // Loop through white moves, if
    for (int i = 0; i < this->whiteMoves.size(); i++) {
      if (this->whiteMoves[i] == this->blackKingPosition) {
        this->blackChecked = true;
      }
    }

    // if (this->blackChecked) {
    //   for (int i = 0; i < this->blackKingMoves.size(); i++) {
    //     for (int j = 0; i < this->whiteMoves.size(); i++) {
    //       if (this->blackKingMoves[i] == this->whiteMoves[i]) {

    //       }
    //       // if threatening piece can be killed
    //     }
    //   }
    //   if (this->blackKingMoves.size() == 0) {

    //   }
    // }
  } else if (this->turn == Color::BLACK) {
    for (int i = 0; i < this->blackKingMoves.size(); i++) {
      if (this->blackMoves[i] == this->whiteKingPosition) {
        this->whiteChecked = true;
      }
    }
  }
}
