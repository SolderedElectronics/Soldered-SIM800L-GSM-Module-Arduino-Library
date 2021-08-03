/**
 **************************************************
 *
 * @file        SIM800L-SOLDERED.h
 * @brief       Header file for the SIM800L module by Soldered
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors     Zvonimir Haramustek for soldered.com
 ***************************************************/

#ifndef __SIM800L_SOLDERED__
#define __SIM800L_SOLDERED__

#include "Arduino.h"

#include "libs/BareBoneSim800/BareBoneSim800.h"

class SIM800L : public BareBoneSim800
{
};

#undef BareBoneSim800

#endif
