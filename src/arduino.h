//
//  arduino.h
//  lescer_viewer
//
//  Created by miguel on 21/09/15.
//
//

#ifndef __lescer_viewer__arduino__
#define __lescer_viewer__arduino__

#include "ofMain.h"
#include "app.h"


#define ARDUINO_BAUD_RATE 57600
#define ARDUINO_PORT_NAME "tty.usbmodem"

class Arduino
{
    App *app;
    

public:
    Arduino(App *a);;
    void update(ofEventArgs &args);
    ofArduino	ard;
    ofSerial serial;
    
    // arduino serial hot plugging
    int getArduinoPort();
    bool isArduinoConnected;
    
    void reconnectArduino();
    
    void updateArduino();
    void setupArduino(const int & version);
    
   	bool		bSetupArduino;


};


#endif /* defined(__lescer_viewer__arduino__) */
