#include "uop_msb.h"
#include <chrono>
#include <cstdint>
using namespace uop_msb;

//Used this to 
Ticker tick;
Thread t1,t2;


Mutex sumLock;

volatile uint32_t sum;

void processSample();
void dispAverage();
void sampleISR();


int main(void)
{
/*
1. Create an ISR - called by a Ticker every 1ms. This ISR simply has the job of signalling a waiting thread to perform an ADC conversion
2. Create a thread that waits for a signal from the ISR. This thread should ideally have the highest priority
3. Each time it is unblocked by the signal, it should read the ADC (Use `AnalogIn`) for the LDR and add it to a running sum.
4. Every 1s, it should print out the average of the past 1000 samples to the terminal. 
*/

    t1.start(processSample);
    t2.start(dispAverage);
    tick.attach(sampleISR,1ms);
    t1.set_priority(osPriorityRealtime);    
    while (true) {
        ThisThread::sleep_for(1000ms);
    }
    
}   

void processSample(){

    AnalogIn ldr(AN_LDR_PIN);
    int i = 0;
    while(1){
        ThisThread::flags_wait_all(1);
        sumLock.lock();
        sum += ldr.read_u16();
        sumLock.unlock();
        if(i >= 999){
            t2.flags_set(1);
            i = 0;
        }
        i = i + 1;
        ThisThread::flags_clear(1);
    }
}

void dispAverage(){
    uint16_t average;
    while(1){
        ThisThread::flags_wait_all(1);
        sumLock.lock();
        average = sum/1000;
        sum = 0.0;
        sumLock.unlock();
        printf("Average reading: %hu\n", average);
        ThisThread::flags_clear(1);

    }

}

void sampleISR(){
    t1.flags_set(1);
}
