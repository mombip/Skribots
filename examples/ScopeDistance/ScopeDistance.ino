#include <SkriBot.h>

SkriBot robot;          //defining our Robot
int degree = 90;
int left;
int kat = 900;
bool LeftSensor;
bool RightSensor;
bool CenterSensor;
long int STA;
long int STO;
void setup() {
  robot.AddScope(7,6,9,"Main");
  robot.AddRotor(8,"Right",1535);
  robot.AddRotor(10,"Left",1460);
  robot.AddLineSensor(2,"LEFT");         //Adding line sensors
  robot.AddLineSensor(0,"CENTER");
  robot.AddLineSensor(1,"RIGHT");
  robot.Stop();
 
  
}
void RoundObstacle(){
    robot.Stop();
    robot.FaceRight(kat);
    robot.SetScopeAngle("Main",180);
    delay(200);
          STA = millis();
          while(robot.GetScopeDistance("Main")  < 30){
            robot.MoveForward();
            delay(250);
          }
          robot.MoveForward(1000);
          STO = millis();
          robot.Stop();
          robot.FaceLeft(kat);
          delay(250);
          
          while(robot.GetScopeDistance("Main") > 30){
             robot.MoveForward();
             delay(250);
          }
          delay(250);
          while(robot.GetScopeDistance("Main")  < 30){
            robot.MoveForward();
            delay(250);
          }
          robot.MoveForward(500);
          robot.FaceLeft(kat);
          robot.MoveForward(STO-STA);
          robot.FaceRight(kat);
          robot.SetScopeAngle("Main",90);
  
}
int Scan(){
  delay(1000);
  float L = robot.GetScopeDistance("Main");
  int LiM;
  float LiT;
  int leftCounter = 0;
  int rightCounter = 0;
  for(int i = 0; i < 9; i++){
    delay(400);
    leftCounter++;
    robot.SetScopeAngle("Main",degree + i*10);
    LiM = robot.GetScopeDistance("Main");
    LiT = L/cos((float)3.14*i*10/180);
    Serial.print(i);
    Serial.print(" ");
    Serial.println(LiT);
    if(sqrt((LiT-LiM)*(LiT-LiM)) > 5)break;
  }
  delay(500);
  robot.SetScopeAngle("Main",90);
   for(int i = 0; i < 9; i++){
    delay(250);
    rightCounter++;
    robot.SetScopeAngle("Main",degree - i*10);
    LiM = robot.GetScopeDistance("Main");
    LiT = L/cos((float)3.14*i*5/180);
    Serial.print(i);
    Serial.print(" ");
    Serial.println(LiT);
    if(sqrt((LiT-LiM)*(LiT-LiM)) > 5)break;
  }
  robot.SetScopeAngle("Main",90);
  delay(500);
  if(leftCounter > rightCounter){
     return(1);
  }else if(leftCounter < rightCounter){
     return(2);
  }else{
     return(0);
  }
}

void loop() {
  delay(100);
  while(robot.GetScopeDistance("Main") > 10){
LeftSensor     = robot.ReadLineSensor("LEFT");
CenterSensor  = robot.ReadLineSensor("RIGHT");
RightSensor   = robot.ReadLineSensor("CENTER");       // Reading from line sensors
  
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
  RoundObstacle();

}
