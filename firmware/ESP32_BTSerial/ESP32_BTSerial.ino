#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32"); // Bluetooth device name
}

void loop() {
  if (SerialBT.available()) {
    Serial.print("Received: ");
    Serial.println(SerialBT.readString());
  }

  SerialBT.println("Hello Python!"); // Send data
  delay(300);

  
}
