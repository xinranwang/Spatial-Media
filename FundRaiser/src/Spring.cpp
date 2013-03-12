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

Spring::Spring(float x, float y, int l, float _minlen, float _maxlen, Bob _b) {
    anchor.set(x, y);
    len = l;
    minlen = _minlen;
    maxlen = _maxlen;
    b = _b;
}

//void Spring::connect(Bob b) {
//    ofVec2f force = b.location - anchor;
//    float d = force.length();
//    float stretch = d - len;
//    
//    force.normalize();
//    force *= -1 * k * stretch;
//    b.applyForce(force);
//}
//
//void Spring::constrainLength(Bob b, float minlen, float maxlen) {
//    ofVec2f dir = b.location - anchor;
//    float d = dir.length();
//    //cout << d << endl;
//    if (d < minlen) {
//        dir.normalize();
//        dir *= minlen;
//        b.location = anchor + dir;
//        b.velocity *= 0;
//        //cout << "too short" << endl;
//    }
//    else if (d > maxlen) {
//        dir.normalize();
//        dir *= maxlen;
//        cout << dir << endl;
//        cout << anchor.x << ":" << anchor.y << endl;
//        //b.location = anchor + dir;
//        b.location.set(anchor + dir);
//        cout << b.location.x << ":" << b.location.y << endl;
//        b.velocity *= 0;
//        //cout << "too long" << endl;
//    }
//}

void Spring::update(float mx, float my) {
    ofVec2f force = b.location - anchor;
    float fl = force.length();
    float stretch = fl - len;
    
    force.normalize();
    force *= -1 * k * stretch;
    b.applyForce(force);
    
    ofVec2f dir = b.location - anchor;
    float d = dir.length();
    //cout << d << endl;
    if (d < minlen) {
        dir.normalize();
        dir *= minlen;
        b.location = anchor + dir;
        b.velocity *= 0;
        //cout << "too short" << endl;
    }
    else if (d > maxlen) {
        dir.normalize();
        dir *= maxlen;
        b.location = anchor + dir;
        b.velocity *= 0;
        //cout << "too long" << endl;
    }
    b.update();
    b.drag(mx, my);
}

void Spring::display() {
    ofSetColor(175);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofRect(anchor.x, anchor.y, 10, 10);
}
