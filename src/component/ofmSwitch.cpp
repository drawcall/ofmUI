#include "ofmMathUtil.h"
#include "ofmSwitch.h"
#include "ofmTheme.h"

ofmSwitch::ofmSwitch() {
    _initTheme();
    enabledTouch = true;
    value = 1;
    key = "switch";
}

void ofmSwitch::_initTheme() {
    ofmForm::initTheme();
    ofmTheme* theme = ofmTheme::instance();
    width = theme->switchWidth;
    height = theme->switchHeight;
    radius = theme->switchRadius;
    round = theme->round;
    backColor = ofColor::fromHex(theme->backColor);
    frontColor = ofColor::fromHex(theme->frontColor);
    barColor = ofColor::fromHex(theme->barColor);
}

void ofmSwitch::draw() {
    ofPushStyle();
    if (value == 1) {
        ofSetColor(frontColor);
    } else {
        ofSetColor(backColor);
    }

    float top = -height / 2;
    float left = -width / 2;
    float right = left + width;
    if (cap == "circle") {
        ofDrawRectRounded(left, top, width, height, height / 2);
    } else {
        ofDrawRectangle(left, top, width, height);
    }

    ofSetColor(barColor);
    float r = radius == 0 ? (height + 8) / 2 : radius;
    float cx1 = left;
    float cx2 = right;
    float cy = 0;
    float cx = value == 1 ? cx2 : cx1;

    if (barType == "circle") {
        ofDrawCircle(cx, cy, r);
    } else {
        ofDrawRectangle(cx - r, cy - r, r * 2, r * 2);
    }

    ofmForm::draw();
    ofPopStyle();
}

void ofmSwitch::onTouchDown(ofmTouch& touch) {
    ofmComp::onTouchDown(touch);
    value = value == 1 ? 0 : 1;
    ofNotifyEvent(valueChange, value, this);
}

void ofmSwitch::destroy() {}
