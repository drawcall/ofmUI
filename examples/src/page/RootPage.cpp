#include "Page1.h"
#include "Page2.h"
#include "Page3.h"
#include "RootPage.h"
#include "ofEvents.h"

using namespace std;

void RootPage::setup() {
    ofmRootView::setup();

    loadFont("ofmui/fonts/Verdana.ttf", 24);
    addMainView(new Page1());
    addUI();
    addListener();
}

void RootPage::addUI() {
    uiLayer = new ofmUILayer();

    // default btn
    int l = 3;
    for (int i = 1; i <= l; i++) {
        ofmButton* btn = new ofmButton();
        btn->id = "btn" + to_string(i);
        btn->text = "PAGE 0" + to_string(i);
        btn->setWH(180, 80);
        btn->round = 16;
        btn->color = ofColor::fromHex(0xff0000);
        float x = (2 * i - 1) * 100 / (2 * l);
        btn->setXY(to_string(x) + "%", "90%");
        uiLayer->addChild(btn);
        btns.push_back(btn);
        ofAddListener(btn->touchDown, this, &RootPage::onBtnTouchDown);
    }
    
    btns[0]->color.setSaturation(100);
    addUILayer(uiLayer);
    addDrawer();
}

void RootPage::addDrawer() {
    drawer = new ofmDrawer();
    drawer->hasCloseBtn = true;
    drawer->setXY("50%", "100%");
    drawer->height = 500;
    drawer->touchClose = true;
    uiLayer->addChild(drawer);

    ofmLabel* label = new ofmLabel();
    label->text = "A drawer panel";
    label->color = ofColor::fromHex(0xccffee);
    label->setXY(0, -450);
    label->fontSize = 20;
    drawer->addChild(label);

    // default btn
    // slider
    ofmSlider* slider1 = new ofmSlider();
    slider1->value = 0.7;
    slider1->title = "Scale Value";
    slider1->hasBar = true;
    slider1->key = "scale";
    slider1->setXY(0, -300);
    drawer->addChild(slider1);

    // slider
    ofmSlider* slider2 = new ofmSlider();
    slider2->title = "Data";
    slider2->key = "data";
    slider2->value = 0.5;
    slider2->hasBar = false;
    slider2->height = 20;
    slider2->setXY(0, -100);
    drawer->addChild(slider2);
}


void RootPage::addListener() {
    ofmEventBus::instance()->on("updateValues", [](map<string, float>& values) {
        cout << "--------------------" << endl;
        for (map<string, float>::iterator it = values.begin();
             it != values.end(); ++it) {
            std::cout << it->first << " " << it->second << endl;
        }
    });
    
    ofmEventBus::instance()->on("appearDrawer", [this]() {
        drawer->appear();
    });
}

void RootPage::onBtnTouchDown(ofmTouch& touch) {
    for(unsigned int i = 0; i < btns.size(); i++) {
        btns[i]->color.setSaturation(255);
    }
    
    if (touch.id == "btn1") {
        navigateTo(new Page1(), "rollRight");
        btns[0]->color.setSaturation(100);
    } else if (touch.id == "btn2") {
        navigateTo(new Page2());
        btns[1]->color.setSaturation(100);
    } else if (touch.id == "btn3") {
        navigateTo(new Page3(), "moveLeft");
        btns[2]->color.setSaturation(100);
    }
}
