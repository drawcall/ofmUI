#pragma once

#include <map>
#include <memory>
#include <string>

#include "ofEvents.h"
#include "ofImage.h"
#include "ofmCloseButton.h"
#include "ofmPanel.h"

class ofmDialog : public ofmPanel {
public:
    ofmDialog();
    ofmDialog(std::string);
    virtual void draw();
    virtual void setPath(std::string);
    virtual void initOnce();
    void destroy();
   
    std::string text;
    std::string path;

protected:
    virtual void _initTheme();
    virtual void _addCloseBtn();
    virtual void _drawGraphicPanel();
    ofImage* _img = NULL;
};
