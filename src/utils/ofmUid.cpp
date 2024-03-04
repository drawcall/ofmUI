#include <map>
#include <string>

#include "ofmUid.h"

using namespace std;

map<string, int> ofmUid::_idsMap;

string ofmUid::id(string type) {
    if (_idsMap.find(type) == _idsMap.end()) {
        _idsMap[type] = 0;
    }

    _idsMap[type]++;
    return type + "_" + to_string(_idsMap[type]);
}
