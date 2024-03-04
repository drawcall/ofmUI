#pragma once

#include "ofEvents.h"
#include "ofGraphics.h"
#include "ofImage.h"
#include "ofPoint.h"
#include "ofmForm.h"

class ofmSwitch : public ofmForm {
public:
    ofmSwitch();
    void draw();
    void destroy();
    void onTouchDown(ofmTouch&);

    ofColor backColor;
    ofColor frontColor;
    ofColor barColor;
    std::string barType = "circle";
    std::string cap = "circle";

protected:
    virtual void _initTheme();
};
