# ELECTRIVITY: An EDGE IOT SYSTEM
A wireless IoT system with AI enhanced processing and automation.

### List of Hardware Components
- Check [HARDWARE](hardware/readme.md)
- Check [MQTT Topics](application/topics_mqtt.md)



## STATUS
In Progress.

- Hardware and Firmware : @aitesam961
- Mobile application and Linux Program: @Hassan & @Fawad

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

The provided FNC follows guidelines provided by [MIT Data Management:
File Organization documents](https://ocw.mit.edu/courses/res-str-002-data-management-spring-2016/497580bd31c004cc758a2afb0a115aa4_MITRES_STR_002S16_File.pdf)
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
│   ├── EVTY_arch_blueprint_v1.pdf
│   ├── EVTY_part_list_phase1_v1.pdf
│   ├── EVTY_part_list_prelim_v1.pdf
│   ├── EVTY_poc_demo_doc_v1.pdf
│   ├── EVTY_poc_demo_v1.drawio
│   ├── EVTY_poc_demo_v1.png
│   ├── EVTY_pres_phase1_v1.pdf
│   ├── im1.jpeg
│   ├── im2.jpeg
│   ├── im3.jpeg
│   ├── image_2024-02-22_001135263.png
│   ├── images
│   │   ├── image1.jpeg
│   │   ├── image2.jpeg
│   │   ├── image3.jpeg
│   │   ├── image4.jpeg
│   │   ├── image5.jpeg
│   │   └── image6.jpeg
│   ├── poc_demo.md
│   ├── prism-xp1_swd.drawio
│   ├── prism-xp1_swd.png
│   ├── prism-xp1_sysd.drawio
│   ├── prism-xp1_sysd.jpg
│   ├── readme.md
│   └── Report.pdf
├── firmware
│   ├── EVTY_FW_ARDPIO_v1
│   │   ├── debugger_esp.cpp
│   │   ├── esp32_r2.cpp
│   │   ├── esp32_r3.cpp
│   │   ├── esp32_r4.cpp
│   │   ├── esp32_s1.cpp
│   │   ├── esp_r1.cpp
│   │   ├── include
│   │   │   └── README
│   │   ├── lib
│   │   │   └── README
│   │   ├── platformio.ini
│   │   ├── src
│   │   │   ├── electrivity.code-workspace
│   │   │   └── main.cpp
│   │   └── test
│   │       └── README
│   ├── readme.md
│   └── test_builds
│       ├── r1_cRtos.c
│       └── s1_cRtos.c
├── hardware
│   ├── 3dmodel
│   │   ├── EVTY_stackupmodel_v1.blend
│   │   ├── EVTY_stackupmodel_v1.blend1
│   │   └── lib
│   │       ├── 4 Channel Relay Board.stl
│   │       ├── 4 Channel Relay Board.stp
│   │       ├── ESP32-DEVKITC-32D--3DModel-STEP-269445.STEP
│   │       ├── ESP32-DEVKITC-32D--3DModel-STEP-269445.stl
│   │       ├── m3-16mm.STEP
│   │       ├── m3-16mm.stl
│   │       ├── nut.STEP
│   │       ├── nut.stl
│   │       ├── Power_Board_asm.STEP
│   │       ├── Power_Board_asm.stl
│   │       ├── proto_7x5.stl
│   │       └── proto_7x5.stp
│   ├── physical_addresses.md
│   ├── readme.md
│   └── schem
│       └── EVTY_Schematics_brd_v1.0.pdf
├── linux_app
│   ├── mqttapp.py
│   ├── mqtt_switch_control.sh
│   └── topics_mqtt.md
├── mobile_app
│   └── EVTY_distribution_plan_v1.md
├── osimage
│   └── readme.md
├── README.md
└── reference
    ├── mqtt-v5.0-os.pdf
    └── TTP223.pdf

27 directories, 77 files

```