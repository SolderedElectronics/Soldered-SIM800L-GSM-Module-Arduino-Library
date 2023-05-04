/**
 **************************************************
 *
 * @file        recieveCall.ino
 * @brief       Example for recieving a phone call with the SIM800 module.
 *
 *              To successfully run the sketch:
 *              -Change RX and TX pin defines, according to your board.
 *              -Insert a valid SIM card in the SIM800 module.
 *              -Call the number of the SIM card once it's ready.
 *
 *              To Enable Debugging - Go to <BareBoneSim800.h file and change the
 *              #define DEBUG 0 to #define DEBUG 1
 *
 * @author     Karlo Leksic for soldered.com
 *
 *   See more at https://www.solde.red/333071
 ***************************************************/

/**
 * Connecting diagram:
 *
 * SIM800 Breakout              Dasduino Core / Connect / ConnectPlus
 * GND------------------------->GND
 * TX-------------------------->RX (PIN 8) / 13 / IO33
 * RX-------------------------->TX (PIN 9) / 12 / IO32
 * VCC------------------------->VCC
 * PWRKEY---------------------->VCC
 *
 * You may use any other available pins on your board as well.
 */

// Include soldered library of SIM800L breakout
#include "SIM800L-SOLDERED.h"

// RX and TX pins
// Make sure to change this if required
#define RX_PIN 8
#define TX_PIN 9

// Create SIM800 object on the given pins
SIM800L sim800(RX_PIN, TX_PIN);

void setup()
{
    // Start Serial communication with PC using 115200 baud rate
    Serial.begin(115200);

    // This must be called if we are using pins other than default
    // sim800.setPins(RX_PIN, TX_PIN);

    sim800.begin(); // Initialize SIM800 module
    Serial.println("Checking for new SMS with SIM800 Breakout...");

    // This delay is necessary, it helps the device to be ready and connect to a network
    delay(8000);
    Serial.println("Device should be ready by now.");

    // Check if SIM800 is connected
    if (sim800.isAttached())
    {
        Serial.println("Device is Attached");
    }
    else
    {
        Serial.println("Can't find SIM800!");

        // Can't find SIM800 module, go to infinite loop
        while (1)
        {
            delay(100);
        }
    }

    Serial.println("SIM800 found!");
    Serial.println("Call me!");
}

void loop()
{
    // Check for an incoming call
    if (sim800.incomingCall())
    {
        // Let it ring for a bit
        delay(2000);

        // Hang up the call
        sim800.hangUpCall();

        // Alternatively, you can answer the call with
        // sim800.answerCall();
    }

    // Wait a half a second before checking again
    delay(500);
}
