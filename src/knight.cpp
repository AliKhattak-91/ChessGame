#include <SFML/Graphics.hpp>
#include <iostream>

#include "board.hpp"
#include "knight.hpp"

using namespace std;
using namespace sf;

Knight::Knight() {
  if (!whiteKnightTexture.loadFromFile("sprites\\white-knight.png")) {
    cout << "FAILED TO LOAD WHITE KNIGHT TEXTURE" << endl;
  }
  whiteKnightSprite.setTexture(whiteKnightTexture);
  whiteKnightSprite.setScale(0.8, 0.8);
}

void Knight::knightMovement(Board chessBoard[][8], Knight *piece, int indexX,
                            int indexY) {
  if (piece->isSelected) {

    // Knight Movement
    // Rules:
    // 1) Knight can move in 8 direction
    // 2) two steps up/down/left/right and one up and one down

    // Upward two places
    if (indexX == piece->currentPositionX - 2 &&
        indexY == piece->currentPositionY + 1) {
      cout << "Knight Moved to: " << indexX << " " << indexY << endl;

      chessBoard[indexX][indexY].removePreviousPiece(piece->currentSqaure);
      chessBoard[indexX][indexY].setCurrentKnight(piece);
      piece->currentSqaure = &chessBoard[indexX][indexY];
      piece->currentPositionX = indexX;
      piece->currentPositionY = indexY;
      piece->isSelected = false;

    } else if (indexX == piece->currentPositionX - 2 &&
               indexY == piece->currentPositionY - 1) {
      cout << "Knight Moved to: " << indexX << " " << indexY << endl;

      chessBoard[indexX][indexY].removePreviousPiece(piece->currentSqaure);
      chessBoard[indexX][indexY].setCurrentKnight(piece);
      piece->currentSqaure = &chessBoard[indexX][indexY];
      piece->currentPositionX = indexX;
      piece->currentPositionY = indexY;
      piece->isSelected = false;

    }
    // Right two places
    else if (indexX == piece->currentPositionX - 1 &&
             indexY == piece->currentPositionY + 2) {
      cout << "Knight Moved to: " << indexX << " " << indexY << endl;

      chessBoard[indexX][indexY].removePreviousPiece(piece->currentSqaure);
      chessBoard[indexX][indexY].setCurrentKnight(piece);
      piece->currentSqaure = &chessBoard[indexX][indexY];
      piece->currentPositionX = indexX;
      piece->currentPositionY = indexY;
      piece->isSelected = false;

    } else if (indexX == piece->currentPositionX + 1 &&
               indexY == piece->currentPositionY + 2) {
      cout << "Knight Moved to: " << indexX << " " << indexY << endl;

      chessBoard[indexX][indexY].removePreviousPiece(piece->currentSqaure);
      chessBoard[indexX][indexY].setCurrentKnight(piece);
      piece->currentSqaure = &chessBoard[indexX][indexY];
      piece->currentPositionX = indexX;
      piece->currentPositionY = indexY;
      piece->isSelected = false;

    }
    // Downward two places
    else if (indexX == piece->currentPositionX + 2 &&
             indexY == piece->currentPositionY + 1) {
      cout << "Knight Moved to: " << indexX << " " << indexY << endl;

      chessBoard[indexX][indexY].removePreviousPiece(piece->currentSqaure);
      chessBoard[indexX][indexY].setCurrentKnight(piece);
      piece->currentSqaure = &chessBoard[indexX][indexY];
      piece->currentPositionX = indexX;
      piece->currentPositionY = indexY;
      piece->isSelected = false;

    } else if (indexX == piece->currentPositionX + 2 &&
               indexY == piece->currentPositionY - 1) {
      cout << "Knight Moved to: " << indexX << " " << indexY << endl;

      chessBoard[indexX][indexY].removePreviousPiece(piece->currentSqaure);
      chessBoard[indexX][indexY].setCurrentKnight(piece);
      piece->currentSqaure = &chessBoard[indexX][indexY];
      piece->currentPositionX = indexX;
      piece->currentPositionY = indexY;
      piece->isSelected = false;

    }
    // Left two places
    else if (indexX == piece->currentPositionX - 1 &&
             indexY == piece->currentPositionY - 2) {
      cout << "Knight Moved to: " << indexX << " " << indexY << endl;

      chessBoard[indexX][indexY].removePreviousPiece(piece->currentSqaure);
      chessBoard[indexX][indexY].setCurrentKnight(piece);
      piece->currentSqaure = &chessBoard[indexX][indexY];
      piece->currentPositionX = indexX;
      piece->currentPositionY = indexY;
      piece->isSelected = false;

    } else if (indexX == piece->currentPositionX + 1 &&
               indexY == piece->currentPositionY - 2) {
      cout << "Knight Moved to: " << indexX << " " << indexY << endl;

      chessBoard[indexX][indexY].removePreviousPiece(piece->currentSqaure);
      chessBoard[indexX][indexY].setCurrentKnight(piece);
      piece->currentSqaure = &chessBoard[indexX][indexY];
      piece->currentPositionX = indexX;
      piece->currentPositionY = indexY;
      piece->isSelected = false;

    } else {
      piece->isSelected = false;
    }
  }
}
