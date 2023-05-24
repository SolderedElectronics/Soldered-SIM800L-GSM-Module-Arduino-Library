/**
 **************************************************
 *
 * @file        SendSMS.ino
 * @brief       Send an SMS with SIM800 Breakout by Soldered
 * 
 *              To successfully run the sketch:
 *              -Change RX and TX pin defines, according to your board.
 *              -Insert a valid SIM card in the SIM800 module.
 *              -Change the phone number to a valid one in the code below.
 * 
 *              NOTE: SIM800 draws a lot of current so additional power with a good connection is probably required.
 * 
 *              To Enable Debugging - Go to <BareBoneSim800.h file and change the
 *              #define DEBUG 0 to #define DEBUG 1
 *
 * @authors     Karlo Leksic for soldered.com
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

// +385 is the country code for Croatia, change it to yours and replace # signs with the number you want to text
const char *phoneNumber = "+385#########";

// You may also change the contents of the message here
char *message = "Hello from SIM800!";

// Create SIM800 object on the given pins
SIM800L sim800(RX_PIN, TX_PIN);

void setup()
{
    // Start Serial communication with PC using 115200 baud rate
    Serial.begin(115200);

    // This must be called if we are using pins other than default
    // sim800.setPins(RX_PIN, TX_PIN);

    sim800.begin(); // Initialize SIM800 module
    Serial.println("Sending a text with SIM800 Breakout...");

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
    Serial.println("Sending SMS!");

    // Send the SMS and check if it was sent
    if (sim800.sendSMS(phoneNumber, message))
    {
        Serial.println("SMS Sent!");
    }
    else
    {
        Serial.println("Something went wrong when sending the SMS.");
    }
}

void loop()
{
    // Nothing here
}