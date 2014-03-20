#include "DigitalSensor.h"

DigitalSensor::DigitalSensor(byte pin, const char * name) : Sensor(pin, name) {}

DigitalSensor::DigitalSensor(byte pin, const char * name, int interval) : Sensor(pin, name, interval) {}

DigitalSensor::~DigitalSensor() {}

int DigitalSensor::read() {
    return this->readDigital();
}
