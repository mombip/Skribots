#include <SkriBot.h>

/*In this example robot has got two rotors one for each side, distance sensor and three LEDs showing distance from the nearest obstacle in front of it. 
 * 
 * Robot moves forward if there is no obstacle in front of it, gives a warninig if somthing is close, and stops 10 cm from obstacle to avoid collision.
 * 
 * Connections for robot:
 * Left Rotor on digital PIN 9
 * Right Rotor on digital PIN 10
 * "Safe Way" LED on digital PIN 2
 * "Warning" LED on digital PIN 3
 * "STOP" LED on PIN 4
 * 
 * Distance detector needs two pins to be conected:
 * ECHO on pin  7
 * TRIGER on pin 6
 * IMPORTANT!!!
 * Timmings for turns are set for example values, when building own robot you should do some tests to set good working turning times.
 */

  SkriBot robot;    //defining our hero
  
   int distance;    //variable to keep distance from the obstacle

void setup() {

   robot.AddRotor(9,"Left");           //Adding rotors
   robot.AddRotor(10,"Right");

   robot.AddLED(4,"STOPLED");         // Adding LEDs
   robot.AddLED(2,"OKLED");
   robot.AddLED(3,"WARNINGLED");

   robot.AddDistSensor(7,6,"Left"); // Adding Distance sensor and defining it as a center sensor

}

void loop() {

 distance = robot.ReadLeftDistSensor(25); 		// Reading the distance to the nearest obstacle up to 25 cm if nothing in range it returns 25 cm.

       if(distance == 25){
             robot.TurnOnLED("OKLED");                // If no obastacle is in range go continuisly forward.
             robot.MoveBack();
       }else if(distance < 25 && distance > 10){
             robot.TurnOffLED("OKLED");                // If  obastacle is in range go forward but be carful.
             robot.TurnOnLED("WARNINGLED");
             robot.MoveBack();
       }else if(distance < 10){
             robot.TurnOffLED("OKLED");                // If  obastacle is too close STOP the robot.
             robot.TurnOnLED("STOPLED");
             robot.TurnOffLED("WARNINGLED");
             robot.Stop();
       }
      
       delay(500);
 

 
}
