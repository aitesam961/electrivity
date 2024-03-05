# XP-1: Client Distribution

Each room gets allocated a single board ID (i.e board1, board2 ...). This scheme will slightly differ for the production model.

### Bed Room:
```
prism/board1/switch1	
prism/board1/switch2
prism/board1/switch3
prism/board1/switch4
```
```
prism/board1/touch1
prism/board1/touch2
prism/board1/touch3
prism/board1/touch4
```
### Living Room:
```
prism/board2/switch1
prism/board2/switch2
prism/board2/switch3
prism/board2/switch4
```
```
prism/board2/touch1
prism/board2/touch2
prism/board2/touch3
prism/board2/touch4
```
### Kitchen:
```
prism/board3/switch1
prism/board3/switch2
prism/board3/switch3
prism/board3/switch4
```
```
prism/board3/touch1
prism/board3/touch2
prism/board3/touch3
prism/board3/touch4
```
### Lawn:
```
prism/board4/switch1
prism/board4/switch2
prism/board4/switch3
prism/board4/switch4
```
```
prism/board4/touch1
prism/board4/touch2
prism/board4/touch3
prism/board4/touch4
```


## Valid Strings

#### Switches

Hardware clients subscribe to `switch` topics across the network and read values. The valid string values are `on` and `off`. All other values execute exception case.

#### Touch

Hardware publishes the `touch` topics ON CHANGE ONLY. Whenever a user touches the sensor, a `high` signal is published and the publisher goes silent. The raspberry pi stores this `on` state until user touches the same sensor again OR mobile app changes the state. 
The valis strings for touch published by the user are `high` and `low`. The raspberry pi is responsible for exception handling in this regard.


### Add or Remove Devices

User can add or remove available devices through mobile app. RPi uses client.subscribe(x,x) or client.unsubscribe(x,x) functions of MQTT to add or remove devices. Mobile app uses its own set of signals to send or receive data from RPi that eventually execute addition or removal of devices.

**NOTE: No Sensors are active for this prototype. If mobile app may or may not include interface for sensors for XP-1 but production version will certainly use sensor inputs.** 