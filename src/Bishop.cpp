// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "Bishop.h"

Bishop::Bishop(Color color) : Piece('b', color, false, true) {
}

bool Bishop::eat(
    vector<vector<Piece*> > &board,
    const Position &currentPosition,
    const Position &nextPosition) {
  int column = currentPosition.column + 1;

  for (int row = currentPosition.row + 1; row < 8; row++) {
    Position position {
      column,
      row
    };

    if (column < 8 && board[row][column]->getColor() != Color::NONE
      && board[row][column]->getColor() != this->color) {
      this->possibleMoves.push_back(position);
    } else {
      break;
    }

    column++;
  }

  column = currentPosition.column - 1;

  for (int row = currentPosition.row + 1; row < 8; row++) {
    Position position {
      column,
      row
    };

    if (column >= 0 && board[row][column]->getColor() != Color::NONE
      && board[row][column]->getColor() != this->color) {
      this->possibleMoves.push_back(position);
    } else {
      break;
    }

    column--;
  }

  column = currentPosition.column + 1;

  for (int row = currentPosition.row - 1; row >= 0; row--) {
    Position position {
      column,
      row
    };

    if (column < 8 && board[row][column]->getColor() != Color::NONE
      && board[row][column]->getColor() != this->color) {
      this->possibleMoves.push_back(position);
    } else {
      break;
    }

    column++;
  }

  column = currentPosition.column - 1;

  for (int row = currentPosition.row - 1; row >= 0; row--) {
    Position position {
      column,
      row
    };

    if (column >= 0 && board[row][column]->getColor() != Color::NONE
      && board[row][column]->getColor() != this->color) {
      this->possibleMoves.push_back(position);
    } else {
      break;
    }

    column--;
  }

  for (size_t move = 0; move < this->possibleMoves.size(); move++) {
    if (this->possibleMoves[move] == nextPosition) {
      return true;
    }
  }

  return false;
}

bool Bishop::move(
    vector<vector<Piece*> > &board,
    const Position &currentPosition,
    const Position &nextPosition) {
  int column = currentPosition.column + 1;

  for (int row = currentPosition.row + 1; row < 8; row++) {
    Position position {
      column,
      row
    };

    if (column < 8 && board[row][column]->getColor() == Color::NONE) {
      this->possibleMoves.push_back(position);
    } else {
      break;
    }

    column++;
  }

  column = currentPosition.column - 1;

  for (int row = currentPosition.row + 1; row < 8; row++) {
    Position position {
      column,
      row
    };

    if (column >= 0 && board[row][column]->getColor() == Color::NONE) {
      this->possibleMoves.push_back(position);
    } else {
      break;
    }

    column--;
  }

  column = currentPosition.column + 1;

  for (int row = currentPosition.row - 1; row >= 0; row--) {
    Position position {
      column,
      row
    };

    if (column < 8 && board[row][column]->getColor() == Color::NONE) {
      this->possibleMoves.push_back(position);
    } else {
      break;
    }

    column++;
  }

  column = currentPosition.column - 1;

  for (int row = currentPosition.row - 1; row >= 0; row--) {
    Position position {
      column,
      row
    };

    if (column >= 0 && board[row][column]->getColor() == Color::NONE) {
      this->possibleMoves.push_back(position);
    } else {
      break;
    }

    column--;
  }

  for (size_t move = 0; move < this->possibleMoves.size(); move++) {
    if (this->possibleMoves[move] == nextPosition) {
      return true;
    }
  }

  return false;
}
