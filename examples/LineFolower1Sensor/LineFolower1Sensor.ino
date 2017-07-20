#include <SkriBot.h>
/*
 * In this example we present the most basic algorithm for line followe with one sensor only. Robot will search for the line by turning Right if it sees the line and turning left if it don't.
 * 
 * Connections for robot:
 * 
 * Left Rotor on digital pins: 6 - speed PIN, 7 - direction PIN
 * Right Rotor on digital pins: 5 - speed PIN, 4 - direction PIN
 * 
 * Line dtector on ANALOG pin 0
 *
 *IMPORTANT!!!!: Sensor needs to calibrat! after the code starts you need to put sensor above line and above background of the line to let it save raw 
 * values for those two . Calibration takes about 10 seconds.
 */
SkriBot robot;
                        
void setup() {
  robot.AddLineSensor(0,"Center");         //Adding line sensor and gi

  robot.AddDCRotor(6,7,"Left");          //adding rotors for movement
  robot.AddDCRotor(5,4,"Right");
  robot.SetSpeed(250);
}

void loop() {
  if(robot.ReadLineSensor("Center")){           //Chcecking if sensor is detecting the line below it.
    
    robot.TurnLeft(200);                		// Turning Left
                      
  }else{
    
    robot.TurnRight(200);               		//Turning Right  
  }

}
