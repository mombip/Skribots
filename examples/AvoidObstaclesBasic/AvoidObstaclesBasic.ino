#include <SkriBot.h>
 /* In this example we present the simplest obstacle avoiding algorithm:
 * 
 * If you see obstacle on right side - Turn Left
 * If you see obstacle on left  side - Turn Right 
 * 
 * Connections for robot:
 * Left Rotor on digital PIN 9
 * Right Rotor on digital PIN 10
 * 
 * Distance detectors needs two pins to be conected:
 * 
 * Detector on the Left Side of the robot:
 * ECHO on pin  7
 * TRIGER on pin 6
 * 
 * DEetector on the Right Side of the robot:
 * ECHO on pin  12
 * TRIGER on pin 11
 *
 * WARNING!!!: You need to make tests to set optimal angle od distance detectors. 
 * Pointing them right ahead is not always the best option...
 *
 */
  SkriBot robot;                                  //defining our hero
  int LeftSensor,RightSensor;  
void setup() {
  robot.AddRotor(9,"Left");                       //adding Rotors
  robot.AddRotor(10,"Right");
  
  robot.AddDistSensor(12,11,"Left");              //adding Distance sensors 
  robot.AddDistSensor(7,6,"Right");

}

void loop() {
   LeftSensor = robot.ReadLeftDistSensor(15);       //Read distance to neares obstacle from both sensors up to 15 cm
   RightSensor = robot.ReadRightDistSensor(15);  

   if(LeftSensor == 15 && RightSensor == 15){       // There is no obstacles near both sensors -  move forward
      robot.MoveForward();
   }else if(LeftSensor < 15){                       // Obstacle near Left Sensor - avoid it by turning Right
      robot.TurnRight();
   }else if(RightSensor < 15){                      // Obstacle near Right Sensor - avoid it by turning Left
      robot.TurnLeft();
   }
   
}
