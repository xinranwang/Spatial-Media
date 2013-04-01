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
    gravity = stringVec.getPerpendicular();
    
    //controlPoint.set(tables[index2].x, ofGetHeight() - stringsEdge);
    Bob bob(tables[index2].dot.x, tables[index2].dot.y);
    spring = Spring(tables[index2].dot.x, tables[index2].dot.y, 0, 0, pluckDist, bob);
    
    makeString();
    
    hiddenString.addVertex(tables[index1].dot);
    hiddenString.addVertex(tables[index2].dot);
    
    mesh.setupIndicesAuto();
    mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
}

GuitarString::~GuitarString() {
    
}

void GuitarString::checkPluck(float _x, float _y) {
    
    spring.b.applyForce(gravity);
    spring.update(_x, _y);
    
    ofPoint closestPoint = hiddenString.getClosestPoint(ofPoint(_x, _y));
    if (ofDist(_x, _y, closestPoint.x, closestPoint.y) < 5) {
        prePluck = true;
    }
    
    if (ofDist(_x, _y, closestPoint.x, closestPoint.y) < pluckDist && prePluck) {
        spring.b.location.set(_x, _y);
        spring.anchor.set(closestPoint);
        spring.b.clicked(_x, _y);
        
        //age++;
    } else {
        spring.b.stopDragging();
        if (prePluck) {
            age++;
            prePluck = false;
        }
        
    }


}

bool GuitarString::checkLife() {
    if (age < lifetime) {
        return true;
    }
    return false;
}

void GuitarString::update(bool isProjectionMode) {
    string.clear();
    makeString();
    mesh.clear();
    ofFloatColor start;
    ofFloatColor end;
    
    if (isProjectionMode) {
        lifetime = 10000; // bump up lifetime so the string stays up for testing while projected
        start = ofColor(0, 255, 100);
        end = ofColor(0, 100, 255);
    } else {
        if (lifetime > 10) {
            lifetime = ofRandom(5, 10); // in the case where it had previously been projected
        }
        start = tables[index1].color;
        end = tables[index2].color;
    }
    
    // if string is not curved, color mapping is different
    if (prePluck) {
        for (int i = 0; i < string.size(); i++) {
            mesh.addVertex(string[i]);
            ofPoint closestPoint = hiddenString.getClosestPoint(string[i]);
            mesh.addColor(start.lerp(end, (float) (closestPoint.y - tables[index1].y) / (tables[index2].y - tables[index1].y) ));
        }
    } else {
        for (int i = 0; i < string.size(); i++) {
            mesh.addVertex(string[i]);
            mesh.addColor( start.lerp(end, (float) i / string.size()) );
        }
    }
}

void GuitarString::makeString() {
    string.addVertex(tables[index1].x, stringsEdge);
    if (prePluck) {
        string.addVertex(spring.b.location);
        string.addVertex(tables[index2].dot);
    } else {
        string.bezierTo(spring.b.location, tables[index2].dot, tables[index2].dot);
    }
}

void GuitarString::draw(bool isProjectionMode) {
    if (isProjectionMode) {
        update(isProjectionMode); // make strings specific colors for projection
    }
    ofNoFill();
    if (isProjectionMode) {
        ofSetLineWidth(3); // option to have different string width for projection
    } else {
        ofSetLineWidth(3);
        // draw table lines only when not in projection mode
        ofSetColor(tables[index1].color);
        ofLine(tables[index1].x, tables[index1].y, tables[index1].dot.x, tables[index1].dot.y);
        ofSetColor(tables[index2].color);
        ofLine(tables[index2].dot.x, tables[index2].dot.y, tables[index2].x, tables[index2].y);
    }

    mesh.draw();
//    spring.b.display();
//    spring.display();
}