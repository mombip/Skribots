#include <SkriBot.h>
/*In this example robot will be controlled by your smartphone using ToothFairy App.
 * WARNING!!!: Application must be installed on your Smartphone sad thing is, that the application works ONLY FOR ANDROID. 
 * You can download it on Android from store for free: https://play.google.com/store/apps/details?id=com.avrthing.toothfairyfree
 * 
 * Robot configuration in this example is:
 * -Left Rotor on digital PIN 9
 * -Right Rotor on digital PIN 10
 * 
 * -Bluetooth adapter connected to Arduino RX and TX pins
 * 
 * WARNING!!!: Bluetooth adapter MUST BE DISCONNECTED when uploading the code (there is only one Serial port on Arduino Uno and adapter will block the Arduino-PC communication)!!!
 * 
 * After uploading code to the robot you should connect with robot with the app click the 'choose device' button and pick HT BT adapter, and enjoy controlling your robot with your smartphone!
 * If you will have more question about using ToothFairy App, you can visit: http://avrthing.com/toothfairy/
 *
 *
 * IMPORTANT!!!
 * Timmings for turns are set for example values, when building own robot you should do some tests to set good working turning times.
 */
 
  SkriBot robot;                           //Defining our hero
  
  BlueDentist *myDentist;                  // Object that will handle communication between our robot and Android.

  BDBTN *FButton;                          //Buttons for ToothFairy app
  BDBTN *LButton;
  BDBTN *RButton;
  
void setup() {
  robot.AddRotor(9,"Left");               //adding rotors
  robot.AddRotor(10,"Right");

   
  FButton   = new BDBTN("Forward");       //creating buttons in ToothFairy Software
  LButton   = new BDBTN("Left");
  RButton   = new BDBTN("Right");

  myDentist = new BlueDentist(9600);      //initializing Andrioi connection 
  
   myDentist->add(FButton);               //adding buttons to Andriod app GUI
   myDentist->add(LButton);
   myDentist->add(RButton);
   
}

void loop() {
  

  if(FButton->getPresses()){
    
      FButton->reset();                   //Reseting button to wait for another click.
    
      robot.MoveForward(500);             //Move Forward for 500ms.           
  }
  if(LButton->getPresses()){
    
      LButton->reset();                   //Reseting button to wait for another click.
    
      robot.FaceLeft();                   //Face Left.    
  }
  if(RButton->getPresses()){  
    
      RButton->reset();                   //Reseting button to wait for another click. 
  
      robot.FaceRight();                  //Fece Right.
  }    
    
  myDentist->run();                       //Sending information to Android GUI.

}
