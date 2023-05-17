#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>

#define uchar unsigned char
#define LedPinRed 0
#define LedPinGreen 1
#define LedPinBlue 2

void ledInit(void){
    softPwmCreate(LedPinRed, 0, 100);
    softPwmCreate(LedPinGreen, 0, 100);
    softPwmCreate(LedPinBlue, 0, 100);
}

void ledColorSet(uchar r_val, uchar g_val, uchar b_val){
    softPwmWrite(LedPinRed, r_val);
    softPwmWrite(LedPinGreen, g_val);
    softPwmWrite(LedPinBlue, b_val);
}

void cleanup(){
    softPwmStop(LedPinRed);
    softPwmStop(LedPinGreen);
    softPwmStop(LedPinBlue);
}

int main(void){
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
    cleanup();
    return 0;
}
