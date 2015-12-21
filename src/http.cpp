#include "http.h"

HTTP::HTTP(App *a){
    app = a;
    httpUtils.start();
    ofLogNotice() << "Starting HTTP service";
    
    ofAddListener(ofEvents().update, this, &HTTP::update);
    refresh_rate = 30;
}

void HTTP::download(){
    ofAddListener(httpUtils.newResponseEvent,this,&HTTP::downloadResponse);
    ofxHttpForm form;
    form.method = OFX_HTTP_GET;
    form.action = Assets::getInstance()->getRemoteDataAddress();
    httpUtils.addForm(form);
}


void HTTP::downloadResponse(ofxHttpResponse & response){
    if(response.reasonForStatus == "OK"){
        if( response.responseBody.size() == 0){
            refresh_rate = 30 * 5;
        }
        else{
            app->setRemoteData(response.responseBody);
            refresh_rate = 30 * 30;
        }
    }
    else{
        ofLogError() << "Download error";
        app->setRemoteError();
    }
    ofRemoveListener(httpUtils.newResponseEvent,this,&HTTP::downloadResponse);
}


void HTTP::update(ofEventArgs &args){
    if(ofGetFrameNum() % refresh_rate == 0)
        download();
}



