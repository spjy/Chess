// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "Pawn.h"

Pawn::Pawn(Color color, Position position)
  : Piece('p', color, position, false, false) {
}

bool Pawn::eat(const Position &currentPosition, const Position &nextPosition) {
  vector<Position> possibleMoves;
  // Color color = board[currentPosition.row][currentPosition.row]->ge

  // TODO: En Passant
  if (this->color == Color::WHITE) {
    cout << "WHITE" << endl;
    Position position {
      currentPosition.column + 1,
      currentPosition.row + 1
    };
    possibleMoves.push_back(position);

    position = {
      currentPosition.column - 1,
      currentPosition.row + 1
    };

    possibleMoves.push_back(position);
  } else if (this->color == Color::BLACK) {
    Position position {
      currentPosition.column - 1,
      currentPosition.row - 1
    };

    possibleMoves.push_back(position);

    position = {
      currentPosition.column + 1,
      currentPosition.row - 1
    };

    possibleMoves.push_back(position);
  }

  for (size_t i = 0; i < possibleMoves.size(); i++) {
    cout << possibleMoves[i].column << possibleMoves[i].row
      << " | " << nextPosition.column << nextPosition.row << endl;
    if (possibleMoves[i].column == nextPosition.column
      && possibleMoves[i].row == nextPosition.row) {
      return true;
    }
  }

  return false;
}

bool Pawn::move(const Position &currentPosition, const Position &nextPosition) {
  vector<Position> possibleMoves;
  Position move;

  if (this->color == Color::WHITE) {
    if (!this->moved) {
      Position position {
        currentPosition.column,
        currentPosition.row + 2
      };

      possibleMoves.push_back(position);
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

      possibleMoves.push_back(position);
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

void Pawn::promote(const Position &currentPosition, const Position &nextPosition) {
  char piece;
  
  if (nextPosition.row == 7) {
    cout << "Enter the piece you want to promote this pawn to:" << endl;
    cin >> piece;
  }
}
