// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "Queen.h"

Queen::Queen(Color color, Position position) : Piece('q', color, position) {
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

void Queen::eat() {
}

void Queen::move() {
}