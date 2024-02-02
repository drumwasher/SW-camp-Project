/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Feb  2 11:07:58 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "rtwtypes.h"
#include "untitled_private.h"

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Model step function */
void untitled_step(void)
{
  boolean_T c_value;

  /* MATLABSystem: '<Root>/Digital Input' */
  if (untitled_DW.obj.SampleTime != untitled_P.DigitalInput_SampleTime) {
    untitled_DW.obj.SampleTime = untitled_P.DigitalInput_SampleTime;
  }

  c_value = readDigitalPin(24);

  /* Logic: '<Root>/NOT' incorporates:
   *  MATLABSystem: '<Root>/Digital Input'
   * */
  untitled_B.NOT = !c_value;

  /* MATLABSystem: '<Root>/Digital Output' */
  writeDigitalPin(22, (uint8_T)untitled_B.NOT);

  {                                    /* Sample time: [0.1s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled_M->Timing.taskTime0 =
    ((time_T)(++untitled_M->Timing.clockTick0)) * untitled_M->Timing.stepSize0;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(untitled_M, -1);
  untitled_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (2460128023U);
  untitled_M->Sizes.checksums[1] = (335599902U);
  untitled_M->Sizes.checksums[2] = (3410095891U);
  untitled_M->Sizes.checksums[3] = (1984578105U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  /* Start for MATLABSystem: '<Root>/Digital Input' */
  untitled_DW.obj.matlabCodegenIsDeleted = false;
  untitled_DW.obj.SampleTime = untitled_P.DigitalInput_SampleTime;
  untitled_DW.obj.isInitialized = 1L;
  digitalIOSetup(24, 2.0);
  untitled_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  untitled_DW.obj_h.matlabCodegenIsDeleted = false;
  untitled_DW.obj_h.isInitialized = 1L;
  digitalIOSetup(22, 1);
  untitled_DW.obj_h.isSetupComplete = true;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!untitled_DW.obj_h.matlabCodegenIsDeleted) {
    untitled_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
