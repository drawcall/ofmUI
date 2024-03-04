#pragma once

#include <string>

class ofmRect {
public:
    void set(float, float, float, float);
    void setXYWH(float, float, float, float);
    void setCenterWH(float, float, float, float);
    float getWidth();
    bool inside(float, float);
    std::string toString();

    float left = 0;
    float right = 0;
    float top = 0;
    float bottom = 0;
};
