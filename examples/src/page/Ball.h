#pragma once

#include "ofColor.h"
#include "ofmMain.h"

class Ball {
public:
    void update();
    void draw();

    float x = 300;
    float y = 300;
    float radius = 200;
    float vx = 2.5;
    float vy = 2.5;

    ofColor color;
};
