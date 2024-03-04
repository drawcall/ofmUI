#pragma once

#include <string>

#include "ofColor.h"
#include "ofGraphics.h"
#include "ofmButton.h"

class ofmCloseButton : public ofmButton {
public:
    ofmCloseButton();
    void draw();

    ofColor frontColor;
    std::string shape = "circle";

protected:
    void _initTheme();
};
