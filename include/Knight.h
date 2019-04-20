// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_KNIGHT_H_
#define INCLUDE_KNIGHT_H_

#include "Piece.h"

class Knight : public Piece {
 public:
  Knight(Color color, Position position);

  void move() override;
  void eat() override;
};

#endif  // INCLUDE_KNIGHT_H_
