#include "Page1.h"
#include "ofGraphics.h"

using namespace std;

void Page1::setup() {
    addUI();
    ball1.color = ofColor::fromHex(0x00eeff);
    ball2.color = ofColor::fromHex(0x0f1033);
    ball2.radius = 70;
    ball2.vy = -3;
}

void Page1::addUI() {
    uiLayer = new ofmUILayer();

    ofmLabel* label = new ofmLabel();
    label->text = "Buttons Example";
    label->color = ofColor::fromHex(0xFF0000);
    label->setXY("50%", "10%");
    uiLayer->addChild(label);

    // default btn3
    ofmButton* btn1 = new ofmButton();
    btn1->text = "Default Btn";
    btn1->animateType = "scale";
    btn1->color = ofColor(0, 255, 0);
    btn1->textColor = ofColor(0, 0, 0);
    btn1->setXY("50%", "30%");
    uiLayer->addChild(btn1);
    btn1->id = "btn1";
    ofAddListener(btn1->touchDown, this, &Page1::onBtnTouchDown);

    ofmButton* btn2 = new ofmButton("images/btn2.png");
    btn2->setXY("50%", "50%");
    uiLayer->addChild(btn2);
    btn2->id = "btn2";
    ofAddListener(btn2->touchDown, this, &Page1::onBtnTouchDown);

    ofmButton* btn3 = new ofmButton();
    btn3->isCircle = true;
    btn3->width = 120;
    btn3->text = "Btn";
    btn3->setXY("50%", "70%");
    uiLayer->addChild(btn3);
    btn3->id = "btn3";
    ofAddListener(btn3->touchDown, this, &Page1::onBtnTouchDown);

    addUILayer(uiLayer);
}

void Page1::onBtnTouchDown(ofmTouch& touch) {
    if (touch.id == "btn1") {
        ofmAlert* alert = ofmAlert::getRootAlert();
        alert->setText("Hello World");
        alert->setXY(ofGetWidth() / 2, ofGetHeight() / 2);
        alert->appear();
    } else if (touch.id == "btn2") {
        float r = ofmMathUtil::randomAToB(10, 300);
        ofmTween::to(&ball1.radius, r, 0, 1, EASE_OUT_BOUNCE);
    } else {
        brotation += 360;
        ofmComp* btn = uiLayer->getCompById(touch.id);
        ofmTween::to(&btn->rotation, brotation, 0, 0.6, EASE_OUT_BACK);
    }
}

void Page1::update() {
    ofmView::update();
    ball1.update();
    ball2.update();
}

void Page1::draw() {
    ofSetColor(255, 255, 11);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

    ofmView::draw();
    ball1.draw();
    ball2.draw();
}
