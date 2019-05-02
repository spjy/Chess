// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "Queen.h"

Queen::Queen(Color color) : Piece('q', color, true, true) {

}

bool Queen::eat(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  // Diagonal movement
  for (auto row = currentPosition.row + 1; row < 8; row++) {
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

  // Straight movement
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

bool Queen::move(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  // Diagonal movement
  for (auto row = currentPosition.row + 1; row < 8; row++) {
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

  // Straight movement
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
