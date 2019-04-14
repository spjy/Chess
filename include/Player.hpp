#include <iostream>
#include <vector>

#include "Piece.hpp"
#include "Constants.hpp"

class Player {
  Color color;
  bool turn;
  bool checked;
  std::vector<Piece*> eaten;
};
