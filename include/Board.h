// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_BOARD_H_
#define INCLUDE_BOARD_H_

#include "Constants.h"
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
#include "King.h"
#include "Open.h"

using std::vector;

class Board {
 public:
  vector<vector<Piece*> > board;
  Color turn = Color::WHITE;

  Board();
  void initializePawns(Color color, int row);
  void initializeOpenSpots(int row);
  void initializeCapitals(Color color, int row);
  void printBoard();

  bool checkIfOffBoard();
  bool checkIfObstructed();
  bool movement(Position currentPosition, Position nextPosition);

  Color getTurn();

  void setTurn(Color turn);

  void changeTurn();
};

#endif  // INCLUDE_BOARD_H_
