#ifndef LineSensor3_H
#define LineSensor3_H
#include "Arduino.h"
#include <QTRSensors.h>
#define NUM_SENSORS             3  // number of sensors used
#define NUM_SAMPLES_PER_SENSOR  4  // average 4 analog samples per sensor reading
#define EMITTER_PIN             2  // emitter is controlled by digital pin 2
  
  class LineSensor
 {
  public:
    LineSensor(int pinLeft,int pinCenter,int pinRight);
    bool ReadLeftSensor();
    bool ReadRightSensor();
    bool ReadCenterSensor();
    void calibrate();
    void ReadAllSensors(bool *arr);
    void SetLogicBorder(int border);
  private:
  	QTRSensorsAnalog *qtra;
  	int logicBorder;
  	unsigned char sensorAddressArray[6];  //sensor read out is from 0 to 1000 where 0 is minimum reflectance(line) and 1000 is maximum reflectance(no line) need to be set for some value to recognise line under sensor
 };
 #endif
