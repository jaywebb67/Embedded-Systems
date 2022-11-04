#ifndef __TRAFFICLIGHT__
#define __TRAFFICLIGHT__

#include "mbed.h"
using namespace chrono;

#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2
#define TRAF_GRN2_PIN PC_9
#define TRAF_YEL2_PIN PC_8
#define TRAF_RED2_PIN PC_7

class TrafficLight 
{
    public:
        typedef enum {STOP, READY, GO, WARNING} LIGHT_STATE;
        typedef enum {SET_1, SET_2} TRAFFIC_SET;

    private:
        DigitalInOut redLED;
        DigitalInOut yellowLED;
        DigitalInOut greenLED;
    
        Ticker t;
        LIGHT_STATE State;
        TRAFFIC_SET setNo;
    
        double flash_ms;
    
        void yellowFlashISR();
        void flashYellow(bool flash,double flashTime);
        void updateOutput();
        void setLightPins();
    public:
        //Constructor
        TrafficLight(TRAFFIC_SET trafficSet); 

    //PinName redPin = TRAF_RED1_PIN, PinName yellowPin = TRAF_YEL1_PIN, PinName greenPin=TRAF_GRN1_PIN
    
        //Destructor
        ~TrafficLight();

        //Advance the traffic lights to the next state
        LIGHT_STATE nextState();
        void stop();
        void setFlashSpeed(double flash_ms);
        double getFlashSpeed();
    
};


#endif
