// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_ROOK_H_
#define INCLUDE_ROOK_H_

#include "Piece.h"

class Rook : public Piece {
 public:
  Rook(Color color, Position position);

  bool move(const Position &currentPosition, const Position &nextPosition) override;
  bool eat(const Position &currentPosition, const Position &nextPosition) override;
};

#endif  // INCLUDE_ROOK_H_

// Algorithm for rook
// Check if Rook is going row or column wise,
// -> can be done by checking if row/col is the same

// Get dist. <-> curr. pos. and target pos.
// Loop over row/col depending on movement of Rook.
// Loop from lowest value pos. up to other pos.
// ^ -> lowest value pos. could be either curr. or target pos.
// Do this loop within the move/eat functions. *********
// Check if there is a none open piece in it's way. 

