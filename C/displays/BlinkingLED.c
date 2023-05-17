// Blinking LED program for Raspberry Pi 4
#include <wiringPi.h>
#include <stdio.h>
// LED Pin - wiringPi pin 0 is BCM_GPIO 17.
#define LedPin   0

int main(void){
    //when initialize wiring fail
    //print message to screen
    if(wiringPiSetup() == -1){
    printf("wirePi initialize failed!\n");
    return 1;
    }

//set LedPin as output to write some value to it
pinMode(LedPin, OUTPUT);

while(1){
    //cycling LED on
    digitalWrite(LedPin, LOW);
    printf("LED on...\n");
    delay(500);
    //cycling LED off
    digitalWrite(LedPin, HIGH);
    printf("...LED off\n");
    delay(500);
}
return 0;
}