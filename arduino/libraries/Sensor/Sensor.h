#ifndef SENSOR_H
#define SENSOR_H

// include Arduino basic header
#include <Arduino.h>

// Arduino reads data this count times 
#define READ_COUNT 5

// Arduino waits this time before next reading
#define READ_DELAY 5

// Base class for sensors
class Sensor {
  public:
    /**
      pin - arduino pin that sensor connected;
      name - name of sensor;
      delay - interval for reading and sending data
    */
    Sensor(byte, char *, int = 1000);
    virtual ~Sensor();
    /**
      analogRead uses by default
    */
    virtual int read();
    char * getName();
    bool isNeedRead();

  protected:
    byte pin;
    int readAnalog();
    int readDigital();

  private:
    char * name;
    int interval;
    int timeToRead;

    /**
      Reads several times from func and returns average value
    */
    int readUsing(int (*)(byte));
    void updateTimeToRead();
};

#endif // SENSOR_H
