#ifndef ROOK_HPP
#define ROOK_HPP

#include <SFML/Graphics.hpp>

class Board;

class Rook {
public:
  std::string pieceName;

  sf::Texture whiteRookTexture;
  sf::Sprite whiteRookSprite;

  bool isSelected = false;
  Board *currentSqaure;

  int currentPositionX;
  int currentPositionY;

  Rook();
  void rookMovement(Board chessBoard[0][8], Rook *piece, int indexX,
                    int indexY);
};

#endif
