#include "ofmTween.h"
#include "ofmUtil.h"

ofmTween* ofmTween::__instance = 0;
bool ofmTween::_inited = false;
bool ofmTween::_destroyed = false;

//--------------------------------------------------------------
ofmTween* ofmTween::Instance() {
    if (__instance == 0) {
        __instance = new ofmTween();
        __instance->_eventIndex = 0;
        __instance->_currMillis = 0;
        removeAllTweens();
    }
    
    return __instance;
}

//--------------------------------------------------------------
void ofmTween::init() {
    if(!_inited) {
        Instance();
        _inited = true;
    }
}

//--------------------------------------------------------------
void ofmTween::update(int a_millis) {
    init();
    
    __instance->_currMillis = a_millis;
    int _twCount = 0;
    vector<Tween>::iterator it;
    vector<int> eventsToFire;
    vector<float*> eventArgs;
    
    
    for ( it=__instance->_tweens.begin(); it < __instance->_tweens.end(); it++ ) {
        if(it->complete()) {
            int evindex = getEventIDForTween( &(*it) );
            if(evindex > -1) {
                //float args = it->getPropertyValue();
                float* arg = it->getProperty();
                eventsToFire.push_back( evindex );
                eventArgs.push_back( arg );
            }
        }
        
        _twCount ++;
    }
    
    if(__instance->_tweens.size() > 0) {
        int _totesTweens = __instance->_tweens.size();
        for(int i = _totesTweens-1; i >= 0; i--) {
            if(__instance->_tweens[i].complete()) {
                //removeOnComplete( &__instance->_tweens[i] );
                removeTween( __instance->_tweens[i].getProperty() );
            }
        }
        
    }
    
    for(unsigned int i = 0; i < eventsToFire.size(); i++) {
        int evindex = getEventIndexForID( eventsToFire[i] );
        __instance->_events[evindex]( eventArgs[i] );
        removeOnComplete( eventsToFire[i] );
    }
    
    _twCount = 0;
    for ( it=__instance->_tweens.begin(); it < __instance->_tweens.end(); it++ ) {
        it->update( __instance->_currMillis );
        _twCount++;
    }
}

void ofmTween::to(float* a_property, float a_end, float a_delay, float a_duration, int a_easeType, float a_p, float a_a) {
    float a_begin = *a_property;
    fromTo(a_property, a_begin, a_end, a_delay, a_duration, a_easeType, a_p, a_a);
}

void ofmTween::from(float* a_property, float a_begin, float a_delay, float a_duration, int a_easeType, float a_p, float a_a) {
    float a_end = *a_property;
    *a_property = a_begin;
    fromTo(a_property, a_begin, a_end, a_delay, a_duration, a_easeType, a_p, a_a);
}

void ofmTween::to(ofmBase* ui, map<string, float> a_end, float a_delay, float a_duration, int a_easeType) {
    if(ofmUtil::mapHasKey<string, float>(a_end, "x"))
        to(&ui->alpha, a_end["x"], a_delay, a_duration, a_easeType);
    if(ofmUtil::mapHasKey<string, float>(a_end, "y"))
        to(&ui->alpha, a_end["y"], a_delay, a_duration, a_easeType);
    if(ofmUtil::mapHasKey<string, float>(a_end, "alpha"))
        to(&ui->alpha, a_end["alpha"], a_delay, a_duration, a_easeType);
    if(ofmUtil::mapHasKey<string, float>(a_end, "scale"))
        to(&ui->alpha, a_end["scale"], a_delay, a_duration, a_easeType);
    if(ofmUtil::mapHasKey<string, float>(a_end, "rotation"))
        to(&ui->alpha, a_end["rotation"], a_delay, a_duration, a_easeType);
}

void ofmTween::fromTo(float* a_property, float a_begin, float a_end, float a_delay, float a_duration, int a_easeType, float a_p, float a_a) {
    if(_destroyed) return;
    
    init();
    removeOnComplete( a_property );
    removeTween( a_property );
    Tween tweenzlebob( a_property, __instance->_currMillis, a_begin, a_end, a_delay, a_duration, a_easeType, a_p, a_a );
    __instance->_tweens.push_back( tweenzlebob );
}

void ofmTween::fromTo(vector <float *> a_properties, float a_begin, float a_end, float a_delay, float a_duration, int a_easeType, float a_p, float a_a) {
    if(_destroyed) return;
    
    init();
    for (unsigned int i = 0; i < a_properties.size(); i++) {
        fromTo(a_properties[i], a_begin, a_end, a_delay, a_duration, a_easeType, a_p, a_a);
    }
}

//--------------------------------------------------------------
void ofmTween::fromTo( TweenParams& a_params ) {
    if(_destroyed) return;
    
    init();
    if(a_params.bUseSeconds) {
        fromTo(a_params.property, a_params.begin, a_params.end, a_params.delay, a_params.duration, a_params.easeType, a_params.p, a_params.a);
    } else {
        fromTo(a_params.property, a_params.begin, a_params.end, (int)a_params.delay, (int)a_params.duration, a_params.easeType, a_params.p, a_params.a);
    }
}

//--------------------------------------------------------------
void ofmTween::fromTo( vector<TweenParams>& a_params ) {
    if(_destroyed) return;
    
    init();
    for(unsigned int i = 0; i < a_params.size(); i++) {
        fromTo( a_params[i] );
    }
}

//--------------------------------------------------------------
void ofmTween::removeTween( float* a_property ) {
    init();
    if (__instance->_tweens.size() > 0) {
        int i = 0;
        vector<Tween>::iterator it;
        for ( it=__instance->_tweens.begin(); it < __instance->_tweens.end(); it++ ) {
            if ( it->getProperty() == a_property ) {
                it->remove();
                __instance->_tweens.erase( it );
                break;
            }
            i++;
        }
    }
}

//--------------------------------------------------------------
Tween* ofmTween::getTween( float* a_property ) {
    if(_destroyed) return NULL;
    
    init();
    vector<Tween>::iterator it;
    for ( it=__instance->_tweens.begin(); it < __instance->_tweens.end(); it++ ) {
        if(it->getProperty() == a_property) {
            return ((Tween*) &(*it));
        }
    }
    
    return NULL;
}

// protected //
//--------------------------------------------------------------
int ofmTween::getEventIndexForTween( Tween* a_tween ) {
    if(a_tween == NULL) return -1;
    unsigned int evid = a_tween->eventID;
    for(unsigned int i = 0; i < __instance->_events.size(); i++) {
        if( (__instance->_events[i].getID()) == evid ) {
            return i;
            break;
        }
    }
    return -1;
}

//--------------------------------------------------------------
int ofmTween::getEventIDForTween( Tween* a_tween ) {
    if(a_tween == NULL) return -1;
    unsigned int evid = a_tween->eventID;
    for(unsigned int i = 0; i < __instance->_events.size(); i++) {
        if( (__instance->_events[i].getID()) == evid ) {
            return __instance->_events[i].getID();
            break;
        }
    }
    return -1;
}

//--------------------------------------------------------------
int ofmTween::getEventIndexForID( int a_eventID ) {
    for(unsigned int i = 0; i < __instance->_events.size(); i++) {
        if( (__instance->_events[i].getID()) == a_eventID ) {
            return i;
        }
    }
    return -1;
}

//--------------------------------------------------------------
void ofmTween::removeOnComplete( Tween* a_tween ) {
    if(a_tween == NULL) return;
    unsigned int evid = a_tween->eventID;
    for(unsigned int i = 0; i < __instance->_events.size(); i++) {
        if( (__instance->_events[i].getID()) == evid ) {
            if(__instance->_events[i] == true) {
                __instance->_events[i].destroy();
                __instance->_events[i] = NULL;
                __instance->_events.erase( __instance->_events.begin() + i);
            }
            break;
        }
    }
}

//--------------------------------------------------------------
void ofmTween::removeOnComplete( float* a_property ) {
    removeOnComplete( getTween(a_property) );
}

//--------------------------------------------------------------
void ofmTween::removeOnComplete( int a_eventID ) {
    for(unsigned int i = 0; i < __instance->_events.size(); i++) {
        if( (__instance->_events[i].getID()) == a_eventID ) {
            __instance->_events[i].destroy();
            __instance->_events[i] = NULL;
            __instance->_events.erase( __instance->_events.begin() + i);
            break;
        }
    }
}

//--------------------------------------------------------------
void ofmTween::removeAllListeners() {
    __instance->_events.clear();
}

//--------------------------------------------------------------
void ofmTween::removeAllTweens() {
    for(unsigned int i = 0; i < __instance->_events.size(); i++) {
        __instance->_events[i].destroy();
        __instance->_events[i] = NULL;
    }
    
    __instance->_events.clear();
    __instance->_tweens.clear();
}

//--------------------------------------------------------------
void ofmTween::destroy() {
    init();
    removeAllTweens();
    
    if(__instance != 0) {
        delete __instance;
        __instance = 0;
    }
    _destroyed = true;
    
}

//--------------------------------------------------------------
void ofmTween::pauseAllTweens() {
    init();
    if (__instance->_tweens.size() > 0) {
        vector<Tween>::iterator it;
        for ( it=__instance->_tweens.begin(); it < __instance->_tweens.end(); it++ ) {
            it->pause();
        }
    }
}

//--------------------------------------------------------------
void ofmTween::resetAllTweens() {
    if (__instance->_tweens.size() > 0) {
        vector<Tween>::iterator it;
        for ( it=__instance->_tweens.begin(); it < __instance->_tweens.end(); it++ ) {
            it->reset(__instance->_currMillis);
        }
    }
}

//--------------------------------------------------------------
void ofmTween::resumeAllTweens() {
    if (__instance->_tweens.size() > 0) {
        vector<Tween>::iterator it;
        for ( it=__instance->_tweens.begin(); it < __instance->_tweens.end(); it++ ) {
            it->resume(__instance->_currMillis);
        }
    }
}

// toggle pause / resume all tweens //
//--------------------------------------------------------------
void ofmTween::toggleAllTweens() {
    init();
    if (__instance->_tweens.size() > 0) {
        vector<Tween>::iterator it;
        for ( it=__instance->_tweens.begin(); it < __instance->_tweens.end(); it++ ) {
            it->toggle(__instance->_currMillis);
        }
    }
}

//--------------------------------------------------------------
Tween* ofmTween::getRecentTween() {
    init();
    if (__instance->_tweens.size() > 0) {
        return &__instance->_tweens[__instance->_tweens.size() - 1];
    }
    return 0;
}

//--------------------------------------------------------------
int ofmTween::getSize() {
    init();
    return __instance->_tweens.size();
}
