
# Project: PRISM
# An Egde IoT System for home automation
# 
# Author: aitesam961
# 
# This is the main source code for RPI local client


import paho.mqtt.client as mqtt
import time
# MQTT Broker
mqttBroker = "192.168.0.101"
mqttPort = 1883
mqttClientID = "RPiClient1"

# MQTT Topics
top_sb1s1 = "prism/sboard1/sensor1"  
top_sb1s2 = "prism/sboard1/sensor2"  
top_sb1s3 = "prism/sboard1/sensor3"  

top_b1s1 = "prism/board1/switch1"  
top_b1s2 = "prism/board1/switch2"  
top_b1s3 = "prism/board1/switch3"  
top_b1s4 = "prism/board1/switch4" 

top_b1t1 = "prism/board1/touch1"  
top_b1t2 = "prism/board1/touch2"  
top_b1t3 = "prism/board1/touch3"  
top_b1t4 = "prism/board1/touch4" 


def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    client.subscribe(top_b1t1)
    client.subscribe(top_b1t2)
    client.subscribe(top_b1t3)
    client.subscribe(top_b1t4)
    client.subscribe(top_sb1s1)
    client.subscribe(top_sb1s2)
    client.subscribe(top_sb1s3)

def on_message(client, userdata, msg):
    if msg.topic == top_b1t1:
        if msg.payload == b'high':
            print("Switch-1 ON")
        else:
            print("Switch-1 OFF")
    if msg.topic == top_b1t2:
        if msg.payload == b'high':
            print("Switch-2 ON")
        else:
            print("Switch-2 OFF")
    if msg.topic == top_b1t3:
        if msg.payload == b'high':
            print("Switch-3 ON")
        else:
            print("Switch-3 OFF")
    if msg.topic == top_b1t4:
        if msg.payload == b'high':
            print("Switch-4 ON")
        else:
            print("Switch-4 OFF")

    if msg.topic == top_sb1s1:
        print("Temperature : "+str(msg.payload))
    if msg.topic == top_sb1s2:
        print("Humidity : "+str(msg.payload))
    if msg.topic == top_sb1s3:
        print("Light Intensity : "+str(msg.payload))

client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION1, mqttClientID)    # using V1 because V2 breaks the plugin
client.on_connect = on_connect
client.on_message = on_message

client.connect(mqttBroker, mqttPort, 60)

client.loop_forever()
