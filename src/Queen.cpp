// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "Queen.h"

Queen::Queen(Color color) : Piece('q', color, true, true) {}

bool Queen::eat(
    vector<vector<Piece*> > &board,
    const Position &currentPosition,
    const Position &nextPosition) {
  // Diagonal movement
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

  // Straight movement
  for (int i = currentPosition.row + 1; i < 8; i++) {
    Position position {
      currentPosition.column,
      i
    };

    if (board[i][currentPosition.column]->getColor() != Color::NONE
      && board[i][currentPosition.column]->getColor() != this->color) {
      this->possibleMoves.push_back(position);
      break;
    }
  }

  for (int i = currentPosition.column + 1; i < 8; i++) {
    Position position {
      currentPosition.column,
      i
    };

    if (board[i][currentPosition.column]->getColor() != Color::NONE
      && board[i][currentPosition.column]->getColor() != this->color) {
      this->possibleMoves.push_back(position);
      break;
    }
  }

  for (int i = currentPosition.row - 1; i >= 0; i--) {
    Position position {
      i,
      currentPosition.row
    };

    if (board[i][currentPosition.column]->getColor() != Color::NONE
      && board[i][currentPosition.column]->getColor() != this->color) {
      this->possibleMoves.push_back(position);
      break;
    }
  }

  for (int i = currentPosition.column - 1; i >= 0; i--) {
    Position position {
      i,
      currentPosition.row
    };

    if (board[i][currentPosition.column]->getColor() != Color::NONE
      && board[i][currentPosition.column]->getColor() != this->color) {
      this->possibleMoves.push_back(position);
      break;
    }
  }

  for (size_t move = 0; move < this->possibleMoves.size(); move++) {
    cout << this->possibleMoves[move].column << this->possibleMoves[move].row << " | " << nextPosition.column << nextPosition.row << endl;
    if (this->possibleMoves[move].column == nextPosition.column
      && this->possibleMoves[move].row == nextPosition.row) {
      return true;
    }
  }

  return false;
}

bool Queen::move(
    vector<vector<Piece*> > &board,
    const Position &currentPosition,
    const Position &nextPosition) {
  // Diagonal movement
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

  // Straight movement
  for (int i = currentPosition.row + 1; i < 8; i++) {
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

  for (int i = currentPosition.column + 1; i < 8; i++) {
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

  for (int i = currentPosition.row - 1; i >= 0; i--) {
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

  for (int i = currentPosition.column - 1; i >= 0; i--) {
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
    if (this->possibleMoves[move].column == nextPosition.column
      && this->possibleMoves[move].row == nextPosition.row) {
      return true;
    }
  }

  return false;
}
