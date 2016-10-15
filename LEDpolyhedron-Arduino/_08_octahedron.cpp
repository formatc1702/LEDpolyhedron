/*

 Octahedron layout

 < TODO >
 
*/

// Constant definitions ///////////////////////////////////////////////

// Geometry definition
#define NUMBER_OF_EDGES 12
#define EDGES_PER_VERTEX 4

#define NUMBER_OF_LEDS NUMBER_OF_EDGES * 2

// Arduino pin definitions
// Arduino Uno
/*
#define K 2
#define Y 3
#define R 4
#define B 5
#define G 6
#define W 7
// */

// ATtiny84
// /*
#include <avr/io.h>
#define K PA1
#define Y PB2
#define R PB1
#define B PA3
#define G PA5
#define W PA6
// */

// two bytes per edge, antiparallel to each other 
const char ledpins[NUMBER_OF_LEDS][2] = {
  {Y,W},
  {W,Y},
  {K,Y},
  {Y,K},
  {B,K},
  {K,B},
  {W,B},
  {B,W},
  {K,R},
  {R,K},
  {G,K},
  {K,G},
  {W,G},
  {G,W},
  {R,W},
  {W,R},
  {B,R},
  {R,B},
  {G,B},
  {B,G},
  {Y,G},
  {G,Y},
  {R,Y},
  {Y,R}
};

// Define neighboring LEDs for each LED
// 0th neighbour: LED on same edge
// 1st and 2nd neighbour: LEDs on same vertex but on other edge
const char NEIGHBOURS[NUMBER_OF_LEDS][EDGES_PER_VERTEX] = {
  { 1, 7,13,14},
  { 0, 2,21,22},
  { 3, 1,21,22},
  { 2, 4, 9,10},
  { 5, 3, 9,10},
  { 4, 6,17,18},
  { 7, 5,17,18},
  { 6, 0,13,14},
  { 9,15,16,23},
  { 8, 3, 4,10},
  {11, 3, 4, 9},
  {10,12,19,20},
  {13,11,19,20},
  {12, 0, 7,14},
  {15, 0, 7,13},
  {14, 8,16,23},
  {17, 8,15,23},
  {16, 5, 6,18},
  {19, 5, 6,17},
  {18,11,12,20},
  {21,11,12,19},
  {20, 1, 2,22},
  {23, 1, 2,21},
  {22, 8,15,16},
};

