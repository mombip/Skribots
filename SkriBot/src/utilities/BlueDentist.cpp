#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <Arduino.h>
#include "BlueDentist.h"
#include <string.h>
/*syntax for commands to this interface follow:
Example NAME\tATTR\tVAL
a buffer is created to store the current command
when a numerical 1 is received the interface is reset and following bytes are placed into the buffer
when a numerical 2 is received the command is carried out
this leaves as a command string to be parsed


the NAME portion of this is used to find the appropriate control
*/ 
#define MAXCMDSIZE 30


//functions for BDControl

  BDControl::BDControl(char* myName)
  {
    name = myName;
  }
  
//functions for button BDBTN  
  

  char BDBTN::getPresses()
  {
    return presses;
  }
  
  BDBTN::BDBTN(char *mName) :BDControl(mName)
  {
    presses = 0;
  }
  void BDBTN::onClick()
  {
    presses++;
  }
  void BDBTN::sendVal(char *)
  {}
  void BDBTN::setVal(char *val, char *)
  {}
  void BDBTN::publish()
  {
    Serial.write(1);
    Serial.write("CTRL\t");
    Serial.write(name);
    Serial.write("\tBTN\tNA");
    Serial.write(2);
  }
  int BDBTN::runCmd(char *cmd, char *attr, char *value)
  {
    if(!strcmp(cmd, "SET"))
     {
      onClick();
     }
    return 1;
  }
 
  void BDBTN::reset()
  {
    presses = 0;
  }

  //FUNCTIONS FOR BDTEXTFIELD 
  
  

  BDTextField::BDTextField(char *mName) : BDControl(mName)
  {
    int len = MAXCMDSIZE - strlen(mName) - 9;
    
    mValue = new char[len];
    mValue[0] = 0;  
}
  int BDTextField::runCmd(char *cmd, char *attr, char *value)
  {
    if(!strcmp(cmd, "SET"))
    {
      strcpy(mValue, value);
      return 1;
    }
    else
    return 0;
  }
  void BDTextField::publish()
  {
    Serial.write(1);
    Serial.write("CTRL\t");
    Serial.write(name);
    Serial.write("\tTXT\tNA");
    Serial.write(2);
    
  }
  char *BDTextField::getVal()
  {
    return mValue;
  }
  void BDTextField::sendVal(char *)
  {}
  void BDTextField::setVal(char *val, char *)
  {}
//Funtions for BDLogField

  BDLogField::BDLogField(char *mName) : BDControl(mName)
  {
    
  }
  void BDLogField::publish()
  {
    Serial.write(1);
    Serial.write("CTRL\t");
    Serial.write(name);
    Serial.write("\tLOG\tNA");
    Serial.write(2);
  }
  void BDLogField::print(char *me)
  {
    int i = 0;
    while(me[i] != 0)
    {
      if(me[i] == '\t' || me[i] ==1 || me[i] ==2)
        me[i] = '_';
      i++;
    }
    Serial.write(1);
    Serial.write("APP\t");
    Serial.write(name);
    Serial.write("\tTXT\t");
    Serial.write(me);
    Serial.write(2);
    
  }
  void BDLogField::println(char *me)
  {
    print(me);
    print("\n");
    
  }

  //Functions for BDSlider
  
  int BDSlider::runCmd(char *cmd, char *attr, char *value)
  {
    //message(cmd);
    //message(attr);
   // message(value);
    if(!strcmp(cmd, "GET"))
    {
      sendVal(attr);
      return 1;
    } 
      else if(!strcmp(cmd, "SET"))
      {
        setVal(attr, value);
        return 1;
      }
      else
        return 0;
  
  }
  int BDSlider::getVal()
  {
    return val;
  }
  char *BDSlider::toString()
  {
    static char retVal[6];
    itoa(val, retVal, 10);
    return retVal;
  }
  void BDSlider::message(char *msg)
  {
    Serial.write("\x01MESSAGE\t ");
    Serial.write(msg);
    Serial.write("\x02");
  }

  BDSlider::BDSlider(char *mName) :BDControl(mName)
  {
    val = 0;
    minimum= 0;
    maximum = 255;
  }
 
  void BDSlider::sendVal(char *attr)
  {
    char buf[7];
    if(!strcmp(attr, "VALUE"))
    itoa(val, buf, 10);
    else if(!strcmp(attr, "MAX"))
    itoa(maximum, buf, 10);
    else if(!strcmp(attr, "MIN"))
    itoa(minimum, buf, 10);
    
    Serial.write("\x01");
    Serial.write("SET\t");
    Serial.write(name);
    Serial.write("\t");
    Serial.write(attr);
    Serial.write("\t");
    Serial.write(buf); 
    Serial.write("\x02");
  }
  void BDSlider::setVal(char *attr, char *newVal)
  {  
    if(!strcmp(attr, "VALUE"))
      val = atoi(newVal);
      else if(!strcmp(attr, "MIN"))
        minimum = atoi(newVal);
        else if(!strcmp(attr, "MAX"))
         maximum = atoi(newVal);
   }
  void BDSlider::publish()
  {
    Serial.write(1);
    Serial.write("CTRL\t");
    Serial.write(name);
    Serial.write("\tSLD\tNA");
    Serial.write(2);
  }
//functions for BDNumField

  BDNumField::BDNumField(char *mName) : BDControl(mName)
  {
    mValue = 0;
  }
  int BDNumField::runCmd(char *cmd, char *attr, char *value)
  {
    if(!strcmp(cmd, "SET"))
    {
      mValue = atoi(value);
    }
    else
    return 0;
  }
   char *BDNumField::toString()
  {
    static char retVal[6];
    itoa(mValue, retVal, 10);
    Serial.print(retVal);// for debug
    return retVal;
  }
  void BDNumField::publish()
  {
    Serial.write(1);
    Serial.write("CTRL\t");
    Serial.write(name);
    Serial.write("\tNUM\tNA");
    Serial.write(2);
    
  }
  void BDNumField::setVal(int me)
  {
    mValue = me;
  }
  int BDNumField::getVal()
  {
    return mValue;
  }
  void BDNumField::sendVal(char *)
  {}
  void BDNumField::setVal(char *val, char *)
  {}

//functions for BDContainer
  BDContainer::BDContainer()
  {
    curTrol = 0;
    next = 0;
  }
  BDContainer::BDContainer(BDControl *me)
  {
    curTrol = me;
    next = 0;
  }
  void BDContainer::setCur(BDControl *mCur)
  {
    curTrol = mCur;
  }
  void BDContainer::setNext(BDControl *mNext)
  {
    next = new BDContainer();
    next->setCur(mNext);
  }
  BDContainer *BDContainer::getNext()
  {
    return next;
  }
  BDContainer *BDContainer::getCur()
  {
    return this;
  }
  BDControl *BDContainer::getControl()
  {
    return curTrol;
  }
//functions for blue dentist

  BlueDentist::BlueDentist(int myBaudRate)
  {
    Serial.begin(myBaudRate);
    index = MAXCMDSIZE;
    first = 0;
    ignore = false;
  }
  void BlueDentist::run()
   {
      
  //   Serial.write("running\n");
      char curByte = Serial.read();
      if(curByte != -1)
      {
      //Serial.print(curByte);
      }
       //Serial.print("\n");
      
      if(curByte == -1)
      {
        
      }
      else if(curByte==1)
      {
        index = 0;
        ignore = false;
      //  Serial.print(curByte);
       // Serial.print("\n");
      }
      else if(curByte==2)
      {
    //    Serial.print(curByte);
      //  Serial.print("\n");
     //  Serial.println(buf);
        buf[index] = 0;
   //     Serial.println(buf);
        if(!ignore)
        execute();
      }
      else 
      {
       // Serial.print(curByte);
        //Serial.print("\n");
        buf[index] = curByte;
        if(index < MAXCMDSIZE-1)
          index++; 
          else
            ignore = true;
          
      }
   }
   void BlueDentist::add(BDControl *me)
   {
     BDContainer *tmp = first;
     if(tmp == 0)
     {
       first = new BDContainer(me);
     }
     else
     {
       while(tmp->getNext() != 0)
       {
         tmp = tmp->getNext();  
       }
       tmp->setNext(me);
     }
   }
   
   void BlueDentist::execute()
   { 
       //Serial.println(buf);//for debugging
       if(!strcmp(buf, "REPORT"))
       {
         BDContainer *me = first;
         while(me != 0)
         {
           me->getControl()->publish();
           me= me->getNext();
         }
       }
       else
       {
      char *myCmd, *myName, *myAttr, *myVal;
      myCmd = strtok(buf,"\t");
      myName = strtok(NULL, "\t");
      myAttr = strtok(NULL, "\t");
      myVal = strtok(NULL, "\t");
      BDContainer *myContainer = first;
   //   Serial.println(myCmd);
     // Serial.println(myName);
    //  Serial.println(myAttr);
     // Serial.println(myVal);
      while(myContainer != 0)
      {
        if(strcmp(myContainer->getControl()->name, myName)==0)
          {
            break;
          }
          else
          myContainer = myContainer->getNext();
          
      }
      if(myContainer != 0)
        myContainer->getControl()->runCmd(myCmd, myAttr, myVal);
      
     }
      
   }


