#include "Sensor.h"

Sensor::Sensor() {}

Sensor::Sensor(byte pin, const char * name, int interval) {
  this->pin = pin;
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
  this->interval = interval;
  this->timeToRead = 0;
  pinMode(pin, INPUT);
}

Sensor::~Sensor() {
  delete this->name;
}

int Sensor::read() {
  return this->readAnalog();
}

char * Sensor::getName() {
  return this->name;
}

bool Sensor::isNeedRead() {
  return millis() >= this->timeToRead;
}


// Protected methods

int Sensor::readAnalog() {
  return this->readUsing(&analogRead);
}

int Sensor::readDigital() {
  return this->readUsing(&digitalRead);
}


// Private methods

int Sensor::readUsing(int (*readFunction)(byte)) {
  int sum = 0;
  for(byte i = 0; i < READ_COUNT; i++) {
    sum += readFunction(this->pin);
    delay(READ_DELAY);
  }
  this->updateTimeToRead();
  return sum / READ_COUNT;
}

void Sensor::updateTimeToRead() {
  this->timeToRead = millis() + this->interval;
}
