//
//  StandingTable.h
//  FundRaiser
//
//  Created by Xinran Wang on 3/8/13.
//
//

#ifndef __FundRaiser__StandingTable__
#define __FundRaiser__StandingTable__

#include <iostream>
#include "ofMain.h"

class StandingTable {
public:
    StandingTable(int _x, int _y, int _tableSize, int _stringsEdge);
    void draw();
    
    int x;
    int y;
    int tableSize;
    bool isHovered;
    bool isSelected;
    int stringsEdge;
    ofColor color;
    ofPoint dot;
};

#endif /* defined(__FundRaiser__StandingTable__) */
