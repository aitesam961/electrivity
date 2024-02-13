import bluepy.btle as btle
import time

# ESP32 BLE device MAC address
esp32_mac_address = "08:D1:F9:E7:DE:12"

class NotificationHandler(btle.DefaultDelegate):
    def handleNotification(self, cHandle, data):
        if cHandle == temperature_handle:
            temperature = int.from_bytes(data, byteorder='little')
            print("Temperature received:", temperature, "°C")
        elif cHandle == control_handle:
            control_signal = int.from_bytes(data, byteorder='little')
            if control_signal == 1:
                print("Relay turned ON")
            elif control_signal == 0:
                print("Relay turned OFF")

# UUIDs for temperature and control characteristics
temperature_uuid = "6e400002-b5a3-f393-e0a9-e50e24dcca9e"
control_uuid = "6e400003-b5a3-f393-e0a9-e50e24dcca9e"

# Connect to the ESP32 BLE peripheral
esp32_device = btle.Peripheral(esp32_mac_address)
esp32_device.setDelegate(NotificationHandler())

# Find characteristics handles
temperature_handle = esp32_device.getCharacteristics(uuid=temperature_uuid)[0].getHandle()
control_handle = esp32_device.getCharacteristics(uuid=control_uuid)[0].getHandle()

try:
    while True:
        if esp32_device.waitForNotifications(1.0):
            continue
        print("Waiting for notifications...")
        time.sleep(1)

        # Read temperature data
        temperature_data = esp32_device.readCharacteristic(temperature_handle)
        temperature = int.from_bytes(temperature_data, byteorder='little')
        print("Temperature:", temperature, "°C")

        # Send control signal to turn relay ON (1)
        esp32_device.writeCharacteristic(control_handle, b"\x01", withResponse=True)
        print("Relay turned ON")

        time.sleep(1)  # Wait for 5 seconds

        # Send control signal to turn relay OFF (0)
        esp32_device.writeCharacteristic(control_handle, b"\x00", withResponse=True)
        print("Relay turned OFF")

        time.sleep(1)  # Wait for 5 seconds

except KeyboardInterrupt:
    print("Keyboard interrupt detected. Disconnecting...")
    esp32_device.disconnect()
