#pragma once

#include "ofMain.h"
#include "ofxSimpleProjectionMapper.h"
#include "StandingTable.h"
#include "GuitarString.h"
#include "Bob.h"
#include "Spring.h"
#include <iostream>
#include "ofxTSPSReceiver.h"

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
    
        void audioOut(float * input, int bufferSize, int nChannels);
    
    vector<StandingTable> tables;
    //vector<GuitarString> strings;
    list<GuitarString> strings;
    
    int index1 = -1;
    int index2 = -1;
    
    Bob bob;
    Spring spring;
    
    ofxSimpleProjectionMapper mapper;
    bool bDrawBounds;
    bool projectionMode;
    
    
    float maxLength;
    float minLength;
    
    ofSoundStream soundStream;
    
    float 	pan;
    int		sampleRate;
    float 	volumeMax;
    
    vector <float> lAudio;
    vector <float> rAudio;
    
    //------------------- for the simple sine wave synthesis
    float 	targetFrequency;
    float 	phase;
    float 	phaseAdder;
    float 	phaseAdderTarget;
    
    // create TSPS Receiver object
    ofxTSPS::Receiver tspsReceiver;
};
