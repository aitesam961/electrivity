#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#include <DHT.h>

// BLE GATT UUIDs defination. (Custom UUIDs)
#define SERVICE_UUID        "6e410000-b5a3-f393-e0a9-e50e24dcca9e"
#define TEMPERATURE_UUID    "6e410010-b5a3-f393-e0a9-e50e24dcca9e"
#define HUMIDITY_UUID       "6e410011-b5a3-f393-e0a9-e50e24dcca9e"
#define LIGHT_UUID          "6e410012-b5a3-f393-e0a9-e50e24dcca9e"
#define BLE_NAME            "Sensor Device"

#define DHTTYPE DHT11 

// Define sensor pins
#define DHT11_PIN 4
#define LDR_PIN   32

#define LED_PIN   2

BLEServer *pServer = NULL;
BLECharacteristic *pCharacteristicTemperature = NULL;
BLECharacteristic *pCharacteristicHumidity    = NULL;
BLECharacteristic *pCharacteristicLight       = NULL;

bool deviceConnected = false;
bool controlValueChanged = false;
byte lastControlValue = 0;


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
    controlValueChanged = true;
    lastControlValue = *pCharacteristic->getValue().c_str();
  }
};


DHT dht(DHT11_PIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

  dht.begin();


  // Initialize BLE GATT Service with SERVICE_UUID
  BLEDevice::init(BLE_NAME);
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Create BLE GATT Chracteristics
  pCharacteristicTemperature = pService->createCharacteristic(TEMPERATURE_UUID,BLECharacteristic::PROPERTY_NOTIFY);
  pCharacteristicTemperature->addDescriptor(new BLE2902());

  pCharacteristicHumidity = pService->createCharacteristic(HUMIDITY_UUID,BLECharacteristic::PROPERTY_NOTIFY);
  pCharacteristicHumidity->addDescriptor(new BLE2902());

  pCharacteristicLight = pService->createCharacteristic(LIGHT_UUID,BLECharacteristic::PROPERTY_NOTIFY);
  pCharacteristicLight->addDescriptor(new BLE2902());

  // Start all services
  pService->start();

  pServer->getAdvertising()->start();
  Serial.println("Waiting for client to connect.......");
  
  pinMode(LED_PIN,OUTPUT);
}

void loop() {
  
  if (deviceConnected) {
    digitalWrite(LED_PIN,LOW);
    // Read only when client is connected
    u_int8_t temperature = dht.readTemperature();
    u_int8_t humidity    = dht.readHumidity();
    bool lightstatus = (analogRead(LDR_PIN) >= 2950) ? false : true;

    pCharacteristicTemperature->setValue((uint8_t*)&temperature, sizeof(temperature));
    pCharacteristicTemperature->notify();
    Serial.println("Temperature sent: " + String(temperature) + " °C");

    pCharacteristicHumidity->setValue((uint8_t*)&humidity, sizeof(humidity));
    pCharacteristicHumidity->notify();
    Serial.println("Humidity sent: " + String(humidity) + " %");

    pCharacteristicLight->setValue((uint8_t*)&lightstatus, sizeof(lightstatus));
    pCharacteristicLight->notify();
    Serial.println("Light Status sent: " + String(lightstatus));

    
  }
  else{
    Serial.println("Client not connected.....");
    digitalWrite(LED_PIN,HIGH);
  }

  delay(500);
}
