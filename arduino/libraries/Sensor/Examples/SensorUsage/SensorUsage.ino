#include <Sensor.h>

// new Sensor named SA on A3 pin
Sensor mySensor(A3, "SA");

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if(mySensor.isNeedRead()) {
    int val = mySensor.read();
    Serial.print(mySensor.getName());
    Serial.println(val);
  }
  delay(100);
}
