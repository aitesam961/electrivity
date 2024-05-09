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
#include<Arduino.h>
#include <WiFi.h>
#include "EmonLib.h"  
#include <PubSubClient.h>

#define  mains_voltage 220;

const char* ssid            = "secureLAN";
const char* password        = "secureLAN";
const char* mqttServer      = "10.42.0.1";
const int mqttPort          = 1883;
const char* mqttClientID    = "ESP32_ROOM_4";

const char* top_swh_1 = "prism/board4/switch1";
const char* top_swh_2 = "prism/board4/switch2";
const char* top_swh_3 = "prism/board4/switch3";
const char* top_swh_4 = "prism/board4/switch4";

const char* top_tch_1 = "prism/board4/touch1";
const char* top_tch_2 = "prism/board4/touch2";
const char* top_tch_3 = "prism/board4/touch3";
const char* top_tch_4 = "prism/board4/touch4";

const char* top_pch_1 = "prism/board4/pwrch1";
const char* top_pch_2 = "prism/board4/pwrch2";
const char* top_pch_3 = "prism/board4/pwrch3";
const char* top_pch_4 = "prism/board4/pwrch4";


const int switch1_pin     = 15;
const int switch2_pin     = 4;
const int switch3_pin     = 16;
const int switch4_pin     = 17;
 
const int touch1_pin      = 19;
const int touch2_pin      = 21;
const int touch3_pin      = 22;
const int touch4_pin      = 23;
 
const int led_pin         = 2 ;  

const int cts1_pin        = 33;
const int cts2_pin        = 32;
const int cts3_pin        = 35;
const int cts4_pin        = 34;

const int num_i_read      = 4;

uint8_t ttemp1 = 0;
uint8_t ttemp2 = 0;
uint8_t ttemp3 = 0;
uint8_t ttemp4 = 0;

double    Irms1 = 0;
double    Irms2 = 0;
double    Irms3 = 0;
double    Irms4 = 0;

u_int16_t powerch1, powerinitch1 = 0;
u_int16_t powerch2, powerinitch2 = 0;
u_int16_t powerch3, powerinitch3 = 0;
u_int16_t powerch4, powerinitch4 = 0;

char pch1[16];
char pch2[16];
char pch3[16];
char pch4[16];

uint16_t ct_iter_trace  = 0;

int avgfifo1[num_i_read] = {0};
int avgfifo2[num_i_read] = {0};
int avgfifo3[num_i_read] = {0};
int avgfifo4[num_i_read] = {0};


WiFiClient espClient;
PubSubClient client(espClient);

EnergyMonitor emon1;
EnergyMonitor emon2; 
EnergyMonitor emon3;  
EnergyMonitor emon4; 

void callback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  if (String(topic) == top_swh_1) {
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
      digitalWrite(switch4_pin, LOW);
      Serial.println("Relay-4 turned ON");
    } else if (message == "off") {
      digitalWrite(switch4_pin, HIGH);
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
  pinMode(touch1_pin, INPUT);
  pinMode(touch2_pin, INPUT);
  pinMode(touch3_pin, INPUT);
  pinMode(touch4_pin, INPUT);

  pinMode(switch1_pin, OUTPUT);
  pinMode(switch2_pin, OUTPUT);
  pinMode(switch3_pin, OUTPUT);
  pinMode(switch4_pin, OUTPUT);

  emon1.current(cts1_pin, 32.59);  
  emon2.current(cts2_pin, 32.59); 
  emon3.current(cts3_pin, 32.59); 
  emon4.current(cts4_pin, 32.59); 

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
  
  uint8_t switchState1 = digitalRead(touch1_pin);
  if (switchState1 == 1) {
    if(ttemp1 == 0){
      client.publish(top_tch_1, "high");
      Serial.println("Touch-1 HIGH");
      ttemp1 = 1;
    }
  }
  else{
    ttemp1 = 0;
    Serial.println("Resetting_TTEMP");
  }

  uint8_t switchState2 = digitalRead(touch2_pin);
  if (switchState2 == 1) {
    if(ttemp2 == 0){
      client.publish(top_tch_2, "high");
      Serial.println("Touch-2 HIGH");
      ttemp2 = 1;
    }
  }
  else{
    ttemp2 = 0;
    Serial.println("Resetting_TTEMP");
  }

  uint8_t switchState3 = digitalRead(touch3_pin);
  if (switchState3 == 1) {
    if(ttemp3 == 0){
      client.publish(top_tch_3, "high");
      Serial.println("Touch-3 HIGH");
      ttemp3 = 1;
    }
  }
  else{
    ttemp3 = 0;
    Serial.println("Resetting_TTEMP");
  }

  uint8_t switchState4 = digitalRead(touch4_pin);
  if (switchState4 == 1) {
    if(ttemp4 == 0){
      client.publish(top_tch_4, "high");
      Serial.println("Touch-4 HIGH");
      ttemp4 = 1;
    }
  }
  else{
    ttemp4 = 0;
    Serial.println("Resetting_TTEMP");
  }

  Irms1 = emon1.calcIrms(1480);
  Irms2 = emon2.calcIrms(1480);
  Irms3 = emon3.calcIrms(1480);
  Irms4 = emon4.calcIrms(1480);

  powerch1  = (Irms1/100)*mains_voltage;
  powerch2  = (Irms2/100)*mains_voltage;
  powerch3  = (Irms3/100)*mains_voltage;
  powerch4  = (Irms4/100)*mains_voltage;

if(ct_iter_trace < num_i_read){
  avgfifo1[ct_iter_trace] = powerch1;
  avgfifo2[ct_iter_trace] = powerch2;
  avgfifo3[ct_iter_trace] = powerch3;
  avgfifo4[ct_iter_trace] = powerch4;

  ct_iter_trace +=  1;
}
else{
  ct_iter_trace = 0;

  powerinitch1  = ((avgfifo1[0]+avgfifo1[1]+avgfifo1[2]+avgfifo1[3])/4);
  powerinitch2  = ((avgfifo2[0]+avgfifo2[1]+avgfifo2[2]+avgfifo2[3])/4);
  powerinitch3  = ((avgfifo3[0]+avgfifo3[1]+avgfifo3[2]+avgfifo3[3])/4);
  powerinitch4  = ((avgfifo4[0]+avgfifo4[1]+avgfifo4[2]+avgfifo4[3])/4);

  powerinitch1  = powerinitch1 < 5 ? 0 : powerinitch1;
  powerinitch2  = powerinitch2 < 5 ? 0 : powerinitch2;
  powerinitch3  = powerinitch3 < 5 ? 0 : powerinitch3;
  powerinitch4  = powerinitch4 < 5 ? 0 : powerinitch4;

  // data type conversion for transfer
  snprintf(pch1, sizeof(pch1), "%u", powerinitch1);
  snprintf(pch2, sizeof(pch2), "%u", powerinitch2);
  snprintf(pch3, sizeof(pch3), "%u", powerinitch3);
  snprintf(pch4, sizeof(pch4), "%u", powerinitch4);

  Serial.print("Power Consumption, Channel 1  : "); Serial.println(pch1);
  Serial.print("Power Consumption, Channel 2  : "); Serial.println(pch2);
  Serial.print("Power Consumption, Channel 3  : "); Serial.println(pch3);
  Serial.print("Power Consumption, Channel 4  : "); Serial.println(pch4);

  client.publish(top_pch_1, pch1);
  client.publish(top_pch_2, pch2);
  client.publish(top_pch_3, pch3);
  client.publish(top_pch_4, pch4);
}

  delay(100);
  Serial.println("Tick..........!");
}
