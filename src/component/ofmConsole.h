#pragma once

#include <string>

#include "ofmComp.h"

class ofmConsole : public ofmComp {
public:
    ofmConsole();
    void logs(const std::string&);
    float lineHeight;

    static ofmConsole* instance();
    static void log(const std::string&);
    static void log(const float&);
    static void logFPS();
    static void hide();
    static void setY(float y);

private:
    void _draw();
    std::string _str;
    static ofmConsole* _instance;
};
