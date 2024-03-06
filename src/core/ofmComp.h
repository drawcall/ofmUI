#pragma once

#include <string>

#include "ofmConstants.h"
#include "ofmBase.h"
#include "ofmRect.h"
#include "ofmTouch.h"
#include "ofmData.h"

class ofmCon;

class ofmComp : public ofmBase {
public:
    // col
    float width = 200;
    float height = 80;
    float round = 0;
    float radius = 0;
    ofColor color;
    ofColor textColor;
    ofmRect rect;
    ofmData data;
    
    std::string text;
    std::string path;

    bool enabledRetina = true;
    bool enabledTouch = false;
    bool touching = false;
    ofmCon* parent = NULL;

    ofEvent<ofmTouch> touchDown;
    ofEvent<ofmTouch> touchMove;
    ofEvent<ofmTouch> touchUp;

    std::string cname = "ofmComp";

    virtual void setWH(float, float);
    virtual void setWH(std::string, std::string = "");
    virtual void update();
    virtual void destroy();
    virtual void initOnce();

    virtual void onTouchDown(ofmTouch& point);
    virtual void onTouchMoved(ofmTouch& point);
    virtual void onTouchUp(ofmTouch& point);
    virtual bool hitTest(ofPoint& point);
    virtual bool hitTestSelfAndChild(ofPoint& point);
    virtual void _draw();

protected:
    virtual void _updateMatrix();
    virtual void _updateTouchPoint(ofPoint& point);
    bool _inited = false;
    ofmTouch _touch;
};
