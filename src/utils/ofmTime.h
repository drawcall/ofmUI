#pragma once

#include <string>

class ofmTime {
public:
    float now = 0;
    float old = 0;
    float delta = 0;
    float second = 0;

    void update();
};
