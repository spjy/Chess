// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "Queen.h"

Queen::Queen(Color color, Position position) : Piece('q', color, position, true, true) {

}
// Combine Rook and Bishop 
bool Queen::eat(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  return true;
}

bool Queen::move(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  return true;
}