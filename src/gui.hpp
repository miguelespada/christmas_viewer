#include "ofxGui.h"
#include "app.h"

class Gui
{
    ofxPanel gui;
    App *app;
    OscAdapter *osc;
    bool bVisible;
    
public:
    
    Gui(App *a, OscAdapter *o){
        app = a;
        osc = o;
        gui.setup();
        init();
        
        bVisible = true;
        load();
    }
    
    void draw(){
        if(bVisible)
            gui.draw();
    }
    
    void load(){
        string path = ofToDataPath("gui.xml");
        ofLogNotice() << "Loading gui from: " << path;
        gui.loadFromFile(path);
    }
    
    void save(){
        string path = ofToDataPath("gui.xml");
        ofLogNotice() << "Saving gui to: " << path;
        gui.saveToFile(path);
    }
    
    void toggleVisibility(){
        bVisible = !bVisible;
    }
    
    
    //--------------------------------------------------------------
    void init(){
        
        
    }
    
};

