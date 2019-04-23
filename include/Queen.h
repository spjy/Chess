// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_QUEEN_H_
#define INCLUDE_QUEEN_H_

#include "Piece.h"

class Queen : public Piece {
 public:
  Queen(Color color, Position position);

  bool move(Position currentPosition, Position nextPosition) override;
  bool eat(Position currentPosition, Position nextPosition) override;
};

#endif  // INCLUDE_QUEEN_H_
