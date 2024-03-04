#include "ofmAnim.h"
#include "ofmTween.h"
#include "ofmComp.h"

Tween* ofmAnim::appear(ofmBase* node, std::string type, float time, int ease){
    if(type == "fade") return fadeAppear(node, time, ease);
    if(type == "slideUp") return slideUpAppear(node, time, ease);
    if(type == "slideDown") return slideDownAppear(node, time, ease);
    if(type == "rotate") return rotateAppear(node, time, ease);
    if(type == "moveUp") return moveUpAppear(node, time, ease);
    if(type == "zoomFade") return zoomFadeAppear(node, time, ease);
    
    return zoomAppear(node, time, ease);
}

Tween* ofmAnim::disAppear(ofmBase* node, std::string type, float time, int ease){
    if(type == "fade") return fadeDisAppear(node, time, ease);
    if(type == "slideUp") return slideUpDisAppear(node, time, ease);
    if(type == "slideDown") return slideDownDisAppear(node, time, ease);
    if(type == "rotate") return rotateDisAppear(node, time, ease);
    if(type == "moveUp") return moveUpDisAppear(node, time, ease);
    if(type == "zoomFade") return zoomFadeDisAppear(node, time, ease);
    
    return zoomDisAppear(node, time, ease);
}

// zoon in out ----------------------------------------
Tween* ofmAnim::zoomAppear(ofmBase* node, float time, int ease) {
    ofmTween::fromTo(&node->scale, 0.1, 1, 0, time, ease);
    return ofmTween::getTween(&node->scale);
}

Tween* ofmAnim::zoomDisAppear(ofmBase* node, float time, int ease) {
    ofmTween::to(&node->scale, 0.1, 0, time, ease);
    return ofmTween::getTween(&node->scale);
}

Tween* ofmAnim::zoomFadeAppear(ofmBase* node, float time, int ease) {
    ofmTween::fromTo(&node->alpha, 0.5, 1, 0, time, EASE_LINEAR);
    ofmTween::fromTo(&node->scale, 0.1, 1, 0, time, ease);
    return ofmTween::getTween(&node->scale);
}

Tween* ofmAnim::zoomFadeDisAppear(ofmBase* node, float time, int ease) {
    ofmTween::to(&node->alpha, 0.1, 0, time, ease);
    ofmTween::to(&node->scale, 0.1, 0, time, ease);
    return ofmTween::getTween(&node->scale);
}

// alpha fade ----------------------------------------
Tween* ofmAnim::fadeAppear(ofmBase* node, float time, int ease) {
    ofmTween::fromTo(&node->alpha, 0, 1, 0, time, EASE_OUT_SINE);
    return ofmTween::getTween(&node->alpha);
}

Tween* ofmAnim::fadeDisAppear(ofmBase* node, float time, int ease) {
    ofmTween::to(&node->alpha, 0, 0, time, EASE_IN_SINE);
    return ofmTween::getTween(&node->alpha);
}

// slide down up ----------------------------------------
Tween* ofmAnim::slideDownAppear(ofmBase* node, float time, int ease) {
    ofmTween::fromTo(&node->alpha, 0, 1, 0, time, EASE_LINEAR);
    ofmTween::from(&node->y, node->y - OFM_ANI_DIS, 0, time, ease);
    return ofmTween::getTween(&node->y);
}

Tween* ofmAnim::slideDownDisAppear(ofmBase* node, float time, int ease) {
    ofmTween::to(&node->alpha, 0, 0, time, EASE_LINEAR);
    ofmTween::to(&node->y, node->y - OFM_ANI_DIS, 0, time, ease);
    return ofmTween::getTween(&node->y);
}

Tween* ofmAnim::slideUpAppear(ofmBase* node, float time, int ease) {
    ofmTween::fromTo(&node->alpha, 0, 1, 0, time, EASE_LINEAR);
    ofmTween::from(&node->y, node->y + OFM_ANI_DIS, 0, time, ease);
    return ofmTween::getTween(&node->y);
}

Tween* ofmAnim::slideUpDisAppear(ofmBase* node, float time, int ease) {
    ofmTween::to(&node->alpha, 0, 0, time, EASE_LINEAR);
    ofmTween::to(&node->y, node->y + OFM_ANI_DIS, 0, time, ease);
    return ofmTween::getTween(&node->y);
}

// rotate left right ----------------------------------------
Tween* ofmAnim::rotateAppear(ofmBase* node, float time, int ease) {
    ofmTween::fromTo(&node->scale, 0.1, 1, 0, time, ease);
    ofmTween::fromTo(&node->rotation, 180, 0, 0, time, ease);
    return ofmTween::getTween(&node->rotation);
}

Tween* ofmAnim::rotateDisAppear(ofmBase* node, float time, int ease) {
    ofmTween::to(&node->scale, 0.1, 0, time, ease);
    ofmTween::to(&node->rotation, -180, 0, time, ease);
    return ofmTween::getTween(&node->rotation);
}

// move up down ----------------------------------------
Tween* ofmAnim::moveUpAppear(ofmBase* node, float time, int ease) {
    ofmComp* comp = (ofmComp*)node;
    float pos = comp->y + comp->height;
    ofmTween::from(&comp->y, pos, 0, time, ease);
    return ofmTween::getTween(&comp->y);
}

Tween* ofmAnim::moveUpDisAppear(ofmBase* node, float time, int ease) {
    ofmComp* comp = (ofmComp*)node;
    float pos = comp->y + comp->height;
    ofmTween::to(&comp->y, pos, 0, time, ease);
    return ofmTween::getTween(&comp->y);
}
