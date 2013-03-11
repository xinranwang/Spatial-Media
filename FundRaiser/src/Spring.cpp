//
//  Spring.cpp
//  FundRaiser
//
//  Created by Xinran Wang on 3/11/13.
//
//

#include "Spring.h"

Spring::Spring() {
    
}

Spring::Spring(float x, float y, int l) {
    anchor.set(x, y);
    len = l;
}

void Spring::connect(Bob b) {
    ofVec2f force = b.location - anchor;
    float d = force.length();
    float stretch = d - len;
    
    force.normalize();
    force *= -1 * k * stretch;
    b.applyForce(force);
}

void Spring::constrainLength(Bob b, float minlen, float maxlen) {
    ofVec2f dir = b.location - anchor;
    float d = dir.length();
    
    if (d < minlen) {
        dir.normalize();
        dir *= minlen;
        b.location = anchor + dir;
        b.velocity *= 0;
    }
    else if (d > maxlen) {
        dir.normalize();
        dir *= maxlen;
        b.location = anchor + dir;
        b.velocity *= 0;
    }
}

void Spring::display() {
    
}

void Spring::displayLine(Bob b) {
    
}