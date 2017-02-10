#if POLYHEDRON==TETRAHEDRON
/*

 Tetrahedron layout

 //             A
 //            /|\
 //           / 2 \
 //          0  |  1
 //         /   |   \
 //        /    |    \
 //       /     5     \
 //      3      |      4
 //     /       |       \
 //    /      __D__      \
 //   /   _10      9___   \
 //  /__11             8___\
 // B------6---------7------C

*/

// Constant definitions ///////////////////////////////////////////////

// Geometry definition
#define NUMBER_OF_EDGES 6
// tetrahedron  6
// cube         12
// octahedron   12
// dodecahedron 30
// icosahedron  30

#define EDGES_PER_VERTEX 3
// tetrahedron  3
// cube         3
// octahedron   4
// dodecahedron 3
// icosahedron  5

#define NUMBER_OF_LEDS NUMBER_OF_EDGES * 2

// Arduino pin definitions
// Arduino Uno
// /*
#define A 8
#define B 9
#define C 10
#define D 11
// */

// ATtiny45/85
/*
#define A PB2
#define B PB4
#define C PB1
#define D PB3
// */

// two bytes per edge, antiparallel to each other
/* const int ledpins[NUMBER_OF_LEDS][2] = {
  {B,A},
  {C,A},
  {D,A},
  {A,B},
  {A,C},
  {A,D},
  {C,B},
  {B,C},
  {D,C},
  {C,D},
  {B,D},
  {D,B}};

// Define neighboring LEDs for each LED
// 0th neighbour: LED on same edge
// 1st and 2nd neighbour: LEDs on same vertex but on other edge
const int NEIGHBOURS[NUMBER_OF_LEDS][EDGES_PER_VERTEX] = {
  {3,1,2},
  {4,0,2},
  {5,0,1},
  {0,6,11},
  {1,7,8},
  {2,10,9},
  {7,3,11},
  {6,4,8},
  {9,4,7},
  {8,5,10},
  {11,5,9},
  {10,3,6}
};
// */
#endif
