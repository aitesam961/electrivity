#include <Arduino.h>
#include <BluetoothSerial.h>

u_int8_t device_name = 255 ;
u_int8_t active   = 111;
u_int8_t sendtemp = 001;
u_int8_t sendhumi = 002;
u_int8_t lit_on   = 101;
u_int8_t lit_off  = 100;
u_int8_t meActive = 0;

int temperature, humidity;
int relaycontrol;

uint8_t received,send;

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  Serial.println("System Booting...");
  SerialBT.begin(device_name); // Bluetooth device name
  Serial.println(device_name + " is live");

}

void loop() {
  temperature = random(20,30);
  humidity    = random(40,60);
 
  
  if (SerialBT.available()) {
    received   = SerialBT.read();

    if(received == device_name){
      SerialBT.write(active);
      meActive    = 111;
    }


  }
  else{
     Serial.println("IDLE: Waiting for data");
  }
  received = 0;
  delay(500);
}