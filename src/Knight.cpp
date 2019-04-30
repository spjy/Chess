// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "Knight.h"

Knight::Knight(Color color, Position position) : Piece('n', color, position, false, false) {
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

bool Knight::eat(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  vector<Position> possibleMoves;

  Position position {
    currentPosition.column + 1,
    currentPosition.row + 2
  };

  possibleMoves.push_back(position);

  position = {
    currentPosition.column - 1,
    currentPosition.row + 2
  };

  possibleMoves.push_back(position);

  position = {
    currentPosition.column + 2,
    currentPosition.row + 1
  };

  possibleMoves.push_back(position);

  position = {
    currentPosition.column + 2,
    currentPosition.row - 1
  };

  possibleMoves.push_back(position);

  position = {
    currentPosition.column + 1,
    currentPosition.row - 2
  };

  possibleMoves.push_back(position);

  position = {
    currentPosition.column - 1,
    currentPosition.row - 2
  };

  possibleMoves.push_back(position);

  position = {
    currentPosition.column - 2,
    currentPosition.row + 1
  };

  possibleMoves.push_back(position);

  position = {
    currentPosition.column - 2,
    currentPosition.row - 1
  };

  possibleMoves.push_back(position);

  for (size_t i = 0; i < possibleMoves.size(); i++) {
    cout << possibleMoves[i].column << possibleMoves[i].row << " | " << nextPosition.column << nextPosition.row << endl;
    if (possibleMoves[i].column == nextPosition.column && possibleMoves[i].row == nextPosition.row) {
      return true;
    }
  }

  return false;
}

bool Knight::move(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  return this->eat(board, currentPosition, nextPosition);
}
