#pragma once

#include <string>
#include <vector>

#include "ofEvents.h"
#include "ofmComp.h"
#include "ofmCon.h"
#include "ofmTouch.h"

class ofmUILayer : public ofmCon {
public:
    ofmUILayer();
    void destroy();
    ofmComp* getCompById(std::string);
    bool testChildTouchDown(ofPoint& touch);
    float appWidth;
    float appHeight;

private:
    void _addListener();
    void _onTouchDown(ofTouchEventArgs& args);
    void _onTouchMoved(ofTouchEventArgs& args);
    void _onTouchUp(ofTouchEventArgs& args);
    ofmTouch _touch;
};
