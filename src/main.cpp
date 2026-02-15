#include "bishop.hpp"
#include "board.hpp"
#include "knight.hpp"
#include "pawn.hpp"
#include "rook.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void processInput(RenderWindow &window, Event *event);
void initializeBoard();
void initializeWhitePawns();
void initializeWhiteBishops();
void initializeWhiteRooks();
void initializeWhiteKnight();

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 1000;

// Object initialization
Board chessBoard[8][8];

Pawn whitePawns[8];

Bishop whiteLS_Bishop;
Bishop whiteDS_Bishop;

Rook whiteRookLeft;
Rook whiteRookRight;

Knight whiteKnightLeft;
Knight whiteKnightRight;

int main() {
  RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "ChessGame");

  initializeBoard();

  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }
      // Input Handling
      processInput(window, &event);
    }

    window.clear(Color::Black);

    // Render the Chess Board;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        // assign indices to the chessboard sqaures
        chessBoard[i][j].squareIndices = Vector2i(i, j);
        window.draw(chessBoard[i][j].square);
      }
    }

    // Render white pawns
    for (int i = 0; i < 8; i++) {
      window.draw(whitePawns[i].pawnSprite);
    }

    // Render white bishops
    window.draw(whiteLS_Bishop.whiteBishopSprite);
    window.draw(whiteDS_Bishop.whiteBishopSprite);

    // Render white rook
    window.draw(whiteRookLeft.whiteRookSprite);
    window.draw(whiteRookRight.whiteRookSprite);

    // Render white knight
    window.draw(whiteKnightLeft.whiteKnightSprite);
    window.draw(whiteKnightRight.whiteKnightSprite);
    window.display();
  }
}

void processInput(RenderWindow &window, Event *event) {
  if (Keyboard::isKeyPressed(Keyboard::Escape)) {
    window.close();
  }

  if (event->type == Event::MouseButtonPressed) {

    if (event->mouseButton.button == Mouse::Right) {

      for (int i = 0; i < 8; i++) {
        cout << whitePawns[i].isSelected << endl;
      }
      cout << endl;
    }

    if (event->mouseButton.button == Mouse::Left) {

      // Get the square where the mouse clicked
      // check if that square is empty or not

      Vector2i mousePosI = Mouse::getPosition(window);

      // Piece Selection
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          if (chessBoard[i][j].square.getGlobalBounds().contains(
                  static_cast<Vector2f>(mousePosI))) {
            if (!chessBoard[i][j].isEmpty) {

              // White Pawn
              if (chessBoard[i][j].currentHoldingPieceName == "white_pawn") {
                whitePawns[j].isSelected = true;
              } else if (chessBoard[i][j].currentHoldingPieceName ==
                         "lightSquare_Bishop") {
                whiteLS_Bishop.isSelected = true;

              } else if (chessBoard[i][j].currentHoldingPieceName ==
                         "darkSquare_Bishop") {
                whiteDS_Bishop.isSelected = true;
              } else if (chessBoard[i][j].currentHoldingPieceName ==
                         "whiteRookLeft") {
                whiteRookLeft.isSelected = true;
              } else if (chessBoard[i][j].currentHoldingPieceName ==
                         "whiteRookRight") {
                whiteRookRight.isSelected = true;
              } else if (chessBoard[i][j].currentHoldingPieceName ==
                         "whiteKnightLeft") {
                whiteKnightLeft.isSelected = true;
              } else if (chessBoard[i][j].currentHoldingPieceName ==
                         "whiteKnightRight") {
                whiteKnightRight.isSelected = true;
              }

              // rest of the pieces will go here....
              // .
              // .
              // .
              // .
              // .
            }

            // Piece movement
            if (chessBoard[i][j].isEmpty) {
              if (whitePawns[j].isSelected) {
                whitePawns[j].pawnMovement(chessBoard, &whitePawns[j], i, j);
              } else if (whiteLS_Bishop.isSelected) {
                whiteLS_Bishop.bishopMovement(chessBoard, &whiteLS_Bishop, i,
                                              j);
              } else if (whiteDS_Bishop.isSelected) {
                whiteDS_Bishop.bishopMovement(chessBoard, &whiteDS_Bishop, i,
                                              j);
              } else if (whiteRookLeft.isSelected) {
                whiteRookLeft.rookMovement(chessBoard, &whiteRookLeft, i, j);
              } else if (whiteRookRight.isSelected) {
                whiteRookRight.rookMovement(chessBoard, &whiteRookRight, i, j);
              } else if (whiteKnightLeft.isSelected) {
                whiteKnightLeft.knightMovement(chessBoard, &whiteKnightLeft, i,
                                               j);
              } else if (whiteKnightRight.isSelected) {
                whiteKnightRight.knightMovement(chessBoard, &whiteKnightRight,
                                                i, j);
              }
            }
          }
        }
      }
    }
  }
}
void initializeBoard() {

  int offsetX = 0;
  int offsetY = 0;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {

      Board board;
      board.square.setPosition(200 + offsetX, 100 + offsetY);

      // Chess Board Coloring
      if (i % 2 == 0) {
        // light sq -> dark sq
        if (j % 2 == 0) {
          board.square.setFillColor(Color(238, 238, 210));
        } else {
          board.square.setFillColor(Color(118, 150, 86));
        }
      } else {
        // dark sq -> light sq
        if (j % 2 == 0) {
          board.square.setFillColor(Color(118, 150, 86));
        } else {
          board.square.setFillColor(Color(238, 238, 210));
        }
      }

      chessBoard[i][j] = board;
      offsetX += 100;
    }

    offsetX = 0;
    offsetY += 100;
  }

  // Initialize Pieces
  initializeWhitePawns();
  initializeWhiteBishops();
  initializeWhiteRooks();
  initializeWhiteKnight();
}

void initializeWhitePawns() {
  // White pawn
  for (int i = 0; i < 8; i++) {
    chessBoard[6][i].setCurrentPawn(&whitePawns[i]);
    whitePawns[i].currentSquare = &chessBoard[6][i];
  }
}

void initializeWhiteBishops() {
  // Light Square White Bishop
  whiteLS_Bishop.pieceName = "lightSquare_Bishop";
  chessBoard[7][5].setCurrentBishop(&whiteLS_Bishop);
  whiteLS_Bishop.currentSqaure = &chessBoard[7][5];
  whiteLS_Bishop.currentPositionX = 7;
  whiteLS_Bishop.currentPositionY = 5;

  // Dark Square White Bishop
  whiteDS_Bishop.pieceName = "darkSquare_Bishop";
  chessBoard[7][2].setCurrentBishop(&whiteDS_Bishop);
  whiteDS_Bishop.currentSqaure = &chessBoard[7][2];
  whiteDS_Bishop.currentPositionX = 7;
  whiteDS_Bishop.currentPositionY = 2;
}
void initializeWhiteRooks() {
  // White Rook_Left
  whiteRookLeft.pieceName = "whiteRookLeft";
  chessBoard[7][0].setCurrentRook(&whiteRookLeft);
  whiteRookLeft.currentSqaure = &chessBoard[7][0];
  whiteRookLeft.currentPositionX = 7;
  whiteRookLeft.currentPositionY = 0;

  // White Rook_Right
  whiteRookRight.pieceName = "whiteRookRight";
  chessBoard[7][7].setCurrentRook(&whiteRookRight);
  whiteRookRight.currentSqaure = &chessBoard[7][7];
  whiteRookRight.currentPositionX = 7;
  whiteRookRight.currentPositionY = 7;
}

void initializeWhiteKnight() {
  // White Knight Left
  whiteKnightLeft.pieceName = "whiteKnightLeft";
  chessBoard[7][1].setCurrentKnight(&whiteKnightLeft);
  whiteKnightLeft.currentSqaure = &chessBoard[7][1];
  whiteKnightLeft.currentPositionX = 7;
  whiteKnightLeft.currentPositionY = 1;

  whiteKnightRight.pieceName = "whiteKnightRight";
  chessBoard[7][6].setCurrentKnight(&whiteKnightRight);
  whiteKnightRight.currentSqaure = &chessBoard[7][6];
  whiteKnightRight.currentPositionX = 7;
  whiteKnightRight.currentPositionY = 6;
}
