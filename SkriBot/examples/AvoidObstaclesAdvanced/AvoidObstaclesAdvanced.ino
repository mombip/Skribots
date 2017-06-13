#include <SkriBot.h>
 /* In this example we present the more advance obstacle avoiding algorithm, which is more complexed then the basic 
 *  form and allows our robot to escape from cornerners and avoid difficult obstacles.
 *  
 *  We decide which way to turn by comparing sesnors readouts not simply turning if we see anything. 
 *  
 *  If there will be a situaton that the robot will turn left after turning right we are probably in the corner... 
 *  It's time to make a big turn and get away! See the code below for details
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
  SkriBot robot;                        //defining our hero
  int LeftSensor,RightSensor;           //variables for sensor readout
  int lastLeftSensor,lastRightSensor;   //variable for sensor readouts from previous decision making
void setup() {
  robot.AddRotor(9,"Left");             //adding Rotors
  robot.AddRotor(10,"Right");
  
  robot.AddDistSensor(12,11,"Left");   //adding Distance Sensors  and naming them "Left and Right";
  robot.AddDistSensor(7,6,"Right");

}

void loop() {
    LeftSensor = robot.ReadDistSensor("Left",10);
    RightSensor = robot.ReadDistSensor("Right",10);         //Reading from distance sensors up to 10 cm.
    if(LeftSensor > RightSensor){                           //checking previous readout
        if(RightSensor > lastRightSensor){        
          robot.TurnRight(300);                              // Turning Right  
        }else{
          robot.TurnLeft(600);                              // We turned Left and now we are turning Right again?! We are probably in the corner lets escape!
        } 
    }
    if(RightSensor > LeftSensor){
      if(LeftSensor > lastLeftSensor ){
        robot.TurnLeft(300);                                 // Turning Left
      }
      else{
        robot.TurnRight(600);                                 // We turned Right and now we are turning Left again?! We are probably in the corner lets escape!
      }
    }
    else{
      robot.MoveForward();                                   //Move Forward if there are no obstacles in th way.                                 
    }
    lastRightSensor = RightSensor;
    lastLeftSensor = LeftSensor;                             //Remembering last readouts

}
