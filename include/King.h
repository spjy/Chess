// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_KING_H_
#define INCLUDE_KING_H_

#include "Piece.h"

class King : public Piece {
 public:
  King(Color color, Position position);

  bool move(Position currentPosition, Position nextPosition) override;
  bool eat(Position currentPosition, Position nextPosition) override;
};

#endif  // INCLUDE_KING_H_
