// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_KNIGHT_H_
#define INCLUDE_KNIGHT_H_

#include "Piece.h"

class Knight : public Piece {
 public:
  Knight(Color color, Position position) : Piece('n', color, position) {
    Movement movement;

    movement.forward = false;
    movement.backward = false;
    movement.diagonal = false;
    movement.left = false;
    movement.right = false;
    movement.knight = true;
    movement.oneSpace = false;
    movement.unlimitedSpaces = false;

    Piece::setMovement(movement);
  }

  void move() override;
  void eat() override;
};

#endif  // INCLUDE_KNIGHT_H_
