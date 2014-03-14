#ifndef DIGITAL_SENSOR_H
#define DIGITAL_SENSOR_H

#include "Sensor.h"

class DigitalSensor : public Sensor
{
  public:
    DigitalSensor(byte pin, char * name, int interval);
    virtual ~DigitalSensor();
    virtual int read();
};

#endif // DIGITAL_SENSOR_H
