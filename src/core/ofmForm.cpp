#include "ofmFont.h"
#include "ofmForm.h"
#include "ofmTheme.h"

void ofmForm::initTheme() {
    cname = "ofmForm";
    ofmTheme* theme = ofmTheme::instance();
    textColor = ofColor::fromHex(theme->textColor);
}

void ofmForm::draw() {
    ofmComp::draw();

    if (title != "") {
        ofSetColor(textColor);
        float tx, ty;
        if (titleAlign == "top") {
            tx = -width / 2;
            ty = -height / 2 - titleDis;
            ofmFont::instance()->drawText(title, tx, ty, "left");
        } else {
            tx = -width / 2 - titleDis;
            ty = 0;
            ofmFont::instance()->drawText(title, tx, ty, "right");
        }
    }
}
