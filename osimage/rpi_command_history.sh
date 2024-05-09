1  vcgencmd measure_temp
    2  hostname -I
    3  shutdown now
    4  sudo apt update && sudo apt upgrade
    5  vcgencmd measure_temp
    6  shutdown now
    7  sudo shutdown now
    8  vcgencmd measure_temp
    9  sudo apt-get install python3-pip libglib2.0-dev
   10  sudo pip3 install bluepy
   11  sudo rm -rf /usr/lib/python3.11/EXTERNALLY-MANAGED
   12  sudo pip3 install bluepy
   13  vcgencmd measure_temp
   14  pip3 show bluepy
   15  vcgencmd measure_temp
   16  shutdown now
   17  sudo shutdown now
   18  ls
   19  mkdir bleapp
   20  cd bleapp
   21  nano bleserial.py
   22  sudo ./bleserial.py
   23  sudo python3 bleserial.py
   24  vcgencmd measure_temp
   25  ifconfig
   26  sudo apt udpate
   27  cd ..
   28  sudo apt udpate
   29  sudo apt update
   30  sudo apt update && sudo apt upgrade
   31  clear
   32  ls
   33  cd bleapp
   34  ls
   35  sudo python3 bleserial.py
   36  shutdown now
   37  sudo shutdown now
   38  vcgencmd measure_temp
   39  sudo apt update
   40  clear
   41  ls
   42  cd bleapp
   43  ls
   44  python3 bleserial.py
   45  cd ..
   46  sudo apt-get install python3-bluez
   47  cd bleapp
   48  python3 bleserial.py
   49  sudo python3 bleserial.py
   50  sudo hcitool scan
   51  sudo bluetoothctl 
   52  sudo systemctl stop bluetooth
   53  sudo systemctl start bluetooth
   54  sudo hcitool scan
   55  sudo bluetoothctl
   56  sudo python3 bleserial.py
   57  hciconfig
   58  sudo hciconfig hci0 up
   59  sudo rfkill list
   60  sudo rfkill unblock bluetooth
   61  hciconfig
   62  sudo python3 bleserial.py
   63  ls
   64  nano bleserial.py
   65  sudo python3 bleserial.py
   66  nano bleserial.py
   67  sudo python3 bleserial.py
   68  vcgencmd measure_temp
   69  shutdown now
   70  sudo shutdown now
   71  ls
   72  cd bleapp
   73  scp ~/bleapp/* username@aitesam961:~/Downloads
   74  sudo shutdown now
   75  sudo apt update
   76  sudo apt upgrade
   77  sudo apt install -y mosquitto mosquitto-clients
   78  pip3 install paho-mqtt
   79  sudo shutdown now
   80  clear
   81  ls
   82  rm -rf bleapp
   83  ls
   84  mkdir mqttapp
   85  cd mqttapp
   86  ls
   87  hostname -I
   88  ls
   89  sudo python3 mqttapp.py
   90  cd .
   91  cd ..
   92  sudo pip3 install paho-mqtt
   93  cd mqttapp
   94  sudo python3 mqttapp.py
   95  sudo systemctl start mosquitto.service
   96  sudo systemctl stop mosquitto.service
   97  sudo systemctl restart mosquitto.service
   98  sudo systemctl status mosquitto.service
   99  sudo systemctl stop mosquitto.service
  100  sudo systemctl status mosquitto.service
  101  clear
  102  sudo systemctl enable mosquitto.service
  103  mosquitto -v
  104  sudo nano /etc/mosquitto/mosquitto.conf
  105  sudo systemctl restart mosquitto
  106  sudo python3 mqttapp.py
  107  sudo systemctl stop mosquitto
  108  sudo shutdown now
  109  clear
  110  ls
  111  cd mqttapp
  112  ls
  113  sudo python3 mqttapp.py
  114  cd ..
  115  pip install --upgrade paho-mqtt
  116  sudo pip install --upgrade paho-mqtt
  117  cd mqttapp
  118  ls
  119  sudo python3 mqttapp.py
  120  cd..
  121  cd ..
  122  sudo pip install paho-mqtt<2.0.0
  123  sudo pip uninstall paho-mqtt
  124  sudo apt autoremove
  125  sudo pip install paho-client
  126  sudo pip3 install paho-mqtt
  127  cd mqttapp
  128  ls
  129  sudo python3 mqttapp.py
  130  sudo nano /etc/mosquitto/mosquitto.conf
  131  sudo shutdown now
  132  clear
  133  ls
  134  nmap
  135  sudo iwlist wlan0 scan
  136  ping 8.8.8.8
  137  sudo iwlist wlan0 scan
  138  clear
  139  sudo nano /etc/wpa_supplicant/wpa_supplicant.conf
  140  reboot
  141  sudo reboot
  142  sudo nano /etc/wpa_supplicant/wpa_supplicant.conf
  143  sudo nano /etc/network/interfaces
  144  sudo shutdown now
  145  sudo nano /etc/wpa_supplicant/wpa_supplicant.conf
  146  sudo shutdown now
  147  sudo raspi-config
  148  ls
  149  cd mqttapp
  150  ls
  151  sudo python3 mqttapp.py
  152  sudo shutdown now
  153  sudo raspi-config
  154  clear
  155  ls
  156  cd mqttapp
  157  ls
  158  sudo python3 mqttapp.py
  159  cd mqttapp
  160  ls
  161  sudo python3 mqttapp.py
  162  ls
  163  sudo nano mqtt_switch_control.sh
  164  ./mqtt_switch_control.sh
  165  sudo nano mqtt_switch_control.sh
  166  ./mqtt_switch_control.sh
  167  sudo nano mqtt_switch_control.sh
  168  ./mqtt_switch_control.sh
  169  mosquitto_pub -h "$broker_address" -t "prism/board1/switch1" -m "on"
  170  mosquitto_pub -h "$192.168.0.101" -t "prism/board1/switch1" -m "on"
  171  mosquitto_pub -h "$192.168.0.101" -t "prism/board1/switch1" -m "off"
  172  sudo nano mqtt_switch_control.sh
  173  ./mqtt_switch_control.sh
  174  sudo shutdown onw
  175  sudo shutdown now
  176  cd mqttapp
  177  ls
  178  cat publisher.sh
  179  sudo nano  publisher.sh
  180  ls
  181  sudosudosss
  182  sudo nano mqtt_switch_control.sh
  183  chmod +x mqtt_switch_control.sh
  184  ./mqtt_switch_control.sh
  185  sudo ./mqtt_switch_control.sh
  186  ls
  187  sudo ./mqtt_switch_control.sh
  188  ls -l mqtt_switch_control.sh
  189  chmod +x mqtt_switch_control.sh
  190  sudo chmod +x mqtt_switch_control.sh
  191  ./mqtt_switch_control.sh
  192  sudo nano mqtt_switch_control.sh
  193  ./mqtt_switch_control.sh
  194  sudo nano mqtt_switch_control.sh
  195  reboot
  196  sudo reboot
  197  sudo raspi-config
  198  sudo raspi-config
  199  sudo wpa_cli -i wlan0 reconfigure
  200  sudo ifconfig wlan0 down && sudo ifconfig wlan0 up
  201  sudo raspi-config
  202  ls
  203  cd mqttapp
  204  ls
  205  sudo nano mqtt_switch_control.sh
  206  ./mqtt_switch_control.sh
  207  sudo nano mqtt_switch_control.sh
  208  mosquitto_pub -h "$192.168.0.101" -t "prism/board1/switch1" -m "off"
  209  mosquitto_pub -h "$192.168.0.101" -t "prism/board1/switch1" -m "on"
  210  mosquitto_pub -h "192.168.0.101" -t "prism/board1/switch1" -m "on"
  211  sudo nano mqtt_switch_control.sh
  212  mosquitto_pub -h "192.168.0.101" -t "prism/board1/switch1" -m "on"
  213  mosquitto_pub -h "192.168.0.101" -t "prism/board1/switch1" -m "off"
  214  ./mqtt_switch_control.sh
  215  clear
  216  mosquitto_pub -h "192.168.0.101" -t "prism/board1/switch1" -m "on"
  217  mosquitto_pub -h "192.168.0.101" -t "prism/board1/switch2" -m "on"
  218  mosquitto_pub -h "192.168.0.101" -t "prism/board1/switch2" -m "off"
  219  mosquitto_pub -h "192.168.0.101" -t "prism/board1/switch1" -m "off"
  220  mosquitto_pub -h "192.168.0.101" -t "prism/board1/switch4" -m "off"
  221  mosquitto_pub -h "192.168.0.101" -t "prism/board1/switch1" -m "on"
  222  mosquitto_pub -h "192.168.0.101" -t "prism/board1/switch3" -m "on"
  223  mosquitto_pub -h "192.168.0.101" -t "prism/board1/switch3" -m "off"
  224  mosquitto_pub -h "192.168.0.101" -t "prism/board1/switch1" -m "off"
  225  clear
  226  ls
  227  cd mqttapp
  228  ls
  229  sudo python3 mqttapp.py
  230  clear
  231  sudo python3 mqttapp.py
  232  clear
  233  ls
  234  sudo python3 mqttapp.py
  235  sudo shutdown now
  236  cd mqttapp
  237  ls
  238  sudo python3 mqttapp.py
  239  sudo raspi-config
  240  timedatectl
  241  timedatectl list-timezones
  242  sudo timedatectl set-timezone Asia/Karachi
  243  timedatectl
  244  sudo timedatectl set-ntp on
  245  timedatectl
  246  sudo date -s "25 FEB 2024 11:01:00"
  247  timedatectl
  248  clear
  249  sudo python3 mqttapp.py
  250  sudo shutdown now
  251  mosquitto_pub -h "192.168.0.101" -t "prism/board1/switch1" -m "off"
  252  cd mqttapp
  253  ls
  254  sudo python3 mqttapp.py 
  255  sudo shutdown now
  256  sudo raspi-config
  257  clear
  258  sudo apt update
  259  sudo apt install htop
  260  htop
  261  sudo apt upgrade
  262  sudo ifconfig wlan0
  263  sudo raspi-config
  264  clear
  265  raspi-config
  266  sudo raspi-config
  267  clear
  268  sudo iw wlan0 scan
  269  sudo raspi-config
  270  sudo killall wpa_supplicant
  271  sudo raspi-config
  272  shutdown now
  273  sudo raspi-config
  274  sudo apt update -y && sudo apt upgrade -y
  275  sudo apt autoremove
  276  vcgencmd measure_temp
  277  sudo shutdown now
  278  ls
  279  cd mqttapp
  280  ls
  281  cat mqtt.py
  282  cat mqttapp.py
  283  sudo python3 mqtttapp.py    
  284  sudo python3 mqttapp.py    
  285  sudo nano mqttapp.py
  286  sudo install ngrock
  287  sudo install ngrok
  288  ngrokngrok
  289  snap install ngrok
  290  ngrok config add-authtoken 2bRAFLL3Tea08Bg577pYzGpTKu6_7ex4as9fSWHbKxqQYAivD
  291  wget https://bin.equinox.io/c/bNyj1mQVY4c/ngrok-v3-stable-linux-arm64.tgz
  292  sudo tar xvzf ./ngrok-v3-stable-linux-arm64.tgz -C /usr/local/bin
  293  ngrok
  294  ngrok config add-authtoken 2bRAFLL3Tea08Bg577pYzGpTKu6_7ex4as9fSWHbKxqQYAivD
  295  vcgencmd measure_temp
  296  ifconfig
  297  cd mqttapp
  298  sudo python3 mqttapp.py
  299  mosquitto_pub -h "$192.168.8.103" -t "prism/board1/switch1" -m "on"
  300  mosquitto_pub -h "192.168.8.103" -t "prism/board1/switch1" -m "on"
  301  mosquitto_pub -h "192.168.8.103" -t "prism/board1/switch1" -m "off"
  302  cat mqttapp.py
  303  cat >>mqttapp.py
  304  nano mqttapp.py
  305  sudo python3 mqttapp.py
  306  sudo chmod 666 /dev/ttyACM0
  307  sudo python3 mqttapp.py
  308  mosquitto_pub -h "192.168.8.103" -t "prism/board1/switch1" -m "on"
  309  mosquitto_pub -h "192.168.8.103" -t "prism/board1/switch1" -m "off"
  310  sudo shutdown njow
  311  sudo shutdown now
  312  ngrok http 1883
  313  mosquitto_pub -h "192.168.8.103" -t "prism/board1/switch1" -m "o"
  314  mosquitto_pub -h "192.168.8.103" -t "prism/board1/switch1" -m "on"
  315  mosquitto_pub -h "192.168.8.103" -t "prism/board1/switch1" -m "off"
  316  ifconfig
  317  cd mqttapp
  318  ls
  319  gedit mqttapp
  320  sudo apt install gedit
  321  gedit mqttapp
  322  gedit mqttapp.py
  323  nano mqttapp.py
  324  sudo python3 mqttapp.py
  325  nano mqttapp.py
  326  sudo python3 mqttapp.py
  327  nano mqttapp.py
  328  sudo python3 mqttapp.py
  329  nano mqttapp.py
  330  sudo python3 mqttapp.py
  331  nano mqttapp.py
  332  sudo python3 mqttapp.py
  333  mosquitto_pub -h "192.168.8.103" -t "prism/board1/switch1" -m "on
  334  mosquitto_pub -h "192.168.8.103" -t "prism/board1/switch1" -m "on"
  335  mosquitto_pub -h "192.168.8.103" -t "prism/board1/switch1" -m "off"
  336  mosquitto_pub -h "192.168.8.103" -t "prism/board1/switch1" -m "on"
  337  mosquitto_pub -h "192.168.8.103" -t "prism/board1/switch3" -m "on"
  338  mosquitto_pub -h "192.168.8.103" -t "prism/board1/switch1" -m "on"
  339  sudo shutdown now
  340  sudo raspi-config
  341  mosquitto_pub -h "192.168.8.103" -t "prism/board1/switch1" -m "off"
  342  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch1" -m "off"
  343  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch1" -m "on"
  344  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch1" -m "off"
  345  vcgencmd measure_temp
  346  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch2" -m "off"
  347  mkdir tkinter
  348  cd tkinter
  349  ls
  350  nano tkinter
  351  nano tkinter.py
  352  ls
  353  rm -rf tkinter
  354  ls
  355  sudo python3 tkinter.py
  356  sudo pip install tk
  357  sudo rm -rf /usr/lib/python3.11/EXTERNALLY-MANAGED
  358  ls
  359  sudo python3 tkinter.py
  360  sudo pip install tk
  361  sudo python3 tkinter.py
  362  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch1" -m "on"
  363  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch1" -m "off"
  364  rm -rf tkinter.py
  365  nano dummy.py
  366  sudo python3 dummy.py
  367  nano flask.py
  368  sudo python3 flask.py
  369  sudo pip3 install flask
  370  sudo python3 flask.py
  371  nano flask.py
  372  clear
  373  ls
  374  nano dummy.py
  375  rm -rf dummy.py flask.py
  376  ls
  377  nano 123123.py
  378  ls
  379  sudo python3 123123.py
  380  ls
  381  sudo python3 123123.py
  382  myaql
  383  mysql
  384  whereis mysql-server
  385  whereis mysql
  386  sudo apt install mysql-server
  387  sudo apt install mysql
  388  sudo apt install mysql-server
  389  sudo apt-get install mariadb-server
  390  sudo apt install mysql-server
  391  sudo mysql -u root -p
  392  sudo apt install mysql-server
  393  sudo mysql_secure_installation
  394  sudo apt install mysql-server
  395  sudo mysql_secure_installation
  396  sudo mysql -u root -p
  397  sudo apt update
  398  sudo apt upgrade
  399  sudo mysql -u root -p
  400  # Import the MySQL GPG key
  401  sudo apt-key adv --fetch-keys 'https://dev.mysql.com/doc/refman/8.0/en/checking-gpg-signature.html'
  402  # Add the MySQL APT repository
  403  sudo add-apt-repository 'deb [arch=amd64,arm64,ppc64el] http://repo.mysql.com/apt/ubuntu focal mysql-8.0'
  404  # Update the package list
  405  sudo apt update
  406  # Install MySQL Server
  407  sudo apt install mysql-server
  408  sudo apt autoremove mariadb
  409  mariadb
  410  sudo mysql -u root -p
  411  ls
  412  cd mqttapp
  413  ls
  414  sudo python3 mqttapp.py
  415  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch1" -m "off"
  416  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch4" -m "on"
  417  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch4" -m "off"
  418  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch1" -m "off"
  419  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch4" -m "on"
  420  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch4" -m "off"
  421  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch4" -m "on"
  422  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch3" -m "on"
  423  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch4" -m "off"
  424  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch3" -m "off"
  425  sudo python3 mqttapp.py
  426  nano mqttapp.py
  427  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch3" -m "off"
  428  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch2" -m "off"
  429  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch2\4" -m "off"
  430  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch4" -m "off"
  431  nano mqttapp.py
  432  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch1" -m "off"
  433  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch2" -m "off"
  434  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch4" -m "off"
  435  nano mqttapp.py
  436  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch4" -m "on"
  437  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch3" -m "on"
  438  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch4" -m "on"
  439  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch3" -m "on"
  440  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch3" -m "off"
  441  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch4" -m "on"
  442  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch3" -m "on"
  443  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch3" -m "off"
  444  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch4" -m "off"
  445  clear
  446  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch4" -m "off"
  447  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch3" -m "off"
  448  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch2" -m "off"
  449  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch1" -m "off"
  450  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch2" -m "off"
  451  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch3" -m "off"
  452  mosquitto_pub -h "192.168.1.94" -t "prism/board1/switch4" -m "off"
  453  sudo shutdown now
  454  ls
  455  sudo apt update
  456  sudo apt upgrade
  457  sudo raspi-config
  458  sudo shutdown now
  459  nmcli device
  460  sudo nmcli device wifi hotspot ssid <secureLAN> password <secureLAN> ifname wlan0
  461  sudo nmcli device wifi hotspot ssid secureLAN password secureLAN ifname wlan0
  462  hostname -I
  463  nmcli device
  464  clear
  465  nmcli device
  466  reboot
  467  sudo reboot
  468  clear
  469  ls
  470  nmcli device
  471  sudo nmcli device wifi hotspot ssid pinetwork password pinetwork ifname wlan0
  472  nmcli device
  473  ifconfig wlan0
  474  ifconfig wlx502b73c4193b
  475  sudo nano /etc/hostapd/hostapd.conf
  476  sudo systemctl restart hostapd
  477  nmcli con list
  478  nmcli help
  479  nmcli g
  480  nmcli n
  481  nmcli c
  482  nmcli a
  483  nmcli m
  484  sudo nmcli device wifi.hidden hotspot ssid pinetwork password pinetwork ifname wlan0
  485  man nm-settings
  486  cd /etc/NetworkManager/system-connections
  487  ls
  488  nmcli device
  489  sudo nano Hotspot.nmconnection
  490  sudo nano Hotspot-1.nmconnection
  491  sudo nmcli device wifi.hidden hotspot ssid pinetwork password pinetwork ifname wlan0
  492  sudo nmcli device wifi hotspot ssid pinetwork password pinetwork ifname wlan0
  493  nmcli device
  494  sudo nano Hotspot-1.nmconnection
  495  sudo nano Hotspot.nmconnection
  496  sudo nmcli device wifi hotspot ssid pinetwork password pinetwork ifname wlan0
  497  reboot
  498  sudo reboot
  499  ls
  500  cd /etc/NetworkManager/system-connections
  501  ls
  502  sudo nano Hotspot-1.nmconnection
  503  sudo nmcli device wifi hotspot ssid pinetwork password pinetwork ifname wlan0
  504  sudo nano Hotspot-1.nmconnection
  505  sudo nano Hotspot.nmconnection
  506  sudo nmcli device wifi hotspot ssid secureLAN password secureLAN ifname wlan0
  507  nmcli device
  508  sudo nano Hotspot.nmconnection
  509  nmcli device
  510  cd ..
  511  cd ....
  512  cd
  513  ls
  514  ifconfig wlan0
  515  ifconfig wlx502b73c4193b
  516  sudo shutdown now
  517  ls
  518  nmcli device
  519  sudo nmcli device wifi hotspot ssid secureLAN password secureLAN ifname wlan0
  520  mosquitto_pub -h "10.42.0.1" -t "prism/board1/switch1" -m "on"
  521  mosquitto_pub -h "10.42.0.1" -t "prism/board1/switch2" -m "on"
  522  mosquitto_pub -h "10.42.0.1" -t "prism/board1/switch3" -m "on"
  523  mosquitto_pub -h "10.42.0.1" -t "prism/board1/switch4" -m "on"
  524  ls
  525  nmcli device
  526  sudo nmcli device wifi hotspot ssid secureLAN password secureLAN ifname wlan0
  527  cd etc
  528  cd '
  529  cd /
  530  ls
  531  cd etc
  532  cd init.d
  533  ls
  534  cd ..
  535  ls
  536  sudo nano rc.local
  537  reboot
  538  sudo reboot
  539  ls
  540  nmcli device
  541  sudo nano /etc/rc.local
  542  sudo nano .bashrc
  543  reboot
  544  sudo reboot
  545  nmcli device
  546  reboot
  547  sudo reboot now
  548  nmcli device
  549  ifconfig wlx502b73c4193b
  550  nmcli device
  551  nmcli dev wifi show-password
  552  ls
  553  clear
  554  ls
  555  cd mqttapp
  556  ls
  557  mosquitto_pub -h "10.42.0.1" -t "prism/board1/switch2" -m "on"
  558  mosquitto_pub -h "10.42.0.1" -t "prism/board1/switch3" -m "on"
  559  mosquitto_pub -h "10.42.0.1" -t "prism/board1/switch1" -m "on"
  560  mosquitto_pub -h "10.42.0.1" -t "prism/board1/switch4" -m "on"
  561  mosquitto_pub -h "10.42.0.1" -t "prism/board1/switch1" -m "off"
  562  mosquitto_pub -h "10.42.0.1" -t "prism/board1/switch2" -m "off"
  563  mosquitto_pub -h "10.42.0.1" -t "prism/board1/switch3" -m "off"
  564  mosquitto_pub -h "10.42.0.1" -t "prism/board1/switch4" -m "off"
  565  ls
  566  ifconfig
  567  cd ..
  568  ls
  569  cd mqttapp
  570  ls
  571  sudo python3 mqttapp.py
  572  cd mqttapp
  573  sudo python3 mqttapp.py
  574  sudo shutdown now
  575  cd mqttapp]
  576  cd mqttapp
  577  ls
  578  sudo python3 mqttapp.py
  579  ifcoind
  580  ifconfig
  581  sudo raspi-config
  582  nmcli device
  583  cd mqttapp
  584  ls
  585  sudo python3 mqttapp.py
  586  ls
  587  sudo python3 mqttapp.py
  588  ifconfig
  589  nmcli device
  590  ifconfig
  591  cd mqttapp
  592  ls
  593  sudo python3 mqttapp.py
  594  clear
  595  nmcli device
  596  ifconfig
  597  sudo python3 mqttapp.py
  598  sudo shutdown now
  599  ls
  600  nmcli device
  601  sudo raspi-config
  602  lks
  603  ls
  604  clear
  605  ls
  606  cd mqttapp
  607  ls
  608  nano mqttapp.py
  609  nmcli dev
  610  ls
  611  cd mqttapp
  612  ls
  613  nano mqttapp.py
  614  python3 mqttapp.py
  615  sudo shutdown now
  616  clear
  617  cd mqttapp
  618  python3 mqttapp.py
  619  sudo shutdown now
  620  cllear
  621  clear
  622  ls
  623  nmcli device
  624  sudo raspi-config
  625  nmcli device
  626  sudo raspi-config
  627  nmcli device
  628  reboot
  629  sudo reboot
  630  nmcli device
  631  sudo raspi-config
  632  nmcli device
  633  sudo raspi-config
  634  clear
  635  nmcli device
  636  reboot
  637  ls
  638  clear
  639  nmcli device
  640  sudo nmcli d wifi connect Aitesam961 password 12341234 ifname wlan1
  641  nmcli device
  642  ifconfig 
  643  clear
  644  sudo shutdown now
  645  nmcli device
  646  ls
  647  cd Desktop
  648  ls
  649  cd electrovity-server
  650  ls
  651  history
  652  cd ~/Downloads
  653  ls
  654  cd ..
  655  expo start
  656  whereis expo
  657  ls
  658  cd mqttapp
  659  ls
  660  sudo python3 mqttapp.py
  661  cd ~/Desktop
  662  ls
  663  cd electrovity-server
  664  ls
  665  expo start
  666  ls
  667  whereis uvicorn
  668  uvicorn main:app --host 0.0.0.0 --port 8000 --reload
  669  uvicorn main:app --host 0.0.0.0 --port 8000
  670  nmcli dev
  671  cd ~/Desktop
  672  ls
  673  cd electrovity-server
  674  ls
  675  uvicorn main:app --host 0.0.0.0 --port 8000
  676  clear
  677  cd ~
  678  lsa
  679  clear
  680  lsusb
  681  nmcli dev
  682  ifconfig wlan0 wlan1
  683  ifconfig wlan0
  684  ifconfig wlan1
  685  nmcli connection show
  686  iw dev wlan0 station dump
  687  sudo shutdown now
  688  history
  689  nmcli dev
  690  history
  691  ngrok config add-authtoken 2bRAFLL3Tea08Bg577pYzGpTKu6_7ex4as9fSWHbKxqQYAivD
  692  ngrok
  693  ngrok http 1883
  694  ngrok http 8000
  695  sud oshutdown now
  696  sudo shutdown now
  697  cd Desktop
  698  ls
  699  cd electrovity-server
  700  ls
  701  uvicorn main:app --host 0.0.0.0 --port 8000
  702  ngrok http --domain=eternal-innocent-hamster.ngrok-free.app 8000
  703  cd mqttapp
  704  sudo python3 mqttapp.py
  705  sudo shutdown now
  706  cd Desktop
  707  cd electrovity-server
  708  uvicorn main:app --host 0.0.0.0 --port 8000
  709  ngrok http --domain=eternal-innocent-hamster.ngrok-free.app 8000
  710  sudo shutdown now
  711  cd Desktop
  712  cd electrovity-server
  713  uvicorn main:app --host 0.0.0.0 --port 8000
  714  cd mqttapp
  715  ls
  716  sudo python3 mqttapp.py
  717  nmcli dev
  718  ifconfig
  719  ngrok http --domain=eternal-innocent-hamster.ngrok-free.app 8000
  720  ngrok http --domain=eternal-innocent-hamster.ngrok-free.app 8000 
  721  sudo shutdown now
  722  cd ~/mqttapp & sudo python3 mqttapp.py
  723  cd ~/mqttapp
  724  sudo python3 mqttapp.py
  725  cd ~/Desktop/electrovity-server && uvicorn main:app --host 0.0.0.0 --port 8000
  726  nmcli dev
  727  ifconfig
  728  clear
  729  nmcli dev
  730  ifconfig wlan0
  731  ifconfig wlan1
  732  sudo apt update
  733  sudo apt upgrade
  734  history

