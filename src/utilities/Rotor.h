#ifndef Rotor_H
#define Rotor_H
#include "Arduino.h"
  class Rotor
 {
  public:
  	Rotor(int SpeedPin,int DirectionPin);
    void SetSpeed(int speed);
    void SetDirection(int dir);
    void Move();
    void Stop();
    int GetSpeed();
    int GetDirection();
  private:
  int _speed_pin;
  int _dir_pin;
  int _speed;
  int _dir;
 };

 #endif