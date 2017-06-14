#ifndef DistSensor_H
#define DistSensor_H
#include "Arduino.h"

  class DistSensor
 {
  public:
    DistSensor(int EP,int Trigg, String Name);
    int ReadSensor(int cm);
    int RawReadSensor();
    String GetName();
  private:
  int EchoPin;
  int TriggerPin;
  String name;
  
 };
 #endif
