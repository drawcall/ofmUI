#include "ofAppRunner.h"
#include "ofGraphics.h"
#include "ofmBase.h"
#include "ofmMathUtil.h"

void ofmBase::_draw() {
    if (!visible) return;
}

void ofmBase::setXY(float _x, float _y) {
    x = _x;
    y = _y;
}

void ofmBase::setXY(std::string _x, std::string _y) {
    float px = ofmMathUtil::strToNum(_x);
    x = ofGetWidth() * (px / 100);

    if (_y != "") {
        float py = ofmMathUtil::strToNum(_y);
        y = ofGetHeight() * (py / 100);
    }
}

bool ofmBase::canRender() {
    if (!visible) return false;
    if (alpha < 0.01) return false;
    if (scale <= 0.01) return false;
    if (x <= -9999) return false;
    if (y <= -9999) return false;
    if (x >= 9999) return false;
    if (y >= 9999) return false;
    return true;
}

void ofmBase::pushMatrix() {
    if (!(x == 0 && y == 0)) ofTranslate(x, y);
    if (scale != 1) ofScale(scale);
    if (rotation != 0) ofRotateDeg(rotation);
}

void ofmBase::draw() {}

void ofmBase::update() {}

void ofmBase::resize() {}

void ofmBase::destroy() {}
