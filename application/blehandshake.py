import bluetooth
import time

target_address = "08:D1:F9:E7:DE:12"  # Replace with the actual ESP32 MAC address
port = 1

class BluetoothCommunication:
    def __init__(self):
        self.sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
        self.sock.connect((target_address, port))

    def send_data(self, data):
        self.sock.send(data)

    def receive_data(self):
        return self.sock.recv(1024)

    def close_connection(self):
        self.sock.close()

if __name__ == "__main__":
    bt_communication = BluetoothCommunication()

    try:
        while True:
            # Wait for 1 second
            time.sleep(1)

            # Send initial string data
            bt_communication.send_data("ESP32-DEMO-BOARD-1".encode())

            # Receive response from ESP32
            response_data = bt_communication.receive_data()
            print("Received:", response_data.decode())

            if response_data.decode() == "ACTIVE":
                # Send command for temperature data
                bt_communication.send_data("SEND_TEMP".encode())

            # Receive data from ESP32
            received_data = bt_communication.receive_data()
            print("Received:", received_data.decode())

            # Optional: Add user response functionality here

    except KeyboardInterrupt:
        bt_communication.close_connection()
        print("Connection closed.")
