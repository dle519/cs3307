// lights class
//@authors  Authors: Rachelle Cheung, Amir Ijad, Khadija Khairullah, Asad Khan, David Le
//
//@brief this class is responsible for displaying the light pattern that a user has chosen
//during an entrance

#include <wiringPi.h>
#include "lights.h"
#include <iostream>
using namespace std;

//@brief assigns pins as output pins and assigning pin numbers
void lights::setup(){
    int ledPin1 = 25;
    int ledPin2 = 23;
    int ledPin3 = 22;
    int ledPin4 = 21;
    int number;
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
    pinMode(ledPin4, OUTPUT);
}

//@brief creating default lights pattern
void lights::defaultPattern(){
    for(int i = 0; i < 10; i++){
        digitalWrite(ledPin1, HIGH); //changed from ledPin to ledPin1
        delay(500); //delay in milliseconds, alternative delayMicroseconds(#)
        digitalWrite(ledPin1, LOW); //changed from ledPin to ledPin1
        delay(500);
	if (i == 9)
	{
	    digitalWrite(ledPin1, HIGH);
	    digitalWrite(ledPin2, HIGH);
	    digitalWrite(ledPin3, HIGH);
	    digitalWrite(ledPin4, HIGH);
	}
    }
}

//@brief creating preset patterns depending on user input. 
//@parameters user inputs integer number --> results in particular pattern being chosen
void lights::chosenPattern(int number){
    //pattern 1
    if (number == 1) {
	for (int i = 0; i < 5; i++) {
	    digitalWrite(ledPin1, HIGH);
	    delay (500);
	    digitalWrite(ledPin1, LOW);
	    digitalWrite(ledPin2, HIGH);
	    delay(500);
	    digitalWrite(ledPin2, LOW);
	    digitalWrite(ledPin3, HIGH);
	    delay(500);
	    digitalWrite(ledPin3, LOW);
	    digitalWrite(ledPin4, HIGH);
	    delay(500);
	    digitalWrite(ledPin4, LOW);
	    digitalWrite(ledPin3,HIGH);
	    delay(500);
	    digitalWrite(ledPin3, LOW);
	    digitalWrite(ledPin2, HIGH);
	    delay(500);
	    digitalWrite(ledPin2, LOW);
	    
	    if (i == 4)
	    {
		digitalWrite(ledPin1, HIGH);
		digitalWrite(ledPin2, HIGH);
		digitalWrite(ledPin3, HIGH);
		digitalWrite(ledPin4, HIGH);
	    }
	}
    }
    
    //pattern 2
    if (number == 2) {
	for (int i = 0; i < 5; i++) {
	    digitalWrite(ledPin1, HIGH);
	    delay (500);
	    digitalWrite(ledPin1, LOW);
	    delay (500);
	    digitalWrite(ledPin1, HIGH);
	    delay (500);
	    digitalWrite(ledPin1, LOW);
	    delay (500);
	    digitalWrite(ledPin1, HIGH);
	    delay (500);
	    digitalWrite(ledPin1, LOW);
	    delay (500);
	    digitalWrite(ledPin2, HIGH);
	    delay(500);
	    digitalWrite(ledPin2, LOW);
	    delay (500);
	    digitalWrite(ledPin2, HIGH);
	    delay(500);
	    digitalWrite(ledPin2, LOW);
	    delay (500);
	    digitalWrite(ledPin2, HIGH);
	    delay(500);
	    digitalWrite(ledPin2, LOW);
	    delay (500);
	    digitalWrite(ledPin3, HIGH);
	    delay(500);
	    digitalWrite(ledPin3, LOW);
	    delay(500);
	    digitalWrite(ledPin3, HIGH);
	    delay(500);
	    digitalWrite(ledPin3, LOW);
	    delay(500);
	    digitalWrite(ledPin3, HIGH);
	    delay(500);
	    digitalWrite(ledPin3, LOW);
	    delay(500);
	    digitalWrite(ledPin4, HIGH);
	    delay(500);
	    digitalWrite(ledPin4, LOW);
	    delay(500);
	    digitalWrite(ledPin4, HIGH);
	    delay(500);
	    digitalWrite(ledPin4, LOW);
	    delay(500);
	    digitalWrite(ledPin4, HIGH);
	    delay(500);
	    digitalWrite(ledPin4, LOW);
	    delay(500);
	    
	    if (i == 4)
	    {
		digitalWrite(ledPin1, HIGH);
		digitalWrite(ledPin2, HIGH);
		digitalWrite(ledPin3, HIGH);
		digitalWrite(ledPin4, HIGH);
	    }
	}
    }
    
    //pattern 3
    if (number == 3) {
	for (int i = 0; i < 10; i++) {
	    digitalWrite(ledPin1, HIGH);
	    digitalWrite(ledPin4, HIGH);
	    delay(500);
	    digitalWrite(ledPin4, LOW);
	    digitalWrite(ledPin1, LOW);
	    delay (500);
	    digitalWrite(ledPin2, HIGH);
	    digitalWrite(ledPin3, HIGH);
	    delay(500);
	    digitalWrite(ledPin2, LOW);
	    digitalWrite(ledPin3, LOW);
	    delay(500);
	    
	    if (i == 9)
	    {
		digitalWrite(ledPin1, HIGH);
		digitalWrite(ledPin2, HIGH);
		digitalWrite(ledPin3, HIGH);
		digitalWrite(ledPin4, HIGH);
	    }
	}
    }
}

//@brief turns off all led lights
void lights::turnOff(){
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
}
