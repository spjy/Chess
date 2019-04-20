// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_ROOK_H_
#define INCLUDE_ROOK_H_

#include "Piece.h"

class Rook : public Piece {
 public:
  Rook(Color color, Position position);

    void move() override;
    void eat() override;
};

#endif  // INCLUDE_ROOK_H_
