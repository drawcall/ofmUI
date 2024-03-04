#pragma once

#include <string>

#include "ofPoint.h"
#include "ofmMatrix.h"

class ofmBaseView {
public:
    float _alpha = 1;
    float _x = 0;
    float _y = 0;
    float _scale = 1;
    float _rotation = 0;
    bool _visible = true;
    std::string id = "";

    virtual bool _canRender();
    virtual void _pushMatrix();
};
