#include <SFML/Graphics.hpp>
#include <iostream>

#include "board.hpp"
#include "pawn.hpp"

using namespace std;
using namespace sf;

Pawn::Pawn() {
  if (!pawnTexture.loadFromFile("sprites\\white-pawn.png")) {
    cout << "FAILED TO LOAD WHITE PAWN TEXTURE" << endl;
  }
  pawnSprite.setTexture(pawnTexture);
  pawnSprite.setScale(0.9, 0.9);
}

void Pawn::pawnMovement(Board chessboard[][8], Pawn *piece, int indexX,
                        int indexY) {
  if (Pawn::isSelected) {
    // move the pawn only if selected
    // move the pawn only if the squares are available
    // move the pawn only if it can capture anything
    //      -> make another function to check if capture is possible or not

    // Pawn Movement Rules
    // 1) can only move upwards = check
    // 2) can only move one square = check
    // 3) can only move two squares if it is the first move

    if (indexX == piece->currentSquare->squareIndices.x - 1 &&
        indexY == piece->currentSquare->squareIndices.y &&
        piece->currentSquare->squareIndices.x != -1) {

      if (chessboard[indexX][piece->currentSquare->squareIndices.y].isEmpty) {
        chessboard[indexX][piece->currentSquare->squareIndices.y]
            .removePreviousPiece(Pawn::currentSquare);
        chessboard[indexX][piece->currentSquare->squareIndices.y]
            .setCurrentPiece(piece);
        Pawn::currentSquare =
            &chessboard[indexX][piece->currentSquare->squareIndices.y];
        Pawn::isSelected = false;
      }
    }

    cout << piece->currentSquare->squareIndices.x << " "
         << piece->currentSquare->squareIndices.y << endl;
  }
}
