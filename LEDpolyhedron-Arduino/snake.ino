// Make a snake run along the edges of the polyhedron

// Snake definitions
const int snakemaxlength = 4;
const long snakeupdatedelay = 75;
const long snakelengthupdatedelay = 5000;

// Variables
byte snake[snakemaxlength]; // stores what LEDs the snake is on. 0th element is the head
int snakedisplaylength = 4;
boolean snakeonvertex = true;

// For timing
long snakeupdatetime=0;
long snakelengthupdatetime=0;

// Functions ////////////////////////////////////////////////

// Snake management

void initSnake(int _snakelength) {
  // Put snake head at the last led (11 on tetrahedron) and all further elements on 10, 9, 8, ...
  for(int i=0;i<snakemaxlength;i++) {
    snake[i] = NUMBER_OF_LEDS - 1 - i;
  }
}

void initSnake() {
  initSnake(snakemaxlength);
}

// return 12 bit LED array with current snake position
long getSnake() {
  long _snake=(long)0;
  for(int i=0;i<snakedisplaylength;i++) {
    _snake = _snake | (long)1 << (NUMBER_OF_LEDS - 1 - snake[i] );
  } 
  return _snake;
}

// Snake movement and growth

void advanceSnake() {
  if(millis() - snakeupdatetime >= snakeupdatedelay) {    
    advanceSnakeNow();
    snakeupdatetime += snakeupdatedelay; 
  }
}

void growSnake() {
  if(millis() - snakelengthupdatetime >= snakelengthupdatedelay) {    
    if(++snakedisplaylength > snakemaxlength)
      snakedisplaylength = 1;
    snakelengthupdatetime += snakelengthupdatedelay; 
  }
}


// Snake logic

long advanceSnakeNow() {
  for(int i=snakemaxlength-1;i>0;i--) {
    snake[i] = snake[i-1];
  } 
  snake[0] = decideNewSnake();
}

long decideNewSnake() {
  snakeonvertex = !snakeonvertex;
  if(!snakeonvertex)
    return getNewSnakeOnVertex(snake[0]); // decide randomly
  else
    return getNewSnakeOnEdge(snake[0]); // advance along edge
}

int getNewSnakeOnEdge(int currentPixel) {
  return NEIGHBOURS[currentPixel][0]; // chose 0th element of neighbour array
}

int getNewSnakeOnVertex(int currentPixel) {
  int _rand = random(1,EDGES_PER_VERTEX); // choose 1st or 2nd element of neighbour array
  return NEIGHBOURS[currentPixel][_rand];
}

