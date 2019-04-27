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
// All Rook moves the same regardless of which COLOR
// For eat, check if the piece is in the same row/column
// Loop through each tile, from lowest to other position ?

  if(rook.row == target.row){ // Movement will be columnwise
    // Compare which column is the lower value
    if(rook.column < target.column){
      Position position {
        // Rook moves the difference between the two columns
        currentPosition.column +(target.column - rook.column),
        currentPosition.row
      }
    }else if(target.column < rook.column){
      position {
        // Rook moves the difference between the two columns
        currentPosition.column -(rook.column - target.column),
        currentPosition.row
      }
    }
  }
  

// Check if the rook and the target piece is in the same column

  if(rook.column == target.column){ // Movement will be row-wise
    // Compare which row is the lower value
    if(rook.row < target.row){
      Position position {
        currentPosition.column,
        currentPosition.row +(target.row - rook.row) 
        // Rook moves the difference between the two rows.
      }
      possibleMoves.push_back(position);
    }else if(target.row < rook.row){
      position = {
        currentPosition.column,
        currentPosition.row -(rook.row - target.row)
        // Rook moves the difference between the two rows
      }
      possibleMoves.push_back(position);
    }
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
