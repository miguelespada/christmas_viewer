#include "standbyState.h"

StandbyState::StandbyState(App *a):BaseState(a){
    BaseState::initialize();
};

StandbyState::~StandbyState(){
};

void StandbyState::draw(){
    app->drawGifs();
};

void StandbyState::update(){
    app->processRemoteData();
};

void StandbyState::next(){
    app->setCurrentState(new StandbyState(app));
    delete this;
};

void StandbyState::keypressed(int key){
    switch (key) {
        case ' ':
            next();
            break;
        case 13:
            next();
            break;
        default:
            break;
    }
}