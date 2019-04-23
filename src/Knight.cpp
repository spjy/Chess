// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "Knight.h"

Knight::Knight(Color color, Position position) : Piece('n', color, position) {
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

bool Knight::eat(Position currentPosition, Position nextPosition) {
}

bool Knight::move(Position currentPosition, Position nextPosition) {
}
