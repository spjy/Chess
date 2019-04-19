// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_OPEN_H_
#define INCLUDE_OPEN_H_

#include "Piece.h"

class Open : public Piece {
 public:
  Open(Position position);

  void move() override;
  void eat() override;
};

#endif  // INCLUDE_PAWN_H_
