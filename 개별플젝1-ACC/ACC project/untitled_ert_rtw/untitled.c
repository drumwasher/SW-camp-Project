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
 * C/C++ source code generated on : Mon Feb  5 09:34:41 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "rtwtypes.h"
#include "untitled_private.h"
#include <math.h>
#include "rt_nonfinite.h"

/* Named constants for Chart: '<S2>/Chart' */
#define untitled_IN_AccOff             ((uint8_T)1U)
#define untitled_IN_AccOn              ((uint8_T)2U)
#define untitled_IN_AccStandby         ((uint8_T)3U)

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;
static void rate_scheduler(void);

/* Callback for Hardware Interrupt Block: '<Root>/External Interrupt5' */
void MW_ISR_20(void)
{
  /* Call the system: <S2>/Function-Call Subsystem4 */
  {
    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt5' */

    /* Output and update for function-call system: '<S2>/Function-Call Subsystem4' */

    /* Sum: '<S9>/Add' incorporates:
     *  Constant: '<S9>/Constant'
     *  Delay: '<S9>/Delay'
     */
    untitled_DW.Delay_DSTATE_m = untitled_P.Constant_Value -
      untitled_DW.Delay_DSTATE_m;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt5' */

    /* RateTransition generated from: '<S2>/Function-Call Subsystem4' incorporates:
     *  Delay: '<S9>/Delay'
     */
    switch (untitled_DW.TmpRTBAtFunctionCallSubsystem_o) {
     case 0:
      untitled_DW.TmpRTBAtFunctionCallSubsystem_f = 1;
      break;

     case 1:
      untitled_DW.TmpRTBAtFunctionCallSubsystem_f = 0;
      break;

     default:
      untitled_DW.TmpRTBAtFunctionCallSubsystem_f = (int8_T)
        (untitled_DW.TmpRTBAtFunctionCallSubsystem_c == 0);
      break;
    }

    if (untitled_DW.TmpRTBAtFunctionCallSubsystem_f != 0) {
      untitled_DW.TmpRTBAtFunctionCallSubsystem_e = untitled_DW.Delay_DSTATE_m;
    } else {
      untitled_DW.TmpRTBAtFunctionCallSubsystem4O = untitled_DW.Delay_DSTATE_m;
    }

    untitled_DW.TmpRTBAtFunctionCallSubsystem_c =
      untitled_DW.TmpRTBAtFunctionCallSubsystem_f;
    untitled_DW.TmpRTBAtFunctionCallSubsystem_f = -1;

    /* End of RateTransition generated from: '<S2>/Function-Call Subsystem4' */
  }
}

/* Callback for Hardware Interrupt Block: '<Root>/External Interrupt6' */
void MW_ISR_21(void)
{
  /* Call the system: <S2>/Function-Call Subsystem6 */
  {
    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt6' */

    /* Output and update for function-call system: '<S2>/Function-Call Subsystem6' */

    /* Sum: '<S10>/Add' incorporates:
     *  Constant: '<S10>/Constant'
     *  Delay: '<S10>/Delay'
     */
    untitled_DW.Delay_DSTATE = untitled_P.Constant_Value_m -
      untitled_DW.Delay_DSTATE;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt6' */

    /* RateTransition generated from: '<S2>/Function-Call Subsystem6' incorporates:
     *  Delay: '<S10>/Delay'
     */
    switch (untitled_DW.TmpRTBAtFunctionCallSubsyste_ff) {
     case 0:
      untitled_DW.TmpRTBAtFunctionCallSubsystem_n = 1;
      break;

     case 1:
      untitled_DW.TmpRTBAtFunctionCallSubsystem_n = 0;
      break;

     default:
      untitled_DW.TmpRTBAtFunctionCallSubsystem_n = (int8_T)
        (untitled_DW.TmpRTBAtFunctionCallSubsystem_k == 0);
      break;
    }

    if (untitled_DW.TmpRTBAtFunctionCallSubsystem_n != 0) {
      untitled_DW.TmpRTBAtFunctionCallSubsystem_a = untitled_DW.Delay_DSTATE;
    } else {
      untitled_DW.TmpRTBAtFunctionCallSubsystem6O = untitled_DW.Delay_DSTATE;
    }

    untitled_DW.TmpRTBAtFunctionCallSubsystem_k =
      untitled_DW.TmpRTBAtFunctionCallSubsystem_n;
    untitled_DW.TmpRTBAtFunctionCallSubsystem_n = -1;

    /* End of RateTransition generated from: '<S2>/Function-Call Subsystem6' */
  }
}

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (untitled_M->Timing.TaskCounters.TID[1])++;
  if ((untitled_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    untitled_M->Timing.TaskCounters.TID[1] = 0;
  }

  (untitled_M->Timing.TaskCounters.TID[2])++;
  if ((untitled_M->Timing.TaskCounters.TID[2]) > 19) {/* Sample time: [0.2s, 0.0s] */
    untitled_M->Timing.TaskCounters.TID[2] = 0;
  }

  (untitled_M->Timing.TaskCounters.TID[3])++;
  if ((untitled_M->Timing.TaskCounters.TID[3]) > 99) {/* Sample time: [1.0s, 0.0s] */
    untitled_M->Timing.TaskCounters.TID[3] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S4>/If Action Subsystem'
 *    '<S4>/If Action Subsystem1'
 *    '<S4>/If Action Subsystem2'
 */
void untitled_IfActionSubsystem(real_T rtu_In1, real_T rtu_In2, real_T *rty_Out1,
  real_T *rty_Out2)
{
  /* SignalConversion generated from: '<S15>/In1' */
  *rty_Out1 = rtu_In1;

  /* SignalConversion generated from: '<S15>/In2' */
  *rty_Out2 = rtu_In2;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void untitled_step(void)
{
  real_T rtb_Gain;
  real_T rtb_Merge;
  real_T rtb_TmpRTBAtFunctionCallSubsy_f;
  uint32_T duration;
  int16_T rtb_state;
  uint16_T b_varargout_1;
  uint8_T tmp;
  if (untitled_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<Root>/Ultrasonic Sensor' */
    if (untitled_DW.obj_m.TunablePropsChanged) {
      untitled_DW.obj_m.TunablePropsChanged = false;
    }

    MW_UltrasonicRead(&duration, 1, 50, 51, 10);

    /* Gain: '<S4>/Gain' incorporates:
     *  MATLABSystem: '<Root>/Ultrasonic Sensor'
     * */
    rtb_Gain = (real_T)duration * 0.000343 / 2.0 * untitled_P.Gain_Gain;
  }

  if (untitled_M->Timing.TaskCounters.TID[2] == 0) {
    /* DiscretePulseGenerator: '<S4>/Pulse Generator' */
    untitled_B.PulseGenerator = (untitled_DW.clockTickCounter <
      untitled_P.PulseGenerator_Duty) && (untitled_DW.clockTickCounter >= 0L) ?
      untitled_P.PulseGenerator_Amp : 0.0;

    /* DiscretePulseGenerator: '<S4>/Pulse Generator' */
    if (untitled_DW.clockTickCounter >= untitled_P.PulseGenerator_Period - 1.0)
    {
      untitled_DW.clockTickCounter = 0L;
    } else {
      untitled_DW.clockTickCounter++;
    }
  }

  if (untitled_M->Timing.TaskCounters.TID[1] == 0) {
    /* If: '<S4>/If' incorporates:
     *  Constant: '<S4>/Constant'
     *  Constant: '<S4>/Constant1'
     *  Constant: '<S4>/Constant2'
     *  Constant: '<S4>/Constant3'
     */
    if (rtb_Gain < 10.0) {
      /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      untitled_IfActionSubsystem(untitled_P.Constant_Value_mh,
        untitled_P.Constant2_Value, &untitled_B.Merge, &rtb_Merge);

      /* End of Outputs for SubSystem: '<S4>/If Action Subsystem' */
    } else if (rtb_Gain < 50.0) {
      /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S16>/Action Port'
       */
      untitled_IfActionSubsystem(untitled_B.PulseGenerator,
        untitled_P.Constant3_Value, &untitled_B.Merge, &rtb_Merge);

      /* End of Outputs for SubSystem: '<S4>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S17>/Action Port'
       */
      untitled_IfActionSubsystem(untitled_P.Constant1_Value, 0.0,
        &untitled_B.Merge, &rtb_Merge);

      /* End of Outputs for SubSystem: '<S4>/If Action Subsystem2' */
    }

    /* End of If: '<S4>/If' */
  }

  /* RateTransition generated from: '<S2>/Function-Call Subsystem4' */
  switch (untitled_DW.TmpRTBAtFunctionCallSubsystem_f) {
   case 0:
    untitled_DW.TmpRTBAtFunctionCallSubsystem_o = 1;
    break;

   case 1:
    untitled_DW.TmpRTBAtFunctionCallSubsystem_o = 0;
    break;

   default:
    untitled_DW.TmpRTBAtFunctionCallSubsystem_o =
      untitled_DW.TmpRTBAtFunctionCallSubsystem_c;
    break;
  }

  if (untitled_DW.TmpRTBAtFunctionCallSubsystem_o != 0) {
    rtb_Gain = untitled_DW.TmpRTBAtFunctionCallSubsystem_e;
  } else {
    rtb_Gain = untitled_DW.TmpRTBAtFunctionCallSubsystem4O;
  }

  untitled_DW.TmpRTBAtFunctionCallSubsystem_o = -1;

  /* End of RateTransition generated from: '<S2>/Function-Call Subsystem4' */
  /* RateTransition generated from: '<S2>/Function-Call Subsystem6' */
  switch (untitled_DW.TmpRTBAtFunctionCallSubsystem_n) {
   case 0:
    untitled_DW.TmpRTBAtFunctionCallSubsyste_ff = 1;
    break;

   case 1:
    untitled_DW.TmpRTBAtFunctionCallSubsyste_ff = 0;
    break;

   default:
    untitled_DW.TmpRTBAtFunctionCallSubsyste_ff =
      untitled_DW.TmpRTBAtFunctionCallSubsystem_k;
    break;
  }

  if (untitled_DW.TmpRTBAtFunctionCallSubsyste_ff != 0) {
    rtb_TmpRTBAtFunctionCallSubsy_f =
      untitled_DW.TmpRTBAtFunctionCallSubsystem_a;
  } else {
    rtb_TmpRTBAtFunctionCallSubsy_f =
      untitled_DW.TmpRTBAtFunctionCallSubsystem6O;
  }

  untitled_DW.TmpRTBAtFunctionCallSubsyste_ff = -1;

  /* End of RateTransition generated from: '<S2>/Function-Call Subsystem6' */

  /* Chart: '<S2>/Chart' */
  if (untitled_DW.is_active_c3_untitled == 0U) {
    untitled_DW.is_active_c3_untitled = 1U;
    untitled_DW.is_c3_untitled = untitled_IN_AccOff;
    untitled_DW.v1 = rtb_Gain;
    untitled_DW.v2 = rtb_TmpRTBAtFunctionCallSubsy_f;
    rtb_state = 0;

    /* Switch: '<S4>/Switch' incorporates:
     *  Constant: '<S4>/Constant1'
     */
    rtb_Gain = untitled_P.Constant1_Value;
  } else {
    switch (untitled_DW.is_c3_untitled) {
     case untitled_IN_AccOff:
      if (untitled_DW.v1 != rtb_Gain) {
        untitled_DW.is_c3_untitled = untitled_IN_AccStandby;
        untitled_DW.v1 = rtb_Gain;
        untitled_DW.v2 = rtb_TmpRTBAtFunctionCallSubsy_f;
        rtb_state = 1;

        /* Switch: '<S4>/Switch' */
        rtb_Gain = untitled_B.Merge;
      } else {
        untitled_DW.v1 = rtb_Gain;
        untitled_DW.v2 = rtb_TmpRTBAtFunctionCallSubsy_f;
        rtb_state = 0;

        /* Switch: '<S4>/Switch' incorporates:
         *  Constant: '<S4>/Constant1'
         */
        rtb_Gain = untitled_P.Constant1_Value;
      }
      break;

     case untitled_IN_AccOn:
      if ((untitled_DW.v1 != rtb_Gain) || (untitled_DW.v2 !=
           rtb_TmpRTBAtFunctionCallSubsy_f)) {
        untitled_DW.is_c3_untitled = untitled_IN_AccOff;
        untitled_DW.v1 = rtb_Gain;
        untitled_DW.v2 = rtb_TmpRTBAtFunctionCallSubsy_f;
        rtb_state = 0;

        /* Switch: '<S4>/Switch' incorporates:
         *  Constant: '<S4>/Constant1'
         */
        rtb_Gain = untitled_P.Constant1_Value;
      } else {
        untitled_DW.v1 = rtb_Gain;
        untitled_DW.v2 = rtb_TmpRTBAtFunctionCallSubsy_f;
        rtb_state = 2;

        /* Switch: '<S4>/Switch' */
        rtb_Gain = untitled_B.Merge;
      }
      break;

     default:
      /* case IN_AccStandby: */
      if (untitled_DW.v2 != rtb_TmpRTBAtFunctionCallSubsy_f) {
        untitled_DW.is_c3_untitled = untitled_IN_AccOff;
        untitled_DW.v1 = rtb_Gain;
        untitled_DW.v2 = rtb_TmpRTBAtFunctionCallSubsy_f;
        rtb_state = 0;

        /* Switch: '<S4>/Switch' incorporates:
         *  Constant: '<S4>/Constant1'
         */
        rtb_Gain = untitled_P.Constant1_Value;
      } else {
        if (untitled_DW.v1 != rtb_Gain) {
          untitled_DW.is_c3_untitled = untitled_IN_AccOn;
          untitled_DW.v1 = rtb_Gain;
          untitled_DW.v2 = rtb_TmpRTBAtFunctionCallSubsy_f;
          rtb_state = 2;
        } else {
          untitled_DW.v1 = rtb_Gain;
          untitled_DW.v2 = rtb_TmpRTBAtFunctionCallSubsy_f;
          rtb_state = 1;
        }

        /* Switch: '<S4>/Switch' */
        rtb_Gain = untitled_B.Merge;
      }
      break;
    }
  }

  /* End of Chart: '<S2>/Chart' */

  /* MATLABSystem: '<Root>/Digital Output' incorporates:
   *  Switch: '<S4>/Switch'
   */
  rtb_Gain = rt_roundd_snf(rtb_Gain);
  if (rtb_Gain < 256.0) {
    if (rtb_Gain >= 0.0) {
      tmp = (uint8_T)rtb_Gain;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(23, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output' */
  if (untitled_M->Timing.TaskCounters.TID[2] == 0) {
    /* DiscretePulseGenerator: '<S2>/Pulse Generator6' */
    untitled_B.PulseGenerator6 = (untitled_DW.clockTickCounter_g <
      untitled_P.PulseGenerator6_Duty) && (untitled_DW.clockTickCounter_g >= 0L)
      ? untitled_P.PulseGenerator6_Amp : 0.0;

    /* DiscretePulseGenerator: '<S2>/Pulse Generator6' */
    if (untitled_DW.clockTickCounter_g >= untitled_P.PulseGenerator6_Period -
        1.0) {
      untitled_DW.clockTickCounter_g = 0L;
    } else {
      untitled_DW.clockTickCounter_g++;
    }
  }

  if (untitled_M->Timing.TaskCounters.TID[3] == 0) {
    /* DiscretePulseGenerator: '<S2>/Pulse Generator7' */
    untitled_B.PulseGenerator7 = (untitled_DW.clockTickCounter_k <
      untitled_P.PulseGenerator7_Duty) && (untitled_DW.clockTickCounter_k >= 0L)
      ? untitled_P.PulseGenerator7_Amp : 0.0;

    /* DiscretePulseGenerator: '<S2>/Pulse Generator7' */
    if (untitled_DW.clockTickCounter_k >= untitled_P.PulseGenerator7_Period -
        1.0) {
      untitled_DW.clockTickCounter_k = 0L;
    } else {
      untitled_DW.clockTickCounter_k++;
    }
  }

  /* MATLABSystem: '<Root>/Analog Input' */
  if (untitled_DW.obj.SampleTime != untitled_P.AnalogInput_SampleTime) {
    untitled_DW.obj.SampleTime = untitled_P.AnalogInput_SampleTime;
  }

  untitled_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle
    (62UL);
  MW_AnalogInSingle_ReadResult
    (untitled_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     MW_ANALOGIN_UINT16);

  /* Gain: '<S3>/Gain' incorporates:
   *  MATLABSystem: '<Root>/Analog Input'
   * */
  duration = (uint32_T)untitled_P.Gain_Gain_j * b_varargout_1;

  /* Chart: '<S3>/Chart' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  Gain: '<S3>/Gain'
   */
  if (untitled_DW.is_active_c1_untitled == 0U) {
    untitled_DW.is_active_c1_untitled = 1U;
    untitled_DW.is_c1_untitled = untitled_IN_AccOff;
    untitled_DW.a = (real_T)duration * 7.62939453125E-6;
    rtb_Gain = 0.0;
  } else {
    switch (untitled_DW.is_c1_untitled) {
     case untitled_IN_AccOff:
      if (rtb_state == 1) {
        untitled_DW.is_c1_untitled = untitled_IN_AccStandby;
        rtb_Gain = untitled_DW.a;
      } else {
        untitled_DW.a = (real_T)duration * 7.62939453125E-6;
        rtb_Gain = 0.0;
      }
      break;

     case untitled_IN_AccOn:
      if (rtb_state == 0) {
        untitled_DW.is_c1_untitled = untitled_IN_AccOff;
        untitled_DW.a = (real_T)duration * 7.62939453125E-6;
        rtb_Gain = 0.0;
      } else {
        rtb_Gain = (real_T)duration * 7.62939453125E-6;
      }
      break;

     default:
      /* case IN_AccStandby: */
      if (rtb_state == 2) {
        untitled_DW.is_c1_untitled = untitled_IN_AccOn;
        rtb_Gain = (real_T)duration * 7.62939453125E-6;
      } else if (rtb_state == 0) {
        untitled_DW.is_c1_untitled = untitled_IN_AccOff;
        untitled_DW.a = (real_T)duration * 7.62939453125E-6;
        rtb_Gain = 0.0;
      } else {
        rtb_Gain = untitled_DW.a;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/Chart' */
  if (untitled_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<Root>/PWM' */
    untitled_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

    /* If: '<S3>/If' incorporates:
     *  Constant: '<S3>/Constant'
     *  Constant: '<S3>/Constant1'
     *  DataTypeConversion: '<S3>/Data Type Conversion1'
     *  Product: '<S3>/Divide'
     */
    if (rtb_Merge == 1.0) {
      rtb_Gain /= untitled_P.Constant1_Value_f;
    } else if (rtb_Merge == 2.0) {
      rtb_Gain = untitled_P.Constant_Value_b;
    }

    rtb_Gain = floor(rtb_Gain);

    /* End of If: '<S3>/If' */

    /* DataTypeConversion: '<S3>/Data Type Conversion1' */
    if (rtIsNaN(rtb_Gain) || rtIsInf(rtb_Gain)) {
      rtb_Gain = 0.0;
    } else {
      rtb_Gain = fmod(rtb_Gain, 256.0);
    }

    /* MATLABSystem: '<Root>/PWM' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion1'
     */
    MW_PWM_SetDutyCycle(untitled_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, (real_T)
                        (rtb_Gain < 0.0 ? (int16_T)(uint8_T)-(int8_T)(uint8_T)
                         -rtb_Gain : (int16_T)(uint8_T)rtb_Gain));
  }

  /* If: '<S2>/If5' incorporates:
   *  Constant: '<S6>/Constant'
   *  MATLABSystem: '<Root>/Digital Output4'
   *  SignalConversion generated from: '<S5>/In1'
   *  SignalConversion generated from: '<S7>/In1'
   */
  if (rtb_state == 1) {
    /* Outputs for IfAction SubSystem: '<S2>/ACC standby2' incorporates:
     *  ActionPort: '<S7>/ACC standby'
     */
    rtb_Gain = untitled_B.PulseGenerator6;

    /* End of Outputs for SubSystem: '<S2>/ACC standby2' */
  } else if (rtb_state == 2) {
    rtb_Gain = untitled_P.Constant_Value_e;
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/ACC off5' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    rtb_Gain = untitled_B.PulseGenerator7;

    /* End of Outputs for SubSystem: '<S2>/ACC off5' */
  }

  rtb_Gain = rt_roundd_snf(rtb_Gain);

  /* End of If: '<S2>/If5' */

  /* MATLABSystem: '<Root>/Digital Output4' */
  if (rtb_Gain < 256.0) {
    if (rtb_Gain >= 0.0) {
      tmp = (uint8_T)rtb_Gain;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(22, tmp);
  rate_scheduler();
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* InitializeConditions for RateTransition generated from: '<S2>/Function-Call Subsystem4' */
  untitled_DW.TmpRTBAtFunctionCallSubsystem4O =
    untitled_P.TmpRTBAtFunctionCallSubsystem4O;
  untitled_DW.TmpRTBAtFunctionCallSubsystem_f = -1;
  untitled_DW.TmpRTBAtFunctionCallSubsystem_o = -1;

  /* InitializeConditions for RateTransition generated from: '<S2>/Function-Call Subsystem6' */
  untitled_DW.TmpRTBAtFunctionCallSubsystem6O =
    untitled_P.TmpRTBAtFunctionCallSubsystem6O;
  untitled_DW.TmpRTBAtFunctionCallSubsystem_n = -1;
  untitled_DW.TmpRTBAtFunctionCallSubsyste_ff = -1;

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt5' incorporates:
   *  SubSystem: '<S2>/Function-Call Subsystem4'
   */

  /* System initialize for function-call system: '<S2>/Function-Call Subsystem4' */

  /* SystemInitialize for Outport: '<S9>/sw1' incorporates:
   *  Delay: '<S9>/Delay'
   *  Sum: '<S9>/Add'
   */
  untitled_DW.Delay_DSTATE_m = untitled_P.sw1_Y0;

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(20), &MW_ISR_20, FALLING);

  /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt5' */

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt6' incorporates:
   *  SubSystem: '<S2>/Function-Call Subsystem6'
   */

  /* System initialize for function-call system: '<S2>/Function-Call Subsystem6' */

  /* SystemInitialize for Outport: '<S10>/sw2' incorporates:
   *  Delay: '<S10>/Delay'
   *  Sum: '<S10>/Add'
   */
  untitled_DW.Delay_DSTATE = untitled_P.sw2_Y0;

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(21), &MW_ISR_21, FALLING);

  /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt6' */

  /* Start for MATLABSystem: '<Root>/Ultrasonic Sensor' */
  untitled_DW.obj_m.isInitialized = 1L;
  MW_UltrasonicSetup(50, 51);
  untitled_DW.obj_m.TunablePropsChanged = false;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  untitled_DW.obj_g.matlabCodegenIsDeleted = false;
  untitled_DW.obj_g.isInitialized = 1L;
  digitalIOSetup(23, 1);
  untitled_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  untitled_DW.obj.matlabCodegenIsDeleted = false;
  untitled_DW.obj.SampleTime = untitled_P.AnalogInput_SampleTime;
  untitled_DW.obj.isInitialized = 1L;
  untitled_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open
    (62UL);
  untitled_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM' */
  untitled_DW.obj_b.matlabCodegenIsDeleted = false;
  untitled_DW.obj_b.isInitialized = 1L;
  untitled_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
  untitled_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output4' */
  untitled_DW.obj_h.matlabCodegenIsDeleted = false;
  untitled_DW.obj_h.isInitialized = 1L;
  digitalIOSetup(22, 1);
  untitled_DW.obj_h.isSetupComplete = true;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!untitled_DW.obj_g.matlabCodegenIsDeleted) {
    untitled_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj.isInitialized == 1L) && untitled_DW.obj.isSetupComplete)
    {
      untitled_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(62UL);
      MW_AnalogIn_Close(untitled_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!untitled_DW.obj_b.matlabCodegenIsDeleted) {
    untitled_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_b.isInitialized == 1L) &&
        untitled_DW.obj_b.isSetupComplete) {
      untitled_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(untitled_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      untitled_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(untitled_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output4' */
  if (!untitled_DW.obj_h.matlabCodegenIsDeleted) {
    untitled_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output4' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
