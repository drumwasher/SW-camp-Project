/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Final_integration_1.c
 *
 * Code generated for Simulink model 'Final_integration_1'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Feb 15 09:21:38 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Final_integration_1.h"
#include "rtwtypes.h"
#include "Final_integration_1_private.h"
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <float.h>

/* Block signals (default storage) */
B_Final_integration_1_T Final_integration_1_B;

/* Block states (default storage) */
DW_Final_integration_1_T Final_integration_1_DW;

/* Real-time model */
static RT_MODEL_Final_integration_1_T Final_integration_1_M_;
RT_MODEL_Final_integration_1_T *const Final_integration_1_M =
  &Final_integration_1_M_;
static void rate_monotonic_scheduler(void);
uint32_T MultiWord2uLong(const uint32_T u[])
{
  return u[0];
}

void uMultiWordShr(const uint32_T u1[], int16_T n1, uint16_T n2, uint32_T y[],
                   int16_T n)
{
  uint32_T u1i;
  uint32_T yi;
  int16_T i;
  int16_T i1;
  int16_T nb;
  int16_T nc;
  uint16_T nr;
  nb = (int16_T)(n2 >> 5);
  i = 0;
  if (nb < n1) {
    nc = n + nb;
    if (nc > n1) {
      nc = n1;
    }

    nr = n2 - ((uint16_T)nb << 5);
    if (nr > 0U) {
      u1i = u1[nb];
      for (i1 = nb + 1; i1 < nc; i1++) {
        yi = u1i >> nr;
        u1i = u1[i1];
        y[i] = u1i << (32U - nr) | yi;
        i++;
      }

      yi = u1i >> nr;
      if (nc < n1) {
        yi |= u1[nc] << (32U - nr);
      }

      y[i] = yi;
      i++;
    } else {
      for (i1 = nb; i1 < nc; i1++) {
        y[i] = u1[i1];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = 0UL;
    i++;
  }
}

void uMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[], int16_T
                   n2, uint32_T y[], int16_T n)
{
  uint32_T a0;
  uint32_T a1;
  uint32_T b1;
  uint32_T cb;
  uint32_T u1i;
  uint32_T w01;
  uint32_T w10;
  uint32_T yk;
  int16_T i;
  int16_T j;
  int16_T k;
  int16_T ni;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0UL;
  }

  for (i = 0; i < n1; i++) {
    cb = 0UL;
    u1i = u1[i];
    a1 = u1i >> 16U;
    a0 = u1i & 65535UL;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      b1 = u1i >> 16U;
      u1i &= 65535UL;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }
}

/* Callback for Hardware Interrupt Block: '<Root>/Drive Mode Switch' */
void MW_ISR_2(void)
{
  /* Call the system: <S14>/SW1 */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_1_DW.IfActionSubsystem_SubsysRanBC_o);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_1_DW.IfActionSubsystem1_SubsysRan_da);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_1_DW.IfActionSubsystem_SubsysRanBC_g);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_1_DW.IfActionSubsystem1_SubsysRanB_d);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Final_integration_1_DW.SW1_SubsysRanBC);

    /* S-Function (arduinoextint_sfcn): '<Root>/Drive Mode Switch' */

    /* Output and update for function-call system: '<S14>/SW1' */

    /* Asynchronous task (with no priority assigned)
     * reads absolute time */
    switch (Final_integration_1_M->Timing.rtmDbBufWriteBuf2) {
     case 0:
      Final_integration_1_M->Timing.rtmDbBufReadBuf2 = 1;
      break;

     case 1:
      Final_integration_1_M->Timing.rtmDbBufReadBuf2 = 0;
      break;

     default:
      Final_integration_1_M->Timing.rtmDbBufReadBuf2 =
        Final_integration_1_M->Timing.rtmDbBufLastBufWr2;
      break;
    }

    Final_integration_1_M->Timing.clockTick2 =
      Final_integration_1_M->Timing.rtmDbBufClockTick2
      [Final_integration_1_M->Timing.rtmDbBufReadBuf2];
    Final_integration_1_M->Timing.rtmDbBufReadBuf2 = 0xFF;

    /* If: '<S17>/If' incorporates:
     *  Delay: '<S17>/Delay'
     */
    if (Final_integration_1_DW.Delay_DSTATE_f == 0.0) {
      /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem' incorporates:
       *  ActionPort: '<S18>/Action Port'
       */
      /* Merge: '<S17>/Merge' incorporates:
       *  Constant: '<S17>/Constant2'
       *  SignalConversion generated from: '<S18>/In1'
       */
      Final_integration_1_B.Merge_o = Final_integration_1_P.Constant2_Value;

      /* End of Outputs for SubSystem: '<S17>/If Action Subsystem' */

      /* Update for IfAction SubSystem: '<S17>/If Action Subsystem' incorporates:
       *  ActionPort: '<S18>/Action Port'
       */
      /* Update for If: '<S17>/If' */
      Final_integration_1_DW.IfActionSubsystem_SubsysRanBC_o = 4;

      /* End of Update for SubSystem: '<S17>/If Action Subsystem' */
    } else if (Final_integration_1_DW.Delay_DSTATE_f == 1.0) {
      /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S19>/Action Port'
       */
      /* If: '<S19>/If1' */
      if ((Final_integration_1_B.Delay_n == 0.0) && (Final_integration_1_B.Delay
           == 0.0)) {
        /* Outputs for IfAction SubSystem: '<S19>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S21>/Action Port'
         */
        /* Merge: '<S17>/Merge' incorporates:
         *  Constant: '<S19>/Constant'
         *  SignalConversion generated from: '<S21>/In1'
         */
        Final_integration_1_B.Merge_o = Final_integration_1_P.Constant_Value;

        /* End of Outputs for SubSystem: '<S19>/If Action Subsystem1' */

        /* Update for IfAction SubSystem: '<S19>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S21>/Action Port'
         */
        /* Update for If: '<S19>/If1' */
        Final_integration_1_DW.IfActionSubsystem1_SubsysRan_da = 4;

        /* End of Update for SubSystem: '<S19>/If Action Subsystem1' */
      } else {
        /* Outputs for IfAction SubSystem: '<S19>/If Action Subsystem' incorporates:
         *  ActionPort: '<S20>/Action Port'
         */
        /* Merge: '<S17>/Merge' incorporates:
         *  Constant: '<S19>/Constant1'
         *  SignalConversion generated from: '<S20>/In1'
         */
        Final_integration_1_B.Merge_o = Final_integration_1_P.Constant1_Value;

        /* End of Outputs for SubSystem: '<S19>/If Action Subsystem' */

        /* Update for IfAction SubSystem: '<S19>/If Action Subsystem' incorporates:
         *  ActionPort: '<S20>/Action Port'
         */
        /* Update for If: '<S19>/If1' */
        Final_integration_1_DW.IfActionSubsystem_SubsysRanBC_g = 4;

        /* End of Update for SubSystem: '<S19>/If Action Subsystem' */
      }

      /* End of If: '<S19>/If1' */
      /* End of Outputs for SubSystem: '<S17>/If Action Subsystem1' */

      /* Update for IfAction SubSystem: '<S17>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S19>/Action Port'
       */
      /* Update for If: '<S17>/If' */
      Final_integration_1_DW.IfActionSubsystem1_SubsysRanB_d = 4;

      /* End of Update for SubSystem: '<S17>/If Action Subsystem1' */
    }

    /* End of If: '<S17>/If' */

    /* Update for Delay: '<S17>/Delay' */
    Final_integration_1_DW.Delay_DSTATE_f = Final_integration_1_B.Merge_o;
    Final_integration_1_DW.SW1_SubsysRanBC = 4;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/Drive Mode Switch' */
  }

  extmodeEvent(2,((Final_integration_1_M->Timing.clockTick2) * 0.01));
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Final_integration_1_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Final_integration_1_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  Final_integration_1_M->Timing.RateInteraction.TID0_1 =
    (Final_integration_1_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Final_integration_1_M->Timing.TaskCounters.TID[1])++;
  if ((Final_integration_1_M->Timing.TaskCounters.TID[1]) > 19) {/* Sample time: [0.2s, 0.0s] */
    Final_integration_1_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S8>/If Action Subsystem1'
 *    '<S8>/If Action Subsystem3'
 *    '<S5>/If Action Subsystem1'
 */
void Final_in_IfActionSubsystem1(real_T *rty_Out1,
  P_IfActionSubsystem1_Final_in_T *localP)
{
  /* SignalConversion generated from: '<S11>/Out1' incorporates:
   *  Constant: '<S11>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
}

/*
 * Output and update for action system:
 *    '<S40>/If Action Subsystem'
 *    '<S40>/If Action Subsystem2'
 */
void Final_int_IfActionSubsystem(real_T rtu_In1, real_T *rty_Out1, real_T
  *rty_Out2)
{
  /* SignalConversion generated from: '<S41>/Out1' incorporates:
   *  SignalConversion generated from: '<S41>/In1'
   */
  *rty_Out1 = rtu_In1;

  /* SignalConversion generated from: '<S41>/Out2' incorporates:
   *  SignalConversion generated from: '<S41>/In1'
   */
  *rty_Out2 = rtu_In1;
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

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function for TID0 */
void Final_integration_1_step0(void)   /* Sample time: [0.01s, 0.0s] */
{
  uint64m_T tmp;
  uint64m_T tmp_0;
  real_T rtb_Product_n;
  uint32_T tmp_1;
  uint16_T b_varargout_1;
  uint8_T tmp_2;

  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_1_DW.IfActionSubsystem1_SubsysRan_jo);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_1_DW.IfActionSubsystem3_SubsysRanB_m);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (Final_integration_1_DW.IfActionSubsystem1_i.IfActionSubsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_1_DW.IfActionSubsystem_SubsysRanBC_j);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_1_DW.IfActionSubsystem9_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_1_DW.IfActionSubsystem10_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_1_DW.IfActionSubsystem_SubsysRanBC_i);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_1_DW.IfActionSubsystem1_SubsysRanB_e);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_1_DW.IfActionSubsystem2_SubsysRanB_j);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_1_DW.IfActionSubsystem3_SubsysRanB_j);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_1_DW.IfActionSubsystem1_SubsysRanB_m);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_1_DW.IfActionSubsystem_SubsysRanBC_f);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_1_DW.IfActionSubsystem2_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_1_DW.IfActionSubsystem3_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_1_DW.IfActionSubsystem11_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_1_DW.IfActionSubsystem_SubsysRanB_eh);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (Final_integration_1_DW.IfActionSubsystem_k.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_1_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_1_DW.IfActionSubsystem1_SubsysRanB_g);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_1_DW.IfActionSubsystem1_SubsysRanBC);

  /* RateTransition: '<S14>/Rate Transition' */
  Final_integration_1_B.RateTransition = Final_integration_1_B.Merge_o;

  /* If: '<S3>/If' */
  if (Final_integration_1_B.RateTransition == 1.0) {
    /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    /* SignalConversion generated from: '<S15>/sw2' */
    Final_integration_1_B.sw2 = Final_integration_1_B.Mod1;

    /* End of Outputs for SubSystem: '<S13>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<S13>/If Action Subsystem' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    /* Update for If: '<S3>/If' */
    srUpdateBC(Final_integration_1_DW.IfActionSubsystem_SubsysRanBC_j);

    /* End of Update for SubSystem: '<S13>/If Action Subsystem' */
  }

  /* End of If: '<S3>/If' */

  /* Constant: '<Root>/전방 장애물 거리' */
  Final_integration_1_B.u = Final_integration_1_P.f;

  /* Constant: '<Root>/좌측 장애물 거리' */
  Final_integration_1_B.u_e = Final_integration_1_P.l;

  /* Constant: '<Root>/우측 장애물 거리' */
  Final_integration_1_B.u_f = Final_integration_1_P.r;

  /* Constant: '<Root>/후방 장애물 거리' */
  Final_integration_1_B.u_k = Final_integration_1_P.b;

  /* MATLABSystem: '<Root>/가변저항' */
  if (Final_integration_1_DW.obj_l.SampleTime !=
      Final_integration_1_P._SampleTime) {
    Final_integration_1_DW.obj_l.SampleTime = Final_integration_1_P._SampleTime;
  }

  Final_integration_1_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(62UL);
  MW_AnalogInSingle_ReadResult
    (Final_integration_1_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* If: '<S22>/If3' incorporates:
   *  If: '<S24>/If'
   */
  if (Final_integration_1_B.RateTransition == 0.0) {
    /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem9' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    /* Merge: '<S24>/Merge' incorporates:
     *  Constant: '<S25>/Constant'
     *  Merge: '<S22>/Merge7'
     *  SignalConversion generated from: '<S25>/Out1'
     */
    Final_integration_1_B.Merge7 = Final_integration_1_P.Constant_Value_m;

    /* Merge: '<S24>/Merge1' incorporates:
     *  Constant: '<S25>/Constant'
     *  Merge: '<S22>/Merge8'
     *  SignalConversion generated from: '<S25>/Out2'
     */
    Final_integration_1_B.Merge8 = Final_integration_1_P.Constant_Value_m;

    /* Merge: '<S22>/Merge9' incorporates:
     *  Constant: '<S25>/Constant'
     *  SignalConversion generated from: '<S25>/Out3'
     */
    Final_integration_1_B.Merge9 = Final_integration_1_P.Constant_Value_m;

    /* End of Outputs for SubSystem: '<S22>/If Action Subsystem9' */

    /* Update for IfAction SubSystem: '<S22>/If Action Subsystem9' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    /* Update for If: '<S22>/If3' */
    srUpdateBC(Final_integration_1_DW.IfActionSubsystem9_SubsysRanBC);

    /* End of Update for SubSystem: '<S22>/If Action Subsystem9' */
  } else if (Final_integration_1_B.sw2 == 0.0) {
    /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
     *  Gain: '<S4>/Gain4'
     *  MATLABSystem: '<Root>/가변저항'
     * */
    rtb_Product_n = (real_T)((uint32_T)Final_integration_1_P.Gain4_Gain *
      b_varargout_1) * 7.62939453125E-6;

    /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem10' incorporates:
     *  ActionPort: '<S23>/Action Port'
     */
    /* Merge: '<S24>/Merge' incorporates:
     *  Constant: '<S23>/Constant'
     *  Constant: '<S23>/Constant1'
     *  Constant: '<S23>/Constant2'
     *  Constant: '<S23>/Constant4'
     *  Constant: '<S23>/Constant5'
     *  DataTypeConversion: '<S4>/Data Type Conversion'
     *  Merge: '<S22>/Merge7'
     *  Product: '<S23>/Divide'
     *  Product: '<S23>/Divide1'
     *  Product: '<S23>/Product'
     *  Sum: '<S23>/Minus'
     *  Sum: '<S23>/Sum'
     */
    Final_integration_1_B.Merge7 = ((rtb_Product_n -
      Final_integration_1_P.Constant2_Value_n) /
      Final_integration_1_P.Constant5_Value /
      Final_integration_1_P.Constant1_Value_l +
      Final_integration_1_P.Constant4_Value) * Final_integration_1_P.default1;

    /* Merge: '<S24>/Merge1' incorporates:
     *  Constant: '<S23>/Constant3'
     *  Constant: '<S23>/Constant6'
     *  Constant: '<S23>/Constant7'
     *  Constant: '<S23>/Constant8'
     *  Constant: '<S23>/Constant9'
     *  Merge: '<S22>/Merge8'
     *  Product: '<S23>/Divide2'
     *  Product: '<S23>/Divide3'
     *  Product: '<S23>/Product1'
     *  Sum: '<S23>/Minus1'
     *  Sum: '<S23>/Sum1'
     */
    Final_integration_1_B.Merge8 = ((Final_integration_1_P.Constant7_Value -
      rtb_Product_n) / Final_integration_1_P.Constant9_Value /
      Final_integration_1_P.Constant6_Value +
      Final_integration_1_P.Constant8_Value) * Final_integration_1_P.default1;

    /* Merge: '<S22>/Merge9' incorporates:
     *  Constant: '<S23>/Constant10'
     *  SignalConversion generated from: '<S23>/Out3'
     */
    Final_integration_1_B.Merge9 = Final_integration_1_P.Constant10_Value;

    /* End of Outputs for SubSystem: '<S22>/If Action Subsystem10' */

    /* Update for IfAction SubSystem: '<S22>/If Action Subsystem10' incorporates:
     *  ActionPort: '<S23>/Action Port'
     */
    /* Update for If: '<S22>/If3' */
    srUpdateBC(Final_integration_1_DW.IfActionSubsystem10_SubsysRanBC);

    /* End of Update for SubSystem: '<S22>/If Action Subsystem10' */
  } else {
    /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem11' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    if (Final_integration_1_B.u > 10.0) {
      /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S27>/Action Port'
       */
      /* If: '<S24>/If' incorporates:
       *  Constant: '<S27>/Constant'
       *  If: '<S27>/If'
       *  Merge: '<S22>/Merge9'
       *  SignalConversion generated from: '<S27>/Out3'
       */
      Final_integration_1_B.Merge9 = Final_integration_1_P.Constant_Value_k;
      if ((Final_integration_1_B.u_e < 10.0) && (Final_integration_1_B.u_f <
           10.0)) {
        /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem' incorporates:
         *  ActionPort: '<S30>/Action Port'
         */
        /* Product: '<S30>/Product' incorporates:
         *  Constant: '<S30>/Constant1'
         *  Sum: '<S30>/Subtract'
         */
        rtb_Product_n = (Final_integration_1_B.u_e - Final_integration_1_B.u_f) *
          Final_integration_1_P.steering;

        /* Merge: '<S24>/Merge' incorporates:
         *  Constant: '<S30>/Constant'
         *  Constant: '<S30>/Constant2'
         *  Product: '<S30>/Product1'
         *  Sum: '<S30>/Subtract1'
         */
        Final_integration_1_B.Merge7 = (Final_integration_1_P.Constant2_Value_k
          - rtb_Product_n) * Final_integration_1_P.default1;

        /* Merge: '<S24>/Merge1' incorporates:
         *  Constant: '<S30>/Constant2'
         *  Constant: '<S30>/Constant3'
         *  Product: '<S30>/Product3'
         *  Sum: '<S30>/Subtract3'
         */
        Final_integration_1_B.Merge8 = (Final_integration_1_P.Constant2_Value_k
          + rtb_Product_n) * Final_integration_1_P.default1;

        /* End of Outputs for SubSystem: '<S27>/If Action Subsystem' */

        /* Update for IfAction SubSystem: '<S27>/If Action Subsystem' incorporates:
         *  ActionPort: '<S30>/Action Port'
         */
        /* Update for If: '<S27>/If' */
        srUpdateBC(Final_integration_1_DW.IfActionSubsystem_SubsysRanBC_i);

        /* End of Update for SubSystem: '<S27>/If Action Subsystem' */
      } else if (Final_integration_1_B.u_e < 10.0) {
        /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S31>/Action Port'
         */
        /* Sum: '<S31>/Subtract' incorporates:
         *  Constant: '<S31>/Constant4'
         */
        Final_integration_1_B.Subtract = Final_integration_1_P.Constant4_Value_d
          - Final_integration_1_B.u_e;

        /* Product: '<S31>/Product' incorporates:
         *  Constant: '<S31>/Constant1'
         */
        Final_integration_1_B.Product = Final_integration_1_P.steering *
          Final_integration_1_B.Subtract;

        /* Merge: '<S24>/Merge1' incorporates:
         *  Constant: '<S31>/Constant'
         *  Constant: '<S31>/Constant2'
         *  Product: '<S31>/Product3'
         *  Sum: '<S31>/Subtract3'
         */
        Final_integration_1_B.Merge8 = (Final_integration_1_P.Constant2_Value_l
          - Final_integration_1_B.Product) * Final_integration_1_P.default1;

        /* Sum: '<S31>/Subtract1' incorporates:
         *  Constant: '<S31>/Constant2'
         */
        Final_integration_1_B.Subtract1 =
          Final_integration_1_P.Constant2_Value_l +
          Final_integration_1_B.Product;

        /* Product: '<S31>/Product1' incorporates:
         *  Constant: '<S31>/Constant'
         */
        Final_integration_1_B.Product1 = Final_integration_1_P.default1 *
          Final_integration_1_B.Subtract1;

        /* Merge: '<S24>/Merge' incorporates:
         *  SignalConversion generated from: '<S31>/Out2'
         */
        Final_integration_1_B.Merge7 = Final_integration_1_B.Product1;

        /* Update for IfAction SubSystem: '<S27>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S31>/Action Port'
         */
        /* Update for If: '<S27>/If' */
        srUpdateBC(Final_integration_1_DW.IfActionSubsystem1_SubsysRanB_e);

        /* End of Update for SubSystem: '<S27>/If Action Subsystem1' */
      } else if (Final_integration_1_B.u_f < 10.0) {
        /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S32>/Action Port'
         */
        /* Product: '<S32>/Product' incorporates:
         *  Constant: '<S32>/Constant1'
         *  Constant: '<S32>/Constant4'
         *  Sum: '<S32>/Subtract'
         */
        rtb_Product_n = (Final_integration_1_P.Constant4_Value_o -
                         Final_integration_1_B.u_f) *
          Final_integration_1_P.steering;

        /* Merge: '<S24>/Merge' incorporates:
         *  Constant: '<S32>/Constant'
         *  Constant: '<S32>/Constant2'
         *  Product: '<S32>/Product1'
         *  Sum: '<S32>/Subtract1'
         */
        Final_integration_1_B.Merge7 = (Final_integration_1_P.Constant2_Value_lo
          - rtb_Product_n) * Final_integration_1_P.default1;

        /* Merge: '<S24>/Merge1' incorporates:
         *  Constant: '<S32>/Constant'
         *  Constant: '<S32>/Constant2'
         *  Product: '<S32>/Product3'
         *  Sum: '<S32>/Subtract3'
         */
        Final_integration_1_B.Merge8 = (Final_integration_1_P.Constant2_Value_lo
          + rtb_Product_n) * Final_integration_1_P.default1;

        /* End of Outputs for SubSystem: '<S27>/If Action Subsystem2' */

        /* Update for IfAction SubSystem: '<S27>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S32>/Action Port'
         */
        /* Update for If: '<S27>/If' */
        srUpdateBC(Final_integration_1_DW.IfActionSubsystem2_SubsysRanB_j);

        /* End of Update for SubSystem: '<S27>/If Action Subsystem2' */
      } else {
        /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem3' incorporates:
         *  ActionPort: '<S33>/Action Port'
         */
        /* Merge: '<S24>/Merge' incorporates:
         *  Constant: '<S33>/Constant'
         *  SignalConversion generated from: '<S33>/Out1'
         */
        Final_integration_1_B.Merge7 = Final_integration_1_P.default1;

        /* Merge: '<S24>/Merge1' incorporates:
         *  Constant: '<S33>/Constant1'
         *  SignalConversion generated from: '<S33>/Out2'
         */
        Final_integration_1_B.Merge8 = Final_integration_1_P.default1;

        /* End of Outputs for SubSystem: '<S27>/If Action Subsystem3' */

        /* Update for IfAction SubSystem: '<S27>/If Action Subsystem3' incorporates:
         *  ActionPort: '<S33>/Action Port'
         */
        /* Update for If: '<S27>/If' */
        srUpdateBC(Final_integration_1_DW.IfActionSubsystem3_SubsysRanB_j);

        /* End of Update for SubSystem: '<S27>/If Action Subsystem3' */
      }

      /* End of Outputs for SubSystem: '<S24>/If Action Subsystem1' */

      /* Update for IfAction SubSystem: '<S24>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S27>/Action Port'
       */
      /* Update for If: '<S24>/If' */
      srUpdateBC(Final_integration_1_DW.IfActionSubsystem1_SubsysRanB_m);

      /* End of Update for SubSystem: '<S24>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem' incorporates:
       *  ActionPort: '<S26>/Action Port'
       */
      /* If: '<S24>/If' incorporates:
       *  Constant: '<S26>/Constant'
       *  Constant: '<S26>/Constant1'
       *  Constant: '<S26>/Constant2'
       *  Merge: '<S22>/Merge9'
       *  Merge: '<S24>/Merge'
       *  Merge: '<S24>/Merge1'
       *  SignalConversion generated from: '<S26>/Out1'
       *  SignalConversion generated from: '<S26>/Out2'
       *  SignalConversion generated from: '<S26>/Out3'
       */
      Final_integration_1_B.Merge7 = Final_integration_1_P.Constant_Value_e;
      Final_integration_1_B.Merge8 = Final_integration_1_P.Constant1_Value_j;
      Final_integration_1_B.Merge9 = Final_integration_1_P.Constant2_Value_lk;

      /* End of Outputs for SubSystem: '<S24>/If Action Subsystem' */

      /* Update for IfAction SubSystem: '<S24>/If Action Subsystem' incorporates:
       *  ActionPort: '<S26>/Action Port'
       */
      /* Update for If: '<S24>/If' */
      srUpdateBC(Final_integration_1_DW.IfActionSubsystem_SubsysRanBC_f);

      /* End of Update for SubSystem: '<S24>/If Action Subsystem' */
    }

    /* If: '<S24>/If1' */
    if (Final_integration_1_B.u_k > 10.0) {
      /* Update for IfAction SubSystem: '<S24>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S28>/Action Port'
       */
      /* Update for If: '<S24>/If1' */
      srUpdateBC(Final_integration_1_DW.IfActionSubsystem2_SubsysRanBC);

      /* End of Update for SubSystem: '<S24>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S29>/Action Port'
       */
      /* Merge: '<S24>/Merge' incorporates:
       *  Gain: '<S29>/Gain'
       *  Merge: '<S22>/Merge7'
       */
      Final_integration_1_B.Merge7 *= Final_integration_1_P.Gain_Gain;

      /* Merge: '<S24>/Merge1' incorporates:
       *  Gain: '<S29>/Gain1'
       *  Merge: '<S22>/Merge8'
       */
      Final_integration_1_B.Merge8 *= Final_integration_1_P.Gain1_Gain;

      /* End of Outputs for SubSystem: '<S24>/If Action Subsystem3' */

      /* Update for IfAction SubSystem: '<S24>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S29>/Action Port'
       */
      /* Update for If: '<S24>/If1' */
      srUpdateBC(Final_integration_1_DW.IfActionSubsystem3_SubsysRanBC);

      /* End of Update for SubSystem: '<S24>/If Action Subsystem3' */
    }

    /* End of If: '<S24>/If1' */
    /* End of Outputs for SubSystem: '<S22>/If Action Subsystem11' */

    /* Update for IfAction SubSystem: '<S22>/If Action Subsystem11' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    /* Update for If: '<S22>/If3' */
    srUpdateBC(Final_integration_1_DW.IfActionSubsystem11_SubsysRanBC);

    /* End of Update for SubSystem: '<S22>/If Action Subsystem11' */
  }

  /* End of If: '<S22>/If3' */

  /* RateTransition: '<S6>/Rate Transition' incorporates:
   *  Delay: '<S36>/Delay'
   */
  Final_integration_1_B.RateTransition_b = Final_integration_1_DW.Delay_DSTATE_d;

  /* MATLABSystem: '<Root>/Adas Mode Switch' */
  if (Final_integration_1_DW.obj_g.SampleTime !=
      Final_integration_1_P.AdasModeSwitch_SampleTime) {
    Final_integration_1_DW.obj_g.SampleTime =
      Final_integration_1_P.AdasModeSwitch_SampleTime;
  }

  /* MATLABSystem: '<Root>/Adas Mode Switch' */
  Final_integration_1_B.AdasModeSwitch = readDigitalPin(31);

  /* DiscretePulseGenerator: '<S7>/Pulse Generator' */
  rtb_Product_n = (Final_integration_1_DW.clockTickCounter <
                   Final_integration_1_P.PulseGenerator_Duty_m) &&
    (Final_integration_1_DW.clockTickCounter >= 0L) ?
    Final_integration_1_P.PulseGenerator_Amp_g : 0.0;
  if (Final_integration_1_DW.clockTickCounter >=
      Final_integration_1_P.PulseGenerator_Period_h - 1.0) {
    Final_integration_1_DW.clockTickCounter = 0L;
  } else {
    Final_integration_1_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S7>/Pulse Generator' */

  /* If: '<S7>/If1' */
  if (Final_integration_1_B.sw2 == 1.0) {
    /* Outputs for IfAction SubSystem: '<S7>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* SignalConversion generated from: '<S9>/Input' incorporates:
     *  Constant: '<S7>/Constant'
     *  Product: '<S7>/Product1'
     */
    rtb_Product_n = Final_integration_1_P.Constant_Value_c0 *
      Final_integration_1_B.RateTransition;

    /* End of Outputs for SubSystem: '<S7>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<S7>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Update for If: '<S7>/If1' */
    srUpdateBC(Final_integration_1_DW.IfActionSubsystem1_SubsysRan_jo);

    /* End of Update for SubSystem: '<S7>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S7>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* SignalConversion generated from: '<S10>/Input' incorporates:
     *  Product: '<S7>/Product'
     */
    rtb_Product_n *= Final_integration_1_B.RateTransition;

    /* End of Outputs for SubSystem: '<S7>/If Action Subsystem3' */

    /* Update for IfAction SubSystem: '<S7>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* Update for If: '<S7>/If1' */
    srUpdateBC(Final_integration_1_DW.IfActionSubsystem3_SubsysRanB_m);

    /* End of Update for SubSystem: '<S7>/If Action Subsystem3' */
  }

  /* End of If: '<S7>/If1' */

  /* MATLABSystem: '<S7>/Digital Output' */
  rtb_Product_n = rt_roundd_snf(rtb_Product_n);
  if (rtb_Product_n < 256.0) {
    if (rtb_Product_n >= 0.0) {
      tmp_2 = (uint8_T)rtb_Product_n;
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint8_T;
  }

  writeDigitalPin(43, tmp_2);

  /* End of MATLABSystem: '<S7>/Digital Output' */

  /* If: '<S8>/If1' */
  if (Final_integration_1_B.RateTransition == 1.0) {
    /* Outputs for IfAction SubSystem: '<S8>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    Final_in_IfActionSubsystem1(&rtb_Product_n,
      &Final_integration_1_P.IfActionSubsystem1_i);

    /* End of Outputs for SubSystem: '<S8>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S8>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    Final_in_IfActionSubsystem1(&rtb_Product_n,
      &Final_integration_1_P.IfActionSubsystem3_f);

    /* End of Outputs for SubSystem: '<S8>/If Action Subsystem3' */
  }

  /* End of If: '<S8>/If1' */

  /* MATLABSystem: '<S8>/Digital Output' */
  rtb_Product_n = rt_roundd_snf(rtb_Product_n);
  if (rtb_Product_n < 256.0) {
    if (rtb_Product_n >= 0.0) {
      tmp_2 = (uint8_T)rtb_Product_n;
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint8_T;
  }

  writeDigitalPin(42, tmp_2);

  /* End of MATLABSystem: '<S8>/Digital Output' */

  /* If: '<S5>/If' */
  if (Final_integration_1_B.Merge9 == 1.0) {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    /* DiscretePulseGenerator: '<S34>/Pulse Generator' */
    rtb_Product_n = (Final_integration_1_DW.clockTickCounter_p5 <
                     Final_integration_1_P.PulseGenerator_Duty) &&
      (Final_integration_1_DW.clockTickCounter_p5 >= 0L) ?
      Final_integration_1_P.PulseGenerator_Amp : 0.0;
    if (Final_integration_1_DW.clockTickCounter_p5 >=
        Final_integration_1_P.PulseGenerator_Period - 1.0) {
      Final_integration_1_DW.clockTickCounter_p5 = 0L;
    } else {
      Final_integration_1_DW.clockTickCounter_p5++;
    }

    /* End of DiscretePulseGenerator: '<S34>/Pulse Generator' */
    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<S5>/If Action Subsystem' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    /* Update for If: '<S5>/If' */
    srUpdateBC(Final_integration_1_DW.IfActionSubsystem_SubsysRanB_eh);

    /* End of Update for SubSystem: '<S5>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    Final_in_IfActionSubsystem1(&rtb_Product_n,
      &Final_integration_1_P.IfActionSubsystem1_f);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem1' */
  }

  /* End of If: '<S5>/If' */

  /* MATLABSystem: '<S5>/PWM' */
  Final_integration_1_DW.obj_ge.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
    (9UL);

  /* Start for MATLABSystem: '<S5>/PWM' */
  if (!(rtb_Product_n <= 255.0)) {
    rtb_Product_n = 255.0;
  }

  if (!(rtb_Product_n >= 0.0)) {
    rtb_Product_n = 0.0;
  }

  /* MATLABSystem: '<S5>/PWM' */
  MW_PWM_SetDutyCycle(Final_integration_1_DW.obj_ge.PWMDriverObj.MW_PWM_HANDLE,
                      rtb_Product_n);

  /* Delay: '<S1>/Delay' */
  Final_integration_1_B.Delay = Final_integration_1_DW.Delay_DSTATE;

  /* MATLABSystem: '<Root>/조도센서 Input' */
  if (Final_integration_1_DW.obj_a.SampleTime !=
      Final_integration_1_P.Input_SampleTime) {
    Final_integration_1_DW.obj_a.SampleTime =
      Final_integration_1_P.Input_SampleTime;
  }

  Final_integration_1_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(55UL);
  MW_AnalogInSingle_ReadResult
    (Final_integration_1_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* Delay: '<S3>/Delay' */
  Final_integration_1_B.Delay_n = Final_integration_1_DW.Delay_DSTATE_m;

  /* DiscretePulseGenerator: '<S40>/Pulse Generator' */
  rtb_Product_n = (Final_integration_1_DW.clockTickCounter_p <
                   Final_integration_1_P.PulseGenerator_Duty_b) &&
    (Final_integration_1_DW.clockTickCounter_p >= 0L) ?
    Final_integration_1_P.PulseGenerator_Amp_k : 0.0;
  if (Final_integration_1_DW.clockTickCounter_p >=
      Final_integration_1_P.PulseGenerator_Period_k - 1.0) {
    Final_integration_1_DW.clockTickCounter_p = 0L;
  } else {
    Final_integration_1_DW.clockTickCounter_p++;
  }

  /* End of DiscretePulseGenerator: '<S40>/Pulse Generator' */

  /* If: '<S40>/If' incorporates:
   *  Constant: '<S40>/Constant'
   *  Constant: '<S40>/Constant1'
   */
  if (Final_integration_1_B.RateTransition_b == 0.0) {
    /* Outputs for IfAction SubSystem: '<S40>/If Action Subsystem' incorporates:
     *  ActionPort: '<S41>/Action Port'
     */
    Final_int_IfActionSubsystem(Final_integration_1_P.Constant1_Value_m,
      &Final_integration_1_B.Merge, &Final_integration_1_B.Merge1);

    /* End of Outputs for SubSystem: '<S40>/If Action Subsystem' */
  } else if (Final_integration_1_B.RateTransition_b == 1.0) {
    /* Gain: '<S40>/Gain' incorporates:
     *  Gain: '<S1>/Gain'
     *  MATLABSystem: '<Root>/조도센서 Input'
     * */
    tmp_1 = (uint32_T)Final_integration_1_P.Gain_Gain_i * b_varargout_1;
    uMultiWordMul(&Final_integration_1_P.Gain_Gain_a, 1, &tmp_1, 1,
                  &tmp_0.chunks[0U], 2);

    /* DataTypeConversion: '<S40>/Data Type Conversion' */
    uMultiWordShr(&tmp_0.chunks[0U], 2, 42U, &tmp.chunks[0U], 2);

    /* Outputs for IfAction SubSystem: '<S40>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S42>/Action Port'
     */
    /* If: '<S42>/If' incorporates:
     *  DataTypeConversion: '<S40>/Data Type Conversion'
     */
    if ((uint8_T)MultiWord2uLong(&tmp.chunks[0U]) <= 34) {
      /* Outputs for IfAction SubSystem: '<S42>/If Action Subsystem' incorporates:
       *  ActionPort: '<S44>/Action Port'
       */
      /* Merge: '<S40>/Merge' incorporates:
       *  Constant: '<S42>/Constant'
       *  SignalConversion generated from: '<S44>/In1'
       */
      Final_integration_1_B.Merge = Final_integration_1_P.Constant_Value_c;

      /* End of Outputs for SubSystem: '<S42>/If Action Subsystem' */

      /* Update for IfAction SubSystem: '<S42>/If Action Subsystem' incorporates:
       *  ActionPort: '<S44>/Action Port'
       */
      /* Update for If: '<S42>/If' */
      srUpdateBC(Final_integration_1_DW.IfActionSubsystem_SubsysRanBC);

      /* End of Update for SubSystem: '<S42>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S42>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S45>/Action Port'
       */
      /* Merge: '<S40>/Merge' incorporates:
       *  Constant: '<S42>/Constant1'
       *  SignalConversion generated from: '<S45>/In1'
       */
      Final_integration_1_B.Merge = Final_integration_1_P.Constant1_Value_p;

      /* End of Outputs for SubSystem: '<S42>/If Action Subsystem1' */

      /* Update for IfAction SubSystem: '<S42>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S45>/Action Port'
       */
      /* Update for If: '<S42>/If' */
      srUpdateBC(Final_integration_1_DW.IfActionSubsystem1_SubsysRanB_g);

      /* End of Update for SubSystem: '<S42>/If Action Subsystem1' */
    }

    /* End of If: '<S42>/If' */

    /* Merge: '<S40>/Merge1' incorporates:
     *  SignalConversion generated from: '<S42>/In1'
     */
    Final_integration_1_B.Merge1 = rtb_Product_n;

    /* End of Outputs for SubSystem: '<S40>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<S40>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S42>/Action Port'
     */
    /* Update for If: '<S40>/If' */
    srUpdateBC(Final_integration_1_DW.IfActionSubsystem1_SubsysRanBC);

    /* End of Update for SubSystem: '<S40>/If Action Subsystem1' */
  } else if (Final_integration_1_B.RateTransition_b == 2.0) {
    /* Outputs for IfAction SubSystem: '<S40>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S43>/Action Port'
     */
    Final_int_IfActionSubsystem(Final_integration_1_P.Constant_Value_f,
      &Final_integration_1_B.Merge, &Final_integration_1_B.Merge1);

    /* End of Outputs for SubSystem: '<S40>/If Action Subsystem2' */
  }

  /* End of If: '<S40>/If' */

  /* MATLABSystem: '<S40>/Digital Output' */
  rtb_Product_n = rt_roundd_snf(Final_integration_1_B.Merge);
  if (rtb_Product_n < 256.0) {
    if (rtb_Product_n >= 0.0) {
      tmp_2 = (uint8_T)rtb_Product_n;
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint8_T;
  }

  writeDigitalPin(44, tmp_2);

  /* End of MATLABSystem: '<S40>/Digital Output' */

  /* MATLABSystem: '<S40>/Digital Output1' */
  rtb_Product_n = rt_roundd_snf(Final_integration_1_B.Merge1);
  if (rtb_Product_n < 256.0) {
    if (rtb_Product_n >= 0.0) {
      tmp_2 = (uint8_T)rtb_Product_n;
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint8_T;
  }

  writeDigitalPin(45, tmp_2);

  /* End of MATLABSystem: '<S40>/Digital Output1' */

  /* RateTransition generated from: '<S6>/If Action Subsystem' */
  if (Final_integration_1_M->Timing.RateInteraction.TID0_1) {
    Final_integration_1_DW.TmpRTBAtIfActionSubsystemInport =
      Final_integration_1_B.RateTransition;
  }

  /* End of RateTransition generated from: '<S6>/If Action Subsystem' */

  /* MATLABSystem: '<Root>/조도센서 Switch' */
  if (Final_integration_1_DW.obj.SampleTime !=
      Final_integration_1_P.Switch_SampleTime) {
    Final_integration_1_DW.obj.SampleTime =
      Final_integration_1_P.Switch_SampleTime;
  }

  /* MATLABSystem: '<Root>/조도센서 Switch' */
  Final_integration_1_B.Switch = readDigitalPin(36);

  /* Update for Delay: '<S1>/Delay' */
  Final_integration_1_DW.Delay_DSTATE = Final_integration_1_B.RateTransition_b;

  /* Update for Delay: '<S3>/Delay' */
  Final_integration_1_DW.Delay_DSTATE_m = Final_integration_1_B.sw2;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Final_integration_1_M->Timing.taskTime0 =
    ((time_T)(++Final_integration_1_M->Timing.clockTick0)) *
    Final_integration_1_M->Timing.stepSize0;
  switch (Final_integration_1_M->Timing.rtmDbBufReadBuf2) {
   case 0:
    Final_integration_1_M->Timing.rtmDbBufWriteBuf2 = 1;
    break;

   case 1:
    Final_integration_1_M->Timing.rtmDbBufWriteBuf2 = 0;
    break;

   default:
    Final_integration_1_M->Timing.rtmDbBufWriteBuf2 =
      !Final_integration_1_M->Timing.rtmDbBufLastBufWr2;
    break;
  }

  Final_integration_1_M->Timing.rtmDbBufClockTick2
    [Final_integration_1_M->Timing.rtmDbBufWriteBuf2] =
    Final_integration_1_M->Timing.clockTick0;
  Final_integration_1_M->Timing.rtmDbBufLastBufWr2 =
    Final_integration_1_M->Timing.rtmDbBufWriteBuf2;
  Final_integration_1_M->Timing.rtmDbBufWriteBuf2 = 0xFF;
}

/* Model step function for TID1 */
void Final_integration_1_step1(void)   /* Sample time: [0.2s, 0.0s] */
{
  real_T rtb_Plus;

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_1_DW.IfActionSubsystem1_SubsysRanB_j);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_1_DW.IfActionSubsystem_SubsysRanBC_n);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_1_DW.IfActionSubsystem1_SubsysRan_gf);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_integration_1_DW.IfActionSubsystem_SubsysRanBC_e);

  /* If: '<S13>/If' */
  if (!Final_integration_1_B.AdasModeSwitch) {
    /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    /* Sum: '<S16>/Sum' incorporates:
     *  Constant: '<S16>/Constant2'
     *  Delay: '<S16>/Delay1'
     */
    Final_integration_1_DW.Delay1_DSTATE +=
      Final_integration_1_P.Constant2_Value_m;

    /* Math: '<S16>/Mod1' incorporates:
     *  Constant: '<S16>/Constant3'
     *  Delay: '<S16>/Delay1'
     */
    Final_integration_1_B.Mod1 = rt_modd_snf
      (Final_integration_1_DW.Delay1_DSTATE,
       Final_integration_1_P.Constant3_Value);

    /* End of Outputs for SubSystem: '<S13>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<S13>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    /* Update for If: '<S13>/If' */
    srUpdateBC(Final_integration_1_DW.IfActionSubsystem1_SubsysRanB_j);

    /* End of Update for SubSystem: '<S13>/If Action Subsystem1' */
  }

  /* End of If: '<S13>/If' */

  /* If: '<S6>/If' */
  if (!Final_integration_1_B.Switch) {
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem' incorporates:
     *  ActionPort: '<S36>/Action Port'
     */
    /* If: '<S36>/If' incorporates:
     *  RateTransition generated from: '<S6>/If Action Subsystem'
     */
    if (Final_integration_1_DW.TmpRTBAtIfActionSubsystemInport == 1.0) {
      /* Outputs for IfAction SubSystem: '<S36>/If Action Subsystem' incorporates:
       *  ActionPort: '<S38>/Action Port'
       */
      /* SignalConversion generated from: '<S38>/In1' incorporates:
       *  Constant: '<S36>/Constant'
       */
      rtb_Plus = Final_integration_1_P.Constant_Value_mf;

      /* End of Outputs for SubSystem: '<S36>/If Action Subsystem' */

      /* Update for IfAction SubSystem: '<S36>/If Action Subsystem' incorporates:
       *  ActionPort: '<S38>/Action Port'
       */
      /* Update for If: '<S36>/If' */
      srUpdateBC(Final_integration_1_DW.IfActionSubsystem_SubsysRanBC_n);

      /* End of Update for SubSystem: '<S36>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S36>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S39>/Action Port'
       */
      /* SignalConversion generated from: '<S39>/In1' incorporates:
       *  Constant: '<S36>/Constant2'
       */
      rtb_Plus = Final_integration_1_P.Constant2_Value_f;

      /* End of Outputs for SubSystem: '<S36>/If Action Subsystem1' */

      /* Update for IfAction SubSystem: '<S36>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S39>/Action Port'
       */
      /* Update for If: '<S36>/If' */
      srUpdateBC(Final_integration_1_DW.IfActionSubsystem1_SubsysRan_gf);

      /* End of Update for SubSystem: '<S36>/If Action Subsystem1' */
    }

    /* End of If: '<S36>/If' */

    /* Math: '<S36>/Mod' incorporates:
     *  Constant: '<S36>/Constant1'
     *  Delay: '<S36>/Delay'
     *  Sum: '<S36>/Plus'
     */
    Final_integration_1_DW.Delay_DSTATE_d = rt_modd_snf(rtb_Plus +
      Final_integration_1_DW.Delay_DSTATE_d,
      Final_integration_1_P.Constant1_Value_g);

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<S6>/If Action Subsystem' incorporates:
     *  ActionPort: '<S36>/Action Port'
     */
    /* Update for If: '<S6>/If' */
    srUpdateBC(Final_integration_1_DW.IfActionSubsystem_SubsysRanBC_e);

    /* End of Update for SubSystem: '<S6>/If Action Subsystem' */
  }

  /* End of If: '<S6>/If' */

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.2, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Final_integration_1_M->Timing.clockTick1++;
}

/* Model initialize function */
void Final_integration_1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(Final_integration_1_M, -1);
  Final_integration_1_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Final_integration_1_M->Sizes.checksums[0] = (3063440125U);
  Final_integration_1_M->Sizes.checksums[1] = (366790233U);
  Final_integration_1_M->Sizes.checksums[2] = (488758131U);
  Final_integration_1_M->Sizes.checksums[3] = (2201962837U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[42];
    Final_integration_1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem1_SubsysRan_jo;
    systemRan[4] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem3_SubsysRanB_m;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem1_i.IfActionSubsystem1_SubsysRanBC;
    systemRan[7] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem3_f.IfActionSubsystem1_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem_SubsysRanBC_j;
    systemRan[9] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem1_SubsysRanB_j;
    systemRan[10] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem_SubsysRanBC_o;
    systemRan[11] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem_SubsysRanBC_g;
    systemRan[12] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem1_SubsysRan_da;
    systemRan[13] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem1_SubsysRanB_d;
    systemRan[14] = (sysRanDType *)&Final_integration_1_DW.SW1_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem10_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem_SubsysRanBC_f;
    systemRan[17] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem_SubsysRanBC_i;
    systemRan[18] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem1_SubsysRanB_e;
    systemRan[19] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem2_SubsysRanB_j;
    systemRan[20] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem3_SubsysRanB_j;
    systemRan[21] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem1_SubsysRanB_m;
    systemRan[22] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem3_SubsysRanBC;
    systemRan[24] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem11_SubsysRanBC;
    systemRan[25] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem9_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem_SubsysRanB_eh;
    systemRan[27] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem1_f.IfActionSubsystem1_SubsysRanBC;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem_SubsysRanBC_n;
    systemRan[30] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem1_SubsysRan_gf;
    systemRan[31] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem_SubsysRanBC_e;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = &rtAlwaysEnabled;
    systemRan[34] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem_k.IfActionSubsystem_SubsysRanBC;
    systemRan[35] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[36] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem1_SubsysRanB_g;
    systemRan[37] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[38] = (sysRanDType *)
      &Final_integration_1_DW.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[39] = &rtAlwaysEnabled;
    systemRan[40] = &rtAlwaysEnabled;
    systemRan[41] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Final_integration_1_M->extModeInfo,
      &Final_integration_1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Final_integration_1_M->extModeInfo,
                        Final_integration_1_M->Sizes.checksums);
    rteiSetTPtr(Final_integration_1_M->extModeInfo, rtmGetTPtr
                (Final_integration_1_M));
  }

  Final_integration_1_M->Timing.rtmDbBufReadBuf2 = 0xFF;
  Final_integration_1_M->Timing.rtmDbBufWriteBuf2 = 0xFF;
  Final_integration_1_M->Timing.rtmDbBufLastBufWr2 = 0;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  Final_integration_1_DW.Delay_DSTATE =
    Final_integration_1_P.Delay_InitialCondition_d;

  /* InitializeConditions for Delay: '<S3>/Delay' */
  Final_integration_1_DW.Delay_DSTATE_m =
    Final_integration_1_P.Delay_InitialCondition_n;

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/Drive Mode Switch' incorporates:
   *  SubSystem: '<S14>/SW1'
   */
  /* System initialize for function-call system: '<S14>/SW1' */

  /* Asynchronous task (with no priority assigned)
   * reads absolute time */
  switch (Final_integration_1_M->Timing.rtmDbBufWriteBuf2) {
   case 0:
    Final_integration_1_M->Timing.rtmDbBufReadBuf2 = 1;
    break;

   case 1:
    Final_integration_1_M->Timing.rtmDbBufReadBuf2 = 0;
    break;

   default:
    Final_integration_1_M->Timing.rtmDbBufReadBuf2 =
      Final_integration_1_M->Timing.rtmDbBufLastBufWr2;
    break;
  }

  Final_integration_1_M->Timing.clockTick2 =
    Final_integration_1_M->Timing.rtmDbBufClockTick2
    [Final_integration_1_M->Timing.rtmDbBufReadBuf2];
  Final_integration_1_M->Timing.rtmDbBufReadBuf2 = 0xFF;

  /* InitializeConditions for Delay: '<S17>/Delay' */
  Final_integration_1_DW.Delay_DSTATE_f =
    Final_integration_1_P.Delay_InitialCondition;

  /* SystemInitialize for Merge: '<S17>/Merge' */
  Final_integration_1_B.Merge_o = Final_integration_1_P.Merge_InitialOutput;

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(2), &MW_ISR_2, RISING);

  /* SystemInitialize for IfAction SubSystem: '<S13>/If Action Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S15>/sw2' incorporates:
   *  Outport: '<S15>/ADAS_state'
   */
  Final_integration_1_B.sw2 = Final_integration_1_P.ADAS_state_Y0;

  /* End of SystemInitialize for SubSystem: '<S13>/If Action Subsystem' */

  /* SystemInitialize for IfAction SubSystem: '<S13>/If Action Subsystem1' */
  /* InitializeConditions for Delay: '<S16>/Delay1' */
  Final_integration_1_DW.Delay1_DSTATE =
    Final_integration_1_P.Delay1_InitialCondition;

  /* SystemInitialize for Math: '<S16>/Mod1' incorporates:
   *  Outport: '<S16>/sw2'
   */
  Final_integration_1_B.Mod1 = Final_integration_1_P.sw2_Y0;

  /* End of SystemInitialize for SubSystem: '<S13>/If Action Subsystem1' */
  /* SystemInitialize for IfAction SubSystem: '<S6>/If Action Subsystem' */
  /* SystemInitialize for Outport: '<S36>/light_mode' incorporates:
   *  Delay: '<S36>/Delay'
   *  Math: '<S36>/Mod'
   */
  Final_integration_1_DW.Delay_DSTATE_d = Final_integration_1_P.light_mode_Y0;

  /* End of SystemInitialize for SubSystem: '<S6>/If Action Subsystem' */

  /* SystemInitialize for Merge: '<S40>/Merge' */
  Final_integration_1_B.Merge = Final_integration_1_P.Merge_InitialOutput_b;

  /* SystemInitialize for Merge: '<S40>/Merge1' */
  Final_integration_1_B.Merge1 = Final_integration_1_P.Merge1_InitialOutput;

  /* Start for MATLABSystem: '<Root>/가변저항' */
  Final_integration_1_DW.obj_l.matlabCodegenIsDeleted = false;
  Final_integration_1_DW.obj_l.SampleTime = Final_integration_1_P._SampleTime;
  Final_integration_1_DW.obj_l.isInitialized = 1L;
  Final_integration_1_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(62UL);
  Final_integration_1_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Adas Mode Switch' */
  Final_integration_1_DW.obj_g.matlabCodegenIsDeleted = false;
  Final_integration_1_DW.obj_g.SampleTime =
    Final_integration_1_P.AdasModeSwitch_SampleTime;
  Final_integration_1_DW.obj_g.isInitialized = 1L;
  digitalIOSetup(31, 0);
  Final_integration_1_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S7>/Digital Output' */
  Final_integration_1_DW.obj_b.matlabCodegenIsDeleted = false;
  Final_integration_1_DW.obj_b.isInitialized = 1L;
  digitalIOSetup(43, 1);
  Final_integration_1_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S8>/Digital Output' */
  Final_integration_1_DW.obj_gm.matlabCodegenIsDeleted = false;
  Final_integration_1_DW.obj_gm.isInitialized = 1L;
  digitalIOSetup(42, 1);
  Final_integration_1_DW.obj_gm.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/PWM' */
  Final_integration_1_DW.obj_ge.matlabCodegenIsDeleted = false;
  Final_integration_1_DW.obj_ge.isInitialized = 1L;
  Final_integration_1_DW.obj_ge.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL,
    0.0, 0.0);
  Final_integration_1_DW.obj_ge.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/조도센서 Input' */
  Final_integration_1_DW.obj_a.matlabCodegenIsDeleted = false;
  Final_integration_1_DW.obj_a.SampleTime =
    Final_integration_1_P.Input_SampleTime;
  Final_integration_1_DW.obj_a.isInitialized = 1L;
  Final_integration_1_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(55UL);
  Final_integration_1_DW.obj_a.isSetupComplete = true;

  /* Start for MATLABSystem: '<S40>/Digital Output' */
  Final_integration_1_DW.obj_e.matlabCodegenIsDeleted = false;
  Final_integration_1_DW.obj_e.isInitialized = 1L;
  digitalIOSetup(44, 1);
  Final_integration_1_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S40>/Digital Output1' */
  Final_integration_1_DW.obj_i.matlabCodegenIsDeleted = false;
  Final_integration_1_DW.obj_i.isInitialized = 1L;
  digitalIOSetup(45, 1);
  Final_integration_1_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/조도센서 Switch' */
  Final_integration_1_DW.obj.matlabCodegenIsDeleted = false;
  Final_integration_1_DW.obj.SampleTime =
    Final_integration_1_P.Switch_SampleTime;
  Final_integration_1_DW.obj.isInitialized = 1L;
  digitalIOSetup(36, 0);
  Final_integration_1_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void Final_integration_1_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/가변저항' */
  if (!Final_integration_1_DW.obj_l.matlabCodegenIsDeleted) {
    Final_integration_1_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Final_integration_1_DW.obj_l.isInitialized == 1L) &&
        Final_integration_1_DW.obj_l.isSetupComplete) {
      Final_integration_1_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(62UL);
      MW_AnalogIn_Close
        (Final_integration_1_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/가변저항' */
  /* Terminate for MATLABSystem: '<Root>/Adas Mode Switch' */
  if (!Final_integration_1_DW.obj_g.matlabCodegenIsDeleted) {
    Final_integration_1_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Adas Mode Switch' */

  /* Terminate for MATLABSystem: '<S7>/Digital Output' */
  if (!Final_integration_1_DW.obj_b.matlabCodegenIsDeleted) {
    Final_integration_1_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S7>/Digital Output' */

  /* Terminate for MATLABSystem: '<S8>/Digital Output' */
  if (!Final_integration_1_DW.obj_gm.matlabCodegenIsDeleted) {
    Final_integration_1_DW.obj_gm.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S8>/Digital Output' */

  /* Terminate for MATLABSystem: '<S5>/PWM' */
  if (!Final_integration_1_DW.obj_ge.matlabCodegenIsDeleted) {
    Final_integration_1_DW.obj_ge.matlabCodegenIsDeleted = true;
    if ((Final_integration_1_DW.obj_ge.isInitialized == 1L) &&
        Final_integration_1_DW.obj_ge.isSetupComplete) {
      Final_integration_1_DW.obj_ge.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle
        (Final_integration_1_DW.obj_ge.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Final_integration_1_DW.obj_ge.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(9UL);
      MW_PWM_Close(Final_integration_1_DW.obj_ge.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/PWM' */

  /* Terminate for MATLABSystem: '<Root>/조도센서 Input' */
  if (!Final_integration_1_DW.obj_a.matlabCodegenIsDeleted) {
    Final_integration_1_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Final_integration_1_DW.obj_a.isInitialized == 1L) &&
        Final_integration_1_DW.obj_a.isSetupComplete) {
      Final_integration_1_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(55UL);
      MW_AnalogIn_Close
        (Final_integration_1_DW.obj_a.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/조도센서 Input' */

  /* Terminate for MATLABSystem: '<S40>/Digital Output' */
  if (!Final_integration_1_DW.obj_e.matlabCodegenIsDeleted) {
    Final_integration_1_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S40>/Digital Output' */

  /* Terminate for MATLABSystem: '<S40>/Digital Output1' */
  if (!Final_integration_1_DW.obj_i.matlabCodegenIsDeleted) {
    Final_integration_1_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S40>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/조도센서 Switch' */
  if (!Final_integration_1_DW.obj.matlabCodegenIsDeleted) {
    Final_integration_1_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/조도센서 Switch' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
