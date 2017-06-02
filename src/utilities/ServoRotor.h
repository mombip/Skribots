#ifndef ServoRotor_H
#define ServoRotor_H
#include "Arduino.h"
#include "Servo.h"
  class ServoRotor
 {
  public:
  	ServoRotor(int Pin, String Side);
    void Move(char Direction);
    void Stop(int S);
  private:
  int _pin;
  String _side;
  Servo servo;
 };

 #endif
