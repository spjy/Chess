// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_ROOK_H_
#define INCLUDE_ROOK_H_

#include "Piece.h"

class Rook : public Piece {
 public:
  Rook(Color color, Position position) : Piece('r', color, position) {
    Movement movement;

    movement.forward = true;
    movement.backward = true;
    movement.diagonal = false;
    movement.left = true;
    movement.right = true;
    movement.knight = false;
    movement.oneSpace = false;
    movement.unlimitedSpaces = true;

    Piece::setMovement(movement);
  }

    void move() override;
    void eat() override;
};

#endif  // INCLUDE_ROOK_H_
