// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "Pawn.h"
#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"

Pawn::Pawn(Color color) : Piece('p', color, false, false) {
}

bool Pawn::eat(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  vector<Position> moves;
  // Color color = board[currentPosition.row][currentPosition.row]->ge

  // TODO: En Passant
  if (this->color == Color::WHITE) {
    moves = {
      {
        currentPosition.column + 1,
        currentPosition.row + 1
      },
      {
        currentPosition.column - 1,
        currentPosition.row + 1
      }
    };
  } else if (this->color == Color::BLACK) {
    moves = {
      {
        currentPosition.column - 1,
        currentPosition.row - 1
      },
      {
        currentPosition.column + 1,
        currentPosition.row - 1
      }
    };
  }

  for (auto move = 0; move < moves.size(); move++) {
    this->setPossibleMoves(board, moves[move]);
    cout << moves[move].column << moves[move].row << " | " << nextPosition.column << nextPosition.row << endl;
    if (moves[move].column == nextPosition.column && moves[move].row == nextPosition.row) {
      return true;
    }
  }

  return false;
}

bool Pawn::move(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  vector<Position> moves;
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
        moves.push_back(position);
      }
    }

    Position position {
      currentPosition.column,
      currentPosition.row + 1
    };
    // TODO: En Passant  
    moves.push_back(position);
  } else if (this->color == Color::BLACK) {
    if (!this->moved) {
      Position position {
        currentPosition.column,
        currentPosition.row - 2
      };

      // Check if piece in between jump
      if (board[position.row + 1][position.column]->getColor() == Color::NONE) {
        moves.push_back(position);
      }
    }

    Position position {
      currentPosition.column,
      currentPosition.row - 1
    };
    // TODO: En Passant  
    moves.push_back(position);
  }

  for (size_t move = 0; move < moves.size(); move++) {
    cout << moves[move].column << moves[move].row << " | " << nextPosition.column << nextPosition.row << endl;
    this->setPossibleMoves(board, moves[move]);
    if (moves[move].column == nextPosition.column && moves[move].row == nextPosition.row) {
      // Check if pawn is promoted
      if (nextPosition.row == 8 || nextPosition.row == 0) {
        this->promote(board, currentPosition, nextPosition);
      }
      return true;
    }
  }

  return false;
}

void Pawn::promote(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  char piece;
  
  cout << "Enter the piece you want to promote this pawn to (q, b, n, r):" << endl;
  cin >> piece;

  if (piece == 'q') {
    board[nextPosition.row][nextPosition.column] = new Queen(this->getColor());
  } else if (piece == 'b') {
    board[nextPosition.row][nextPosition.column] = new Bishop(this->getColor());
  } else if (piece == 'n') {
    board[nextPosition.row][nextPosition.column] = new Knight(this->getColor());
  } else if (piece == 'r') {
    board[nextPosition.row][nextPosition.column] = new Rook(this->getColor());
  }
}
