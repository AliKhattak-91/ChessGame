#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>

// Forward declaration for Pawn class
class Pawn;

class Board {

public:
  sf::RectangleShape square;
  bool isEmpty = true;
  std::string currentHoldingPieceName;
  sf::Vector2i squareIndices;
  Board();

  void setCurrentPiece(Pawn *piece);
  void removePreviousPiece(Board *previousSqaure);
  void getCurrentPiece(Pawn *piece);
};

#endif
