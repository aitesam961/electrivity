import bluetooth 
import time

target_address = "A8:03:2A:EB:03:16"
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
            # Send data
            data_to_send = b"Hello ESP32!"
            bt_communication.send_data(data_to_send)

            # Receive data
            received_data = bt_communication.receive_data()
            print("Received:", received_data.decode())

            time.sleep(1)

    except KeyboardInterrupt:
        bt_communication.close_connection()
        print("Connection closed.")

