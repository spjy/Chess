// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_CONSTANTS_H_
#define INCLUDE_CONSTANTS_H_

#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

enum class Color {
  WHITE,
  BLACK,
  NONE
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

int char_to_int(char c);

#endif  // INCLUDE_CONSTANTS_H_
