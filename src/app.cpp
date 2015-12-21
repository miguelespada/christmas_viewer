#include "app.h"
#include "http.h"


App::App():BaseApp(){
    bNew = false;

}


void App::processRemoteData(){

    if(bRemoteNewData){
            
        string url = remoteData["url"].asString();
        g.loadFile(url);
        t.setString(remoteData["name"].asString() + " - " + remoteData["body"].asString());
        if(remoteData["favorited"].asString() == "false"){
            Assets::getInstance()->newGif.play();
            bNew = true;
        }
        bRemoteNewData = false;
    }
}

void App::drawGifs(){
        g.draw();
    ofPushMatrix();
    ofTranslate(0, 800);
        t.draw();
    ofPopMatrix();
  
}