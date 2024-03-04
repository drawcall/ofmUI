#pragma once
#include <string>

#include "ofQuaternion.h"
#include "ofVec3f.h"

class ofmMathUtil {
public:
    static float randomAToB(float, float);
    static float randomAToB(float, float, bool);
    static int randomAToBInt(float, float);
    static float randomFloating(float, float);
    static int randomFloating(float, float, bool);
    static float random(float max = 1);
    static float intercept(float num, int k = 4);
    static float max(float a, float b);
    static float min(float a, float b);
    static float mod(float a, float b);
    static float abs(float a);
    static float strToNum(std::string);
    static std::string toString(float a, int fixed = 3);
    static std::string vec3fToString(ofVec3f& vec, int fixed = 3);
    static std::string quatToString(ofQuaternion& quat, int fixed = 3);
};
