#include "app.h"
#include "http.h"


App::App():BaseApp(){
}


void App::processRemoteData(){

    if(bRemoteNewData){
            
        string url = remoteData["url"].asString();
        g.loadFile(url);
        t.setString(remoteData["name"].asString() + " - " + remoteData["body"].asString());
        cout << remoteData["favorited"].asString() << endl;
        if(remoteData["favorited"].asString() == "false")
            Assets::getInstance()->newGif.play();
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