#ifndef PAWN_HPP
#define PAWN_HPP

#include <SFML/Graphics.hpp>

// Forward declaration for Board Class
class Board;

class Pawn {
public:
  std::string pieceName = "white_pawn";
  sf::Texture pawnTexture;
  sf::Sprite pawnSprite;
  bool isSelected = false;
  Board *currentSquare;

  int pieceOrigionalRow;
  int pieceOrigionalCol = 2;

  bool pawnFirstMove = true;

  Pawn();
  void pawnMovement(Board chessBoard[][8], Pawn *piece, int indexX, int indexY);
};

#endif
