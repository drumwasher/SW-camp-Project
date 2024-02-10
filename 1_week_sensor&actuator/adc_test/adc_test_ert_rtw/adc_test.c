/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: adc_test.c
 *
 * Code generated for Simulink model 'adc_test'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Feb  1 09:17:03 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "adc_test.h"
#include "adc_test_private.h"

/* Block signals (default storage) */
B_adc_test_T adc_test_B;

/* Block states (default storage) */
DW_adc_test_T adc_test_DW;

/* Real-time model */
static RT_MODEL_adc_test_T adc_test_M_;
RT_MODEL_adc_test_T *const adc_test_M = &adc_test_M_;

/* Model step function */
void adc_test_step(void)
{
  /* MATLABSystem: '<Root>/Analog Input' */
  if (adc_test_DW.obj_p.SampleTime != adc_test_P.AnalogInput_SampleTime) {
    adc_test_DW.obj_p.SampleTime = adc_test_P.AnalogInput_SampleTime;
  }

  adc_test_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle
    (54UL);

  /* MATLABSystem: '<Root>/Analog Input' */
  MW_AnalogInSingle_ReadResult
    (adc_test_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &adc_test_B.AnalogInput, MW_ANALOGIN_UINT16);

  /* MATLABSystem: '<Root>/Analog Input1' */
  if (adc_test_DW.obj.SampleTime != adc_test_P.AnalogInput1_SampleTime) {
    adc_test_DW.obj.SampleTime = adc_test_P.AnalogInput1_SampleTime;
  }

  adc_test_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle
    (55UL);

  /* MATLABSystem: '<Root>/Analog Input1' */
  MW_AnalogInSingle_ReadResult
    (adc_test_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &adc_test_B.AnalogInput1, MW_ANALOGIN_UINT16);

  {                                    /* Sample time: [0.2s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  adc_test_M->Timing.taskTime0 =
    ((time_T)(++adc_test_M->Timing.clockTick0)) * adc_test_M->Timing.stepSize0;
}

/* Model initialize function */
void adc_test_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(adc_test_M, -1);
  adc_test_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  adc_test_M->Sizes.checksums[0] = (859580678U);
  adc_test_M->Sizes.checksums[1] = (1700836716U);
  adc_test_M->Sizes.checksums[2] = (3496529933U);
  adc_test_M->Sizes.checksums[3] = (4052231240U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    adc_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(adc_test_M->extModeInfo,
      &adc_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(adc_test_M->extModeInfo, adc_test_M->Sizes.checksums);
    rteiSetTPtr(adc_test_M->extModeInfo, rtmGetTPtr(adc_test_M));
  }

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  adc_test_DW.obj_p.matlabCodegenIsDeleted = false;
  adc_test_DW.obj_p.SampleTime = adc_test_P.AnalogInput_SampleTime;
  adc_test_DW.obj_p.isInitialized = 1L;
  adc_test_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(54UL);
  adc_test_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input1' */
  adc_test_DW.obj.matlabCodegenIsDeleted = false;
  adc_test_DW.obj.SampleTime = adc_test_P.AnalogInput1_SampleTime;
  adc_test_DW.obj.isInitialized = 1L;
  adc_test_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open
    (55UL);
  adc_test_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void adc_test_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!adc_test_DW.obj_p.matlabCodegenIsDeleted) {
    adc_test_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((adc_test_DW.obj_p.isInitialized == 1L) &&
        adc_test_DW.obj_p.isSetupComplete) {
      adc_test_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(54UL);
      MW_AnalogIn_Close(adc_test_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */
  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  if (!adc_test_DW.obj.matlabCodegenIsDeleted) {
    adc_test_DW.obj.matlabCodegenIsDeleted = true;
    if ((adc_test_DW.obj.isInitialized == 1L) && adc_test_DW.obj.isSetupComplete)
    {
      adc_test_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(55UL);
      MW_AnalogIn_Close(adc_test_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
