#include <SFML/Graphics.hpp>
#include <iostream>

#include "board.hpp"
#include "rook.hpp"

using namespace std;
using namespace sf;

Rook::Rook() {
  if (!whiteRookTexture.loadFromFile("sprites\\white-rook.png")) {
    cout << "FAILED TO LOAD WHITE ROOK TEXTURE" << endl;
  }
  whiteRookSprite.setTexture(whiteRookTexture);
  whiteRookSprite.setScale(0.8, 0.8);
}

void Rook::rookMovement(Board chessBoard[][8], Rook *piece, int indexX,
                        int indexY) {

  if (piece->isSelected) {

    // Rook Movement Rules:
    // 1) Can go vertical and horizontal only from its currentposition
    // one for loop to check on horizontal
    // one for loop to check on neg horizontal
    //
    // one for loop to check on vertical
    // one for loop to check on neg vertical

    // Upward Direction
    for (int i = piece->currentPositionX - 1; i >= 0; i--) {
      // check if the squares are empty to move
      if (chessBoard[i][piece->currentPositionY].isEmpty) {
        if (indexX == i && indexY == piece->currentPositionY) {
          chessBoard[i][piece->currentPositionY].removePreviousPiece(
              piece->currentSqaure);
          chessBoard[i][piece->currentPositionY].setCurrentRook(piece);
          piece->currentSqaure = &chessBoard[i][piece->currentPositionY];
          piece->currentPositionX = i;
          piece->isSelected = false;
          break;
        }
      } else {
        break;
      }
    }
    // Downward Direction
    for (int i = piece->currentPositionX + 1; i < 8; i++) {
      // check if the squares are empty to move
      if (chessBoard[i][piece->currentPositionY].isEmpty) {
        if (indexX == i && indexY == piece->currentPositionY) {
          chessBoard[i][piece->currentPositionY].removePreviousPiece(
              piece->currentSqaure);
          chessBoard[i][piece->currentPositionY].setCurrentRook(piece);
          piece->currentSqaure = &chessBoard[i][piece->currentPositionY];
          piece->currentPositionX = i;
          piece->isSelected = false;
          break;
        }
      } else {
        break;
      }
    }

    // Right Direction
    for (int i = piece->currentPositionY + 1; i < 8; i++) {
      if (chessBoard[piece->currentPositionX][i].isEmpty) {
        if (indexX == piece->currentPositionX && indexY == i) {
          chessBoard[piece->currentPositionX][i].removePreviousPiece(
              piece->currentSqaure);
          chessBoard[piece->currentPositionX][i].setCurrentRook(piece);
          piece->currentSqaure = &chessBoard[piece->currentPositionX][i];
          piece->currentPositionY = i;
          piece->isSelected = false;
          break;
        }
      } else {
        break;
      }
    }

    // Left Direction
    for (int i = piece->currentPositionY - 1; i >= 0; i--) {
      if (chessBoard[piece->currentPositionX][i].isEmpty) {
        if (indexX == piece->currentPositionX && indexY == i) {
          chessBoard[piece->currentPositionX][i].removePreviousPiece(
              piece->currentSqaure);
          chessBoard[piece->currentPositionX][i].setCurrentRook(piece);
          piece->currentSqaure = &chessBoard[piece->currentPositionX][i];
          piece->currentPositionY = i;
          piece->isSelected = false;
          break;
        }
      } else {
        break;
      }
    }

    piece->isSelected = false;
  }
}
