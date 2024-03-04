#pragma once

#include <string>
#include <vector>

#include "ofmComp.h"
#include "ofmTouch.h"

class ofmCon : public ofmComp {
public:
    virtual void _draw();
    virtual void addChild(ofmComp& ui);
    virtual void removeChild(ofmComp& ui);
    virtual void addChild(ofmComp* ui);
    virtual void removeChild(ofmComp* ui);
    virtual bool hitTest(ofPoint& point);
    virtual bool hitTestSelfAndChild(ofPoint& point);
    virtual void update();
    virtual void resize();
    virtual void destroy();

    virtual void onTouchDown(ofmTouch& point);
    virtual void onTouchMoved(ofmTouch& point);
    virtual void onTouchUp(ofmTouch& point);

    std::vector<ofmComp*> children;
    std::string cname = "ofmCon";

protected:
    void _drawChildren();
    bool _destroyed = false;
};
