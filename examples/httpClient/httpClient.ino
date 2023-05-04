/**
 **************************************************
 *
 * @file        httpClient.ino
 * @brief       Example for connecting to the internet with the SIM800 module.
 *
 *              To successfully run the sketch:
 *              -Change RX and TX pin defines, according to your board.
 *              -Insert a valid SIM card in the SIM800 module.
 *              - Make sure the card can go on the internet.
 *
 *              NOTE: SIM800 draws a lot of current so additional power with a good connection is probably required.
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

// Include soldered library sof SIM800L breakout
#include "SIM800L-SOLDERED.h"

// RX and TX pins
// Make sure to change this if required
#define RX_PIN 8
#define TX_PIN 9

// Create SIM800 object with a specified APN
// APN (Access Point Name) is an identifier which helps mobile networks connect to the internet
// To find yours:
//  -Insert the SIM800 SIM card into your mobile phone
//  -Check 'Mobile Data Options' (or similar) in your Settings app
// The right one should be automatically selected.
SIM800L sim800("internet.ht.hr");

// Link to make sample GET request with
char resource[] = "postman-echo.com/get";

// HTTP Port
const int port = 80;

void setup()
{
    // Start Serial communication with PC using 115200 baud rate
    Serial.begin(115200);

    // This must be called if we are using pins other than default
    sim800.setPins(RX_PIN, TX_PIN);

    sim800.begin(); // Initialize SIM800 module
    Serial.println("Doing GET request on the internet with SIM800 Breakout...");

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

    // Connect to the GPRS APN Network
    Serial.println("Connecting to APN...");
    if (sim800.gprsConnect())
    {
        Serial.println("Connected!");
    }
    else
    {
        Serial.println("Something went wrong while connecting.");
        while (1)
        {
            delay(100);
        }
    }

    Serial.println("Making HTTP GET request...");

    // Send request and print the result!
    String result = sim800.sendHTTPData(resource);
    Serial.println("Received: ");
    Serial.println(result);

    // Disconnect and close connection with network
    sim800.closeHTTP();
    sim800.gprsDisconnect();
}

void loop()
{
    // Nothing here
}
