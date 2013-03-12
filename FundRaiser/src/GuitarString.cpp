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
    tables = _tables;
    ofVec2f stringVec(tables[index2].x - tables[index1].x, ofGetHeight() - stringsEdge * 2);
    gravity = stringVec.getPerpendicular() * 2;
    cout << gravity.x << ":" << gravity.y << endl;
    
    //controlPoint.set(tables[index2].x, ofGetHeight() - stringsEdge);
    bob = Bob(tables[index2].x, ofGetHeight() - stringsEdge);
    spring = Spring(tables[index2].x, ofGetHeight() - stringsEdge, 0);
    
    makeString();
    mesh.setupIndicesAuto();
    mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
}

void GuitarString::checkPluck(float _x, float _y) {
    bob.applyForce(gravity);
    spring.connect(bob);
    spring.constrainLength(bob, 0, 200);
    bob.update();
    bob.drag(_x, _y);
    
    ofPoint closestPoint = string.getClosestPoint(ofPoint(_x, _y));
    if (ofDist(_x, _y, closestPoint.x, closestPoint.y) < pluckDist) {
        bob.location.set(_x, _y);
        spring.anchor.set(closestPoint);
        bob.clicked(_x, _y);
        
        //controlPoint.set(_x, _y);
    } else {
        //controlPoint.set(tables[index2].x, ofGetHeight() - stringsEdge);
//        bob.location.set(tables[index2].x, ofGetHeight() - stringsEdge);
//        spring.anchor.set(tables[index2].x, ofGetHeight() - stringsEdge);
        bob.stopDragging();
    }


}

void GuitarString::update() {
    string.clear();
    makeString();
    mesh.clear();
    
    ofFloatColor start = tables[index1].color;
    ofFloatColor end = tables[index2].color;
    
    for (int i = 0; i < string.size(); i++) {
        mesh.addVertex(string[i]);
        mesh.addColor( start.lerp(end, (float) i / string.size()) );
    }
}

void GuitarString::makeString() {
    string.addVertex(tables[index1].x, stringsEdge);
    //string.bezierTo(controlPoint, ofPoint(tables[index2].x, ofGetHeight() - stringsEdge), ofPoint(tables[index2].x, ofGetHeight() - stringsEdge));
    string.bezierTo(bob.location, ofPoint(tables[index2].x, ofGetHeight() - stringsEdge), ofPoint(tables[index2].x, ofGetHeight() - stringsEdge));
    
}

void GuitarString::draw() {
    
    ofNoFill();
    ofSetLineWidth(3);
    ofSetColor(tables[index1].color);
    ofLine(tables[index1].x, tables[index1].y, tables[index1].x, stringsEdge);
    ofSetColor(tables[index2].color);
    ofLine(tables[index2].x, ofGetHeight() - stringsEdge, tables[index2].x, tables[index2].y);

    //string.draw();
    mesh.draw();
    bob.display();
    spring.display();
}