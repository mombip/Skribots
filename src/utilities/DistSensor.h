#ifndef DistSensor_H
#define DistSensor_H
#include "Arduino.h"

  class DistSensor
 {
  public:
    DistSensor(int EP,int Trigg);
    int ReadSensor(int cm);
    int RawReadSensor();
  private:
  int EchoPin;
  int TriggerPin;
  
 };
 #endif
