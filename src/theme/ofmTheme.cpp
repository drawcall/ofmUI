#include <math.h>

#include "ofmMathUtil.h"
#include "ofmTheme.h"

using namespace std;

ofmTheme* ofmTheme::_instance = NULL;

ofmTheme* ofmTheme::instance() {
    if (_instance == NULL) _instance = new ofmTheme();
    return _instance;
}

void ofmTheme::init() {}

void ofmTheme::setTheme(std::string theme) {
    if (theme == "blue") {
        color = 0x1677FF;
        backColor = 0xd7d7d7;
        frontColor = 0x1677FF;
        closeColor = 0x1890ff;
        barColor = 0x0049ad;
    } else if (theme == "green") {
        color = 0x237804;
        backColor = 0xd7d7d7;
        frontColor = 0x237804;
        closeColor = 0x52c41a;
        barColor = 0x092b00;
    }
}

int ofmTheme::retinaFontSize(int _fontSize) {
    fontSize = (float)_fontSize;
    retinaValuePtr(&fontSize);
    return (int)fontSize;
}

void ofmTheme::retinaImageSize(std::shared_ptr<ofImage> img) {
    if (img == NULL) return;

    float w = retinaValue(img->getWidth());
    float h = retinaValue(img->getHeight());
    img->resize((int)w, (int)h);
}

void ofmTheme::retinaImageSize(ofImage* img) {
    if (img == NULL) return;

    float w = retinaValue(img->getWidth());
    float h = retinaValue(img->getHeight());
    img->resize((int)w, (int)h);
}

void ofmTheme::retinaValuePtr(float* val) {
    float scale = _getScale();
    *val *= scale;
    *val = floor(*val);
}

int ofmTheme::retinaIntValue(int val) {
    float scale = _getScale();
    val *= scale;
    return floor(val);
}

float ofmTheme::retinaValue(float val) {
    float scale = _getScale();
    val *= scale;
    return floor(val);
}

float ofmTheme::_getMinScreenSize() {
    return ofmMathUtil::min(ofGetWidth(), ofGetHeight());
}

// https://developer.apple.com/design/human-interface-guidelines/ios/visual-design/adaptivity-and-layout/
float ofmTheme::_getScale() {
    if (!enabledRetina) return 1.0;

    // [640-1080-1242]

    float size = _getMinScreenSize();
    float scale = 1.0;

    if (size >= 1200)
        scale = 1150.0 / baseScreen;
    else if (size >= 1000)
        scale = 1080.0 / baseScreen;
    else
        scale = 1.0;

    return scale;
}
