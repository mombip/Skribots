#include <SkriBot.h>
/*
 * In this example we present Line folower which uses three sensors from the LineSenosor bar. 
 * We can read specific values for each of 3 detectors in Line detector left, right and center instead of reading from it as one. 
 * 
 * Algorithm is explained in comments below.
 * 
 * Connections for robot:
 * 
 * Left Rotor on digital PIN 9
 * Right Rotor on digital PIN 10
 * 
 * Line dtector on ANALOG pins 0,1,2
 * 
 *IMPORTANT!!!!: Sensor needs to calibrat! after the code starts you need to put sensor above line and above background of the line to let it save raw 
 * values for those two . Calibration takes about 10 seconds.
 *
 * WARNING!!!: This configuration requires line detector to be perallel to the line, and due to small detector size it will work good only for thin lines and small robots. 
 */
SkriBot robot;
void setup() {
  robot.AddLineSensor(2,1,0);         //Adding line sensor
  
  robot.AddRotor(9,"Left");           //Adding Rotors
  robot.AddRotor(10,"Right");
}
void loop() {

if(!robot.ReadLeftLineSensor() && !robot.ReadRightLineSensor() && robot.ReadCenterLineSensor()){  //if we see line on the middle sensor we can proceed forward
    robot.MoveForward(150);
}else if(robot.ReadLeftLineSensor()){                                                             // Line is on the Left we want to have it in the middle - let's turn Right
  
    robot.Move('Z',150);                                                                          //Secial Function for moving only Right wheel
    
}else if(robot.ReadRightLineSensor()){                                                            // Line is on the Right we want to have it in the middle - let's turn Left
  
    robot.Move('M',150);                                                                          //Secial Function for moving only Left wheel
    
}else if(robot.ReadRightLineSensor() && robot.ReadCenterLineSensor()){                            //Sharp Right turn
    robot.TurnRight(300);
}else if(robot.ReadLeftLineSensor() && robot.ReadCenterLineSensor()){                             //Sharp Left  turn
    robot.TurnLeft(300);
}
else{
  robot.TurnRight(100);
}

    
    
}
