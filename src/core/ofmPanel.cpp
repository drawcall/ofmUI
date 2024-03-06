#include "ofmPanel.h"
#include "ofmForm.h"
#include "ofmTheme.h"
#include "ofmUtil.h"

using namespace std;

ofmPanel::ofmPanel() {
    _initTheme();
    _hide();
}

void ofmPanel::_initTheme() {
    ofmTheme* theme = ofmTheme::instance();
    width = theme->dialogWidth;
    height = theme->dialogHeight;
    round = theme->round;
    panelColor = ofColor::fromHex(theme->panelColor);
    closeColor = ofColor::fromHex(theme->closeColor);
}

void ofmPanel::initOnce() {
    _addCloseBtn();
    ofmTheme* theme = ofmTheme::instance();
    ofmComp::initOnce();

    for (vector<ofmComp*>::iterator it = children.begin(); it != children.end();
         it++) {
        ofmComp* comp = *it;
        theme->retinaValuePtr(&comp->x);
        theme->retinaValuePtr(&comp->y);
    }
}

map<string, float> ofmPanel::getFormValues() {
    ofmUtil::emptyMap(values);
    for (vector<ofmComp*>::iterator it = children.begin(); it != children.end();
         it++) {
        if ((*it)->cname == "ofmForm") {
            ofmForm* comp = (ofmForm*)(*it);
            values[comp->key] = comp->value;
        }
    }

    return values;
}

void ofmPanel::_addCloseBtn() {
    if (hasCloseBtn) {
        float r = ofmTheme::instance()->circleButtonRadius;
        float dis = r + 4;
        _closeBtn = new ofmCloseButton();
        _closeBtn->color = closeColor;
        _closeBtn->width = r;
        _closeBtn->x = width / 2 - dis;
        _closeBtn->y = -height / 2 + dis;
        addChild(_closeBtn);
        ofAddListener(_closeBtn->touchDown, this, &ofmPanel::_onClose);
    }
}

void ofmPanel::_show() {
    visible = true;
    _appeared = true;
    _oldX = x;
    _oldY = y;
}

void ofmPanel::_hide() {
    visible = false;
    _appeared = false;
    x = _oldX;
    y = _oldY;
}

Tween* ofmPanel::appear(std::string aniType, float time, int ease) {
    if (_appeared) return NULL;
    _show();
    return ofmAnim::appear(this, aniType, time, ease);
}

Tween* ofmPanel::disAppear(std::string aniType, float time, int ease) {
    Tween* tween = ofmAnim::disAppear(this, aniType, time, ease);
    ofmTween::onComplete(tween, this, &ofmPanel::_onDisAppearComplete);
    return tween;
}

Tween* ofmPanel::submitAndDisAppear(std::string aniType, float time, int ease) {
    Tween* tween = ofmAnim::disAppear(this, aniType, time, ease);
    ofmTween::onComplete(tween, this, &ofmPanel::_onSubmit);
    return tween;
}

void ofmPanel::_onClose(ofmTouch& touch) {
    disAppear();
}

void ofmPanel::_onDisAppearComplete(float* arg) {
    ofmUtil::emptyMap(values);
    ofNotifyEvent(close, values, this);
    _hide();
}

void ofmPanel::_onSubmit(float* arg) {
    getFormValues();
    ofNotifyEvent(submit, values, this);
    _hide();
}

void ofmPanel::_removeCloseBtnListener() {
    if (_closeBtn != NULL) ofRemoveListener(_closeBtn->touchDown, this, &ofmPanel::_onClose);
}

void ofmPanel::destroy() {
    _removeCloseBtnListener();
    ofmCon::destroy();
}
