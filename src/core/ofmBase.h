#pragma once

#include <string>

#include "ofPoint.h"
#include "ofmMatrix.h"

class ofmBase {
public:
    float alpha = 1;
    float x = 0;
    float y = 0;
    float scale = 1;
    float rotation = 0;
    float reg = 0.5;
    bool visible = true;
    ofmMatrix matrix;

    std::string cname = "ofmBase";
    std::string id = "";

    virtual void setXY(float, float);
    virtual void setXY(std::string, std::string = "");
    virtual bool canRender();
    virtual void update();
    virtual void resize();
    virtual void draw();
    virtual void pushMatrix();
    virtual void destroy();

    virtual void _draw();
};
