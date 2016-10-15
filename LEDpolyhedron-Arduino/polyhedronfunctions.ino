// Take care of running the LEDs

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

// Timing stuff (in microseconds)
#define LED_ONTIME 100
#define LED_OFFTIME 1
 
// Arduino pin definitions
#define A 8
#define B 9
#define C 10
#define D 11

// LED pin definitions
#define ANODE 0
#define CATHODE 1
 
// two bytes per edge, antiparallel to each other 
const byte ledpins[NUMBER_OF_LEDS][2] = {
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
  {10,3,6}};

// Functions //////////////////////////////////////////////////

// Write all LEDs at once
// Pass an int, n lower bits stand for the n polyhedron LEDs
void writeLEDs(long _ledState) {
  for(int i=0;i<NUMBER_OF_LEDS;i++) {
    writeLed(i,(_ledState >> (NUMBER_OF_LEDS - 1 - i)) & (long)1);
    delayMicroseconds(LED_ONTIME);
    writeLed(i,0); 
    delayMicroseconds(LED_OFFTIME);
  }
}

// Write a single LED (direct charlieplex pin control)
void writeLed(byte led, long state) {
  if(state == (long)1) {
    pinMode(ledpins[led][ANODE],OUTPUT);
    pinMode(ledpins[led][CATHODE],OUTPUT);
    digitalWrite(ledpins[led][ANODE],HIGH);
    digitalWrite(ledpins[led][CATHODE],LOW);
  } 
  else {
    pinMode(ledpins[led][ANODE],INPUT);
    pinMode(ledpins[led][CATHODE],INPUT);   
  }
}
