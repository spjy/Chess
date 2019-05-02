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
  Movement movement; /**< Constraints on how the piece can move */
  vector<Position> possibleMoves;

 public:
  Piece(
    char symbol,
    Color color,
    bool unlimitedStraight,
    bool unlimitedDiagonal);
  void setMovement(Movement movement);
  char getSymbol();
  bool hasUnlimitedStraight();
  bool hasUnlimitedDiagonal();
  Color getColor();
  char getColorSymbol();
  void clearPossibleMoves();

  void setPossibleMoves(vector<vector<Piece*> > &board, const Position &position);
  virtual bool move(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) = 0;
  virtual bool eat(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) = 0;
};

#endif  // INCLUDE_PIECE_H_
