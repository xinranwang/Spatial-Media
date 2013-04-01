//
//  StandingTable.cpp
//  FundRaiser
//
//  Created by Xinran Wang on 3/8/13.
//
//

#include "StandingTable.h"

StandingTable::StandingTable(int _x, int _y, int _tableSize, int _stringsEdge) {
    x = _x;
    y = _y;
    isHovered = false;
    isSelected = false;
    tableSize = _tableSize;
    stringsEdge = _stringsEdge;
    color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    if (y < ofGetHeight() / 2) {
        dot.set(x, stringsEdge);
    } else {
        dot.set(x, ofGetHeight() - stringsEdge);
    }
}

void StandingTable::draw() {

    
    if (isSelected || isHovered) {
        ofSetColor(color);
    } else {
        ofSetColor(200);
    }
    
    ofSetLineWidth(1);
    ofFill();
    ofCircle(x, y, tableSize / 2);
    // Smoothing with noFill
    ofNoFill();
    ofCircle(x, y, tableSize / 2);
    
    // Draw dots
    ofSetColor(100);
    ofFill();
    ofCircle(dot, 5);
    // Smoothing with noFill
    ofNoFill();
    ofCircle(dot, 5);
}