#include <iostream>
#include "ofAppRunner.h"
#include "ofEvents.h"
#include "ofmScroll.h"
#include "ofmTheme.h"
#include "ofmUtil.h"
#include "ofmMathUtil.h"

using namespace std;

ofmScroll::ofmScroll(float w, float h):ofmCon() {
    width = w;
    height = h;
    _fbo.allocate(width, height, GL_RGBA);
    _con = new ofmCon();
    ofmCon::addChild(_con);
}

void ofmScroll::setContentHeight(float contentHeight) {
    _contentHeight = contentHeight;
}

void ofmScroll::addChild(ofmComp& ui) {
    addChild(&ui);
}

void ofmScroll::removeChild(ofmComp& ui) {
    removeChild(&ui);
}

void ofmScroll::addChild(ofmComp* ui) {
    _con->addChild(ui);
    float posY = ui->y + ui->height;
    _contentHeight = ofmMathUtil::max(posY, _contentHeight);
}

void ofmScroll::removeChild(ofmComp* ui) {
    _con->removeChild(ui);
}

void ofmScroll::_draw() {
    if (!canRender()) return;
    ofPushMatrix();
    pushMatrix();
    draw();
    ofPopMatrix();
}

void ofmScroll::update() {
    ofmCon::update();
    _fbo.begin();
    ofClear(255, 255, 255, 0);
    
    _drawChildren();
    _fbo.end();
}

void ofmScroll::draw() {
    ofPushStyle();
    ofEnableAlphaBlending();
    if (debug) {
        ofSetColor(0, 0, 0);
        ofDrawRectangle(x, y, width, height);
    }
    _fbo.draw(0, 0);
    ofDisableAlphaBlending();
    ofPopStyle();
}

void ofmScroll::onTouchDown(ofmTouch& touch) {
    _point.set(touch.localX, touch.localY);
}

void ofmScroll::onTouchUp(ofmTouch& touch) {
    
}

void ofmScroll::onTouchMoved(ofmTouch& touch) {
    dis = touch.localY - _point.y;
    float sdis = dis / 10;
    _con->y -=sdis;
    _judgeBoundary();
    
    _point.set(touch.localX, touch.localY);
}

void ofmScroll::_initTheme() {
    ofmTheme::instance();
}

void ofmScroll::_judgeBoundary() {
    if (_con->y >= 0) {
        _con->y = 0;
    }
    
    if (_con->y + _contentHeight < height) {
        _con->y = height - _contentHeight;
    }
}

void ofmScroll::_clear() {
    _fbo.begin();
    ofClear(255, 255, 255, 0);
    _fbo.end();
}

void ofmScroll::destroy() {
    ofmCon::destroy();
    _fbo.clear();
    delete _con;
    _con = NULL;
}
