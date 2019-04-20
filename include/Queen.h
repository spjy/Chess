// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_QUEEN_H_
#define INCLUDE_QUEEN_H_

#include "Piece.h"

class Queen : public Piece {
 public:
  Queen(Color color, Position position);

  void move() override;
  void eat() override;
};

#endif  // INCLUDE_QUEEN_H_
