#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    gpio_t gasDetector, overTempDetector, alarmOffButton, alarmLED;
    //DigitalIn gasDetector(D2);
    gpio_init_in_ex(&gasDetector, D2, PullDown);
    gpio_init_in_ex(&overTempDetector, D3, PullDown);
    gpio_init_in(&alarmOffButton, BUTTON1);
    //DigitalIn gasDetector(D2);
    //DigitalIn overTempDetector(D3);
    //DigitalIn alarmOffButton(BUTTON1);

    gpio_init_out(&alarmLED,LED1);
    DigitalOut alarmLed(LED1);

    //gasDetector.mode(PullDown);
    //overTempDetector.mode(PullDown);

    alarmLed = OFF;

    bool alarmState = OFF;

    while (true) {

        if ( gpio_read(&gasDetector) || gpio_read(&overTempDetector) ) {
            alarmState = ON;
        }

        alarmLed = alarmState;

        if ( gpio_read(&alarmOffButton) ) {
            alarmState = OFF;
        }
    }
}