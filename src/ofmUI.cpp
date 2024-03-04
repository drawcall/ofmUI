#include "ofmTheme.h"
#include "ofmUI.h"
#include "ofmUtil.h"
#include "ofmDevice.h"

using namespace std;

vector<ofmUILayer *> ofmUI::children;

void ofmUI::init() {
    ofmTheme::instance()->init();
    ofmDevice::detect();
}

void ofmUI::enableRetina(bool enable) {
    ofmTheme::instance()->enabledRetina = enable;
}

void ofmUI::loadFont(std::string path, int size) {
    int fontSize = ofmTheme::instance()->retinaFontSize(size);
    ofmFont::loadFont(path, fontSize);
}

void ofmUI::setTheme(std::string theme) {
    ofmTheme::instance()->setTheme(theme);
}

void ofmUI::addUILayer(ofmUILayer *layer) {
    removeUILayer(layer);
    children.emplace_back(layer);
}

void ofmUI::removeUILayer(ofmUILayer *layer) {
    ofmUtil::removeFromVector(children, layer);
}

void ofmUI::update() {
    ofmTween::update(ofGetElapsedTimeMillis());

    if (children.empty()) return;
    for (vector<ofmUILayer *>::iterator it = children.begin();
         it != children.end(); it++) {
        (*it)->update();
    }
}

void ofmUI::draw() {
    if (children.empty()) return;
    for (vector<ofmUILayer *>::iterator it = children.begin();
         it != children.end(); it++) {
        (*it)->_draw();
    }
}

void ofmUI::resize() {
    if (children.empty()) return;
    for (vector<ofmUILayer *>::iterator it = children.begin();
         it != children.end(); it++) {
        (*it)->resize();
    }
}

void ofmUI::destroy() {
    ofmTween::destroy();
    ofmUtil::destroyElementsFromVector(children);
    ofmFont::destroyAll();
}
