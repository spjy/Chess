// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_KNIGHT_H_
#define INCLUDE_KNIGHT_H_

#include "Piece.h"

class Knight : public Piece {
 public:
  Knight(Color color);

  bool move(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) override;
  bool eat(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) override;
};

#endif  // INCLUDE_KNIGHT_H_
