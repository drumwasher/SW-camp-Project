/*
 * Blink_LED2.c
 *
 *  Created on: 2024. 2. 20.
 *      Author: JINKYU
 */

#include "Blink_LED2.h"
#include "IfxPort.h"
#include "Bsp.h"
#include "ADC.h"
#define LED &MODULE_P10,2

void initLED(void){
    IfxPort_setPinModeOutput(LED, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    IfxPort_setPinLow(LED);

}
void blinkLED(void){
    IfxPort_togglePin(LED);
    waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER,stSensorAdcRaw.UlSSence0_RAW));
}

