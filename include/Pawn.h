// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_PAWN_H_
#define INCLUDE_PAWN_H_

#include "Piece.h"

class Pawn : public Piece {
 private:
  bool moved = false;
 public:
  Pawn(Color color, Position position);

  bool move(const Position &currentPosition, const Position &nextPosition) override;
  bool eat(const Position &currentPosition, const Position &nextPosition) override;
  void promote(const Position &currentPosition, const Position &nextPosition);
};

#endif  // INCLUDE_PAWN_H_
