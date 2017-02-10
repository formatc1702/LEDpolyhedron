// LED pyramid idea by JK
// Work on Arduino code including snake and others by
// Daniel Rojas (danielrojas.net) and
// JH
#include <Arduino.h>

#define TETRAHEDRON   4
#define CUBE          6
#define OCTAHEDRON    8
#define DODECAHEDRON 12
#define ICOSAHEDRON  20

#define PL_ARDUINO 0
#define PL_ATTINY  1

#define POLYHEDRON TETRAHEDRON
#define PLATFORM   PL_ARDUINO

#include "polyhedron.h"
#include "snake.h"


// #include "_04_tetrahedron.cpp"
// #include "_06_cube.cpp" // unfinished
// #include "_08_octahedron.cpp"
// #include "_12_dodecahedron.cpp" // unfinished
// #include "_20_icosahedron.cpp"


void setup() {
  initSnake(4); // initalize the snake with a certain displayed length
}

void loop() {
//  advanceSnake(); // make snake move along the edges of the pyramid, randomly deciding which path to take
  //growSnake(); // every once in a while, make the snake longer
//  writeLEDs(getSnake()); // actually send output to the LEDs
  writeLEDs((long)11111111111111111111111111111111); // actually send output to the LEDs
}
