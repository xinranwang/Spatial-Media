//
//  Bob.cpp
//  FundRaiser
//
//  Created by Xinran Wang on 3/11/13.
//
//

#include "Bob.h"

Bob::Bob() {
    
}

Bob::Bob(float x, float y) {
    location.set(x, y);
}

void Bob::update() {
    velocity += acceleration;
    velocity *= damping;
    location += velocity;
    acceleration *= 0;
}

void Bob::applyForce(ofVec2f force) {
    ofVec2f f = force;
    f /= mass;
    acceleration += f;
}

void Bob::display() {
    ofSetColor(175);
    if (dragging) {
        ofSetColor(50);
    }
    ofCircle(location.x, location.y, mass);
}

void Bob::clicked(int mx, int my) {
    float d = ofDist(mx, my, location.x, location.y);
    if (d < mass) {
        dragging = true;
        dragOffset.x = location.x - mx;
        dragOffset.y = location.y - my;
    }
}

void Bob::stopDragging() {
    dragging = false;
}

void Bob::drag(int mx, int my) {
    if (dragging) {
        location.x = mx + dragOffset.x;
        location.y = my + dragOffset.y;
    }
    
}