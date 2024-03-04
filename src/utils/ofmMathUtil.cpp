#include <math.h>

#include "ofmMathUtil.h"

using namespace std;

float ofmMathUtil::randomAToB(float x, float y) {
    float high = max(x, y);
    float low = min(x, y);
    return max(low, (low + ((high - low) * rand() / float(RAND_MAX))) *
                        (1.0f - std::numeric_limits<float>::epsilon()));
}

float ofmMathUtil::randomAToB(float x, float y, bool isInt) {
    float val = randomAToB(x, y);
    if (isInt) {
        return floor(val);
    } else {
        return val;
    }
}

int ofmMathUtil::randomAToBInt(float x, float y) {
    return (int)randomAToB(x, y, true);
}

float ofmMathUtil::randomFloating(float center, float f) {
    return randomAToB(center - f, center + f);
}

int ofmMathUtil::randomFloating(float center, float f, bool isInt) {
    float val = randomFloating(center, f);
    if (isInt) {
        return floor(val);
    } else {
        return val;
    }
}

float ofmMathUtil::random(float a) {
    return (a * rand() / float(RAND_MAX)) *
           (1.0f - std::numeric_limits<float>::epsilon());
}

float ofmMathUtil::intercept(float num, int k) {
    float digits = pow(10, k);
    return floor(num * digits) / digits;
}

float ofmMathUtil::max(float a, float b) {
    return a >= b ? a : b;
}

float ofmMathUtil::min(float a, float b) {
    return a <= b ? a : b;
}

float ofmMathUtil::mod(float a, float b) {
    return b == 0 ? a : fmod(a, b);
}

float ofmMathUtil::abs(float a) {
    return a >= 0 ? a : -a;
}

string ofmMathUtil::toString(float val, int fixed) {
    string str = std::to_string(val);
    return str.substr(0, str.find(".") + fixed + 1);
}

string ofmMathUtil::vec3fToString(ofVec3f& vec, int fixed) {
    string sx = " x:" + toString(vec.x, fixed);
    string sy = " y:" + toString(vec.y, fixed);
    string sz = " z:" + toString(vec.z, fixed);
    return sx + sy + sz;
}

string ofmMathUtil::quatToString(ofQuaternion& quat, int fixed) {
    ofVec3f angle = quat.getEuler();
    return vec3fToString(angle);
}

float ofmMathUtil::strToNum(string str) {
    str = str.replace(str.find("%"), 1, "");
    return stof(str);
}
