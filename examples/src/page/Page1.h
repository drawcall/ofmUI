#pragma once

#include "Ball.h"
#include "ofmMain.h"
#include "ofmView.h"

class Page1 : public ofmView {
public:
    void setup();
    void update();
    void addUI();
    void draw();
    void onBtnTouchDown(ofmTouch&);

    ofmUILayer* uiLayer;
    Ball ball1;
    Ball ball2;
    float brotation = 0;
};
