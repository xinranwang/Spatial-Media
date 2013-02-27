#include "testApp.h"
#include <iostream.h>

//--------------------------------------------------------------
void testApp::setup(){
    tspsReceiver.connect(12000);
    
    //ofSetRectMode(OF_RECTMODE_CENTER);
    ofEnableSmoothing();
    ofBackground(30);
    ofSetFrameRate(60);
    ofSetCircleResolution(60);
    
    centroid.x = ofGetHeight() / 2;
    x = ofGetHeight() / 2;
    y = ofGetWidth() / 2;
    xSpeed = 5;
    ySpeed = 5;
    boardWidth = 100;
    boardHeight = 10;
    ballSize = 10;
    
    boundary = 0;
}

//--------------------------------------------------------------
void testApp::update(){
    // get TSPS people
    vector<ofxTSPS::Person *> people = tspsReceiver.getPeople();
    
    if (people.size() > 0) {
        // Choosing the biggest person
        int index = 0;
        for (int i = 0; i < people.size(); i++){
            if (people[i]->boundingRect.width > people[index]->boundingRect.width) {
                index = i;
            }
        }
        centroid = people[index]->centroid;
        //centroid.x *= ofGetWidth();
        cout << centroid.x << endl;
        centroid.x = ofMap(centroid.x, 0.2, 0.8, 0, ofGetWidth());

    }

    // Update the ball's position
    x = x + xSpeed;
    y = y + ySpeed;
    
    if ((x > ofGetWidth() - boundary) || (x < boundary)) {
        xSpeed *= -1;
    }
    if (y < 0) {
        ySpeed *= -1;
    }
    if (x >= centroid.x && x <= centroid.x + boardWidth && y > ofGetHeight() - 50 - ballSize) {
        ySpeed *= -1;
    }
    
    // Get a new ball when lost
    if (y > ofGetHeight() - 30 - ballSize) {
        x = ofRandom(boundary, ofGetWidth() - boundary);
        y = ofRandom(300);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(30);
    ofSetColor(255);
    
    // Draw the boundary
    ofRect(0, 0, boundary, ofGetHeight());
    ofRect(ofGetWidth() - boundary, 0, boundary, ofGetHeight());
    
    ofRect(centroid.x, ofGetHeight() - 50, boardWidth, boardHeight);
    ofCircle(x, y, ballSize);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}