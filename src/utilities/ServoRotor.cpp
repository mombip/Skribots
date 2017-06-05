#include "ServoRotor.h"

ServoRotor::ServoRotor(int Pin, String Side){
  _pin  = Pin;
  _side = Side; 
  //pinMode(_pin, OUTPUT);
  servo.attach(_pin,1000,2000);
  servo.writeMicroseconds(1520);
}

void ServoRotor::Move(char dir){
  switch(dir){
    case 'F':
      servo.writeMicroseconds(1900);
    break;
    case 'B':
      servo.writeMicroseconds(1100);
    break;
  }
}

void ServoRotor::Stop(int serv){
  servo.writeMicroseconds(1520);
}
