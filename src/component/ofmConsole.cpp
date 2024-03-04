#include <iostream>

#include "ofAppRunner.h"
#include "ofGraphics.h"
#include "ofmConsole.h"

using namespace std;

ofmConsole::ofmConsole() {
    x = 20;
    y = 120;
    scale = 2;
    alpha = 0.75;
    height = 50;
    lineHeight = 12 * scale;
    color = ofColor::fromHex(0xffffff);
    textColor = ofColor::fromHex(0x000000);
}

void ofmConsole::logs(const string& str) {
    _str = str;
}

void ofmConsole::_draw() {
    if (!visible) return;
    
    ofPushMatrix();
    ofPushStyle();
    ofEnableAlphaBlending();
    
    // bg
    color.a = 255 * alpha;
    ofSetColor(color);
    ofDrawRectangle(0.0, y, ofGetWidth(), height);
    // text
    lineHeight = (12 * scale) / 2 + height / 2;
    ofTranslate(x, y + lineHeight);
    ofScale(scale);
    ofSetColor(textColor);
    ofDrawBitmapString(_str, 0, 0);
    
    ofDisableAlphaBlending();
    ofPopStyle();
    ofPopMatrix();
}

// ------------------------------------------------------------------
// static public methods
// ------------------------------------------------------------------
ofmConsole* ofmConsole::_instance = NULL;

ofmConsole* ofmConsole::instance() {
    if (_instance == NULL) {
        _instance = new ofmConsole();
    }
    return _instance;
}

void ofmConsole::log(const string& str) {
    if (instance()->parent != NULL) {
        instance()->visible = true;
        instance()->logs(str);
    }
}

void ofmConsole::log(const float& n) {
    log(to_string(n));
}

void ofmConsole::logFPS() {
    log(to_string(ofGetFrameRate()));
}

void ofmConsole::hide() {
    instance()->visible = false;
}

void ofmConsole::setY(float _y) {
    instance()->y = _y;
}
