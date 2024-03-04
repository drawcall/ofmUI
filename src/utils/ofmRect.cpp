#include "ofmRect.h"

using namespace std;

void ofmRect::set(float l, float r, float t, float b) {
    left = l;
    right = r;
    top = t;
    bottom = b;
}

void ofmRect::setXYWH(float x, float y, float w, float h) {
    left = x;
    right = left + w;
    top = y;
    bottom = top + h;
}

void ofmRect::setCenterWH(float x, float y, float w, float h) {
    left = x - w * 0.5;
    right = left + w;
    top = y - h * 0.5;
    bottom = top + h;
}

float ofmRect::getWidth() {
    return right - left;
}

bool ofmRect::inside(float x, float y) {
    if (x >= left && x <= right && y >= top && y <= bottom) {
        return true;
    } else {
        return false;
    }
}

string ofmRect::toString() {
    string l = " left:" + to_string(left);
    string r = " right:" + to_string(right);
    string t = " top:" + to_string(top);
    string b = " bottom:" + to_string(bottom);
    string w = " width:" + to_string(right - left);
    string h = " height:" + to_string(bottom - top);
    return l + r + t + b + w + h;
}
