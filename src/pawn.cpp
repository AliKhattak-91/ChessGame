#include <SFML/Graphics.hpp>
#include <iostream>

#include "pawn.hpp"

using namespace std;
using namespace sf;

Pawn::Pawn() {
  if (!pawnTexture.loadFromFile("sprites\\white-pawn.png")) {
    cout << "FAILED TO LOAD WHITE PAWN TEXTURE" << endl;
  }
  pawnSprite.setTexture(pawnTexture);
  pawnSprite.setScale(0.9, 0.9);
}

void Pawn::pawnMovement() {
  if (isSelected) {
    // move the pawn only if selected
    // move the pawn only if the squares are available
    // move the pawn only if it can capture anything
    //      -> make another function to check if capture is possible or not
  }
}
