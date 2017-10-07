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

LineSensor::LineSensor(int PinL, int _id){
 _id = id;
 sensorPin = PinL;
  delay(500);
  int blackReadOut = 0;
    blackReadOut = blackReadOut/100;
    logicBorder = 500;
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

int LineSensor::GetID(){
    return(id);
}

void LineSensor::SetLogicBorder(int border){
  logicBorder = border;
}

String LineSensor::GetName(){
  return(name);
}

