#include <stdio.h>

#include "ofmFont.h"
#include "ofmUtil.h"
#include "ofmTheme.h"

using namespace std;

void ofmFont::load(string path, int fontSize) {
    _getTTFont()->load(path, fontSize);
    ofmUtil::emptyMap(_rects);
    _loaded = true;
}

void ofmFont::drawText(const string& text, float x, float y, string textAlign) {
    if (text == "") return;
    if (!_loaded) cout << "font not _loaded" << endl;

    ofRectangle& rect = _getRect(text);
    float lineHeight = _getTTFont()->getLineHeight();
    float textY = 0;
    float marginTop = ofmTheme::instance()->retinaValue(ofmFont::marginTop);
    
    if (textAlign == "right") {
        textY = y - rect.height / 2 + lineHeight / 2;
        _getTTFont()->drawString(text, x - rect.width, textY + marginTop);
    } else if (textAlign == "left") {
        textY = y;
        _getTTFont()->drawString(text, x, textY + marginTop);
    } else {
        textY = y - rect.height / 2 + lineHeight / 2;
        _getTTFont()->drawString(text, x - rect.width / 2, textY + marginTop);
    }
}

ofRectangle& ofmFont::_getRect(const string& text) {
    if (!ofmUtil::mapHasKey(_rects, text)) {
        ofRectangle rect = _getTTFont()->getStringBoundingBox(text, 0, 0);
        _rects[text] = rect;
    }

    return _rects[text];
}

ofTrueTypeFont* ofmFont::_getTTFont() {
    if (_ttf == NULL) {
        _ttf = new ofTrueTypeFont();
    }

    return _ttf;
}

void ofmFont::destroy() {
    delete _ttf;
    _ttf = NULL;
    ofmUtil::emptyMap(_rects);
}

// ------------------------------------------------------------------
// static public methods
// ------------------------------------------------------------------
ofmFont* ofmFont::_instance = NULL;
map<int, ofmFont*> ofmFont::_fonts;
string ofmFont::_defaultPath = "";
int ofmFont::_defaultFontSize = 1;
float ofmFont::marginTop = 4;

ofmFont* ofmFont::instance() {
    if (_instance == NULL) {
        _instance = new ofmFont();
        _fonts[1] = _instance;
    }

    return _instance;
}

void ofmFont::loadFont(string path, int fontSize) {
    instance()->load(path, fontSize);
    _defaultPath = path;
    _defaultFontSize = fontSize;
}

ofmFont* ofmFont::getInsByFontSize(int fontSize) {
    if (_defaultFontSize == fontSize || fontSize < 12) {
        return instance();
    } else if (ofmUtil::mapHasKey(_fonts, fontSize)) {
        return _fonts[fontSize];
    } else {
        ofmFont* font = new ofmFont();
        font->load(_defaultPath, fontSize);
        _fonts[fontSize] = font;
        return font;
    }
}

void ofmFont::destroyAll() {
    map<int, ofmFont*>::iterator it;
    for (it = _fonts.begin(); it != _fonts.end(); it++) {
        it->second->destroy();
        delete it->second;
        it->second = NULL;
    }

    ofmUtil::emptyMap(_fonts);
    //cout<<_fonts.size()<<endl;
}
