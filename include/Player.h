// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_PLAYER_H_
#define INCLUDE_PLAYER_H_

#include <iostream>
#include <vector>

#include "Piece.h"

class Player {
  Color color;
  bool turn;
  bool checked;
  std::vector<Piece*> eaten;
};

#endif  // INCLUDE_PLAYER_H_
