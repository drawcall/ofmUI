#include "ofmMathUtil.h"
#include "ofmSlider.h"

ofmSlider::ofmSlider() {
    _initTheme();
    enabledTouch = true;
    value = 0.5;
    key = "slider";
}

void ofmSlider::_initTheme() {
    ofmForm::initTheme();
    ofmTheme* theme = ofmTheme::instance();
    width = theme->sliderWidth;
    height = theme->sliderHeight;
    radius = theme->sliderRadius;
    backColor = ofColor::fromHex(theme->backColor);
    frontColor = ofColor::fromHex(theme->frontColor);
    barColor = ofColor::fromHex(theme->barColor);
}

void ofmSlider::draw() {
    ofPushStyle();
    ofSetColor(backColor);

    float top = -height / 2;
    float left = -width / 2;
    if (round == 0) {
        ofDrawRectangle(left, top, width, height);
        ofSetColor(frontColor);
        ofDrawRectangle(left, top, width * value, height);
    } else {
        ofDrawRectRounded(left, top, width, height, round);
        ofSetColor(frontColor);
        ofDrawRectRounded(left, top, width * value, height, round);
    }

    // drawing bar
    if (hasBar) {
        ofSetColor(barColor);
        float barx = left + value * width;
        float bary = 0;
        float r = radius == 0 ? (height + 12) / 2 : radius;

        if (barType == "circle") {
            ofDrawCircle(barx, bary, r);
        } else {
            ofDrawRectangle(barx - r, bary - r, r * 2 + 10, r * 2);
        }
    }

    ofmForm::draw();
    ofPopStyle();
}

void ofmSlider::onTouchDown(ofmTouch& touch) {
    ofmComp::onTouchDown(touch);
    onTouchMoved(touch);
}

void ofmSlider::onTouchUp(ofmTouch& touch) {
    ofmComp::onTouchUp(touch);
}

void ofmSlider::onTouchMoved(ofmTouch& touch) {
    ofmComp::onTouchMoved(touch);
    value = (_touch.localX - rect.left) / rect.getWidth();
    value = ofmMathUtil::max(0, value);
    value = ofmMathUtil::min(1, value);
    ofNotifyEvent(valueChange, value, this);
}

void ofmSlider::destroy() {}
