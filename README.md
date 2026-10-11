# Electrivity — Edge IoT Home Automation

Electrivity is a wireless home automation project combining ESP32 devices, a Raspberry Pi edge host, and MQTT messaging. This repository contains firmware, Linux control scripts, hardware designs, setup notes, and prototype documentation. AI-enhanced processing and automation are part of the project vision.

**Status:** In progress. Some documents describe earlier BLE prototypes; the main firmware and Linux application use MQTT. The `mobile_app/` folder currently contains a device distribution plan.

## Start here

| Task | Entry point |
| --- | --- |
| Understand the system design | [Architecture blueprint](docs/EVTY_arch_blueprint_v1.pdf) |
| Review components | [Hardware component list](hardware/readme.md) |
| Work on ESP32 firmware | [Main source](firmware/EVTY_FW_ARDPIO_v1/src/main.cpp) and [PlatformIO configuration](firmware/EVTY_FW_ARDPIO_v1/platformio.ini) |
| Work on the Linux controller | [MQTT application](linux_app/mqttapp.py) |
| Understand device messaging | [MQTT topics](linux_app/topics_mqtt.md) and [room/board distribution](mobile_app/EVTY_distribution_plan_v1.md) |
| Use the hardware emulator | [Emulator usage guide](HWemulator/Usage_Instructions.md) |
| Review the Raspberry Pi setup | [OS notes](osimage/readme.md) and [PC setup notes](osimage/setup_new_pc.txt) |
| Explore the earlier BLE demonstration | [Proof-of-concept walkthrough](docs/poc_demo.md) |

## Repository structure

Directories only, limited to two levels (`tree -d -L 2`). Hidden directories are omitted. Each folder's purpose is shown alongside its name.

```text
.
├── HWemulator/                   # Hardware emulation scripts and usage instructions
├── archive/                      # Earlier prototypes and experiments
│   ├── BT_MAC_scan/              # Bluetooth MAC address scanning sketch
│   ├── ESP32_BTSerial/            # ESP32 Bluetooth serial experiment
│   ├── _EIS_fw/                  # Earlier ESP32 firmware project
│   └── _apppy/                   # Earlier Python BLE clients and handshake scripts
├── docs/                         # Architecture, reports, presentations, diagrams, and demo notes
│   └── images/                   # Supporting project images
├── firmware/                     # ESP32 firmware and experimental builds
│   ├── EVTY_FW_ARDPIO_v1/         # Arduino/PlatformIO project, main source, and firmware variants
│   └── test_builds/              # Experimental RTOS source files
├── hardware/                     # Component list, device addresses, CAD, and electrical designs
│   ├── 3dmodel/                  # Blender assembly model and component model library
│   ├── EVTY_XP1_SBcase_v1p0/      # Switchboard enclosure: FreeCAD sources and fabrication exports
│   └── schem/                    # Electrical schematics in PDF and JSON formats
├── linux_app/                    # Raspberry Pi/Linux MQTT controller, scripts, and topic reference
├── mobile_app/                   # Mobile integration planning and room/board topic assignments
├── osimage/                      # Raspberry Pi OS notes, setup instructions, and command history
└── reference/                    # External specifications and component datasheets
```

## Working in this repository

- **Firmware:** The PlatformIO project targets `esp32doit-devkit-v1` with the Arduino framework. Start with `src/main.cpp` and `platformio.ini`; additional source files in the project root contain variants and debugging code.
- **Linux application:** Start with `linux_app/mqttapp.py` and the MQTT topic reference. Review the broker address and device/topic assignments when adapting the prototype to your setup.
- **Hardware:** Keep editable CAD sources with their project and fabrication exports in the project's `CAM_Data/` directory. The assembly model and component library live in `hardware/3dmodel/`.
- **Documentation:** Keep design explanations and demonstration notes in `docs/`, and third-party specifications in `reference/`. OS setup notes belong in `osimage/`.
- **Archive:** Use `archive/` for historical context. Put new development in the relevant active component folder.

## Naming conventions

Use descriptive names and keep related source files and exports together. Existing project assets use the following conventions:

**Design projects:** `EVTY_<domain>_<toolchain>_<version>`

Example: `EVTY_FW_ARDPIO_v1`

- `EVTY`: Electrivity
- `FW`: Firmware
- `ARDPIO`: Arduino / PlatformIO
- `v1`: Version 1

**Documents:** `EVTY_<type>_<description>_<version>.<extension>`

Example: `EVTY_pres_phase1_v1.pdf`

- `pres`: Presentation
- `phase1`: Subject or project phase
- `v1`: Version 1
- `.pdf`: File format

Match the surrounding naming convention when adding files. When renaming an existing asset, update its references in the same change.

## Suggested organization improvements

These are proposed follow-up changes; the tree above describes the current layout.

1. **Group documentation by purpose.** Introduce `docs/architecture/`, `docs/demos/`, and `docs/reports/`. Consolidate supporting images under `docs/images/`, replace generic image names with descriptive ones, and update document links together.
2. **Document each component locally.** Add or expand component READMEs with purpose, dependencies, setup steps, entry points, and known limitations. Prioritize `firmware/`, `linux_app/`, and `HWemulator/`.
3. **Identify maintained firmware variants.** Explain which board uses each variant and how it is built. Move confirmed retired variants into `archive/` so the intended source is easy to find.
4. **Standardize folder names gradually.** Consider `hw_emulator/` for `HWemulator/` and `schematics/` for `hardware/schem/`. Check scripts, documentation, and CAD references before moving files.
5. **Keep temporary files out of future commits.** Add a root `.gitignore` for tool caches and editor/CAD backups. Review already tracked backup files separately; ignore rules do not untrack them.
6. **Make local setup reproducible.** Record Python dependencies and move configurable network/device settings into documented configuration examples. Separate repeatable setup steps from command history in `osimage/`.

## Contributors

- Hardware and firmware: @aitesam961
- Mobile application and Linux program: @Hassan and @Fawad
