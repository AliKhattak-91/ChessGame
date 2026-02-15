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
  pawnSprite.setScale(0.75, 0.75);
}

void Pawn::pawnMovement(Board chessboard[][8], Pawn *piece, int indexX,
                        int indexY) {

  if (piece->isSelected) {
    // move the pawn only if selected
    // move the pawn only if the squares are available
    // move the pawn only if it can capture anything
    //      -> make another function to check if capture is possible or not

    // Pawn Movement Rules
    // 1) can only move upwards = check
    // 2) can only move one square = check
    // 3) can only move two squares if it is the first move

    // if first move is true, then two square movement is allowed

    // check if the indexX and indexY are allowed movemable sqaures
    if (piece->pawnFirstMove) {
      if (indexX == piece->currentSquare->squareIndices.x - 1 ||
          indexX == piece->currentSquare->squareIndices.x - 2 &&
              indexY == piece->currentSquare->squareIndices.y) {

        // check whether the allowable squares are empty or not
        // ==> move the pawn
        if (chessboard[indexX][piece->currentSquare->squareIndices.y].isEmpty) {
          chessboard[indexX][piece->currentSquare->squareIndices.y]
              .removePreviousPiece(piece->currentSquare);
          chessboard[indexX][piece->currentSquare->squareIndices.y]
              .setCurrentPawn(piece);
          piece->currentSquare =
              &chessboard[indexX][piece->currentSquare->squareIndices.y];
          piece->isSelected = false;
          piece->pawnFirstMove = false;
        }
      } else {
        piece->isSelected = false;
      }
    }

    // One square upwards than pawn
    if (indexX == piece->currentSquare->squareIndices.x - 1 &&
        indexY == piece->currentSquare->squareIndices.y &&
        piece->currentSquare->squareIndices.x != -1) {

      if (chessboard[indexX][piece->currentSquare->squareIndices.y].isEmpty) {
        chessboard[indexX][piece->currentSquare->squareIndices.y]
            .removePreviousPiece(piece->currentSquare);
        chessboard[indexX][piece->currentSquare->squareIndices.y]
            .setCurrentPawn(piece);
        piece->currentSquare =
            &chessboard[indexX][piece->currentSquare->squareIndices.y];
        piece->isSelected = false;
      }
    } else {
      piece->isSelected = false;
      // Change back the selection color here
      //
      // NOTE;
      // - changing square color isnt simple
      // - because if a pawn is at light square first and moves
      // - now it is on a dark square, hence
      // - checking whether the column is even or odd will fail
      //
      // NOTE;
      // - only solution which comes to mind right now is
      // - to tell each pawn on which square is it on (light or dark).
      // - this way when the pawn moves we change the color of the previous
      // - square and assign it new square
    }
  }
}
