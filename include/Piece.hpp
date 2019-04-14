#include <iostream>
#include <string>
#include "Constants.hpp"

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
    Piece(char symbol, Color color, Position position) :
      symbol(symbol),
      color(color),
      position(position) {
    };

    void setMovement(Movement movement) {
      this->movement = movement;
    }
    
    virtual void move() = 0;
    virtual void eat() = 0;
}; 
