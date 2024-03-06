#include <iostream>

#include "ofmComp.h"
#include "ofmCon.h"
#include "ofmMathUtil.h"
#include "ofmTheme.h"

using namespace std;

void ofmComp::_draw() {
    if (!canRender()) return;

    //ofPushStyle();
    ofPushMatrix();
    pushMatrix();

    // draw element
    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255, alpha * 255);
    draw();
    ofDisableAlphaBlending();

    ofPopMatrix();
    //ofPopStyle();
}

void ofmComp::setWH(float _w, float _h) {
    width = _w;
    height = _h;
}

void ofmComp::setWH(std::string _x, std::string _y) {
    float px = ofmMathUtil::strToNum(_x);
    width = ofGetWidth() * (px / 100);

    if (_y != "") {
        float py = ofmMathUtil::strToNum(_y);
        height = ofGetHeight() * (py / 100);
    }

    enabledRetina = false;
}

bool ofmComp::hitTest(ofPoint& point) {
    if (!enabledTouch) return false;
    if (!canRender()) return false;

    _updateMatrix();
    _updateTouchPoint(point);
    return rect.inside(_touch.localX, _touch.localY);
}

bool ofmComp::hitTestSelfAndChild(ofPoint& point) {
    return hitTest(point);
}

void ofmComp::_updateTouchPoint(ofPoint& point) {
    float mx = point.x;
    float my = point.y;

    float a00 = matrix.a, a01 = matrix.c, a02 = matrix.tx, a10 = matrix.b,
          a11 = matrix.d, a12 = matrix.ty, id = 1 / (a00 * a11 + a01 * -a10);

    float x = a11 * id * mx + -a01 * id * my + (a12 * a01 - a02 * a11) * id;
    float y = a00 * id * my + -a10 * id * mx + (-a12 * a00 + a02 * a10) * id;

    _touch.localX = x;
    _touch.localY = y;
}

void ofmComp::onTouchDown(ofmTouch& _touch) {
    _touch.id = id;
    _touch.copy(_touch);
    ofNotifyEvent(touchDown, _touch, this);
    touching = true;
}

void ofmComp::onTouchMoved(ofmTouch& _touch) {
    _touch.id = id;
    _touch.copy(_touch);
    ofNotifyEvent(touchMove, _touch, this);
}

void ofmComp::onTouchUp(ofmTouch& _touch) {
    if (touching) {
        _touch.id = id;
        _touch.copy(_touch);
        ofNotifyEvent(touchUp, _touch, this);
        touching = false;
    }
}

void ofmComp::update() {
    if (!_inited) {
        initOnce();
        _inited = true;
    }
}

void ofmComp::initOnce() {
    // set theme size
    if (enabledRetina) {
        ofmTheme* theme = ofmTheme::instance();
        theme->retinaValuePtr(&this->width);
        theme->retinaValuePtr(&this->height);
        theme->retinaValuePtr(&this->round);
        theme->retinaValuePtr(&this->radius);
    }

    // set rect zone
    float w = width;
    float h = ofmMathUtil::max(radius, height);
    h = ofmMathUtil::max(40, h);
    rect.setCenterWH(0, 0, w, h);
}

void ofmComp::_updateMatrix() {
    matrix.identity();
    if (parent != NULL) {
        matrix.appendMatrix(parent->matrix);
    }

    matrix.appendTransform(x, y, scale, scale, rotation, reg, reg);
}

void ofmComp::destroy() {
    parent = NULL;
}
