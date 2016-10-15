// Some macros that might be useful to directly access
// vertices, edges and planes on the tetrahedron

/*

const int ALL =  0B111111111111;
const int NONE = 0B000000000000;
const int PLANE_A0 = 0B111000000000;
const int PLANE_A1 = 0B000111000000;
const int PLANE_A2 = 0B000000111111;
const int PLANE_B0 = 0B000100100001;
const int PLANE_B1 = 0B100000010010;
const int PLANE_B2 = 0B011011001100;
const int PLANE_C0 = 0B000010011000;
const int PLANE_C1 = 0B010000100100;
const int PLANE_C2 = 0B101101000011;
const int PLANE_D0 = 0B000001000110;
const int PLANE_D1 = 0B001000001001;
const int PLANE_D2 = 0B110110110000;
const int VERTEX_A = PLANE_A0;
const int VERTEX_B = PLANE_B0;
const int VERTEX_C = PLANE_C0;
const int VERTEX_D = PLANE_D0;
const int EDGE_AB = 0B100100000000;
const int EDGE_AC = 0B010010000000;
const int EDGE_AD = 0B001001000000;
const int EDGE_BC = 0B000000110000;
const int EDGE_BD = 0B000000000011;
const int EDGE_CD = 0B000000001100;
const int FACE_ABC = PLANE_D2;
const int FACE_ABD = PLANE_C2;
const int FACE_ACD = PLANE_B2;
const int FACE_BCD = PLANE_A2;

const int EDGES[6] = {
  EDGE_AB,EDGE_AC,EDGE_AD,EDGE_BC,EDGE_BD,EDGE_CD
};

const int VERTICES[6] = {
  VERTEX_A,VERTEX_B,VERTEX_C,VERTEX_D
};


const int PLANES[4][3] = {
  {
    PLANE_A0,
    PLANE_A1,
    PLANE_A2
  }
  ,
  {
    PLANE_B0,
    PLANE_B1,
    PLANE_B2
  }
  ,
  {
    PLANE_C0,
    PLANE_C1,
    PLANE_C2
  }
  ,
  {
    PLANE_D0,
    PLANE_D1,
    PLANE_D2                                                                                                                                                  
  }
};


// */

/*

 LED orientierungen (0..11)
 
 B,A
 C,A
 D,A
 A,B
 A,C
 A,D
 C,B
 B,C
 D,C
 C,D
 B,D
 D,B
 
 */

/*

 All LEDs
 
 ALL =  0B111111111111
 NONE = 0B000000000000
 
 Ebenen
 
 A0 = 0B111000000000
 A1 = 0B000111000000
 A2 = 0B000000111111
 
 B0 = 0B000100100001
 B1 = 0B100000010010
 B2 = 0B011011001100
 
 C0 = 0B000010011000
 C1 = 0B010000100100
 C2 = 0B101101000011
 
 D0 = 0B000001000110
 D1 = 0B001000001001
 D2 = 0B110110110000
 
 Punkte (Ebene X0)
 
 A = A0
 B = B0
 C = C0
 D = D0
 
 Linien
 
 AB = 0B100100000000
 AC = 0B010010000000
 AD = 0B001001000000
 BC = 0B000000110000
 BD = 0B000000001100
 CD = 0B000000000011
 
 Flaechen (X2)
 
 ABC = D2
 ABD = C2
 ACD = B2
 BCD = A2
 // */

/* 
long planeupdatetime=0;
long planeupdatedelay = 1000;

int counterABCD = 0;
int counter012 = 0;

 abwechselnd die flaechen beleuchten
 if(millis() - planeupdatetime >= planeupdaedelay) {    
   //    if(++counter012 > 2) {t
   //      if(++counterABCD > 3)
   //        counterABCD = 0;
   //      counter012 = 0;
   //    }
   if(++counterABCD > 3)
     counterABCD = 0;
   counter012 = 2;



   ledState = PLANES[counterABCD][counter012];

   planeupdatetime += planeupdatedelay; 
 }
// */