import paho.mqtt.client as mqtt

mqttBroker = "localhost"  # Assuming broker on same Pi
switchTopic = "esp32/switch"
ledTopic = "esp32/led"

def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Connected to MQTT Broker!")
        client.subscribe(switchTopic)
    else:
        print("Failed to connect, return code %d\n", rc)

def on_message(client, userdata, message):
    message = message.payload.decode()
    print("Received message:", message)
    if message == "high":
        print("Switch is HIGH")
    else:
        print("Switch is LOW")

# Remove CallbackAPIVersion for older versions
client = mqtt.Client()

client.on_connect = on_connect
client.on_message = on_message

client.connect(mqttBroker)
client.loop_start()

while True:
    userInput = input("Enter 'on' to turn LED on, 'off' to turn it off: ")
    if userInput == "on" or userInput == "off":
        client.publish(ledTopic, userInput)
