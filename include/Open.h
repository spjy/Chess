// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_OPEN_H_
#define INCLUDE_OPEN_H_

#include "Piece.h"

class Open : public Piece {
 public:
  explicit Open(Position position);

  bool move(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) override;
  bool eat(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) override;
};

#endif  // INCLUDE_OPEN_H_
