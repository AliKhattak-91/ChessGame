#ifndef PAWN_HPP
#define PAWN_HPP

#include "board.hpp"
#include <SFML/Graphics.hpp>

class Pawn {
public:
  sf::Texture pawnTexture;
  sf::Sprite pawnSprite;
  bool isSelected = false;
  Board *currentSquare;

  Pawn();
  void pawnMovement();
};

#endif
