#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>


// BLE GATT UUIDs defination. (Custom UUIDs)
#define SERVICE_UUID        "6e420000-b5a3-f393-e0a9-e50e24dcca9e"
#define SWITCH_1_UUID       "6e420010-b5a3-f393-e0a9-e50e24dcca9e"
#define SWITCH_2_UUID       "6e420011-b5a3-f393-e0a9-e50e24dcca9e"
#define LIGHT_1_UUID        "6e420012-b5a3-f393-e0a9-e50e24dcca9e"
#define LIGHT_2_UUID        "6e420013-b5a3-f393-e0a9-e50e24dcca9e"
#define BLE_NAME            "Controller Device"

#define DHTTYPE DHT11 

// Define sensor pins
#define LIGHT_1_PIN   4
#define LIGHT_2_PIN   15

#define SWITCH_1_PIN  32
#define SWITCH_2_PIN  33

#define LED_PIN   2

BLEServer *pServer = NULL;
BLECharacteristic *pCharacteristicSwitch1 = NULL;
BLECharacteristic *pCharacteristicSwitch2 = NULL;
BLECharacteristic *pCharacteristicLight1  = NULL;
BLECharacteristic *pCharacteristicLight2  = NULL;

bool deviceConnected = false;
bool control1ValueChanged = false;
bool control2ValueChanged = false;
byte lastControl1Value = 0;
byte lastControl2Value = 0;

class MyServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) {
    deviceConnected = true;
  };

  void onDisconnect(BLEServer* pServer) {
    deviceConnected = false;
    pServer->getAdvertising()->start();
    Serial.println("Waiting for client to connect.......");
  }
};

class MyCharacteristicCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
    if (pCharacteristic == pCharacteristicLight1) {
      control1ValueChanged = true;
      lastControl1Value = *pCharacteristic->getValue().c_str();
    } 
    if (pCharacteristic == pCharacteristicLight2) {
      control2ValueChanged = true;
      lastControl2Value = *pCharacteristic->getValue().c_str();
    }
  }
};


void setup() {
  Serial.begin(115200);


  // Initialize BLE GATT Service with SERVICE_UUID
  BLEDevice::init(BLE_NAME);
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Create BLE GATT Chracteristics
  pCharacteristicSwitch1 = pService->createCharacteristic(SWITCH_1_UUID,BLECharacteristic::PROPERTY_NOTIFY);
  pCharacteristicSwitch1->addDescriptor(new BLE2902());

  pCharacteristicSwitch2 = pService->createCharacteristic(SWITCH_2_UUID,BLECharacteristic::PROPERTY_NOTIFY);
  pCharacteristicSwitch2->addDescriptor(new BLE2902());

  pCharacteristicLight1 = pService->createCharacteristic(LIGHT_1_UUID,BLECharacteristic::PROPERTY_WRITE);
  pCharacteristicLight1->setCallbacks(new MyCharacteristicCallbacks());

  pCharacteristicLight2 = pService->createCharacteristic(LIGHT_2_UUID,BLECharacteristic::PROPERTY_WRITE);
  pCharacteristicLight2->setCallbacks(new MyCharacteristicCallbacks());
  
  // Start all services
  pService->start();

  pServer->getAdvertising()->start();
  Serial.println("Waiting for client to connect.......");
  
  pinMode(SWITCH_1_PIN, INPUT_PULLUP);
  pinMode(SWITCH_2_PIN, INPUT_PULLUP);

  pinMode(LIGHT_1_PIN, OUTPUT);
  pinMode(LIGHT_2_PIN, OUTPUT);  

  pinMode(LED_PIN,OUTPUT);

  // Initially pulled HIGH to turn OFF (the sink)
  digitalWrite(LIGHT_1_PIN, HIGH);
  digitalWrite(LIGHT_2_PIN, HIGH);

  
}

void loop() {
  
  if (deviceConnected) {

    digitalWrite(LED_PIN,LOW);
    
    u_int8_t switch1 = (digitalRead(SWITCH_1_PIN) == HIGH)? 0:1;
    u_int8_t switch2 = (digitalRead(SWITCH_2_PIN) == HIGH)? 0:1;

    pCharacteristicSwitch1->setValue((uint8_t*)&switch1, sizeof(switch1));
    pCharacteristicSwitch1->notify();
    Serial.println("Switch 1 sent: " + String(switch1));

    pCharacteristicSwitch2->setValue((uint8_t*)&switch2, sizeof(switch2));
    pCharacteristicSwitch2->notify();
    Serial.println("Switch 2 sent: " + String(switch2));

    if (control1ValueChanged) {
      Serial.println("Control 1 Changed: " + String(lastControl1Value));
      if(lastControl1Value == 0x01){
        digitalWrite(LIGHT_1_PIN, LOW);
      }
      else{
        digitalWrite(LIGHT_1_PIN, HIGH);
      }
      control1ValueChanged = false;
    }
    if (control2ValueChanged) {
      Serial.println("Control 2 Changed: " + String(lastControl2Value));
      if(lastControl2Value == 0x01){
        digitalWrite(LIGHT_2_PIN, LOW);
      }
      else{
        digitalWrite(LIGHT_2_PIN, HIGH);
      }
      control1ValueChanged = false;
    }
  }
  else{
    Serial.println("Client not connected.....");
    digitalWrite(LED_PIN,HIGH);
  }

  delay(500);
}
