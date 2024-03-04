#include <stdio.h>

#include "ofGraphics.h"
#include "ofmCon.h"
#include "ofmUtil.h"

using namespace std;

void ofmCon::addChild(ofmComp& ui) {
    addChild(&ui);
}

void ofmCon::removeChild(ofmComp& ui) {
    removeChild(&ui);
}

void ofmCon::addChild(ofmComp* ui) {
    removeChild(ui);
    ui->parent = this;
    children.emplace_back(ui);
}

void ofmCon::removeChild(ofmComp* ui) {
    ui->parent = NULL;
    ofmUtil::removeFromVector(children, ui);
}

void ofmCon::update() {
    ofmComp::update();
    if (children.empty()) return;
    for (int i = 0; i < children.size(); i++) {
        children[i]->update();
    }
}

void ofmCon::resize() {
    for (int i = 0; i < children.size(); i++) {
        children[i]->resize();
    }
}

void ofmCon::_draw() {
    if (!canRender()) return;
    if (children.empty()) return;

    ofPushMatrix();
    pushMatrix();

    draw();
    _drawChildren();

    ofPopMatrix();
}

void ofmCon::_drawChildren() {
    if (children.empty()) return;
    for (int i = 0; i < children.size(); i++) {
        if (children[i]->visible) {
            children[i]->_draw();
        }
    }
}

bool ofmCon::hitTest(ofPoint& point) {
    if (children.empty()) return false;
    if (!canRender()) return false;

    _updateMatrix();
    return true;
}

bool ofmCon::hitTestSelfAndChild(ofPoint& point) {
    if (children.empty()) return false;
    if (!canRender()) return false;
    
    for (int i = 0; i < children.size(); i++) {
        ofmComp* comp = children[i];
        if (comp->hitTestSelfAndChild(point)) return true;
    }
    return false;
}

void ofmCon::onTouchDown(ofmTouch& touch) {
    if (_destroyed) return;
    if (children.empty()) return;
    
    touching = true;
    vector<ofmComp*>::reverse_iterator it;
    for (it = children.rbegin(); it != children.rend(); ++it) {
        if ((*it)->hitTest(touch.point)) {
            (*it)->onTouchDown(touch);
            break;
        }
    }
}

void ofmCon::onTouchMoved(ofmTouch& touch) {
    if (_destroyed) return;
    if (children.empty()) return;

    vector<ofmComp*>::reverse_iterator it;
    for (it = children.rbegin(); it != children.rend(); ++it) {
        if ((*it)->hitTest(touch.point)) {
            (*it)->onTouchMoved(touch);
            break;
        }
    }
}

void ofmCon::onTouchUp(ofmTouch& touch) {
    if (_destroyed) return;
    if (children.empty()) return;

    vector<ofmComp*>::reverse_iterator it;
    for (it = children.rbegin(); it != children.rend(); ++it) {
        if ((*it)->touching) {
            (*it)->onTouchUp(touch);
        }
    }
    touching = false;
}

void ofmCon::destroy() {
    _destroyed = true;
    ofmUtil::destroyElementsFromVector(children);
}
