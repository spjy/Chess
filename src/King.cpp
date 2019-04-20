// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "King.h"
// King is special, it can't move to places where 
// it could be eaten.

King::King(Color color, Position position) : Piece('k', color, position) {
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
void Piece::eat() {
}

void Piece::move() {
}
