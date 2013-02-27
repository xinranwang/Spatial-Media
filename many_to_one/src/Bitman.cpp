//
//  Bitman.cpp
//  many_to_one
//
//  Created by Xinran Wang on 2/26/13.
//
//

#include "Bitman.h"

Bitman::Bitman() {
    step = 0;
    isFacingRight = 0;
    px = 0;
    py = 0;
    hi = "Hello";
    font.loadFont("DINPro-Medium.otf", 30);
    color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}

Bitman::Bitman(int _x, int _y) {
    x = _x;
    y = _y;
    step = 0;
    isFacingRight = 0;
    px = 0;
    py = 0;
    hi = "Hello";
    font.loadFont("DINPro-Medium.otf", 30);
    color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}

void Bitman::setup(int _x, int _y) {
    px = x;
    py = y;
    x = _x;
    y = _y;
}

void Bitman::update() {
    for (int i = 0; i < ofGetWidth(); i += pixelSize) {
        if (x > i && x < i + pixelSize) {
            x = i;
        }
    }
    
    for (int i = 0; i < ofGetHeight(); i += pixelSize) {
        if (y > i && y < i + pixelSize) {
            y = i;
        }
    }
    
    if (px != x) {
        step = 1 - step;
    }
    
    if ((px < x && isFacingRight == 0) || (px > x && isFacingRight == 1)) {
        isFacingRight = 1 - isFacingRight;
    }
    
    y = ofGetHeight() / 2;
}

void Bitman::draw() {
    //helmet
    //white
    ofSetColor(255); // white
    ofRect (x + (2 + isFacingRight) * pixelSize, y + 2 * pixelSize, 9 * pixelSize, 10 * pixelSize);
    ofRect (x + (1 + isFacingRight) * pixelSize, y + 3 * pixelSize, pixelSize, 8 * pixelSize);
    ofRect (x + isFacingRight * pixelSize, y + 4 * pixelSize, pixelSize, 6 * pixelSize);
    ofRect (x + (11 + isFacingRight) * pixelSize, y + 4 * pixelSize, pixelSize, 7 * pixelSize);
    
    //black
    ofSetColor(0);
    ofRect (x + (2 + isFacingRight) * pixelSize, y + 4 * pixelSize, 8 * pixelSize, 7 * pixelSize);
    ofRect (x + (1 + isFacingRight) * pixelSize, y + 5 * pixelSize, 10 * pixelSize, 5 * pixelSize);
    
    //helmet shadows
    ofSetColor(210); // grey
    ofRect (x + isFacingRight * pixelSize, y + 10 * pixelSize, pixelSize, pixelSize);
    ofRect (x + (1 + isFacingRight) * pixelSize, y + 11 * pixelSize, pixelSize, pixelSize);
    ofRect (x + (11 + isFacingRight) * pixelSize, y + 3 * pixelSize, pixelSize, pixelSize);
    ofRect (x + (11 + isFacingRight) * pixelSize, y + 11 * pixelSize, pixelSize, pixelSize);
    ofRect (x + (12 + isFacingRight) * pixelSize, y + 4 * pixelSize, pixelSize, 7 * pixelSize);
    //reflection
    ofRect (x + (3 + isFacingRight * 3) * pixelSize, y + 5 * pixelSize, 4 * pixelSize, pixelSize);
    ofRect (x + (2 + isFacingRight * 8) * pixelSize, y + 6 * pixelSize, pixelSize, pixelSize);
    
    //neck
    ofSetColor(31, 9, 0);
    ofRect (x + 4 * pixelSize, y + 12 * pixelSize, 6 * pixelSize, pixelSize);
    
    //body
    //ofSetColor(255, 76, 5); //orange
    ofSetColor(color);
    ofRect (x + 4 * pixelSize, y + 13 * pixelSize, 6 * pixelSize, 4 * pixelSize);
    
    //arms
    ofSetColor(178, 50, 0);//dark orange
    ofRect (x + 3 * pixelSize, y + 13 * pixelSize, pixelSize, pixelSize);
    ofRect (x + 10 * pixelSize, y + 13 * pixelSize, pixelSize, pixelSize);
    //pants
    ofRect (x + 4 * pixelSize, y + 17 * pixelSize, 6 * pixelSize, pixelSize);
    
    //wrists
    ofSetColor(0);//black
    ofRect (x + 3 * pixelSize, y + 14 * pixelSize, pixelSize, pixelSize);
    ofRect (x + 10 * pixelSize, y + 14 * pixelSize, pixelSize, pixelSize);
    
    //hands
    ofSetColor(255, 213, 170);//skin color
    ofRect (x + 3 * pixelSize, y + 15 * pixelSize, pixelSize, pixelSize);
    ofRect (x + 10 * pixelSize, y + 15 * pixelSize, pixelSize, pixelSize);
    
    //feet
    ofSetColor(70);
    if (step == 0) {
        ofRect (x + 4 * pixelSize, y + 18 * pixelSize, 2 * pixelSize, pixelSize);
        ofRect (x + 8 * pixelSize, y + 18 * pixelSize, 2 * pixelSize, pixelSize);
    }
    else {
        ofRect (x + 5 * pixelSize, y + 18 * pixelSize, 2 * pixelSize, pixelSize);
        ofRect (x + 7 * pixelSize, y + 18 * pixelSize, 2 * pixelSize, pixelSize);
    }
    
    //tie
    ofSetColor(255);//white
    ofRect (x + 6 * pixelSize, y + 13 * pixelSize, pixelSize, 3 * pixelSize);
    
    //badge
    ofSetColor(51, 1, 106);
    ofRect (x + 8 * pixelSize, y + 14 * pixelSize, pixelSize, pixelSize);
}

void Bitman::sayHi() {
    ofSetColor(color);
    font.drawString(hi, x + pixelSize, y - 2 * pixelSize);
}