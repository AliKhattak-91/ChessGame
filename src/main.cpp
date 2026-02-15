#include "bishop.hpp"
#include "board.hpp"
#include "pawn.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void processInput(RenderWindow &window, Event *event);
void initializeBoard();
void initializeWhitePawns();
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 1000;

Board chessBoard[8][8];
Pawn whitePawns[8];
Bishop whiteLS_Bishop;
Bishop whiteDS_Bishop;

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

    // Rendering white pawns
    for (int i = 0; i < 8; i++) {
      window.draw(whitePawns[i].pawnSprite);
    }

    window.draw(whiteLS_Bishop.whiteBishopSprite);
    window.draw(whiteDS_Bishop.whiteBishopSprite);
    window.display();
  }
}

void processInput(RenderWindow &window, Event *event) {
  if (Keyboard::isKeyPressed(Keyboard::Escape)) {
    window.close();
  }

  if (event->type == Event::MouseButtonPressed) {
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
                cout << "Light Square selected" << endl;
              } else if (chessBoard[i][j].currentHoldingPieceName ==
                         "darkSquare_Bishop") {
                whiteDS_Bishop.isSelected = true;
                cout << "Dark square bishop selected" << endl;
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

  initializeWhitePawns();
}

void initializeWhitePawns() {
  // White pawn
  for (int i = 0; i < 8; i++) {
    chessBoard[6][i].setCurrentPawn(&whitePawns[i]);
    whitePawns[i].currentSquare = &chessBoard[6][i];
  }

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
