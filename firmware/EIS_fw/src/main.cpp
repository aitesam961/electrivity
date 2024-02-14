#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#define SERVICE_UUID        "6e400001-b5a3-f393-e0a9-e50e24dcca9e"
#define TEMPERATURE_UUID    "6e400002-b5a3-f393-e0a9-e50e24dcca9e"
#define CONTROL_UUID        "6e400003-b5a3-f393-e0a9-e50e24dcca9e"
#define BLE_NAME            "ESP32-Sensor-Node"

BLEServer *pServer = NULL;
BLECharacteristic *pCharacteristicTemperature = NULL;
BLECharacteristic *pCharacteristicControl = NULL;

bool deviceConnected = false;
bool controlValueChanged = false;
byte lastControlValue = 0;

int generateTemperature() {
  return random(20, 41); // Random number between 20 and 40
}

class MyServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) {
    deviceConnected = true;
  };

  void onDisconnect(BLEServer* pServer) {
    deviceConnected = false;
  }
};

class MyCharacteristicCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
    controlValueChanged = true;
    lastControlValue = *pCharacteristic->getValue().c_str();
  }
};

void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(0));

  BLEDevice::init(BLE_NAME);
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  BLEService *pService = pServer->createService(SERVICE_UUID);

  pCharacteristicTemperature = pService->createCharacteristic(TEMPERATURE_UUID,BLECharacteristic::PROPERTY_NOTIFY);
  pCharacteristicTemperature->addDescriptor(new BLE2902());

  pCharacteristicControl = pService->createCharacteristic(CONTROL_UUID,BLECharacteristic::PROPERTY_WRITE);
  pCharacteristicControl->setCallbacks(new MyCharacteristicCallbacks());

  pService->start();

  pServer->getAdvertising()->start();
  Serial.println("Waiting for a connection...");
}

void loop() {
  if (deviceConnected) {
    int temperature = generateTemperature();
    pCharacteristicTemperature->setValue((uint8_t*)&temperature, sizeof(temperature));
    pCharacteristicTemperature->notify();
    Serial.println("Temperature sent: " + String(temperature) + " °C");

    if (controlValueChanged) {
      Serial.println("Control signal received: " + String(lastControlValue));
      // Handle control signal here
      controlValueChanged = false;
    }

    delay(1000);
  }
}
