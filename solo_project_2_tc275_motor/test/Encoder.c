/*
 * Encoder.c
 *
 *  Created on: 2024. 2. 21.
 *      Author: JINKYU
 */

#include "Encoder.h"
#include "Ifx_Types.h"
#include "IfxPort.h"
#include "Bsp.h"

#define Encoder_A &MODULE_P14,0
#define Encoder_B &MODULE_P14,1

void initEncoder(void)
{
    IfxPort_setPinModeInput(Encoder_A, IfxPort_InputMode_pullUp);
    IfxPort_setPinModeInput(Encoder_B, IfxPort_InputMode_pullUp);
}
boolean getEncoderAValue(void)
{
    return IfxPort_getPinState(Encoder_A);
}
boolean getEncoderBValue(void)
{
    return IfxPort_getPinState(Encoder_B);
}

