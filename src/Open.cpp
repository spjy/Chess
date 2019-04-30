
#include "Open.h"

Open::Open(Position position) : Piece('X', Color::NONE, position, false, false) {
  
}

bool Open::eat(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  return false;
}

bool Open::move(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  return false;
}
