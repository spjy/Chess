// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "Piece.h"

Piece::Piece(char symbol, Color color, Position position) {
  this->symbol = symbol;
  this->color = color;
  this->position = position;
}

void Piece::setMovement(Movement movement) {
  this->movement = movement;
}

char Piece::getSymbol() {
  return this->symbol;
}
