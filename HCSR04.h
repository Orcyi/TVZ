 #include "mbed.h"
 
class HCSR04 {
    
    public:
    
    /** dvije varijable za hcsr04 sensor.
     * @param echoPin 
     * @param triggerPin 
     */
    HCSR04(PinName echoPin, PinName triggerPin);
    
   
    float getDistance_cm();
    void startMeasurement();
    
    private:
    
    InterruptIn echo;       
    DigitalOut trigger;     
    Timer timer;            
    float distance;         
  
    void startTimer();
    void stopTimer();
    void init();
    

 
};