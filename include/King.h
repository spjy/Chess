// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_KING_H_
#define INCLUDE_KING_H_

#include "Piece.h"

class King : public Piece {
 public:
  King(Color color, Position position);

  void move() override;
  void eat() override;
};

#endif  // INCLUDE_KING_H_
