// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "King.h"
// King is special, it can't move to places where 
// it could be eaten.

King::King(Color color, Position position) : Piece('k', color, position, false, false) {
  Movement movement;

  movement.forward = true;
  movement.backward = true;
  movement.diagonal = true;
  movement.left = true;
  movement.right = true;
  movement.knight = false;
  movement.oneSpace = true;
  movement.unlimitedSpaces = false;

  Piece::setMovement(movement);
}

bool King::eat(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  vector<Position> possibleMoves;

  Position position {
    currentPosition.column + 1,
    currentPosition.row
  };
  possibleMoves.push_back(position);

  position = {
    currentPosition.column + 1,
    currentPosition.row + 1
  };
  possibleMoves.push_back(position);

  position = {
    currentPosition.column,
    currentPosition.row + 1
  };
  possibleMoves.push_back(position);
  
  position = {
    currentPosition.column - 1,
    currentPosition.row + 1
  };
  possibleMoves.push_back(position);
  
  position = {
    currentPosition.column - 1,
    currentPosition.row
  };
  possibleMoves.push_back(position);
  
  position = {
    currentPosition.column - 1,
    currentPosition.row - 1
  };
  possibleMoves.push_back(position);
  
  position = {
    currentPosition.column,
    currentPosition.row - 1
  };
  possibleMoves.push_back(position);
  
  position = {
    currentPosition.column - 1,
    currentPosition.row + 1
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

bool King::move(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  return this->eat(board, currentPosition, nextPosition);
}
