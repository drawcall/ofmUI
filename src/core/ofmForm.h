#pragma once

#include <string>

#include "ofEvents.h"
#include "ofmComp.h"

class ofmForm : public ofmComp {
public:
    virtual void draw();
    virtual void initTheme();

    ofEvent<float> valueChange;
    std::string key = "";
    std::string title = "";
    std::string titleAlign = "top";
    float titleDis = 50;
    float value = 0;
};
