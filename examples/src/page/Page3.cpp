#include "Page3.h"
#include "ofGraphics.h"

using namespace std;

void Page3::setup() {
    addUI();
    ball1.color = ofColor::fromHex(0x00eeff);
    ball2.color = ofColor::fromHex(0x0f1033);
    ball2.color.a = 255 * 0.3;
    ball2.radius = 70;
    ball2.vy = -3;
}

void Page3::addUI() {
    uiLayer = new ofmUILayer();

    ofmLabel* label = new ofmLabel();
    label->text = "Forms Example";
    label->color = ofColor::fromHex(0xFF0000);
    label->setXY("50%", "10%");
    uiLayer->addChild(label);

    // default btn2
    ofmButton* btn1 = new ofmButton();
    btn1->text = "Open Dialog";
    btn1->animateType = "scale";
    btn1->setXY("50%", "35%");
    btn1->width = 500;
    uiLayer->addChild(btn1);
    btn1->id = "btn1";
    ofAddListener(btn1->touchDown, this, &Page3::onBtnTouchDown);

    ofmButton* btn2 = new ofmButton();
    btn2->width = 200;
    btn2->color = ofColor::fromHex(0x99cc22);
    btn2->text = "Drawer";
    btn2->setXY("50%", "70%");
    uiLayer->addChild(btn2);
    btn2->id = "btn2";
    ofAddListener(btn2->touchDown, this, &Page3::onBtnTouchDown);
    dialog = addDialog();

    addUILayer(uiLayer);
}

ofmDialog* Page3::addDialog() {
    ofmDialog* dialog = new ofmDialog();
    dialog->text = "Hello World";
    dialog->hasCloseBtn = true;
    dialog->panelColor = ofColor::fromHex(0xffffff);
    dialog->setXY("50%", "50%");
    dialog->height = 700;
    uiLayer->addChild(dialog);

    // text label
    ofmLabel* label = new ofmLabel();
    label->text = "Form Dialog";
    label->color = ofColor::fromHex(0xccffee);
    label->setXY(0, -300);
    dialog->addChild(label);

    // slider
    ofmSlider* slider1 = new ofmSlider();
    slider1->value = 0.7;
    slider1->title = "Scale Value";
    slider1->hasBar = true;
    slider1->key = "scale";
    slider1->setXY(0, -150);
    dialog->addChild(slider1);

    // slider
    ofmSlider* slider2 = new ofmSlider();
    slider2->title = "Data";
    slider2->key = "data";
    slider2->value = 0.5;
    slider2->hasBar = false;
    slider2->height = 20;
    slider2->setXY(0, -50);
    dialog->addChild(slider2);

    // switch
    ofmSwitch* switchui = new ofmSwitch();
    switchui->barType = "circle";
    switchui->title = "Has Color";
    switchui->titleAlign = "left";
    switchui->key = "color";
    switchui->setXY(0, 50);
    dialog->addChild(switchui);

    // default btn
    float h = dialog->height;
    ofmButton* btn = new ofmButton();
    btn->text = "OK";
    btn->color = ofColor::fromHex(0xff0000);
    btn->setXY(0, h / 2 - 100);
    dialog->addChild(btn);
    ofAddListener(btn->touchDown, this, &Page3::onDialogBtnClick);

    return dialog;
}

void Page3::onDialogBtnClick(ofmTouch& touch) {
    map<string, float> values = dialog->getFormValues();
    ofmEventBus::instance()->emit("updateValues", values);
    dialog->disAppear();
}

void Page3::onBtnTouchDown(ofmTouch& touch) {
    if (touch.id == "btn1") {
        dialog->appear();
    } else if (touch.id == "btn2") {
        ofmEventBus::instance()->emit("appearDrawer");
    }
}

void Page3::update() {
    ofmView::update();
    ball1.update();
    ball2.update();
}

void Page3::draw() {
    ofSetColor(123, 33, 55);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

    ofmView::draw();
    ball1.draw();
    ball2.draw();
}
