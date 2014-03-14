#ifndef SENSORS_CONTROLLER_H
#define SENSORS_CONTROLLER_H

#include "Sensor.h"

/**
  Controller stores sensors, polls their for theirs data in their intervals
*/
class SensorsController {
  public:
    SensorsController();
    virtual ~SensorsController();
    // Stores sensor
    void addSensor(Sensor *);
    void process();
    // Set the printer that will be receive data
    void setPrinter(Print &);

  private:
    Sensor * sensors[10];
    byte countSensors;
    Print * p;
};

#endif // SENSORS_CONTROLLER_H
