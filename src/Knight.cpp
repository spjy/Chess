// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "Knight.h"

Knight::Knight(Color color) : Piece('n', color, false, false) {
}

bool Knight::eat(
    vector<vector<Piece*> > &board,
    const Position &currentPosition,
    const Position &nextPosition) {
  vector<Position> moves {
    {
      currentPosition.column + 1,
      currentPosition.row + 2
    },
    {
      currentPosition.column - 1,
      currentPosition.row + 2
    },
    {
      currentPosition.column + 2,
      currentPosition.row + 1
    },
    {
      currentPosition.column + 2,
      currentPosition.row - 1
    },
    {
      currentPosition.column + 1,
      currentPosition.row - 2
    },
    {
      currentPosition.column - 1,
      currentPosition.row - 2
    },
    {
      currentPosition.column - 2,
      currentPosition.row + 1
    },
    {
      currentPosition.column - 2,
      currentPosition.row - 1
    }
  };

  for (size_t i = 0; i < moves.size(); i++) {
    cout << moves[i].column << moves[i].row << " | " << nextPosition.column << nextPosition.row << endl;
    this->setPossibleMoves(board, moves[i]);
    if (moves[i].column == nextPosition.column
      && moves[i].row == nextPosition.row) {
      return true;
    }
  }

  return false;
}

bool Knight::move(
    vector<vector<Piece*> > &board,
    const Position &currentPosition,
    const Position &nextPosition) {
  return this->eat(board, currentPosition, nextPosition);
}
