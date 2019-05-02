// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_BISHOP_H_
#define INCLUDE_BISHOP_H_

#include "Piece.h"

class Bishop : public Piece {
 public:
  explicit Bishop(Color color);

  bool move(
    vector<vector<Piece*> > &board,
    const Position &currentPosition,
    const Position &nextPosition) override;

  bool eat(
    vector<vector<Piece*> > &board,
    const Position &currentPosition,
    const Position &nextPosition) override;
};

#endif  // INCLUDE_BISHOP_H_
