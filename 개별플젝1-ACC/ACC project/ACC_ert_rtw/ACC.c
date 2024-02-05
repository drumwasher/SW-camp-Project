/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ACC.c
 *
 * Code generated for Simulink model 'ACC'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Feb  5 10:17:43 2024
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
#define ACC_IN_AccOff                  (1UL)
#define ACC_IN_AccOn                   (2UL)
#define ACC_IN_AccStandby              (3UL)

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
    /* Reset subsysRan breadcrumbs */
    srClearBC(ACC_DW.FunctionCallSubsystem4_SubsysRa);

    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt5' */

    /* Output and update for function-call system: '<S2>/Function-Call Subsystem4' */

    /* Asynchronous task (with no priority assigned)
     * reads absolute time */
    switch (ACC_M->Timing.rtmDbBufWriteBuf4) {
     case 0:
      ACC_M->Timing.rtmDbBufReadBuf4 = 1;
      break;

     case 1:
      ACC_M->Timing.rtmDbBufReadBuf4 = 0;
      break;

     default:
      ACC_M->Timing.rtmDbBufReadBuf4 = ACC_M->Timing.rtmDbBufLastBufWr4;
      break;
    }

    ACC_M->Timing.clockTick4 = ACC_M->Timing.rtmDbBufClockTick4
      [ACC_M->Timing.rtmDbBufReadBuf4];
    ACC_M->Timing.rtmDbBufReadBuf4 = 0xFF;

    /* Sum: '<S10>/Add' incorporates:
     *  Constant: '<S10>/Constant'
     *  Delay: '<S10>/Delay'
     */
    ACC_B.Add_j = ACC_P.Constant_Value - ACC_B.Add_j;
    ACC_DW.FunctionCallSubsystem4_SubsysRa = 4;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt5' */

    /* RateTransition generated from: '<S2>/Function-Call Subsystem4' */
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
      ACC_DW.TmpRTBAtFunctionCallSubsystem_e = ACC_B.Add_j;
    } else {
      ACC_DW.TmpRTBAtFunctionCallSubsystem4O = ACC_B.Add_j;
    }

    ACC_DW.TmpRTBAtFunctionCallSubsystem_c =
      ACC_DW.TmpRTBAtFunctionCallSubsystem_f;
    ACC_DW.TmpRTBAtFunctionCallSubsystem_f = -1;

    /* End of RateTransition generated from: '<S2>/Function-Call Subsystem4' */
  }

  extmodeEvent(4,((ACC_M->Timing.clockTick4) * 0.01));
}

/* Callback for Hardware Interrupt Block: '<Root>/External Interrupt6' */
void MW_ISR_21(void)
{
  /* Call the system: <S2>/Function-Call Subsystem6 */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(ACC_DW.FunctionCallSubsystem6_SubsysRa);

    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt6' */

    /* Output and update for function-call system: '<S2>/Function-Call Subsystem6' */

    /* Asynchronous task (with no priority assigned)
     * reads absolute time */
    switch (ACC_M->Timing.rtmDbBufWriteBuf5) {
     case 0:
      ACC_M->Timing.rtmDbBufReadBuf5 = 1;
      break;

     case 1:
      ACC_M->Timing.rtmDbBufReadBuf5 = 0;
      break;

     default:
      ACC_M->Timing.rtmDbBufReadBuf5 = ACC_M->Timing.rtmDbBufLastBufWr5;
      break;
    }

    ACC_M->Timing.clockTick5 = ACC_M->Timing.rtmDbBufClockTick5
      [ACC_M->Timing.rtmDbBufReadBuf5];
    ACC_M->Timing.rtmDbBufReadBuf5 = 0xFF;

    /* Sum: '<S11>/Add' incorporates:
     *  Constant: '<S11>/Constant'
     *  Delay: '<S11>/Delay'
     */
    ACC_B.Add = ACC_P.Constant_Value_e - ACC_B.Add;
    ACC_DW.FunctionCallSubsystem6_SubsysRa = 4;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt6' */

    /* RateTransition generated from: '<S2>/Function-Call Subsystem6' */
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
      ACC_DW.TmpRTBAtFunctionCallSubsystem_a = ACC_B.Add;
    } else {
      ACC_DW.TmpRTBAtFunctionCallSubsystem6O = ACC_B.Add;
    }

    ACC_DW.TmpRTBAtFunctionCallSubsystem_k =
      ACC_DW.TmpRTBAtFunctionCallSubsystem_n;
    ACC_DW.TmpRTBAtFunctionCallSubsystem_n = -1;

    /* End of RateTransition generated from: '<S2>/Function-Call Subsystem6' */
  }

  extmodeEvent(5,((ACC_M->Timing.clockTick5) * 0.01));
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
  /* SignalConversion generated from: '<S16>/In1' */
  *rty_Out1 = rtu_In1;

  /* SignalConversion generated from: '<S16>/In2' */
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
  real_T rtb_Merge1;
  real_T rtb_Merge3;
  real_T rtb_Merge_o;
  real_T speed;
  uint32_T duration;
  uint16_T b_varargout_1;
  uint8_T tmp;

  /* Reset subsysRan breadcrumbs */
  srClearBC(ACC_DW.ACCstandby2_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ACC_DW.ACCon2_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ACC_DW.ACCoff5_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ACC_DW.IfActionSubsystem_SubsysRanBC_m);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ACC_DW.IfActionSubsystem1_SubsysRanB_g);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ACC_DW.IfActionSubsystem2_SubsysRanB_b);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ACC_DW.IfActionSubsystem_i.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ACC_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ACC_DW.IfActionSubsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ACC_DW.IfActionSubsystem2_SubsysRanBC);
  if (ACC_M->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<Root>/Ultrasonic Sensor' */
    if (ACC_DW.obj_i.TunablePropsChanged) {
      ACC_DW.obj_i.TunablePropsChanged = false;
    }

    MW_UltrasonicRead(&duration, 1, 50, 51, 10);

    /* Gain: '<S4>/Gain' incorporates:
     *  MATLABSystem: '<Root>/Ultrasonic Sensor'
     * */
    ACC_B.Gain = (real_T)duration * 0.000343 / 2.0 * ACC_P.Gain_Gain;
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
    if (ACC_B.Gain < 10.0) {
      /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem' incorporates:
       *  ActionPort: '<S16>/Action Port'
       */
      ACC_IfActionSubsystem(ACC_P.Constant_Value_ei, ACC_P.Constant2_Value,
                            &ACC_B.Merge, &rtb_Merge1);

      /* End of Outputs for SubSystem: '<S4>/If Action Subsystem' */
    } else if (ACC_B.Gain < 50.0) {
      /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S17>/Action Port'
       */
      ACC_IfActionSubsystem(ACC_B.PulseGenerator, ACC_P.Constant3_Value,
                            &ACC_B.Merge, &rtb_Merge1);

      /* End of Outputs for SubSystem: '<S4>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S18>/Action Port'
       */
      ACC_IfActionSubsystem(ACC_P.Constant1_Value, 0.0, &ACC_B.Merge,
                            &rtb_Merge1);

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
    /* RateTransition generated from: '<S2>/Function-Call Subsystem4' */
    ACC_B.TmpRTBAtFunctionCallSubsystem4O =
      ACC_DW.TmpRTBAtFunctionCallSubsystem_e;
  } else {
    /* RateTransition generated from: '<S2>/Function-Call Subsystem4' */
    ACC_B.TmpRTBAtFunctionCallSubsystem4O =
      ACC_DW.TmpRTBAtFunctionCallSubsystem4O;
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
    /* RateTransition generated from: '<S2>/Function-Call Subsystem6' */
    ACC_B.TmpRTBAtFunctionCallSubsystem6O =
      ACC_DW.TmpRTBAtFunctionCallSubsystem_a;
  } else {
    /* RateTransition generated from: '<S2>/Function-Call Subsystem6' */
    ACC_B.TmpRTBAtFunctionCallSubsystem6O =
      ACC_DW.TmpRTBAtFunctionCallSubsystem6O;
  }

  ACC_DW.TmpRTBAtFunctionCallSubsyste_ff = -1;

  /* End of RateTransition generated from: '<S2>/Function-Call Subsystem6' */

  /* Chart: '<S2>/Chart' */
  if (ACC_DW.is_active_c3_ACC == 0U) {
    ACC_DW.is_active_c3_ACC = 1U;
    ACC_DW.is_c3_ACC = ACC_IN_AccOff;
    ACC_DW.v1 = ACC_B.TmpRTBAtFunctionCallSubsystem4O;
    ACC_DW.v2 = ACC_B.TmpRTBAtFunctionCallSubsystem6O;

    /* RateTransition: '<S2>/Rate Transition' */
    ACC_B.RateTransition = 0.0;
  } else {
    switch (ACC_DW.is_c3_ACC) {
     case ACC_IN_AccOff:
      if (ACC_DW.v1 != ACC_B.TmpRTBAtFunctionCallSubsystem4O) {
        ACC_DW.is_c3_ACC = ACC_IN_AccStandby;
        ACC_DW.v1 = ACC_B.TmpRTBAtFunctionCallSubsystem4O;
        ACC_DW.v2 = ACC_B.TmpRTBAtFunctionCallSubsystem6O;

        /* RateTransition: '<S2>/Rate Transition' */
        ACC_B.RateTransition = 1.0;
      } else {
        ACC_DW.v1 = ACC_B.TmpRTBAtFunctionCallSubsystem4O;
        ACC_DW.v2 = ACC_B.TmpRTBAtFunctionCallSubsystem6O;

        /* RateTransition: '<S2>/Rate Transition' */
        ACC_B.RateTransition = 0.0;
      }
      break;

     case ACC_IN_AccOn:
      if ((ACC_DW.v1 != ACC_B.TmpRTBAtFunctionCallSubsystem4O) || (ACC_DW.v2 !=
           ACC_B.TmpRTBAtFunctionCallSubsystem6O)) {
        ACC_DW.is_c3_ACC = ACC_IN_AccOff;
        ACC_DW.v1 = ACC_B.TmpRTBAtFunctionCallSubsystem4O;
        ACC_DW.v2 = ACC_B.TmpRTBAtFunctionCallSubsystem6O;

        /* RateTransition: '<S2>/Rate Transition' */
        ACC_B.RateTransition = 0.0;
      } else {
        ACC_DW.v1 = ACC_B.TmpRTBAtFunctionCallSubsystem4O;
        ACC_DW.v2 = ACC_B.TmpRTBAtFunctionCallSubsystem6O;

        /* RateTransition: '<S2>/Rate Transition' */
        ACC_B.RateTransition = 2.0;
      }
      break;

     default:
      /* case IN_AccStandby: */
      if (ACC_DW.v2 != ACC_B.TmpRTBAtFunctionCallSubsystem6O) {
        ACC_DW.is_c3_ACC = ACC_IN_AccOff;
        ACC_DW.v1 = ACC_B.TmpRTBAtFunctionCallSubsystem4O;
        ACC_DW.v2 = ACC_B.TmpRTBAtFunctionCallSubsystem6O;

        /* RateTransition: '<S2>/Rate Transition' */
        ACC_B.RateTransition = 0.0;
      } else if (ACC_DW.v1 != ACC_B.TmpRTBAtFunctionCallSubsystem4O) {
        ACC_DW.is_c3_ACC = ACC_IN_AccOn;
        ACC_DW.v1 = ACC_B.TmpRTBAtFunctionCallSubsystem4O;
        ACC_DW.v2 = ACC_B.TmpRTBAtFunctionCallSubsystem6O;

        /* RateTransition: '<S2>/Rate Transition' */
        ACC_B.RateTransition = 2.0;
      } else {
        ACC_DW.v1 = ACC_B.TmpRTBAtFunctionCallSubsystem4O;
        ACC_DW.v2 = ACC_B.TmpRTBAtFunctionCallSubsystem6O;

        /* RateTransition: '<S2>/Rate Transition' */
        ACC_B.RateTransition = 1.0;
      }
      break;
    }
  }

  /* End of Chart: '<S2>/Chart' */

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant1'
   */
  if (ACC_B.RateTransition != 0.0) {
    speed = ACC_B.Merge;
  } else {
    speed = ACC_P.Constant1_Value;
  }

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
  if (ACC_M->Timing.TaskCounters.TID[2] == 0) {
    /* DiscretePulseGenerator: '<S2>/Pulse Generator6' */
    ACC_B.PulseGenerator6 = (ACC_DW.clockTickCounter_g <
      ACC_P.PulseGenerator6_Duty) && (ACC_DW.clockTickCounter_g >= 0L) ?
      ACC_P.PulseGenerator6_Amp : 0.0;

    /* DiscretePulseGenerator: '<S2>/Pulse Generator6' */
    if (ACC_DW.clockTickCounter_g >= ACC_P.PulseGenerator6_Period - 1.0) {
      ACC_DW.clockTickCounter_g = 0L;
    } else {
      ACC_DW.clockTickCounter_g++;
    }
  }

  if (ACC_M->Timing.TaskCounters.TID[3] == 0) {
    /* DiscretePulseGenerator: '<S2>/Pulse Generator7' */
    ACC_B.PulseGenerator7 = (ACC_DW.clockTickCounter_n <
      ACC_P.PulseGenerator7_Duty) && (ACC_DW.clockTickCounter_n >= 0L) ?
      ACC_P.PulseGenerator7_Amp : 0.0;

    /* DiscretePulseGenerator: '<S2>/Pulse Generator7' */
    if (ACC_DW.clockTickCounter_n >= ACC_P.PulseGenerator7_Period - 1.0) {
      ACC_DW.clockTickCounter_n = 0L;
    } else {
      ACC_DW.clockTickCounter_n++;
    }
  }

  /* If: '<S2>/If5' */
  if (ACC_B.RateTransition == 1.0) {
    /* Outputs for IfAction SubSystem: '<S2>/ACC standby2' incorporates:
     *  ActionPort: '<S8>/ACC standby'
     */
    /* SignalConversion generated from: '<S8>/In1' */
    rtb_Merge3 = ACC_B.PulseGenerator6;

    /* End of Outputs for SubSystem: '<S2>/ACC standby2' */

    /* Update for IfAction SubSystem: '<S2>/ACC standby2' incorporates:
     *  ActionPort: '<S8>/ACC standby'
     */
    /* Update for If: '<S2>/If5' */
    srUpdateBC(ACC_DW.ACCstandby2_SubsysRanBC);

    /* End of Update for SubSystem: '<S2>/ACC standby2' */
  } else if (ACC_B.RateTransition == 2.0) {
    /* Outputs for IfAction SubSystem: '<S2>/ACC on2' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* SignalConversion generated from: '<S7>/Out1' incorporates:
     *  Constant: '<S7>/Constant'
     */
    rtb_Merge3 = ACC_P.Constant_Value_b;

    /* End of Outputs for SubSystem: '<S2>/ACC on2' */

    /* Update for IfAction SubSystem: '<S2>/ACC on2' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Update for If: '<S2>/If5' */
    srUpdateBC(ACC_DW.ACCon2_SubsysRanBC);

    /* End of Update for SubSystem: '<S2>/ACC on2' */
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/ACC off5' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* SignalConversion generated from: '<S6>/In1' */
    rtb_Merge3 = ACC_B.PulseGenerator7;

    /* End of Outputs for SubSystem: '<S2>/ACC off5' */

    /* Update for IfAction SubSystem: '<S2>/ACC off5' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Update for If: '<S2>/If5' */
    srUpdateBC(ACC_DW.ACCoff5_SubsysRanBC);

    /* End of Update for SubSystem: '<S2>/ACC off5' */
  }

  /* End of If: '<S2>/If5' */

  /* MATLABSystem: '<Root>/Analog Input' */
  if (ACC_DW.obj.SampleTime != ACC_P.AnalogInput_SampleTime) {
    ACC_DW.obj.SampleTime = ACC_P.AnalogInput_SampleTime;
  }

  ACC_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(62UL);
  MW_AnalogInSingle_ReadResult(ACC_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
    &b_varargout_1, MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<S3>/Data Type Conversion2' incorporates:
   *  Gain: '<S3>/Gain'
   *  MATLABSystem: '<Root>/Analog Input'
   * */
  ACC_B.DataTypeConversion2 = (real_T)((uint32_T)ACC_P.Gain_Gain_f *
    b_varargout_1) * 7.62939453125E-6;

  /* Chart: '<S3>/Chart' */
  if (ACC_DW.is_active_c1_ACC == 0U) {
    ACC_DW.is_active_c1_ACC = 1U;
    ACC_DW.is_c1_ACC = ACC_IN_AccOff;
    ACC_DW.a = ACC_B.DataTypeConversion2;
    speed = 0.0;
  } else {
    switch (ACC_DW.is_c1_ACC) {
     case ACC_IN_AccOff:
      if (ACC_B.RateTransition == 1.0) {
        ACC_DW.is_c1_ACC = ACC_IN_AccStandby;
        speed = ACC_DW.a;
      } else {
        ACC_DW.a = ACC_B.DataTypeConversion2;
        speed = 0.0;
      }
      break;

     case ACC_IN_AccOn:
      if (ACC_B.RateTransition == 0.0) {
        ACC_DW.is_c1_ACC = ACC_IN_AccOff;
        ACC_DW.a = ACC_B.DataTypeConversion2;
        speed = 0.0;
      } else {
        speed = ACC_B.DataTypeConversion2;
      }
      break;

     default:
      /* case IN_AccStandby: */
      if (ACC_B.RateTransition == 2.0) {
        ACC_DW.is_c1_ACC = ACC_IN_AccOn;
        speed = ACC_B.DataTypeConversion2;
      } else if (ACC_B.RateTransition == 0.0) {
        ACC_DW.is_c1_ACC = ACC_IN_AccOff;
        ACC_DW.a = ACC_B.DataTypeConversion2;
        speed = 0.0;
      } else {
        speed = ACC_DW.a;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/Chart' */
  if (ACC_M->Timing.TaskCounters.TID[1] == 0) {
    /* If: '<S3>/If' */
    if (rtb_Merge1 == 1.0) {
      /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem' incorporates:
       *  ActionPort: '<S13>/Action Port'
       */
      /* SignalConversion generated from: '<S13>/speed' incorporates:
       *  Constant: '<S3>/Constant1'
       *  Product: '<S3>/Divide'
       */
      rtb_Merge_o = speed / ACC_P.Constant1_Value_j;

      /* End of Outputs for SubSystem: '<S3>/If Action Subsystem' */

      /* Update for IfAction SubSystem: '<S3>/If Action Subsystem' incorporates:
       *  ActionPort: '<S13>/Action Port'
       */
      /* Update for If: '<S3>/If' */
      srUpdateBC(ACC_DW.IfActionSubsystem_SubsysRanBC_m);

      /* End of Update for SubSystem: '<S3>/If Action Subsystem' */
    } else if (rtb_Merge1 == 2.0) {
      /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      /* SignalConversion generated from: '<S14>/speed' incorporates:
       *  Constant: '<S3>/Constant'
       */
      rtb_Merge_o = ACC_P.Constant_Value_g;

      /* End of Outputs for SubSystem: '<S3>/If Action Subsystem1' */

      /* Update for IfAction SubSystem: '<S3>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      /* Update for If: '<S3>/If' */
      srUpdateBC(ACC_DW.IfActionSubsystem1_SubsysRanB_g);

      /* End of Update for SubSystem: '<S3>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      /* SignalConversion generated from: '<S15>/speed' */
      rtb_Merge_o = speed;

      /* End of Outputs for SubSystem: '<S3>/If Action Subsystem2' */

      /* Update for IfAction SubSystem: '<S3>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      /* Update for If: '<S3>/If' */
      srUpdateBC(ACC_DW.IfActionSubsystem2_SubsysRanB_b);

      /* End of Update for SubSystem: '<S3>/If Action Subsystem2' */
    }

    /* End of If: '<S3>/If' */
  }

  if (ACC_M->Timing.TaskCounters.TID[3] == 0) {
    /* DiscretePulseGenerator: '<S5>/Pulse Generator' */
    ACC_B.PulseGenerator_i = (ACC_DW.clockTickCounter_f <
      ACC_P.PulseGenerator_Duty_n) && (ACC_DW.clockTickCounter_f >= 0L) ?
      ACC_P.PulseGenerator_Amp_l : 0.0;

    /* DiscretePulseGenerator: '<S5>/Pulse Generator' */
    if (ACC_DW.clockTickCounter_f >= ACC_P.PulseGenerator_Period_p - 1.0) {
      ACC_DW.clockTickCounter_f = 0L;
    } else {
      ACC_DW.clockTickCounter_f++;
    }
  }

  if (ACC_M->Timing.TaskCounters.TID[2] == 0) {
    /* DiscretePulseGenerator: '<S5>/Pulse Generator1' */
    ACC_B.PulseGenerator1 = (ACC_DW.clockTickCounter_p <
      ACC_P.PulseGenerator1_Duty) && (ACC_DW.clockTickCounter_p >= 0L) ?
      ACC_P.PulseGenerator1_Amp : 0.0;

    /* DiscretePulseGenerator: '<S5>/Pulse Generator1' */
    if (ACC_DW.clockTickCounter_p >= ACC_P.PulseGenerator1_Period - 1.0) {
      ACC_DW.clockTickCounter_p = 0L;
    } else {
      ACC_DW.clockTickCounter_p++;
    }
  }

  if (ACC_M->Timing.TaskCounters.TID[1] == 0) {
    /* If: '<S5>/If' */
    if (rtb_Merge1 == 1.0) {
      /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem' incorporates:
       *  ActionPort: '<S19>/Action Port'
       */
      /* SignalConversion generated from: '<S19>/In1' */
      rtb_Merge1 = ACC_B.PulseGenerator1;

      /* End of Outputs for SubSystem: '<S5>/If Action Subsystem' */

      /* Update for IfAction SubSystem: '<S5>/If Action Subsystem' incorporates:
       *  ActionPort: '<S19>/Action Port'
       */
      /* Update for If: '<S5>/If' */
      srUpdateBC(ACC_DW.IfActionSubsystem_SubsysRanBC);

      /* End of Update for SubSystem: '<S5>/If Action Subsystem' */
    } else if (rtb_Merge1 == 2.0) {
      /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      /* SignalConversion generated from: '<S20>/In1' */
      rtb_Merge1 = ACC_B.PulseGenerator_i;

      /* End of Outputs for SubSystem: '<S5>/If Action Subsystem1' */

      /* Update for IfAction SubSystem: '<S5>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      /* Update for If: '<S5>/If' */
      srUpdateBC(ACC_DW.IfActionSubsystem1_SubsysRanBC);

      /* End of Update for SubSystem: '<S5>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      /* SignalConversion generated from: '<S21>/In1' incorporates:
       *  Constant: '<S5>/Constant'
       */
      rtb_Merge1 = ACC_P.Constant_Value_c;

      /* End of Outputs for SubSystem: '<S5>/If Action Subsystem2' */

      /* Update for IfAction SubSystem: '<S5>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      /* Update for If: '<S5>/If' */
      srUpdateBC(ACC_DW.IfActionSubsystem2_SubsysRanBC);

      /* End of Update for SubSystem: '<S5>/If Action Subsystem2' */
    }

    /* End of If: '<S5>/If' */
    /* MATLABSystem: '<Root>/PWM' */
    ACC_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

    /* DataTypeConversion: '<S3>/Data Type Conversion1' */
    speed = floor(rtb_Merge_o);
    if (rtIsNaN(speed) || rtIsInf(speed)) {
      speed = 0.0;
    } else {
      speed = fmod(speed, 256.0);
    }

    /* MATLABSystem: '<Root>/PWM' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion1'
     */
    MW_PWM_SetDutyCycle(ACC_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE, (real_T)(speed <
      0.0 ? (int16_T)(uint8_T)-(int8_T)(uint8_T)-speed : (int16_T)(uint8_T)speed));

    /* MATLABSystem: '<Root>/Digital Output1' */
    speed = rt_roundd_snf(rtb_Merge1);
    if (speed < 256.0) {
      if (speed >= 0.0) {
        tmp = (uint8_T)speed;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    writeDigitalPin(26, tmp);

    /* End of MATLABSystem: '<Root>/Digital Output1' */
  }

  /* MATLABSystem: '<Root>/Digital Output4' */
  speed = rt_roundd_snf(rtb_Merge3);
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

  /* End of MATLABSystem: '<Root>/Digital Output4' */
  {                                    /* Sample time: [0.01s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((ACC_M->Timing.clockTick0 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(0,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  if (ACC_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.1s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((ACC_M->Timing.clockTick1 * 10) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  if (ACC_M->Timing.TaskCounters.TID[2] == 0) {/* Sample time: [0.2s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((ACC_M->Timing.clockTick2 * 20) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(2,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  if (ACC_M->Timing.TaskCounters.TID[3] == 0) {/* Sample time: [1.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((ACC_M->Timing.clockTick3 * 100) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(3,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ACC_M->Timing.taskTime0 =
    ((time_T)(++ACC_M->Timing.clockTick0)) * ACC_M->Timing.stepSize0;
  if (ACC_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.1, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    ACC_M->Timing.clockTick1++;
  }

  if (ACC_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.2s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.2, which is the step size
     * of the task. Size of "clockTick2" ensures timer will not overflow during the
     * application lifespan selected.
     */
    ACC_M->Timing.clockTick2++;
  }

  if (ACC_M->Timing.TaskCounters.TID[3] == 0) {
    /* Update absolute timer for sample time: [1.0s, 0.0s] */
    /* The "clockTick3" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 1.0, which is the step size
     * of the task. Size of "clockTick3" ensures timer will not overflow during the
     * application lifespan selected.
     */
    ACC_M->Timing.clockTick3++;
  }

  switch (ACC_M->Timing.rtmDbBufReadBuf4) {
   case 0:
    ACC_M->Timing.rtmDbBufWriteBuf4 = 1;
    break;

   case 1:
    ACC_M->Timing.rtmDbBufWriteBuf4 = 0;
    break;

   default:
    ACC_M->Timing.rtmDbBufWriteBuf4 = !ACC_M->Timing.rtmDbBufLastBufWr4;
    break;
  }

  ACC_M->Timing.rtmDbBufClockTick4[ACC_M->Timing.rtmDbBufWriteBuf4] =
    ACC_M->Timing.clockTick0;
  ACC_M->Timing.rtmDbBufLastBufWr4 = ACC_M->Timing.rtmDbBufWriteBuf4;
  ACC_M->Timing.rtmDbBufWriteBuf4 = 0xFF;
  switch (ACC_M->Timing.rtmDbBufReadBuf5) {
   case 0:
    ACC_M->Timing.rtmDbBufWriteBuf5 = 1;
    break;

   case 1:
    ACC_M->Timing.rtmDbBufWriteBuf5 = 0;
    break;

   default:
    ACC_M->Timing.rtmDbBufWriteBuf5 = !ACC_M->Timing.rtmDbBufLastBufWr5;
    break;
  }

  ACC_M->Timing.rtmDbBufClockTick5[ACC_M->Timing.rtmDbBufWriteBuf5] =
    ACC_M->Timing.clockTick0;
  ACC_M->Timing.rtmDbBufLastBufWr5 = ACC_M->Timing.rtmDbBufWriteBuf5;
  ACC_M->Timing.rtmDbBufWriteBuf5 = 0xFF;
  rate_scheduler();
}

/* Model initialize function */
void ACC_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(ACC_M, -1);
  ACC_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  ACC_M->Sizes.checksums[0] = (1188625213U);
  ACC_M->Sizes.checksums[1] = (1553614756U);
  ACC_M->Sizes.checksums[2] = (947132226U);
  ACC_M->Sizes.checksums[3] = (4158850794U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[23];
    ACC_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = (sysRanDType *)&ACC_DW.ACCoff5_SubsysRanBC;
    systemRan[7] = (sysRanDType *)&ACC_DW.ACCon2_SubsysRanBC;
    systemRan[8] = (sysRanDType *)&ACC_DW.ACCstandby2_SubsysRanBC;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = (sysRanDType *)&ACC_DW.FunctionCallSubsystem4_SubsysRa;
    systemRan[11] = (sysRanDType *)&ACC_DW.FunctionCallSubsystem6_SubsysRa;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = (sysRanDType *)&ACC_DW.IfActionSubsystem_SubsysRanBC_m;
    systemRan[14] = (sysRanDType *)&ACC_DW.IfActionSubsystem1_SubsysRanB_g;
    systemRan[15] = (sysRanDType *)&ACC_DW.IfActionSubsystem2_SubsysRanB_b;
    systemRan[16] = (sysRanDType *)
      &ACC_DW.IfActionSubsystem_i.IfActionSubsystem_SubsysRanBC;
    systemRan[17] = (sysRanDType *)
      &ACC_DW.IfActionSubsystem1_m.IfActionSubsystem_SubsysRanBC;
    systemRan[18] = (sysRanDType *)
      &ACC_DW.IfActionSubsystem2_j.IfActionSubsystem_SubsysRanBC;
    systemRan[19] = (sysRanDType *)&ACC_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[20] = (sysRanDType *)&ACC_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[21] = (sysRanDType *)&ACC_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[22] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ACC_M->extModeInfo,
      &ACC_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ACC_M->extModeInfo, ACC_M->Sizes.checksums);
    rteiSetTPtr(ACC_M->extModeInfo, rtmGetTPtr(ACC_M));
  }

  ACC_M->Timing.rtmDbBufReadBuf4 = 0xFF;
  ACC_M->Timing.rtmDbBufWriteBuf4 = 0xFF;
  ACC_M->Timing.rtmDbBufLastBufWr4 = 0;
  ACC_M->Timing.rtmDbBufReadBuf5 = 0xFF;
  ACC_M->Timing.rtmDbBufWriteBuf5 = 0xFF;
  ACC_M->Timing.rtmDbBufLastBufWr5 = 0;

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

  /* Asynchronous task (with no priority assigned)
   * reads absolute time */
  switch (ACC_M->Timing.rtmDbBufWriteBuf4) {
   case 0:
    ACC_M->Timing.rtmDbBufReadBuf4 = 1;
    break;

   case 1:
    ACC_M->Timing.rtmDbBufReadBuf4 = 0;
    break;

   default:
    ACC_M->Timing.rtmDbBufReadBuf4 = ACC_M->Timing.rtmDbBufLastBufWr4;
    break;
  }

  ACC_M->Timing.clockTick4 = ACC_M->Timing.rtmDbBufClockTick4
    [ACC_M->Timing.rtmDbBufReadBuf4];
  ACC_M->Timing.rtmDbBufReadBuf4 = 0xFF;

  /* InitializeConditions for Delay: '<S10>/Delay' */
  ACC_B.Add_j = ACC_P.Delay_InitialCondition;

  /* SystemInitialize for Sum: '<S10>/Add' incorporates:
   *  Outport: '<S10>/sw1'
   */
  ACC_B.Add_j = ACC_P.sw1_Y0;

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(20), &MW_ISR_20, FALLING);

  /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt5' */

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt6' incorporates:
   *  SubSystem: '<S2>/Function-Call Subsystem6'
   */

  /* System initialize for function-call system: '<S2>/Function-Call Subsystem6' */

  /* Asynchronous task (with no priority assigned)
   * reads absolute time */
  switch (ACC_M->Timing.rtmDbBufWriteBuf5) {
   case 0:
    ACC_M->Timing.rtmDbBufReadBuf5 = 1;
    break;

   case 1:
    ACC_M->Timing.rtmDbBufReadBuf5 = 0;
    break;

   default:
    ACC_M->Timing.rtmDbBufReadBuf5 = ACC_M->Timing.rtmDbBufLastBufWr5;
    break;
  }

  ACC_M->Timing.clockTick5 = ACC_M->Timing.rtmDbBufClockTick5
    [ACC_M->Timing.rtmDbBufReadBuf5];
  ACC_M->Timing.rtmDbBufReadBuf5 = 0xFF;

  /* InitializeConditions for Delay: '<S11>/Delay' */
  ACC_B.Add = ACC_P.Delay_InitialCondition_d;

  /* SystemInitialize for Sum: '<S11>/Add' incorporates:
   *  Outport: '<S11>/sw2'
   */
  ACC_B.Add = ACC_P.sw2_Y0;

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(21), &MW_ISR_21, FALLING);

  /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt6' */

  /* Start for MATLABSystem: '<Root>/Ultrasonic Sensor' */
  ACC_DW.obj_i.isInitialized = 1L;
  MW_UltrasonicSetup(50, 51);
  ACC_DW.obj_i.TunablePropsChanged = false;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  ACC_DW.obj_n.matlabCodegenIsDeleted = false;
  ACC_DW.obj_n.isInitialized = 1L;
  digitalIOSetup(23, 1);
  ACC_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  ACC_DW.obj.matlabCodegenIsDeleted = false;
  ACC_DW.obj.SampleTime = ACC_P.AnalogInput_SampleTime;
  ACC_DW.obj.isInitialized = 1L;
  ACC_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(62UL);
  ACC_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM' */
  ACC_DW.obj_f.matlabCodegenIsDeleted = false;
  ACC_DW.obj_f.isInitialized = 1L;
  ACC_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
  ACC_DW.obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  ACC_DW.obj_g.matlabCodegenIsDeleted = false;
  ACC_DW.obj_g.isInitialized = 1L;
  digitalIOSetup(26, 1);
  ACC_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output4' */
  ACC_DW.obj_h.matlabCodegenIsDeleted = false;
  ACC_DW.obj_h.isInitialized = 1L;
  digitalIOSetup(22, 1);
  ACC_DW.obj_h.isSetupComplete = true;
}

/* Model terminate function */
void ACC_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!ACC_DW.obj_n.matlabCodegenIsDeleted) {
    ACC_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

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
  if (!ACC_DW.obj_f.matlabCodegenIsDeleted) {
    ACC_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((ACC_DW.obj_f.isInitialized == 1L) && ACC_DW.obj_f.isSetupComplete) {
      ACC_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(ACC_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      ACC_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(ACC_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!ACC_DW.obj_g.matlabCodegenIsDeleted) {
    ACC_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output4' */
  if (!ACC_DW.obj_h.matlabCodegenIsDeleted) {
    ACC_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output4' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
