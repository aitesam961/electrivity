import bluetooth 
import time

target_address = "08:D1:F9:E7:DE:12"
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
            # Receive data from ESP32
            received_data = bt_communication.receive_data()
            print("Received:", received_data.decode())

            # Send response back to ESP32
            response_data = input("Hey ESP32, it's RPI: ")
            bt_communication.send_data(response_data.encode())

            time.sleep(1)

    except KeyboardInterrupt:
        bt_communication.close_connection()
        print("Connection closed.")

