#include <string>
#include <vector>

#include "ofmEventBus.h"
#include "ofmUtil.h"

using namespace std;

const string PARAM_NONE = "[p-none]";
const string PARAM_FLOAT = "[s-f]";
const string PARAM_MAP_FLOAT = "[map-f]";
const string PARAM_PAGE_EVENT = "[page-e]";

ofmEventBus* ofmEventBus::_instance = NULL;

ofmEventBus* ofmEventBus::instance() {
    if (_instance == NULL) _instance = new ofmEventBus();
    return _instance;
}

bool ofmEventBus::has(string type) {
    if (_listeners.find(type) == _listeners.end()) {
        return false;
    } else {
        return true;
    }
}

// ------------------------------------------------------------------
// event emit
// ------------------------------------------------------------------
void ofmEventBus::emit(string type) {
    string str = PARAM_NONE;
    emit(type, str);
}

void ofmEventBus::emit(string type, float num) {
    string str = PARAM_FLOAT + to_string(num);
    emit(type, str);
}

void ofmEventBus::emit(string type, std::map<std::string, float> m) {
    string str = PARAM_MAP_FLOAT;
    for (auto it = m.cbegin(); it != m.cend(); it++) {
        string val = to_string(it->second);
        str += (it->first) + ":" + (val) + "||";
    }
    emit(type, str);
}

void ofmEventBus::emit(string type, ofmPageEvent& pageEvent) {
    string str = PARAM_PAGE_EVENT;
    str += pageEvent.direction + to_string(pageEvent.currIndex);
    emit(type, str);
}

void ofmEventBus::emit(string type, string p) {
    if (!ofmUtil::mapHasKey<string, vector<ofmEBFuncStr> >(_listeners, type)) {
        return;
    }

    vector<ofmEBFuncStr> arr = _listeners[type];
    int i = arr.size() - 1;
    while (i >= 0) {
        (arr[i])(p);
        i--;
    }
}

// ------------------------------------------------------------------
// event on
// ------------------------------------------------------------------
void ofmEventBus::on(std::string type, ofmEBFuncNone listener) {
    on(type, [this, listener](string str) {
        string sign = PARAM_NONE;
        if (ofmUtil::strInclude(str, sign)) {
            listener();
        }
    });
}

void ofmEventBus::on(std::string type, ofmEBFuncF listener) {
    on(type, [this, listener](string str) {
        string sign = PARAM_FLOAT;
        if (ofmUtil::strInclude(str, sign)) {
            str = str.replace(str.find(sign), 5, "");
            float val = atof(str.c_str());
            listener(val);
        }
    });
}

void ofmEventBus::on(std::string type, ofmEBFuncMap listener) {
    on(type, [this, listener](string str) {
        string sign = PARAM_MAP_FLOAT;

        if (ofmUtil::strInclude(str, sign)) {
            str = str.replace(str.find(sign), 7, "");
            map<string, float> cmap = _split(str, "||");
            listener(cmap);
        }
    });
}

void ofmEventBus::on(std::string type, ofmEBFuncPageEvent listener) {
    on(type, [this, listener](string str) {
        string sign = PARAM_PAGE_EVENT;

        if (ofmUtil::strInclude(str, sign)) {
            str = str.replace(str.find(sign), 8, "");
            ofmPageEvent pageEvent;
            listener(pageEvent);
        }
    });
}

void ofmEventBus::on(string type, ofmEBFuncStr listener) {
    //removeEvent(type, listener);

    if (!ofmUtil::mapHasKey(_listeners, type)) {
        vector<ofmEBFuncStr> list;
        _listeners[type] = list;
    }
    _listeners[type].emplace_back(listener);
}

// ------------------------------------------------------------------
// event remove
// ------------------------------------------------------------------
void ofmEventBus::removeEvent(string type) {
    if (_listeners.find(type) == _listeners.end()) return;
    _listeners.erase(type);
}

void ofmEventBus::removeEvent(string type, ofmEBFuncStr listener) {
    if (_listeners.find(type) == _listeners.end()) return;
    vector<ofmEBFuncStr> arr = _listeners[type];

    int length = arr.size();
    for (vector<ofmEBFuncStr>::iterator it = arr.begin(); it != arr.end(); it++) {
        if ((*it).target<ofmEBFuncStr>() == listener.target<ofmEBFuncStr>()) {
            if (length == 1) {
                _listeners.erase(type);
            } else {
                arr.erase(it);
            }
            break;
        }
    }
}

void ofmEventBus::removeAllEvent(string type) {
    if (type == "") {
        ofmUtil::emptyMap(_listeners);
    } else {
        _listeners.erase(type);
    }
}

map<string, float> ofmEventBus::_split(string text, string delims) {
    map<string, float> tokens;
    size_t start = text.find_first_not_of(delims), end = 0;

    while ((end = text.find_first_of(delims, start)) != std::string::npos) {
        string s = text.substr(start, end - start);
        size_t s_s = s.find(":");
        string key = s.substr(0, s_s);
        string val = s.substr(s_s + 1);
        tokens[key] = atof(val.c_str());

        start = text.find_first_not_of(delims, end);
    }

    if (start != std::string::npos) {
        string s = text.substr(start);
        size_t s_s = s.find(":");
        string key = s.substr(0, s_s);
        string val = s.substr(s_s + 1);
        tokens[key] = atof(val.c_str());
    }

    return tokens;
}
