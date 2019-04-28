
#include "Open.h"

Open::Open(Position position) : Piece('X', Color::NONE, position, false, false) {
  
}

bool Open::eat(const Position &currentPosition, const Position &nextPosition) {}

bool Open::move(const Position &currentPosition, const Position &nextPosition) {}
