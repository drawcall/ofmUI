#include "ofmImage.h"

ofmImage::ofmImage(std::string _path) {
    path = _path;
    _img = new ofImage();
    _img->load(path);
    _img->setAnchorPercent(0.5, 0.5);
}

void ofmImage::draw() {
    ofSetColor(255, 255, 255, 255 * alpha);
    _img->draw(0, 0);
}

void ofmImage::destroy() {
    _img->clear();
    delete _img;
    _img = NULL;
}
