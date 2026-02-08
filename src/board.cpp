#include "board.hpp"
#include "pawn.hpp"
#include <iostream>

using namespace std;
using namespace sf;

Board::Board() { square.setSize(Vector2(100.0f, 100.0f)); }

void Board::setCurrentPiece(Pawn *piece) {
  if (isEmpty) {
    // set the piece within the block
    piece->pawnSprite.setPosition(square.getPosition() - Vector2f(10, 10));
    currentHoldingPieceName = piece->pieceName;
    isEmpty = false;
  }
}

void Board::removePreviousPiece(Board *previousSqaure) {
  if (!previousSqaure->isEmpty) {
    // remove the current piece
    previousSqaure->isEmpty = true;
    previousSqaure->currentHoldingPieceName = " ";
  }
}

void Board::getCurrentPiece() {
  // check if the current block has any piece on it
  if (isEmpty) {
    cout << "Sqaure is Empty";
  } else {
    // return the current piece
    cout << "";
  }
}
