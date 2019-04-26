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

bool Rook::eat(Position currentPosition, Position nextPosition) {
  vector<Position> possibleMoves;

  if (this->color == Color::WHITE){
    Position position {
      currentPosition.column +,
      currentPosition.row
    }
    possibleMoves.push_back(position);

    position = (
      currentPosition.column -,
      currentPosition.row
    )
    possibleMoves.push_back(position);

    position = (
      currentPosition.column,
      currentPosition.row +
    )
    possibleMoves.push_back(position);

    position = (
      currentPosition.column,
      currentPosition.row -
    )
    possibleMoves.push_back(position);
  } else if (this->color == Color::BLACK){
    Position position {
      currentPosition.column +,
      currentPosition.row
    }
    possibleMoves.push_back(position);

    position = {
      currentPosition.column -,
      currentPosition.row 
    }
    possibleMoves.push_back(position);

    position = {
      currentPosition.column,
      currentPosition.row +
    }
    possibleMoves.push_back(position);

    position = {
      currentPosition.column,
      currentPosition.row - 
    }
    possibleMoves.push_back(position);
  }
for (size_t i = 0; i < possibleMoves.size(); i++) {
    cout << possibleMoves[i].column << possibleMoves[i].row << " | " << nextPosition.column << nextPosition.row << endl;
    if (possibleMoves[i].column == nextPosition.column && possibleMoves[i].row == nextPosition.row) {
      return true;
    }
  return false;
  }
}

bool Rook::move(Position currentPosition, Position nextPosition) {
  
}
