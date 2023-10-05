/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "Led.h"

// Blinking rate in milliseconds
#define BLINKING_RATE     500ms

#define GREEN_LED     PC_7   // LD1 LED_GREEN
#define BLUE_LED      PB_7   // LD2 LED_BLUE
#define RED_LED       PG_2   // LD3 LED_RED

int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut gLed(GREEN_LED);
    DigitalOut* p = &gLed;
    *p = 0; // led = 0;
    p->write(0);
    Led myLed(BLUE_LED);
    DigitalOut *red = new DigitalOut(RED_LED);
    gLed = 1;
    *myLed.getDigitalOut() = 0;
    myLed.getDigitalOut()->write(1);
    ThisThread::sleep_for(BLINKING_RATE);
    *myLed.getDigitalOut() = 0;
    
    while (true) {
        gLed = !gLed;
        *red = !*red;
        ThisThread::sleep_for(BLINKING_RATE);
    }
    delete red;

}
