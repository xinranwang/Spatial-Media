//
//  Bitman.h
//  many_to_one
//
//  Created by Xinran Wang on 2/26/13.
//
//

#ifndef __many_to_one__Bitman__
#define __many_to_one__Bitman__

#include <iostream>

#include "ofMain.h"

static const int pixelSize = 10;

class Bitman {
public:
    // Constructor
    Bitman();
    Bitman(int _x, int _y);
    
    // Methods
    void setup(int _x, int _y);
    void update();
    void draw();
    void sayHi();
    
    // Properties
    int x;
    int y;
    int px;
    int py;
    int step;
    int isFacingRight;
    ofColor color;
    string hi;
    ofTrueTypeFont font;
};


#endif /* defined(__many_to_one__Bitman__) */
