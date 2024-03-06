#include "ofmFont.h"
#include "ofmLabel.h"
#include "ofmTheme.h"

using namespace std;

ofmLabel::ofmLabel(std::string _text) {
    text = _text;
    ofmTheme* theme = ofmTheme::instance();
    textColor = ofColor::fromHex(theme->textColor);
}

ofmFont* ofmLabel::loadFont(std::string path, int _fontSize) {
    delete _font;
    _font = NULL;
    _font = new ofmFont();
    _font->load(path, _fontSize);
    fontSize = _fontSize;

    return _font;
}

void ofmLabel::initOnce() {
    ofmComp::initOnce();
    ofmTheme* theme = ofmTheme::instance();
    fontSize = theme->retinaIntValue(fontSize);
    _font = ofmFont::getInsByFontSize(fontSize);
}

void ofmLabel::draw() {
    if (text == "") return;
    if (_font == NULL) cout << "not run initOnce/update function" << endl;
    
    ofPushStyle();
    ofSetColor(textColor);
    _font->drawText(text, 0, 0, textAlign);
    ofPopStyle();
}

void ofmLabel::destroy() {
    _font = NULL;
}
