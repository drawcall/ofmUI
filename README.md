# __ofmUI__

__ofmUI__ is a lightweight mobile UI library specifically crafted for the _openFrameworks_ mobile framework. Recognizing the relative deficiency of UI components in _openFrameworks_ mobile, which somewhat hinders developers' ability to construct complex applications, I decided to create __ofmUI__. 

It offers approximately 20 diverse UI components, including `ofmView`, `ofmPanel`, `ofmImage`, `ofmDialog`, among others, to cater to a wide range of interface design requirements. Furthermore, __ofmUI__ is equipped with animation tools like `ofmTween` and `ofmTransition`, enhancing the vibrancy and dynamism of the UI. To improve intra-application communication, __ofmUI__ also integrates event communication tools like `ofmEventBus` and `ofmEvent`, ensuring seamless collaboration among components.

Moreover, it is __cross-platform__, meaning you don't have to rack your brain trying to invoke `native` UI within your project. By using it, you can maintain consistent presentation across _iOS_ and _Android_ without having to deal with more complex `native` interactions. Since it sits on the same display layer as your other elements, it significantly simplifies the development process, leading to improved efficiency and enhanced user experience.

![img](https://github.com/drawcall/ofmUI/blob/main/preview.gif?raw=true)

## Features
- More than 20 kinds of UI components
- ofmView page-level component
- Various page view switching animations
- Form related components
- Easily set themes, fonts, etc.
- _ofmTween_ and _ofmTransition_ animation tools

## Installation
To use __ofmUI__, first you need to download [openFrameworks-IOS](https://openframeworks.cc/download/) or [openFrameworks-Android](https://openframeworks.cc/download/).

To get a copy of the repository you can download the source from [http://github.com/drawcall/ofmUI](http://github.com/drawcall/ofmUI) or, alternatively, you can use git clone:

git clone `git://github.com/drawcall/ofmUI.git`.   
The addon should sit in `openFrameworks/addons/ofmUI/`.

To run the examples, import them into the project generator, create a new project, and open the project file in your IDE.

## Useage

Include main file
```c++
#include "ofmMain.h"
```

Add and set component functions

```c++
// dialog ui
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
ofmSlider* slider = new ofmSlider();
slider->value = 0.7;
slider->title = "Scale Value";
slider->hasBar = true;
slider->key = "scale";
slider->setXY(0, -150);
dialog->addChild(slider);
```

Develop business logic related to pages
```c++
// root page
void RootPage::setup() {
    ofmRootView::setup();
    loadFont("ofmui/fonts/Verdana.ttf", 24);
    addMainView(new Page1());
    addListener();
}

void RootPage::onBtnTouchDown(ofmTouch& touch) {
    if (touch.id == "btn1") {
        navigateTo(new Page1(), "rollRight");
    } else if (touch.id == "btn2") {
        navigateTo(new Page2());
    } else if (touch.id == "btn3") {
        navigateTo(new Page3(), "moveLeft");
    }
}

// child page
class Page1 : public ofmView {...
```

Event dispatch related
```c++
void RootPage::addListener() {
  ofmEventBus::instance()->on("UpdateValues", [](map<string, float>& values) {
      cout << "--------------------" << endl;
      for (map<string, float>::iterator it = values.begin();
          it != values.end(); ++it) {
          std::cout << it->first << " " << it->second << endl;
      }
  });
  ofmEventBus::instance()->emit("Hello");
}
```

How to set theme
```c++
ofmTheme::instance()->setTheme("green");
ofmTheme::instance()->color = 0x1677FF;
// The attributes are as follows
int color = 0x1677FF;
int backColor = 0xd7d7d7;
int frontColor = 0x1677FF;
int closeColor = 0x1890ff;
int barColor = 0x0049ad;
int textColor = 0x222222;
int btnTextColor = 0xFFFFFF;
int panelColor = 0xDDDDDD;
int drawerColor = 0xFFFFFF;
// font size
float fontSize = 24;
// global round
float round = 10;
// button
float buttonWidth = 300;
float buttonHeight = 80;
```

Here's a simple example of using animation.

```c++
// tween
ofmTween::to(&btn->rotation, 180, 0, 0.6, EASE_OUT_BACK);
ofmTween::to(&ball.radius, r, 0, 1, EASE_OUT_BOUNCE);
// transition
ofmTrans::fadeAppear(&ball, 0.5, EASE_OUT);
```

For more examples please see [here](./examples/).

## Details

Here is an overview list of the main components. If you need to understand the detailed usage methods and example codes of these components, please refer to the provided example files or feel free to contact me.

- Page components
  - ofmRootView
  - ofmView

- General components
  - ofmLabel
  - ofmButton
  - ofmImage
  - ofmCloseButton
  - ofmDialog
  - ofmAlert
  - ofmDrawer

- Container components
  - ofmCon
  - ofmPanel
  - ofmUILayer
  - ofmScroll

- Form components
  - ofmForm
  - ofmSlider
  - ofmSwitch

- Logger components
  - ofmConsole

- Event tools
  - ofmEventBus
  - ofmPageEvent
  - ofmTouch

- Event tools
  - ofmEventBus
  - ofmPageEvent
  - ofmTouch

- Animation tools
  - ofmTween
  - ofmTrans
  - ofmAnim
  - TweenFunctions

- Theme settings
  - ofmTheme

## Questions & Feedback

Questions, feedback, feature requests, and improvement suggestions are all warmly welcomed. Before sending me an email, please open an issue or join the conversation in the openFrameworks thread.

If you enjoy using ofmUI, please consider starring the repository or sharing it with your friends. It will greatly motivate me to continue iterating and improving. If you have created something using ofmUI and would like to share it, please let me know, and I will add it to the gallery.

## License
ofmUI is released under the MIT License. http://www.opensource.org/licenses/mit-license