#pragma once

#include <map>
#include <string>

class ofmUid {
public:
    static std::string id(std::string type);

private:
    static std::map<std::string, int> _idsMap;
};
