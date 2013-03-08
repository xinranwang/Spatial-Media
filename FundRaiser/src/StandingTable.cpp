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
}

void StandingTable::draw() {
    if (isSelected || isHovered) {
        ofSetColor(100);
    } else
        ofSetColor(200);
    ofCircle(x, y, tableSize / 2);
}