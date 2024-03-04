#pragma once

#include <map>
#include <string>

class ofmDevice {
public:
    static bool isSimulator;
    static bool isIPhone;
    static bool isAndroid;
    static bool isIPad;
    static std::string detect();
};
