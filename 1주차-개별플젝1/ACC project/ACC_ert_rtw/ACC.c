/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ACC.c
 *
 * Code generated for Simulink model 'ACC'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Feb  3 21:57:23 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ACC.h"
#include "rtwtypes.h"
#include "ACC_private.h"
#include <math.h>
#include "rt_nonfinite.h"

/* Named constants for Chart: '<S2>/Chart' */
#define ACC_IN_AccOff                  ((uint8_T)1U)
#define ACC_IN_AccOn                   ((uint8_T)2U)
#define ACC_IN_AccStandby              ((uint8_T)3U)

/* Block signals (default storage) */
B_ACC_T ACC_B;

/* Block states (default storage) */
DW_ACC_T ACC_DW;

/* Real-time model */
static RT_MODEL_ACC_T ACC_M_;
RT_MODEL_ACC_T *const ACC_M = &ACC_M_;
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
    ACC_DW.Delay_DSTATE_l = ACC_P.Constant_Value - ACC_DW.Delay_DSTATE_l;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt5' */

    /* RateTransition generated from: '<S2>/Function-Call Subsystem4' incorporates:
     *  Delay: '<S9>/Delay'
     */
    switch (ACC_DW.TmpRTBAtFunctionCallSubsystem_o) {
     case 0:
      ACC_DW.TmpRTBAtFunctionCallSubsystem_f = 1;
      break;

     case 1:
      ACC_DW.TmpRTBAtFunctionCallSubsystem_f = 0;
      break;

     default:
      ACC_DW.TmpRTBAtFunctionCallSubsystem_f = (int8_T)
        (ACC_DW.TmpRTBAtFunctionCallSubsystem_c == 0);
      break;
    }

    if (ACC_DW.TmpRTBAtFunctionCallSubsystem_f != 0) {
      ACC_DW.TmpRTBAtFunctionCallSubsystem_e = ACC_DW.Delay_DSTATE_l;
    } else {
      ACC_DW.TmpRTBAtFunctionCallSubsystem4O = ACC_DW.Delay_DSTATE_l;
    }

    ACC_DW.TmpRTBAtFunctionCallSubsystem_c =
      ACC_DW.TmpRTBAtFunctionCallSubsystem_f;
    ACC_DW.TmpRTBAtFunctionCallSubsystem_f = -1;

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
    ACC_DW.Delay_DSTATE = ACC_P.Constant_Value_g - ACC_DW.Delay_DSTATE;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt6' */

    /* RateTransition generated from: '<S2>/Function-Call Subsystem6' incorporates:
     *  Delay: '<S10>/Delay'
     */
    switch (ACC_DW.TmpRTBAtFunctionCallSubsyste_ff) {
     case 0:
      ACC_DW.TmpRTBAtFunctionCallSubsystem_n = 1;
      break;

     case 1:
      ACC_DW.TmpRTBAtFunctionCallSubsystem_n = 0;
      break;

     default:
      ACC_DW.TmpRTBAtFunctionCallSubsystem_n = (int8_T)
        (ACC_DW.TmpRTBAtFunctionCallSubsystem_k == 0);
      break;
    }

    if (ACC_DW.TmpRTBAtFunctionCallSubsystem_n != 0) {
      ACC_DW.TmpRTBAtFunctionCallSubsystem_a = ACC_DW.Delay_DSTATE;
    } else {
      ACC_DW.TmpRTBAtFunctionCallSubsystem6O = ACC_DW.Delay_DSTATE;
    }

    ACC_DW.TmpRTBAtFunctionCallSubsystem_k =
      ACC_DW.TmpRTBAtFunctionCallSubsystem_n;
    ACC_DW.TmpRTBAtFunctionCallSubsystem_n = -1;

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
  (ACC_M->Timing.TaskCounters.TID[1])++;
  if ((ACC_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    ACC_M->Timing.TaskCounters.TID[1] = 0;
  }

  (ACC_M->Timing.TaskCounters.TID[2])++;
  if ((ACC_M->Timing.TaskCounters.TID[2]) > 19) {/* Sample time: [0.2s, 0.0s] */
    ACC_M->Timing.TaskCounters.TID[2] = 0;
  }

  (ACC_M->Timing.TaskCounters.TID[3])++;
  if ((ACC_M->Timing.TaskCounters.TID[3]) > 99) {/* Sample time: [1.0s, 0.0s] */
    ACC_M->Timing.TaskCounters.TID[3] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S4>/If Action Subsystem'
 *    '<S4>/If Action Subsystem1'
 *    '<S4>/If Action Subsystem2'
 */
void ACC_IfActionSubsystem(real_T rtu_In1, real_T rtu_In2, real_T *rty_Out1,
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
void ACC_step(void)
{
  real_T rtb_Gain;
  real_T rtb_Merge;
  real_T rtb_TmpRTBAtFunctionCallSubsy_f;
  uint32_T duration;
  int16_T rtb_state;
  uint16_T b_varargout_1;
  uint8_T tmp;
  if (ACC_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<Root>/Ultrasonic Sensor' */
    if (ACC_DW.obj_ok.TunablePropsChanged) {
      ACC_DW.obj_ok.TunablePropsChanged = false;
    }

    MW_UltrasonicRead(&duration, 1, 50, 51, 10);

    /* Gain: '<S4>/Gain' incorporates:
     *  MATLABSystem: '<Root>/Ultrasonic Sensor'
     * */
    rtb_Gain = (real_T)duration * 0.000343 / 2.0 * ACC_P.Gain_Gain;
  }

  if (ACC_M->Timing.TaskCounters.TID[2] == 0) {
    /* DiscretePulseGenerator: '<S4>/Pulse Generator' */
    ACC_B.PulseGenerator = (ACC_DW.clockTickCounter < ACC_P.PulseGenerator_Duty)
      && (ACC_DW.clockTickCounter >= 0L) ? ACC_P.PulseGenerator_Amp : 0.0;

    /* DiscretePulseGenerator: '<S4>/Pulse Generator' */
    if (ACC_DW.clockTickCounter >= ACC_P.PulseGenerator_Period - 1.0) {
      ACC_DW.clockTickCounter = 0L;
    } else {
      ACC_DW.clockTickCounter++;
    }
  }

  if (ACC_M->Timing.TaskCounters.TID[1] == 0) {
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
      ACC_IfActionSubsystem(ACC_P.Constant_Value_h, ACC_P.Constant2_Value,
                            &ACC_B.Merge, &rtb_Merge);

      /* End of Outputs for SubSystem: '<S4>/If Action Subsystem' */
    } else if (rtb_Gain < 50.0) {
      /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S16>/Action Port'
       */
      ACC_IfActionSubsystem(ACC_B.PulseGenerator, ACC_P.Constant3_Value,
                            &ACC_B.Merge, &rtb_Merge);

      /* End of Outputs for SubSystem: '<S4>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S17>/Action Port'
       */
      ACC_IfActionSubsystem(ACC_P.Constant1_Value, 0.0, &ACC_B.Merge, &rtb_Merge);

      /* End of Outputs for SubSystem: '<S4>/If Action Subsystem2' */
    }

    /* End of If: '<S4>/If' */
  }

  /* RateTransition generated from: '<S2>/Function-Call Subsystem4' */
  switch (ACC_DW.TmpRTBAtFunctionCallSubsystem_f) {
   case 0:
    ACC_DW.TmpRTBAtFunctionCallSubsystem_o = 1;
    break;

   case 1:
    ACC_DW.TmpRTBAtFunctionCallSubsystem_o = 0;
    break;

   default:
    ACC_DW.TmpRTBAtFunctionCallSubsystem_o =
      ACC_DW.TmpRTBAtFunctionCallSubsystem_c;
    break;
  }

  if (ACC_DW.TmpRTBAtFunctionCallSubsystem_o != 0) {
    rtb_Gain = ACC_DW.TmpRTBAtFunctionCallSubsystem_e;
  } else {
    rtb_Gain = ACC_DW.TmpRTBAtFunctionCallSubsystem4O;
  }

  ACC_DW.TmpRTBAtFunctionCallSubsystem_o = -1;

  /* End of RateTransition generated from: '<S2>/Function-Call Subsystem4' */
  /* RateTransition generated from: '<S2>/Function-Call Subsystem6' */
  switch (ACC_DW.TmpRTBAtFunctionCallSubsystem_n) {
   case 0:
    ACC_DW.TmpRTBAtFunctionCallSubsyste_ff = 1;
    break;

   case 1:
    ACC_DW.TmpRTBAtFunctionCallSubsyste_ff = 0;
    break;

   default:
    ACC_DW.TmpRTBAtFunctionCallSubsyste_ff =
      ACC_DW.TmpRTBAtFunctionCallSubsystem_k;
    break;
  }

  if (ACC_DW.TmpRTBAtFunctionCallSubsyste_ff != 0) {
    rtb_TmpRTBAtFunctionCallSubsy_f = ACC_DW.TmpRTBAtFunctionCallSubsystem_a;
  } else {
    rtb_TmpRTBAtFunctionCallSubsy_f = ACC_DW.TmpRTBAtFunctionCallSubsystem6O;
  }

  ACC_DW.TmpRTBAtFunctionCallSubsyste_ff = -1;

  /* End of RateTransition generated from: '<S2>/Function-Call Subsystem6' */

  /* Chart: '<S2>/Chart' */
  if (ACC_DW.is_active_c3_ACC == 0U) {
    ACC_DW.is_active_c3_ACC = 1U;
    ACC_DW.is_c3_ACC = ACC_IN_AccOff;
    ACC_DW.v1 = rtb_Gain;
    ACC_DW.v2 = rtb_TmpRTBAtFunctionCallSubsy_f;
    rtb_state = 0;

    /* Switch: '<S4>/Switch' incorporates:
     *  Constant: '<S4>/Constant1'
     */
    rtb_Gain = ACC_P.Constant1_Value;
  } else {
    switch (ACC_DW.is_c3_ACC) {
     case ACC_IN_AccOff:
      if (ACC_DW.v1 != rtb_Gain) {
        ACC_DW.is_c3_ACC = ACC_IN_AccStandby;
        ACC_DW.v1 = rtb_Gain;
        ACC_DW.v2 = rtb_TmpRTBAtFunctionCallSubsy_f;
        rtb_state = 1;

        /* Switch: '<S4>/Switch' */
        rtb_Gain = ACC_B.Merge;
      } else {
        ACC_DW.v1 = rtb_Gain;
        ACC_DW.v2 = rtb_TmpRTBAtFunctionCallSubsy_f;
        rtb_state = 0;

        /* Switch: '<S4>/Switch' incorporates:
         *  Constant: '<S4>/Constant1'
         */
        rtb_Gain = ACC_P.Constant1_Value;
      }
      break;

     case ACC_IN_AccOn:
      if ((ACC_DW.v1 != rtb_Gain) || (ACC_DW.v2 !=
           rtb_TmpRTBAtFunctionCallSubsy_f)) {
        ACC_DW.is_c3_ACC = ACC_IN_AccOff;
        ACC_DW.v1 = rtb_Gain;
        ACC_DW.v2 = rtb_TmpRTBAtFunctionCallSubsy_f;
        rtb_state = 0;

        /* Switch: '<S4>/Switch' incorporates:
         *  Constant: '<S4>/Constant1'
         */
        rtb_Gain = ACC_P.Constant1_Value;
      } else {
        ACC_DW.v1 = rtb_Gain;
        ACC_DW.v2 = rtb_TmpRTBAtFunctionCallSubsy_f;
        rtb_state = 2;

        /* Switch: '<S4>/Switch' */
        rtb_Gain = ACC_B.Merge;
      }
      break;

     default:
      /* case IN_AccStandby: */
      if (ACC_DW.v2 != rtb_TmpRTBAtFunctionCallSubsy_f) {
        ACC_DW.is_c3_ACC = ACC_IN_AccOff;
        ACC_DW.v1 = rtb_Gain;
        ACC_DW.v2 = rtb_TmpRTBAtFunctionCallSubsy_f;
        rtb_state = 0;

        /* Switch: '<S4>/Switch' incorporates:
         *  Constant: '<S4>/Constant1'
         */
        rtb_Gain = ACC_P.Constant1_Value;
      } else {
        if (ACC_DW.v1 != rtb_Gain) {
          ACC_DW.is_c3_ACC = ACC_IN_AccOn;
          ACC_DW.v1 = rtb_Gain;
          ACC_DW.v2 = rtb_TmpRTBAtFunctionCallSubsy_f;
          rtb_state = 2;
        } else {
          ACC_DW.v1 = rtb_Gain;
          ACC_DW.v2 = rtb_TmpRTBAtFunctionCallSubsy_f;
          rtb_state = 1;
        }

        /* Switch: '<S4>/Switch' */
        rtb_Gain = ACC_B.Merge;
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
  if (ACC_M->Timing.TaskCounters.TID[2] == 0) {
    /* DiscretePulseGenerator: '<S2>/Pulse Generator6' */
    ACC_B.PulseGenerator6 = (ACC_DW.clockTickCounter_n <
      ACC_P.PulseGenerator6_Duty) && (ACC_DW.clockTickCounter_n >= 0L) ?
      ACC_P.PulseGenerator6_Amp : 0.0;

    /* DiscretePulseGenerator: '<S2>/Pulse Generator6' */
    if (ACC_DW.clockTickCounter_n >= ACC_P.PulseGenerator6_Period - 1.0) {
      ACC_DW.clockTickCounter_n = 0L;
    } else {
      ACC_DW.clockTickCounter_n++;
    }
  }

  if (ACC_M->Timing.TaskCounters.TID[3] == 0) {
    /* DiscretePulseGenerator: '<S2>/Pulse Generator7' */
    ACC_B.PulseGenerator7 = (ACC_DW.clockTickCounter_b <
      ACC_P.PulseGenerator7_Duty) && (ACC_DW.clockTickCounter_b >= 0L) ?
      ACC_P.PulseGenerator7_Amp : 0.0;

    /* DiscretePulseGenerator: '<S2>/Pulse Generator7' */
    if (ACC_DW.clockTickCounter_b >= ACC_P.PulseGenerator7_Period - 1.0) {
      ACC_DW.clockTickCounter_b = 0L;
    } else {
      ACC_DW.clockTickCounter_b++;
    }
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
    rtb_Gain = ACC_B.PulseGenerator6;

    /* End of Outputs for SubSystem: '<S2>/ACC standby2' */
  } else if (rtb_state == 2) {
    rtb_Gain = ACC_P.Constant_Value_o;
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/ACC off5' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    rtb_Gain = ACC_B.PulseGenerator7;

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

  /* MATLABSystem: '<Root>/Analog Input' */
  if (ACC_DW.obj.SampleTime != ACC_P.AnalogInput_SampleTime) {
    ACC_DW.obj.SampleTime = ACC_P.AnalogInput_SampleTime;
  }

  ACC_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(62UL);
  MW_AnalogInSingle_ReadResult(ACC_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
    &b_varargout_1, MW_ANALOGIN_UINT16);

  /* Gain: '<S3>/Gain' incorporates:
   *  MATLABSystem: '<Root>/Analog Input'
   * */
  duration = (uint32_T)ACC_P.Gain_Gain_a * b_varargout_1;

  /* Chart: '<S3>/Chart' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  Gain: '<S3>/Gain'
   */
  if (ACC_DW.is_active_c1_ACC == 0U) {
    ACC_DW.is_active_c1_ACC = 1U;
    ACC_DW.is_c1_ACC = ACC_IN_AccOff;
    ACC_DW.a = (real_T)duration * 7.62939453125E-6;
    rtb_Gain = 0.0;
  } else {
    switch (ACC_DW.is_c1_ACC) {
     case ACC_IN_AccOff:
      if (rtb_state == 1) {
        ACC_DW.is_c1_ACC = ACC_IN_AccStandby;
        rtb_Gain = ACC_DW.a;
      } else {
        ACC_DW.a = (real_T)duration * 7.62939453125E-6;
        rtb_Gain = 0.0;
      }
      break;

     case ACC_IN_AccOn:
      if (rtb_state == 0) {
        ACC_DW.is_c1_ACC = ACC_IN_AccOff;
        ACC_DW.a = (real_T)duration * 7.62939453125E-6;
        rtb_Gain = 0.0;
      } else {
        rtb_Gain = (real_T)duration * 7.62939453125E-6;
      }
      break;

     default:
      /* case IN_AccStandby: */
      if (rtb_state == 2) {
        ACC_DW.is_c1_ACC = ACC_IN_AccOn;
        rtb_Gain = (real_T)duration * 7.62939453125E-6;
      } else {
        rtb_Gain = ACC_DW.a;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/Chart' */
  if (ACC_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<Root>/PWM' */
    ACC_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

    /* If: '<S3>/If' incorporates:
     *  Constant: '<S3>/Constant'
     *  Constant: '<S3>/Constant1'
     *  DataTypeConversion: '<S3>/Data Type Conversion1'
     *  Product: '<S3>/Divide'
     */
    if (rtb_Merge == 1.0) {
      rtb_Gain /= ACC_P.Constant1_Value_i;
    } else if (rtb_Merge == 2.0) {
      rtb_Gain = ACC_P.Constant_Value_k;
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
    MW_PWM_SetDutyCycle(ACC_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE, (real_T)
                        (rtb_Gain < 0.0 ? (int16_T)(uint8_T)-(int8_T)(uint8_T)
                         -rtb_Gain : (int16_T)(uint8_T)rtb_Gain));
  }

  rate_scheduler();
}

/* Model initialize function */
void ACC_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* InitializeConditions for RateTransition generated from: '<S2>/Function-Call Subsystem4' */
  ACC_DW.TmpRTBAtFunctionCallSubsystem4O = ACC_P.TmpRTBAtFunctionCallSubsystem4O;
  ACC_DW.TmpRTBAtFunctionCallSubsystem_f = -1;
  ACC_DW.TmpRTBAtFunctionCallSubsystem_o = -1;

  /* InitializeConditions for RateTransition generated from: '<S2>/Function-Call Subsystem6' */
  ACC_DW.TmpRTBAtFunctionCallSubsystem6O = ACC_P.TmpRTBAtFunctionCallSubsystem6O;
  ACC_DW.TmpRTBAtFunctionCallSubsystem_n = -1;
  ACC_DW.TmpRTBAtFunctionCallSubsyste_ff = -1;

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt5' incorporates:
   *  SubSystem: '<S2>/Function-Call Subsystem4'
   */

  /* System initialize for function-call system: '<S2>/Function-Call Subsystem4' */

  /* SystemInitialize for Outport: '<S9>/sw1' incorporates:
   *  Delay: '<S9>/Delay'
   *  Sum: '<S9>/Add'
   */
  ACC_DW.Delay_DSTATE_l = ACC_P.sw1_Y0;

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
  ACC_DW.Delay_DSTATE = ACC_P.sw2_Y0;

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(21), &MW_ISR_21, FALLING);

  /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt6' */

  /* Start for MATLABSystem: '<Root>/Ultrasonic Sensor' */
  ACC_DW.obj_ok.isInitialized = 1L;
  MW_UltrasonicSetup(50, 51);
  ACC_DW.obj_ok.TunablePropsChanged = false;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  ACC_DW.obj_o.matlabCodegenIsDeleted = false;
  ACC_DW.obj_o.isInitialized = 1L;
  digitalIOSetup(23, 1);
  ACC_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output4' */
  ACC_DW.obj_c.matlabCodegenIsDeleted = false;
  ACC_DW.obj_c.isInitialized = 1L;
  digitalIOSetup(22, 1);
  ACC_DW.obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  ACC_DW.obj.matlabCodegenIsDeleted = false;
  ACC_DW.obj.SampleTime = ACC_P.AnalogInput_SampleTime;
  ACC_DW.obj.isInitialized = 1L;
  ACC_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(62UL);
  ACC_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM' */
  ACC_DW.obj_a.matlabCodegenIsDeleted = false;
  ACC_DW.obj_a.isInitialized = 1L;
  ACC_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
  ACC_DW.obj_a.isSetupComplete = true;
}

/* Model terminate function */
void ACC_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!ACC_DW.obj_o.matlabCodegenIsDeleted) {
    ACC_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output4' */
  if (!ACC_DW.obj_c.matlabCodegenIsDeleted) {
    ACC_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output4' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!ACC_DW.obj.matlabCodegenIsDeleted) {
    ACC_DW.obj.matlabCodegenIsDeleted = true;
    if ((ACC_DW.obj.isInitialized == 1L) && ACC_DW.obj.isSetupComplete) {
      ACC_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle
        (62UL);
      MW_AnalogIn_Close(ACC_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!ACC_DW.obj_a.matlabCodegenIsDeleted) {
    ACC_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((ACC_DW.obj_a.isInitialized == 1L) && ACC_DW.obj_a.isSetupComplete) {
      ACC_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(ACC_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      ACC_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(ACC_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
