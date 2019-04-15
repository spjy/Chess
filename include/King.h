// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_KING_H_
#define INCLUDE_KING_H_

#include "Piece.h"

class King : public Piece {
 public:
  King(Color color, Position position) : Piece('k', color, position) {
    Movement movement;

    movement.forward = true;
    movement.backward = true;
    movement.diagonal = true;
    movement.left = true;
    movement.right = true;
    movement.knight = false;
    movement.oneSpace = true;
    movement.unlimitedSpaces = false;

    Piece::setMovement(movement);
  }

  void move() override;
  void eat() override;
};

#endif  // INCLUDE_KING_H_
