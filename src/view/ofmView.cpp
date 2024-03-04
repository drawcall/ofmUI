#include "ofmTrans.h"
#include "ofmUid.h"
#include "ofmUtil.h"
#include "ofmView.h"

using namespace std;

// ------------------------------------------------------------------
// private public methods
// ------------------------------------------------------------------
void ofmView::_setup() {
    id = ofmUid::id(cname);
    setup();
}

void ofmView::_update() {
    //if(!starting) return;
    update();
    _updateUI();
}

void ofmView::_draw() {
    if (!_canRender()) return;

    ofPushMatrix();
    _pushMatrix();
    draw();
    _drawUI();
    ofPopMatrix();
}

void ofmView::_resize() {
    resize();
    _resizeUI();
}

void ofmView::_destroy() {
    _destroyUI();
    destroy();
}

Tween* ofmView::_appear(std::string aniType, float time, int ease) {
    if (_appeared) return NULL;

    _appeared = true;
    return ofmTrans::appear(this, aniType, time, ease);
}

Tween* ofmView::_disAppear(std::string aniType, float time, int ease) {
    stop();
    Tween* tween = ofmTrans::disAppear(this, aniType, time, ease);
    ofmTween::onComplete(tween, this, &ofmView::_onDisAppearComplete);
    return tween;
}

void ofmView::_onDisAppearComplete(float* arg) {
    _appeared = false;
}

// ------------------------------------------------------------------
// protected ui method
// ------------------------------------------------------------------
void ofmView::_updateUI() {
    if (_layers.empty()) return;
    for (int i = 0; i < _layers.size(); i++) {
        _layers[i]->update();
    }
}

void ofmView::_drawUI() {
    if (!_canRender()) return;
    if (_layers.empty()) return;
    for (int i = 0; i < _layers.size(); i++) {
        _layers[i]->_draw();
    }
}

void ofmView::_resizeUI() {
    if (_layers.empty()) return;
    for (int i = 0; i < _layers.size(); i++) {
        _layers[i]->resize();
    }
}

void ofmView::_destroyUI() {
    ofmUtil::destroyElementsFromVector(_layers);
}

// ------------------------------------------------------------------
// functional public method
// ------------------------------------------------------------------
void ofmView::start() {
    starting = true;
}

void ofmView::stop() {
    starting = false;
}

void ofmView::addUILayer(ofmUILayer* layer) {
    removeUILayer(layer);
    _layers.emplace_back(layer);
}

void ofmView::addUILayer(ofmUILayer& layer) {
    addUILayer(&layer);
}

void ofmView::removeUILayer(ofmUILayer* layer) {
    ofmUtil::removeFromVector(_layers, layer);
}

void ofmView::removeUILayer(ofmUILayer& layer) {
    removeUILayer(&layer);
}

// ------------------------------------------------------------------
// override public methods
// ------------------------------------------------------------------
void ofmView::setup() {}

void ofmView::update() {}

void ofmView::draw() {}

void ofmView::resize() {}

void ofmView::destroy() {}

void ofmView::touchDown(ofTouchEventArgs& touch) {}

void ofmView::touchMoved(ofTouchEventArgs& touch) {}

void ofmView::touchUp(ofTouchEventArgs& touch) {}

void ofmView::touchDoubleTap(ofTouchEventArgs& touch) {}

void ofmView::touchCancelled(ofTouchEventArgs& touch) {}
