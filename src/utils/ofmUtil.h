#pragma once
#include <map>
#include <string>
#include <vector>

class ofmUtil {
public:
    ///
    template <typename T>
    static std::vector<T>& removeFromVector(std::vector<T>& vec, T val) {
        vec.erase(std::remove(vec.begin(), vec.end(), val), vec.end());
        return vec;
    }
    
    template <typename T>
    static std::vector<T>& removeFromVectorByIndex(std::vector<T>& vec, int index) {
        vec.erase(vec.begin() + index);
        return vec;
    }
    
    template <typename T>
    static std::vector<T>& sliceVector(std::vector<T>& a, int index, std::vector<T>& b) {
        emptyVector<T>(b);
        for (int i = index; i < a.size(); i++) {
            b.emplace_back(a[i]);
        }
        
        return b;
    }
    
    template <typename T>
    static T getRandFromVector(const std::vector<T>& vec) {
        int random = rand() % vec.size();
        return vec[random];
    }
    
    template <typename T>
    static std::vector<T>& emptyVector(std::vector<T>& vec) {
        std::vector<T> v;
        vec.swap(v);
        return vec;
    }
    
    template <typename T>
    static std::vector<T>& destroyElementsFromVector(std::vector<T>& vec) {
        typename std::vector<T>::iterator it;
        for(it = vec.begin(); it != vec.end(); it++) {
            if((*it) != NULL) {
                (*it)->destroy();
                delete (*it);
                (*it) = NULL;
            }
        }
        
        emptyVector(vec);
        return vec;
    }
    
    template <typename keyType, typename valType>
    static std::map<keyType, valType>& emptyMap(std::map<keyType, valType>& map) {
        if (map.size() == 0) return map;
        map.erase(map.begin(), map.end());
        return map;
    }
    
    template <typename keyType, typename T>
    static bool mapHasKey(std::map<keyType, T>& map, keyType type) {
        if (map.size() == 0) return false;
        if (map.find(type) == map.end()) {
            return false;
        } else {
            return true;
        }
    }
    
    template <typename T>
    static std::vector<T>& concatVector(std::vector<T>& a, std::vector<T>& b) {
        a.insert(a.end(), b.begin(), b.end());
        return a;
    }
    
    static bool strInclude(std::string a, std::string b) {
        std::string::size_type idx;
        idx = a.find(b);
        if (idx == std::string::npos )
            return false;
        else
            return true;
    }
};
