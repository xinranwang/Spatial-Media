//
//  GuitarString.cpp
//  FundRaiser
//
//  Created by Xinran Wang on 3/8/13.
//
//

#include "GuitarString.h"

GuitarString::GuitarString(int _index1, int _index2, int _stringsEdge) {
    index1 = _index1;
    index2 = _index2;
    stringsEdge = _stringsEdge;
    color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}

void GuitarString::draw(vector<StandingTable> tables) {
    ofSetColor(color);
    ofLine(tables[index1].x, tables[index1].y, tables[index1].x, stringsEdge);
    ofLine(tables[index1].x, stringsEdge, tables[index2].x, ofGetHeight() - stringsEdge);
    ofLine(tables[index2].x, ofGetHeight() - stringsEdge, tables[index2].x, tables[index2].y);
}