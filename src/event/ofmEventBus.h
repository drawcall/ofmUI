#pragma once

#include <functional>
#include <map>
#include <string>
#include <vector>
#include "ofmPageEvent.h"

typedef std::function<void()> ofmEBFuncNone;
typedef std::function<void(float)> ofmEBFuncF;
typedef std::function<void(std::string)> ofmEBFuncStr;
typedef std::function<void(std::map<std::string, float>&)> ofmEBFuncMap;
typedef std::function<void(ofmPageEvent&)> ofmEBFuncPageEvent;

class ofmEventBus {
public:
    void emit(std::string);
    void emit(std::string, float);
    void emit(std::string, std::string);
    void emit(std::string, std::map<std::string, float>);
    void emit(std::string, ofmPageEvent&);
    
    void on(std::string type, ofmEBFuncF listener);
    void on(std::string type, ofmEBFuncNone listener);
    void on(std::string type, ofmEBFuncStr listener);
    void on(std::string type, ofmEBFuncMap listener);
    void on(std::string type, ofmEBFuncPageEvent listener);

    void removeEvent(std::string type);
    void removeEvent(std::string type, ofmEBFuncStr);
    void removeAllEvent(std::string type = "");
    bool has(std::string type);

    static ofmEventBus* instance();

private:
    std::map<std::string, float> _split(std::string, std::string);
    std::map<std::string, std::vector<ofmEBFuncStr> > _listeners;
    static ofmEventBus* _instance;
};
