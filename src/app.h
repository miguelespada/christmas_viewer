#ifndef __App__
#define __App__

#include "baseApp.h"
#include "myGif.hpp"
#include "myText.hpp"


#define N_GIFS 10

class App: public BaseApp
{
public:
    myGif g;
    myText t;
    
    
    App();
    ~App(){};
    
    void processRemoteData();
    void drawGifs();
};

#endif
