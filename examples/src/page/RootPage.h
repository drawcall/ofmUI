#pragma once

#include "ofmMain.h"

class RootPage: public ofmRootView {
public:
    void setup();
    void addUI();
    void addDrawer();
    void addListener();
    void onBtnTouchDown(ofmTouch&);
    
    ofmUILayer* uiLayer;
    ofmDrawer* drawer;
    std::vector<ofmButton*> btns;
};
