#include "app.h"
#include "http.h"


App::App():BaseApp(){
}


void App::processRemoteData(){

    if(bRemoteNewData){
            
        string url = remoteData["url"].asString();
        g.loadFile(url);
        t.setString(remoteData["name"].asString() + " - " + remoteData["body"].asString());
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