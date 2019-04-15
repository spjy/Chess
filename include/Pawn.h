// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_PAWN_H_
#define INCLUDE_PAWN_H_

#include "Piece.h"

class Pawn : public Piece {
 public:
  Pawn(Color color, Position position);

  void move() override;
  void eat() override;
};

#endif  // INCLUDE_PAWN_H_
