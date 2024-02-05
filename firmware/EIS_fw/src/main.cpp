#include <Arduino.h>

#define LED_PIN 2


void setup(){
  Serial.begin(115200);
  Serial.print("Booting......");
  pinMode(LED_PIN, OUTPUT);


}
void loop(){
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);

}