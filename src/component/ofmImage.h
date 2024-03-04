#pragma once

#include "ofEvents.h"
#include "ofImage.h"
#include "ofmComp.h"

class ofmImage : public ofmComp {
public:
    ofmImage(std::string);
    void draw();
    void destroy();

protected:
    ofImage* _img;
};
