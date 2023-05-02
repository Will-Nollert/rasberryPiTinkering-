const GPIO = require("pigpio").Gpio;
const led = new GPIO(17, {mode: GPIO.OUTPUT});

let led_state = 0;

setInterval(() => {
    led.digitalWrite(led_state);
    led_state = 1 - led_state;
}, 200);