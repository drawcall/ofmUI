#pragma once

#include "ofmConstants.h"
#include "ofmComp.h"

class ofmImage : public ofmComp {
public:
    ofmImage(std::string);
    void draw();
    void destroy();

protected:
    ofImage* _img;
};
