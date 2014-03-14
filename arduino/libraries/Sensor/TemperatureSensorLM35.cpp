#include "TemperatureSensorLM35.h"

TemperatureSensorLM35::TemperatureSensorLM35(byte pin, char * name, int interval) : Sensor(pin, name, interval) {}

int TemperatureSensorLM35::read() {
    return Sensor::read() * T_KOEF;
}
