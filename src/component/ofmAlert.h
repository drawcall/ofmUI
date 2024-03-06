#pragma once

#include <string>

#include "ofmConstants.h"
#include "ofmButton.h"
#include "ofmDialog.h"
#include "ofmLabel.h"

class ofmAlert : public ofmDialog {
public:
    ofmAlert();
    ofmAlert(std::string);
    virtual void initOnce();
    void setText(std::string);
    void destroy();
    static ofmAlert* getRootAlert();

    ofmLabel* title;
    ofmButton* btn;
    float btnBottom = 100;

protected:
    void _addBtn();
    void _addTitle();
    virtual void _initTheme();
    virtual void _onClose(ofmTouch&);
    static ofmAlert* _rootAlert;
};
