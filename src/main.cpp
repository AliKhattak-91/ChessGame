#include <SFML/Graphics.hpp>
#include <ios>
#include <iostream>
#include <typeinfo>

#include "board.hpp"
#include "pawn.hpp"

using namespace std;
using namespace sf;

void processInput(RenderWindow &window);
void printBoard();

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 1000;

Board chessBoard[8][8];
Pawn whitePawn;

int main() {
  RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "ChessGame");

  printBoard();
  chessBoard[6][2].setCurrentPiece(&whitePawn.pawnSprite);
  whitePawn.currentSquare = &chessBoard[6][2];

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

    // Render a Rectangle;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
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

    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (chessBoard[i][j].square.getGlobalBounds().contains(
                static_cast<Vector2f>(mousePosI))) {

          if (!chessBoard[i][j].isEmpty) {
            whitePawn.isSelected = true;
          }

          // Moving the pawn
          if (whitePawn.isSelected) {
            if (chessBoard[i][j].isEmpty) {

              chessBoard[i][j].removePreviousPiece(whitePawn.currentSquare);
              chessBoard[i][j].setCurrentPiece(&whitePawn.pawnSprite);
              whitePawn.currentSquare = &chessBoard[i][j];
              whitePawn.isSelected = false;
            }
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
        }
      }
    }
  }
}
void printBoard() {

  int offsetX = 0;
  int offsetY = 0;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {

      Board board;
      board.square.setPosition(200 + offsetX, 100 + offsetY);

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
}
