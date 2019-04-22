// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "Rook.h"

Rook::Rook(Color color, Position position) : Piece('r', color, position) {
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

void Rook::eat() {
}

void Rook::move() {
}
