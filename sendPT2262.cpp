/*
 Usage: ./sendPT2262 <AddressCode> <PinCode> <delayUs>
 "F" = 2 . AddressCode len =12.
 */

#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int strin012(char* scode);

int strin012(char* code){
    int i = 0;
    while (i<8) {//8bite in {0,1,2}
      switch(*(code+i)) {
        case '0':
        case '2':
        case '1':
        break;
		default:
		return 1;
      }
      i++;
    }
    while (i<12) {//4bite in {0,1}
      switch(*(code+i)) {
        case '0':
        case '1':
        break;
		default:
		return 1;
      }
      i++;
    }
	return 0;
}

int main(int argc, char *argv[]) {
    
    /*
     output PIN is hardcoded for testing purposes
     see https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     for pin mapping of the raspberry pi GPIO connector
     */
    int PIN = 0;
    char* systemCode = argv[1];
    int outPin = atoi(argv[2]);
    int delayUs  = atoi(argv[3]);

    
    if (wiringPiSetup () == -1) return 1;
  	if (outPin!=NULL) PIN=outPin;
  	if (delayUs==NULL) delayUs=350;
	    printf("sending systemCode[%s] PIN is [%d] BiteWidth is [%d]us.\n", systemCode,PIN,delayUs);
	  if (strlen(systemCode) != 12 ){
		    printf("Input len not 12bite.\nPlease input 8bit Address {0,1,2} and 4bit Chanel {0,1}.\nLike 222211110001 0 350.\n");
		    return 1;
	  }
	  if (strin012(systemCode)) {
		    printf("Input 8bite Address not in {0,1,2} or 4bite Chanel not in {0,1}.\nPlease input 8bit Address {0,1,2} and 4bit Chanel {0,1}.\nLike 222211110001 0 350.\n");
		    return 1;
	  }

	RCSwitch mySwitch = RCSwitch();
	mySwitch.enableTransmit(PIN);
	mySwitch.setPulseLength(delayUs);
	mySwitch.send2262(systemCode);

	return 0;
}


