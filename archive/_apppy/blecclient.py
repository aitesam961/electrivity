import bluepy.btle as btle
import time

# ESP32 BLE device MAC addresses
esp32_sensor_mac_address = "08:D1:F9:E7:DE:12"
esp32_control_mac_address = "08:D1:F9:E8:7E:7E"

class SensorNotificationHandler(btle.DefaultDelegate):
    def handleNotification(self, cHandle, data):
        if cHandle == temperature_handle:
            temperature = int.from_bytes(data, byteorder='little')
            print("Temperature received:", temperature, "°C")
        elif cHandle == humidity_handle:
            humidity = int.from_bytes(data, byteorder='little')
            print("Humidity received:", humidity, "%")
        elif cHandle == light_status_handle:
            light_status = int.from_bytes(data, byteorder='little')
            print("Light Status received:", light_status)

class ControlNotificationHandler(btle.DefaultDelegate):
    def handleNotification(self, cHandle, data):
        if cHandle == switch_1_handle:
            switch_1 = int.from_bytes(data, byteorder='little')
            print("Switch 1 Status received:", switch_1)
        elif cHandle == switch_2_handle:
            switch_2 = int.from_bytes(data, byteorder='little')
            print("Switch 2 Status received:", switch_2)


# UUIDs for characteristics (Sensor)
SERVICE_UUID        = "6e410000-b5a3-f393-e0a9-e50e24dcca9e"
TEMPERATURE_UUID    = "6e410010-b5a3-f393-e0a9-e50e24dcca9e"
HUMIDITY_UUID       = "6e410011-b5a3-f393-e0a9-e50e24dcca9e"
LIGHT_UUID          = "6e410012-b5a3-f393-e0a9-e50e24dcca9e"
# UUIDs for characteristics (Control)
SERVICE_UUID        = "6e420000-b5a3-f393-e0a9-e50e24dcca9e"
SWITCH_1_UUID       = "6e420010-b5a3-f393-e0a9-e50e24dcca9e"
SWITCH_2_UUID       = "6e420011-b5a3-f393-e0a9-e50e24dcca9e"
LIGHT_1_UUID        = "6e420012-b5a3-f393-e0a9-e50e24dcca9e"
LIGHT_2_UUID        = "6e420013-b5a3-f393-e0a9-e50e24dcca9e"


try:
    # Connect to the sensor ESP32 BLE peripheral
    sensor_device = btle.Peripheral(esp32_sensor_mac_address)
    sensor_device.setDelegate(SensorNotificationHandler())

    # Connect to the control ESP32 BLE peripheral
    control_device = btle.Peripheral(esp32_control_mac_address)
    control_device.setDelegate(ControlNotificationHandler())

    # Find characteristics handles for sensor device
    temperature_handle = sensor_device.getCharacteristics(uuid=TEMPERATURE_UUID)[0].getHandle()
    humidity_handle = sensor_device.getCharacteristics(uuid=HUMIDITY_UUID)[0].getHandle()
    light_status_handle = sensor_device.getCharacteristics(uuid=LIGHT_UUID)[0].getHandle()

    # Find characteristics handles for control device
    switch_1_handle = control_device.getCharacteristics(uuid=SWITCH_1_UUID)[0].getHandle()
    switch_2_handle = control_device.getCharacteristics(uuid=SWITCH_2_UUID)[0].getHandle()
    light_1_handle = control_device.getCharacteristics(uuid=LIGHT_1_UUID)[0].getHandle()
    light_2_handle = control_device.getCharacteristics(uuid=LIGHT_2_UUID)[0].getHandle()

    while True:
        if sensor_device.waitForNotifications(1.0):
            continue
        print("Waiting for sensor notifications...")
        time.sleep(0.5)
        # delay to avoid overwhelming the servers

        # Read sensor data
        temperature_data = sensor_device.readCharacteristic(temperature_handle)
        temperature = int.from_bytes(temperature_data, byteorder='little')
        print("Temperature:", temperature, "°C")

        humidity_data = sensor_device.readCharacteristic(humidity_handle)
        humidity = int.from_bytes(humidity_data, byteorder='little')
        print("Humidity:", humidity, "%")

        light_status_data = sensor_device.readCharacteristic(light_status_handle)
        light_status = int.from_bytes(light_status_data, byteorder='little')
        print("Light Status:", light_status)

        # Read switch status from control device
        switch_1_data = control_device.readCharacteristic(switch_1_handle)
        switch_1 = int.from_bytes(switch_1_data, byteorder='little')
        print("Switch 1:", switch_1)

        switch_2_data = control_device.readCharacteristic(switch_2_handle)
        switch_2 = int.from_bytes(switch_2_data, byteorder='little')
        print("Switch 2:", switch_2)

        # Control logic for lights based on sensor data
        if light_status == 0x00:
            control_device.writeCharacteristic(light_1_handle, b"\x01", withResponse=True)
            print("Light 1 turned: ON")
        else:
            control_device.writeCharacteristic(light_1_handle, b"\x00", withResponse=True)
            print("Light 1 turned: OFF")

        if switch_2 == 0x01:
            control_device.writeCharacteristic(light_2_handle, b"\x01", withResponse=True)
            print("Light 2 turned: ON")
        elif switch_2 == 0x00:
            control_device.writeCharacteristic(light_2_handle, b"\x00", withResponse=True)
            print("Light 2 turned: OFF")
        
except KeyboardInterrupt:
    print("\nKeyboard interrupt detected. Disconnecting...")
    sensor_device.disconnect()
    control_device.disconnect()
