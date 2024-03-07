#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(80);
    rootPage = new RootPage();
    rootPage->setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    if(rootPage != NULL) rootPage->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(rootPage != NULL) rootPage->draw();
}

//--------------------------------------------------------------
void ofApp::exit(){
    rootPage->destroy();
    delete rootPage;
    rootPage = NULL;
}

//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void ofApp::touchMoved(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchUp(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(ofTouchEventArgs & touch){
}

//--------------------------------------------------------------
void ofApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void ofApp::lostFocus(){

}

//--------------------------------------------------------------
void ofApp::gotFocus(){

}

//--------------------------------------------------------------
void ofApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void ofApp::deviceOrientationChanged(int newOrientation){

}
