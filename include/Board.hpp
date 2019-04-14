#include <vector>
#include "Piece.hpp"

class Board {
  std::vector<Piece*> board;
  Board();
  bool checkIfOffBoard();
  bool checkIfObstructed();
  int movement();
}
