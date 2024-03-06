#include "ofmAlert.h"
#include "ofmTheme.h"

using namespace std;

ofmAlert::ofmAlert() : ofmDialog() {
    _initTheme();
    hasCloseBtn = false;
}

ofmAlert::ofmAlert(std::string path) : ofmDialog(path) {
    _initTheme();
    hasCloseBtn = false;
}

void ofmAlert::_addTitle() {
    title = new ofmLabel();
    title->text = text;
    title->y = -50;
    title->color = textColor;
    addChild(title);
}

void ofmAlert::setText(string text) {
    title->text = text;
}

void ofmAlert::_initTheme() {
    ofmTheme* theme = ofmTheme::instance();
    ofmDialog::_initTheme();
    width = theme->alertWidth;
    height = theme->alertHeight;
    textColor = ofColor::fromHex(theme->textColor);
}

void ofmAlert::initOnce() {
    ofmDialog::initOnce();
    ofmTheme::instance()->retinaValuePtr(&this->btnBottom);
    _addTitle();
    _addBtn();
}

void ofmAlert::_addBtn() {
    btn = new ofmButton();
    btn->color = closeColor;
    btn->text = "OK";
    btn->width = 350;
    btn->y = height / 2 - btnBottom;
    addChild(btn);
    ofAddListener(btn->touchDown, this, &ofmAlert::_onClose);
}

void ofmAlert::destroy() {
    ofRemoveListener(btn->touchDown, this, &ofmAlert::_onClose);
    ofmDialog::destroy();
}

void ofmAlert::_onClose(ofmTouch& touch) {
    disAppear();
}

ofmAlert* ofmAlert::_rootAlert = NULL;

ofmAlert* ofmAlert::getRootAlert() {
    if (_rootAlert == NULL) {
        _rootAlert = new ofmAlert();
    }

    return _rootAlert;
}
