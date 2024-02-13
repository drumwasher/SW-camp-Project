/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pr2_US_hap.c
 *
 * Code generated for Simulink model 'pr2_US_hap'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Feb 12 18:01:54 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pr2_US_hap.h"
#include "rtwtypes.h"
#include "pr2_US_hap_private.h"
#include <math.h>
#include "rt_nonfinite.h"

/* Named constants for Chart: '<S3>/Chart' */
#define pr2_US_IN_drive_on_adas_on_LRUS (5UL)
#define pr2_US__IN_drive_on_adas_on_FUS (4UL)
#define pr2_US__IN_drive_on_adas_on_LUS (6UL)
#define pr2_US__IN_drive_on_adas_on_RUS (7UL)
#define pr2_US_hap_IN_drive_off        (1UL)
#define pr2_US_hap_IN_drive_on_adas_off (2UL)
#define pr2_US_hap_IN_drive_on_adas_on (3UL)

/* Named constants for Chart: '<S3>/Chart1' */
#define pr2_US_hap_IN_adas_off         (1UL)
#define pr2_US_hap_IN_adas_on          (2UL)
#define pr2_US_hap_IN_adas_on_BUS      (3UL)

/* Block signals (default storage) */
B_pr2_US_hap_T pr2_US_hap_B;

/* Continuous states */
X_pr2_US_hap_T pr2_US_hap_X;

/* Disabled State Vector */
XDis_pr2_US_hap_T pr2_US_hap_XDis;

/* Block states (default storage) */
DW_pr2_US_hap_T pr2_US_hap_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_pr2_US_hap_T pr2_US_hap_Y;

/* Real-time model */
static RT_MODEL_pr2_US_hap_T pr2_US_hap_M_;
RT_MODEL_pr2_US_hap_T *const pr2_US_hap_M = &pr2_US_hap_M_;
void sMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[], int16_T
                   n2, uint32_T y[], int16_T n)
{
  uint32_T a0;
  uint32_T a1;
  uint32_T b1;
  uint32_T cb;
  uint32_T cb1;
  uint32_T cb2;
  uint32_T u1i;
  uint32_T w01;
  uint32_T w10;
  uint32_T yk;
  int16_T i;
  int16_T j;
  int16_T k;
  int16_T ni;
  boolean_T isNegative1;
  boolean_T isNegative2;
  isNegative1 = ((u1[n1 - 1] & 2147483648UL) != 0UL);
  isNegative2 = ((u2[n2 - 1] & 2147483648UL) != 0UL);
  cb1 = 1UL;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0UL;
  }

  for (i = 0; i < n1; i++) {
    cb = 0UL;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535UL;
    cb2 = 1UL;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = (uint32_T)(u1i < cb2);
      }

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

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1UL;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

/* Callback for Hardware Interrupt Block: '<Root>/External Interrupt(SW1)' */
void MW_ISR_20(void)
{
  /* Call the system: <Root>/SW1 PUSH */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(pr2_US_hap_DW.SW1PUSH_SubsysRanBC);

    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt(SW1)' */

    /* Output and update for function-call system: '<Root>/SW1 PUSH' */

    /* Asynchronous task (with no priority assigned)
     * reads absolute time */
    switch (pr2_US_hap_M->Timing.rtmDbBufWriteBuf2) {
     case 0:
      pr2_US_hap_M->Timing.rtmDbBufReadBuf2 = 1;
      break;

     case 1:
      pr2_US_hap_M->Timing.rtmDbBufReadBuf2 = 0;
      break;

     default:
      pr2_US_hap_M->Timing.rtmDbBufReadBuf2 =
        pr2_US_hap_M->Timing.rtmDbBufLastBufWr2;
      break;
    }

    pr2_US_hap_M->Timing.clockTick2 = pr2_US_hap_M->
      Timing.rtmDbBufClockTick2[pr2_US_hap_M->Timing.rtmDbBufReadBuf2];
    pr2_US_hap_M->Timing.rtmDbBufReadBuf2 = 0xFF;

    /* Sum: '<S1>/Add' incorporates:
     *  Constant: '<S1>/Constant'
     *  Delay: '<S1>/Delay'
     */
    pr2_US_hap_B.Add_h = pr2_US_hap_P.Constant_Value -
      pr2_US_hap_DW.Delay_DSTATE_a;

    /* Update for Delay: '<S1>/Delay' */
    pr2_US_hap_DW.Delay_DSTATE_a = pr2_US_hap_B.Add_h;
    pr2_US_hap_DW.SW1PUSH_SubsysRanBC = 4;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt(SW1)' */

    /* RateTransition generated from: '<S3>/Chart' */
    switch (pr2_US_hap_DW.TmpRTBAtChartInport1_read_buf) {
     case 0:
      pr2_US_hap_DW.TmpRTBAtChartInport1_write_buf = 1;
      break;

     case 1:
      pr2_US_hap_DW.TmpRTBAtChartInport1_write_buf = 0;
      break;

     default:
      pr2_US_hap_DW.TmpRTBAtChartInport1_write_buf = (int8_T)
        (pr2_US_hap_DW.TmpRTBAtChartInport1_last_buf_w == 0);
      break;
    }

    if (pr2_US_hap_DW.TmpRTBAtChartInport1_write_buf != 0) {
      pr2_US_hap_DW.TmpRTBAtChartInport1_Buffer1 = pr2_US_hap_B.Add_h;
    } else {
      pr2_US_hap_DW.TmpRTBAtChartInport1_Buffer0 = pr2_US_hap_B.Add_h;
    }

    pr2_US_hap_DW.TmpRTBAtChartInport1_last_buf_w =
      pr2_US_hap_DW.TmpRTBAtChartInport1_write_buf;
    pr2_US_hap_DW.TmpRTBAtChartInport1_write_buf = -1;

    /* End of RateTransition generated from: '<S3>/Chart' */

    /* RateTransition generated from: '<Root>/Display2' */
    switch (pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_read_bu) {
     case 0:
      pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_write_b = 1;
      break;

     case 1:
      pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_write_b = 0;
      break;

     default:
      pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_write_b = (int8_T)
        (pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_last_bu == 0);
      break;
    }

    if (pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_write_b != 0) {
      pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_Buffer1 = pr2_US_hap_B.Add_h;
    } else {
      pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_Buffer0 = pr2_US_hap_B.Add_h;
    }

    pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_last_bu =
      pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_write_b;
    pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_write_b = -1;

    /* End of RateTransition generated from: '<Root>/Display2' */
  }

  extmodeEvent(2,((pr2_US_hap_M->Timing.clockTick2) * 0.01));
}

/* Callback for Hardware Interrupt Block: '<Root>/External Interrupt(SW2)' */
void MW_ISR_21(void)
{
  /* Call the system: <Root>/SW1 PUSH1 */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(pr2_US_hap_DW.SW1PUSH1_SubsysRanBC);

    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt(SW2)' */

    /* Output and update for function-call system: '<Root>/SW1 PUSH1' */

    /* Asynchronous task (with no priority assigned)
     * reads absolute time */
    switch (pr2_US_hap_M->Timing.rtmDbBufWriteBuf3) {
     case 0:
      pr2_US_hap_M->Timing.rtmDbBufReadBuf3 = 1;
      break;

     case 1:
      pr2_US_hap_M->Timing.rtmDbBufReadBuf3 = 0;
      break;

     default:
      pr2_US_hap_M->Timing.rtmDbBufReadBuf3 =
        pr2_US_hap_M->Timing.rtmDbBufLastBufWr3;
      break;
    }

    pr2_US_hap_M->Timing.clockTick3 = pr2_US_hap_M->
      Timing.rtmDbBufClockTick3[pr2_US_hap_M->Timing.rtmDbBufReadBuf3];
    pr2_US_hap_M->Timing.rtmDbBufReadBuf3 = 0xFF;

    /* Sum: '<S2>/Add' incorporates:
     *  Constant: '<S2>/Constant'
     *  Delay: '<S2>/Delay'
     */
    pr2_US_hap_B.Add = pr2_US_hap_P.Constant_Value_f -
      pr2_US_hap_DW.Delay_DSTATE;

    /* Update for Delay: '<S2>/Delay' */
    pr2_US_hap_DW.Delay_DSTATE = pr2_US_hap_B.Add;
    pr2_US_hap_DW.SW1PUSH1_SubsysRanBC = 4;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt(SW2)' */

    /* RateTransition generated from: '<S3>/Chart1' */
    switch (pr2_US_hap_DW.TmpRTBAtChart1Inport1_read_buf) {
     case 0:
      pr2_US_hap_DW.TmpRTBAtChart1Inport1_write_buf = 1;
      break;

     case 1:
      pr2_US_hap_DW.TmpRTBAtChart1Inport1_write_buf = 0;
      break;

     default:
      pr2_US_hap_DW.TmpRTBAtChart1Inport1_write_buf = (int8_T)
        (pr2_US_hap_DW.TmpRTBAtChart1Inport1_last_buf_ == 0);
      break;
    }

    if (pr2_US_hap_DW.TmpRTBAtChart1Inport1_write_buf != 0) {
      pr2_US_hap_DW.TmpRTBAtChart1Inport1_Buffer1 = pr2_US_hap_B.Add;
    } else {
      pr2_US_hap_DW.TmpRTBAtChart1Inport1_Buffer0 = pr2_US_hap_B.Add;
    }

    pr2_US_hap_DW.TmpRTBAtChart1Inport1_last_buf_ =
      pr2_US_hap_DW.TmpRTBAtChart1Inport1_write_buf;
    pr2_US_hap_DW.TmpRTBAtChart1Inport1_write_buf = -1;

    /* End of RateTransition generated from: '<S3>/Chart1' */

    /* RateTransition generated from: '<S3>/Chart' */
    switch (pr2_US_hap_DW.TmpRTBAtChartInport2_read_buf) {
     case 0:
      pr2_US_hap_DW.TmpRTBAtChartInport2_write_buf = 1;
      break;

     case 1:
      pr2_US_hap_DW.TmpRTBAtChartInport2_write_buf = 0;
      break;

     default:
      pr2_US_hap_DW.TmpRTBAtChartInport2_write_buf = (int8_T)
        (pr2_US_hap_DW.TmpRTBAtChartInport2_last_buf_w == 0);
      break;
    }

    if (pr2_US_hap_DW.TmpRTBAtChartInport2_write_buf != 0) {
      pr2_US_hap_DW.TmpRTBAtChartInport2_Buffer1 = pr2_US_hap_B.Add;
    } else {
      pr2_US_hap_DW.TmpRTBAtChartInport2_Buffer0 = pr2_US_hap_B.Add;
    }

    pr2_US_hap_DW.TmpRTBAtChartInport2_last_buf_w =
      pr2_US_hap_DW.TmpRTBAtChartInport2_write_buf;
    pr2_US_hap_DW.TmpRTBAtChartInport2_write_buf = -1;

    /* End of RateTransition generated from: '<S3>/Chart' */

    /* RateTransition generated from: '<Root>/Display3' */
    switch (pr2_US_hap_DW.TmpRTBAtDisplay3Inport1_read_bu) {
     case 0:
      pr2_US_hap_DW.TmpRTBAtDisplay3Inport1_write_b = 1;
      break;

     case 1:
      pr2_US_hap_DW.TmpRTBAtDisplay3Inport1_write_b = 0;
      break;

     default:
      pr2_US_hap_DW.TmpRTBAtDisplay3Inport1_write_b = (int8_T)
        (pr2_US_hap_DW.TmpRTBAtDisplay3Inport1_last_bu == 0);
      break;
    }

    if (pr2_US_hap_DW.TmpRTBAtDisplay3Inport1_write_b != 0) {
      pr2_US_hap_DW.TmpRTBAtDisplay3Inport1_Buffer1 = pr2_US_hap_B.Add;
    } else {
      pr2_US_hap_DW.TmpRTBAtDisplay3Inport1_Buffer0 = pr2_US_hap_B.Add;
    }

    pr2_US_hap_DW.TmpRTBAtDisplay3Inport1_last_bu =
      pr2_US_hap_DW.TmpRTBAtDisplay3Inport1_write_b;
    pr2_US_hap_DW.TmpRTBAtDisplay3Inport1_write_b = -1;

    /* End of RateTransition generated from: '<Root>/Display3' */
  }

  extmodeEvent(3,((pr2_US_hap_M->Timing.clockTick3) * 0.01));
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  pr2_US_hap_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  pr2_US_hap_step();
  pr2_US_hap_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  pr2_US_hap_step();
  pr2_US_hap_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void pr2_US_hap_step(void)
{
  /* local block i/o variables */
  int32_T rtb_TSamp;
  real_T out1_tmp;
  real_T rtb_Add1;
  real_T rtb_Gain1;
  int32_T tmp;
  uint32_T tmp_0;
  uint32_T tmp_1;
  uint16_T b_varargout_1;
  if (rtmIsMajorTimeStep(pr2_US_hap_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&pr2_US_hap_M->solverInfo,
                          ((pr2_US_hap_M->Timing.clockTick0+1)*
      pr2_US_hap_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(pr2_US_hap_M)) {
    pr2_US_hap_M->Timing.t[0] = rtsiGetT(&pr2_US_hap_M->solverInfo);
  }

  /* Integrator: '<S6>/Integrator1' */
  rtb_Gain1 = pr2_US_hap_X.Integrator1_CSTATE;
  if (rtmIsMajorTimeStep(pr2_US_hap_M)) {
    /* RateTransition generated from: '<S3>/Chart1' */
    switch (pr2_US_hap_DW.TmpRTBAtChart1Inport1_write_buf) {
     case 0:
      pr2_US_hap_DW.TmpRTBAtChart1Inport1_read_buf = 1;
      break;

     case 1:
      pr2_US_hap_DW.TmpRTBAtChart1Inport1_read_buf = 0;
      break;

     default:
      pr2_US_hap_DW.TmpRTBAtChart1Inport1_read_buf =
        pr2_US_hap_DW.TmpRTBAtChart1Inport1_last_buf_;
      break;
    }

    if (pr2_US_hap_DW.TmpRTBAtChart1Inport1_read_buf != 0) {
      /* RateTransition generated from: '<S3>/Chart1' */
      pr2_US_hap_B.TmpRTBAtChart1Inport1 =
        pr2_US_hap_DW.TmpRTBAtChart1Inport1_Buffer1;
    } else {
      /* RateTransition generated from: '<S3>/Chart1' */
      pr2_US_hap_B.TmpRTBAtChart1Inport1 =
        pr2_US_hap_DW.TmpRTBAtChart1Inport1_Buffer0;
    }

    pr2_US_hap_DW.TmpRTBAtChart1Inport1_read_buf = -1;

    /* End of RateTransition generated from: '<S3>/Chart1' */

    /* RateTransition generated from: '<S3>/Chart' */
    switch (pr2_US_hap_DW.TmpRTBAtChartInport1_write_buf) {
     case 0:
      pr2_US_hap_DW.TmpRTBAtChartInport1_read_buf = 1;
      break;

     case 1:
      pr2_US_hap_DW.TmpRTBAtChartInport1_read_buf = 0;
      break;

     default:
      pr2_US_hap_DW.TmpRTBAtChartInport1_read_buf =
        pr2_US_hap_DW.TmpRTBAtChartInport1_last_buf_w;
      break;
    }

    if (pr2_US_hap_DW.TmpRTBAtChartInport1_read_buf != 0) {
      /* RateTransition generated from: '<S3>/Chart' */
      pr2_US_hap_B.TmpRTBAtChartInport1 =
        pr2_US_hap_DW.TmpRTBAtChartInport1_Buffer1;
    } else {
      /* RateTransition generated from: '<S3>/Chart' */
      pr2_US_hap_B.TmpRTBAtChartInport1 =
        pr2_US_hap_DW.TmpRTBAtChartInport1_Buffer0;
    }

    pr2_US_hap_DW.TmpRTBAtChartInport1_read_buf = -1;

    /* End of RateTransition generated from: '<S3>/Chart' */

    /* RateTransition generated from: '<S3>/Chart' */
    switch (pr2_US_hap_DW.TmpRTBAtChartInport2_write_buf) {
     case 0:
      pr2_US_hap_DW.TmpRTBAtChartInport2_read_buf = 1;
      break;

     case 1:
      pr2_US_hap_DW.TmpRTBAtChartInport2_read_buf = 0;
      break;

     default:
      pr2_US_hap_DW.TmpRTBAtChartInport2_read_buf =
        pr2_US_hap_DW.TmpRTBAtChartInport2_last_buf_w;
      break;
    }

    if (pr2_US_hap_DW.TmpRTBAtChartInport2_read_buf != 0) {
      /* RateTransition generated from: '<S3>/Chart' */
      pr2_US_hap_B.TmpRTBAtChartInport2 =
        pr2_US_hap_DW.TmpRTBAtChartInport2_Buffer1;
    } else {
      /* RateTransition generated from: '<S3>/Chart' */
      pr2_US_hap_B.TmpRTBAtChartInport2 =
        pr2_US_hap_DW.TmpRTBAtChartInport2_Buffer0;
    }

    pr2_US_hap_DW.TmpRTBAtChartInport2_read_buf = -1;

    /* End of RateTransition generated from: '<S3>/Chart' */

    /* Constant: '<Root>/Constant3' */
    pr2_US_hap_B.Constant3 = pr2_US_hap_P.Constant3_Value;

    /* Constant: '<Root>/Constant' */
    pr2_US_hap_B.Constant = pr2_US_hap_P.Constant_Value_n;

    /* Constant: '<Root>/Constant1' */
    pr2_US_hap_B.Constant1 = pr2_US_hap_P.Constant1_Value;
  }

  /* MATLABSystem: '<Root>/가변저항' */
  if (pr2_US_hap_DW.obj_n.SampleTime != pr2_US_hap_P._SampleTime) {
    pr2_US_hap_DW.obj_n.SampleTime = pr2_US_hap_P._SampleTime;
  }

  pr2_US_hap_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(62UL);
  MW_AnalogInSingle_ReadResult
    (pr2_US_hap_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  Gain: '<S3>/Gain4'
   *  MATLABSystem: '<Root>/가변저항'
   * */
  pr2_US_hap_B.DataTypeConversion = (real_T)((uint32_T)pr2_US_hap_P.Gain4_Gain *
    b_varargout_1) * 7.62939453125E-6;
  if (rtmIsMajorTimeStep(pr2_US_hap_M)) {
    /* Chart: '<S3>/Chart' */
    if (pr2_US_hap_DW.is_active_c3_pr2_US_hap == 0U) {
      pr2_US_hap_DW.is_active_c3_pr2_US_hap = 1U;
      pr2_US_hap_DW.is_c3_pr2_US_hap = pr2_US_hap_IN_drive_off;
      pr2_US_hap_B.out1 = 0.0;
      pr2_US_hap_B.out2 = 0.0;
      pr2_US_hap_DW.steering = 12.8;
      pr2_US_hap_DW.default_k = 128.0;
    } else {
      switch (pr2_US_hap_DW.is_c3_pr2_US_hap) {
       case pr2_US_hap_IN_drive_off:
        if (pr2_US_hap_B.TmpRTBAtChartInport1 == 1.0) {
          pr2_US_hap_DW.is_c3_pr2_US_hap = pr2_US_hap_IN_drive_on_adas_off;
          pr2_US_hap_B.out1 = pr2_US_hap_B.DataTypeConversion;
          pr2_US_hap_B.out2 = 256.0 - pr2_US_hap_B.DataTypeConversion;
        } else {
          pr2_US_hap_B.out1 = 0.0;
          pr2_US_hap_B.out2 = 0.0;
          pr2_US_hap_DW.steering = 12.8;
          pr2_US_hap_DW.default_k = 128.0;
        }
        break;

       case pr2_US_hap_IN_drive_on_adas_off:
        if (pr2_US_hap_B.TmpRTBAtChartInport1 == 0.0) {
          pr2_US_hap_B.buzzer = 0.0;
          pr2_US_hap_DW.is_c3_pr2_US_hap = pr2_US_hap_IN_drive_off;
          pr2_US_hap_B.out1 = 0.0;
          pr2_US_hap_B.out2 = 0.0;
          pr2_US_hap_DW.steering = 12.8;
          pr2_US_hap_DW.default_k = 128.0;
        } else if (pr2_US_hap_B.TmpRTBAtChartInport2 == 1.0) {
          pr2_US_hap_DW.default_k = 128.0;
          pr2_US_hap_B.buzzer = 0.0;
          pr2_US_hap_DW.is_c3_pr2_US_hap = pr2_US_hap_IN_drive_on_adas_on;
          pr2_US_hap_B.out1 = pr2_US_hap_DW.default_k;
          pr2_US_hap_B.out2 = pr2_US_hap_DW.default_k;
        } else {
          pr2_US_hap_B.out1 = pr2_US_hap_B.DataTypeConversion;
          pr2_US_hap_B.out2 = 256.0 - pr2_US_hap_B.DataTypeConversion;
        }
        break;

       case pr2_US_hap_IN_drive_on_adas_on:
        if (pr2_US_hap_B.TmpRTBAtChartInport2 == 0.0) {
          pr2_US_hap_DW.is_c3_pr2_US_hap = pr2_US_hap_IN_drive_on_adas_off;
          pr2_US_hap_B.out1 = pr2_US_hap_B.DataTypeConversion;
          pr2_US_hap_B.out2 = 256.0 - pr2_US_hap_B.DataTypeConversion;
        } else if (pr2_US_hap_B.Constant3 <= 10.0) {
          pr2_US_hap_DW.is_c3_pr2_US_hap = pr2_US__IN_drive_on_adas_on_FUS;
          pr2_US_hap_B.out1 = 0.0;
          pr2_US_hap_B.out2 = 0.0;
          pr2_US_hap_B.buzzer = 1.0;
        } else if (pr2_US_hap_B.Constant1 <= 10.0) {
          pr2_US_hap_DW.is_c3_pr2_US_hap = pr2_US__IN_drive_on_adas_on_RUS;
          pr2_US_hap_B.out1 = pr2_US_hap_DW.default_k - (10.0 -
            pr2_US_hap_B.Constant1) * pr2_US_hap_DW.steering;
          pr2_US_hap_B.out2 = (10.0 - pr2_US_hap_B.Constant1) *
            pr2_US_hap_DW.steering + pr2_US_hap_DW.default_k;
        } else if (pr2_US_hap_B.Constant <= 10.0) {
          pr2_US_hap_DW.is_c3_pr2_US_hap = pr2_US__IN_drive_on_adas_on_LUS;
          out1_tmp = (10.0 - pr2_US_hap_B.Constant) * pr2_US_hap_DW.steering;
          pr2_US_hap_B.out1 = out1_tmp + pr2_US_hap_DW.default_k;
          pr2_US_hap_B.out2 = pr2_US_hap_DW.default_k - out1_tmp;
        } else {
          pr2_US_hap_B.out1 = pr2_US_hap_DW.default_k;
          pr2_US_hap_B.out2 = pr2_US_hap_DW.default_k;
        }
        break;

       case pr2_US__IN_drive_on_adas_on_FUS:
        if ((pr2_US_hap_B.Constant > 10.0) && (pr2_US_hap_B.Constant1 > 10.0) &&
            (pr2_US_hap_B.Constant3 > 10.0)) {
          pr2_US_hap_B.buzzer = 0.0;
          pr2_US_hap_DW.is_c3_pr2_US_hap = pr2_US_hap_IN_drive_on_adas_on;
          pr2_US_hap_B.out1 = pr2_US_hap_DW.default_k;
          pr2_US_hap_B.out2 = pr2_US_hap_DW.default_k;
        } else if ((pr2_US_hap_B.Constant <= 10.0) && (pr2_US_hap_B.Constant1 <=
                    10.0) && (pr2_US_hap_B.Constant3 > 10.0)) {
          pr2_US_hap_B.buzzer = 0.0;
          pr2_US_hap_DW.is_c3_pr2_US_hap = pr2_US_IN_drive_on_adas_on_LRUS;
          out1_tmp = (pr2_US_hap_B.Constant - pr2_US_hap_B.Constant1) *
            pr2_US_hap_DW.steering;
          pr2_US_hap_B.out1 = pr2_US_hap_DW.default_k - out1_tmp;
          pr2_US_hap_B.out2 = out1_tmp + pr2_US_hap_DW.default_k;
        } else if ((pr2_US_hap_B.Constant1 <= 10.0) && (pr2_US_hap_B.Constant3 >
                    10.0)) {
          pr2_US_hap_B.buzzer = 0.0;
          pr2_US_hap_DW.is_c3_pr2_US_hap = pr2_US__IN_drive_on_adas_on_RUS;
          out1_tmp = (10.0 - pr2_US_hap_B.Constant1) * pr2_US_hap_DW.steering;
          pr2_US_hap_B.out1 = pr2_US_hap_DW.default_k - out1_tmp;
          pr2_US_hap_B.out2 = out1_tmp + pr2_US_hap_DW.default_k;
        } else if ((pr2_US_hap_B.Constant <= 10.0) && (pr2_US_hap_B.Constant3 >
                    10.0)) {
          pr2_US_hap_B.buzzer = 0.0;
          pr2_US_hap_DW.is_c3_pr2_US_hap = pr2_US__IN_drive_on_adas_on_LUS;
          out1_tmp = (10.0 - pr2_US_hap_B.Constant) * pr2_US_hap_DW.steering;
          pr2_US_hap_B.out1 = out1_tmp + pr2_US_hap_DW.default_k;
          pr2_US_hap_B.out2 = pr2_US_hap_DW.default_k - out1_tmp;
        } else if (pr2_US_hap_B.TmpRTBAtChartInport2 == 0.0) {
          pr2_US_hap_B.buzzer = 0.0;
          pr2_US_hap_DW.is_c3_pr2_US_hap = pr2_US_hap_IN_drive_on_adas_off;
          pr2_US_hap_B.out1 = pr2_US_hap_B.DataTypeConversion;
          pr2_US_hap_B.out2 = 256.0 - pr2_US_hap_B.DataTypeConversion;
        } else {
          pr2_US_hap_B.out1 = 0.0;
          pr2_US_hap_B.out2 = 0.0;
          pr2_US_hap_B.buzzer = 1.0;
        }
        break;

       case pr2_US_IN_drive_on_adas_on_LRUS:
        if (pr2_US_hap_B.Constant3 <= 10.0) {
          pr2_US_hap_DW.is_c3_pr2_US_hap = pr2_US__IN_drive_on_adas_on_FUS;
          pr2_US_hap_B.out1 = 0.0;
          pr2_US_hap_B.out2 = 0.0;
          pr2_US_hap_B.buzzer = 1.0;
        } else if (pr2_US_hap_B.Constant1 > 10.0) {
          pr2_US_hap_DW.is_c3_pr2_US_hap = pr2_US__IN_drive_on_adas_on_LUS;
          pr2_US_hap_B.out1 = (10.0 - pr2_US_hap_B.Constant) *
            pr2_US_hap_DW.steering + pr2_US_hap_DW.default_k;
          pr2_US_hap_B.out2 = pr2_US_hap_DW.default_k - (10.0 -
            pr2_US_hap_B.Constant) * pr2_US_hap_DW.steering;
        } else if (pr2_US_hap_B.Constant > 10.0) {
          pr2_US_hap_DW.is_c3_pr2_US_hap = pr2_US__IN_drive_on_adas_on_RUS;
          pr2_US_hap_B.out1 = pr2_US_hap_DW.default_k - (10.0 -
            pr2_US_hap_B.Constant1) * pr2_US_hap_DW.steering;
          pr2_US_hap_B.out2 = (10.0 - pr2_US_hap_B.Constant1) *
            pr2_US_hap_DW.steering + pr2_US_hap_DW.default_k;
        } else if (pr2_US_hap_B.TmpRTBAtChartInport2 == 0.0) {
          pr2_US_hap_DW.is_c3_pr2_US_hap = pr2_US_hap_IN_drive_on_adas_off;
          pr2_US_hap_B.out1 = pr2_US_hap_B.DataTypeConversion;
          pr2_US_hap_B.out2 = 256.0 - pr2_US_hap_B.DataTypeConversion;
        } else {
          out1_tmp = pr2_US_hap_B.Constant - pr2_US_hap_B.Constant1;
          pr2_US_hap_B.out1 = pr2_US_hap_DW.default_k - out1_tmp *
            pr2_US_hap_DW.steering;
          pr2_US_hap_B.out2 = out1_tmp * pr2_US_hap_DW.steering +
            pr2_US_hap_DW.default_k;
        }
        break;

       case pr2_US__IN_drive_on_adas_on_LUS:
        if (pr2_US_hap_B.Constant > 10.0) {
          pr2_US_hap_DW.is_c3_pr2_US_hap = pr2_US_hap_IN_drive_on_adas_on;
          pr2_US_hap_B.out1 = pr2_US_hap_DW.default_k;
          pr2_US_hap_B.out2 = pr2_US_hap_DW.default_k;
        } else if (pr2_US_hap_B.Constant1 <= 10.0) {
          pr2_US_hap_DW.is_c3_pr2_US_hap = pr2_US_IN_drive_on_adas_on_LRUS;
          pr2_US_hap_B.out1 = pr2_US_hap_DW.default_k - (pr2_US_hap_B.Constant -
            pr2_US_hap_B.Constant1) * pr2_US_hap_DW.steering;
          pr2_US_hap_B.out2 = (pr2_US_hap_B.Constant - pr2_US_hap_B.Constant1) *
            pr2_US_hap_DW.steering + pr2_US_hap_DW.default_k;
        } else if (pr2_US_hap_B.Constant3 <= 10.0) {
          pr2_US_hap_DW.is_c3_pr2_US_hap = pr2_US__IN_drive_on_adas_on_FUS;
          pr2_US_hap_B.out1 = 0.0;
          pr2_US_hap_B.out2 = 0.0;
          pr2_US_hap_B.buzzer = 1.0;
        } else if (pr2_US_hap_B.TmpRTBAtChartInport2 == 0.0) {
          pr2_US_hap_DW.is_c3_pr2_US_hap = pr2_US_hap_IN_drive_on_adas_off;
          pr2_US_hap_B.out1 = pr2_US_hap_B.DataTypeConversion;
          pr2_US_hap_B.out2 = 256.0 - pr2_US_hap_B.DataTypeConversion;
        } else {
          pr2_US_hap_B.out1 = (10.0 - pr2_US_hap_B.Constant) *
            pr2_US_hap_DW.steering + pr2_US_hap_DW.default_k;
          pr2_US_hap_B.out2 = pr2_US_hap_DW.default_k - (10.0 -
            pr2_US_hap_B.Constant) * pr2_US_hap_DW.steering;
        }
        break;

       default:
        /* case IN_drive_on_adas_on_RUS: */
        if (pr2_US_hap_B.Constant1 > 10.0) {
          pr2_US_hap_DW.is_c3_pr2_US_hap = pr2_US_hap_IN_drive_on_adas_on;
          pr2_US_hap_B.out1 = pr2_US_hap_DW.default_k;
          pr2_US_hap_B.out2 = pr2_US_hap_DW.default_k;
        } else if (pr2_US_hap_B.Constant3 <= 10.0) {
          pr2_US_hap_DW.is_c3_pr2_US_hap = pr2_US__IN_drive_on_adas_on_FUS;
          pr2_US_hap_B.out1 = 0.0;
          pr2_US_hap_B.out2 = 0.0;
          pr2_US_hap_B.buzzer = 1.0;
        } else if (pr2_US_hap_B.Constant <= 10.0) {
          pr2_US_hap_DW.is_c3_pr2_US_hap = pr2_US_IN_drive_on_adas_on_LRUS;
          pr2_US_hap_B.out1 = pr2_US_hap_DW.default_k - (pr2_US_hap_B.Constant -
            pr2_US_hap_B.Constant1) * pr2_US_hap_DW.steering;
          pr2_US_hap_B.out2 = (pr2_US_hap_B.Constant - pr2_US_hap_B.Constant1) *
            pr2_US_hap_DW.steering + pr2_US_hap_DW.default_k;
        } else if (pr2_US_hap_B.TmpRTBAtChartInport2 == 0.0) {
          pr2_US_hap_DW.is_c3_pr2_US_hap = pr2_US_hap_IN_drive_on_adas_off;
          pr2_US_hap_B.out1 = pr2_US_hap_B.DataTypeConversion;
          pr2_US_hap_B.out2 = 256.0 - pr2_US_hap_B.DataTypeConversion;
        } else {
          pr2_US_hap_B.out1 = pr2_US_hap_DW.default_k - (10.0 -
            pr2_US_hap_B.Constant1) * pr2_US_hap_DW.steering;
          pr2_US_hap_B.out2 = (10.0 - pr2_US_hap_B.Constant1) *
            pr2_US_hap_DW.steering + pr2_US_hap_DW.default_k;
        }
        break;
      }
    }

    /* End of Chart: '<S3>/Chart' */

    /* Constant: '<Root>/Constant2' */
    pr2_US_hap_B.Constant2 = pr2_US_hap_P.Constant2_Value;

    /* Chart: '<S3>/Chart1' */
    if (pr2_US_hap_DW.is_active_c1_pr2_US_hap == 0U) {
      pr2_US_hap_DW.is_active_c1_pr2_US_hap = 1U;
      pr2_US_hap_DW.is_c1_pr2_US_hap = pr2_US_hap_IN_adas_off;

      /* DataTypeConversion: '<Root>/Data Type Conversion1' */
      pr2_US_hap_B.DataTypeConversion1 = pr2_US_hap_B.out1;
      pr2_US_hap_B.rout2 = pr2_US_hap_B.out2;
    } else {
      switch (pr2_US_hap_DW.is_c1_pr2_US_hap) {
       case pr2_US_hap_IN_adas_off:
        if (pr2_US_hap_B.TmpRTBAtChart1Inport1 == 1.0) {
          pr2_US_hap_DW.is_c1_pr2_US_hap = pr2_US_hap_IN_adas_on;

          /* DataTypeConversion: '<Root>/Data Type Conversion1' */
          pr2_US_hap_B.DataTypeConversion1 = pr2_US_hap_B.out1;
          pr2_US_hap_B.rout2 = pr2_US_hap_B.out2;
        } else {
          /* DataTypeConversion: '<Root>/Data Type Conversion1' */
          pr2_US_hap_B.DataTypeConversion1 = pr2_US_hap_B.out1;
          pr2_US_hap_B.rout2 = pr2_US_hap_B.out2;
        }
        break;

       case pr2_US_hap_IN_adas_on:
        if (pr2_US_hap_B.TmpRTBAtChart1Inport1 == 0.0) {
          pr2_US_hap_DW.is_c1_pr2_US_hap = pr2_US_hap_IN_adas_off;

          /* DataTypeConversion: '<Root>/Data Type Conversion1' */
          pr2_US_hap_B.DataTypeConversion1 = pr2_US_hap_B.out1;
          pr2_US_hap_B.rout2 = pr2_US_hap_B.out2;
        } else if (pr2_US_hap_B.Constant2 <= 10.0) {
          pr2_US_hap_DW.is_c1_pr2_US_hap = pr2_US_hap_IN_adas_on_BUS;
          pr2_US_hap_B.DataTypeConversion1 = pr2_US_hap_B.out1 * 1.2;
          pr2_US_hap_B.rout2 = pr2_US_hap_B.DataTypeConversion1;
        } else {
          /* DataTypeConversion: '<Root>/Data Type Conversion1' */
          pr2_US_hap_B.DataTypeConversion1 = pr2_US_hap_B.out1;
          pr2_US_hap_B.rout2 = pr2_US_hap_B.out2;
        }
        break;

       default:
        /* case IN_adas_on_BUS: */
        if (pr2_US_hap_B.Constant2 > 10.0) {
          pr2_US_hap_DW.is_c1_pr2_US_hap = pr2_US_hap_IN_adas_on;

          /* DataTypeConversion: '<Root>/Data Type Conversion1' */
          pr2_US_hap_B.DataTypeConversion1 = pr2_US_hap_B.out1;
          pr2_US_hap_B.rout2 = pr2_US_hap_B.out2;
        } else if (pr2_US_hap_B.TmpRTBAtChart1Inport1 == 0.0) {
          pr2_US_hap_DW.is_c1_pr2_US_hap = pr2_US_hap_IN_adas_off;

          /* DataTypeConversion: '<Root>/Data Type Conversion1' */
          pr2_US_hap_B.DataTypeConversion1 = pr2_US_hap_B.out1;
          pr2_US_hap_B.rout2 = pr2_US_hap_B.out2;
        } else {
          pr2_US_hap_B.DataTypeConversion1 = pr2_US_hap_B.out1 * 1.2;
          pr2_US_hap_B.rout2 = pr2_US_hap_B.DataTypeConversion1;
        }
        break;
      }
    }

    /* End of Chart: '<S3>/Chart1' */
  }

  /* MATLABSystem: '<S4>/Encoder' */
  if (pr2_US_hap_DW.obj.SampleTime != pr2_US_hap_P.Encoder_SampleTime) {
    pr2_US_hap_DW.obj.SampleTime = pr2_US_hap_P.Encoder_SampleTime;
  }

  if (pr2_US_hap_DW.obj.TunablePropsChanged) {
    pr2_US_hap_DW.obj.TunablePropsChanged = false;
  }

  MW_EncoderRead(pr2_US_hap_DW.obj.Index, &tmp);
  if (rtmIsMajorTimeStep(pr2_US_hap_M)) {
    /* SampleTimeMath: '<S9>/TSamp' incorporates:
     *  MATLABSystem: '<S4>/Encoder'
     *
     * About '<S9>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     *  Multiplication by K = weightedTsampQuantized is being
     *  done implicitly by changing the scaling of the input signal.
     *  No work needs to be done here.  Downstream blocks may need
     *  to do work to handle the scaling of the output; this happens
     *  automatically.
     */
    rtb_TSamp = tmp;

    /* Sum: '<S9>/Diff' incorporates:
     *  SampleTimeMath: '<S9>/TSamp'
     *  UnitDelay: '<S9>/UD'
     *
     * About '<S9>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     *  Multiplication by K = weightedTsampQuantized is being
     *  done implicitly by changing the scaling of the input signal.
     *  No work needs to be done here.  Downstream blocks may need
     *  to do work to handle the scaling of the output; this happens
     *  automatically.
     *
     * Block description for '<S9>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S9>/UD':
     *
     *  Store in Global RAM
     */
    pr2_US_hap_B.Diff = rtb_TSamp - pr2_US_hap_DW.UD_DSTATE;

    /* DataTypeConversion: '<S4>/Data Type Conversion1' incorporates:
     *  Sum: '<S9>/Diff'
     *
     * Block description for '<S9>/Diff':
     *
     *  Add in CPU
     */
    pr2_US_hap_B.DataTypeConversion1_c = pr2_US_hap_B.Diff * 100L;

    /* Sum: '<Root>/Add1' */
    rtb_Add1 = pr2_US_hap_B.DataTypeConversion1 - (real_T)
      pr2_US_hap_B.DataTypeConversion1_c;

    /* Gain: '<S6>/Gain5' */
    pr2_US_hap_B.Gain5 = pr2_US_hap_P.KP * rtb_Add1;
  }

  /* Sum: '<S6>/Subtract1' */
  pr2_US_hap_B.Subtract1 = rtb_Gain1 + pr2_US_hap_B.Gain5;

  /* Saturate: '<Root>/Saturation' */
  if (pr2_US_hap_B.Subtract1 > pr2_US_hap_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    pr2_US_hap_B.Saturation = pr2_US_hap_P.Saturation_UpperSat;
  } else if (pr2_US_hap_B.Subtract1 < pr2_US_hap_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    pr2_US_hap_B.Saturation = pr2_US_hap_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    pr2_US_hap_B.Saturation = pr2_US_hap_B.Subtract1;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
   *  Gain: '<S5>/Gain1'
   */
  rtb_Gain1 = floor(255.0 / pr2_US_hap_P.Vlim * pr2_US_hap_B.Saturation);
  if (rtIsNaN(rtb_Gain1) || rtIsInf(rtb_Gain1)) {
    rtb_Gain1 = 0.0;
  } else {
    rtb_Gain1 = fmod(rtb_Gain1, 256.0);
  }

  /* DataTypeConversion: '<S5>/Data Type Conversion' */
  pr2_US_hap_B.DataTypeConversion_e = (uint8_T)(rtb_Gain1 < 0.0 ? (int16_T)
    (uint8_T)-(int8_T)(uint8_T)-rtb_Gain1 : (int16_T)(uint8_T)rtb_Gain1);

  /* DataTypeConversion: '<S5>/Data Type Conversion1' */
  pr2_US_hap_B.DataTypeConversion1_m = pr2_US_hap_B.DataTypeConversion_e;
  if (rtmIsMajorTimeStep(pr2_US_hap_M)) {
    /* SignalConversion generated from: '<Root>/Mux1' */
    pr2_US_hap_B.TmpSignalConversionAtTAQSigLogg[0] = 0.0;
    pr2_US_hap_B.TmpSignalConversionAtTAQSigLogg[1] =
      pr2_US_hap_B.DataTypeConversion1_m;
  }

  /* MATLABSystem: '<S5>/PWM' */
  pr2_US_hap_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
  MW_PWM_SetDutyCycle(pr2_US_hap_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, (real_T)
                      pr2_US_hap_B.DataTypeConversion_e);
  if (rtmIsMajorTimeStep(pr2_US_hap_M)) {
    /* Gain: '<S6>/Gain4' */
    pr2_US_hap_B.Gain4 = pr2_US_hap_P.KI * rtb_Add1;

    /* Gain: '<S4>/Gain2' incorporates:
     *  Sum: '<S9>/Diff'
     *
     * Block description for '<S9>/Diff':
     *
     *  Add in CPU
     */
    tmp_0 = (uint32_T)pr2_US_hap_P.Gain2_Gain;
    tmp_1 = (uint32_T)pr2_US_hap_B.Diff;
    sMultiWordMul(&tmp_0, 1, &tmp_1, 1, &pr2_US_hap_B.Gain2.chunks[0U], 2);

    /* DataTypeConversion: '<Root>/Data Type Conversion' */
    pr2_US_hap_B.DataTypeConversion_n = pr2_US_hap_B.rout2;

    /* Outport: '<Root>/Out1' */
    pr2_US_hap_Y.Out1 = pr2_US_hap_B.buzzer;

    /* RateTransition generated from: '<Root>/Display3' */
    switch (pr2_US_hap_DW.TmpRTBAtDisplay3Inport1_write_b) {
     case 0:
      pr2_US_hap_DW.TmpRTBAtDisplay3Inport1_read_bu = 1;
      break;

     case 1:
      pr2_US_hap_DW.TmpRTBAtDisplay3Inport1_read_bu = 0;
      break;

     default:
      pr2_US_hap_DW.TmpRTBAtDisplay3Inport1_read_bu =
        pr2_US_hap_DW.TmpRTBAtDisplay3Inport1_last_bu;
      break;
    }

    if (pr2_US_hap_DW.TmpRTBAtDisplay3Inport1_read_bu != 0) {
      /* RateTransition generated from: '<Root>/Display3' */
      pr2_US_hap_B.TmpRTBAtDisplay3Inport1 =
        pr2_US_hap_DW.TmpRTBAtDisplay3Inport1_Buffer1;
    } else {
      /* RateTransition generated from: '<Root>/Display3' */
      pr2_US_hap_B.TmpRTBAtDisplay3Inport1 =
        pr2_US_hap_DW.TmpRTBAtDisplay3Inport1_Buffer0;
    }

    pr2_US_hap_DW.TmpRTBAtDisplay3Inport1_read_bu = -1;

    /* End of RateTransition generated from: '<Root>/Display3' */

    /* RateTransition generated from: '<Root>/Display2' */
    switch (pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_write_b) {
     case 0:
      pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_read_bu = 1;
      break;

     case 1:
      pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_read_bu = 0;
      break;

     default:
      pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_read_bu =
        pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_last_bu;
      break;
    }

    if (pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_read_bu != 0) {
      /* RateTransition generated from: '<Root>/Display2' */
      pr2_US_hap_B.TmpRTBAtDisplay2Inport1 =
        pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_Buffer1;
    } else {
      /* RateTransition generated from: '<Root>/Display2' */
      pr2_US_hap_B.TmpRTBAtDisplay2Inport1 =
        pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_Buffer0;
    }

    pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_read_bu = -1;

    /* End of RateTransition generated from: '<Root>/Display2' */
  }

  if (rtmIsMajorTimeStep(pr2_US_hap_M)) {
    if (rtmIsMajorTimeStep(pr2_US_hap_M)) {
      /* Update for UnitDelay: '<S9>/UD' incorporates:
       *  SampleTimeMath: '<S9>/TSamp'
       *
       * About '<S9>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       *
       * Block description for '<S9>/UD':
       *
       *  Store in Global RAM
       */
      pr2_US_hap_DW.UD_DSTATE = rtb_TSamp;
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((pr2_US_hap_M->Timing.clockTick0 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(pr2_US_hap_M)) {/* Sample time: [0.01s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((pr2_US_hap_M->Timing.clockTick1 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(pr2_US_hap_M)) {
    rt_ertODEUpdateContinuousStates(&pr2_US_hap_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++pr2_US_hap_M->Timing.clockTick0;
    pr2_US_hap_M->Timing.t[0] = rtsiGetSolverStopTime(&pr2_US_hap_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      pr2_US_hap_M->Timing.clockTick1++;
    }

    switch (pr2_US_hap_M->Timing.rtmDbBufReadBuf2) {
     case 0:
      pr2_US_hap_M->Timing.rtmDbBufWriteBuf2 = 1;
      break;

     case 1:
      pr2_US_hap_M->Timing.rtmDbBufWriteBuf2 = 0;
      break;

     default:
      pr2_US_hap_M->Timing.rtmDbBufWriteBuf2 =
        !pr2_US_hap_M->Timing.rtmDbBufLastBufWr2;
      break;
    }

    pr2_US_hap_M->Timing.rtmDbBufClockTick2
      [pr2_US_hap_M->Timing.rtmDbBufWriteBuf2] = pr2_US_hap_M->Timing.clockTick0;
    pr2_US_hap_M->Timing.rtmDbBufLastBufWr2 =
      pr2_US_hap_M->Timing.rtmDbBufWriteBuf2;
    pr2_US_hap_M->Timing.rtmDbBufWriteBuf2 = 0xFF;
    switch (pr2_US_hap_M->Timing.rtmDbBufReadBuf3) {
     case 0:
      pr2_US_hap_M->Timing.rtmDbBufWriteBuf3 = 1;
      break;

     case 1:
      pr2_US_hap_M->Timing.rtmDbBufWriteBuf3 = 0;
      break;

     default:
      pr2_US_hap_M->Timing.rtmDbBufWriteBuf3 =
        !pr2_US_hap_M->Timing.rtmDbBufLastBufWr3;
      break;
    }

    pr2_US_hap_M->Timing.rtmDbBufClockTick3
      [pr2_US_hap_M->Timing.rtmDbBufWriteBuf3] = pr2_US_hap_M->Timing.clockTick0;
    pr2_US_hap_M->Timing.rtmDbBufLastBufWr3 =
      pr2_US_hap_M->Timing.rtmDbBufWriteBuf3;
    pr2_US_hap_M->Timing.rtmDbBufWriteBuf3 = 0xFF;
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void pr2_US_hap_derivatives(void)
{
  XDot_pr2_US_hap_T *_rtXdot;
  _rtXdot = ((XDot_pr2_US_hap_T *) pr2_US_hap_M->derivs);

  /* Derivatives for Integrator: '<S6>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = pr2_US_hap_B.Gain4;
}

/* Model initialize function */
void pr2_US_hap_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&pr2_US_hap_M->solverInfo,
                          &pr2_US_hap_M->Timing.simTimeStep);
    rtsiSetTPtr(&pr2_US_hap_M->solverInfo, &rtmGetTPtr(pr2_US_hap_M));
    rtsiSetStepSizePtr(&pr2_US_hap_M->solverInfo,
                       &pr2_US_hap_M->Timing.stepSize0);
    rtsiSetdXPtr(&pr2_US_hap_M->solverInfo, &pr2_US_hap_M->derivs);
    rtsiSetContStatesPtr(&pr2_US_hap_M->solverInfo, (real_T **)
                         &pr2_US_hap_M->contStates);
    rtsiSetNumContStatesPtr(&pr2_US_hap_M->solverInfo,
      &pr2_US_hap_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&pr2_US_hap_M->solverInfo,
      &pr2_US_hap_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&pr2_US_hap_M->solverInfo,
      &pr2_US_hap_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&pr2_US_hap_M->solverInfo,
      &pr2_US_hap_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&pr2_US_hap_M->solverInfo, (boolean_T**)
      &pr2_US_hap_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&pr2_US_hap_M->solverInfo, (&rtmGetErrorStatus
      (pr2_US_hap_M)));
    rtsiSetRTModelPtr(&pr2_US_hap_M->solverInfo, pr2_US_hap_M);
  }

  rtsiSetSimTimeStep(&pr2_US_hap_M->solverInfo, MAJOR_TIME_STEP);
  pr2_US_hap_M->intgData.y = pr2_US_hap_M->odeY;
  pr2_US_hap_M->intgData.f[0] = pr2_US_hap_M->odeF[0];
  pr2_US_hap_M->intgData.f[1] = pr2_US_hap_M->odeF[1];
  pr2_US_hap_M->intgData.f[2] = pr2_US_hap_M->odeF[2];
  pr2_US_hap_M->contStates = ((X_pr2_US_hap_T *) &pr2_US_hap_X);
  pr2_US_hap_M->contStateDisabled = ((XDis_pr2_US_hap_T *) &pr2_US_hap_XDis);
  pr2_US_hap_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&pr2_US_hap_M->solverInfo, (void *)&pr2_US_hap_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&pr2_US_hap_M->solverInfo, false);
  rtsiSetSolverName(&pr2_US_hap_M->solverInfo,"ode3");
  rtmSetTPtr(pr2_US_hap_M, &pr2_US_hap_M->Timing.tArray[0]);
  rtmSetTFinal(pr2_US_hap_M, -1);
  pr2_US_hap_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  pr2_US_hap_M->Sizes.checksums[0] = (1571690586U);
  pr2_US_hap_M->Sizes.checksums[1] = (1888660112U);
  pr2_US_hap_M->Sizes.checksums[2] = (1441715571U);
  pr2_US_hap_M->Sizes.checksums[3] = (3332317149U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[8];
    pr2_US_hap_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&pr2_US_hap_DW.SW1PUSH_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&pr2_US_hap_DW.SW1PUSH1_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(pr2_US_hap_M->extModeInfo,
      &pr2_US_hap_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(pr2_US_hap_M->extModeInfo, pr2_US_hap_M->Sizes.checksums);
    rteiSetTPtr(pr2_US_hap_M->extModeInfo, rtmGetTPtr(pr2_US_hap_M));
  }

  pr2_US_hap_M->Timing.rtmDbBufReadBuf2 = 0xFF;
  pr2_US_hap_M->Timing.rtmDbBufWriteBuf2 = 0xFF;
  pr2_US_hap_M->Timing.rtmDbBufLastBufWr2 = 0;
  pr2_US_hap_M->Timing.rtmDbBufReadBuf3 = 0xFF;
  pr2_US_hap_M->Timing.rtmDbBufWriteBuf3 = 0xFF;
  pr2_US_hap_M->Timing.rtmDbBufLastBufWr3 = 0;

  /* Start for Constant: '<Root>/Constant3' */
  pr2_US_hap_B.Constant3 = pr2_US_hap_P.Constant3_Value;

  /* Start for Constant: '<Root>/Constant' */
  pr2_US_hap_B.Constant = pr2_US_hap_P.Constant_Value_n;

  /* Start for Constant: '<Root>/Constant1' */
  pr2_US_hap_B.Constant1 = pr2_US_hap_P.Constant1_Value;

  /* Start for Constant: '<Root>/Constant2' */
  pr2_US_hap_B.Constant2 = pr2_US_hap_P.Constant2_Value;

  /* InitializeConditions for Integrator: '<S6>/Integrator1' */
  pr2_US_hap_X.Integrator1_CSTATE = pr2_US_hap_P.Integrator1_IC;

  /* InitializeConditions for RateTransition generated from: '<S3>/Chart1' */
  pr2_US_hap_DW.TmpRTBAtChart1Inport1_Buffer0 =
    pr2_US_hap_P.TmpRTBAtChart1Inport1_InitialCo;
  pr2_US_hap_DW.TmpRTBAtChart1Inport1_write_buf = -1;
  pr2_US_hap_DW.TmpRTBAtChart1Inport1_read_buf = -1;

  /* InitializeConditions for RateTransition generated from: '<S3>/Chart' */
  pr2_US_hap_DW.TmpRTBAtChartInport1_Buffer0 =
    pr2_US_hap_P.TmpRTBAtChartInport1_InitialCon;
  pr2_US_hap_DW.TmpRTBAtChartInport1_write_buf = -1;
  pr2_US_hap_DW.TmpRTBAtChartInport1_read_buf = -1;

  /* InitializeConditions for RateTransition generated from: '<S3>/Chart' */
  pr2_US_hap_DW.TmpRTBAtChartInport2_Buffer0 =
    pr2_US_hap_P.TmpRTBAtChartInport2_InitialCon;
  pr2_US_hap_DW.TmpRTBAtChartInport2_write_buf = -1;
  pr2_US_hap_DW.TmpRTBAtChartInport2_read_buf = -1;

  /* InitializeConditions for UnitDelay: '<S9>/UD'
   *
   * Block description for '<S9>/UD':
   *
   *  Store in Global RAM
   */
  pr2_US_hap_DW.UD_DSTATE = pr2_US_hap_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for RateTransition generated from: '<Root>/Display3' */
  pr2_US_hap_DW.TmpRTBAtDisplay3Inport1_Buffer0 =
    pr2_US_hap_P.TmpRTBAtDisplay3Inport1_Initial;
  pr2_US_hap_DW.TmpRTBAtDisplay3Inport1_write_b = -1;
  pr2_US_hap_DW.TmpRTBAtDisplay3Inport1_read_bu = -1;

  /* InitializeConditions for RateTransition generated from: '<Root>/Display2' */
  pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_Buffer0 =
    pr2_US_hap_P.TmpRTBAtDisplay2Inport1_Initial;
  pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_write_b = -1;
  pr2_US_hap_DW.TmpRTBAtDisplay2Inport1_read_bu = -1;

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt(SW1)' incorporates:
   *  SubSystem: '<Root>/SW1 PUSH'
   */

  /* System initialize for function-call system: '<Root>/SW1 PUSH' */

  /* Asynchronous task (with no priority assigned)
   * reads absolute time */
  switch (pr2_US_hap_M->Timing.rtmDbBufWriteBuf2) {
   case 0:
    pr2_US_hap_M->Timing.rtmDbBufReadBuf2 = 1;
    break;

   case 1:
    pr2_US_hap_M->Timing.rtmDbBufReadBuf2 = 0;
    break;

   default:
    pr2_US_hap_M->Timing.rtmDbBufReadBuf2 =
      pr2_US_hap_M->Timing.rtmDbBufLastBufWr2;
    break;
  }

  pr2_US_hap_M->Timing.clockTick2 = pr2_US_hap_M->
    Timing.rtmDbBufClockTick2[pr2_US_hap_M->Timing.rtmDbBufReadBuf2];
  pr2_US_hap_M->Timing.rtmDbBufReadBuf2 = 0xFF;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  pr2_US_hap_DW.Delay_DSTATE_a = pr2_US_hap_P.Delay_InitialCondition;

  /* SystemInitialize for Sum: '<S1>/Add' incorporates:
   *  Outport: '<S1>/sw1'
   */
  pr2_US_hap_B.Add_h = pr2_US_hap_P.sw1_Y0;

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(20), &MW_ISR_20, RISING);

  /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt(SW1)' */

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt(SW2)' incorporates:
   *  SubSystem: '<Root>/SW1 PUSH1'
   */

  /* System initialize for function-call system: '<Root>/SW1 PUSH1' */

  /* Asynchronous task (with no priority assigned)
   * reads absolute time */
  switch (pr2_US_hap_M->Timing.rtmDbBufWriteBuf3) {
   case 0:
    pr2_US_hap_M->Timing.rtmDbBufReadBuf3 = 1;
    break;

   case 1:
    pr2_US_hap_M->Timing.rtmDbBufReadBuf3 = 0;
    break;

   default:
    pr2_US_hap_M->Timing.rtmDbBufReadBuf3 =
      pr2_US_hap_M->Timing.rtmDbBufLastBufWr3;
    break;
  }

  pr2_US_hap_M->Timing.clockTick3 = pr2_US_hap_M->
    Timing.rtmDbBufClockTick3[pr2_US_hap_M->Timing.rtmDbBufReadBuf3];
  pr2_US_hap_M->Timing.rtmDbBufReadBuf3 = 0xFF;

  /* InitializeConditions for Delay: '<S2>/Delay' */
  pr2_US_hap_DW.Delay_DSTATE = pr2_US_hap_P.Delay_InitialCondition_e;

  /* SystemInitialize for Sum: '<S2>/Add' incorporates:
   *  Outport: '<S2>/sw1'
   */
  pr2_US_hap_B.Add = pr2_US_hap_P.sw1_Y0_e;

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(21), &MW_ISR_21, RISING);

  /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt(SW2)' */

  /* Start for MATLABSystem: '<Root>/가변저항' */
  pr2_US_hap_DW.obj_n.matlabCodegenIsDeleted = false;
  pr2_US_hap_DW.obj_n.SampleTime = pr2_US_hap_P._SampleTime;
  pr2_US_hap_DW.obj_n.isInitialized = 1L;
  pr2_US_hap_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(62UL);
  pr2_US_hap_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Encoder' */
  pr2_US_hap_DW.obj.Index = 0U;
  pr2_US_hap_DW.obj.matlabCodegenIsDeleted = false;
  pr2_US_hap_DW.obj.SampleTime = pr2_US_hap_P.Encoder_SampleTime;
  pr2_US_hap_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &pr2_US_hap_DW.obj.Index);
  pr2_US_hap_DW.obj.isSetupComplete = true;
  pr2_US_hap_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S4>/Encoder' */
  MW_EncoderReset(pr2_US_hap_DW.obj.Index);

  /* Start for MATLABSystem: '<S5>/PWM' */
  pr2_US_hap_DW.obj_b.matlabCodegenIsDeleted = false;
  pr2_US_hap_DW.obj_b.isInitialized = 1L;
  pr2_US_hap_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
  pr2_US_hap_DW.obj_b.isSetupComplete = true;
}

/* Model terminate function */
void pr2_US_hap_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/가변저항' */
  if (!pr2_US_hap_DW.obj_n.matlabCodegenIsDeleted) {
    pr2_US_hap_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((pr2_US_hap_DW.obj_n.isInitialized == 1L) &&
        pr2_US_hap_DW.obj_n.isSetupComplete) {
      pr2_US_hap_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(62UL);
      MW_AnalogIn_Close(pr2_US_hap_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/가변저항' */

  /* Terminate for MATLABSystem: '<S4>/Encoder' */
  if (!pr2_US_hap_DW.obj.matlabCodegenIsDeleted) {
    pr2_US_hap_DW.obj.matlabCodegenIsDeleted = true;
    if ((pr2_US_hap_DW.obj.isInitialized == 1L) &&
        pr2_US_hap_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Encoder' */
  /* Terminate for MATLABSystem: '<S5>/PWM' */
  if (!pr2_US_hap_DW.obj_b.matlabCodegenIsDeleted) {
    pr2_US_hap_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((pr2_US_hap_DW.obj_b.isInitialized == 1L) &&
        pr2_US_hap_DW.obj_b.isSetupComplete) {
      pr2_US_hap_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(pr2_US_hap_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      pr2_US_hap_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(pr2_US_hap_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
