/**
 **************************************************
 *
 * @file        ReceiveSMS.ino
 * @brief       This is a bare bone library for communicating with SIM800
 *    It's barebone in that - it only provides basic functionalities while still
 *    maintaining strong performance and being memory friendly.
 *    It currently supports GSM(sending and reading SMS),
 *    GPRS connectivity(sending and receiving TCP) with Time and Location
 *
 *    This library is written by Ayo Ayibiowu.
 *    charlesayibiowu@hotmail.com
 *    Designed to work with the GSM Sim800l module
 *
 *    To Enable Debugging - Go to <BareBoneSim800.h file and change the
 *    #define DEBUG 0 to #define DEBUG 1
 *
 *    PINOUT:
 *        _____________________________
 *       |  Dasduino  >>>   SIM800L   |
 *        -----------------------------
 *           GND      >>>   GND
 *        RX  8       >>>   TX
 *        TX  9       >>>   RX
 *           VCC      >>>   VCC
 *    Also, you have to connect the PWRKEY pin to the VCC or some digital pin if you want to control the module.
 *    You can change RX and TX pins callilng setPins() function before begin(), these are the default ones.
 *
 *
 *   Modified by: soldered.com, 21 March 2023
 *   See more at https://www.solde.red/333071
 *
 * @authors     Created on: Oct 24, 2017
 *              Author: Ayo Ayibiowu
 *              Email: charlesayibiowu@hotmail.com
 *              Version: v1.0
 ***************************************************/

#include "SIM800L-SOLDERED.h"

SIM800L sim800;
// SIM800L sim800("your APN");  //needed for gprs funtionality


void setup()
{
    Serial.begin(115200); // Start serial communication with PC using 115200 baudrate
    sim800.begin();       // Initialize sim800 module
    while (!Serial)       // Wait until serial is available
        ;

    Serial.println("Testing GSM module For SMS");
    delay(8000); // This delay is necessary, it helps the device to be ready and connect to a network

    Serial.println("Should be ready by now");
    bool deviceAttached = sim800.isAttached(); // Check if sim800 is connected
    if (deviceAttached)
    {
        Serial.println("Device is Attached");
    }
    else
    {
        Serial.println("Not Attached");

        while (1)
            ;
    }

    // Receiving and Viewing SMS
    String message = "";
    int messageIndex = 1;
    message = sim800.readSMS(messageIndex); // Store message with index messageIndex in message variable
    Serial.print("Received message is: ");
    Serial.println(message);
}

void loop()
{
    // zZZzz
}
