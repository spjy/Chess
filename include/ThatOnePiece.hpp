#include "Piece.h"
// This is the piece that can't eat other pieces
// It it just there to block the way
class TOP : public Piece {
  TOP(Color color, Position position) : Piece('t', color, position) {

  }
}
