#pragma once

#include <vector>
#include <string>
#include "ofmTween.h"
#include "ofmBaseView.h"

const float OFM_TAS_TIME = 0.5;
const int EASEA = EASE_OUT_CUBIC;
const int EASED = EASEA - 1;

class ofmTrans {
public:
    static Tween* appear(ofmBaseView* node, std::string type = "zoom", float time = OFM_TAS_TIME, int ease = EASEA);
    static Tween* disAppear(ofmBaseView* node, std::string type = "zoom", float time = OFM_TAS_TIME, int ease = EASED);
    
    // zoom
    static Tween* zoomAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASEA);
    static Tween* zoomDisAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASED);
    
    // fade
    static Tween* fadeAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASEA);
    static Tween* fadeDisAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASED);
    
    // move
    static Tween* moveLeftAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASEA);
    static Tween* moveLeftDisAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASED);
    static Tween* moveRightAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASEA);
    static Tween* moveRightDisAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASED);
    static Tween* moveTopAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASEA);
    static Tween* moveTopDisAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASED);
    static Tween* moveBottomAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASEA);
    static Tween* moveBottomDisAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASED);
    
    // scale
    static Tween* scaleLeftAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASEA);
    static Tween* scaleLeftDisAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASED);
    static Tween* scaleRightAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASEA);
    static Tween* scaleRightDisAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASED);
    static Tween* scaleTopAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASEA);
    static Tween* scaleTopDisAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASED);
    static Tween* scaleBottomAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASEA);
    static Tween* scaleBottomDisAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASED);
    
    // roll
    static Tween* rollLeftAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASEA);
    static Tween* rollLeftDisAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASED);
    static Tween* rollRightAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASEA);
    static Tween* rollRightDisAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASED);
    static Tween* rollTopAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASEA);
    static Tween* rollTopDisAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASED);
    static Tween* rollBottomAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASEA);
    static Tween* rollBottomDisAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASED);
    
    // rotate
    static Tween* rotateAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASEA);
    static Tween* rotateDisAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASED);
    static Tween* scaleRotateAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASEA);
    static Tween* scaleRotateDisAppear(ofmBaseView* node, float time = OFM_TAS_TIME, int ease = EASED);
    
    // none
    static Tween* noneDisAppear(ofmBaseView* node, float time = OFM_TAS_TIME);
    static Tween* noneAppear(ofmBaseView* node, float time = OFM_TAS_TIME);
    
    static int getEaseOutByType(std::string, int);
    
private:
    static Tween* _scaleInView(ofmBaseView* node, float scale, float time = OFM_TAS_TIME, int ease = EASEA);
    static Tween* _scaleOutView(ofmBaseView* node, float scale, float time = OFM_TAS_TIME, int ease = EASEA);
};
