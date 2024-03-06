#pragma once

#include <string>
#include <vector>

#include "ofmConstants.h"
#include "ofmBaseView.h"
#include "ofmTrans.h"
#include "ofmTween.h"
#include "ofmUILayer.h"

class ofmView : public ofmBaseView {
public:
    // functional public method
    virtual void start();
    virtual void stop();
    virtual void addUILayer(ofmUILayer& layer);
    virtual void addUILayer(ofmUILayer* layer);
    virtual void removeUILayer(ofmUILayer& layer);
    virtual void removeUILayer(ofmUILayer* layer);

    // default public method
    virtual void setup();
    virtual void update();
    virtual void draw();
    virtual void resize();
    virtual void destroy();
    virtual void touchDown(ofTouchEventArgs& touch);
    virtual void touchMoved(ofTouchEventArgs& touch);
    virtual void touchUp(ofTouchEventArgs& touch);
    virtual void touchDoubleTap(ofTouchEventArgs& touch);
    virtual void touchCancelled(ofTouchEventArgs& touch);

    // private-public methods
    void _setup();
    void _update();
    void _draw();
    void _resize();
    void _destroy();
    Tween* _appear(std::string type = "zoom", float time = 0.65,
                   int ease = EASEA);
    Tween* _disAppear(std::string type = "none", float time = 0.55,
                      int ease = EASED);

    bool starting = false;
    bool uiTouching = false;
    bool enabledUITouchCheck = false;
    std::string cname = "ofmView";

protected:
    void _drawUI();
    void _updateUI();
    void _resizeUI();
    void _destroyUI();
    std::vector<ofmUILayer*> _layers;

private:
    void _onDisAppearComplete(float* arg);
    bool _appeared = false;
};
