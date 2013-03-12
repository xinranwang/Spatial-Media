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
#include "Bob.h"
#include "Spring.h"

class GuitarString {
public:
    GuitarString(int _index1, int _index2, int _stringsEdge, vector<StandingTable> _tables);
    void update();
    void checkPluck(float _x, float _y);
    void draw();
    void makeString();
    
    int index1;
    int index2;
    ofColor color;
    int stringsEdge;
    ofPolyline string;
    ofMesh mesh;
    ofPoint controlPoint;
    vector<StandingTable> tables;
    
    Bob bob;
    Spring spring;
    ofVec2f gravity;
    float pluckDist = 20;
};

#endif /* defined(__FundRaiser__GuitarString__) */
