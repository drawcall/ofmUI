#pragma once

#include <string>

class ofmData {
public:
    ofmData();
    ~ofmData();
    void reset();
    void destroy();

    float x = 0;
    float y = 0;
    float time = 0;
    std::string mark;
    bool open = false;
    int index = 0;
    float value = 0;
};
