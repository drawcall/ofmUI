#pragma once

#include <string>
#include <vector>

#include "ofmFont.h"
#include "ofmTheme.h"
#include "ofmTween.h"
#include "ofmUILayer.h"

class ofmUI {
public:
    static void loadFont(std::string path, int size = 24);
    static void update();
    static void init();
    static void draw();
    static void resize();
    static void addUILayer(ofmUILayer *layer);
    static void removeUILayer(ofmUILayer *layer);
    static void destroy();
    static void setTheme(std::string);
    static void enableRetina(bool);

    static std::vector<ofmUILayer *> children;
};
