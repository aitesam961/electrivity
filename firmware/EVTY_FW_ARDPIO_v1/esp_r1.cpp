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


const char* ssid            = "Germanium";
const char* password        = "Germanium";
const char* mqttServer      = "192.168.0.101";
const int mqttPort          = 1883;
const char* mqttClientID = "ESP32_ROOM_1";

const char* top_swh_1 = "prism/board1/switch1";
const char* top_swh_2 = "prism/board1/switch2";
const char* top_swh_3 = "prism/board1/switch3";
const char* top_swh_4 = "prism/board1/switch4";

const char* top_tch_1 = "prism/board1/touch1";
const char* top_tch_2 = "prism/board1/touch2";
const char* top_tch_3 = "prism/board1/touch3";
const char* top_tch_4 = "prism/board1/touch4";

const int switch1_pin     = 15;
const int switch2_pin     = 4;
const int switch3_pin     = 16;
const int switch4_pin     = 17;
 
const int touch1_pin      = 13;
const int touch2_pin      = 33;
const int touch3_pin      = 14;
const int touch4_pin      = 27;
 
const int led_pin         = 2 ;  

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  if (String(topic) == top_swh_1) {`
    if (message == "on") {
      digitalWrite(switch1_pin, LOW);
      Serial.println("Relay-1 turned ON");
    } else if (message == "off") {
      digitalWrite(switch1_pin, HIGH);
      Serial.println("Relay-1 turned OFF");
    }
  }
  if (String(topic) == top_swh_2) {
    if (message == "on") {
      digitalWrite(switch2_pin, LOW);
      Serial.println("Relay-2 turned ON");
    } else if (message == "off") {
      digitalWrite(switch2_pin, HIGH);
      Serial.println("Relay-2 turned OFF");
    }
  }
  if (String(topic) == top_swh_3) {
    if (message == "on") {
      digitalWrite(switch3_pin, LOW);
      Serial.println("Relay-3 turned ON");
    } else if (message == "off") {
      digitalWrite(switch3_pin, HIGH);
      Serial.println("Relay-3 turned OFF");
    }
  }
  if (String(topic) == top_swh_4) {
    if (message == "on") {
      digitalWrite(switch3_pin, LOW);
      Serial.println("Relay-4 turned ON");
    } else if (message == "off") {
      digitalWrite(switch3_pin, HIGH);
      Serial.println("Relay-4 turned OFF");
    }
  }
}


void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT Broker...");
    if (client.connect(mqttClientID)) {
        digitalWrite(led_pin, LOW);
        Serial.println("connected");
        client.subscribe(top_swh_1);
        client.subscribe(top_swh_2);
        client.subscribe(top_swh_3);
        client.subscribe(top_swh_4);
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
  pinMode(touch1_pin, INPUT_PULLUP);
  pinMode(touch2_pin, INPUT_PULLUP);
  pinMode(touch3_pin, INPUT_PULLUP);
  pinMode(touch4_pin, INPUT_PULLUP);

  pinMode(switch1_pin, OUTPUT);
  pinMode(switch2_pin, OUTPUT);
  pinMode(switch3_pin, OUTPUT);
  pinMode(switch4_pin, OUTPUT);

  digitalWrite(switch1_pin, HIGH);
  digitalWrite(switch2_pin, HIGH);
  digitalWrite(switch3_pin, HIGH);
  digitalWrite(switch4_pin, HIGH);
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
    digitalWrite(switch1_pin, HIGH);
    digitalWrite(switch2_pin, HIGH);
    digitalWrite(switch3_pin, HIGH);
    digitalWrite(switch4_pin, HIGH);
    reconnect();
  }
  client.loop();

  int switchState1 = digitalRead(touch1_pin);
  if (switchState1 == HIGH) {
    client.publish(top_tch_1, "high");
    Serial.println("Touch-1 HIGH");
  }
  else{
    client.publish(top_tch_1, "low");
    Serial.println("Touch-1 LOW");
  }
  int switchState2 = digitalRead(touch2_pin);
  if (switchState2 == HIGH) {
    client.publish(top_tch_2, "high");
    Serial.println("Touch-2 HIGH");
  }
  else{
    client.publish(top_tch_2, "low");
    Serial.println("Touch-2 LOW");
  }
  int switchState3 = digitalRead(touch3_pin);
  if (switchState3 == HIGH) {
    client.publish(top_tch_3, "high");
    Serial.println("Touch-3 HIGH");
  }
  else{
    client.publish(top_tch_3, "low");
    Serial.println("Touch-3 LOW");
  }
  int switchState4 = digitalRead(touch4_pin);
  if (switchState4 == HIGH) {
    client.publish(top_tch_4, "high");
    Serial.println("Touch-4 HIGH");
  }
  else{
    client.publish(top_tch_4, "low");
    Serial.println("Touch-4 LOW");
  }
  delay(100);
}
