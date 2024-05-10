#!/bin/bash

while true; do
    mosquitto_pub -h "10.42.0.1" -t "prism/board1/touch1" -m "high"
    mosquitto_pub -h "10.42.0.1" -t "prism/board1/touch2" -m "high"
    mosquitto_pub -h "10.42.0.1" -t "prism/board1/touch3" -m "high"
    mosquitto_pub -h "10.42.0.1" -t "prism/board1/touch4" -m "high"

    mosquitto_pub -h "10.42.0.1" -t "prism/board1/pwrch1" -m $(( ( RANDOM % 10 )  + 1 ))
    mosquitto_pub -h "10.42.0.1" -t "prism/board1/pwrch2" -m $(( ( RANDOM % 10 )  + 1 ))
    mosquitto_pub -h "10.42.0.1" -t "prism/board1/pwrch3" -m $(( ( RANDOM % 10 )  + 1 ))
    mosquitto_pub -h "10.42.0.1" -t "prism/board1/pwrch4" -m $(( ( RANDOM % 10 )  + 1 ))


    sleep 4  # Adjust sleep time as needed
    mosquitto_pub -h "10.42.0.1" -t "prism/board1/touch1" -m "low"
    mosquitto_pub -h "10.42.0.1" -t "prism/board1/touch2" -m "low"
    mosquitto_pub -h "10.42.0.1" -t "prism/board1/touch3" -m "low"
    mosquitto_pub -h "10.42.0.1" -t "prism/board1/touch4" -m "low"

    mosquitto_pub -h "10.42.0.1" -t "prism/board1/pwrch1" -m $(( ( RANDOM % 10 )  + 1 ))
    mosquitto_pub -h "10.42.0.1" -t "prism/board1/pwrch2" -m $(( ( RANDOM % 10 )  + 1 ))
    mosquitto_pub -h "10.42.0.1" -t "prism/board1/pwrch3" -m $(( ( RANDOM % 10 )  + 1 ))
    mosquitto_pub -h "10.42.0.1" -t "prism/board1/pwrch4" -m $(( ( RANDOM % 10 )  + 1 ))
    sleep 4  # Adjust sleep time as needed
done
