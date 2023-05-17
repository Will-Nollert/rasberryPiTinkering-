#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <string.h>

// LCD address for backlight status and control
int LCDAddr = 0x27;
int BLEN = 1;
//File descriptor for LCD
int fd;

//function to write a word of data to the LCD
void write_word(int data){
    int temp = data;
    if ( BLEN == 1 )
        temp |= 0x08;
    else
        temp &= 0xF7;
    wiringPiI2CWrite(fd, temp);
}

//function to send command to the LCD
void send_command(int comm){
    int buf;
    // Send bit7-4 firstly
    buf = comm & 0xF0;
    buf |= 0x04;            // RS = 0, RW = 0, EN = 1
    write_word(buf);
    delay(2);
    buf &= 0xFB;            // Make EN = 0
    write_word(buf);

    // Send bit3-0 secondly
    buf = (comm & 0x0F) << 4;
    buf |= 0x04;            // RS = 0, RW = 0, EN = 1
    write_word(buf);
    delay(2);
    buf &= 0xFB;            // Make EN = 0
    write_word(buf);
}

//function to send Data to the LCD

void send_data(int data){
    int buf;
    // Send bit7-4 firstly
    buf = data & 0xF0;
    buf |= 0x05;            // RS = 1, RW = 0, EN = 1
    write_word(buf);
    delay(2);
    buf &= 0xFB;            // Make EN = 0
    write_word(buf);

    // Send bit3-0 secondly
    buf = (data & 0x0F) << 4;
    buf |= 0x05;            // RS = 1, RW = 0, EN = 1
    write_word(buf);
    delay(2);
    buf &= 0xFB;            // Make EN = 0
    write_word(buf);
}

// Function to initialize the LCD
void init() {
    send_command(0x33);    // Must initialize to 8-line mode at first
    delay(5);
    send_command(0x32);    // Then initialize to 4-line mode
    delay(5);
    send_command(0x28);    // 2 Lines & 5x7 dots
    delay(5);
    send_command(0x0C);    // Enable display without cursor
    delay(5);
    send_command(0x01);    // Clear screen
    wiringPiI2CWrite(fd, 0x08);  // Turn off the backlight
}


// Function to clear the LCD screen
void clear() {
    send_command(0x01);    // Clear screen
}

void write(int x, int y, char data[]){
	int addr, i;
	int tmp;
	if (x < 0)  x = 0;
	if (x > 15) x = 15;
	if (y < 0)  y = 0;
	if (y > 1)  y = 1;

	// Move cursor
	addr = 0x80 + 0x40 * y + x;
	send_command(addr);
	
	tmp = strlen(data);
	for (i = 0; i < tmp; i++){
		send_data(data[i]);
	}
}


void main(){
	fd = wiringPiI2CSetup(LCDAddr);
	init();
	write(0, 0, "Greetings!");
	write(1, 1, "From SunFounder");
}