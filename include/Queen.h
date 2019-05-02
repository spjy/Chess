// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_QUEEN_H_
#define INCLUDE_QUEEN_H_

#include "Piece.h"

class Queen : public Piece {
 public:
  Queen(Color color);

  bool move(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) override;
  bool eat(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) override;
};

#endif  // INCLUDE_QUEEN_H_
