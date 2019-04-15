// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_QUEEN_H_
#define INCLUDE_QUEEN_H_

#include "Piece.h"

class Queen : public Piece {
 public:
  Queen(Color color, Position position) : Piece('q', color, position) {
    Movement movement;

    movement.forward = true;
    movement.backward = true;
    movement.diagonal = true;
    movement.left = true;
    movement.right = true;
    movement.oneSpace = false;
    movement.unlimitedSpaces = true;

    Piece::setMovement(movement);
  }

  void move() override;
  void eat() override;
};

#endif  // INCLUDE_QUEEN_H_
