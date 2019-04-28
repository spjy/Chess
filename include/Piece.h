// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#ifndef INCLUDE_PIECE_H_
#define INCLUDE_PIECE_H_

#include "Constants.h"

/*
  The generic piece class.

  @symbol 
 */

class Piece {
 protected:
  char symbol; /**< The first letter of the piece's name */
  Color color; /**< The color of piece it is. */
  bool eaten = false; /**< Whether the piece has been eaten */
  bool unlimitedStraight;
  bool unlimitedDiagonal;
  Position position; /**< The piece's current position */
  Movement movement; /**< Constraints on how the piece can move */

 public:
  Piece(
    char symbol,
    Color color,
    Position position,
    bool unlimitedStraight,
    bool unlimitedDiagonal);
  void setMovement(Movement movement);
  char getSymbol();
  bool getUnlimitedStraight();
  bool getUnlimitedDiagonal();
  Color getColor();

  virtual bool move(const Position &currentPosition, const Position &nextPosition) = 0;
  virtual bool eat(const Position &currentPosition, const Position &nextPosition) = 0;
};

#endif  // INCLUDE_PIECE_H_
