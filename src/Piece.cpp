// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "Piece.h"

Piece::Piece(char symbol,
  Color color,
  Position position,
  bool unlimitedStraight,
  bool unlimitedDiagonal) {
  this->symbol = symbol;
  this->color = color;
  this->position = position;
  this->unlimitedStraight = unlimitedStraight;
  this->unlimitedDiagonal = unlimitedDiagonal;
}

void Piece::setMovement(Movement movement) {
  this->movement = movement;
}

char Piece::getSymbol() {
  return this->symbol;
}

Color Piece::getColor() {
  return this->color;
}

bool Piece::getUnlimitedStraight() {
  return this->unlimitedStraight;
}

bool Piece::getUnlimitedDiagonal() {
  return this->unlimitedDiagonal;
}
