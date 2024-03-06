#pragma once

#include <string>

#include "ofmConstants.h"
#include "ofmComp.h"
#include "ofmFont.h"

class ofmLabel : public ofmComp {
public:
    ofmLabel(std::string = "");
    void draw();
    void initOnce();
    void destroy();
    ofmFont* loadFont(std::string, int);

    int fontSize = 1;
    std::string textAlign = "center";

private:
    ofmFont* _font;
};
