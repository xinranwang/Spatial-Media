//
//  GuitarString.h
//  FundRaiser
//
//  Created by Xinran Wang on 3/8/13.
//
//

#ifndef __FundRaiser__GuitarString__
#define __FundRaiser__GuitarString__

#include <iostream>
#include "ofMain.h"
#include "StandingTable.h"
//#include "testApp.h"

class GuitarString {
public:
    GuitarString(int _index1, int _index2, int _stringsEdge);
    void draw(vector<StandingTable> tables);
    
    int index1;
    int index2;
    ofColor color;
    int stringsEdge;
};

#endif /* defined(__FundRaiser__GuitarString__) */
