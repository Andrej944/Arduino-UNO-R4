#include <Arduino_CapacitiveTouch.h>

const int TOUCH_PIN = 2;
const int LED_PIN = 12;
const int TOUCH_THRESHOLD = 6000;

CapacitiveTouch touchSensor(TOUCH_PIN);

void setup() {
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);

  touchSensor.begin();
  touchSensor.setThreshold(TOUCH_THRESHOLD);

  Serial.print("Threshold seto to: ");
  Serial.println(touchSensor.getThreshold());
}

void loop() {
  int sensorValue = touchSensor.read();

  Serial.println(sensorValue);

  if(touchSensor.isTouched()){
    Serial.println("Touched!");
    digitalWrite(LED_PIN, HIGH);
  }
  else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(10);
}
