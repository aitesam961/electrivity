/*
*
*  Project: PRISM
*  An Egde IoT System for home automation
*  
*  Author: aitesam961
*  
*  This is the main source file for ESP32 firmware written in arduino framework
*  
*
*/
#include <WiFi.h>
#include <PubSubClient.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>


const char* ssid            = "LIAMAVENTA";
const char* password        = "78900789";
const char* mqttServer      = "192.168.1.94";
const int mqttPort          = 1883;
const char* mqttClientID    = "ESP32_SENSOR_ ROOM_1";

const char* top_dht_temp    = "prism/sboard1/sensor1";
const char* top_dht_humi    = "prism/sboard1/sensor2";
const char* top_ldr_status  = "prism/sboard1/sensor3";

const int DHTPIN            = 15;
const int ldr_pin           = 4;

const int led_pin         = 2 ;  

#define DHTTYPE DHT11

WiFiClient espClient;
PubSubClient client(espClient);

DHT dht(DHTPIN, DHTTYPE);

void callback(char* topic, byte* payload, unsigned int length) {
    String message = "";
    for (int i = 0; i < length; i++) {
        message += (char)payload[i];
    }
}


void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT Broker...");
    if (client.connect(mqttClientID)) {
        digitalWrite(led_pin, LOW);
        Serial.println("connected");
    } else {
        Serial.print("failed, rc=");
        Serial.print(client.state());
        Serial.println(" trying again in 5 seconds");
        digitalWrite(led_pin, HIGH);
        delay(2500);
        digitalWrite(led_pin, LOW);
        delay(2500);
    }
  }
}



void setup() {
  Serial.begin(115200);
  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin, HIGH);
  pinMode(ldr_pin, INPUT);

  
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
    digitalWrite(led_pin, HIGH);
    reconnect();
  }
  client.loop();

  int ldrState = digitalRead(ldr_pin);
  if (ldrState == HIGH) {
    client.publish(top_ldr_status, "high");
    Serial.println("LDR HIGH");
  }
  else{
    client.publish(top_ldr_status, "low");
    Serial.println("LDR LOW");
  }

  u_int8_t dht_temp = dht.readTemperature();
  u_int8_t dht_humi = dht.readHumidity();

  client.publish(top_dht_temp, String(dht_temp).c_str());
  Serial.println("TEMP");
  Serial.print(String(dht_temp).c_str());
  client.publish(top_dht_humi, String(dht_humi).c_str());
  Serial.println("HUMI");
  Serial.print(String(dht_humi).c_str());

  int ldr_state = digitalRead(ldr_pin);
  if (ldr_state == HIGH) {
    client.publish(top_ldr_status, "high");
    Serial.println("Light HIGH");
  }
  else{
    client.publish(top_ldr_status, "low");
    Serial.println("Light LOW");
  }
  delay(100);
}
