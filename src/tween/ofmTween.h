#pragma once

#include "ofmConstants.h"
#include "Tween.h"
#include "TweenEvent.h"
#include "ofmBase.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef struct _tweenParams {
    _tweenParams() {
        bUseSeconds = true;
        duration	= 1.f;
        delay		= 0.f;
    }
    
    _tweenParams( float* a_property, float a_end, int a_delay, int a_duration, int a_easeType=EASE_OUT_SINE) {
        bUseSeconds = false;
        setup( a_property, *a_property, a_end, a_delay, a_duration, a_easeType );
    }
    _tweenParams( float* a_property, float a_begin, float a_end, int a_delay, int a_duration, int a_easeType=EASE_OUT_SINE, float a_p=0, float a_a=0) {
        bUseSeconds = false;
        setup( a_property, a_begin, a_end, a_delay, a_duration, a_easeType, a_p, a_a );
    }
    
    // params for seconds based tween //
    _tweenParams( float* a_property, float a_end, float a_delay, float a_duration, int a_easeType=EASE_OUT_SINE ) {
        bUseSeconds = true;
        setup( a_property, *a_property, a_end, a_delay, a_duration, a_easeType );
    }
    _tweenParams( float* a_property, float a_begin, float a_end, float a_delay, float a_duration, int a_easeType=EASE_OUT_SINE, float a_p=0, float a_a=0 ) {
        bUseSeconds = true;
        setup( a_property, a_begin, a_end, a_delay, a_duration, a_easeType, a_p, a_a );
    }
    
    // setup in frame //
    void setup( float* a_property, float a_begin, float a_end, int a_delay, int a_duration, int a_easeType=EASE_OUT_SINE, float a_p=0, float a_a=0 ) {
        property	= a_property;
        begin		= a_begin;
        end			= a_end;
        delay		= a_delay;
        duration	= a_duration;
        easeType	= a_easeType;
        p			= a_p;
        a			= a_a;
        bUseSeconds	= false;
    }
    
    // setup in seconds //
    void setup( float* a_property, float a_begin, float a_end, float a_delay, float a_duration, int a_easeType=EASE_OUT_SINE, float a_p=0, float a_a=0 ) {
        property	= a_property;
        begin		= a_begin;
        end			= a_end;
        delay		= a_delay;
        duration	= a_duration;
        easeType	= a_easeType;
        p			= a_p;
        a			= a_a;
        bUseSeconds	= true;
    }
    
    float *property;
    float begin, end;
    float duration;
    float delay;
    int easeType;
    float a;
    float p;
    
    bool bUseSeconds;
} TweenParams;

// ------------------------------------------------------------
//
// Class ofmTween
//
// ------------------------------------------------------------

class ofmTween {
public:
    static ofmTween* Instance();
    
    static void init();
    static void update(int a_millis);
    
    static void to(float* a_property, float a_end, float a_delay, float a_duration, int a_easeType=EASE_OUT_SINE, float a_p=0, float a_a=0);
    
    static void from(float* a_property, float a_begin, float a_delay, float a_duration, int a_easeType=EASE_OUT_SINE, float a_p=0, float a_a=0);
    
    static void to(ofmBase* ui, map<string, float> a_end, float a_delay, float a_duration, int a_easeType=EASE_OUT_SINE);
    
    static void fromTo(float* a_property, float a_begin, float a_end, float a_delay, float a_duration, int a_easeType=EASE_OUT_SINE, float a_p=0, float a_a=0);
    
    static void fromTo(vector <float *> a_properties, float a_begin, float a_end, float a_delay, float a_duration, int a_easeType=EASE_OUT_SINE, float a_p=0, float a_a=0);
    
    static void fromTo( TweenParams& a_params );
    static void fromTo( vector<TweenParams>& a_params );
    static void removeAllTweens();
    static void removeTween( float* a_property );
    
    static void destroy();
    static void pauseAllTweens();
    static void resumeAllTweens();
    static void resetAllTweens();
    static void toggleAllTweens();
    static int getSize();
    
    static Tween* getTween( float * a_property );
    static Tween* getRecentTween();
    
    
    typedef TweenEvent<float> TweenEv;
    template <class ListenerClass>
    static void onComplete( Tween* a_tween, ListenerClass* a_listener, void (ListenerClass::*a_listenerMethod)(float* args)) {
        removeOnComplete( a_tween );
        TweenEv completeEvent;
        completeEvent = new TweenEv::T<ListenerClass>(a_listener, a_listenerMethod);
        completeEvent.setID( __instance->_eventIndex );
        a_tween->eventID = __instance->_eventIndex;
        
        __instance->_events.push_back( completeEvent );
        __instance->_eventIndex++;
        if(__instance->_eventIndex > 0xffffffff - 2) {
            __instance->_eventIndex = 0;
        }
    }
    
    template <class ListenerClass>
    static void onComplete( float* a_property, ListenerClass* a_listener, void (ListenerClass::*a_listenerMethod)(float* args)) {
        Tween* tween = getTween(a_property);
        onComplete(tween, a_listener, a_listenerMethod);
    }
    
    static void removeOnComplete( Tween* a_tween );
    static void removeOnComplete( float* a_property );
    static void removeOnComplete( int a_eventID );
    static void removeAllListeners();
    
    
protected:
    ofmTween() {};
    static int getEventIndexForTween( Tween* a_tween );
    static int getEventIDForTween( Tween* a_tween );
    static int getEventIndexForID( int a_eventID );
    
private:
    static ofmTween* __instance;
    static bool _inited;
    static bool _destroyed;
    
    vector <Tween> _tweens;
    vector< TweenEv > _events;
    unsigned int _eventIndex;
    int _currMillis;
};
