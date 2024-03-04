#pragma once

#include <map>
#include <string>

#include "ofPoint.h"
#include "ofmPanel.h"

class ofmDrawer : public ofmPanel {
public:
    ofmDrawer();
    virtual Tween* submitAndDisAppear(float time = 0.5,
                                      int ease = EASE_OUT_QUAD - 1);
    virtual Tween* appear(float time = 0.65, int ease = EASE_IN_OUT_QUAD);
    virtual Tween* disAppear(float time = 0.5, int ease = EASE_OUT_QUAD - 1);
    virtual void onTouchDown(ofmTouch& touch);
    virtual void draw();
    virtual void destroy();
    virtual void initOnce();
    bool touchClose = false;

protected:
    virtual void _initTheme();
    virtual void _onClose(ofmTouch& touch);
    virtual void _addCloseBtn();

private:
    bool _fakeHitTest(ofPoint& point);
};
