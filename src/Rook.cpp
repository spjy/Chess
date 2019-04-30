// Copyright 2019 Spencer Young, Johnson Huynh, Sean Tadekawa

#include "Rook.h"

Rook::Rook(Color color, Position position) : Piece('r', color, position, true, false) {}

bool Rook::eat(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  // for (auto i = currentPosition.row + 1; i < 8; i++) {
  //   Position position {
  //     i,
  //     currentPosition.column
  //   };

  //   if (board[i][currentPosition.column]->getColor() == Color::NONE) {
  //     this->possibleMoves.push_back(position);
  //   } else {
  //     break;
  //   }
  // }

  // for (auto i = currentPosition.column + 1; i < 8; i++) {
  //   Position position {
  //     i,
  //     currentPosition.column
  //   };

  //   if (board[i][currentPosition.column]->getColor() == Color::NONE) {
  //     this->possibleMoves.push_back(position);
  //   } else {
  //     break;
  //   }
  // }

  // for (auto i = currentPosition.row - 1; i >= 0; i--) {
  //   Position position {
  //     i,
  //     currentPosition.column
  //   };

  //   if (board[i][currentPosition.column]->getColor() == Color::NONE) {
  //     this->possibleMoves.push_back(position);
  //   } else {
  //     break;
  //   }
  // }

  // for (auto i = currentPosition.row - 1; i >= 0; i--) {
  //   Position position {
  //     i,
  //     currentPosition.column
  //   };

  //   if (board[i][currentPosition.column]->getColor() == Color::NONE) {
  //     this->possibleMoves.push_back(position);
  //   } else {
  //     break;
  //   }
  // }

  return true;
}

bool Rook::move(vector<vector<Piece*> > &board, const Position &currentPosition, const Position &nextPosition) {
  // for (auto i = currentPosition.row + 1; i < 8; i++) {
  //   Position position {
  //     i,
  //     currentPosition.column
  //   };

  //   if (board[i][currentPosition.column]->getColor() == Color::NONE) {
  //     this->possibleMoves.push_back(position);
  //   } else if (board[i][currentPosition.column]->getColor() != Color::NONE) {
  //     this->possibleMoves.push_back(position);
  //     break;
  //   }
  // }

  // for (auto i = currentPosition.column + 1; i < 8; i++) {
  //   Position position {
  //     i,
  //     currentPosition.column
  //   };

  //   if (board[i][currentPosition.column]->getColor() == Color::NONE) {
  //     this->possibleMoves.push_back(position);
  //   } else if (board[i][currentPosition.column]->getColor() != Color::NONE) {
  //     this->possibleMoves.push_back(position);
  //     break;
  //   }
  // }

  // for (auto i = currentPosition.row - 1; i >= 0; i--) {
  //   Position position {
  //     i,
  //     currentPosition.column
  //   };

  //   if (board[i][currentPosition.column]->getColor() == Color::NONE) {
  //     this->possibleMoves.push_back(position);
  //   } else if (board[i][currentPosition.column]->getColor() != Color::NONE) {
  //     this->possibleMoves.push_back(position);
  //     break;
  //   }
  // }

  // for (auto i = currentPosition.row - 1; i >= 0; i--) {
  //   Position position {
  //     i,
  //     currentPosition.column
  //   };

  //   if (board[i][currentPosition.column]->getColor() == Color::NONE) {
  //     this->possibleMoves.push_back(position);
  //   } else if (board[i][currentPosition.column]->getColor() != Color::NONE) {
  //     this->possibleMoves.push_back(position);
  //     break;
  //   }
  // }

  return true;
}
