// user configurable parameters

sides         =  3; // 3 = triangle
                    // 4 = square
                    // 5 = pentagon
                    // Warning: $diameter is the diagonal when using a square!
diameter       = 80;
height         = 12;
cutoff         = 10;
wallthickness  =  3;
roofthickness  =  2;
holediam       =  4;
edgeradius     =  5;
powerjackdiam =   4.5;


_  = 0.5; // just a little overlap

difference () {
    // main body
    cylinder (height, diameter/2, diameter/2, $fn=sides);
    // cutout
    translate ([0,0,-_]) {
        difference () {
            // main cutout
            cylinder (height - roofthickness + _, diameter/2 - wallthickness, diameter/2 - wallthickness, $fn=sides);
            // leave something at the edges to attach rubber feet or something
            for (i = [0:sides-1]) {
                rotate (i * 360 / sides, [0,0,1]) {
                    translate ([diameter/2 - wallthickness - cutoff,-(sides*cutoff+_)/2,-_/2]) {
                        cube ([cutoff+_,sides*cutoff+_,height+_]);
                    }
                }
            }
        }
    }
    // for the power wires
    cylinder (height+_,holediam,holediam/2, $fn=sides);
    translate([0,0,height-roofthickness-4]) {
        rotate ([0,-90,0]) {
            cylinder (diameter,powerjackdiam/2,powerjackdiam/2,$fn=20);
        }
    }
}
// rounded edges
/*
 translate ([diameter/2-edgeradius,0,-_/2]) {
    cylinder (height+_,edgeradius,edgeradius, $fn=40);
}
// */

    