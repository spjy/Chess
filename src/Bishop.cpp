// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "Bishop.h"

Bishop::Bishop(Color color) : Piece('b', color, false, true) {
}

bool Bishop::eat(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  for (auto row = currentPosition.row + 1; row < 8; row++) {
    for (auto column = currentPosition.column + 1; column < 8; column++) {
      Position position {
        column,
        row
      };

      cout << column << row << endl;

      if (board[row][column]->getColor() != Color::NONE && board[row][column]->getColor() != this->color) {
        this->possibleMoves.push_back(position);
      } else {
        break;
      }
    }
  }

  for (auto row = currentPosition.row - 1; row >= 0; row--) {
    for (auto column = currentPosition.column - 1; column >= 0; column--) {
      Position position {
        column,
        row
      };

      if (board[row][column]->getColor() != Color::NONE && board[row][column]->getColor() != this->color) {
        this->possibleMoves.push_back(position);
      } else {
        break;
      }
    }
  }

  for (auto row = currentPosition.row + 1; row < 8; row++) {
    for (auto column = currentPosition.column - 1; column >= 0; column--) {
      Position position {
        column,
        row
      };

      if (board[row][column]->getColor() != Color::NONE && board[row][column]->getColor() != this->color) {
        this->possibleMoves.push_back(position);
      } else {
        break;
      }
    }
  }

  for (auto row = currentPosition.row - 1; row >= 0; row--) {
    for (auto column = currentPosition.column + 1; column < 8; column++) {
      Position position {
        column,
        row
      };

      if (board[row][column]->getColor() != Color::NONE && board[row][column]->getColor() != this->color) {
        this->possibleMoves.push_back(position);
      } else {
        break;
      }
    }
  }

  for (size_t move = 0; move < this->possibleMoves.size(); move++) {
    cout << this->possibleMoves[move].column << this->possibleMoves[move].row << " | " << nextPosition.column << nextPosition.row << endl;
    if (this->possibleMoves[move].column == nextPosition.column && this->possibleMoves[move].row == nextPosition.row) {
      return true;
    }
  }

  return false;
}

bool Bishop::move(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  for (auto row = currentPosition.row + 1; row < 8; row++) {
    for (auto column = currentPosition.column + 1; column < 8; column++) {
      Position position {
        column,
        row
      };

      cout << column << row << endl;


      if (board[row][column]->getColor() == Color::NONE) {
        this->possibleMoves.push_back(position);
      } else {
        break;
      }
    }
  }

  for (auto row = currentPosition.row - 1; row >= 0; row--) {
    for (auto column = currentPosition.column - 1; column >= 0; column--) {
      Position position {
        column,
        row
      };

      if (board[row][column]->getColor() == Color::NONE) {
        this->possibleMoves.push_back(position);
      } else {
        break;
      }
    }
  }

  for (auto row = currentPosition.row + 1; row < 8; row++) {
    for (auto column = currentPosition.column - 1; column >= 0; column--) {
      Position position {
        column,
        row
      };

      if (board[row][column]->getColor() == Color::NONE) {
        this->possibleMoves.push_back(position);
      } else {
        break;
      }
    }
  }

  for (auto row = currentPosition.row - 1; row >= 0; row--) {
    for (auto column = currentPosition.column + 1; column < 8; column++) {
      Position position {
        column,
        row
      };

      if (board[row][column]->getColor() == Color::NONE) {
        this->possibleMoves.push_back(position);
      } else {
        break;
      }
    }
  }

  for (size_t move = 0; move < this->possibleMoves.size(); move++) {
    cout << this->possibleMoves[move].column << this->possibleMoves[move].row << " | " << nextPosition.column << nextPosition.row << endl;
    if (this->possibleMoves[move].column == nextPosition.column && this->possibleMoves[move].row == nextPosition.row) {
      return true;
    }
  }

  return false;
}
