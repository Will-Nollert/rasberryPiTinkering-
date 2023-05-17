#include <wiringPi.h>
#include <stdio.h>

// create an array and assign it to the pin numbers corresponding to the LEDs on the bargraph
int pins[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

// create a function that will turn on the ODD LEDs
void oddLedBarGrap()
{
    for (int i = 0; i < 10; i++)
    {
        int j = i * 2;
        digitalWrite(pins[j], HIGH);
            delay(300);
        digitalWrite(pins[j], LOW);
    }
}
// create a function that will turn on the EVEN LEDs
void evenLedBarGrap()
{
    for (int i = 0; i < 10; i++)
    {
        int j = i * 2 + 1;
        digitalWrite(pins[j], HIGH);
            delay(300);
        digitalWrite(pins[j], LOW);
    }
}

// light every LED on the bargraph one by one
void allLedBarGraph()
{
    for (int i = 0; i < 10; i++)
    {
        digitalWrite(pins[i], HIGH);
        delay(300);
        digitalWrite(pins[i], LOW);
    }
}

// turn off all the LEDs on the bargraph
void clearLedBarGraph()
{
    for (int i = 0; i < 10; i++)
    {
        digitalWrite(pins[i], LOW);
    }
}

// execute the LED test functions
int main(void)
{
    // if set up failed, print error message
    if (wiringPiSetup() == -1)
    {
        printf("setup wiringPi failed!");
        return 1;
    }
    // set all the pins to output mode
    for (int i = 0; i < 10; i++)
    {
        pinMode(pins[i], OUTPUT);
    }
    // execute the LED test functions with a delay of 1 second between each function
    while (1)
    {
        oddLedBarGrap();
        delay(1000);
        evenLedBarGrap();
        delay(1000);
        allLedBarGraph();
        delay(1000);
        clearLedBarGraph();
        delay(1000);
    }

    // finally clear all the pins and turn off all LEDS
    for (int i = 0; i < 10; i++)
    {
        digitalWrite(pins[i], LOW);
    }
    return 0;
}