#ifndef BISHOP_HPP
#define BISHOP_HPP

#include <SFML/Graphics.hpp>

class Board;

class Bishop {
public:
  std::string pieceName = "lightSquare_Bishop";

  sf::Texture whiteBishopTexture;
  sf::Sprite whiteBishopSprite;

  bool isSelected = false;
  Board *currentSqaure;

  int currentPositionX;
  int currentPositionY;

  Bishop();

  void bishopMovement(Board chessboard[][8], Bishop *piece, int indexX,
                      int indexY);
};

#endif
