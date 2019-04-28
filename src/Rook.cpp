// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "Rook.h"

Rook::Rook(Color color, Position position) : Piece('r', color, position, true, false) {}

bool Rook::eat(const Position &currentPosition, const Position &nextPosition) {
  return true;
}

bool Rook::move(const Position &currentPosition, const Position &nextPosition) {
  return true;
}
