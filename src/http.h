
#ifndef __HTTP__
#define __HTTP__

#include "ofMain.h"
#include "ofxHttpUtils.h"
#include "app.h"

class HTTP{
    App *app;
    ofxHttpUtils httpUtils;
    int refresh_rate;
public:
    HTTP(App *_app);
    void update(ofEventArgs &args);
    
    void download();
    void downloadResponse(ofxHttpResponse & response);
};

#endif