#pragma once

#include <map>
#include <memory>
#include <string>

#include "ofEvents.h"
#include "ofmCloseButton.h"
#include "ofmCon.h"
#include "ofmTouch.h"
#include "ofmAnim.h"

class ofmPanel : public ofmCon {
public:
    ofmPanel();
    
    virtual Tween* submitAndDisAppear(std::string type = "zoom",
                                      float time = 0.55, int ease = AN_EASED);
    virtual Tween* appear(std::string type = "zoom", float time = 0.65, int ease = AN_EASEA);
    virtual Tween* disAppear(std::string type = "zoom", float time = 0.55, int ease = AN_EASED);
    
    virtual void initOnce();
    virtual void destroy();
    virtual std::map<std::string, float> getFormValues();

    bool hasCloseBtn = false;
    ofColor panelColor;
    ofColor closeColor;
    ofEvent<std::map<std::string, float> > submit;
    ofEvent<std::map<std::string, float> > close;
    std::map<std::string, float> values;

protected:
    virtual void _show();
    virtual void _hide();
    virtual void _initTheme();
    virtual void _addCloseBtn();
    virtual void _onSubmit(float* arg);
    virtual void _onDisAppearComplete(float* arg);
    virtual void _onClose(ofmTouch&);
    virtual void _removeCloseBtnListener();
    
    ofmCloseButton* _closeBtn = NULL;
    bool _appeared = false;
    float _oldX = 0;
    float _oldY = 0;
};
