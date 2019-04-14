#include "Piece.hpp"

class Pawn : public Piece {
  Pawn(Color color, Position position) : Piece('p', color, position) {
    bool moved = false; // Checking for the first move of the pawn since it can go two spaces
    Movement movement;

    movement.forward = true;
    movement.backward = false;
    movement.diagonal = true;
    movement.left = false;
    movement.right = false;
    movement.knight = false;
    movement.oneSpace = true;
    movement.unlimitedSpaces = false;
    
    Piece::setMovement(movement);
  };
}
