#include <wiringPi.h>
#include <stdio.h>
//Pule width modulation
//Allows us to vary the brightness of the LED
//By getting and artifical analog output on a digital pin
#include <softPwm.h>

#define uchar unsigned char
#define LedPinRed 0
#define LedPinGreen 1
#define LedPinBlue 2

//function to create a PWM pin +
// set the range to 0-100
void ledInit(void){
    softPwmCreate(LedPinRed, 0, 100);
    softPwmCreate(LedPinGreen, 0, 100);
    softPwmCreate(LedPinBlue, 0, 100);
}

/* function  sets the color of 
an RGB LED using PWM values for its color channels.
takes three input parameters: r_val, g_val, and 
b_val which represent the desired */
void ledColorSet(uchar r_val, uchar g_val, uchar b_val){
    softPwmWrite(LedPinRed, 100);
    softPwmWrite(LedPinGreen, 0);
    softPwmWrite(LedPinBlue, 0);
}

int main(void){
    //when initialize wiringPi fail
    //print message to screen
    if(wiringPiSetup() == -1){
        printf("wiringPi initialize failed!\n");
        return 1;
    }
    ledInit();
    while(1){
        ledColorSet(100, 0, 0); //red
        delay(500);
        ledColorSet(0, 100, 0); //green
        delay(500);
        ledColorSet(0, 0, 100); //blue
        delay(500);
        ledColorSet(100, 100, 0); //yellow
        delay(500);
        ledColorSet(0, 100, 100); //cyan
        delay(500);
        ledColorSet(100, 0, 100); //purple
        delay(500);
        ledColorSet(255, 255, 255); //white
        delay(500);
        ledColorSet(0, 0, 0); //close
        delay(500);
    }
    return 0;
}