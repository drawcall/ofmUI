#pragma once

#include <string>

#include "ofPoint.h"

class ofmPageEvent {
public:
    int prevIndex = -1;
    int currIndex = -1;
    std::string direction = "next";
};
