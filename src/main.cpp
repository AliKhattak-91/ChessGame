#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

void processInput(RenderWindow *window);
void printBoard();

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 1000;

RectangleShape board[8][8];

int main() {
  RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "ChessGame");

  printBoard();

  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }
      // Input Handling
      processInput(&window);
    }

    window.clear(Color::Black);

    // Render a Rectangle;

    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        window.draw(board[i][j]);
      }
    }

    window.display();
  }
}

void processInput(RenderWindow *window) {
  if (Keyboard::isKeyPressed(Keyboard::Escape)) {
    window->close();
  }
}

void printBoard() {

  int offsetX = 0;
  int offsetY = 0;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      RectangleShape rect;
      rect.setSize(Vector2f(100, 100));
      rect.setPosition(200 + offsetX, 100 + offsetY);

      if (i % 2 == 0) {
        // light sq -> dark sq
        if (j % 2 == 0) {
          rect.setFillColor(Color(238, 238, 210));
        } else {
          rect.setFillColor(Color(118, 150, 86));
        }
      } else {
        // dark sq -> light sq
        if (j % 2 == 0) {
          rect.setFillColor(Color(118, 150, 86));
        } else {
          rect.setFillColor(Color(238, 238, 210));
        }
      }

      board[i][j] = rect;
      offsetX += 100;
    }

    offsetX = 0;
    offsetY += 100;
  }
}
