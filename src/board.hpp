#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>

// Forward declaration for Pawn class
class Pawn;
class Bishop;

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

  void removePreviousPiece(Board *previousSqaure);
  void getCurrentPiece(Pawn *piece);
};

#endif
