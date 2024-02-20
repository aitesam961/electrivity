/*

  Project: PRISM
  An Egde IoT System for home automation
  
  Author: aitesam961
  
  This is the main source file for ESP32 firmware written in arduino framework
  -- Paste the code here for compilation

*/
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "M.INAM UL HAQ";
const char* password = "Easy@13290.Wifi";
const char* mqttServer = "192.168.8.103";
const int mqttPort = 1883;
const char* mqttClientID = "ESP32Client1";
const char* switchTopic = "esp32/switch";
const char* ledTopic = "esp32/led";

WiFiClient espClient;
PubSubClient client(espClient);

const int switchPin = 4;
const int ledPin = 2;


void callback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  if (String(topic) == ledTopic) {
    if (message == "on") {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED turned ON");
    } else if (message == "off") {
      digitalWrite(ledPin, LOW);
      Serial.println("LED turned OFF");
    }
  }
}


void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect(mqttClientID)) {
      Serial.println("connected");
      client.subscribe(ledTopic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}



void setup() {
  Serial.begin(115200);
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
}



void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  int switchState = digitalRead(switchPin);
  if (switchState == HIGH) {
    client.publish(switchTopic, "high");
    Serial.println("Switch HIGH");
  }
}
