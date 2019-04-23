// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_OPEN_H_
#define INCLUDE_OPEN_H_

#include "Piece.h"

class Open : public Piece {
 public:
  explicit Open(Position position);

  bool move(Position currentPosition, Position nextPosition) override;
  bool eat(Position currentPosition, Position nextPosition) override;
};

#endif  // INCLUDE_OPEN_H_
