#include <stdio.h>

#include "ofAppRunner.h"
#include "ofGraphics.h"
#include "ofmUILayer.h"
#include "ofmUtil.h"

using namespace std;

ofmUILayer::ofmUILayer() {
    appWidth = ofGetWidth();
    appHeight = ofGetHeight();
    _addListener();
}

ofmComp* ofmUILayer::getCompById(std::string id) {
    vector<ofmComp*>::reverse_iterator it;
    for (it = children.rbegin(); it != children.rend(); ++it) {
        if ((*it)->id == id) {
            return (*it);
        }
    }

    return NULL;
}

void ofmUILayer::_addListener() {
    ofAddListener(ofEvents().touchUp, this, &ofmUILayer::_onTouchUp,
                  OF_EVENT_ORDER_BEFORE_APP);
    ofAddListener(ofEvents().touchDown, this, &ofmUILayer::_onTouchDown,
                  OF_EVENT_ORDER_BEFORE_APP);
    ofAddListener(ofEvents().touchMoved, this, &ofmUILayer::_onTouchMoved,
                  OF_EVENT_ORDER_BEFORE_APP);
}

bool ofmUILayer::testChildTouchDown(ofPoint& point) {
    if (_destroyed) return false;
    if (children.empty()) return false;

    vector<ofmComp*>::reverse_iterator it;
    for (it = children.rbegin(); it != children.rend(); ++it) {
        if ((*it)->hitTestSelfAndChild(point)) {
            return true;
            break;
        }
    }
    
    return false;
}


void ofmUILayer::_onTouchDown(ofTouchEventArgs& args) {
    if (!visible) return;
    if (children.empty()) return;

    _touch.setXY(args.x, args.y);
    ofmCon::onTouchDown(_touch);
}

void ofmUILayer::_onTouchMoved(ofTouchEventArgs& args) {
    if (!visible) return;
    if (children.empty()) return;

    _touch.setXY(args.x, args.y);
    ofmCon::onTouchMoved(_touch);
}

void ofmUILayer::_onTouchUp(ofTouchEventArgs& args) {
    if (!visible) return;

    _touch.setXY(args.x, args.y);
    ofmCon::onTouchUp(_touch);
}

void ofmUILayer::destroy() {
    ofRemoveListener(ofEvents().touchUp, this, &ofmUILayer::_onTouchUp,
                     OF_EVENT_ORDER_BEFORE_APP);
    ofRemoveListener(ofEvents().touchDown, this, &ofmUILayer::_onTouchDown,
                     OF_EVENT_ORDER_BEFORE_APP);
    ofRemoveListener(ofEvents().touchMoved, this, &ofmUILayer::_onTouchMoved,
                     OF_EVENT_ORDER_BEFORE_APP);

    std::vector<ofmComp*>::iterator it;
    for (it = children.begin(); it != children.end(); it++) {
        if ((*it) != NULL) {
            (*it)->destroy();
            delete (*it);
            (*it) = NULL;
        }
    }

    ofmUtil::emptyVector(children);
}
