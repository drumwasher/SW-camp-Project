/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ACC2.c
 *
 * Code generated for Simulink model 'ACC2'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Feb  5 15:38:00 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ACC2.h"
#include "rtwtypes.h"
#include "ACC2_private.h"
#include <math.h>
#include "rt_nonfinite.h"

/* Named constants for Chart: '<S2>/Chart' */
#define ACC2_IN_AccOff                 ((uint8_T)1U)
#define ACC2_IN_AccOn                  ((uint8_T)2U)
#define ACC2_IN_AccStandby             ((uint8_T)3U)

/* Block signals (default storage) */
B_ACC2_T ACC2_B;

/* Block states (default storage) */
DW_ACC2_T ACC2_DW;

/* Real-time model */
static RT_MODEL_ACC2_T ACC2_M_;
RT_MODEL_ACC2_T *const ACC2_M = &ACC2_M_;
static void rate_scheduler(void);

/* Callback for Hardware Interrupt Block: '<Root>/External Interrupt5' */
void MW_ISR_20(void)
{
  /* Call the system: <S2>/Function-Call Subsystem4 */
  {
    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt5' */

    /* Output and update for function-call system: '<S2>/Function-Call Subsystem4' */

    /* Sum: '<S11>/Add' incorporates:
     *  Constant: '<S11>/Constant'
     *  Delay: '<S11>/Delay'
     */
    ACC2_DW.Delay_DSTATE_l = ACC2_P.Constant_Value - ACC2_DW.Delay_DSTATE_l;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt5' */

    /* RateTransition generated from: '<S2>/Function-Call Subsystem4' incorporates:
     *  Delay: '<S11>/Delay'
     */
    switch (ACC2_DW.TmpRTBAtFunctionCallSubsystem_o) {
     case 0:
      ACC2_DW.TmpRTBAtFunctionCallSubsystem_f = 1;
      break;

     case 1:
      ACC2_DW.TmpRTBAtFunctionCallSubsystem_f = 0;
      break;

     default:
      ACC2_DW.TmpRTBAtFunctionCallSubsystem_f = (int8_T)
        (ACC2_DW.TmpRTBAtFunctionCallSubsystem_c == 0);
      break;
    }

    if (ACC2_DW.TmpRTBAtFunctionCallSubsystem_f != 0) {
      ACC2_DW.TmpRTBAtFunctionCallSubsystem_e = ACC2_DW.Delay_DSTATE_l;
    } else {
      ACC2_DW.TmpRTBAtFunctionCallSubsystem4O = ACC2_DW.Delay_DSTATE_l;
    }

    ACC2_DW.TmpRTBAtFunctionCallSubsystem_c =
      ACC2_DW.TmpRTBAtFunctionCallSubsystem_f;
    ACC2_DW.TmpRTBAtFunctionCallSubsystem_f = -1;

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

    /* Sum: '<S12>/Add' incorporates:
     *  Constant: '<S12>/Constant'
     *  Delay: '<S12>/Delay'
     */
    ACC2_DW.Delay_DSTATE = ACC2_P.Constant_Value_o - ACC2_DW.Delay_DSTATE;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt6' */

    /* RateTransition generated from: '<S2>/Function-Call Subsystem6' incorporates:
     *  Delay: '<S12>/Delay'
     */
    switch (ACC2_DW.TmpRTBAtFunctionCallSubsyste_ff) {
     case 0:
      ACC2_DW.TmpRTBAtFunctionCallSubsystem_n = 1;
      break;

     case 1:
      ACC2_DW.TmpRTBAtFunctionCallSubsystem_n = 0;
      break;

     default:
      ACC2_DW.TmpRTBAtFunctionCallSubsystem_n = (int8_T)
        (ACC2_DW.TmpRTBAtFunctionCallSubsystem_k == 0);
      break;
    }

    if (ACC2_DW.TmpRTBAtFunctionCallSubsystem_n != 0) {
      ACC2_DW.TmpRTBAtFunctionCallSubsystem_a = ACC2_DW.Delay_DSTATE;
    } else {
      ACC2_DW.TmpRTBAtFunctionCallSubsystem6O = ACC2_DW.Delay_DSTATE;
    }

    ACC2_DW.TmpRTBAtFunctionCallSubsystem_k =
      ACC2_DW.TmpRTBAtFunctionCallSubsystem_n;
    ACC2_DW.TmpRTBAtFunctionCallSubsystem_n = -1;

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
  (ACC2_M->Timing.TaskCounters.TID[1])++;
  if ((ACC2_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    ACC2_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S4>/If Action Subsystem'
 *    '<S4>/If Action Subsystem1'
 */
void ACC2_IfActionSubsystem(real_T rtu_In1, real_T rtu_In2, real_T *rty_Out1,
  real_T *rty_Out2)
{
  /* SignalConversion generated from: '<S17>/In1' */
  *rty_Out1 = rtu_In1;

  /* SignalConversion generated from: '<S17>/In2' */
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
void ACC2_step(void)
{
  real_T PulseGenerator;
  real_T PulseGenerator1;
  real_T rtb_Gain;
  real_T rtb_Merge;
  real_T rtb_Merge1;
  real_T speed;
  uint32_T duration;
  int16_T rtb_state;
  uint16_T b_varargout_1;
  uint8_T tmp;
  if (ACC2_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<Root>/Ultrasonic Sensor' */
    if (ACC2_DW.obj_lm.TunablePropsChanged) {
      ACC2_DW.obj_lm.TunablePropsChanged = false;
    }

    MW_UltrasonicRead(&duration, 1, 50, 51, 10);

    /* Gain: '<S4>/Gain' incorporates:
     *  MATLABSystem: '<Root>/Ultrasonic Sensor'
     * */
    rtb_Gain = (real_T)duration * 0.000343 / 2.0 * ACC2_P.Gain_Gain;
  }

  /* DiscretePulseGenerator: '<S4>/Pulse Generator' */
  PulseGenerator = (ACC2_DW.clockTickCounter < ACC2_P.PulseGenerator_Duty) &&
    (ACC2_DW.clockTickCounter >= 0L) ? ACC2_P.PulseGenerator_Amp : 0.0;

  /* DiscretePulseGenerator: '<S4>/Pulse Generator' */
  if (ACC2_DW.clockTickCounter >= ACC2_P.PulseGenerator_Period - 1.0) {
    ACC2_DW.clockTickCounter = 0L;
  } else {
    ACC2_DW.clockTickCounter++;
  }

  if (ACC2_M->Timing.TaskCounters.TID[1] == 0) {
    /* If: '<S4>/If' incorporates:
     *  Constant: '<S4>/Constant'
     *  Constant: '<S4>/Constant2'
     *  Constant: '<S4>/Constant3'
     */
    if (rtb_Gain < 10.0) {
      /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem' incorporates:
       *  ActionPort: '<S17>/Action Port'
       */
      ACC2_IfActionSubsystem(ACC2_P.Constant_Value_oi, ACC2_P.Constant2_Value,
        &ACC2_B.Merge, &rtb_Merge1);

      /* End of Outputs for SubSystem: '<S4>/If Action Subsystem' */
    } else if (rtb_Gain < 50.0) {
      /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S18>/Action Port'
       */
      ACC2_IfActionSubsystem(PulseGenerator, ACC2_P.Constant3_Value,
        &ACC2_B.Merge, &rtb_Merge1);

      /* End of Outputs for SubSystem: '<S4>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S19>/Action Port'
       */
      /* Merge: '<S4>/Merge' incorporates:
       *  Constant: '<S4>/Constant1'
       *  SignalConversion generated from: '<S19>/In1'
       */
      ACC2_B.Merge = ACC2_P.Constant1_Value_e;

      /* SignalConversion generated from: '<S19>/In2' incorporates:
       *  Constant: '<S4>/Constant1'
       */
      rtb_Merge1 = ACC2_P.Constant1_Value_e;

      /* End of Outputs for SubSystem: '<S4>/If Action Subsystem2' */
    }

    /* End of If: '<S4>/If' */
  }

  /* RateTransition generated from: '<S2>/Function-Call Subsystem4' */
  switch (ACC2_DW.TmpRTBAtFunctionCallSubsystem_f) {
   case 0:
    ACC2_DW.TmpRTBAtFunctionCallSubsystem_o = 1;
    break;

   case 1:
    ACC2_DW.TmpRTBAtFunctionCallSubsystem_o = 0;
    break;

   default:
    ACC2_DW.TmpRTBAtFunctionCallSubsystem_o =
      ACC2_DW.TmpRTBAtFunctionCallSubsystem_c;
    break;
  }

  if (ACC2_DW.TmpRTBAtFunctionCallSubsystem_o != 0) {
    rtb_Gain = ACC2_DW.TmpRTBAtFunctionCallSubsystem_e;
  } else {
    rtb_Gain = ACC2_DW.TmpRTBAtFunctionCallSubsystem4O;
  }

  ACC2_DW.TmpRTBAtFunctionCallSubsystem_o = -1;

  /* End of RateTransition generated from: '<S2>/Function-Call Subsystem4' */
  /* RateTransition generated from: '<S2>/Function-Call Subsystem6' */
  switch (ACC2_DW.TmpRTBAtFunctionCallSubsystem_n) {
   case 0:
    ACC2_DW.TmpRTBAtFunctionCallSubsyste_ff = 1;
    break;

   case 1:
    ACC2_DW.TmpRTBAtFunctionCallSubsyste_ff = 0;
    break;

   default:
    ACC2_DW.TmpRTBAtFunctionCallSubsyste_ff =
      ACC2_DW.TmpRTBAtFunctionCallSubsystem_k;
    break;
  }

  if (ACC2_DW.TmpRTBAtFunctionCallSubsyste_ff != 0) {
    PulseGenerator = ACC2_DW.TmpRTBAtFunctionCallSubsystem_a;
  } else {
    PulseGenerator = ACC2_DW.TmpRTBAtFunctionCallSubsystem6O;
  }

  ACC2_DW.TmpRTBAtFunctionCallSubsyste_ff = -1;

  /* End of RateTransition generated from: '<S2>/Function-Call Subsystem6' */

  /* Chart: '<S2>/Chart' */
  if (ACC2_DW.is_active_c3_ACC2 == 0U) {
    ACC2_DW.is_active_c3_ACC2 = 1U;
    ACC2_DW.is_c3_ACC2 = ACC2_IN_AccOff;
    ACC2_DW.v1 = rtb_Gain;
    ACC2_DW.v2 = PulseGenerator;
    rtb_state = 0;

    /* Switch: '<S4>/Switch' incorporates:
     *  Constant: '<S4>/Constant1'
     */
    speed = ACC2_P.Constant1_Value_e;
  } else {
    switch (ACC2_DW.is_c3_ACC2) {
     case ACC2_IN_AccOff:
      if (ACC2_DW.v1 != rtb_Gain) {
        ACC2_DW.is_c3_ACC2 = ACC2_IN_AccStandby;
        ACC2_DW.v1 = rtb_Gain;
        ACC2_DW.v2 = PulseGenerator;
        rtb_state = 1;

        /* Switch: '<S4>/Switch' */
        speed = ACC2_B.Merge;
      } else {
        ACC2_DW.v1 = rtb_Gain;
        ACC2_DW.v2 = PulseGenerator;
        rtb_state = 0;

        /* Switch: '<S4>/Switch' incorporates:
         *  Constant: '<S4>/Constant1'
         */
        speed = ACC2_P.Constant1_Value_e;
      }
      break;

     case ACC2_IN_AccOn:
      if ((ACC2_DW.v1 != rtb_Gain) || (ACC2_DW.v2 != PulseGenerator)) {
        ACC2_DW.is_c3_ACC2 = ACC2_IN_AccOff;
        ACC2_DW.v1 = rtb_Gain;
        ACC2_DW.v2 = PulseGenerator;
        rtb_state = 0;

        /* Switch: '<S4>/Switch' incorporates:
         *  Constant: '<S4>/Constant1'
         */
        speed = ACC2_P.Constant1_Value_e;
      } else {
        ACC2_DW.v1 = rtb_Gain;
        ACC2_DW.v2 = PulseGenerator;
        rtb_state = 2;

        /* Switch: '<S4>/Switch' */
        speed = ACC2_B.Merge;
      }
      break;

     default:
      /* case IN_AccStandby: */
      if (ACC2_DW.v2 != PulseGenerator) {
        ACC2_DW.is_c3_ACC2 = ACC2_IN_AccOff;
        ACC2_DW.v1 = rtb_Gain;
        ACC2_DW.v2 = PulseGenerator;
        rtb_state = 0;

        /* Switch: '<S4>/Switch' incorporates:
         *  Constant: '<S4>/Constant1'
         */
        speed = ACC2_P.Constant1_Value_e;
      } else {
        if (ACC2_DW.v1 != rtb_Gain) {
          ACC2_DW.is_c3_ACC2 = ACC2_IN_AccOn;
          ACC2_DW.v1 = rtb_Gain;
          ACC2_DW.v2 = PulseGenerator;
          rtb_state = 2;
        } else {
          ACC2_DW.v1 = rtb_Gain;
          ACC2_DW.v2 = PulseGenerator;
          rtb_state = 1;
        }

        /* Switch: '<S4>/Switch' */
        speed = ACC2_B.Merge;
      }
      break;
    }
  }

  /* End of Chart: '<S2>/Chart' */

  /* MATLABSystem: '<Root>/Digital Output' incorporates:
   *  Switch: '<S4>/Switch'
   */
  speed = rt_roundd_snf(speed);
  if (speed < 256.0) {
    if (speed >= 0.0) {
      tmp = (uint8_T)speed;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(23, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output' */

  /* DiscretePulseGenerator: '<S2>/Pulse Generator6' */
  rtb_Gain = (ACC2_DW.clockTickCounter_k < ACC2_P.PulseGenerator6_Duty) &&
    (ACC2_DW.clockTickCounter_k >= 0L) ? ACC2_P.PulseGenerator6_Amp : 0.0;
  if (ACC2_DW.clockTickCounter_k >= ACC2_P.PulseGenerator6_Period - 1.0) {
    ACC2_DW.clockTickCounter_k = 0L;
  } else {
    ACC2_DW.clockTickCounter_k++;
  }

  /* End of DiscretePulseGenerator: '<S2>/Pulse Generator6' */

  /* DiscretePulseGenerator: '<S2>/Pulse Generator7' */
  PulseGenerator = (ACC2_DW.clockTickCounter_b < ACC2_P.PulseGenerator7_Duty) &&
    (ACC2_DW.clockTickCounter_b >= 0L) ? ACC2_P.PulseGenerator7_Amp : 0.0;
  if (ACC2_DW.clockTickCounter_b >= ACC2_P.PulseGenerator7_Period - 1.0) {
    ACC2_DW.clockTickCounter_b = 0L;
  } else {
    ACC2_DW.clockTickCounter_b++;
  }

  /* End of DiscretePulseGenerator: '<S2>/Pulse Generator7' */

  /* MATLABSystem: '<Root>/Analog Input' */
  if (ACC2_DW.obj_p.SampleTime != ACC2_P.AnalogInput_SampleTime) {
    ACC2_DW.obj_p.SampleTime = ACC2_P.AnalogInput_SampleTime;
  }

  ACC2_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle
    (62UL);
  MW_AnalogInSingle_ReadResult
    (ACC2_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     MW_ANALOGIN_UINT16);

  /* Gain: '<S3>/Gain' incorporates:
   *  MATLABSystem: '<Root>/Analog Input'
   * */
  duration = (uint32_T)ACC2_P.Gain_Gain_o * b_varargout_1;

  /* Chart: '<S3>/Chart' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  Gain: '<S3>/Gain'
   */
  if (ACC2_DW.is_active_c1_ACC2 == 0U) {
    ACC2_DW.is_active_c1_ACC2 = 1U;
    ACC2_DW.is_c1_ACC2 = ACC2_IN_AccOff;
    ACC2_DW.a = (real_T)duration * 7.62939453125E-6;
    speed = 0.0;
  } else {
    switch (ACC2_DW.is_c1_ACC2) {
     case ACC2_IN_AccOff:
      if (rtb_state == 1) {
        ACC2_DW.is_c1_ACC2 = ACC2_IN_AccStandby;
        speed = ACC2_DW.a;
      } else {
        ACC2_DW.a = (real_T)duration * 7.62939453125E-6;
        speed = 0.0;
      }
      break;

     case ACC2_IN_AccOn:
      if (rtb_state == 0) {
        ACC2_DW.is_c1_ACC2 = ACC2_IN_AccOff;
        ACC2_DW.a = (real_T)duration * 7.62939453125E-6;
        speed = 0.0;
      } else {
        speed = (real_T)duration * 7.62939453125E-6;
      }
      break;

     default:
      /* case IN_AccStandby: */
      if (rtb_state == 2) {
        ACC2_DW.is_c1_ACC2 = ACC2_IN_AccOn;
        speed = (real_T)duration * 7.62939453125E-6;
      } else if (rtb_state == 0) {
        ACC2_DW.is_c1_ACC2 = ACC2_IN_AccOff;
        ACC2_DW.a = (real_T)duration * 7.62939453125E-6;
        speed = 0.0;
      } else {
        speed = ACC2_DW.a;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/Chart' */
  if (ACC2_M->Timing.TaskCounters.TID[1] == 0) {
    /* If: '<S3>/If' */
    if (rtb_Merge1 == 1.0) {
      /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      /* SignalConversion generated from: '<S14>/speed' incorporates:
       *  Constant: '<S3>/Constant1'
       *  Product: '<S3>/Divide'
       */
      rtb_Merge = speed / ACC2_P.Constant1_Value_c;

      /* End of Outputs for SubSystem: '<S3>/If Action Subsystem' */
    } else if (rtb_Merge1 == 2.0) {
      /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      /* SignalConversion generated from: '<S15>/speed' incorporates:
       *  Constant: '<S3>/Constant'
       */
      rtb_Merge = ACC2_P.Constant_Value_f;

      /* End of Outputs for SubSystem: '<S3>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S16>/Action Port'
       */
      /* SignalConversion generated from: '<S16>/speed' */
      rtb_Merge = speed;

      /* End of Outputs for SubSystem: '<S3>/If Action Subsystem2' */
    }

    /* End of If: '<S3>/If' */
  }

  /* DiscretePulseGenerator: '<S5>/Pulse Generator' */
  speed = (ACC2_DW.clockTickCounter_j < ACC2_P.PulseGenerator_Duty_k) &&
    (ACC2_DW.clockTickCounter_j >= 0L) ? ACC2_P.PulseGenerator_Amp_l : 0.0;

  /* DiscretePulseGenerator: '<S5>/Pulse Generator' */
  if (ACC2_DW.clockTickCounter_j >= ACC2_P.PulseGenerator_Period_l - 1.0) {
    ACC2_DW.clockTickCounter_j = 0L;
  } else {
    ACC2_DW.clockTickCounter_j++;
  }

  /* DiscretePulseGenerator: '<S5>/Pulse Generator1' */
  PulseGenerator1 = (ACC2_DW.clockTickCounter_o < ACC2_P.PulseGenerator1_Duty) &&
    (ACC2_DW.clockTickCounter_o >= 0L) ? ACC2_P.PulseGenerator1_Amp : 0.0;

  /* DiscretePulseGenerator: '<S5>/Pulse Generator1' */
  if (ACC2_DW.clockTickCounter_o >= ACC2_P.PulseGenerator1_Period - 1.0) {
    ACC2_DW.clockTickCounter_o = 0L;
  } else {
    ACC2_DW.clockTickCounter_o++;
  }

  if (ACC2_M->Timing.TaskCounters.TID[1] == 0) {
    /* If: '<S5>/If' */
    if (rtb_Merge1 == 2.0) {
      /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      /* Merge: '<S5>/Merge' incorporates:
       *  SignalConversion generated from: '<S20>/In1'
       */
      ACC2_B.Merge_e = PulseGenerator1;

      /* End of Outputs for SubSystem: '<S5>/If Action Subsystem' */
    } else if (rtb_Merge1 == 1.0) {
      /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      /* Merge: '<S5>/Merge' incorporates:
       *  SignalConversion generated from: '<S21>/In1'
       */
      ACC2_B.Merge_e = speed;

      /* End of Outputs for SubSystem: '<S5>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      /* Merge: '<S5>/Merge' incorporates:
       *  Constant: '<S5>/Constant'
       *  SignalConversion generated from: '<S22>/In1'
       */
      ACC2_B.Merge_e = ACC2_P.Constant_Value_fw;

      /* End of Outputs for SubSystem: '<S5>/If Action Subsystem2' */
    }

    /* End of If: '<S5>/If' */
  }

  /* MATLABSystem: '<Root>/Analog Input1' */
  if (ACC2_DW.obj.SampleTime != ACC2_P.AnalogInput1_SampleTime) {
    ACC2_DW.obj.SampleTime = ACC2_P.AnalogInput1_SampleTime;
  }

  ACC2_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(63UL);
  MW_AnalogInSingle_ReadResult(ACC2_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
    &b_varargout_1, MW_ANALOGIN_UINT16);

  /* MATLABSystem: '<Root>/PWM1' */
  ACC2_DW.obj_eu.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(3UL);

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant1'
   */
  if (rtb_state != 0) {
    /* If: '<S6>/If' incorporates:
     *  DataTypeConversion: '<S6>/Data Type Conversion1'
     *  DataTypeConversion: '<S6>/Data Type Conversion2'
     *  Gain: '<S6>/Gain'
     *  MATLABSystem: '<Root>/Analog Input1'
     *  Sum: '<S6>/Add'
     * */
    if (b_varargout_1 < 500U) {
      /* Sum: '<S6>/Add' incorporates:
       *  Constant: '<S6>/Constant2'
       */
      speed = floor((real_T)b_varargout_1 - ACC2_P.Constant2_Value_f);
      if (rtIsNaN(speed) || rtIsInf(speed)) {
        speed = 0.0;
      } else {
        speed = fmod(speed, 256.0);
      }

      rtb_Merge1 = ((uint16_T)(speed < 0.0 ? (int16_T)(uint8_T)-(int8_T)(uint8_T)
        -speed : (int16_T)(uint8_T)speed) * ACC2_P.Gain_Gain_f) >> 9;
    } else {
      /* DataTypeConversion: '<S6>/Data Type Conversion1' incorporates:
       *  Constant: '<S6>/Constant'
       */
      speed = floor(ACC2_P.Constant_Value_kz);
      if (rtIsNaN(speed) || rtIsInf(speed)) {
        speed = 0.0;
      } else {
        speed = fmod(speed, 256.0);
      }

      rtb_Merge1 = speed < 0.0 ? (int16_T)(uint8_T)-(int8_T)(uint8_T)-speed :
        (int16_T)(uint8_T)speed;
    }

    /* End of If: '<S6>/If' */
  } else {
    rtb_Merge1 = ACC2_P.Constant1_Value_f;
  }

  /* Start for MATLABSystem: '<Root>/PWM1' incorporates:
   *  Switch: '<S6>/Switch'
   */
  if (!(rtb_Merge1 <= 255.0)) {
    rtb_Merge1 = 255.0;
  }

  if (!(rtb_Merge1 >= 0.0)) {
    rtb_Merge1 = 0.0;
  }

  /* MATLABSystem: '<Root>/PWM1' */
  MW_PWM_SetDutyCycle(ACC2_DW.obj_eu.PWMDriverObj.MW_PWM_HANDLE, rtb_Merge1);

  /* MATLABSystem: '<Root>/PWM2' */
  ACC2_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(44UL);

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Constant1'
   */
  if (rtb_state != 0) {
    rtb_Merge1 = ACC2_B.Merge_e;
  } else {
    rtb_Merge1 = ACC2_P.Constant1_Value;
  }

  /* Start for MATLABSystem: '<Root>/PWM2' incorporates:
   *  Switch: '<S5>/Switch'
   */
  if (!(rtb_Merge1 <= 255.0)) {
    rtb_Merge1 = 255.0;
  }

  if (!(rtb_Merge1 >= 0.0)) {
    rtb_Merge1 = 0.0;
  }

  /* MATLABSystem: '<Root>/PWM2' */
  MW_PWM_SetDutyCycle(ACC2_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE, rtb_Merge1);
  if (ACC2_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<Root>/PWM' */
    ACC2_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

    /* DataTypeConversion: '<S3>/Data Type Conversion1' */
    speed = floor(rtb_Merge);
    if (rtIsNaN(speed) || rtIsInf(speed)) {
      speed = 0.0;
    } else {
      speed = fmod(speed, 256.0);
    }

    /* MATLABSystem: '<Root>/PWM' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion1'
     */
    MW_PWM_SetDutyCycle(ACC2_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, (real_T)(speed
      < 0.0 ? (int16_T)(uint8_T)-(int8_T)(uint8_T)-speed : (int16_T)(uint8_T)
      speed));
  }

  /* If: '<S2>/If5' incorporates:
   *  Constant: '<S8>/Constant'
   *  MATLABSystem: '<Root>/Digital Output4'
   *  SignalConversion generated from: '<S9>/In1'
   */
  if (rtb_state == 1) {
    /* Outputs for IfAction SubSystem: '<S2>/ACC standby2' incorporates:
     *  ActionPort: '<S9>/ACC standby'
     */
    PulseGenerator = rtb_Gain;

    /* End of Outputs for SubSystem: '<S2>/ACC standby2' */
  } else if (rtb_state == 2) {
    PulseGenerator = ACC2_P.Constant_Value_k;
  }

  speed = rt_roundd_snf(PulseGenerator);

  /* End of If: '<S2>/If5' */

  /* MATLABSystem: '<Root>/Digital Output4' */
  if (speed < 256.0) {
    if (speed >= 0.0) {
      tmp = (uint8_T)speed;
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
void ACC2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* InitializeConditions for RateTransition generated from: '<S2>/Function-Call Subsystem4' */
  ACC2_DW.TmpRTBAtFunctionCallSubsystem4O =
    ACC2_P.TmpRTBAtFunctionCallSubsystem4O;
  ACC2_DW.TmpRTBAtFunctionCallSubsystem_f = -1;
  ACC2_DW.TmpRTBAtFunctionCallSubsystem_o = -1;

  /* InitializeConditions for RateTransition generated from: '<S2>/Function-Call Subsystem6' */
  ACC2_DW.TmpRTBAtFunctionCallSubsystem6O =
    ACC2_P.TmpRTBAtFunctionCallSubsystem6O;
  ACC2_DW.TmpRTBAtFunctionCallSubsystem_n = -1;
  ACC2_DW.TmpRTBAtFunctionCallSubsyste_ff = -1;

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt5' incorporates:
   *  SubSystem: '<S2>/Function-Call Subsystem4'
   */

  /* System initialize for function-call system: '<S2>/Function-Call Subsystem4' */

  /* SystemInitialize for Outport: '<S11>/sw1' incorporates:
   *  Delay: '<S11>/Delay'
   *  Sum: '<S11>/Add'
   */
  ACC2_DW.Delay_DSTATE_l = ACC2_P.sw1_Y0;

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(20), &MW_ISR_20, FALLING);

  /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt5' */

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt6' incorporates:
   *  SubSystem: '<S2>/Function-Call Subsystem6'
   */

  /* System initialize for function-call system: '<S2>/Function-Call Subsystem6' */

  /* SystemInitialize for Outport: '<S12>/sw2' incorporates:
   *  Delay: '<S12>/Delay'
   *  Sum: '<S12>/Add'
   */
  ACC2_DW.Delay_DSTATE = ACC2_P.sw2_Y0;

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(21), &MW_ISR_21, FALLING);

  /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt6' */

  /* Start for MATLABSystem: '<Root>/Ultrasonic Sensor' */
  ACC2_DW.obj_lm.isInitialized = 1L;
  MW_UltrasonicSetup(50, 51);
  ACC2_DW.obj_lm.TunablePropsChanged = false;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  ACC2_DW.obj_g.matlabCodegenIsDeleted = false;
  ACC2_DW.obj_g.isInitialized = 1L;
  digitalIOSetup(23, 1);
  ACC2_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  ACC2_DW.obj_p.matlabCodegenIsDeleted = false;
  ACC2_DW.obj_p.SampleTime = ACC2_P.AnalogInput_SampleTime;
  ACC2_DW.obj_p.isInitialized = 1L;
  ACC2_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open
    (62UL);
  ACC2_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input1' */
  ACC2_DW.obj.matlabCodegenIsDeleted = false;
  ACC2_DW.obj.SampleTime = ACC2_P.AnalogInput1_SampleTime;
  ACC2_DW.obj.isInitialized = 1L;
  ACC2_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(63UL);
  ACC2_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM1' */
  ACC2_DW.obj_eu.matlabCodegenIsDeleted = false;
  ACC2_DW.obj_eu.isInitialized = 1L;
  ACC2_DW.obj_eu.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(3UL, 0.0, 0.0);
  ACC2_DW.obj_eu.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM2' */
  ACC2_DW.obj_e.matlabCodegenIsDeleted = false;
  ACC2_DW.obj_e.isInitialized = 1L;
  ACC2_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(44UL, 0.0, 0.0);
  ACC2_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM' */
  ACC2_DW.obj_l.matlabCodegenIsDeleted = false;
  ACC2_DW.obj_l.isInitialized = 1L;
  ACC2_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
  ACC2_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output4' */
  ACC2_DW.obj_h.matlabCodegenIsDeleted = false;
  ACC2_DW.obj_h.isInitialized = 1L;
  digitalIOSetup(22, 1);
  ACC2_DW.obj_h.isSetupComplete = true;
}

/* Model terminate function */
void ACC2_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!ACC2_DW.obj_g.matlabCodegenIsDeleted) {
    ACC2_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!ACC2_DW.obj_p.matlabCodegenIsDeleted) {
    ACC2_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((ACC2_DW.obj_p.isInitialized == 1L) && ACC2_DW.obj_p.isSetupComplete) {
      ACC2_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle
        (62UL);
      MW_AnalogIn_Close(ACC2_DW.obj_p.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  if (!ACC2_DW.obj.matlabCodegenIsDeleted) {
    ACC2_DW.obj.matlabCodegenIsDeleted = true;
    if ((ACC2_DW.obj.isInitialized == 1L) && ACC2_DW.obj.isSetupComplete) {
      ACC2_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle
        (63UL);
      MW_AnalogIn_Close(ACC2_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */

  /* Terminate for MATLABSystem: '<Root>/PWM1' */
  if (!ACC2_DW.obj_eu.matlabCodegenIsDeleted) {
    ACC2_DW.obj_eu.matlabCodegenIsDeleted = true;
    if ((ACC2_DW.obj_eu.isInitialized == 1L) && ACC2_DW.obj_eu.isSetupComplete)
    {
      ACC2_DW.obj_eu.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(3UL);
      MW_PWM_SetDutyCycle(ACC2_DW.obj_eu.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      ACC2_DW.obj_eu.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(3UL);
      MW_PWM_Close(ACC2_DW.obj_eu.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM1' */

  /* Terminate for MATLABSystem: '<Root>/PWM2' */
  if (!ACC2_DW.obj_e.matlabCodegenIsDeleted) {
    ACC2_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((ACC2_DW.obj_e.isInitialized == 1L) && ACC2_DW.obj_e.isSetupComplete) {
      ACC2_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(44UL);
      MW_PWM_SetDutyCycle(ACC2_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      ACC2_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(44UL);
      MW_PWM_Close(ACC2_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM2' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!ACC2_DW.obj_l.matlabCodegenIsDeleted) {
    ACC2_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((ACC2_DW.obj_l.isInitialized == 1L) && ACC2_DW.obj_l.isSetupComplete) {
      ACC2_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(ACC2_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      ACC2_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(ACC2_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output4' */
  if (!ACC2_DW.obj_h.matlabCodegenIsDeleted) {
    ACC2_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output4' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
