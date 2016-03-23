# About
RCSwitch-piPT2262
rcswitch-pi-PT2262 is for controlling rc remote controlled power sockets 
with the raspberry pi. 
RCSwitch-pi and PT2262 encode 

example:
sendPT2262 112211001000 0 200
sendPT2262 84 PIN us
  


#
Kudos to the projects [rc-switch](http://code.google.com/p/rc-switch)
and [wiringpi](https://projects.drogon.net/raspberry-pi/wiringpi).
I just adapted the rc-switch code to use the wiringpi library instead of
the library provided by the arduino.


## Usage

First you have to install the [wiringpi](https://projects.drogon.net/raspberry-pi/wiringpi/download-and-install/) library.
After that you can compile the example program *send* by executing *make*. 
You may want to changet the used GPIO pin before compilation in the send.cpp source file.
