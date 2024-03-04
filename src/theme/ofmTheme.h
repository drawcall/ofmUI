#pragma once

#include <map>
#include <memory>
#include <string>

#include "ofImage.h"

// default size 640x1003

class ofmTheme {
public:
    // methods
    void setTheme(std::string);
    void init();
    void retinaValuePtr(float* val);
    float retinaValue(float val);
    int retinaIntValue(int val);
    int retinaFontSize(int);
    void retinaImageSize(ofImage*);
    void retinaImageSize(std::shared_ptr<ofImage>);
    static ofmTheme* instance();

    bool enabledRetina = true;
    float baseScreen = 640;

    int color = 0x1677FF;
    int backColor = 0xd7d7d7;
    int frontColor = 0x1677FF;
    int closeColor = 0x1890ff;
    int barColor = 0x0049ad;
    int textColor = 0x222222;
    int btnTextColor = 0xFFFFFF;
    int panelColor = 0xDDDDDD;
    int drawerColor = 0xFFFFFF;

    // font size
    float fontSize = 24;

    // global round
    float round = 10;

    // button
    float buttonWidth = 300;
    float buttonHeight = 80;
    float circleButtonRadius = 50;

    // slider
    float sliderWidth = 400;
    float sliderHeight = 6;
    float sliderRadius = 26;
    float sliderRound = 0;

    // switch
    float switchWidth = 70;
    float switchHeight = 20;
    float switchRadius = 26;

    // dialog
    float dialogWidth = 550;
    float dialogHeight = 500;
    float dialogHasColose = true;

    // alert
    float alertWidth = 550;
    float alertHeight = 300;
    
    float drawerHeight = 300;

private:
    float _getMinScreenSize();
    float _getScale();
    static ofmTheme* _instance;
};
