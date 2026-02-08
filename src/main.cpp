#include <SFML/Graphics.hpp>
#include <iostream>
#include <typeinfo>

#include "board.hpp"
#include "pawn.hpp"

using namespace std;
using namespace sf;

void processInput(RenderWindow &window);
void initializeBoard();
void initializeWhitePawns();

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 1000;

Board chessBoard[8][8];
Pawn whitePawn;

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
      processInput(window);
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

    window.draw(whitePawn.pawnSprite);

    window.display();
  }
}

void processInput(RenderWindow &window) {
  if (Keyboard::isKeyPressed(Keyboard::Escape)) {
    window.close();
  }

  if (Mouse::isButtonPressed(Mouse::Left)) {
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
              whitePawn.isSelected = true;
              cout << "Pawn at square: " << i << " " << j
                   << " is selected: " << boolalpha << whitePawn.isSelected
                   << endl;
            }
            // The rest of the pieces will go here
            // .
            // .
            // .
          }

          if (chessBoard[i][j].isEmpty) {
            whitePawn.pawnMovement(chessBoard, &whitePawn, i, j);
          }
        }
      }
    }
  }

  if (Mouse::isButtonPressed(Mouse::Right)) {
    // Get the square where the mouse clicked
    // check if that square is empty or not

    Vector2i mousePosI = Mouse::getPosition(window);

    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (chessBoard[i][j].square.getGlobalBounds().contains(
                static_cast<Vector2f>(mousePosI))) {

          cout << chessBoard[i][j].isEmpty << endl;
          cout << chessBoard[i][j].currentHoldingPieceName << endl;
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

  chessBoard[6][2].setCurrentPiece(&whitePawn);
  whitePawn.currentSquare = &chessBoard[6][2];
}
