//
//  Spring.h
//  FundRaiser
//
//  Created by Xinran Wang on 3/11/13.
//
//

#ifndef __FundRaiser__Spring__
#define __FundRaiser__Spring__

#include <iostream>
#include "ofMain.h"
#include "Bob.h"

class Spring {
public:
    Spring();
    Spring(float x, float y, int l);
    void connect(Bob b);
    void constrainLength(Bob b, float minlen, float maxlen);
    void display();
    void displayLine(Bob b);
    
    ofVec2f anchor;
    float len;
    float k = 0.2;

};
#endif /* defined(__FundRaiser__Spring__) */
