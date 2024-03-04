#include "ofmData.h"

ofmData::ofmData() {}
ofmData::~ofmData() {}

void ofmData::reset() {
    index = 0;
    open = false;
    mark = "";
}

void ofmData::destroy() {
    //~Data();
    reset();
}
