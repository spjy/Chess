
#include "Open.h"

Open::Open(Position position) : Piece(' ', Color::NONE, position) {
  // Checking for the first move of the pawn since it can go two spaces
  bool moved = false;
  Movement movement;

  movement.forward = false;
  movement.backward = false;
  movement.diagonal = false;
  movement.left = false;
  movement.right = false;
  movement.knight = false;
  movement.oneSpace = false;
  movement.unlimitedSpaces = false;

  Piece::setMovement(movement);
}

void Piece::eat() {
}

void Piece::move() {
}
