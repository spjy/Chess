// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_BISHOP_H_
#define INCLUDE_BISHOP_H_

#include "Piece.h"

class Bishop : public Piece {
 public:
  Bishop(Color color, Position position);

  void move() override;
  void eat() override;
};

#endif  // INCLUDE_BISHOP_H_
