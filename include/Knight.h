// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_KNIGHT_H_
#define INCLUDE_KNIGHT_H_

#include "Piece.h"

class Knight : public Piece {
 public:
  Knight(Color color, Position position);

  bool move(const Position &currentPosition, const Position &nextPosition) override;
  bool eat(const Position &currentPosition, const Position &nextPosition) override;
};

#endif  // INCLUDE_KNIGHT_H_
