#include "board.hpp"
#include "pawn.hpp"

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void processInput(RenderWindow &window, Event *event);
void initializeBoard();
void initializeWhitePawns();
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 1000;

Board chessBoard[8][8];
Pawn whitePawns[8];

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
    window.display();
  }
}

void processInput(RenderWindow &window, Event *event) {
  if (Keyboard::isKeyPressed(Keyboard::Escape)) {
    window.close();
  }

  if (event->type == Event::MouseButtonPressed) {
    event->mouseButton.button = Mouse::Left;

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
            } // rest of the pieces will go here....
              // .
              // .
              // .
              // .
              // .
          }

          // White Pawn movement
          if (chessBoard[i][j].isEmpty) {
            if (whitePawns[j].isSelected) {
              whitePawns[j].pawnMovement(chessBoard, &whitePawns[j], i, j);
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
    chessBoard[6][i].setCurrentPiece(&whitePawns[i]);
    whitePawns[i].currentSquare = &chessBoard[6][i];
  }
}
