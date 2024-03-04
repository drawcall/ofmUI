#pragma once

#include <vector>
#include <string>
#include "ofmTween.h"
#include "ofmBase.h"

const float OFM_ANI_TIME = 0.5;
const float OFM_ANI_DIS = 500;
const int AN_EASEA = EASE_OUT_BACK;
const int AN_EASED = AN_EASEA - 1;

class ofmAnim {
public:
    static Tween* appear(ofmBase* node, std::string type = "zoom", float time = OFM_ANI_TIME, int ease = AN_EASEA);
    static Tween* disAppear(ofmBase* node, std::string type = "zoom", float time = OFM_ANI_TIME, int ease = AN_EASED);
    
    // zoom
    static Tween* zoomAppear(ofmBase* node, float time = OFM_ANI_TIME, int ease = AN_EASEA);
    static Tween* zoomDisAppear(ofmBase* node, float time = OFM_ANI_TIME, int ease = AN_EASED);
    static Tween* zoomFadeAppear(ofmBase* node, float time = OFM_ANI_TIME, int ease = AN_EASEA);
    static Tween* zoomFadeDisAppear(ofmBase* node, float time = OFM_ANI_TIME, int ease = AN_EASED);
    
    // fade
    static Tween* fadeAppear(ofmBase* node, float time = OFM_ANI_TIME, int ease = AN_EASEA);
    static Tween* fadeDisAppear(ofmBase* node, float time = OFM_ANI_TIME, int ease = AN_EASED);
    
    // slide
    static Tween* slideUpAppear(ofmBase* node, float time = OFM_ANI_TIME, int ease = AN_EASEA);
    static Tween* slideUpDisAppear(ofmBase* node, float time = OFM_ANI_TIME, int ease = AN_EASED);
    static Tween* slideDownAppear(ofmBase* node, float time = OFM_ANI_TIME, int ease = AN_EASEA);
    static Tween* slideDownDisAppear(ofmBase* node, float time = OFM_ANI_TIME, int ease = AN_EASED);
    
    // rotate
    static Tween* rotateAppear(ofmBase* node, float time = OFM_ANI_TIME, int ease = AN_EASEA);
    static Tween* rotateDisAppear(ofmBase* node, float time = OFM_ANI_TIME, int ease = AN_EASED);
    
    // move up
    static Tween* moveUpAppear(ofmBase* node, float time = OFM_ANI_TIME, int ease = AN_EASEA);
    static Tween* moveUpDisAppear(ofmBase* node, float time = OFM_ANI_TIME, int ease = AN_EASED);
};
