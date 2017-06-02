#include <SkriBot.h>

/*In this example robot has got two rotors one for each side, and two LEDs coresponding to each rotor.
 * LEDs signalize which rotor is working at the moment;
 * Connections for robot:
 * Left Rotor on digital PIN 6
 * Right Rotor on digital PIN 7
 * Left Rotor LED on digital PIN 2
 * Right Rotor LED on digital PIN 3
 * 
 * IMPORTANT!!!
 * Timmings for turns are set for example values, when building own robot you should do some tests to set good working turning times.
 */
 
SkriBot robot;                      //defining our hero

void setup() {
  
    robot.AddRotor(9,"Left");           //Adding rotors
    robot.AddRotor(10,"Right");

    robot.AddLED(6,"LeftRotorLED");    //Adding LEDs
    robot.AddLED(7,"RightRotorLED");
    
}
void loop() {
        robot.TurnOnLED("LeftRotorLED");    //Turn leds ON
        robot.TurnOnLED("RightRotorLED");
        
        robot.MoveForward(2000);             //Go forward for 2 s
        
        robot.TurnOffLED("LeftRotorLED");
        robot.TurnOffLED("RightRotorLED");

        robot.TurnOnLED("LeftRotorLED");
        
        robot.FaceLeft(1000);                //Face Left for 1000ms
        
        robot.TurnOffLED("LeftRotorLED");

        robot.TurnOnLED("LeftRotorLED");    //Turn leds ON
        robot.TurnOnLED("RightRotorLED");
        
        robot.MoveForward(2000);             //Go Forward for 2 s
        
        robot.TurnOffLED("LeftRotorLED");
        robot.TurnOffLED("RightRotorLED");

        robot.TurnOnLED("RightRotorLED");
        
        robot.FaceLeft(1000);                //Face Left for 1000ms
        
        robot.TurnOffLED("RingtRotorLED");
  
  
  
  

}
