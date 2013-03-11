#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofSetCircleResolution(60);
    ofEnableSmoothing();
    //ofSetWindowShape(roomSize * makeBigger, roomSize * makeBigger);
    
    // Initiate Tables
    for (int i = 0; i < 18; i++) {
        // Upper
        if (i < 9) {
            tables.push_back( StandingTable::StandingTable( 150 + i * tableDist / 2, margin + ( i % 2) * tableDist, tableSize) );
        }
        // Lower
        else {
            tables.push_back( StandingTable::StandingTable( 150 + (i - 9) * tableDist / 2, ofGetHeight() - margin - ( (i - 9) % 2) * tableDist, tableSize) );
        }
    }
}

//--------------------------------------------------------------
void testApp::update(){
    if (index1 != -1 && index2 != -1) {
        strings.push_back( GuitarString(index1, index2, stringsEdge, tables) );
        index1 = -1;
        index2 = -1;
    }
    for (int i = 0; i < strings.size(); i++) {
        strings[i].update();
        ofPoint p = strings[i].string.getClosestPoint(ofPoint(ofGetMouseX(), ofGetMouseY()));
        cout << "string" << i << ": " << p.x << ", " << p.y << endl;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(255);
//    StandingTable *table = new StandingTable(50, 50, tableSize);
//    table->draw();
    
    // Draw strings
    for (int i = 0; i < strings.size(); i++) {
        strings[i].draw();
    }
    
    // Draw tables
    for (int i = 0; i < tables.size(); i++) {
        
        if ((ofGetMouseX() < tables[i].x + tableSize && ofGetMouseX() > tables[i].x - tableSize)
            && (ofGetMouseY() < tables[i].y + tableSize && ofGetMouseY() > tables[i].y - tableSize)) {
            tables[i].isHovered = true;
        } else {
            tables[i].isHovered = false;
        }
        tables[i].draw();
    }
    
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
    for (int i = 0; i < tables.size(); i++) {
        if ((ofGetMouseX() < tables[i].x + tableSize && ofGetMouseX() > tables[i].x - tableSize)
            && (ofGetMouseY() < tables[i].y + tableSize && ofGetMouseY() > tables[i].y - tableSize)) {
            tables[i].isSelected = true;
            if (i < 9) {
                index1 = i;
            } else {
                index2 = i;
            }
        }
    }

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