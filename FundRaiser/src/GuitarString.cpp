//
//  GuitarString.cpp
//  FundRaiser
//
//  Created by Xinran Wang on 3/8/13.
//
//

#include "GuitarString.h"

GuitarString::GuitarString(int _index1, int _index2, int _stringsEdge, vector<StandingTable> _tables) {
    
    index1 = _index1;
    index2 = _index2;
    stringsEdge = _stringsEdge;
    color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    tables = _tables;
    
    controlPoint.set(tables[index2].x, ofGetHeight() - stringsEdge);
    bob = Bob(controlPoint.x, controlPoint.y);
    spring = Spring(controlPoint.x, controlPoint.y, 0);
    
    makeString();
    //mesh.addVertices(string.getVertices());
}

void GuitarString::update() {
    //controlPoint.x -= 10;
    string.clear();
    makeString();
//    mesh.clear();
//    mesh.addVertices(string.getVertices());
}

void GuitarString::makeString() {
//    string.addVertex(tables[index1].x, tables[index1].y);
    string.addVertex(tables[index1].x, stringsEdge);
    string.bezierTo(controlPoint, ofPoint(tables[index2].x, ofGetHeight() - stringsEdge), ofPoint(tables[index2].x, ofGetHeight() - stringsEdge));
//    string.addVertex(tables[index2].x, tables[index2].y);
    
}

void GuitarString::draw() {
    
    ofNoFill();
    ofSetColor(tables[index1].color);
    ofLine(tables[index1].x, tables[index1].y, tables[index1].x, stringsEdge);
    ofSetColor(tables[index2].color);
    ofLine(tables[index2].x, ofGetHeight() - stringsEdge, tables[index2].x, tables[index2].y);
    ofSetColor(color);
    string.draw();
    
//    ofBeginShape();
//    ofVertex(tables[index1].x, tables[index1].y);
//    ofVertex(tables[index1].x, stringsEdge);
//    ofBezierVertex(controlPoint.x, controlPoint.y, tables[index2].x, ofGetHeight() - stringsEdge, tables[index2].x, ofGetHeight() - stringsEdge);
//    //ofVertex(tables[index2].x, ofGetHeight() - stringsEdge);
//    ofVertex(tables[index2].x, tables[index2].y);
//    ofEndShape();
}