// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_ROOK_H_
#define INCLUDE_ROOK_H_

#include "Piece.h"

class Rook : public Piece {
 public:
  Rook(Color color, Position position);

  bool move(Position currentPosition, Position nextPosition) override;
  bool eat(Position currentPosition, Position nextPosition) override;
};

#endif  // INCLUDE_ROOK_H_
