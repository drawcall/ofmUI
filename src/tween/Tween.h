#pragma once
#include "TweenSelector.h"
#include "TweenEvent.h"

class Tween {
public:
    
    Tween() {};
    Tween(float* a_property, float a_begin, float a_end, int a_delay, int a_duration, int a_easeType, float a_p=0, float a_a=0);
    Tween(float* a_property, int a_millis, float a_begin, float a_end, float a_delay, float a_duration, int a_easeType, float a_p=0, float a_a=0);
    
    void update(int a_millis);
    void remove();
    bool complete();
    bool running();
    void pause();
    void resume(int a_millis);
    void toggle(int a_millis);
    void reset(int a_millis);
    
    float* getProperty();
    float getPropertyValue();
    float getPropertyPct();
    void updateProperty();
    float getTimePct();
    void setTimePct(float a_pct, int a_millis = 0);
    void setRepeat( int a_repeat, bool a_pingPong=false );
    
    unsigned int eventID;
    
    
private:
    void _setup(float* a_property, float a_begin, float a_end, float a_delay, float a_duration, int a_easeType, float a_p, float a_a);
    
    int _startTime;
    float _time, _duration, _delay;
    float _change, _begin, _end;
    float _initBegin, _initEnd;
    
    float _a, _p;
    float *_propAdd;
    int _easeType;
    
    int _repeatTotal;
    int _repeatCount;
    bool _pingPong;
    int _dir;
    
    bool _isComplete;
    bool _isRunning;
    bool _useSeconds;
};
