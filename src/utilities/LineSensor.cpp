#include "LineSensor.h"

LineSensor::LineSensor(int PinL, String Name){
  sensorAddressArray =  (unsigned char)PinL;
 qtra = new QTRSensorsAnalog(sensorAddressArray,1, 4, 2);
 name = Name;
  delay(500);
  logicBorder = 600;
}

void LineSensor::ReadSensor(bool logicPosition){
  unsigned int sensorValues[1];
  qtra->readLine(sensorValues);
    if(sensorValues > logicBorder){
      logicPosition = true;
    }else{
      logicPosition = false;
    }
  
}

void LineSensor::calibrate(){
  for (int ij = 0; ij < 400; ij++){
    qtra->calibrate();       // reads all sensors 10 times at 2.5 ms per six sensors (i.e. ~25 ms per call)
  }
    qtra->calibratedMinimumOn[0];
    qtra->calibratedMaximumOn[0];
   delay(1000);
}

void LineSensor::SetLogicBorder(int border){
  logicBorder = border;
}

String LineSensor::GetName(){
  return(name);
}

