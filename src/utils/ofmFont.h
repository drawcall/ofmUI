#pragma once

#include <map>
#include <string>
#include <vector>

#include "ofmConstants.h"

class ofmFont {
public:
    void load(std::string path, int size = 36);
    void drawText(const std::string&, float x = 0, float y = 0,
                  std::string textAlign = "center");
    void destroy();

    static ofmFont* instance();
    static ofmFont* getInsByFontSize(int);
    static void loadFont(std::string path, int size = 36);
    static void destroyAll();
    static float marginTop;

private:
    ofRectangle& _getRect(const std::string& text);
    ofTrueTypeFont* _getTTFont();
    ofTrueTypeFont* _ttf = NULL;
    bool _loaded = false;
    std::map<std::string, ofRectangle> _rects;

    // static props
    static ofmFont* _instance;
    static std::string _defaultPath;
    static int _defaultFontSize;
    static std::map<int, ofmFont*> _fonts;
};
