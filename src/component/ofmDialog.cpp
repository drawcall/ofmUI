#include "ofmAnim.h"
#include "ofmDialog.h"
#include "ofmForm.h"
#include "ofmTheme.h"
#include "ofmUtil.h"

using namespace std;

ofmDialog::ofmDialog():ofmPanel() {
}

ofmDialog::ofmDialog(string _path):ofmPanel() {
    setPath(_path);
}

void ofmDialog::setPath(string _path) {
    path = _path;
    _img = new ofImage();
    _img->load(path);
    _img->setAnchorPercent(0.5, 0.5);
    width = _img->getWidth();
    height = _img->getHeight();
}

void ofmDialog::initOnce() {
    ofmTheme* theme = ofmTheme::instance();
    theme->retinaImageSize(_img);
    ofmPanel::initOnce();
}

void ofmDialog::draw() {
    if (path == "") {
        _drawGraphicPanel();
    } else {
        _img->draw(0, 0);
    }
}

void ofmDialog::_initTheme() {
    ofmPanel::_initTheme();
    ofmTheme* theme = ofmTheme::instance();
    width = theme->dialogWidth;
    height = theme->dialogHeight;
}

void ofmDialog::_drawGraphicPanel() {
    ofPushStyle();
    ofEnableAlphaBlending();
    
    panelColor.a = 255 * alpha;
    ofSetColor(panelColor);
    if (round == 0) {
        ofDrawRectangle(-width / 2, -height / 2, width, height);
    } else {
        ofDrawRectRounded(-width / 2, -height / 2, width, height, round);
    }
    
    ofDisableAlphaBlending();
    ofPopStyle();
}

void ofmDialog::_addCloseBtn() {
    ofmPanel::_addCloseBtn();
    if(_closeBtn != NULL) {
        float r = ofmTheme::instance()->circleButtonRadius;
        float dis = r + 4;
        _closeBtn->x = width / 2 - dis;
        _closeBtn->y = -height / 2 + dis;
    }
}


void ofmDialog::destroy() {
    if (_img != NULL) _img->clear();
    delete _img;
    _img = NULL;
    
    ofmPanel::destroy();
}
