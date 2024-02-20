import paho.mqtt.client as mqtt

# MQTT Broker
mqttBroker = "192.168.8.103"
mqttPort = 1883
mqttClientID = "RPiClient1"
ledTopic = "esp32/led"
switchTopic = "esp32/switch"

def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    client.subscribe(switchTopic)

def on_message(client, userdata, msg):
    print(msg.topic+" "+str(msg.payload))
    if msg.topic == switchTopic:
        if msg.payload == b'high':
            client.publish(ledTopic, "on")
            print("LED turned ON")
        else:
            client.publish(ledTopic, "off")
            print("LED turned OFF")

client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION1, mqttClientID)
client.on_connect = on_connect
client.on_message = on_message

client.connect(mqttBroker, mqttPort, 60)

client.loop_forever()
