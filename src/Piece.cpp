// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "Piece.h"

Piece::Piece(char symbol,
  Color color,
  bool unlimitedStraight,
  bool unlimitedDiagonal) {
  this->symbol = symbol;
  this->color = color;
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

bool Piece::hasUnlimitedStraight() {
  return this->unlimitedStraight;
}

bool Piece::hasUnlimitedDiagonal() {
  return this->unlimitedDiagonal;
}

char Piece::getColorSymbol() {
  if (this->color == Color::BLACK) {
    return 'B';
  } else if (this->color == Color::WHITE) {
    return 'W';
  }

  return ' ';
}

void Piece::setPossibleMoves(
  vector<vector<Piece*> > &board,
  const Position &position) {
  if (position.row >= 0 && position.row < 8
    && position.column >= 0 && position.column < 8) {
      this->possibleMoves.push_back(position);
  }
}

void Piece::clearPossibleMoves() {
  this->possibleMoves.clear();
}
