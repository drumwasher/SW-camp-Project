/*
 * Configration_ISR.h
 *
 *  Created on: 2024. 2. 21.
 *      Author: JINKYU
 */

#ifndef CONFIGURATION_ISR_H_
#define CONFIGURATION_ISR_H_

#define ISR_ASSIGN(no,cpu) ((no<<8)+cpu)
#define ISR_PRIORITY(no_cpu) (no_cpu>>8)
#define ISR_PROVIDER(no_cpu) (no_cpu%8)

#define ISR_PRIORITY_TIMER 200
#define ISR_PROVIDER_TIMER IfxSrc_Tos_cpu0
#define INTERRUPT_TIMER ISR_ASSIGN(ISR_PRIORITY_TIMER,ISR_PROVIDER_TIMER)

#endif /* CONFIGURATION_ISR_H_ */
