/*
 * Scheduling.h
 *
 *  Created on: 2024. 2. 20.
 *      Author: JINKYU
 */

#ifndef DRIVER_STM_H_
#define DRIVER_STM_H_

#include "Ifx_Types.h"
#include "IfxStm.h"
#include "IfxCpu_Irq.h"

typedef struct
{
     uint8 u8nuSchduling1msFlag;
     uint8 u8nuSchduling10msFlag;
     uint8 u8nuSchduling100msFlag;
     uint8 u8nuSchduling1sFlag;
}SchedulingFlag;

extern SchedulingFlag stSchedulingInfo;

extern void Driver_Stm_Init(void);




#endif /* DRIVER_STM_H_ */
