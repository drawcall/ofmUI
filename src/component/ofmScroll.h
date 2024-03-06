#pragma once

#include <map>
#include <memory>
#include <string>

#include "ofmConstants.h"
#include "ofmCloseButton.h"
#include "ofmPanel.h"

class ofmScroll : public ofmCon {
public:
    ofmScroll(float w, float h);
    virtual void addChild(ofmComp& ui);
    virtual void removeChild(ofmComp& ui);
    virtual void addChild(ofmComp* ui);
    virtual void removeChild(ofmComp* ui);
    virtual void setContentHeight(float);
    
    virtual void onTouchDown(ofmTouch&);
    virtual void onTouchMoved(ofmTouch&);
    virtual void onTouchUp(ofmTouch&);
    
    virtual void draw();
    void update();
    virtual void destroy();
    bool debug = false;

protected:
    void _draw();
    virtual void _clear();
    virtual void _initTheme();
    virtual void _judgeBoundary();
    
    ofFbo _fbo;
    ofPoint _point;
    ofmCon* _con;
    float dis = 0;
    float _contentHeight = 0;
};
