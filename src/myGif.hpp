
#include "ofMain.h"
#include "assets.h"

#include "ofxAwesomium.h"

class myGif{
    
public:
    
    ofVideoPlayer gif;
    int w;
    int h;
    string gifName;
    
    ofxAwesomium browser;
    
    myGif(){
        ofAddListener(ofEvents().update, this, &myGif::update);
         browser.setup(1024, 768);
    }
    
    void loadFile(string file){
        gifName = file;
        ofLogNotice() << "Loading gif " << gifName;
        
        
        browser.loadURL("http://res.cloudinary.com/espadaysantacruz/image/upload/c_fill,h_768,w_1024/" + gifName);
    }
    
    void update(ofEventArgs &args){
        ofxAwesomium::updateCore();
        browser.update();
    }
    
    void draw(){
        if(gifName != ""){
            ofEnableAlphaBlending();
            browser.draw(0, 0);
    
            Assets::getInstance()->caravana.draw(0, 0);
            ofDisableAlphaBlending();
        }
    }
};