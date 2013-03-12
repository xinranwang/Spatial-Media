#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofSetCircleResolution(60);
    ofEnableSmoothing();
    //ofSetWindowShape(roomSize * makeBigger, roomSize * makeBigger);
    
    canvas.allocate(ofGetWidth(), ofGetHeight() - 2 * stringsEdge);
    canvas.begin();
    ofClear(0);
    canvas.end();
    mapper.initialize(ofGetWidth(), ofGetHeight() - 2 * stringsEdge);
    mapper.load("mapsettings.txt");
    bDrawBounds = false;
    
    // Initiate Tables
    for (int i = 0; i < 18; i++) {
        // Upper
        if (i < 9) {
            tables.push_back( StandingTable::StandingTable( 150 + i * tableDist / 2, margin + ( i % 2) * tableDist, tableSize, stringsEdge) );
        }
        // Lower
        else {
            tables.push_back( StandingTable::StandingTable( 150 + (i - 9) * tableDist / 2, ofGetHeight() - margin - ( (i - 9) % 2) * tableDist, tableSize, stringsEdge) );
        }
    }
    projectionMode = false;
}

//--------------------------------------------------------------
void testApp::update(){
    if (index1 != -1 && index2 != -1) {
        strings.push_back( GuitarString(index1, index2, stringsEdge, tables) );
        index1 = -1;
        index2 = -1;
    }

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
    
    mapper.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    if (projectionMode) {
        canvas.begin();
        ofTranslate(0, -stringsEdge);
    }
    
    
    ofBackground(0);
    
    // Draw strings
    list<GuitarString>::iterator i;
    for (i = strings.begin(); i != strings.end(); i++) {
        i->draw();
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
    
    if (projectionMode) {
        canvas.end();
        //ofTranslate(0, stringsEdge);
        mapper.startMapping();
        canvas.draw(0,0);
        mapper.stopMapping();
    }
    
    if ( bDrawBounds ){
        mapper.drawBoundingBox();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == 'p') {
        projectionMode = !projectionMode;
    } else if ( key == 's' ){
        // save to a file
        mapper.save("mapsettings.txt");
    } else if ( key == 'd' ){
        bDrawBounds = !bDrawBounds;
    } else if ( key == 'f' ) {
        ofToggleFullscreen();
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    mapper.mouseDragged(x, y);
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
    
    mapper.mousePressed(x, y);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    mapper.mouseReleased(x, y);
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