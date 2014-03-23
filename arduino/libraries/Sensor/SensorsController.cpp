#include "SensorsController.h"

SensorsController::SensorsController(byte maxCount) {
    this->sensors = new Sensor*[maxCount];
    this->maxCount = maxCount;
    this->countSensors = 0;
    this->p = NULL;
}

SensorsController::~SensorsController() {
    delete [] this->sensors;
}

void SensorsController::addSensor(Sensor * newSensor) {
  if (this->countSensors < this->maxCount) {
    sensors[this->countSensors++] = newSensor;
    this->transmitPackage("NS", this->countSensors);
  } else {
    this->transmitPackage("ER", 3);
  }
}

void SensorsController::process() {
  for(byte i = 0; i < countSensors; i++) {
    if(sensors[i]->isNeedRead()) {
      this->transmitPackage(sensors[i]->getName(), sensors[i]->read());
    }
  }
}

void SensorsController::transmitPackage(const char * name, const int value) {
  if(NULL != p) {
    char package [] = {0xDE, 0xAD, name[0], name[1], value >> 8, value & 0xFF, 0xFE, 0xED};
    p->write(package);
  }
}

void SensorsController::setPrinter(Print & printer) {
  this->p = & printer;
}
