#pragma once

#include "Ball.h"
#include "ofmMain.h"
#include "ofmView.h"

class Page3 : public ofmView {
public:
    void setup();
    void update();
    void addUI();
    void draw();
    ofmDialog* addDialog();
    void onBtnTouchDown(ofmTouch&);
    void onDialogBtnClick(ofmTouch& touch);

    ofmUILayer* uiLayer;
    ofmDialog* dialog;
    Ball ball1;
    Ball ball2;
    float brotation = 0;
};
