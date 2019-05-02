// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "Rook.h"

Rook::Rook(Color color) : Piece('r', color, true, false) {}

bool Rook::eat(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  for (auto i = currentPosition.row + 1; i < 8; i++) {
    Position position {
      currentPosition.column,
      i
    };

    if (board[i][currentPosition.column]->getColor() != Color::NONE && board[i][currentPosition.column]->getColor() != this->color) {
      this->possibleMoves.push_back(position);
      break;
    }
  }

  for (auto i = currentPosition.column + 1; i < 8; i++) {
    Position position {
      currentPosition.column,
      i
    };

    if (board[i][currentPosition.column]->getColor() != Color::NONE && board[i][currentPosition.column]->getColor() != this->color) {
      this->possibleMoves.push_back(position);
      break;
    }
  }

  for (auto i = currentPosition.row - 1; i >= 0; i--) {
    Position position {
      i,
      currentPosition.row
    };

    if (board[i][currentPosition.column]->getColor() != Color::NONE && board[i][currentPosition.column]->getColor() != this->color) {
      this->possibleMoves.push_back(position);
      break;
    }
  }

  for (auto i = currentPosition.column - 1; i >= 0; i--) {
    Position position {
      i,
      currentPosition.row
    };

    if (board[i][currentPosition.column]->getColor() != Color::NONE && board[i][currentPosition.column]->getColor() != this->color) {
      this->possibleMoves.push_back(position);
      break;
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

bool Rook::move(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  for (auto i = currentPosition.row + 1; i < 8; i++) {
    Position position {
      currentPosition.column,
      i
    };

    if (board[i][currentPosition.column]->getColor() == Color::NONE) {
      this->possibleMoves.push_back(position);
    } else {
      break;
    }
  }

  for (auto i = currentPosition.column + 1; i < 8; i++) {
    Position position {
      i,
      currentPosition.row
    };

    if (board[currentPosition.row][i]->getColor() == Color::NONE) {
      this->possibleMoves.push_back(position);
    } else {
      break;
    }
  }

  for (auto i = currentPosition.row - 1; i >= 0; i--) {
    Position position {
      currentPosition.column,
      i
    };

    if (board[i][currentPosition.column]->getColor() == Color::NONE) {
      this->possibleMoves.push_back(position);
    } else {
      break;
    }
  }

  for (auto i = currentPosition.column - 1; i >= 0; i--) {
    Position position {
      i,
      currentPosition.row
    };

    if (board[currentPosition.row][i]->getColor() == Color::NONE) {
      this->possibleMoves.push_back(position);
    } else {
      break;
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
