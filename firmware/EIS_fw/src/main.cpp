#include <Arduino.h>
#include <BluetoothSerial.h>

String device_name = "ESP32-DEMO-BOARD-1" ;
u_int8_t active   = 111;
u_int8_t sendtemp = 001;
u_int8_t sendhumi = 002;
u_int8_t lit_on   = 101;
u_int8_t lit_off  = 100;

int temperature, humidity;
int relaycontrol;

String receive,send,nametag;

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
    receive = SerialBT.readString();
    Serial.println(receive);
    if(receive == device_name){
      SerialBT.println(active);
      Serial.println("ESP32: Name Request Received");
    }
    receive = SerialBT.readString();
    if(receive == sendtemp){
      SerialBT.println(temperature);
      Serial.println("Sending Temperature" + temperature);
    }
    else if (receive == sendhumi){
      SerialBT.println(humidity);
      Serial.println("Sending Humidity" + humidity);
    }
    receive = SerialBT.readString();
    if(receive == lit_on){
      relaycontrol = 1;
      Serial.println("Light is ON");
    }
    else if (receive == lit_off){
      relaycontrol = 0;
      Serial.println("Light is OFF");
    }
  }
  else{
     Serial.println("IDLE: Waiting for data");
  }
  receive = "";
  delay(500);
}