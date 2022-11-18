#ifndef __FLASHING__
#define __FLASHING__

#include "mbed.h"



class flashing {

    private:
        DigitalOut  _ledPin;
        Ticker yellowTick;
        };

    public:

        //Constructor turning on LED when object is created
        flashing(PinName ledPin) : _ledPin(ledPin) {

                //Simple ticker for the yellow LED
                _ledPin = 1;
                yellowTick.attach(&flashing::toggleYellowISR,500ms);
        }
        //Destructor, ensuring led is switched off when out of scope
        ~flashing() {
          _ledPin = 0;
          yellowTick.dettach();
        }
 

        void toggleYellowISR(){

            _ledPin = !_ledPin;
        }
};






#endif