#include "ofEvents.h"
#include "ofmTouch.h"

using namespace std;

bool ofmTouch::isTouched() {
    return ofGetMousePressed();
}

void ofmTouch::update() {
    point.x = ofGetMouseX();
    point.y = ofGetMouseY();
}

void ofmTouch::setXY(float _x, float _y) {
    point.x = _x;
    point.y = _y;
}

void ofmTouch::copy(ofmTouch& touch) {
    setXY(touch.point.x, touch.point.y);
}

string ofmTouch::toString() {
    string sx = " x:" + to_string(point.x);
    string sy = " y:" + to_string(point.y);
    return sx + sy;
}
