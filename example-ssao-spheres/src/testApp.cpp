#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    centers.resize( 100 );
    colors.resize( 100 );
    for (int i=0; i<centers.size(); i++) {
        centers[i].set( ofRandom(-150, 150), ofRandom(-150, 150), ofRandom(-150, 150) );
        colors[i] = ofColor::fromHsb( ofRandomuf() > .7 ? ofRandom(10,20) : ofRandom(150,160), 200, ofRandom(200,255));
    }
    
    loadShader();
}

//--------------------------------------------------------------
void testApp::loadShader(){
    ssao.setup( ofGetWidth(), ofGetHeight(), GL_RGBA );
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    float elapsedTime = ofGetElapsedTimef();
    ofSetWindowTitle( ofToString( ofGetFrameRate() ) );
    
    ssao.begin();
    camera.begin();
    float step = PI * 2./float(centers.size() );
    //tex.getTextureReference().bind();
    for(int i=0; i<centers.size(); i++){
        ofSetColor(colors[i]);
        ofSphere(centers[i].x, centers[i].y, centers[i].z, 40 + sin( elapsedTime + float(i) * step)*20 );
    }
    //tex.getTextureReference().unbind();
    
    camera.end();
    ssao.end();

    ssao.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'S'){
        loadShader();
    }
    if(key == 'f'){
        ofToggleFullscreen();
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    loadShader();
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}