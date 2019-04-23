
#include "Open.h"

Open::Open(Position position) : Piece('X', Color::NONE, position) {
  // Checking for the first move of the pawn since it can go two spaces
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

bool Open::eat(Position currentPosition, Position nextPosition) {
}

bool Open::move(Position currentPosition, Position nextPosition) {
}
