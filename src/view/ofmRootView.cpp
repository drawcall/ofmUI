#include <stdio.h>

#include "ofmConstants.h"
#include "ofmAlert.h"
#include "ofmRootView.h"
#include "ofmUI.h"
#include "ofmUtil.h"

using namespace std;

// ------------------------------------------------------------------
// setup and init method
// ------------------------------------------------------------------
void ofmRootView::setup() {
    ofmUI::init();
    _addListener();
    cname = "ofmRootView";
}

void ofmRootView::loadFont(std::string path, int size) {
    ofmUI::loadFont(path, size);
}

void ofmRootView::setTheme(std::string theme) {
    ofmUI::setTheme(theme);
}

void ofmRootView::enableRetina(bool enable) {
    ofmUI::enableRetina(enable);
}

// ------------------------------------------------------------------
// add main view or add child
// ------------------------------------------------------------------
void ofmRootView::addMainView(ofmView* view) {
    addChild(view);
    view->_setup();
    view->start();
    _currView = view;
    _navigating = false;
}

void ofmRootView::addUILayer(ofmUILayer* layer) {
    ofmView::addUILayer(layer);
    _addRootAlert(layer);
    _addConsole(layer);
}

void ofmRootView::addChild(ofmView* view) {
    removeChild(view);
    children.emplace_back(view);
}

void ofmRootView::removeChild(ofmView* view) {
    ofmUtil::removeFromVector(children, view);
}

// ------------------------------------------------------------------
// navigate to new page
// ------------------------------------------------------------------
ofmView* ofmRootView::getCurrentView() {
    return _currView;
}

void ofmRootView::navigateTo(ofmView* view, std::string type, float time,
                             int ease) {
    if (_navigating) return;

    int easeIn = ease;
    int easeOut = ofmTrans::getEaseOutByType(type, ease);

    // disAppear prevent view
    if (_currView != NULL) {
        _prevView = _currView;
        Tween* disTween = _prevView->_disAppear(type, time, easeOut);
        ofmTween::onComplete(disTween, this,
                             &ofmRootView::_onDisAppearComplete);
    }
    
    // appear current view
    Tween* appTween = view->_appear(type, time, easeIn);
    ofmTween::onComplete(appTween, this, &ofmRootView::_onAppearComplete);
    addChild(view);
    view->_setup();

    _currView = view;
    _navigating = true;
}

// ------------------------------------------------------------------
// update draw destory
// ------------------------------------------------------------------
void ofmRootView::update() {
    ofmUI::update();
    for (int i = 0; i < children.size(); i++) {
        children[i]->_update();
    }
    ofmView::_updateUI();
}

void ofmRootView::draw() {
    drawRoot();
    for (int i = 0; i < children.size(); i++) {
        children[i]->_draw();
    }
    ofmView::_drawUI();
}

void ofmRootView::resize() {
    for (int i = 0; i < children.size(); i++) {
        children[i]->_resize();
    }
    ofmView::_resizeUI();
}

void ofmRootView::destroy() {
    _removeListener();
    ofmUI::destroy();
    ofmView::_destroyUI();
    ofmUtil::destroyElementsFromVector(children);
    _prevView = NULL;
    _currView = NULL;
}

// ------------------------------------------------------------------
// private method
// ------------------------------------------------------------------
void ofmRootView::_onAppearComplete(float* arg) {
    _navigating = false;
    _currView->start();
    ofNotifyEvent(viewAppeared, _currView, this);
}

void ofmRootView::_onDisAppearComplete(float* arg) {
    if (_prevView == NULL) return;
    
    removeChild(_prevView);
    _prevView->_destroy();
    delete _prevView;
    _prevView = NULL;
}

void ofmRootView::_addListener() {
    _removeListener();
    ofAddListener(ofEvents().touchUp, this, &ofmRootView::_touchUp,
                  OF_EVENT_ORDER_BEFORE_APP);
    ofAddListener(ofEvents().touchDown, this, &ofmRootView::_touchDown,
                  OF_EVENT_ORDER_BEFORE_APP);
    ofAddListener(ofEvents().touchMoved, this, &ofmRootView::_touchMoved,
                  OF_EVENT_ORDER_BEFORE_APP);
    ofAddListener(ofEvents().touchDoubleTap, this,
                  &ofmRootView::_touchDoubleTap, OF_EVENT_ORDER_BEFORE_APP);
    ofAddListener(ofEvents().touchCancelled, this,
                  &ofmRootView::_touchCancelled, OF_EVENT_ORDER_BEFORE_APP);
}

void ofmRootView::_removeListener() {
    ofRemoveListener(ofEvents().touchUp, this, &ofmRootView::_touchUp,
                     OF_EVENT_ORDER_BEFORE_APP);
    ofRemoveListener(ofEvents().touchDown, this, &ofmRootView::_touchDown,
                     OF_EVENT_ORDER_BEFORE_APP);
    ofRemoveListener(ofEvents().touchMoved, this, &ofmRootView::_touchMoved,
                     OF_EVENT_ORDER_BEFORE_APP);
    ofRemoveListener(ofEvents().touchDoubleTap, this,
                     &ofmRootView::_touchDoubleTap, OF_EVENT_ORDER_BEFORE_APP);
    ofRemoveListener(ofEvents().touchCancelled, this,
                     &ofmRootView::_touchCancelled, OF_EVENT_ORDER_BEFORE_APP);
}

bool ofmRootView::_isUILayersBlock(ofTouchEventArgs& touch) {
    _touchPoint.x = touch.x;
    _touchPoint.y = touch.y;
    for (int i = 0; i < _layers.size(); i++) {
        ofmUILayer* layer = _layers[i];
        if (layer->testChildTouchDown(_touchPoint)) return true;
    }
    
    return false;
}

void ofmRootView::_touchDown(ofTouchEventArgs& touch) {
    for (vector<ofmView*>::iterator it = children.begin(); it != children.end();
         it++) {
        if ((*it)->_visible) {
            // or open ui touchdown block
            if (enableUITouchDownBlock) {
                if (!_isUILayersBlock(touch)) (*it)->touchDown(touch);
            } else {
                (*it)->touchDown(touch);
            }
        }
    }
}

void ofmRootView::_touchMoved(ofTouchEventArgs& touch) {
    for (vector<ofmView*>::iterator it = children.begin(); it != children.end();
         it++) {
        if ((*it)->_visible) {
            if ((*it)->enabledUITouchCheck) {
                (*it)->uiTouching = _isUILayersBlock(touch);
            }
            (*it)->touchMoved(touch);
        }
    }
}

void ofmRootView::_touchUp(ofTouchEventArgs& touch) {
    for (vector<ofmView*>::iterator it = children.begin(); it != children.end();
         it++) {
        if ((*it)->_visible) {
            (*it)->touchUp(touch);
        }
    }
}

void ofmRootView::_touchDoubleTap(ofTouchEventArgs& touch) {
    for (vector<ofmView*>::iterator it = children.begin(); it != children.end();
         it++) {
        if ((*it)->_visible) {
            (*it)->touchDoubleTap(touch);
        }
    }
}

void ofmRootView::_touchCancelled(ofTouchEventArgs& touch) {
    for (vector<ofmView*>::iterator it = children.begin(); it != children.end();
         it++) {
        if ((*it)->_visible) {
            (*it)->touchCancelled(touch);
        }
    }
}

void ofmRootView::_addRootAlert(ofmUILayer* layer) {
    ofmAlert* alert = ofmAlert::getRootAlert();
    if (alert->parent != NULL) return;

    alert->setXY(ofGetWidth() / 2, ofGetHeight() / 2);
    layer->addChild(alert);
}

void ofmRootView::_addConsole(ofmUILayer* layer) {
    ofmConsole* console = ofmConsole::instance();
    if (console->parent != NULL) return;

    console->visible = false;
    layer->addChild(console);
}
