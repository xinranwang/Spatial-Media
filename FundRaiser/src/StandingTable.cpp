//
//  StandingTable.cpp
//  FundRaiser
//
//  Created by Xinran Wang on 3/8/13.
//
//

#include "StandingTable.h"

StandingTable::StandingTable(int _x, int _y, int _tableSize) {
    x = _x;
    y = _y;
    isHovered = false;
    isSelected = false;
    tableSize = _tableSize;
    color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}

void StandingTable::draw() {

    
    if (isSelected || isHovered) {
        ofSetColor(color);
    } else
        ofSetColor(200);
    
    ofFill();
    ofCircle(x, y, tableSize / 2);
}