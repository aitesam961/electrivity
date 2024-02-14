import bluepy.btle as btle
import time

# ESP32 BLE device MAC addresses
esp32_sensor_mac_address    = "08:D1:F9:E7:DE:12"  # MAC address for the sensor ESP32
esp32_control_mac_address   = "08:D1:F9:E8:7E:7C"  # MAC address for the control ESP32

class SensorNotificationHandler(btle.DefaultDelegate):
    def handleNotification(self, cHandle, data):
        if cHandle == temperature_handle:
            temperature = int.from_bytes(data, byteorder='little')
            print("Temperature received:", temperature, "°C")
        elif cHandle == humidity_handle:
            humidity = int.from_bytes(data, byteorder='little')
            print("Humidity received:", humidity, "%")
        elif cHandle == light_intensity_handle:
            light_intensity = int.from_bytes(data, byteorder='little')
            print("Light Intensity received:", light_intensity)

class ControlNotificationHandler(btle.DefaultDelegate):
    def handleNotification(self, cHandle, data):
        if cHandle == control_handle:
            control_signal = int.from_bytes(data, byteorder='little')
            if control_signal == 1:
                print("Relay turned ON")
            elif control_signal == 0:
                print("Relay turned OFF")

# UUIDs for characteristics
temperature_uuid = "6e400002-b5a3-f393-e0a9-e50e24dcca9e"
humidity_uuid = "6e400003-b5a3-f393-e0a9-e50e24dcca9e"
light_intensity_uuid = "6e400004-b5a3-f393-e0a9-e50e24dcca9e"
control_uuid = "6e400005-b5a3-f393-e0a9-e50e24dcca9e"

try:
    # Connect to the sensor ESP32 BLE peripheral
    sensor_device = btle.Peripheral(esp32_sensor_mac_address)
    sensor_device.setDelegate(SensorNotificationHandler())

    # Connect to the control ESP32 BLE peripheral
    control_device = btle.Peripheral(esp32_control_mac_address)
    control_device.setDelegate(ControlNotificationHandler())

    # Find characteristics handles for sensor device
    temperature_handle = sensor_device.getCharacteristics(uuid=temperature_uuid)[0].getHandle()
    humidity_handle = sensor_device.getCharacteristics(uuid=humidity_uuid)[0].getHandle()
    light_intensity_handle = sensor_device.getCharacteristics(uuid=light_intensity_uuid)[0].getHandle()

    # Find characteristics handles for control device
    control_handle = control_device.getCharacteristics(uuid=control_uuid)[0].getHandle()

    while True:
        if sensor_device.waitForNotifications(1.0):
            continue
        print("Waiting for sensor notifications...")
        time.sleep(1)

        # Read sensor data
        temperature_data = sensor_device.readCharacteristic(temperature_handle)
        temperature = int.from_bytes(temperature_data, byteorder='little')
        print("Temperature:", temperature, "°C")

        humidity_data = sensor_device.readCharacteristic(humidity_handle)
        humidity = int.from_bytes(humidity_data, byteorder='little')
        print("Humidity:", humidity, "%")

        light_intensity_data = sensor_device.readCharacteristic(light_intensity_handle)
        light_intensity = int.from_bytes(light_intensity_data, byteorder='little')
        print("Light Intensity:", light_intensity)

        time.sleep(1)  # Wait for 1 second

        # Send control signal to control device to turn relay ON (1)
        control_device.writeCharacteristic(control_handle, b"\x01", withResponse=True)
        print("Relay turned ON")

        time.sleep(5)  # Wait for 5 seconds

        # Send control signal to control device to turn relay OFF (0)
        control_device.writeCharacteristic(control_handle, b"\x00", withResponse=True)
        print("Relay turned OFF")

        time.sleep(5)  # Wait for 5 seconds

except KeyboardInterrupt:
    print("Keyboard interrupt detected. Disconnecting...")
    sensor_device.disconnect()
    control_device.disconnect()
