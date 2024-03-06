#include "ofmTrans.h"
#include "ofmTween.h"
#include "ofmUtil.h"
#include "ofmMathUtil.h"
#include "ofmConstants.h"

Tween* ofmTrans::appear(ofmBaseView* node, std::string type, float time, int ease){
    if(type == "none") return noneAppear(node, time);
    if(type == "fade") return fadeAppear(node, time, ease);
    if(type == "rotate") return rotateAppear(node, time, ease);
    if(type == "scaleRotate") return scaleRotateAppear(node, time, ease);
    
    if(type == "moveLeft") return moveLeftAppear(node, time, ease);
    if(type == "moveRight") return moveRightAppear(node, time, ease);
    if(type == "moveTop") return moveTopAppear(node, time, ease);
    if(type == "moveBottom") return moveBottomAppear(node, time, ease);
    
    if(type == "scaleLeft") return scaleLeftAppear(node, time, ease);
    if(type == "scaleRight") return scaleRightAppear(node, time, ease);
    if(type == "scaleTop") return scaleTopAppear(node, time, ease);
    if(type == "scaleBottom") return scaleBottomAppear(node, time, ease);
    
    if(type == "rollLeft") return rollLeftAppear(node, time, ease);
    if(type == "rollRight") return rollRightAppear(node, time, ease);
    if(type == "rollTop") return rollTopAppear(node, time, ease);
    if(type == "rollBottom") return rollBottomAppear(node, time, ease);
    
    return zoomAppear(node, time, ease);
}

Tween* ofmTrans::disAppear(ofmBaseView* node, std::string type, float time, int ease){
    if(type == "none") return noneDisAppear(node, time);
    if(type == "fade") return fadeDisAppear(node, time, ease);
    if(type == "rotate") return rotateDisAppear(node, time, ease);
    if(type == "scaleRotate") return scaleRotateDisAppear(node, time, ease);
    
    if(type == "moveLeft") return moveLeftDisAppear(node, time, ease);
    if(type == "moveRight") return moveRightDisAppear(node, time, ease);
    if(type == "moveTop") return moveTopDisAppear(node, time, ease);
    if(type == "moveBottom") return moveBottomDisAppear(node, time, ease);
    
    if(type == "scaleLeft") return scaleLeftDisAppear(node, time, ease);
    if(type == "scaleRight") return scaleRightDisAppear(node, time, ease);
    if(type == "scaleTop") return scaleTopDisAppear(node, time, ease);
    if(type == "scaleBottom") return scaleBottomDisAppear(node, time, ease);
    
    if(type == "rollLeft") return rollLeftDisAppear(node, time, ease);
    if(type == "rollRight") return rollRightDisAppear(node, time, ease);
    if(type == "rollTop") return rollTopDisAppear(node, time, ease);
    if(type == "rollBottom") return rollBottomDisAppear(node, time, ease);
    
    return zoomDisAppear(node, time, ease);;
}

// zoom in out ----------------------------------------
Tween* ofmTrans::zoomAppear(ofmBaseView* node, float time, int ease) {
    ofmTween::fromTo(&node->_alpha, 0, 1, 0, time, EASE_LINEAR);
    return _scaleInView(node, 0.01, time, ease);
}

Tween* ofmTrans::zoomDisAppear(ofmBaseView* node, float time, int ease) {
    ofmTween::to(&node->_alpha, 0, 0, time, EASE_LINEAR);
    return _scaleOutView(node, 0.01, time, ease);
}

// _alpha fade ----------------------------------------
Tween* ofmTrans::fadeAppear(ofmBaseView* node, float time, int ease) {
    ofmTween::fromTo(&node->_alpha, 0, 1, 0, time, EASE_OUT_SINE);
    return ofmTween::getTween(&node->_alpha);
}

Tween* ofmTrans::fadeDisAppear(ofmBaseView* node, float time, int ease) {
    ofmTween::to(&node->_alpha, 0, 0, time, EASE_IN_SINE);
    return ofmTween::getTween(&node->_alpha);
}

// move down up ----------------------------------------
Tween* ofmTrans::moveLeftAppear(ofmBaseView* node, float time, int ease) {
    float w = ofGetWidth();
    ofmTween::from(&node->_x, node->_x + w, 0, time, ease);
    return ofmTween::getTween(&node->_x);
}

Tween* ofmTrans::moveLeftDisAppear(ofmBaseView* node, float time, int ease) {
    float w = ofGetWidth();
    ofmTween::to(&node->_x, node->_x - w, 0, time, ease);
    return ofmTween::getTween(&node->_x);
}

Tween* ofmTrans::moveRightAppear(ofmBaseView* node, float time, int ease) {
    float w = ofGetWidth();
    ofmTween::from(&node->_x, node->_x - w, 0, time, ease);
    return ofmTween::getTween(&node->_x);
}

Tween* ofmTrans::moveRightDisAppear(ofmBaseView* node, float time, int ease) {
    float w = ofGetWidth();
    ofmTween::to(&node->_x, node->_x + w, 0, time, ease);
    return ofmTween::getTween(&node->_x);
}

Tween* ofmTrans::moveTopAppear(ofmBaseView* node, float time, int ease) {
    float h = ofGetHeight();
    ofmTween::from(&node->_y, node->_y + h, 0, time, ease);
    return ofmTween::getTween(&node->_y);
}

Tween* ofmTrans::moveTopDisAppear(ofmBaseView* node, float time, int ease) {
    float h = ofGetHeight();
    ofmTween::to(&node->_y, node->_y - h, 0, time, ease);
    return ofmTween::getTween(&node->_y);
}

Tween* ofmTrans::moveBottomAppear(ofmBaseView* node, float time, int ease) {
    float h = ofGetHeight();
    ofmTween::from(&node->_y, node->_y - h, 0, time, ease);
    return ofmTween::getTween(&node->_y);
}

Tween* ofmTrans::moveBottomDisAppear(ofmBaseView* node, float time, int ease) {
    float h = ofGetHeight();
    ofmTween::to(&node->_y, node->_y + h, 0, time, ease);
    return ofmTween::getTween(&node->_y);
}

// _scale left up ----------------------------------------
Tween* ofmTrans::scaleLeftAppear(ofmBaseView* node, float time, int ease) {
    float w = ofGetWidth();
    ofmTween::from(&node->_x, node->_x + w, 0, time, ease);
    return ofmTween::getTween(&node->_x);
}

Tween* ofmTrans::scaleLeftDisAppear(ofmBaseView* node, float time, int ease) {;
    return _scaleOutView(node, 0.3, time, ease);;
}

Tween* ofmTrans::scaleRightAppear(ofmBaseView* node, float time, int ease) {
    float w = ofGetWidth();
    ofmTween::from(&node->_x, node->_x - w, 0, time, ease);
    return ofmTween::getTween(&node->_x);
}

Tween* ofmTrans::scaleRightDisAppear(ofmBaseView* node, float time, int ease) {
    return _scaleOutView(node, 0.3, time, ease);;
}

Tween* ofmTrans::scaleTopAppear(ofmBaseView* node, float time, int ease) {
    float h = ofGetHeight();
    ofmTween::from(&node->_y, node->_y + h, 0, time, ease);
    return ofmTween::getTween(&node->_y);
}

Tween* ofmTrans::scaleTopDisAppear(ofmBaseView* node, float time, int ease) {
    return _scaleOutView(node, 0.3, time, ease);;
}

Tween* ofmTrans::scaleBottomAppear(ofmBaseView* node, float time, int ease) {
    float h = ofGetHeight();
    ofmTween::from(&node->_y, node->_y - h, 0, time, ease);
    return ofmTween::getTween(&node->_y);
}

Tween* ofmTrans::scaleBottomDisAppear(ofmBaseView* node, float time, int ease) {
    return _scaleOutView(node, 0.3, time, ease);;
}

// roll left up ----------------------------------------
Tween* ofmTrans::rollLeftAppear(ofmBaseView* node, float time, int ease) {
    float w = ofGetWidth();
    float h = ofGetHeight();
    float _scale = 0.5;
    
    ofmTween::fromTo(&node->_y, (1-_scale) * h/2, 0, 0, time, ease);
    ofmTween::fromTo(&node->_scale, _scale, 1, 0, time, ease);
    ofmTween::from(&node->_x, node->_x + w, 0, time, ease);
    return ofmTween::getTween(&node->_x);
}

Tween* ofmTrans::rollLeftDisAppear(ofmBaseView* node, float time, int ease) {
    float w = ofGetWidth();
    float h = ofGetHeight();
    float _scale = 0.5;
    
    ofmTween::to(&node->_y, (1-_scale) * h/2, 0, time, ease);
    ofmTween::to(&node->_scale, _scale, 0, time, ease);
    ofmTween::to(&node->_x, node->_x - w, 0, time, ease);
    return ofmTween::getTween(&node->_x);
}

Tween* ofmTrans::rollRightAppear(ofmBaseView* node, float time, int ease) {
    float w = ofGetWidth();
    float h = ofGetHeight();
    float _scale = 0.5;
    
    ofmTween::fromTo(&node->_y, (1-_scale) * h/2, 0, 0, time, ease);
    ofmTween::fromTo(&node->_scale, _scale, 1, 0, time, ease);
    ofmTween::from(&node->_x, node->_x - w, 0, time, ease);
    return ofmTween::getTween(&node->_x);
}

Tween* ofmTrans::rollRightDisAppear(ofmBaseView* node, float time, int ease) {
    float w = ofGetWidth();
    float h = ofGetHeight();
    float _scale = 0.5;
    
    ofmTween::to(&node->_y, (1-_scale) * h/2, 0, time, ease);
    ofmTween::to(&node->_scale, _scale, 0, time, ease);
    ofmTween::to(&node->_x, node->_x + w, 0, time, ease);
    return ofmTween::getTween(&node->_x);
}

Tween* ofmTrans::rollTopAppear(ofmBaseView* node, float time, int ease) {
    float w = ofGetWidth();
    float h = ofGetHeight();
    float _scale = 0.5;
    
    ofmTween::fromTo(&node->_x, (1-_scale) * w/2, 0, 0, time, ease);
    ofmTween::fromTo(&node->_scale, _scale, 1, 0, time, ease);
    ofmTween::from(&node->_y, node->_y + h, 0, time, ease);
    return ofmTween::getTween(&node->_y);
}

Tween* ofmTrans::rollTopDisAppear(ofmBaseView* node, float time, int ease) {
    float w = ofGetWidth();
    float h = ofGetHeight();
    float _scale = 0.5;
    
    ofmTween::to(&node->_x, (1-_scale) * w/2, 0, time, ease);
    ofmTween::to(&node->_scale, _scale, 0, time, ease);
    ofmTween::to(&node->_y, node->_y - h, 0, time, ease);
    return ofmTween::getTween(&node->_y);
}

Tween* ofmTrans::rollBottomAppear(ofmBaseView* node, float time, int ease) {
    float w = ofGetWidth();
    float h = ofGetHeight();
    float _scale = 0.5;
    
    ofmTween::fromTo(&node->_x, (1-_scale) * w/2, 0, 0, time, ease);
    ofmTween::fromTo(&node->_scale, _scale, 1, 0, time, ease);
    ofmTween::from(&node->_y, node->_y - h, 0, time, ease);
    return ofmTween::getTween(&node->_y);
}

Tween* ofmTrans::rollBottomDisAppear(ofmBaseView* node, float time, int ease) {
    float w = ofGetWidth();
    float h = ofGetHeight();
    float _scale = 0.5;
    
    ofmTween::to(&node->_x, (1-_scale) * w/2, 0, time, ease);
    ofmTween::to(&node->_scale, _scale, 0, time, ease);
    ofmTween::to(&node->_y, node->_y + h, 0, time, ease);
    return ofmTween::getTween(&node->_y);
}

// rotate left right ----------------------------------------
Tween* ofmTrans::scaleRotateAppear(ofmBaseView* node, float time, int ease) {
    return _scaleInView(node, 0.1, time, ease);
}

Tween* ofmTrans::scaleRotateDisAppear(ofmBaseView* node, float time, int ease) {
    _scaleOutView(node, 0.1, time, ease);
    ofmTween::to(&node->_rotation, -180, 0, time, ease);
    return ofmTween::getTween(&node->_rotation);
}

Tween* ofmTrans::rotateAppear(ofmBaseView* node, float time, int ease) {
    ofmTween::fromTo(&node->_scale, 0.1, 1, 0, time, ease);
    ofmTween::fromTo(&node->_rotation, 180, 0, 0, time, ease);
    return ofmTween::getTween(&node->_rotation);
}

Tween* ofmTrans::rotateDisAppear(ofmBaseView* node, float time, int ease) {
    ofmTween::to(&node->_scale, 0.1, 0, time, ease);
    ofmTween::to(&node->_rotation, -180, 0, time, ease);
    return ofmTween::getTween(&node->_rotation);
}

// none animate ----------------------------------------
Tween* ofmTrans::noneAppear(ofmBaseView* node, float time) {
    node->_visible = true;
    ofmTween::to(&node->_x, node->_x, 0, 0, EASE_LINEAR);
    return ofmTween::getTween(&node->_x);
}

Tween* ofmTrans::noneDisAppear(ofmBaseView* node, float time) {
    ofmTween::to(&node->_x, node->_x, 0, time, EASE_LINEAR);
    return ofmTween::getTween(&node->_x);
}

// get ease
int ofmTrans::getEaseOutByType(std::string type, int easeIn) {
    if(ofmUtil::strInclude(type, "move")) {
        return easeIn;
    }
    
    int easeOut = 0;
    easeOut = easeIn - 1;
    return ofmMathUtil::max(0, easeOut);
}

Tween* ofmTrans::_scaleInView(ofmBaseView* node, float _scale, float time, int ease) {
    float w = ofGetWidth();
    float h = ofGetHeight();
    
    ofmTween::fromTo(&node->_x, (1-_scale) * w/2, 0, 0, time, ease);
    ofmTween::fromTo(&node->_y, (1-_scale) * h/2, 0, 0, time, ease);
    ofmTween::fromTo(&node->_scale, _scale, 1, 0, time, ease);
    return ofmTween::getTween(&node->_scale);
}

Tween* ofmTrans::_scaleOutView(ofmBaseView* node, float _scale, float time, int ease) {
    float w = ofGetWidth();
    float h = ofGetHeight();
    
    ofmTween::to(&node->_x, (1-_scale) * w/2, 0, time, ease);
    ofmTween::to(&node->_y, (1-_scale) * h/2, 0, time, ease);
    ofmTween::to(&node->_scale, _scale, 0, time, ease);
    return ofmTween::getTween(&node->_scale);
}
