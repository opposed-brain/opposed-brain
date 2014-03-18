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
    if(p != NULL) {
      this->p->print("NS");
      this->p->println(newSensor->getName());
    }
  } else {
    if(p != NULL) {
      this->p->println("ER03");
    }
  }
}

void SensorsController::process() {
  // if printer didn't setup
  if(p == NULL) {
    return;
  }
  for(byte i = 0; i < countSensors; i++) {
    if(sensors[i]->isNeedRead()) {
      p->print(sensors[i]->getName());
      p->println(sensors[i]->read());
    }
  }
}

void SensorsController::setPrinter(Print & printer){
    this->p = & printer;
}
