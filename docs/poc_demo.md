# Proof-of-Concept Demonstration

## Setup

###  ESP32-S1  (Server 1)

Basically a sensor device. Integrates a DHT-11 temperature, humidity sensor and an analog light sensor. The ESP32 advertises a BLE GATT server profile and allows connection with Raspberry pi Client against known UUIDs.

Temp, Humi and Light intensity, each has a unique GATT chracteristic.The system is powered by a micro-USB power adapter.


###  ESP32-S2  (Server 2)

Primarily acts as a relay controlling device. The GPIOs connect to a relay board. The resistors are for current limiting to keep ESP32 in safe operational range.The Relay board connects to a household Wall Switch board that has AC Bulbs for indication.

![Im1](docs/im1.jpeg)

Moreover, the pushbuttons emulate user actions against switches. (Demo Alternative until current sensors arrive).

The system is powered by power adapter directly from the socket.


### Raspberry pi Zero W Central Client

Pi Zero W acts as a central client. (Pi-5 is not in use because of missing accessories.)

It runs a python program with root permissions. Makes use of bluepy library for bluetooth Communication profiles.
The UUIDs and MAC addresses of server devices are already stored in the program.


### Wireless Access Point

Not neccessary but helps access the pi thorugh SSH for convenient configuration. Eventually, would allow for WAN connection to mobile app.

## Operation
This demonstration includes a sensor server and a control server. The wireless communication is implemented using BLE GATT standard communication protocol.

At the boot-up, the servers wait for the central client to connect. At this time, a blue LED on ESP32 is turned ON. The Raspberry pi client connects to servers using their MAC addresses that are pre-defined in the client application.

After successful pairing, Sensor Service reads the sensor data and transmits a GATT Chracterisitic for each field. Raspberry Pi reads the chracteristics and asserts the control signals accordingly.

### Operational Range

Using the BLE GATT channel with ESP32 connected to my Phone, I experienced a very good range of ~11 meters (apologies: 15 in the video was an approximate measurement). In case of ESP32 connected to raspberry pi zero w over BLE 4.2 GATT, I experienced the range dropping at ~4-5 meters.(BLE + WiFi active). So clearly, RPi is the bottleneck.

### Summary

This is the proof-of-concept demonstration of the system working with basic features as reading from sensors and toggling light switches.
Several improvements and additions have yet to be made.