// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_PIECE_H_
#define INCLUDE_PIECE_H_

#include "Constants.h"

/*
  The generic piece class.

  @symbol 
 */

class Piece {
 private:
  char symbol; /**< The first letter of the piece's name */
  Color color; /**< The color of piece it is. */
  bool eaten = false; /**< Whether the piece has been eaten */
  Position position; /**< The piece's current position */
  Movement movement; /**< Constraints on how the piece can move */

 public:
  Piece(char symbol, Color color, Position position);
  void setMovement(Movement movement);
  char getSymbol();
  Color getColor();

  virtual bool move(Position currentPosition, Position nextPosition) = 0;
  virtual bool eat(Position currentPosition, Position nextPosition) = 0;
};

#endif  // INCLUDE_PIECE_H_
