#pragma once

#include <string>

#include "ofPoint.h"

class ofmTouch {
public:
    bool isTouched();
    void update();
    void setXY(float, float);
    void copy(ofmTouch&);
    std::string toString();

    ofPoint point;
    std::string id;

    float localX = -100;
    float localY = -100;
};
