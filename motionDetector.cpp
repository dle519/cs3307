//motionDetector class
//
//@authors Authors: Rachelle Cheung, Amir Ijad, Khadija Khairullah, Asad Khan, David Le
//
//@brief this class sets up the motion detectors and reads their input

#include <wiringPi.h>
#include "motionDetector.h"

//@brief sets up motion detector pins
void motionDetector::setup(){
    pinMode(mdPin1, INPUT);
}

//@brief reads input from motion detector pin
int motionDetector::checkPin1(){
    return digitalRead(mdPin1);
}
