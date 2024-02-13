/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: dcmotor_test.c
 *
 * Code generated for Simulink model 'dcmotor_test'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Feb 12 22:14:58 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "dcmotor_test.h"
#include "dcmotor_test_private.h"
#include "rtwtypes.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_dcmotor_test_T dcmotor_test_B;

/* Block states (default storage) */
DW_dcmotor_test_T dcmotor_test_DW;

/* Real-time model */
static RT_MODEL_dcmotor_test_T dcmotor_test_M_;
RT_MODEL_dcmotor_test_T *const dcmotor_test_M = &dcmotor_test_M_;

/* Callback for Hardware Interrupt Block: '<Root>/External Interrupt' */
void MW_ISR_2(void)
{
  /* Call the system: <Root>/Function-Call Subsystem */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(dcmotor_test_DW.FunctionCallSubsystem_SubsysRan);

    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

    /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */

    /* Asynchronous task (with no priority assigned)
     * reads absolute time */
    switch (dcmotor_test_M->Timing.rtmDbBufWriteBuf1) {
     case 0:
      dcmotor_test_M->Timing.rtmDbBufReadBuf1 = 1;
      break;

     case 1:
      dcmotor_test_M->Timing.rtmDbBufReadBuf1 = 0;
      break;

     default:
      dcmotor_test_M->Timing.rtmDbBufReadBuf1 =
        dcmotor_test_M->Timing.rtmDbBufLastBufWr1;
      break;
    }

    dcmotor_test_M->Timing.clockTick1 =
      dcmotor_test_M->Timing.rtmDbBufClockTick1
      [dcmotor_test_M->Timing.rtmDbBufReadBuf1];
    dcmotor_test_M->Timing.rtmDbBufReadBuf1 = 0xFF;

    /* Logic: '<S1>/NOT' incorporates:
     *  Delay: '<S1>/Delay'
     */
    dcmotor_test_DW.Delay_DSTATE = !dcmotor_test_DW.Delay_DSTATE;
    dcmotor_test_DW.FunctionCallSubsystem_SubsysRan = 4;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */
  }

  extmodeEvent(1,((dcmotor_test_M->Timing.clockTick1) * 0.01));
}

/* Model step function */
void dcmotor_test_step(void)
{
  uint16_T b_varargout_1;

  /* MATLABSystem: '<Root>/Analog Input' */
  if (dcmotor_test_DW.obj.SampleTime != dcmotor_test_P.AnalogInput_SampleTime) {
    dcmotor_test_DW.obj.SampleTime = dcmotor_test_P.AnalogInput_SampleTime;
  }

  dcmotor_test_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(62UL);
  MW_AnalogInSingle_ReadResult
    (dcmotor_test_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Gain: '<Root>/Gain'
   *  MATLABSystem: '<Root>/Analog Input'
   * */
  dcmotor_test_B.DataTypeConversion = (uint8_T)(((uint32_T)
    dcmotor_test_P.Gain_Gain * b_varargout_1) >> 17);

  /* MATLABSystem: '<Root>/PWM' */
  dcmotor_test_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
  MW_PWM_SetDutyCycle(dcmotor_test_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, (real_T)
                      dcmotor_test_B.DataTypeConversion);

  /* RateTransition: '<Root>/Rate Transition' incorporates:
   *  Delay: '<S1>/Delay'
   */
  dcmotor_test_B.RateTransition = dcmotor_test_DW.Delay_DSTATE;

  /* MATLABSystem: '<Root>/Digital Output' */
  writeDigitalPin(13, (uint8_T)dcmotor_test_B.RateTransition);

  {                                    /* Sample time: [0.01s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  dcmotor_test_M->Timing.taskTime0 =
    ((time_T)(++dcmotor_test_M->Timing.clockTick0)) *
    dcmotor_test_M->Timing.stepSize0;
  switch (dcmotor_test_M->Timing.rtmDbBufReadBuf1) {
   case 0:
    dcmotor_test_M->Timing.rtmDbBufWriteBuf1 = 1;
    break;

   case 1:
    dcmotor_test_M->Timing.rtmDbBufWriteBuf1 = 0;
    break;

   default:
    dcmotor_test_M->Timing.rtmDbBufWriteBuf1 =
      !dcmotor_test_M->Timing.rtmDbBufLastBufWr1;
    break;
  }

  dcmotor_test_M->Timing.rtmDbBufClockTick1
    [dcmotor_test_M->Timing.rtmDbBufWriteBuf1] =
    dcmotor_test_M->Timing.clockTick0;
  dcmotor_test_M->Timing.rtmDbBufLastBufWr1 =
    dcmotor_test_M->Timing.rtmDbBufWriteBuf1;
  dcmotor_test_M->Timing.rtmDbBufWriteBuf1 = 0xFF;
}

/* Model initialize function */
void dcmotor_test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(dcmotor_test_M, -1);
  dcmotor_test_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  dcmotor_test_M->Sizes.checksums[0] = (1861747648U);
  dcmotor_test_M->Sizes.checksums[1] = (3413536121U);
  dcmotor_test_M->Sizes.checksums[2] = (1783690059U);
  dcmotor_test_M->Sizes.checksums[3] = (1423676186U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    dcmotor_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)
      &dcmotor_test_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(dcmotor_test_M->extModeInfo,
      &dcmotor_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(dcmotor_test_M->extModeInfo,
                        dcmotor_test_M->Sizes.checksums);
    rteiSetTPtr(dcmotor_test_M->extModeInfo, rtmGetTPtr(dcmotor_test_M));
  }

  dcmotor_test_M->Timing.rtmDbBufReadBuf1 = 0xFF;
  dcmotor_test_M->Timing.rtmDbBufWriteBuf1 = 0xFF;
  dcmotor_test_M->Timing.rtmDbBufLastBufWr1 = 0;

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */

  /* Asynchronous task (with no priority assigned)
   * reads absolute time */
  switch (dcmotor_test_M->Timing.rtmDbBufWriteBuf1) {
   case 0:
    dcmotor_test_M->Timing.rtmDbBufReadBuf1 = 1;
    break;

   case 1:
    dcmotor_test_M->Timing.rtmDbBufReadBuf1 = 0;
    break;

   default:
    dcmotor_test_M->Timing.rtmDbBufReadBuf1 =
      dcmotor_test_M->Timing.rtmDbBufLastBufWr1;
    break;
  }

  dcmotor_test_M->Timing.clockTick1 = dcmotor_test_M->
    Timing.rtmDbBufClockTick1[dcmotor_test_M->Timing.rtmDbBufReadBuf1];
  dcmotor_test_M->Timing.rtmDbBufReadBuf1 = 0xFF;

  /* SystemInitialize for Outport: '<S1>/Out1' incorporates:
   *  Delay: '<S1>/Delay'
   *  Logic: '<S1>/NOT'
   */
  dcmotor_test_DW.Delay_DSTATE = dcmotor_test_P.Out1_Y0;

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(2), &MW_ISR_2, FALLING);

  /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  dcmotor_test_DW.obj.matlabCodegenIsDeleted = false;
  dcmotor_test_DW.obj.SampleTime = dcmotor_test_P.AnalogInput_SampleTime;
  dcmotor_test_DW.obj.isInitialized = 1L;
  dcmotor_test_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(62UL);
  dcmotor_test_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM' */
  dcmotor_test_DW.obj_b.matlabCodegenIsDeleted = false;
  dcmotor_test_DW.obj_b.isInitialized = 1L;
  dcmotor_test_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
  dcmotor_test_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  dcmotor_test_DW.obj_m.matlabCodegenIsDeleted = false;
  dcmotor_test_DW.obj_m.isInitialized = 1L;
  digitalIOSetup(13, 1);
  dcmotor_test_DW.obj_m.isSetupComplete = true;
}

/* Model terminate function */
void dcmotor_test_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!dcmotor_test_DW.obj.matlabCodegenIsDeleted) {
    dcmotor_test_DW.obj.matlabCodegenIsDeleted = true;
    if ((dcmotor_test_DW.obj.isInitialized == 1L) &&
        dcmotor_test_DW.obj.isSetupComplete) {
      dcmotor_test_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(62UL);
      MW_AnalogIn_Close(dcmotor_test_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!dcmotor_test_DW.obj_b.matlabCodegenIsDeleted) {
    dcmotor_test_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((dcmotor_test_DW.obj_b.isInitialized == 1L) &&
        dcmotor_test_DW.obj_b.isSetupComplete) {
      dcmotor_test_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(dcmotor_test_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      dcmotor_test_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(dcmotor_test_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!dcmotor_test_DW.obj_m.matlabCodegenIsDeleted) {
    dcmotor_test_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
