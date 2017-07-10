#include <SkriBot.h>
/*
 * In this example we present Line folower which uses three sensors from the LineSenosor bar. 
 * We can read specific values for each of 3 detectors in Line detector left, right and center instead of reading from it as one. 
 * 
 * Algorithm is explained in comments below.
 * 
 * Connections for robot:
 * 
 * Left Rotor on digital pins: 6 - speed PIN, 7 - direction PIN
 * Right Rotor on digital pins: 5 - speed PIN, 4 - direction PIN
 * 
 * Line dtector on ANALOG pins 0,1,2
 * 
 *IMPORTANT!!!!: Sensor needs to calibrat! after the code starts you need to put sensor above line and above background of the line to let it save raw 
 * values for those two . Calibration takes about 10 seconds.
 *
 * WARNING!!!: This configuration requires line detector to be perallel to the line, and due to small detector size it will work good only for thin lines and small robots. 
 */

SkriBot robot;
bool LeftSensor;
bool RightSensor;
bool CenterSensor;
void setup() {
  robot.AddLineSensor(2,"LEFT");         //Adding line sensors
  robot.AddLineSensor(0,"CENTER");
  robot.AddLineSensor(1,"RIGHT");

  robot.AddDCRotor(6,7,"Left");          //adding rotors for movement
  robot.AddDCRotor(5,4,"Right");
}

void loop() {

LeftSensor 		= robot.ReadLineSensor("LEFT");
CenterSensor 	= robot.ReadLineSensor("RIGHT");
RightSensor		= robot.ReadLineSensor("CENTER");				// Reading from line sensors
	
if(!LeftSensor && !RightSensor && CenterSensor){  //if we see line on the middle sensor we can proceed forward
    robot.MoveForward();
}else if(LeftSensor){                                                             // Line is on the Left we want to have it in the middle - let's turn Right
  
    robot.Move('Z',150);                                                                          //Secial Function for moving only Right wheel
    
}else if(RightSensor){                                                            // Line is on the Right we want to have it in the middle - let's turn Left
  
    robot.Move('M',150);                                                                          //Secial Function for moving only Left wheel
    
}else if(CenterSensor && RightSensor){                            //Sharp Right turn
    robot.TurnRight(300);
}else if(LeftSensor && CenterSensor){                             //Sharp Left  turn
    robot.TurnLeft(300);
}
else{
  	robot.TurnRight(100);
}

    
    
}
