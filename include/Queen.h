// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_QUEEN_H_
#define INCLUDE_QUEEN_H_

#include "Piece.h"

class Queen : public Piece {
 public:
  Queen(Color color, Position position);

  bool move(const Position &currentPosition, const Position &nextPosition) override;
  bool eat(const Position &currentPosition, const Position &nextPosition) override;
};

#endif  // INCLUDE_QUEEN_H_
