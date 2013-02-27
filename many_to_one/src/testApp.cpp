#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    tspsReceiver.connect(12000);
    
}

//--------------------------------------------------------------
void testApp::update(){
    // get TSPS people
    vector<ofxTSPS::Person *> people = tspsReceiver.getPeople();
    
    for (int i = 0; i < people.size(); i++) {
        ofPoint centroid = people[i]->centroid;
        centroid.x *= ofGetWidth();
        centroid.y *= ofGetHeight();
        
        if (bitmen.count(people[i]->pid) == 0) {
            bitmen[people[i]->pid] = Bitman(centroid.x, centroid.y);
        } else {
            bitmen[people[i]->pid].setup(centroid.x, centroid.y);
        }
        
        bitmen[people[i]->pid].update();
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(30);
    vector<ofxTSPS::Person *> people = tspsReceiver.getPeople();
    for (int i = 0; i < people.size(); i++) {
        bitmen[people[i]->pid].draw();
    }
    bitmenMeet();
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

void testApp::bitmenMeet() {
    vector<ofxTSPS::Person *> people = tspsReceiver.getPeople();
    for (int i = 0; i < people.size(); i++) {
        for (int j = 0; j < people.size(); j++) {
            if (bitmen[people[i]->pid].x - bitmen[people[j]->pid].x < 13 * pixelSize
                && bitmen[people[i]->pid].x - bitmen[people[j]->pid].x > -13 * pixelSize
                && bitmen[people[i]->pid].y == bitmen[people[j]->pid].y
                && i != j) {
                bitmen[people[i]->pid].sayHi();
                bitmen[people[j]->pid].sayHi();
            }
        }
    }
}