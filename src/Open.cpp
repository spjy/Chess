// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "Open.h"

Open::Open() : Piece('X', Color::NONE, false, false) {}

bool Open::eat(
    vector<vector<Piece*> > &board,
    const Position &currentPosition,
    const Position &nextPosition) {
  return false;
}

bool Open::move(
    vector<vector<Piece*> > &board,
    const Position &currentPosition,
    const Position &nextPosition) {
  return false;
}
