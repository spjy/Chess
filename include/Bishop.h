// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_BISHOP_H_
#define INCLUDE_BISHOP_H_

#include "Piece.h"

class Bishop : public Piece {
 public:
  Bishop(Color color, Position position) : Piece('b', color, position) {
    Movement movement;
    movement.forward = false;
    movement.backward = false;
    movement.diagonal = true;
    movement.left = false;
    movement.right = false;
    movement.knight = false;
    movement.oneSpace = false;
    movement.unlimitedSpaces = true;
  }

  void move() override;
  void eat() override;
};

#endif  // INCLUDE_BISHOP_H_
