// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "Bishop.h"

Bishop::Bishop(Color color, Position position) : Piece('b', color, position) {
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
Piece::setMovement(movement);
}

void Piece::eat() {
}

void Piece::move() {
}