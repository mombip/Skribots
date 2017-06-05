#ifndef SkriBot_H
#define SkriBot_H
#include "Arduino.h"
#include <utilities/ServoRotor.h>
#include <utilities/DistSensor.h>
#include <utilities/RobotLED.h>
#include <utilities/LineSensor.h>
#include <StandardCplusplus.h>
#include <utilities/BlueDentist.h>
#include <vector>

  class SkriBot
 {
  public:
  	SkriBot();
  	void AddRotor(int Pin,String Side); 
  	void AddDistSensor(int EchoPin,int TrigPin,String side);
    void AddLED(int Pin,String name);
    void AddLineSensor(int leftPin,int centerPin, int rightPin);   //functions for element adding

    void Move(char Direction,int ms);
    void FaceLeft(int ms = 200);
    void FaceRight(int ms = 200);
    void TurnLeft(int ms = 200);
    void TurnRight(int ms = 200);
    void MoveForward(int ms = -1);
    void MoveBack(int ms = -1);
    void Stop();                                                  //functions for movements

    int ReadLeftDistSensor(int cm);
    int ReadRightDistSensor(int cm);
    int ReadCenterDistSensor(int cm);                             //distance sensor readout

    void TurnOnLED(String name);
    void TurnOffLED(String name);                                 // LED functions

    bool ReadLeftLineSensor(int i = 0);
    bool ReadRightLineSensor(int i = 0);
    bool ReadCenterLineSensor(int i = 0);
    bool ReadLineSensor(int i =0 );
    void CalibrateLineSensor();                                       // line sensor readout

  private:
  std::vector<ServoRotor> LeftRotors;
  std::vector<ServoRotor> RightRotors;
  std::vector<DistSensor> LeftDistSensors;
  std::vector<DistSensor> RightDistSensors;
  std::vector<DistSensor> CenterDistSensors;
  std::vector<RobotLED> LEDs;
  std::vector<LineSensor> LineSensors;
 };

 #endif
