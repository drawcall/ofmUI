#include "Ball.h"
#include "ofAppRunner.h"

void Ball::update() {
    float d = radius + 10;
    float l = -d;
    float r = ofGetWidth() + d;
    float t = -d;
    float b = ofGetHeight() + d;

    if (x >= r || x <= l) {
        vx *= -1.0;
    }

    if (y >= b || y <= t) {
        vy *= -1.0;
    }

    x += vx;
    y += vy;
}

void Ball::draw() {
    ofSetColor(color);
    ofDrawCircle(x, y, radius);
}
