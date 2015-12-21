#include "ofMain.h"
#include "ofxTrueTypeFontUC.h"

#define SPEED 5
class myText{
    ofxTrueTypeFontUC myFont;
    string myString;
    int x;
    int y;
    int w;
    int stringWidth;
    
    
public:
    
     myText(){
         ofAddListener(ofEvents().update, this, &myText::update);
         myFont.loadFont("frabk.ttf", 124, true, true);
         myString == "";
     }
    
    void setString(string s){
        if(myString !=  ofToUpper(s)){
            myString = ofToUpper(s);
            w = ofGetWidth();
            y = myFont.stringHeight(myString);
            stringWidth = myFont.stringWidth(myString);
            x = 0;
        }
    }
    
    void update(ofEventArgs &args){
        x += SPEED;
        if (x > stringWidth  + w )
            x = 0;
    }
    
    void draw(){
        if(myString != "")
            myFont.drawStringAsShapes(myString, w - x , y);
    }
};