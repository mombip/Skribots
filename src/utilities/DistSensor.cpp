#include "DistSensor.h"

DistSensor::DistSensor(int EP,int Trigg){
  EchoPin = EP;
  TriggerPin = Trigg;
   pinMode(Trigg, OUTPUT);
   pinMode(EP, INPUT);
}

  int DistSensor::ReadSensor(int cm){
    digitalWrite(TriggerPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(TriggerPin,LOW);
    unsigned long int sigT = pulseIn(EchoPin,HIGH);
    long int l = sigT/58;
    if(l < cm){
      return(l);
    }
    else{
      return(cm);
    }

  }

  int DistSensor::RawReadSensor(){
    digitalWrite(TriggerPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(TriggerPin,LOW);
    unsigned long int sigT = pulseIn(EchoPin,HIGH);
    long int l = sigT/58;
    return(l);
  }