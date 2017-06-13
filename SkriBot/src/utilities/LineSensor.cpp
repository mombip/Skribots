#include "LineSensor.h"

LineSensor::LineSensor(int PinL, String Name){
 name = Name;
 sensorPin = PinL;
  delay(500);
  int blackReadOut = 0;
  /*for(int kk = 0; kk< 100; kk++){
    blackReadOut += analogRead(sensorPin);
    delay(20);
  }*/
    blackReadOut = blackReadOut/100;
    logicBorder = 500;
    //Serial.println(logicBorder);
}

bool LineSensor::ReadSensor(){
  int readout = analogRead(sensorPin);
    if(readout > logicBorder){
      return(true);
    }else{
      return(false);
    }  
}

int LineSensor::ReadSensorRaw(){
    return(analogRead(sensorPin));
}

void LineSensor::SetLogicBorder(int border){
  logicBorder = border;
}

String LineSensor::GetName(){
  return(name);
}

