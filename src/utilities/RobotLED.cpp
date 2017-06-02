#include "RobotLED.h"

	RobotLED::RobotLED(int pin,String name){
		pinMode(pin,OUTPUT);
		LEDpin = pin;
		LEDname = name;
		LEDstate = false;
	}
    void RobotLED::turnON(){
    	digitalWrite(LEDpin,HIGH);
    	LEDstate = true;
    }
    void RobotLED::turnOFF(){
    	digitalWrite(LEDpin,LOW);
    	LEDstate = false;
    }
    bool RobotLED::readState(){
    	return(LEDstate);
    }

    String RobotLED::name(){
    	return(LEDname);
    }