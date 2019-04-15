// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_CONSTANTS_H_
#define INCLUDE_CONSTANTS_H_

enum class Color {
  WHITE,
  BLACK
};

struct Movement {
  bool forward;
  bool backward;
  bool diagonal;
  bool left;
  bool right;
  bool knight;
  bool oneSpace;
  bool twoSpaces;
  bool unlimitedSpaces;
};

struct Position {
  int column;
  int row;
};

#endif  // INCLUDE_CONSTANTS_H_
