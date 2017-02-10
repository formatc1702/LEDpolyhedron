/*

 Icosahedron layout

 < TODO >

*/

// Constant definitions ///////////////////////////////////////////////

// Geometry definition
#define NUMBER_OF_EDGES  30
#define EDGES_PER_VERTEX  5

#define NUMBER_OF_LEDS NUMBER_OF_EDGES * 2

// pin definitions
#if PLATFORM==ARDUINO
// Arduino Uno
#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8
#define H 9
#define I 10
#define J 11
#define K 12
#define L 13

#else
// ATtiny88
#include <avr/io.h>
#define A PD0
#define B PD2
#define C PC4
#define D PC2
#define E PC0
#define F PD4
#define G PD6
#define H PB7
#define I PB5
#define J PB3
#define K PB0
#define L PB1

#endif

// two bytes per edge, antiparallel to each other
const char ledpins[NUMBER_OF_LEDS][2] = {
  {A,B},
  {A,C},
  {A,D},
  {A,E},
  {A,F},
  {B,A},
  {C,A},
  {D,A},
  {E,A},
  {F,A},
  {F,B},
  {B,F},
  {B,C},
  {C,B},
  {C,D},
  {D,C},
  {D,E},
  {E,D},
  {E,F},
  {F,E},
  {F,G},
  {B,G},
  {B,H},
  {C,H},
  {C,I},
  {D,I},
  {D,J},
  {E,J},
  {E,K},
  {F,K},
  {G,F},
  {F,B},
  {H,B},
  {H,C},
  {I,C},
  {I,D},
  {J,D},
  {J,E},
  {K,E},
  {K,F},
  {K,G},
  {G,K},
  {G,H},
  {H,G},
  {H,I},
  {I,H},
  {I,J},
  {J,I},
  {J,K},
  {K,J},
  {K,L},
  {G,L},
  {H,L},
  {I,L},
  {J,L},
  {L,K},
  {L,G},
  {L,H},
  {L,I},
  {L,J}
};

// Define neighboring LEDs for each LED
// 0th neighbour: LED on same edge
// 1st and 2nd neighbour: LEDs on same vertex but on other edge
const char NEIGHBOURS[NUMBER_OF_LEDS][EDGES_PER_VERTEX] = {
{ 5, 1, 2, 3, 4},
{ 6, 0, 2, 3, 4},
{ 7, 0, 1, 3, 4},
{ 8, 0, 1, 2, 4},
{ 9, 0, 1, 2, 3},
{ 0,11,12,21,22},
{ 1,13,14,23,24},
{ 2,15,16,25,26},
{ 3,17,18,27,28},
{ 4,10,19,20,29},
{11, 9,19,20,29},
{10, 5,12,21,22},
{13, 5,11,21,22},
{12, 6,14,23,24},
{15, 6,13,23,24},
{14, 7,16,25,26},
{17, 7,15,25,26},
{16, 8,18,27,28},
{19, 8,17,27,28},
{18, 9,10,20,29},
{30, 9,10,19,29},
{31, 5,11,12,22},
{32, 5,11,12,21},
{33, 6,13,14,24},
{34, 6,13,14,23},
{35, 7,15,16,26},
{36, 7,15,16,25},
{37, 8,17,18,28},
{38, 8,17,18,27},
{39, 9,10,19,20},
{20,31,41,42,51},
{21,30,41,42,51},
{22,33,43,44,52},
{23,32,43,44,52},
{24,35,45,46,53},
{25,34,45,46,53},
{26,37,47,48,54},
{27,36,47,48,54},
{28,39,49,50,55},
{29,39,49,50,55},
{41,38,39,49,50},
{40,30,31,42,51},
{43,30,31,41,51},
{42,32,33,44,52},
{45,32,33,43,52},
{44,34,35,36,53},
{47,34,35,45,53},
{46,36,37,48,54},
{49,36,37,47,54},
{48,38,39,40,50},
{55,38,39,40,49},
{56,30,31,41,42},
{57,32,33,43,44},
{58,34,35,45,46},
{59,36,37,47,48},
{50,56,57,58,59},
{51,55,57,58,59},
{52,55,56,58,59},
{53,55,56,57,59},
{54,55,56,57,58}
};
