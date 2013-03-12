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

    
    
//    for (int i = 0; i < strings.size(); i++) {
//
//        strings[i].checkPluck(ofGetMouseX(), ofGetMouseY());
//        strings[i].update();
//        
//    }
    list<GuitarString>::iterator i;
    for (i = strings.begin(); i != strings.end(); ) {
        if (!i->checkLife()) {
            tables[i->index1].isSelected = false;
            tables[i->index2].isSelected = false;
            i = strings.erase(i);
        }
        else ++i;
    }
    
    
    //list<GuitarString>::iterator i;
    for (i = strings.begin(); i != strings.end(); i++) {

        i->checkPluck(ofGetMouseX(), ofGetMouseY());
        i->update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    
    // Draw strings
    list<GuitarString>::iterator i;
    for (i = strings.begin(); i != strings.end(); i++) {
        i->draw();
    }
//    for (int i = 0; i < strings.size(); i++) {
//        //if (strings[i].checkLife()) {
//            strings[i].draw();
////        } else {
////            tables[strings[i].index1].isSelected = false;
////            tables[strings[i].index2].isSelected = false;
////        }
//    }
    
    // Draw tables
    for (int i = 0; i < tables.size(); i++) {
        
        if ((ofGetMouseX() < tables[i].x + tableSize && ofGetMouseX() > tables[i].x - tableSize)
            && (ofGetMouseY() < tables[i].y + tableSize && ofGetMouseY() > tables[i].y - tableSize)) {
            tables[i].isHovered = true;
        } else {
            tables[i].isHovered = false;
        }
        tables[i].draw();
        
        // Draw dots
        ofSetColor(100);
        ofFill();
        if (tables[i].y < ofGetHeight() / 2) {
            ofCircle(tables[i].x, stringsEdge, 5);
        } else {
            ofCircle(tables[i].x, ofGetHeight() - stringsEdge, 5);
        }
        // Smoothing with noFill
        ofNoFill();
        if (tables[i].y < ofGetHeight() / 2) {
            ofCircle(tables[i].x, stringsEdge, 5);
        } else {
            ofCircle(tables[i].x, ofGetHeight() - stringsEdge, 5);
        }
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
            if (i < 9) {
//                if (index1 != -1) {
//                    tables[index1].isSelected = false;
//                }
                index1 = i;
            } else {
//                if (index2 != -1) {
//                    tables[index2].isSelected = false;
//                }
                index2 = i;
            }
            tables[i].isSelected = true;
            //tables[i].isSelected = !tables[i].isSelected;
                

            
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