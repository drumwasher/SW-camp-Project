/*
 * ADC.c
 *
 *  Created on: 2024. 2. 20.
 *      Author: JINKYU
 */
#include "ADC.h"
#include "IfxVadc.h"
#include "IfxVadc_Adc.h"

typedef struct
{
        IfxVadc_Adc vadc;
        IfxVadc_Adc_Group adcGroup;
}App_VadcAutoScan;

static void DrvAdc_Group0Init(void);
static void DrvAdc_Group0ChannelInit(uint8 param_ChNum);

App_VadcAutoScan g_VadcAutoScan;

IfxVadc_Adc_Channel adc0Channel[ADC_GROUP0_MAX];

SensorAdcRaw stSensorAdcRaw;

static void DrvAdc_Group0ChannelInit(uint8 param_ChNum)
{
    IfxVadc_Adc_ChannelConfig adcChannelConfigInfo;
    uint32 ulTemp = ((uint32)1u << param_ChNum);

    IfxVadc_Adc_initChannelConfig(&adcChannelConfigInfo, &g_VadcAutoScan.adcGroup);

    adcChannelConfigInfo.channelId = (IfxVadc_ChannelId)(param_ChNum);
    adcChannelConfigInfo.resultRegister = (IfxVadc_ChannelResult)(param_ChNum);

    IfxVadc_Adc_initChannel(&adc0Channel[param_ChNum], &adcChannelConfigInfo);

    IfxVadc_Adc_setScan(&g_VadcAutoScan.adcGroup, ulTemp, ulTemp);
}

void DrvAdcInit(void)
{
    DrvAdc_Group0Init();
}

void DrvAdc_Group0Init(void)
{
    IfxVadc_Adc_Config adcConfig;
    IfxVadc_Adc_initModuleConfig(&adcConfig, &MODULE_VADC);

    IfxVadc_Adc_initModule(&g_VadcAutoScan.vadc, &adcConfig);

    IfxVadc_Adc_GroupConfig adcGroupConfig;
    IfxVadc_Adc_initGroupConfig(&adcGroupConfig, &g_VadcAutoScan.vadc);

    adcGroupConfig.groupId = IfxVadc_GroupId_0;
    adcGroupConfig.master = adcGroupConfig.groupId;

    adcGroupConfig.arbiter.requestSlotScanEnabled = TRUE;

    adcGroupConfig.scanRequest.autoscanEnabled = TRUE;

    adcGroupConfig.scanRequest.triggerConfig.gatingMode = 1;

    IfxVadc_Adc_initGroup(&g_VadcAutoScan.adcGroup, &adcGroupConfig);

    DrvAdc_Group0ChannelInit(ADC_GROUP0_CH0);

    IfxVadc_Adc_startScan(&g_VadcAutoScan.adcGroup);
}
extern void DrvAdc_GetAdcRawGroup0(void)
{
    Ifx_VADC_RES conversionResult;

    conversionResult = IfxVadc_Adc_getResult(&adc0Channel[ADC_GROUP0_CH0]);
    stSensorAdcRaw.UlSSence0_RAW = conversionResult.B.RESULT;

    IfxVadc_Adc_startScan(&g_VadcAutoScan.adcGroup);
}
