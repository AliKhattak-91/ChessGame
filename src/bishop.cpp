#include <SFML/Graphics.hpp>
#include <iostream>

#include "bishop.hpp"
#include "board.hpp"

using namespace sf;
using namespace std;

Bishop::Bishop() {

  if (!whiteBishopTexture.loadFromFile("sprites\\white-bishop.png")) {
    cout << "FAILED TO LOAD LIGHT SQUARE BISHOP TEXTURE" << endl;
  }
  whiteBishopSprite.setTexture(whiteBishopTexture);
  whiteBishopSprite.setScale(0.8, 0.8);
}

void Bishop::bishopMovement(Board chessBoard[][8], Bishop *piece, int indexX,
                            int indexY) {
  if (piece->isSelected) {
    // Light square bishop only moves on light squares diagonally
    // Use a for loop which checks all the
    // possible diagonals from the bishop positions
    // (there will be only 4 diagonals to check)
    //
    // The check whether the input is valid will be if the user
    // clicks on those diagonals

    // top right (row - 1, col + 1)
    int row = piece->currentPositionX - 1;
    int col = piece->currentPositionY + 1;

    while (row >= 0 && col < 8) {
      if (chessBoard[row][col].isEmpty) {
        if (indexX == row && indexY == col) {
          cout << "Piece moved to: " << row << " " << col << endl;

          chessBoard[row][col].removePreviousPiece(piece->currentSqaure);
          chessBoard[row][col].setCurrentBishop(piece);
          piece->currentSqaure = &chessBoard[row][col];
          piece->currentPositionX = row;
          piece->currentPositionY = col;
          piece->isSelected = false;
          break;
        }
        row--;
        col++;
      } else {
        break;
      }
    }

    // bottom left (row + 1 and col - 1)

    row = piece->currentPositionX + 1;
    col = piece->currentPositionY - 1;

    while (row < 8 && col >= 0) {
      if (chessBoard[row][col].isEmpty) {
        if (indexX == row && indexY == col) {
          cout << "Piece moved to: " << row << " : " << col << endl;

          chessBoard[row][col].removePreviousPiece(piece->currentSqaure);
          chessBoard[row][col].setCurrentBishop(piece);
          piece->currentSqaure = &chessBoard[row][col];
          piece->currentPositionX = row;
          piece->currentPositionY = col;

          piece->isSelected = false;
          break;
        }
        row++;
        col--;
      } else {
        break;
      }
    }

    // top left (row - 1, col - 1)
    row = piece->currentPositionX - 1;
    col = piece->currentPositionY - 1;

    while (row >= 0 && col >= 0) {
      if (chessBoard[row][col].isEmpty) {
        if (indexX == row && indexY == col) {
          cout << "Piece moved to: " << row << " : " << col << endl;

          chessBoard[row][col].removePreviousPiece(piece->currentSqaure);
          chessBoard[row][col].setCurrentBishop(piece);
          piece->currentSqaure = &chessBoard[row][col];
          piece->currentPositionX = row;
          piece->currentPositionY = col;

          piece->isSelected = false;
          break;
        }
        row--;
        col--;
      } else {
        break;
      }
    }

    // bottom right (row + 1, col + 1)

    row = piece->currentPositionX + 1;
    col = piece->currentPositionY + 1;

    while (row < 8 && col < 8) {
      if (chessBoard[row][col].isEmpty) {
        if (indexX == row && indexY == col) {
          cout << "Piece moved to: " << row << " : " << col << endl;

          chessBoard[row][col].removePreviousPiece(piece->currentSqaure);
          chessBoard[row][col].setCurrentBishop(piece);
          piece->currentSqaure = &chessBoard[row][col];
          piece->currentPositionX = row;
          piece->currentPositionY = col;

          piece->isSelected = false;
          break;
        }
        row++;
        col++;
      } else {
        break;
      }
    }

    piece->isSelected = false;
  }
}
