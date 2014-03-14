#ifndef TEMPERATURE_SENSOR_LM35_H
#define TEMPERATURE_SENSOR_LM35_H

#include "Sensor.h"

class TemperatureSensorLM35 : public Sensor
{
  public:
    TemperatureSensorLM35(byte pin, char * name, int interval);
    virtual int read();

  private:
    // 0.48828125
    static const double T_KOEF = 5.0 * 100 / 1024;
};

#endif // TEMPERATURE_SENSOR_LM35_H
