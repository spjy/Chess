// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_KING_H_
#define INCLUDE_KING_H_

#include "Piece.h"

class King : public Piece {
 public:
  King(Color color);

  bool move(
    vector<vector<Piece*> > &board,
    const Position &currentPosition,
    const Position &nextPosition) override;

  bool eat(
    vector<vector<Piece*> > &board,
    const Position &currentPosition,
    const Position &nextPosition) override;
};

#endif  // INCLUDE_KING_H_
