#ifndef BOARD_HPP
#define BOARD_HPP

#include "knight.hpp"
#include <SFML/Graphics.hpp>

// Forward declaration for Pawn class
class Pawn;
class Bishop;
class Rook;

class Board {

public:
  sf::RectangleShape square;
  bool isEmpty = true;
  std::string currentHoldingPieceName;
  sf::Vector2i squareIndices;
  Board();

  // Pawn
  void setCurrentPawn(Pawn *piece);

  // Bishop
  void setCurrentBishop(Bishop *piece);

  // Rook
  void setCurrentRook(Rook *piece);

  // Knight
  void setCurrentKnight(Knight *piece);

  void removePreviousPiece(Board *previousSqaure);
  void getCurrentPiece(Pawn *piece);
};

#endif
