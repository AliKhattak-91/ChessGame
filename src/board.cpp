#include "board.hpp"
#include "bishop.hpp"
#include "pawn.hpp"
#include <iostream>

using namespace std;
using namespace sf;

Board::Board() { square.setSize(Vector2(100.0f, 100.0f)); }

void Board::setCurrentPawn(Pawn *piece) {
  if (isEmpty) {
    // set the piece within the block
    piece->pawnSprite.setPosition(square.getPosition() - Vector2f(0, 0));
    currentHoldingPieceName = piece->pieceName;
    isEmpty = false;
  }
}

void Board::setCurrentBishop(Bishop *piece) {
  if (isEmpty) {
    piece->whiteBishopSprite.setPosition(square.getPosition() - Vector2f(3, 0));
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

void Board::getCurrentPiece(Pawn *piece) {
  // check if the current block has any piece on it
  if (isEmpty) {
    cout << "Sqaure is Empty";
  } else {
    // return the current piece
    cout << piece->pieceName << endl;
  }
}
