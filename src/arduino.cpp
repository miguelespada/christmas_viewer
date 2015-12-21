//
//  arduino.cpp
//  lescer_viewer
//
//  Created by miguel on 21/09/15.
//
//

#include "arduino.h"

Arduino::Arduino(App *a){
    app = a;
    
    isArduinoConnected = false;
    
    ofAddListener(ofEvents().update, this, &Arduino::update);
    
}


//--------------------------------------------------------------
void Arduino::update(ofEventArgs &args){
    
    if(isArduinoConnected)
        updateArduino();
    
    if(ofGetFrameNum() % 100 == 0)
        reconnectArduino();

}

void Arduino::reconnectArduino(){
    int port = getArduinoPort();
    if(port >=0 ){
        if(isArduinoConnected){
            //cout << "Arduino is connected" << endl;
        }else{
            ofLogNotice() << "Trying to connect arduino...";

            ard.disconnect();
            ard.connect(serial.getDeviceList()[port].getDeviceName(), ARDUINO_BAUD_RATE);
            
            // listen for EInitialized notification. this indicates that
            // the arduino is ready to receive commands and it is safe to
            // call setupArduino()
            ofAddListener(ard.EInitialized, this, &Arduino::setupArduino);
            
            isArduinoConnected = true;
        }
    }
    else{
        ofLogNotice() << "Arduino not present...";
        isArduinoConnected = false;
    }
}


int Arduino::getArduinoPort(){
    ofSerial serial;
    vector <ofSerialDeviceInfo> deviceList =  serial.getDeviceList();
    for(int i=0; i<deviceList.size(); i++){
        if(deviceList[i].getDeviceName().find(ARDUINO_PORT_NAME) != std::string::npos){
            return i;
        }
    }
    cout << "arduino port not found " << endl;
    return -1;
};


//--------------------------------------------------------------
void Arduino::updateArduino(){
    ard.update();
    
    if(app->bNew){
        for(int i = 0; i < 4; i ++){
            ard.sendDigital(2, ARD_HIGH);
            ofSleepMillis(100);
            ard.sendDigital(2, ARD_LOW);
            ofSleepMillis(100);
        }
        app->bNew = false;
    }
    else
        ard.sendDigital(2, ARD_LOW);
        
        

}

//--------------------------------------------------------------
void Arduino::setupArduino(const int & version) {
    
    ofRemoveListener(ard.EInitialized, this, &Arduino::setupArduino);
    
    bSetupArduino = true;
    
    ofLogNotice() << ard.getFirmwareName();
    ofLogNotice() << "firmata v" << ard.getMajorFirmwareVersion() << "." << ard.getMinorFirmwareVersion();
    
    
    ard.sendDigitalPinMode(2, ARD_OUTPUT);
}
