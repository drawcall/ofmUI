#include "ofmTime.h"
#include "ofmConstants.h"

void ofmTime::update() {
    now = ofGetElapsedTimeMillis();

    if (old == 0) {
        delta = 0;
    } else {
        delta = now - old;
    }

    second += delta / 1000;
    old = now;
}
