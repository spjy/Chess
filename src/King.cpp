// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "King.h"
// King is special, it can't move to places where 
// it could be eaten.

King::King(Color color) : Piece('k', color, false, false) {
}

bool King::eat(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  vector<Position> moves {
    {
      currentPosition.column + 1,
      currentPosition.row
    },
    {
      currentPosition.column + 1,
      currentPosition.row + 1
    },
    {
      currentPosition.column,
      currentPosition.row + 1
    },
    {
      currentPosition.column - 1,
      currentPosition.row + 1
    },
    {
      currentPosition.column - 1,
        currentPosition.row
    },
    {
      currentPosition.column - 1,
      currentPosition.row - 1
    },
    {
      currentPosition.column,
      currentPosition.row - 1
    },
    {
      currentPosition.column - 1,
      currentPosition.row + 1
    }
  };

  for (size_t i = 0; i < moves.size(); i++) {
    cout << moves[i].column << moves[i].row << " | " << nextPosition.column << nextPosition.row << endl;
    this->setPossibleMoves(board, moves[i]);
    if (moves[i].column == nextPosition.column && moves[i].row == nextPosition.row) {
      return true;
    }
  }
  
  return false;
}

bool King::move(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  return this->eat(board, currentPosition, nextPosition);
}
