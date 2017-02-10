#include <Arduino.h>

#if   POLYHEDRON == TETRAHEDRON
#include "_04_tetrahedron.h"
#elif POLYHEDRON == CUBE
#include "_06_cube.h"
#elif POLYHEDRON == OCTAHEDRON
#include "_08_octahedron.h"
#elif POLYHEDRON == DODECAHEDRON
#include "_12_dodecahedron.h"
#elif POLYHEDRON == ICOSAHEDRON
#include "_20_icosahedron.h"
#else
#error "Wrong definiton of POLYHEDRON"
#endif

#if   PLATFORM == PL_ARDUINO
#elif PLATFORM == PL_ATTINY
#else
#error "Wrong definition of PLATFORM"
#endif

// Timing stuff (in microseconds)
#define LED_ONTIME 100
#define LED_OFFTIME 1

// LED pin definitions
#define ANODE   0
#define CATHODE 1

void writeLEDs(long _ledState);
void writeLed (byte led, long state);
