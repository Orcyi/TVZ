#include "mbed.h"
#include "HCSR04.h"

HCSR04::HCSR04(PinName echoPin, PinName triggerPin) : echo(echoPin), trigger(triggerPin) {
    init();
}

void HCSR04::init() {
    echo.rise(this, &HCSR04::startTimer);
    echo.fall(this, &HCSR04::stopTimer);
    distance = -1; 
}

void HCSR04::startTimer() {
    timer.start(); 
}

void HCSR04::stopTimer() {
    timer.stop(); 
}

void HCSR04::startMeasurement() {
    trigger = 1;
    wait_us(10);
    trigger = 0;
    wait_ms(25); 
    distance = timer.read() * 1e6 / 58;
    timer.reset(); 
}

float HCSR04::getDistance_cm() {
    startMeasurement();
    return distance;
}