// Timing stuff (in microseconds)
#define LED_ONTIME 100
#define LED_OFFTIME 1
 
// LED pin definitions
#define ANODE   0
#define CATHODE 1
 
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

