#include <SkriBot.h>

/*In this example robot has got two rotors one for each side, distance sensor and three LEDs showing distance from the nearest obstacle in front of it. 
 * 
 * Robot moves forward if there is no obstacle in front of it, gives a warninig if somthing is close, and stops 10 cm from obstacle to avoid collision.
 * 
 * Connections for robot:
 * Left Rotor on digital pins: 6 - speed PIN, 7 - direction PIN
 * Right Rotor on digital pins: 5 - speed PIN, 4 - direction PIN
 *
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

 #define ECHO_PIN 11
 #define TRIGGER_PIN 12

 #define STOP_LED_PIN 4
 #define WARNING_LED_PIN  3
 #define OK_LED_PIN 5

  SkriBot robot;    //defining our hero
  
   int distance;    //variable to keep distance from the obstacle

void setup() {

  robot.AddDCRotor(6,7,"Left");          //adding rotors for movement
  robot.AddDCRotor(5,4,"Right");
  robot.SetSpeed(250);
  
   robot.AddLED(STOP_LED_PIN,"STOPLED");         // Adding LEDs
   robot.AddLED(OK_LED_PIN,"OKLED");
   robot.AddLED(WARNING_LED_PIN,"WARNINGLED");

   robot.AddDistSensor(ECHO_PIN,TRIGGER_PIN,"Main"); // Adding Distance sensor and naming it "Main" we need to define on which 

}

void loop() {

 distance = robot.ReadDistSensor("Main",50); 		// Reading the distance to the nearest obstacle from our previously defined "Main" sensor up to 25 cm if nothing in range it returns 25 cm.

       if(distance == 50){
             //robot.TurnOnLED("OKLED");
             robot.SetSpeed(255);                // If no obastacle is in range go continuisly forward.
             robot.MoveBack();
       }else if(distance < 50 && distance > 20){
             //robot.TurnOffLED("OKLED");                // If  obastacle is in range go forward but be carful.
             //robot.TurnOnLED("WARNINGLED");
             robot.SetSpeed(200);
             robot.MoveBack();
       }else if(distance < 20){
             //robot.TurnOffLED("OKLED");                // If  obastacle is too close STOP the robot.
             //robot.TurnOnLED("STOPLED");
             //robot.TurnOffLED("WARNINGLED");
             robot.Stop();
       }
      
       delay(500);
 

 
}
