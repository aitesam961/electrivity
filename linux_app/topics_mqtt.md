
### List of MQTT topics
```
prism/board1/switch1
prism/board1/switch2
prism/board1/switch3
prism/board1/switch4

prism/board2/switch1
prism/board2/switch2
prism/board2/switch3
prism/board2/switch4

prism/board3/switch1
prism/board3/switch2
prism/board3/switch3
prism/board3/switch4

prism/board4/switch1
prism/board4/switch2
prism/board4/switch3
prism/board4/switch4

prism/board1/touch1
prism/board1/touch2
prism/board1/touch3
prism/board1/touch4

prism/board2/touch1
prism/board2/touch2
prism/board2/touch3
prism/board2/touch4

prism/board3/touch1
prism/board3/touch2
prism/board3/touch3
prism/board3/touch4

prism/board4/touch1
prism/board4/touch2
prism/board4/touch3
prism/board4/touch4


prism/sboard1/sensor1
prism/sboard1/sensor2
prism/sboard1/sensor3

```

**There are 4x switches/touches per board. As the first step, implement support for at least 4 boards.**




### Standard Message strings

#### From Client to RPi

- a = `high`

- a = `low`

#### From RPi to Clients

- publish(`on`)

- publish(`off`)

