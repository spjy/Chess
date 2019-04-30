// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "Pawn.h"

Pawn::Pawn(Color color, Position position) : Piece('p', color, position, false, false) {
  // // Checking for the first move of the pawn since it can go two spaces
  // Movement movement;

  // movement.forward = true;
  // movement.backward = false;
  // movement.diagonal = true;
  // movement.left = false;
  // movement.right = false;
  // movement.knight = false;
  // movement.oneSpace = true;
  // movement.unlimitedSpaces = false;

  // Piece::setMovement(movement);
}

bool Pawn::eat(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  vector<Position> possibleMoves;
  // Color color = board[currentPosition.row][currentPosition.row]->ge

  // TODO: En Passant
  if (this->color == Color::WHITE) {
    cout << "WHITE" << endl;
    // Up right
    Position position {
      currentPosition.column + 1,
      currentPosition.row + 1
    };
    
    possibleMoves.push_back(position);

    // Up left
    position = {
      currentPosition.column - 1,
      currentPosition.row + 1
    };

    possibleMoves.push_back(position);
  } else if (this->color == Color::BLACK) {
    // Down left
    Position position {
      currentPosition.column - 1,
      currentPosition.row - 1
    };

    possibleMoves.push_back(position);

    // Down right
    position = {
      currentPosition.column + 1,
      currentPosition.row - 1
    };

    possibleMoves.push_back(position);
  }

  for (size_t i = 0; i < possibleMoves.size(); i++) {
    cout << possibleMoves[i].column << possibleMoves[i].row << " | " << nextPosition.column << nextPosition.row << endl;
    if (possibleMoves[i].column == nextPosition.column && possibleMoves[i].row == nextPosition.row) {
      return true;
    }
  }

  return false;
}

bool Pawn::move(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  vector<Position> possibleMoves;
  Position move;

  if (this->color == Color::WHITE) {
    // Forward 2
    if (!this->moved) {
      Position position {
        currentPosition.column,
        currentPosition.row + 2
      };

      // Check if piece in between jump
      if (board[position.row - 1][position.column]->getColor() == Color::NONE) {
        possibleMoves.push_back(position);
      }
    }

    Position position {
      currentPosition.column,
      currentPosition.row + 1
    };
    // TODO: En Passant  
    possibleMoves.push_back(position);
  } else if (this->color == Color::BLACK) {
    if (!this->moved) {
      Position position {
        currentPosition.column,
        currentPosition.row - 2
      };

      // Check if piece in between jump
      if (board[position.row + 1][position.column]->getColor() == Color::NONE) {
        possibleMoves.push_back(position);
      }
    }

    Position position {
      currentPosition.column,
      currentPosition.row - 1
    };
    // TODO: En Passant  
    possibleMoves.push_back(position);
  }

  for (size_t i = 0; i < possibleMoves.size(); i++) {
    cout << possibleMoves[i].column << possibleMoves[i].row << " | " << nextPosition.column << nextPosition.row << endl;
    if (possibleMoves[i].column == nextPosition.column && possibleMoves[i].row == nextPosition.row) {
      return true;
    }
  }

  return false;
}

void Pawn::promote(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  char piece;
  
  if (nextPosition.row == 7) {
    cout << "Enter the piece you want to promote this pawn to:" << endl;
    cin >> piece;
  }
}
