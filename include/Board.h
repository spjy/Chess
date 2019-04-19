// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_BOARD_H_
#define INCLUDE_BOARD_H_

#include <iostream>
#include <vector>
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
#include "King.h"
#include "Open.h"

class Board {
 public:
  std::vector<std::vector<Piece*> > board;

  Board();
  void initializePawns(Color color, int row);
  void initializeOpenSpots(int row);
  void initializeCapitals(Color color, int row);
  void printBoard();
  bool checkIfOffBoard();
  bool checkIfObstructed();
  bool movement();
};

#endif  // INCLUDE_BOARD_H_
