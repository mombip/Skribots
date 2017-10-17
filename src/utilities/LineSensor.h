#ifndef LineSensor3_H
#define LineSensor3_H
#include "Arduino.h"
  
  class LineSensor
 {
  public:
    LineSensor(int InputPin,String name);
    LineSensor(int InputPin,int id);;
    int ReadSensorRaw();
    bool ReadSensor();
    void SetLogicBorder(int border);
    String GetName();
    int GetID();
  private:
    int id;
  	int logicBorder;
  	int sensorPin;  //sensor read out is from 0 to 1000 where 0 is minimum reflectance(line) and 1000 is maximum reflectance(no line) need to be set for some value to recognise line under sensor
    String name; 
 };

 #endif
