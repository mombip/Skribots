#include <SkriBot.h>
/*
 * In this example we present basic algorithm for line followe with two line sensors. Robot will go forward if both don't see the line and lurn if one will. 
 * We want our robot to keep line between sensors.
 * 
 *  Connections for robot:
 * 
 * Left Rotor on digital PIN 9
 * Right Rotor on digital PIN 10
 * 
 * Line dtector 1 on ANALOG pin 0 on the LEFT side of Our Robot
 * Line dtector 2 on ANALOG pins 1 on the RIGHT side of Our Robot 
 * 
 *IMPORTANT!!!!: Sensor needs to calibrat! after the code starts you need to put sensor above line and above background of the line to let it save raw 
 * values for those two . Calibration takes about 10 seconds.
 */
SkriBot robot;
bool LEFTSens, RIGHTSens;
                        
void setup() {
  robot.AddLineSensor(0,"LEFT");         //Adding line sensor
  robot.AddLineSensor(1,"RIGHT");         // In order to refer to this sensor we need to give '1' as an argument to the reading sensor
                                      //functions if you will implement more sensors you can refere to each sensor by its number
  
  robot.AddRotor(9,"Left");           //Adding Rotors and definig which rotor is on which side
  robot.AddRotor(10,"Right");
}

void loop() {
  LEFTSens   = robot.ReadLineSensor("LEFT");   //Reading from first sensor
  RIGHTSens  = robot.ReadLineSensor("RIGHT");
  
  if(!LEFTSens && !RIGHTSens){           //Chcecking if both sensor are detecting the line below it.
    
    robot.MoveForward();                 // Going Forward
                      
  }else if(LEFTSens){                                 
    
    robot.TurnLeft(200);                 //Turning Left 
    
  }else if(RIGHTSens){                   //Reading from second sensor
    
    robot.TurnRight(200);                //Turning Right
  }

}
