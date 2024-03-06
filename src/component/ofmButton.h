#pragma once

#include <memory>
#include <string>

#include "ofmConstants.h"
#include "ofmComp.h"
#include "ofmTheme.h"
#include "ofmTime.h"
#include "ofmTouch.h"

class ofmCon;
class ofmButton : public ofmComp {
public:
    ofmButton();
    ofmButton(std::string);
    virtual void initOnce();
    virtual void draw();
    virtual void update();
    virtual void setPath(std::string);
    void onTouchDown(ofmTouch&);
    void onTouchUp(ofmTouch&);
    void destroy();
    ofImage* getImage();

    float animateAlpha = 0.82;
    float animateScale = 0.92;
    float debounce = 1.05;
    bool isCircle = false;
    std::string animateType = "alpha";

protected:
    virtual void _initTheme();
    virtual void _drawGraphicBtn();
    ofImage* _img = NULL;
    ofmTime _time;
};
