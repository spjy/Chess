#include "Piece.hpp"
#include "Board.hpp"

Board::Board() {
  Pieces spaces[8][8];
  std::vector<Pieces*> board;
  this->board = board;
}

bool Board::checkIfOffBoard() {

}

bool Board::checkIfObstructed() {

}

int Board::movement() {

}
