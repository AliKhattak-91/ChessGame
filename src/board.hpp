#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>

class Board {

public:
  sf::RectangleShape square;
  bool isEmpty = true;

  Board();

  void setCurrentPiece(sf::Sprite *piece);
  void removePreviousPiece(Board *previousSqaure);
  void getCurrentPiece();
};

#endif
