#pragma once

#include <cstdarg>
#include <string>

#include "ofEvents.h"
#include "ofGraphics.h"
#include "ofmConsole.h"
#include "ofmTrans.h"
#include "ofmView.h"

class ofmRootView : public ofmView {
public:
    virtual void setup();
    virtual void draw();
    virtual void update();
    virtual void resize();
    virtual void destroy();

    // functional public method
    virtual void drawRoot(){};
    virtual void addMainView(ofmView* view);
    virtual void addChild(ofmView* view);
    virtual void removeChild(ofmView* view);
    virtual void navigateTo(ofmView* view, std::string type = "zoom",
                            float time = 0.6, int ease = EASEA);
    ofmView* getCurrentView();

    // init method
    void loadFont(std::string path, int size = 32);
    void enableRetina(bool);
    void setTheme(std::string);
    void addUILayer(ofmUILayer* layer);

    ofEvent<ofmView*> viewAppeared;
    std::vector<ofmView*> children;
    bool enableUITouchDownBlock = false;
    bool enableUITouchMovedBlock = false;

private:
    void _addListener();
    void _removeListener();
    void _onAppearComplete(float*);
    void _onDisAppearComplete(float*);
    void _touchDown(ofTouchEventArgs& touch);
    void _touchMoved(ofTouchEventArgs& touch);
    void _touchUp(ofTouchEventArgs& touch);
    void _touchDoubleTap(ofTouchEventArgs& touch);
    void _touchCancelled(ofTouchEventArgs& touch);
    void _addRootAlert(ofmUILayer* layer);
    void _addConsole(ofmUILayer* layer);
    bool _isUILayersBlock(ofTouchEventArgs& touch);

    bool _navigating = false;
    ofPoint _touchPoint;
    ofmView* _currView = NULL;
    ofmView* _prevView = NULL;
};
