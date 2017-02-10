// LED pyramid idea by JK
// Work on Arduino code including snake and others by
// Daniel Rojas (danielrojas.net) and
// JH
#include <Arduino.h>
#include "defs.h"

#define POLYHEDRON TETRAHEDRON
#define PLATFORM   PL_ARDUINO

#include "polyhedron.h"
#include "snake.h"

void setup() {
  initSnake(4); // initalize the snake with a certain displayed length
}

void loop() {
  advanceSnake();        // make snake move along the edges of the pyramid, randomly deciding which path to take
  //growSnake(); // every once in a while, make the snake longer
  writeLEDs(getSnake()); // actually send output to the LEDs
}
