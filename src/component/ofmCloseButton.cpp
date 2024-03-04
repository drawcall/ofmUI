#include "ofmCloseButton.h"
#include "ofmTheme.h"

ofmCloseButton::ofmCloseButton() : ofmButton() {
    isCircle = true;
    _initTheme();
}

void ofmCloseButton::_initTheme() {
    ofmTheme* theme = ofmTheme::instance();
    width = theme->circleButtonRadius * 2;
    frontColor = ofColor::fromHex(0xffffff);
    frontColor.a = 255 * 0.85;
}

void ofmCloseButton::draw() {
    ofPushStyle();
    color.a = 255 * alpha;
    ofSetColor(color);

    float x = -width / 2;
    float y = -width / 2;
    float r = width / 2;

    if (isCircle) {
        ofDrawCircle(0, 0, r);
    } else {
        ofDrawRectangle(x, y, r * 2, r * 2);
    }

    ofPushMatrix();
    ofRotateZDeg(45);
    float d = 10;
    float h = 4;
    ofSetColor(frontColor);
    ofDrawRectangle(x + d, -h / 2, (r - d) * 2, h);
    ofDrawRectangle(-h / 2, y + d, h, (r - d) * 2);
    ofPopMatrix();

    ofPopStyle();
}
