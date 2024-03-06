#include "ofmAnim.h"
#include "ofmDrawer.h"
#include "ofmTheme.h"

using namespace std;

ofmDrawer::ofmDrawer():ofmPanel() {
    alpha = 0.9;
    width = ofGetWidth();
}

void ofmDrawer::initOnce() {
    ofmPanel::initOnce();
    width = ofGetWidth();
}

void ofmDrawer::draw() {
    ofPushStyle();
    ofEnableAlphaBlending();
    panelColor.a = floor(255 * alpha);
    ofSetColor(panelColor);
    float dis = 80;
    ofDrawRectangle(-width/2, -height, width, height + dis);
    ofDisableAlphaBlending();  
    ofPopStyle();
}

void ofmDrawer::onTouchDown(ofmTouch& touch) {
    ofmPanel::onTouchDown(touch);
    if(touchClose && _appeared) {
        if (!_fakeHitTest(touch.point)) {
            disAppear();
        }
    }
}

bool ofmDrawer::_fakeHitTest(ofPoint& point) {
    _updateMatrix();
    _updateTouchPoint(point);
    rect.setXYWH(-width/2, -height, width, height);
    return rect.inside(_touch.localX, _touch.localY);

}

Tween* ofmDrawer::appear(float time, int ease) {
    return ofmPanel::appear("moveUp", time, ease);
}

Tween* ofmDrawer::disAppear(float time, int ease) {
    return ofmPanel::disAppear("moveUp", time, ease);
}

Tween* ofmDrawer::submitAndDisAppear(float time, int ease) {
    return ofmPanel::submitAndDisAppear("moveUp", time, ease);
}

void ofmDrawer::_addCloseBtn() {
    ofmPanel::_addCloseBtn();
    
    if(_closeBtn != NULL) {
        float r = ofmTheme::instance()->circleButtonRadius;
        float dis = r + 4;
        _closeBtn->x = width/2 - dis;
        _closeBtn->y = -height + dis;
        _removeCloseBtnListener();
        ofAddListener(_closeBtn->touchDown, this, &ofmDrawer::_onClose);
    }
}

void ofmDrawer::_onClose(ofmTouch& touch) {
    disAppear();
}

void ofmDrawer::_initTheme() {
    ofmPanel::_initTheme();
    ofmTheme* theme = ofmTheme::instance();
    panelColor = ofColor::fromHex(theme->drawerColor);
    width = ofGetWidth();
    height = theme->drawerHeight;
}

void ofmDrawer::destroy() {
    ofRemoveListener(_closeBtn->touchDown, this, &ofmDrawer::_onClose);
    ofmPanel::destroy();
}
