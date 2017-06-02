#ifndef RobotLED_H
#define RobotLED_H
#include "Arduino.h"

  class RobotLED
 {
  public:
  	RobotLED(int pin,String name);
    void turnON();
    void turnOFF();
    bool readState();
    String name();
  	
  private:
  int  LEDpin;
  bool LEDstate;
  String LEDname;
 };

 #endif