/*
 * Scheduling.c
 *
 *  Created on: 2024. 2. 20.
 *      Author: JINKYU
 */
#include "DRIVER_STM.h"
#include "IfxPort.h"
#include "IfxPort_Pinmap.h"

typedef struct
{
        Ifx_STM *stmSfr;
        IfxStm_CompareConfig stmConfig;
}App_Stm;

App_Stm g_Stm;
uint32 u32nuCounter1ms = 0;
SchedulingFlag stSchedulingInfo;




void Driver_Stm_Init()
{
    boolean interruptState = IfxCpu_disableInterrupts();

    IfxStm_enableOcdsSuspend(&MODULE_STM0);

    g_Stm.stmSfr = &MODULE_STM0;
    IfxStm_initCompareConfig(&g_Stm.stmConfig);

    g_Stm.stmConfig.triggerPriority = 100u;
    g_Stm.stmConfig.typeOfService = IfxSrc_Tos_cpu0;
    g_Stm.stmConfig.ticks = 100000u;

    IfxStm_initCompare(g_Stm.stmSfr, &g_Stm.stmConfig);

    IfxCpu_restoreInterrupts(interruptState);
}

IFX_INTERRUPT(STM_IntHandler,0,100);

void STM_IntHandler(void)
{
    IfxCpu_enableInterrupts();

    IfxStm_clearCompareFlag(g_Stm.stmSfr,g_Stm.stmConfig.comparator);
    IfxStm_increaseCompare(g_Stm.stmSfr,g_Stm.stmConfig.comparator,100000u);

    u32nuCounter1ms++;

    if((u32nuCounter1ms % 1) == 0u)
    {
        stSchedulingInfo.u8nuSchduling1msFlag = 1u;
    }

    if((u32nuCounter1ms % 10) == 0u)
    {
        stSchedulingInfo.u8nuSchduling10msFlag = 1u;
    }

    if((u32nuCounter1ms % 100) == 0u)
    {
        stSchedulingInfo.u8nuSchduling100msFlag = 1u;
    }
    if((u32nuCounter1ms % 1000) == 0u)
    {
        stSchedulingInfo.u8nuSchduling1sFlag = 1u;
    }
}
