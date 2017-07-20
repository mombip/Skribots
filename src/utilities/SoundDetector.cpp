#include "SoundDetector.h"

SoundDetector::SoundDetector(int outputPin, String name){
	 _out_pin = outputPin;
  	 _name	  = name;
  	 pinMode(_out_pin,INPUT);
}


int SoundDetector::ReadSound(){
	int read = digitalRead(_out_pin);
	delay(200);
	return(read);
	
}

void SoundDetector::WaitForSound(){

	while(digitalRead(_out_pin) == 0);
	delay(200);
}

String SoundDetector::name(){
	return(_name);
}

int SoundDetector::CountSound(int sec){
	int totalTime = 1000*sec;
	int start = millis();
	int counter = 0;
	while(millis() - start < totalTime){
		while(digitalRead(_out_pin) == 0){
			if(millis() - start > totalTime){
				delay(300);
				counter--;
				break;
			}
		} 
		counter++;
		delay(300);
	}
	return(counter);
}