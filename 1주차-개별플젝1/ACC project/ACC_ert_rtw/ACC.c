/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ACC.c
 *
 * Code generated for Simulink model 'ACC'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Feb  2 17:20:40 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ACC.h"
#include "ACC_private.h"
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <float.h>

/* Block signals (default storage) */
B_ACC_T ACC_B;

/* Block states (default storage) */
DW_ACC_T ACC_DW;

/* Real-time model */
static RT_MODEL_ACC_T ACC_M_;
RT_MODEL_ACC_T *const ACC_M = &ACC_M_;
static void rate_scheduler(void);

/* Callback for Hardware Interrupt Block: '<Root>/External Interrupt1' */
void MW_ISR_20(void)
{
  /* Call the system: <Root>/Function-Call Subsystem */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(ACC_DW.FunctionCallSubsystem_SubsysRan);

    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt1' */

    /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */

    /* Asynchronous task (with no priority assigned)
     * reads absolute time */
    switch (ACC_M->Timing.rtmDbBufWriteBuf3) {
     case 0:
      ACC_M->Timing.rtmDbBufReadBuf3 = 1;
      break;

     case 1:
      ACC_M->Timing.rtmDbBufReadBuf3 = 0;
      break;

     default:
      ACC_M->Timing.rtmDbBufReadBuf3 = ACC_M->Timing.rtmDbBufLastBufWr3;
      break;
    }

    ACC_M->Timing.clockTick3 = ACC_M->Timing.rtmDbBufClockTick3
      [ACC_M->Timing.rtmDbBufReadBuf3];
    ACC_M->Timing.rtmDbBufReadBuf3 = 0xFF;

    /* Math: '<S5>/Rem' incorporates:
     *  Constant: '<S5>/Constant'
     *  Constant: '<S5>/Constant1'
     *  Delay: '<S5>/Delay'
     *  Sum: '<S5>/Add'
     */
    ACC_DW.Delay_DSTATE = rt_remd_snf(ACC_P.Constant1_Value +
      ACC_DW.Delay_DSTATE, ACC_P.Constant_Value);

    /* SignalConversion generated from: '<S5>/Out1' incorporates:
     *  Constant: '<S5>/Constant2'
     */
    ACC_B.OutportBufferForOut1_b = ACC_P.Constant2_Value;
    ACC_DW.FunctionCallSubsystem_SubsysRan = 4;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt1' */

    /* RateTransition: '<Root>/Rate Transition1' incorporates:
     *  Delay: '<S5>/Delay'
     */
    switch (ACC_DW.RateTransition1_read_buf) {
     case 0:
      ACC_DW.RateTransition1_write_buf = 1;
      break;

     case 1:
      ACC_DW.RateTransition1_write_buf = 0;
      break;

     default:
      ACC_DW.RateTransition1_write_buf = (int8_T)
        (ACC_DW.RateTransition1_last_buf_wr == 0);
      break;
    }

    if (ACC_DW.RateTransition1_write_buf != 0) {
      ACC_DW.RateTransition1_Buffer1 = ACC_DW.Delay_DSTATE;
    } else {
      ACC_DW.RateTransition1_Buffer0 = ACC_DW.Delay_DSTATE;
    }

    ACC_DW.RateTransition1_last_buf_wr = ACC_DW.RateTransition1_write_buf;
    ACC_DW.RateTransition1_write_buf = -1;

    /* End of RateTransition: '<Root>/Rate Transition1' */

    /* RateTransition generated from: '<Root>/Function-Call Subsystem' */
    switch (ACC_DW.TmpRTBAtFunctionCallSubsystem_a) {
     case 0:
      ACC_DW.TmpRTBAtFunctionCallSubsystem_i = 1;
      break;

     case 1:
      ACC_DW.TmpRTBAtFunctionCallSubsystem_i = 0;
      break;

     default:
      ACC_DW.TmpRTBAtFunctionCallSubsystem_i = (int8_T)
        (ACC_DW.TmpRTBAtFunctionCallSubsystem_e == 0);
      break;
    }

    if (ACC_DW.TmpRTBAtFunctionCallSubsystem_i != 0) {
      ACC_DW.TmpRTBAtFunctionCallSubsystem_h = ACC_B.OutportBufferForOut1_b;
    } else {
      ACC_DW.TmpRTBAtFunctionCallSubsystemOu = ACC_B.OutportBufferForOut1_b;
    }

    ACC_DW.TmpRTBAtFunctionCallSubsystem_e =
      ACC_DW.TmpRTBAtFunctionCallSubsystem_i;
    ACC_DW.TmpRTBAtFunctionCallSubsystem_i = -1;

    /* End of RateTransition generated from: '<Root>/Function-Call Subsystem' */
  }

  extmodeEvent(3,((ACC_M->Timing.clockTick3) * 0.01));
}

/* Callback for Hardware Interrupt Block: '<Root>/External Interrupt2' */
void MW_ISR_21(void)
{
  /* Call the system: <Root>/Function-Call Subsystem5 */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(ACC_DW.FunctionCallSubsystem5_SubsysRa);

    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt2' */

    /* Output and update for function-call system: '<Root>/Function-Call Subsystem5' */

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

    /* SignalConversion generated from: '<S6>/Out1' incorporates:
     *  Constant: '<S6>/Constant'
     */
    ACC_B.OutportBufferForOut1 = ACC_P.Constant_Value_o;
    ACC_DW.FunctionCallSubsystem5_SubsysRa = 4;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt2' */

    /* RateTransition generated from: '<Root>/Function-Call Subsystem5' */
    switch (ACC_DW.TmpRTBAtFunctionCallSubsyste_h4) {
     case 0:
      ACC_DW.TmpRTBAtFunctionCallSubsyste_ag = 1;
      break;

     case 1:
      ACC_DW.TmpRTBAtFunctionCallSubsyste_ag = 0;
      break;

     default:
      ACC_DW.TmpRTBAtFunctionCallSubsyste_ag = (int8_T)
        (ACC_DW.TmpRTBAtFunctionCallSubsystem_f == 0);
      break;
    }

    if (ACC_DW.TmpRTBAtFunctionCallSubsyste_ag != 0) {
      ACC_DW.TmpRTBAtFunctionCallSubsystem_c = ACC_B.OutportBufferForOut1;
    } else {
      ACC_DW.TmpRTBAtFunctionCallSubsystem5O = ACC_B.OutportBufferForOut1;
    }

    ACC_DW.TmpRTBAtFunctionCallSubsystem_f =
      ACC_DW.TmpRTBAtFunctionCallSubsyste_ag;
    ACC_DW.TmpRTBAtFunctionCallSubsyste_ag = -1;

    /* End of RateTransition generated from: '<Root>/Function-Call Subsystem5' */
  }

  extmodeEvent(4,((ACC_M->Timing.clockTick4) * 0.01));
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
  if ((ACC_M->Timing.TaskCounters.TID[1]) > 19) {/* Sample time: [0.2s, 0.0s] */
    ACC_M->Timing.TaskCounters.TID[1] = 0;
  }

  (ACC_M->Timing.TaskCounters.TID[2])++;
  if ((ACC_M->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [1.0s, 0.0s] */
    ACC_M->Timing.TaskCounters.TID[2] = 0;
  }
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      q = ceil(u1);
    } else {
      q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != q)) {
      q = fabs(u0 / u1);
      if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
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
  real_T rtb_RateTransition1;
  real_T rtb_TmpRTBAtFunctionCallSubsy_e;
  real_T rtb_TmpRTBAtFunctionCallSubsyst;
  uint8_T tmp;

  /* Reset subsysRan breadcrumbs */
  srClearBC(ACC_DW.ACCoff1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ACC_DW.ACCstandby_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ACC_DW.ACCon_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ACC_DW.ACCoff2_SubsysRanBC);

  /* RateTransition: '<Root>/Rate Transition1' */
  switch (ACC_DW.RateTransition1_write_buf) {
   case 0:
    ACC_DW.RateTransition1_read_buf = 1;
    break;

   case 1:
    ACC_DW.RateTransition1_read_buf = 0;
    break;

   default:
    ACC_DW.RateTransition1_read_buf = ACC_DW.RateTransition1_last_buf_wr;
    break;
  }

  if (ACC_DW.RateTransition1_read_buf != 0) {
    rtb_RateTransition1 = ACC_DW.RateTransition1_Buffer1;
  } else {
    rtb_RateTransition1 = ACC_DW.RateTransition1_Buffer0;
  }

  ACC_DW.RateTransition1_read_buf = -1;

  /* End of RateTransition: '<Root>/Rate Transition1' */

  /* RateTransition generated from: '<Root>/Function-Call Subsystem' */
  switch (ACC_DW.TmpRTBAtFunctionCallSubsystem_i) {
   case 0:
    ACC_DW.TmpRTBAtFunctionCallSubsystem_a = 1;
    break;

   case 1:
    ACC_DW.TmpRTBAtFunctionCallSubsystem_a = 0;
    break;

   default:
    ACC_DW.TmpRTBAtFunctionCallSubsystem_a =
      ACC_DW.TmpRTBAtFunctionCallSubsystem_e;
    break;
  }

  if (ACC_DW.TmpRTBAtFunctionCallSubsystem_a != 0) {
    rtb_TmpRTBAtFunctionCallSubsyst = ACC_DW.TmpRTBAtFunctionCallSubsystem_h;
  } else {
    rtb_TmpRTBAtFunctionCallSubsyst = ACC_DW.TmpRTBAtFunctionCallSubsystemOu;
  }

  ACC_DW.TmpRTBAtFunctionCallSubsystem_a = -1;

  /* End of RateTransition generated from: '<Root>/Function-Call Subsystem' */
  /* RateTransition generated from: '<Root>/Function-Call Subsystem5' */
  switch (ACC_DW.TmpRTBAtFunctionCallSubsyste_ag) {
   case 0:
    ACC_DW.TmpRTBAtFunctionCallSubsyste_h4 = 1;
    break;

   case 1:
    ACC_DW.TmpRTBAtFunctionCallSubsyste_h4 = 0;
    break;

   default:
    ACC_DW.TmpRTBAtFunctionCallSubsyste_h4 =
      ACC_DW.TmpRTBAtFunctionCallSubsystem_f;
    break;
  }

  if (ACC_DW.TmpRTBAtFunctionCallSubsyste_h4 != 0) {
    rtb_TmpRTBAtFunctionCallSubsy_e = ACC_DW.TmpRTBAtFunctionCallSubsystem_c;
  } else {
    rtb_TmpRTBAtFunctionCallSubsy_e = ACC_DW.TmpRTBAtFunctionCallSubsystem5O;
  }

  ACC_DW.TmpRTBAtFunctionCallSubsyste_h4 = -1;

  /* End of RateTransition generated from: '<Root>/Function-Call Subsystem5' */
  if (ACC_M->Timing.TaskCounters.TID[1] == 0) {
    /* DiscretePulseGenerator: '<Root>/Pulse Generator1' */
    ACC_B.PulseGenerator1 = (ACC_DW.clockTickCounter <
      ACC_P.PulseGenerator1_Duty) && (ACC_DW.clockTickCounter >= 0L) ?
      ACC_P.PulseGenerator1_Amp : 0.0;

    /* DiscretePulseGenerator: '<Root>/Pulse Generator1' */
    if (ACC_DW.clockTickCounter >= ACC_P.PulseGenerator1_Period - 1.0) {
      ACC_DW.clockTickCounter = 0L;
    } else {
      ACC_DW.clockTickCounter++;
    }
  }

  if (ACC_M->Timing.TaskCounters.TID[2] == 0) {
    /* DiscretePulseGenerator: '<Root>/Pulse Generator2' */
    ACC_B.PulseGenerator2 = (ACC_DW.clockTickCounter_h <
      ACC_P.PulseGenerator2_Duty) && (ACC_DW.clockTickCounter_h >= 0L) ?
      ACC_P.PulseGenerator2_Amp : 0.0;

    /* DiscretePulseGenerator: '<Root>/Pulse Generator2' */
    if (ACC_DW.clockTickCounter_h >= ACC_P.PulseGenerator2_Period - 1.0) {
      ACC_DW.clockTickCounter_h = 0L;
    } else {
      ACC_DW.clockTickCounter_h++;
    }

    /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
    ACC_B.PulseGenerator = (ACC_DW.clockTickCounter_o <
      ACC_P.PulseGenerator_Duty) && (ACC_DW.clockTickCounter_o >= 0L) ?
      ACC_P.PulseGenerator_Amp : 0.0;

    /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
    if (ACC_DW.clockTickCounter_o >= ACC_P.PulseGenerator_Period - 1.0) {
      ACC_DW.clockTickCounter_o = 0L;
    } else {
      ACC_DW.clockTickCounter_o++;
    }
  }

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Math: '<Root>/Rem'
   *  Sum: '<Root>/Add'
   */
  if (rt_remd_snf(rtb_TmpRTBAtFunctionCallSubsyst +
                  rtb_TmpRTBAtFunctionCallSubsy_e, ACC_P.Constant2_Value_m) !=
      0.0) {
    rtb_TmpRTBAtFunctionCallSubsyst = ACC_P.Constant_Value_o3;
  } else {
    rtb_TmpRTBAtFunctionCallSubsyst = ACC_P.Constant1_Value_n;
  }

  /* If: '<Root>/If3' incorporates:
   *  Switch: '<Root>/Switch'
   */
  if (rtb_TmpRTBAtFunctionCallSubsyst == 1.0) {
    /* Outputs for IfAction SubSystem: '<Root>/ACC off1' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* Merge: '<Root>/Merge1' incorporates:
     *  SignalConversion generated from: '<S1>/In1'
     */
    ACC_B.Merge1 = ACC_B.PulseGenerator;

    /* End of Outputs for SubSystem: '<Root>/ACC off1' */

    /* Update for IfAction SubSystem: '<Root>/ACC off1' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* Update for If: '<Root>/If3' */
    srUpdateBC(ACC_DW.ACCoff1_SubsysRanBC);

    /* End of Update for SubSystem: '<Root>/ACC off1' */
  } else if (rtb_RateTransition1 == 1.0) {
    /* Outputs for IfAction SubSystem: '<Root>/ACC standby' incorporates:
     *  ActionPort: '<S4>/ACC standby'
     */
    /* Merge: '<Root>/Merge1' incorporates:
     *  SignalConversion generated from: '<S4>/In1'
     */
    ACC_B.Merge1 = ACC_B.PulseGenerator1;

    /* End of Outputs for SubSystem: '<Root>/ACC standby' */

    /* Update for IfAction SubSystem: '<Root>/ACC standby' incorporates:
     *  ActionPort: '<S4>/ACC standby'
     */
    /* Update for If: '<Root>/If3' */
    srUpdateBC(ACC_DW.ACCstandby_SubsysRanBC);

    /* End of Update for SubSystem: '<Root>/ACC standby' */
  } else if (rtb_RateTransition1 == 2.0) {
    /* Outputs for IfAction SubSystem: '<Root>/ACC on' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Merge: '<Root>/Merge1' incorporates:
     *  Constant: '<S3>/Constant'
     *  SignalConversion generated from: '<S3>/Out1'
     */
    ACC_B.Merge1 = ACC_P.Constant_Value_j;

    /* End of Outputs for SubSystem: '<Root>/ACC on' */

    /* Update for IfAction SubSystem: '<Root>/ACC on' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Update for If: '<Root>/If3' */
    srUpdateBC(ACC_DW.ACCon_SubsysRanBC);

    /* End of Update for SubSystem: '<Root>/ACC on' */
  } else {
    /* Outputs for IfAction SubSystem: '<Root>/ACC off2' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Merge: '<Root>/Merge1' incorporates:
     *  SignalConversion generated from: '<S2>/In1'
     */
    ACC_B.Merge1 = ACC_B.PulseGenerator2;

    /* End of Outputs for SubSystem: '<Root>/ACC off2' */

    /* Update for IfAction SubSystem: '<Root>/ACC off2' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Update for If: '<Root>/If3' */
    srUpdateBC(ACC_DW.ACCoff2_SubsysRanBC);

    /* End of Update for SubSystem: '<Root>/ACC off2' */
  }

  /* End of If: '<Root>/If3' */

  /* MATLABSystem: '<Root>/Digital Output2' */
  rtb_TmpRTBAtFunctionCallSubsyst = rt_roundd_snf(ACC_B.Merge1);
  if (rtb_TmpRTBAtFunctionCallSubsyst < 256.0) {
    if (rtb_TmpRTBAtFunctionCallSubsyst >= 0.0) {
      tmp = (uint8_T)rtb_TmpRTBAtFunctionCallSubsyst;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(22, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output2' */
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

  if (ACC_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.2s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((ACC_M->Timing.clockTick1 * 20) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  if (ACC_M->Timing.TaskCounters.TID[2] == 0) {/* Sample time: [1.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((ACC_M->Timing.clockTick2 * 100) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(2,currentTime);
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
    /* Update absolute timer for sample time: [0.2s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.2, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    ACC_M->Timing.clockTick1++;
  }

  if (ACC_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [1.0s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 1.0, which is the step size
     * of the task. Size of "clockTick2" ensures timer will not overflow during the
     * application lifespan selected.
     */
    ACC_M->Timing.clockTick2++;
  }

  switch (ACC_M->Timing.rtmDbBufReadBuf3) {
   case 0:
    ACC_M->Timing.rtmDbBufWriteBuf3 = 1;
    break;

   case 1:
    ACC_M->Timing.rtmDbBufWriteBuf3 = 0;
    break;

   default:
    ACC_M->Timing.rtmDbBufWriteBuf3 = !ACC_M->Timing.rtmDbBufLastBufWr3;
    break;
  }

  ACC_M->Timing.rtmDbBufClockTick3[ACC_M->Timing.rtmDbBufWriteBuf3] =
    ACC_M->Timing.clockTick0;
  ACC_M->Timing.rtmDbBufLastBufWr3 = ACC_M->Timing.rtmDbBufWriteBuf3;
  ACC_M->Timing.rtmDbBufWriteBuf3 = 0xFF;
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
  ACC_M->Sizes.checksums[0] = (3886780365U);
  ACC_M->Sizes.checksums[1] = (3121002092U);
  ACC_M->Sizes.checksums[2] = (3546985940U);
  ACC_M->Sizes.checksums[3] = (2877305563U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[10];
    ACC_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&ACC_DW.ACCoff1_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&ACC_DW.ACCoff2_SubsysRanBC;
    systemRan[3] = (sysRanDType *)&ACC_DW.ACCon_SubsysRanBC;
    systemRan[4] = (sysRanDType *)&ACC_DW.ACCstandby_SubsysRanBC;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = (sysRanDType *)&ACC_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[7] = (sysRanDType *)&ACC_DW.FunctionCallSubsystem5_SubsysRa;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ACC_M->extModeInfo,
      &ACC_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ACC_M->extModeInfo, ACC_M->Sizes.checksums);
    rteiSetTPtr(ACC_M->extModeInfo, rtmGetTPtr(ACC_M));
  }

  ACC_M->Timing.rtmDbBufReadBuf3 = 0xFF;
  ACC_M->Timing.rtmDbBufWriteBuf3 = 0xFF;
  ACC_M->Timing.rtmDbBufLastBufWr3 = 0;
  ACC_M->Timing.rtmDbBufReadBuf4 = 0xFF;
  ACC_M->Timing.rtmDbBufWriteBuf4 = 0xFF;
  ACC_M->Timing.rtmDbBufLastBufWr4 = 0;

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition1' */
  ACC_DW.RateTransition1_Buffer0 = ACC_P.RateTransition1_InitialConditio;
  ACC_DW.RateTransition1_write_buf = -1;
  ACC_DW.RateTransition1_read_buf = -1;

  /* InitializeConditions for RateTransition generated from: '<Root>/Function-Call Subsystem' */
  ACC_DW.TmpRTBAtFunctionCallSubsystemOu = ACC_P.TmpRTBAtFunctionCallSubsystemOu;
  ACC_DW.TmpRTBAtFunctionCallSubsystem_i = -1;
  ACC_DW.TmpRTBAtFunctionCallSubsystem_a = -1;

  /* InitializeConditions for RateTransition generated from: '<Root>/Function-Call Subsystem5' */
  ACC_DW.TmpRTBAtFunctionCallSubsystem5O = ACC_P.TmpRTBAtFunctionCallSubsystem5O;
  ACC_DW.TmpRTBAtFunctionCallSubsyste_ag = -1;
  ACC_DW.TmpRTBAtFunctionCallSubsyste_h4 = -1;

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt1' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */

  /* Asynchronous task (with no priority assigned)
   * reads absolute time */
  switch (ACC_M->Timing.rtmDbBufWriteBuf3) {
   case 0:
    ACC_M->Timing.rtmDbBufReadBuf3 = 1;
    break;

   case 1:
    ACC_M->Timing.rtmDbBufReadBuf3 = 0;
    break;

   default:
    ACC_M->Timing.rtmDbBufReadBuf3 = ACC_M->Timing.rtmDbBufLastBufWr3;
    break;
  }

  ACC_M->Timing.clockTick3 = ACC_M->Timing.rtmDbBufClockTick3
    [ACC_M->Timing.rtmDbBufReadBuf3];
  ACC_M->Timing.rtmDbBufReadBuf3 = 0xFF;

  /* SystemInitialize for SignalConversion generated from: '<S5>/Out1' incorporates:
   *  Constant: '<S5>/Constant2'
   */
  ACC_B.OutportBufferForOut1_b = ACC_P.Constant2_Value;

  /* SystemInitialize for Outport: '<S5>/Out2' incorporates:
   *  Delay: '<S5>/Delay'
   *  Math: '<S5>/Rem'
   */
  ACC_DW.Delay_DSTATE = ACC_P.Out2_Y0;

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(20), &MW_ISR_20, FALLING);

  /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt1' */

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt2' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem5'
   */

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem5' */

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

  /* SystemInitialize for SignalConversion generated from: '<S6>/Out1' incorporates:
   *  Constant: '<S6>/Constant'
   */
  ACC_B.OutportBufferForOut1 = ACC_P.Constant_Value_o;

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(21), &MW_ISR_21, FALLING);

  /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt2' */

  /* Start for MATLABSystem: '<Root>/Digital Output2' */
  ACC_DW.obj.matlabCodegenIsDeleted = false;
  ACC_DW.obj.isInitialized = 1L;
  digitalIOSetup(22, 1);
  ACC_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void ACC_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output2' */
  if (!ACC_DW.obj.matlabCodegenIsDeleted) {
    ACC_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
