// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "Pawn.h"

Pawn::Pawn(Color color, Position position) : Piece('p', color, position) {
  // Checking for the first move of the pawn since it can go two spaces
  bool moved = false;
  Movement movement;

  movement.forward = true;
  movement.backward = false;
  movement.diagonal = true;
  movement.left = false;
  movement.right = false;
  movement.knight = false;
  movement.oneSpace = true;
  movement.unlimitedSpaces = false;

  Piece::setMovement(movement);
}

void Piece::eat() {
}

void Piece::move() {
}
