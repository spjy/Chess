// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "Pawn.h"

Pawn::Pawn(Color color, Position position) : Piece('p', color, position) {
  // Checking for the first move of the pawn since it can go two spaces
  Movement movement;

  movement.forward = true;
  movement.backward = false;
  movement.diagonal = true;
  movement.left = false;
  movement.right = false;
  movement.knight = false;
  movement.oneSpace = true;
  movement.unlimitedSpaces = false;

  Piece::setMovement(movement);
}

bool Pawn::eat(Position currentPosition, Position nextPosition) {
  vector<Position> possibleMoves;
  // Color color = board[currentPosition.row][currentPosition.row]->ge

  Position position {
    currentPosition.column + 1,
    currentPosition.row + 1
  };
  // TODO: En Passant  
  possibleMoves.push_back(position);

  position = {
    currentPosition.column - 1,
    currentPosition.row + 1
  };

  possibleMoves.push_back(position);


}

bool Pawn::move(Position currentPosition, Position nextPosition) {
  vector<Position> possibleMoves;
  Position move;

  if (!this->moved) {
    Position position {
      currentPosition.column,
      currentPosition.row + 2
    };
  }

  Position position {
    currentPosition.column,
    currentPosition.row + 1
  };
  // TODO: En Passant  
  possibleMoves.push_back(position);

  for (int i = 0; i < possibleMoves.size(); i++) {
    if (possibleMoves[i].column == nextPosition.column && possibleMoves[i].row == nextPosition.row) {
      return true;
    }
  }
  return false;
}

void Pawn::promote(Position currentPosition, Position nextPosition) {
  char piece;
  
  if (nextPosition.row = 7) {
    cout << "Enter the piece you want to promote this pawn to:" << endl;
    cin >> piece;
  }
}
