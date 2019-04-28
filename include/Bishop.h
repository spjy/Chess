// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_BISHOP_H_
#define INCLUDE_BISHOP_H_

#include "Piece.h"

class Bishop : public Piece {
 public:
  Bishop(Color color, Position position);

  bool move(const Position &currentPosition, const Position &nextPosition) override;
  bool eat(const Position &currentPosition, const Position &nextPosition) override;
};

#endif  // INCLUDE_BISHOP_H_
