#include <SkriBot.h>
 /* In this example we present the simplest obstacle avoiding algorithm:
 * 
 * If you see obstacle on right side - Turn Left
 * If you see obstacle on left  side - Turn Right 
 * 
 * Connections for robot:
 * 
 * Left Rotor on digital pins: 6 - speed PIN, 7 - direction PIN
 * Right Rotor on digital pins: 5 - speed PIN, 4 - direction PIN
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

  robot.AddDCRotor(6,7,"Left");          //adding rotors for movement
  robot.AddDCRotor(5,4,"Right");
  
  robot.AddDistSensor(12,11,"Left");              //adding Distance sensor and naming them "Left" and "Right". 
  robot.AddDistSensor(7,6,"Right");

}

void loop() {
   LeftSensor = robot.ReadDistSensor("Left",20);       //Read distance to neares obstacle from both sensors up to 15 cm. We use names that we give to our sensors to read from them.
   RightSensor = robot.ReadDistSensor("Right",20);  

   if(LeftSensor == 20 && RightSensor == 20){       // There is no obstacles near both sensors -  move forward
      robot.MoveForward();
   }else if(LeftSensor < 20){                       // Obstacle near Left Sensor - avoid it by turning Right
      robot.FaceRight();
   }else if(RightSensor < 20){                      // Obstacle near Right Sensor - avoid it by turning Left
      robot.FaceLeft();
   }
   
}
