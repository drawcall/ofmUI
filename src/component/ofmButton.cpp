#include "ofmButton.h"
#include "ofmFont.h"
#include <iostream>
#include "ofmCon.h"

using namespace std;

ofmButton::ofmButton() {
    enabledTouch = true;
    _initTheme();
}

ofmButton::ofmButton(string _path) {
    setPath(_path);
    enabledTouch = true;
    _initTheme();
}

void ofmButton::_initTheme() {
    ofmTheme* theme = ofmTheme::instance();
    color = ofColor::fromHex(theme->color);
    textColor = ofColor::fromHex(theme->btnTextColor);
    width = theme->buttonWidth;
    height = theme->buttonHeight;
    round = theme->round;
}

void ofmButton::initOnce() {
    ofmTheme* theme = ofmTheme::instance();
    theme->retinaImageSize(_img);
    ofmComp::initOnce();
}

ofImage* ofmButton::getImage() {
    return _img;
}

void ofmButton::update() {
    ofmComp::update();
    _time.update();
    if (_time.second >= debounce) {
        _time.second = 0;
        enabledTouch = true;
    }
}

void ofmButton::setPath(string _path) {
    path = _path;
    _img = new ofImage();
    _img->load(path);
    _img->setAnchorPercent(0.5, 0.5);
    width = _img->getWidth();
    height = _img->getHeight();
}

void ofmButton::draw() {
    if (path == "") {
        _drawGraphicBtn();
    } else {
        float a = parent != NULL ? parent->alpha * alpha : alpha;
        ofSetColor(255, 255, 255, 255 * a);
        float scale = width / _img->getWidth();
        ofScale(scale, scale);
        _img->draw(0, 0);
    }
}

void ofmButton::_drawGraphicBtn() {
    ofPushStyle();
    color.a = 255 * alpha;
    ofSetColor(color);
    if (isCircle) {
        ofDrawCircle(0, 0, width / 2);
    } else if (round == 0) {
        ofDrawRectangle(-width / 2, -height / 2, width, height);
    } else {
        ofDrawRectRounded(-width / 2, -height / 2, width, height, round);
    }

    ofSetColor(textColor);
    ofmFont::instance()->drawText(text, 0, 0);
    ofPopStyle();
}

void ofmButton::onTouchDown(ofmTouch& touch) {
    if (!enabledTouch) return;
    
    // btn click
    ofmComp::onTouchDown(touch);
    
    // animate effect
    if (animateType == "alpha") {
        alpha = animateAlpha;
        color.a = alpha * 255;
    }
    if (animateType == "scale") scale = animateScale;
    enabledTouch = false;
    
    // reset time second
    _time.second = 0;
}

void ofmButton::onTouchUp(ofmTouch& touch) {
    ofmComp::onTouchUp(touch);
    if (animateType == "alpha") {
        alpha = 1;
        color.a = alpha * 255;
    }
    if (animateType == "scale") scale = 1;
}

void ofmButton::destroy() {
    if (_img != NULL) _img->clear();
    delete _img;
    _img = NULL;

    ofmComp::destroy();
}
