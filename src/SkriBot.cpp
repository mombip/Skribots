#include "SkriBot.h"
 
  SkriBot::SkriBot(){
    
  }
  void SkriBot::AddRotor(int Pin, String Side, int neutral){
    ServoRotor rotor(Pin,Side,neutral);
     if(Side == "Left"){
      LeftRotors.push_back(rotor);
     }else if(Side == "Right"){
      RightRotors.push_back(rotor);
     }
  }

  void SkriBot::AddDistSensor(int EchoPin,int TrigPin,String name){
    DistSensor dsensor(EchoPin,TrigPin,name);
      DistSensors.push_back(dsensor);
  }

  void SkriBot::AddLineSensor(int pinL,String Name){
    LineSensor lsensor(pinL,Name);
    delay(500);
    LineSensors.push_back(lsensor);
  }

  void SkriBot::AddLED(int pin,String name){
    RobotLED led(pin,name);
    LEDs.push_back(led);
  }

  void SkriBot::AddScope(int EchoPin,int Trigg,int ServoPin,String Name){
    Scope scope(EchoPin,Trigg,ServoPin,Name);
    Scopes.push_back(scope);
  }

  void SkriBot::SetScopeAngle(String name,int deg){
    for(int zz = 0; zz < Scopes.size(); zz++){
                    if(Scopes[zz].GetName() == name){
                      Scopes[zz].SetAngle(deg);
                      break;
                    }
      }
  }

  int SkriBot::GetScopeDistance(String name){
    for(int zz = 0; zz < Scopes.size(); zz++){
                    if(Scopes[zz].GetName() == name){
                      return(Scopes[zz].GetDistance());
                      break;
                    }
      }
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

  bool SkriBot::ReadLineSensor(String name){ 
    for(int zz = 0; zz < LineSensors.size(); zz++){
                    if(LineSensors[zz].GetName() == name){
                      return(LineSensors[zz].ReadSensor());
                      break;
                    }
      }
    return(false);
  }

  int SkriBot::ReadDistSensor(String id, int max){
     for(int zz = 0; zz < DistSensors.size(); zz++){
                    if(DistSensors[zz].GetName() == id){
                      return(DistSensors[zz].ReadSensor(max));
                      break;
                    }
      }
      return(0);
  }


  
  void SkriBot::Move(char Dir,int ms){
      switch(Dir){
        case 'B':
                  for(int kk = 0; kk < LeftRotors.size(); kk++){
                    LeftRotors[kk].Move('F');
                  }
          
                  for(int zz = 0; zz < RightRotors.size(); zz++){
                    RightRotors[zz].Move('B');
                  }
        break;
        
        case 'F':
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

