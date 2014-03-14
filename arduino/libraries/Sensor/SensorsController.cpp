#include "SensorsController.h"

SensorsController::SensorsController()
{
    countSensors = 0;
    p = NULL;
}

SensorsController::~SensorsController() {}

void SensorsController::addSensor(Sensor * newSensor){
  sensors[countSensors++] = newSensor;
  if(p != NULL) {
    this->p->print("Sensor detect ");
    this->p->println(newSensor->getName());
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
