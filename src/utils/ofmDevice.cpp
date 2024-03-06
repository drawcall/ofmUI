#include <iostream>
#include "ofmConstants.h"
#include "ofmDevice.h"

using namespace std;

bool ofmDevice::isIPad = false;
bool ofmDevice::isIPhone = false;
bool ofmDevice::isAndroid = false;
bool ofmDevice::isSimulator = false;

string ofmDevice::detect() {
    string result = "Know";
//#if TARGET_OS_SIMULATOR || TARGET_OS_IPHONE_SIMULATOR || TARGET_IPHONE_SIMULATOR
//    isSimulator = true;
//    result = "Simulator";
//#elif TARGET_OS_IPHONE
//    isIPhone = true;
//    result = "IPhone";
//#elif TARGET_ANDROID
//    isAndroid = true;
//    result = "Android";
//#endif
    
    isIPhone = true;
    result = "IPhone";
    return result;
}
