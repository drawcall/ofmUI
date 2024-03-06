#include "ofmBaseView.h"
#include "ofmMathUtil.h"

bool ofmBaseView::_canRender() {
    if (!_visible) return false;
    if (_alpha < 0.01) return false;
    if (_scale <= 0.01) return false;
    if (_x <= -9999) return false;
    if (_y <= -9999) return false;
    if (_x >= 9999) return false;
    if (_y >= 9999) return false;
    return true;
}

void ofmBaseView::_pushMatrix() {
    if (!(_x == 0 && _y == 0)) ofTranslate(_x, _y);
    if (_scale != 1) ofScale(_scale);
    if (_rotation != 0) ofRotateDeg(_rotation);
}
