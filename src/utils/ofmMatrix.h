#pragma once

#include "ofVec3f.h"
#include <string>

class ofmMatrix {
public:
    void identity();
    void append(float a = 1,
                float b = 0,
                float c = 0,
                float d = 1,
                float tx = 0,
                float ty = 0);
    void appendMatrix(ofmMatrix&);
    void appendTransform(float x, float y, float sx, float sy,
                         float r, float regX, float regY);
    std::string toString();
    
    float a = 1;
    float b = 0;
    float c = 0;
    float d = 1;
    float tx = 0;
    float ty = 0;
};
