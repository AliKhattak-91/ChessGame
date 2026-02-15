#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include <SFML/Graphics.hpp>

class Board;

class Knight {
public:
  std::string pieceName;

  sf::Texture whiteKnightTexture;
  sf::Sprite whiteKnightSprite;

  bool isSelected = false;
  Board *currentSqaure;

  int currentPositionX;
  int currentPositionY;

  Knight();
  void knightMovement(Board chessBoard[][8], Knight *piece, int indexX,
                      int indexY);
};

#endif
