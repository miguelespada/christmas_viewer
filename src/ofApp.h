#pragma once

#include "ofMain.h"
#include "app.h"
#include "OscAdapter.h"
#include "gui.hpp"
#include "http.h"
#include "ofxSyphon.h"
#include "arduino.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void draw();
        void keyPressed(int key);
    
        App *app;
        OscAdapter *osc;
        Gui *gui;
        HTTP *http;
    Arduino *arduino;
    
    
    ofxSyphonServer mainOutputSyphonServer;
};
