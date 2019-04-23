// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_KNIGHT_H_
#define INCLUDE_KNIGHT_H_

#include "Piece.h"

class Knight : public Piece {
 public:
  Knight(Color color, Position position);

  bool move(Position currentPosition, Position nextPosition) override;
  bool eat(Position currentPosition, Position nextPosition) override;
};

#endif  // INCLUDE_KNIGHT_H_
