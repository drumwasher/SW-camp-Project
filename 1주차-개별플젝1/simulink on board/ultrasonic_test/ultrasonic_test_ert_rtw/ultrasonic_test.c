/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ultrasonic_test.c
 *
 * Code generated for Simulink model 'ultrasonic_test'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Feb  1 10:31:57 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ultrasonic_test.h"
#include "rtwtypes.h"
#include "ultrasonic_test_private.h"

/* Block signals (default storage) */
B_ultrasonic_test_T ultrasonic_test_B;

/* Block states (default storage) */
DW_ultrasonic_test_T ultrasonic_test_DW;

/* Real-time model */
static RT_MODEL_ultrasonic_test_T ultrasonic_test_M_;
RT_MODEL_ultrasonic_test_T *const ultrasonic_test_M = &ultrasonic_test_M_;

/* Model step function */
void ultrasonic_test_step(void)
{
  uint32_T duration;

  /* MATLABSystem: '<Root>/Ultrasonic Sensor' */
  if (ultrasonic_test_DW.obj.TunablePropsChanged) {
    ultrasonic_test_DW.obj.TunablePropsChanged = false;
  }

  MW_UltrasonicRead(&duration, 1, 50, 51, 10);

  /* Gain: '<Root>/Gain' incorporates:
   *  MATLABSystem: '<Root>/Ultrasonic Sensor'
   * */
  ultrasonic_test_B.Gain = (real_T)duration * 0.000343 / 2.0 *
    ultrasonic_test_P.Gain_Gain;

  {                                    /* Sample time: [0.1s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ultrasonic_test_M->Timing.taskTime0 =
    ((time_T)(++ultrasonic_test_M->Timing.clockTick0)) *
    ultrasonic_test_M->Timing.stepSize0;
}

/* Model initialize function */
void ultrasonic_test_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(ultrasonic_test_M, -1);
  ultrasonic_test_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  ultrasonic_test_M->Sizes.checksums[0] = (624426353U);
  ultrasonic_test_M->Sizes.checksums[1] = (1897580098U);
  ultrasonic_test_M->Sizes.checksums[2] = (1663470960U);
  ultrasonic_test_M->Sizes.checksums[3] = (3229362531U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    ultrasonic_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ultrasonic_test_M->extModeInfo,
      &ultrasonic_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ultrasonic_test_M->extModeInfo,
                        ultrasonic_test_M->Sizes.checksums);
    rteiSetTPtr(ultrasonic_test_M->extModeInfo, rtmGetTPtr(ultrasonic_test_M));
  }

  /* Start for MATLABSystem: '<Root>/Ultrasonic Sensor' */
  ultrasonic_test_DW.obj.isInitialized = 1L;
  MW_UltrasonicSetup(50, 51);
  ultrasonic_test_DW.obj.TunablePropsChanged = false;
}

/* Model terminate function */
void ultrasonic_test_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
