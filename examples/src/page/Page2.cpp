#include "Page2.h"
#include "ofGraphics.h"

using namespace std;

void Page2::setup() {
    addUI();
    ball1.color = ofColor::fromHex(0x00eeff);
    ball2.color = ofColor::fromHex(0x0f1033);
    ball2.radius = 70;
    ball2.vy = -3;
}

void Page2::addUI() {
    uiLayer = new ofmUILayer();

    ofmLabel* label = new ofmLabel();
    label->text = "Alert Example";
    label->fontSize = 32;
    label->color = ofColor::fromHex(0xFF0000);
    label->setXY("50%", "10%");
    uiLayer->addChild(label);
    ofmEventBus::instance()->on("changeTitle",
                                [label](string str) { label->text = str; });

    // default btn2
    ofmButton* btn1 = new ofmButton();
    btn1->text = "Open Dialog";
    btn1->animateType = "scale";
    btn1->setXY("50%", "35%");
    btn1->width = 500;
    uiLayer->addChild(btn1);
    btn1->id = "btn1";
    ofAddListener(btn1->touchDown, this, &Page2::onBtnTouchDown);

    ofmButton* btn2 = new ofmButton();
    btn2->isCircle = true;
    btn2->color = ofColor::fromHex(0x333333);
    btn2->width = 200;
    btn2->text = "Btn";
    btn2->setXY("50%", "70%");
    uiLayer->addChild(btn2);
    btn2->id = "btn2";
    ofAddListener(btn2->touchDown, this, &Page2::onBtnTouchDown);
    addDialog();
    addAlert();

    addUILayer(uiLayer);
}

void Page2::addDialog() {
    dialog = new ofmDialog();
    dialog->text = "Hello World";
    dialog->hasCloseBtn = true;
    dialog->setXY("50%", "50%");
    uiLayer->addChild(dialog);

    ofmLabel* label = new ofmLabel();
    label->text = "Change Title";
    label->color = ofColor::fromHex(0xccffee);
    label->setXY(0, -200);
    label->fontSize = 30;
    dialog->addChild(label);

    // default btn
    float w = dialog->width;
    float h = dialog->height;
    ofmButton* btn = new ofmButton();
    btn->text = "OK";
    btn->color = ofColor::fromHex(0xff0000);
    btn->setXY(0, h / 2 - 100);
    dialog->addChild(btn);
    ofAddListener(btn->touchDown, this, &Page2::onDialogBtnClick);
}

void Page2::addAlert() {
    ofmAlert* alert = new ofmAlert();
    alert->text = "Hello World";
    alert->id = "alert-01";
    alert->setXY(ofGetWidth() / 2, ofGetHeight() / 2);
    uiLayer->addChild(alert);
}

void Page2::onDialogBtnClick(ofmTouch& touch) {
    ofmEventBus::instance()->emit("changeTitle", "change title");
}

void Page2::onBtnTouchDown(ofmTouch& touch) {
    if (touch.id == "btn1") {
        dialog->appear();
    } else if (touch.id == "btn2") {
        ofmAlert* alert = (ofmAlert*)uiLayer->getCompById("alert-01");
        alert->appear("rotate", 0.65);
    } else {
        brotation += 360;
        ofmComp* btn = uiLayer->getCompById(touch.id);
        ofmTween::to(&btn->rotation, brotation, 0, 0.6, EASE_OUT_BACK);
    }
}

void Page2::update() {
    ofmView::update();
    ball1.update();
    ball2.update();
    ofmConsole::logFPS();
}

void Page2::draw() {
    ofSetColor(0, 255, 125);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

    ofmView::draw();
    ball1.draw();
    ball2.draw();
}

void Page2::destroy() {
    ofmView::destroy();
    ofmEventBus::instance()->removeAllEvent("changeTitle");
}
