#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableDepthTest();
	ofSetBackgroundColor(0, 0, 0);
	
	/* SETUP PARTICLE SYSTEM*/
	ParticleSystem::InitializeParticles();
	Generator::Setup();

	Jesus.loadModel("Christ.obj", true);
	Jesus.enableMaterials();
	Jesus.enableNormals();
	Jesus.setPosition(0, 100, 0);

	ofEnableLighting();
	ofEnableDepthTest();


	light.setPosition(ofVec3f(0, 50, 1000));
	camera.setPosition(ofVec3f(0, 0, 3000));
	
	ofSetSphereResolution(4);
}

//--------------------------------------------------------------
void ofApp::update(){

	ParticleSystem::Update();
	Generator::Emmit();
	light.setPosition(camera.getPosition());
}

//--------------------------------------------------------------
void ofApp::draw(){

	camera.begin();
	light.enable();
	ofDrawAxis(200);

	Jesus.drawFaces();
	ParticleSystem::Draw();
	Generator::DrawColliders();

	light.disable();
	camera.end();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	//emmiter->SetPosition(ofVec3f(x - (ofGetScreenWidth() / 2), (ofGetScreenHeight() / 2) - y, 0));
	
		
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
