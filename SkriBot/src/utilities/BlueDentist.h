

/*syntax for commands to this interface follow:
Example <NAME:ATTR=VAL>
a buffer is created to store the current command
when a < is received the interface is reset and following bytes are placed into the buffer
when a > is received the command is carried out
this leaves as a command string to be parsed:


the NAME portion of this is used to find the appropriate control, then the string is passed to that BDControls runCmd(char *) function
*/ 
#ifndef bluedentist_h
#define bluedentist_h

#include <Arduino.h>
#define MAXCMDSIZE 30

class BDControl
{
  public:
  char *name;
  
  

  virtual void sendVal(char *){}
  virtual void setVal(char *val, char *){}
  virtual void publish(){}
  virtual int runCmd(char *, char *, char *){} 
  
  BDControl(char* myName);
};
class BDBTN: public BDControl
{
  char presses;
  
  public:
  
  char getPresses();
  
  BDBTN(char *mName);
  
  void onClick();
  void sendVal(char *);
  void setVal(char *val, char *);
  void publish();
  int runCmd(char *cmd, char *attr, char *value);
  void reset();
 };
class BDTextField: public BDControl
{
  //longest command will be SET:NAME:TXT:[value] = name length plus value length plus 9 + 1 for null termination
  char *mValue;
  
  public:
  BDTextField(char *mName);
  int runCmd(char *cmd, char *attr, char *value);
  void publish();
  char *getVal();
  void sendVal(char *);
  void setVal(char *val, char *);
  
  
};
class BDLogField: public BDControl
{
  public:
  BDLogField(char *mName);
  void publish();
  void print(char *me);
  void println(char *me);
};

class BDSlider: public BDControl
{
 
  int val;
  int minimum;
  int maximum;
  public:
  int runCmd(char *cmd, char *attr, char *value);
  int getVal();
  char *toString();
  void message(char *msg);
  BDSlider(char *mName);
 
  void sendVal(char *attr);
  void setVal(char *attr, char *newVal);
  void publish();
};

class BDNumField: public BDControl
{
   //longest command will be SET:NAME:TXT:[value] = name length plus value length plus 9 + 1 for null termination
  int mValue;
  
  public:
  BDNumField(char *mName);
  char *toString();
  void publish();
  int getVal();
  void sendVal(char *);
  void setVal(char *val, char *);
  void setVal(int me);
  int runCmd(char *cmd, char *attr, char *value);
};

class BDContainer
{
  BDControl *curTrol;
  BDContainer *next;
  public:
  BDContainer();
  BDContainer(BDControl *me);
  void setCur(BDControl *mCur);
  void setNext(BDControl *mNext);
  BDContainer *getNext();
  BDContainer *getCur();
  BDControl *getControl();
};

class BlueDentist
{
  BDContainer *first;
  char buf[MAXCMDSIZE];
  char index;
  boolean ignore;
  public:
  BlueDentist(int myBaudRate);
  void run();
  void add(BDControl *me);
   
  void execute();
   
};



#endif