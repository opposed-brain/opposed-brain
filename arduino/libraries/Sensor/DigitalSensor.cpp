#include "DigitalSensor.h"

DigitalSensor::DigitalSensor(byte pin, char * name, int interval) : Sensor(pin, name, interval) {}

DigitalSensor::~DigitalSensor() {}

int DigitalSensor::read() {
    return this->readDigital();
}
