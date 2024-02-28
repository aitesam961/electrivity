# ELECTRIVITY: An EDGE IOT SYSTEM
A wireless IoT system with AI enhanced processing and automation.

### List of Hardware Components
- Check [HARDWARE](hardware/readme.md)
- Check [MQTT Topics](application/topics_mqtt.md)


## STATUS
In Progress.

- Hardware and Firmware : @aitesam961
- Mobile application and Linux Program: Hassan & Fawad

## File Naming Conventions

The project files follows a uniform file naming convention across the repository.

### Design Files: 
Design files should be placed under respective folders and DE project sources should be named as:
```
EVTY_FW_PIO_V1
EVTY: Electrivity
FW: Firmware 
PIO: Development Environment
V1: Version
```

### Documents:
Documents must follow the naming order as the example below

```
EVTY_pres_sysd_v1.xls
EVTY: Electrivity
pres: presentation
sysd: Descriptor
v1: version
.xls: extension
```


### Directory Tree

```
.
├── application
│   ├── mqttapp.py
│   ├── mqtt_switch_control.sh
│   └── topics_mqtt.md
├── archive
│   ├── _apppy
│   │   ├── blecclient.py
│   │   ├── blehandshake.py
│   │   └── bleserial.py
│   ├── BT_MAC_scan
│   │   └── BT_MAC_scan.ino
│   ├── _EIS_fw
│   │   ├── ESP_Control.cpp
│   │   ├── ESP_SENSOR.cpp
│   │   ├── firmware.code-workspace
│   │   ├── include
│   │   │   └── README
│   │   ├── lib
│   │   │   └── README
│   │   ├── platformio.ini
│   │   ├── src
│   │   │   └── main.cpp
│   │   └── test
│   │       └── README
│   └── ESP32_BTSerial
│       └── ESP32_BTSerial.ino
├── docs
│   ├── EIS1ABrev1v0.pdf
│   ├── EIS_BOM_s1 - Sheet1.pdf
│   ├── EIS_clist_v1.1.pdf
│   ├── EIS_poc_demo.drawio
│   ├── EIS_poc_demo.png
│   ├── im1.jpeg
│   ├── im2.jpeg
│   ├── im3.jpeg
│   ├── image_2024-02-22_001135263.png
│   ├── poc_demo.md
│   ├── poc_demo.pdf
│   ├── prism_cp0.1_vx.pdf
│   ├── prism-xp1_swd.drawio
│   ├── prism-xp1_swd.png
│   ├── prism-xp1_sysd.drawio
│   ├── prism-xp1_sysd.jpg
│   ├── readme.md
│   └── Report.pdf
├── firmware
│   ├── electrivity_fw
│   │   ├── esp32_s1.cpp
│   │   ├── esp_r1.cpp
│   │   ├── include
│   │   │   └── README
│   │   ├── lib
│   │   │   └── README
│   │   ├── platformio.ini
│   │   ├── src
│   │   │   └── main.cpp
│   │   └── test
│   │       └── README
│   └── readme.md
├── hardware
│   ├── physical_addresses.md
│   └── readme.md
├── osimage
│   └── readme.md
├── README.md
└── reference
    └── mqtt-v5.0-os.pdf

```