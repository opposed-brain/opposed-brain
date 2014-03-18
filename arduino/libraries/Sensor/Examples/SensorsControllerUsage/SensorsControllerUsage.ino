#include <Sensor.h>
#include <DigitalSensor.h>
#include <TemperatureSensorLM35.h>
#include <SensorsController.h>

SensorsController * sc;

void setup()
{
  Serial.begin(9600);
  sc = new SensorsController(4);
  sc->setPrinter(Serial);

  sc->addSensor(new DigitalSensor(7, "BT"));
  sc->addSensor(new Sensor(A3, "JX", 1000));
  sc->addSensor(new Sensor(A4, "JY", 500));
  sc->addSensor(new TemperatureSensorLM35(A2, "TD", 300));
}

void loop()
{
  sc->process();
  delay(10);
}
