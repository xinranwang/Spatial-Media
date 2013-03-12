#pragma once

#include "ofMain.h"
#include "StandingTable.h"
#include "GuitarString.h"
#include "Bob.h"
#include "Spring.h"
#include <iostream>

static const int tableSize = 48;
static const int roomSize = 360;
static const int makeBigger = 2;
static const int tableDist = 100;
static const int margin = 100;
static const int stringsEdge = 250;

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    vector<StandingTable> tables;
    vector<GuitarString> strings;
    
    int index1 = -1;
    int index2 = -1;
    
    Bob bob;
    Spring spring;
};
