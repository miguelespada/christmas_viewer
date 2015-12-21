#pragma once

#include "ofMain.h"
#include "app.h"
#include "OscAdapter.h"
#include "gui.hpp"
#include "http.h"
#include "ofxSyphon.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void draw();
    
        App *app;
        OscAdapter *osc;
        Gui *gui;
        HTTP *http;
    
    
    ofxSyphonServer mainOutputSyphonServer;
};
