#pragma once

#include <string>

#include "ofmConstants.h"
#include "ofmForm.h"
#include "ofmTheme.h"

class ofmSlider : public ofmForm {
public:
    ofmSlider();
    void draw();
    void destroy();
    void onTouchDown(ofmTouch&);
    void onTouchMoved(ofmTouch&);
    void onTouchUp(ofmTouch&);

    ofColor backColor;
    ofColor frontColor;
    ofColor barColor;
    std::string barType = "circle";
    float animateAlpha = 0.88;
    bool hasBar = true;

protected:
    virtual void _initTheme();
};
