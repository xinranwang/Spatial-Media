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
    ofVec2f stringVec;
    stringVec.set(tables[index2].x - tables[index1].x, tables[index2].y - tables[index1].x);
    gravity = stringVec.getPerpendicular();
    
    controlPoint.set(tables[index2].x, ofGetHeight() - stringsEdge);
    bob = Bob(controlPoint.x, controlPoint.y);
    spring = Spring(controlPoint.x, controlPoint.y, 0);
    
    bob.applyForce(gravity);
    spring.connect(bob);
    spring.constrainLength(bob, 30, 100);
    
    makeString();
    mesh.setupIndicesAuto();
    mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
}

void GuitarString::checkPluck(float _x, float _y) {
    ofPoint closestPoint = string.getClosestPoint(ofPoint(_x, _y));
    if (ofDist(_x, _y, closestPoint.x, closestPoint.y) < pluckDist) {
        controlPoint.set(_x, _y);
    } else {
        controlPoint.set(tables[index2].x, ofGetHeight() - stringsEdge);
    }
}

void GuitarString::update() {
    //controlPoint.x -= 10;
    string.clear();
    makeString();
    mesh.clear();
    
    ofFloatColor start = tables[index1].color;
    ofFloatColor end = tables[index2].color;
    
    for (int i = 0; i < string.size(); i++) {
        mesh.addVertex(string[i]);
        mesh.addColor( start.lerp(end, (float) i / string.size()) );
    }
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
    ofSetLineWidth(3);
    ofSetColor(tables[index1].color);
    ofLine(tables[index1].x, tables[index1].y, tables[index1].x, stringsEdge);
    ofSetColor(tables[index2].color);
    ofLine(tables[index2].x, ofGetHeight() - stringsEdge, tables[index2].x, tables[index2].y);
    ofSetColor(color);
    //string.draw();
    mesh.draw();
    
//    ofBeginShape();
//    ofVertex(tables[index1].x, tables[index1].y);
//    ofVertex(tables[index1].x, stringsEdge);
//    ofBezierVertex(controlPoint.x, controlPoint.y, tables[index2].x, ofGetHeight() - stringsEdge, tables[index2].x, ofGetHeight() - stringsEdge);
//    //ofVertex(tables[index2].x, ofGetHeight() - stringsEdge);
//    ofVertex(tables[index2].x, tables[index2].y);
//    ofEndShape();
}