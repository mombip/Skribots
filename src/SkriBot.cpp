#include "SkriBot.h"
 
  SkriBot::SkriBot(){
    
  }
  void SkriBot::AddRotor(int Pin, String Side){
    ServoRotor rotor(Pin,Side);
     if(Side == "Left"){
      LeftRotors.push_back(rotor);
     }else if(Side == "Right"){
      RightRotors.push_back(rotor);
     }
  }

  void SkriBot::AddDistSensor(int EchoPin,int TrigPin,String Side){
    DistSensor dsensor(EchoPin,TrigPin);
     if(Side == "Left"){
      LeftDistSensors.push_back(dsensor);
     }else if(Side == "Right"){
      RightDistSensors.push_back(dsensor);
     }else if(Side == "Center"){
      CenterDistSensors.push_back(dsensor);
     }
  }

  void SkriBot::AddLineSensor(int pinL,int pinC,int pinR){
    LineSensor lsensor(pinL,pinC,pinR);
    delay(500);
    LineSensors.push_back(lsensor);
    CalibrateLineSensor();
  }

  void SkriBot::CalibrateLineSensor(){
    LineSensors[0].calibrate();
  }

  void SkriBot::AddLED(int pin,String name){
    RobotLED led(pin,name);
    LEDs.push_back(led);
  }

  void SkriBot::TurnOnLED(String name){
    for(int zz = 0; zz < LEDs.size(); zz++){
                    if(LEDs[zz].name() == name){
                      LEDs[zz].turnON();
                      break;
                    }
      }
  }

  void SkriBot::TurnOffLED(String name){
    for(int zz = 0; zz < LEDs.size(); zz++){
                    if(LEDs[zz].name() == name){
                      LEDs[zz].turnOFF();
                      break;
                    }
      }
  }

  int SkriBot::ReadLeftDistSensor(int cm){
    return(LeftDistSensors[0].ReadSensor(cm));
  }

  int SkriBot::ReadRightDistSensor(int cm){
    return(RightDistSensors[0].ReadSensor(cm));
  }

  int SkriBot::ReadCenterDistSensor(int cm){
     return(CenterDistSensors[0].ReadSensor(cm));
  }

  bool SkriBot::ReadLeftLineSensor(int i){
    return(LineSensors[i].ReadLeftSensor());
  }

   bool SkriBot::ReadRightLineSensor(int i){
    return(LineSensors[i].ReadRightSensor());
  }

   bool SkriBot::ReadCenterLineSensor(int i){
    return(LineSensors[i].ReadCenterSensor());
  }

  bool SkriBot::ReadLineSensor(int i){
    bool logicPositions[3]; 
    LineSensors[i].ReadAllSensors(logicPositions);
    return(logicPositions[0] || logicPositions[1] || logicPositions[2]);
  }

  
  void SkriBot::Move(char Dir,int ms){
      switch(Dir){
        case 'F':
                  for(int kk = 0; kk < LeftRotors.size(); kk++){
                    LeftRotors[kk].Move('F');
                  }
          
                  for(int zz = 0; zz < RightRotors.size(); zz++){
                    RightRotors[zz].Move('B');
                  }
        break;
        
        case 'B':
                  for(int kk = 0; kk < LeftRotors.size(); kk++){
                    LeftRotors[kk].Move('B');
                  }
          
                  for(int zz = 0; zz < RightRotors.size(); zz++){
                    RightRotors[zz].Move('F');
                  }
        break;

        case 'L':
                  for(int kk = 0; kk < LeftRotors.size(); kk++){
                    LeftRotors[kk].Move('B');
                  }
          
                  for(int zz = 0; zz < RightRotors.size(); zz++){
                    RightRotors[zz].Move('B');
                  }
         break;

         case 'R':
                  for(int kk = 0; kk < LeftRotors.size(); kk++){
                    LeftRotors[kk].Move('F');
                  }
          
                  for(int zz = 0; zz < RightRotors.size(); zz++){
                    RightRotors[zz].Move('F');
                  }
         break;

        case 'S' :
                  for(int kk = 0; kk < LeftRotors.size(); kk++){
                    LeftRotors[kk].Stop(0);
                  }
          
                  for(int zz = 0; zz < RightRotors.size(); zz++){
                    RightRotors[zz].Stop(0);
                  }
         break; 
//*******************************************************************************
         case 'K' :
                  for(int kk = 0; kk < LeftRotors.size(); kk++){
                    LeftRotors[kk].Move('F');
                  }
         break;

         case 'Z' :
                  for(int kk = 0; kk < LeftRotors.size(); kk++){
                    LeftRotors[kk].Move('B');
                  }
         break;

         case 'M' :
                  for(int kk = 0; kk < RightRotors.size(); kk++){
                    RightRotors[kk].Move('F');
                  }
         break;

         case 'N' :
                  for(int kk = 0; kk < RightRotors.size(); kk++){
                    RightRotors[kk].Move('B');
                  }
         break;

         case 'Y' :
                  for(int kk = 0; kk < LeftRotors.size(); kk++){
                    LeftRotors[kk].Stop(0);
                  }
         break;

         case 'X' :
                  for(int kk = 0; kk < LeftRotors.size(); kk++){
                    RightRotors[kk].Stop(0);
                  }
         break;

      }
        
        if(ms > 0 ){
          delay(ms);
      for(int kk = 0; kk < LeftRotors.size(); kk++){
                    LeftRotors[kk].Stop(0);
                  }
          
      for(int zz = 0; zz < RightRotors.size(); zz++){
                    RightRotors[zz].Stop(0);
                  }
        }
  }

    void SkriBot::TurnLeft(int ms){Move('Z',ms);}
    void SkriBot::TurnRight(int ms){Move('M',ms);}
    void SkriBot::FaceLeft(int ms){Move('L',ms);}
    void SkriBot::FaceRight(int ms){Move('R',ms);}
    void SkriBot::MoveForward(int ms){Move('F',ms);}
    void SkriBot::MoveBack(int ms){Move('B',ms);}
    void SkriBot::Stop(){Move('S',-1);}

