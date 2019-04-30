// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "Bishop.h"

Bishop::Bishop(Color color, Position position) : Piece('b', color, position, false, true) {
}

bool Bishop::eat(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  
}

bool Bishop::move(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  return true;
}
