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