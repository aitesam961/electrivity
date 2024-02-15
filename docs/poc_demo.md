# Proof-of-Concept Demonstration

## Setup

###  ESP32-S1  (Server 1)

Basically a sensor device. Integrates a DHT-11 temperature, humidity sensor and an analog light sensor. The ESP32 advertises a BLE GATT server profile and allows connection with Raspberry pi Client against known UUIDs.

Temp, Humi and Light intensity, each has a unique GATT chracteristic.The system is powered by a micro-USB power adapter.


###  ESP32-S2  (Server 2)

Primarily acts as a relay controlling device. The GPIOs connect to a relay board. The resistors are for current limiting to keep ESP32 in safe operational range.The Relay board connects to a household Wall Switch board that has AC Bulbs for indication.

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


### Summary

This is the proof-of-concept demonstration of the system working with basic features as reading from sensors and toggling light switches.
Several improvements and additions have yet to be made.