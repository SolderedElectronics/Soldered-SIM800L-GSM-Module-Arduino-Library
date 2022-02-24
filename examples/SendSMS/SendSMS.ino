/**
 **************************************************
 *
 * @file        SendSMS.ino
 * @brief       This is a bare bone library for communicating with SIM800
 *    It's barebone in that - it only provides basic functunaitlites while still
 *    maintaining strong performance and being memory friendly.
 *    It currently supports GSM(sending and reading SMS),
 *    GPRS connectivity(sending and receiving TCP) with Time and Location
 *
 *    This library is writing by  Ayo Ayibiowu.
 *    charlesayibiowu@hotmail.com
 *    Designed to work with the GSM Sim800l module,
 *    and possibily other SIMxxx modules(not tested with others)
 *
 *    This library use AltSoftSerial, and the pins has already be defined
 *    be sure that GND is attached to arduino too.
 *    The RESET_PIN is not used for this Library, you can leave it un-connected
 *
 *    To Enable Debugging - Go to <BareBoneSim800.h file and change the
 *    #define DEBUG 0 to #define DEBUG 1
 *
 *    PINOUT:
 *        _____________________________
 *       |  ARDUINO UNO >>>   SIM800L  |
 *        -----------------------------
 *            GND      >>>   GND
 *        RX  8       >>>   TX
 *        TX  9       >>>   RX
 *
 *
 *   POWER SOURCE 4.2V (MAX) >>> VCC
 *
 *
 *
 *   Modified by: soldered.com
 *   See more at https://www.solde.red/333071
 *
 * @authors     Created on: Oct 24, 2017
 *              Author: Ayo Ayibiowu
 *              Email: charlesayibiowu@hotmail.com
 *              Version: v1.0
 ***************************************************/

#include "SIM800L-SOLDERED.h"

BareBoneSim800 sim800; //
// BareBoneSim800 sim800("your APN");  //needed for gprs funtionality


void setup()
{
    Serial.begin(115200); //Start serial communication with PC using 115200 baudrate
    sim800.begin(); //Initialize sim800 module
    while (!Serial) //Wait until serial is available
        ;

    Serial.println("Testing GSM module For SMS Sending");
    delay(8000); // this delay is necessary, it helps the device to be ready and connect to a network

    Serial.println("Should be ready by now");
    bool deviceAttached = sim800.isAttached(); //Check if sim800 is connected
    if (deviceAttached)
        Serial.println("Device is Attached");
    else
        Serial.println("Not Attached");

    // Testing sending SMS aspect

    const char *number = "+2347038945220";
    char *message = "Hello, This is a text message";

    delay(1000);

    bool messageSent = sim800.sendSMS(number, message); // Send message to number "number" with content
                                                        // stored in message variable
    if (messageSent)
        Serial.println("Message Sent");
    else
        Serial.println("Not Sent, Something happened");
}

void loop()
{
    // zZZzz
}
