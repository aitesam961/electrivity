import paho.mqtt.client as mqtt
# MQTT Broker
mqttBroker = "10.42.0.1"
mqttPort = 1883
mqttClientID = "ESP32-ROOM-1"

# EVTY MQTT Topics

top_b1s1 = "prism/board1/switch1"  
top_b1s2 = "prism/board1/switch2"  
top_b1s3 = "prism/board1/switch3"  
top_b1s4 = "prism/board1/switch4" 

top_b1t1 = "prism/board1/touch1"  
top_b1t2 = "prism/board1/touch2"  
top_b1t3 = "prism/board1/touch3"  
top_b1t4 = "prism/board1/touch4" 

b1_pch_1 = "prism/board1/pwrch1"
b1_pch_2 = "prism/board1/pwrch2"
b1_pch_3 = "prism/board1/pwrch3"
b1_pch_4 = "prism/board1/pwrch4"



def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    # Subscribe to switch topics (sent by broker)
    client.subscribe(top_b1s1)
    client.subscribe(top_b1s2)
    client.subscribe(top_b1s3)
    client.subscribe(top_b1s4)

def on_message(client, userdata, msg):
    if msg.topic == top_b1s1:
        if msg.payload == b'on':
            print("Relay-1 Turned ON")
        else:
            print("Relay-1 Turned OFF")
    if msg.topic == top_b1s2:
        if msg.payload == b'on':
            print("Relay-2 Turned ON")
        else:
            print("Relay-2 Turned OFF")
    if msg.topic == top_b1s3:
        if msg.payload == b'on':
            print("Relay-3 Turned ON")
        else:
            print("Relay-3 Turned OFF")
    if msg.topic == top_b1s4:
        if msg.payload == b'on':
            print("Relay-4 Turned ON")
        else:
            print("Relay-4 Turned OFF")

        
# Footer
client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION1, mqttClientID)    # using V1 because V2 breaks the plugin
client.on_connect = on_connect
client.on_message = on_message

client.connect(mqttBroker, mqttPort, 60)
client.loop_forever()






