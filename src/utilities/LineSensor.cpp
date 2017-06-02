#include "LineSensor.h"

LineSensor::LineSensor(int PinLeft,int PinCenter,int PinRight){
  sensorAddressArray[0] =  (unsigned char)PinLeft;
  sensorAddressArray[1] =  (unsigned char)PinRight;
  sensorAddressArray[2] =  (unsigned char)PinCenter;
// for(int i = 0; i < 3; i++)sensorAddressArray[i] = i;
 qtra = new QTRSensorsAnalog(sensorAddressArray,3, 4, 2);
  delay(500);
  logicBorder = 600;
}

void LineSensor::ReadAllSensors(bool *logicPositions){
  unsigned int sensorValues[3];
  qtra->readLine(sensorValues);
  for( int y = 0; y < 3 ; y++){
    //Serial.print(sensorValues[y]);
    //Serial.print(" ");
    if(sensorValues[y] > logicBorder){
      logicPositions[y] = true;
    }else{
      logicPositions[y] = false;
    }
  }
}

void LineSensor::calibrate(){
  for (int ij = 0; ij < 400; ij++){
    qtra->calibrate();       // reads all sensors 10 times at 2.5 ms per six sensors (i.e. ~25 ms per call)
  }

  for(int i = 0; i < 3; i++){
    qtra->calibratedMinimumOn[i];
    qtra->calibratedMaximumOn[i];
  }

   delay(1000);

}
bool LineSensor::ReadLeftSensor(){
   bool logicPositions[3]; 
   ReadAllSensors(logicPositions);
   delay(100);
   return(logicPositions[0]);
}

bool LineSensor::ReadCenterSensor(){
   bool logicPositions[3]; 
   ReadAllSensors(logicPositions);
   delay(100);
   return(logicPositions[1]);
}

bool LineSensor::ReadRightSensor(){
   bool logicPositions[3]; 
   ReadAllSensors(logicPositions);
   delay(100);
   return(logicPositions[2]);
}

void LineSensor::SetLogicBorder(int border){
  logicBorder = border;
}

