/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ex2_encoder.c
 *
 * Code generated for Simulink model 'ex2_encoder'.
 *
 * Model version                  : 1.20
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Feb  7 17:17:19 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ex2_encoder.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "ex2_encoder_private.h"

/* Block signals (default storage) */
B_ex2_encoder_T ex2_encoder_B;

/* Continuous states */
X_ex2_encoder_T ex2_encoder_X;

/* Disabled State Vector */
XDis_ex2_encoder_T ex2_encoder_XDis;

/* Block states (default storage) */
DW_ex2_encoder_T ex2_encoder_DW;

/* Real-time model */
static RT_MODEL_ex2_encoder_T ex2_encoder_M_;
RT_MODEL_ex2_encoder_T *const ex2_encoder_M = &ex2_encoder_M_;
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

int32_T MultiWord2sLong(const uint32_T u[])
{
  return (int32_T)u[0];
}

void sMultiWordShr(const uint32_T u1[], int16_T n1, uint16_T n2, uint32_T y[],
                   int16_T n)
{
  uint32_T u1i;
  uint32_T yi;
  uint32_T ys;
  int16_T i;
  int16_T i1;
  int16_T nb;
  int16_T nc;
  uint16_T nr;
  nb = (int16_T)(n2 >> 5);
  i = 0;
  ys = (u1[n1 - 1] & 2147483648UL) != 0UL ? MAX_uint32_T : 0UL;
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

      y[i] = (nc < n1 ? u1[nc] : ys) << (32U - nr) | u1i >> nr;
      i++;
    } else {
      for (i1 = nb; i1 < nc; i1++) {
        y[i] = u1[i1];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
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
  ex2_encoder_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ex2_encoder_step();
  ex2_encoder_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ex2_encoder_step();
  ex2_encoder_derivatives();

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
void ex2_encoder_step(void)
{
  /* local block i/o variables */
  int32_T rtb_TSamp;
  if (rtmIsMajorTimeStep(ex2_encoder_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&ex2_encoder_M->solverInfo,
                          ((ex2_encoder_M->Timing.clockTick0+1)*
      ex2_encoder_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ex2_encoder_M)) {
    ex2_encoder_M->Timing.t[0] = rtsiGetT(&ex2_encoder_M->solverInfo);
  }

  {
    int128m_T tmp_2;
    real_T lastTime;
    real_T rtb_Add1;
    real_T rtb_Gain1;
    real_T *lastU;
    int32_T tmp;
    uint32_T tmp_0;
    uint32_T tmp_1;
    static const int64m_T tmp_3 = { { 25UL, 0UL }/* chunks */
    };

    /* Step: '<Root>/Step' */
    if (ex2_encoder_M->Timing.t[0] < ex2_encoder_P.Step_Time) {
      /* Step: '<Root>/Step' */
      ex2_encoder_B.Step = ex2_encoder_P.Step_Y0;
    } else {
      /* Step: '<Root>/Step' */
      ex2_encoder_B.Step = ex2_encoder_P.Step_YFinal;
    }

    /* End of Step: '<Root>/Step' */
    if (rtmIsMajorTimeStep(ex2_encoder_M)) {
      /* SignalConversion generated from: '<Root>/Mux1' */
      ex2_encoder_B.TmpSignalConversionAtTAQSigLogg[0] = ex2_encoder_B.Step;
      ex2_encoder_B.TmpSignalConversionAtTAQSigLogg[1] = 0.0;
    }

    /* MATLABSystem: '<S1>/Encoder' */
    if (ex2_encoder_DW.obj.SampleTime != ex2_encoder_P.Encoder_SampleTime) {
      ex2_encoder_DW.obj.SampleTime = ex2_encoder_P.Encoder_SampleTime;
    }

    if (ex2_encoder_DW.obj.TunablePropsChanged) {
      ex2_encoder_DW.obj.TunablePropsChanged = false;
    }

    MW_EncoderRead(ex2_encoder_DW.obj.Index, &tmp);
    if (rtmIsMajorTimeStep(ex2_encoder_M)) {
      /* SampleTimeMath: '<S4>/TSamp' incorporates:
       *  MATLABSystem: '<S1>/Encoder'
       *
       * About '<S4>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       */
      rtb_TSamp = tmp;

      /* Gain: '<S1>/Gain1' incorporates:
       *  SampleTimeMath: '<S4>/TSamp'
       *  Sum: '<S4>/Diff'
       *  UnitDelay: '<S4>/UD'
       *
       * About '<S4>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       *
       * Block description for '<S4>/Diff':
       *
       *  Add in CPU
       *
       * Block description for '<S4>/UD':
       *
       *  Store in Global RAM
       */
      tmp_0 = (uint32_T)ex2_encoder_P.Gain1_Gain_n;
      tmp_1 = (uint32_T)(rtb_TSamp - ex2_encoder_DW.UD_DSTATE);
      sMultiWordMul(&tmp_0, 1, &tmp_1, 1, &ex2_encoder_B.Gain1.chunks[0U], 2);

      /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
       *  Gain: '<S1>/Gain1'
       */
      sMultiWordMul(&ex2_encoder_B.Gain1.chunks[0U], 2, &tmp_3.chunks[0U], 2,
                    &tmp_2.chunks[0U], 4);
      sMultiWordShr(&tmp_2.chunks[0U], 4, 31U, &ex2_encoder_B.r.chunks[0U], 4);

      /* DataTypeConversion: '<S1>/Data Type Conversion1' */
      ex2_encoder_B.DataTypeConversion1 = MultiWord2sLong
        (&ex2_encoder_B.r.chunks[0U]);
    }

    /* Sum: '<Root>/Add1' */
    rtb_Add1 = ex2_encoder_B.Step - (real_T)ex2_encoder_B.DataTypeConversion1;

    /* Gain: '<S3>/Gain6' */
    ex2_encoder_B.Gain6 = ex2_encoder_P.KD * rtb_Add1;

    /* Derivative: '<S3>/Derivative1' */
    rtb_Gain1 = ex2_encoder_M->Timing.t[0];
    if ((ex2_encoder_DW.TimeStampA >= rtb_Gain1) && (ex2_encoder_DW.TimeStampB >=
         rtb_Gain1)) {
      rtb_Gain1 = 0.0;
    } else {
      lastTime = ex2_encoder_DW.TimeStampA;
      lastU = &ex2_encoder_DW.LastUAtTimeA;
      if (ex2_encoder_DW.TimeStampA < ex2_encoder_DW.TimeStampB) {
        if (ex2_encoder_DW.TimeStampB < rtb_Gain1) {
          lastTime = ex2_encoder_DW.TimeStampB;
          lastU = &ex2_encoder_DW.LastUAtTimeB;
        }
      } else if (ex2_encoder_DW.TimeStampA >= rtb_Gain1) {
        lastTime = ex2_encoder_DW.TimeStampB;
        lastU = &ex2_encoder_DW.LastUAtTimeB;
      }

      rtb_Gain1 = (ex2_encoder_B.Gain6 - *lastU) / (rtb_Gain1 - lastTime);
    }

    /* End of Derivative: '<S3>/Derivative1' */

    /* Sum: '<S3>/Subtract1' incorporates:
     *  Gain: '<S3>/Gain5'
     *  Integrator: '<S3>/Integrator1'
     */
    ex2_encoder_B.Saturation = (ex2_encoder_P.KP * rtb_Add1 +
      ex2_encoder_X.Integrator1_CSTATE) + rtb_Gain1;

    /* Saturate: '<Root>/Saturation' */
    if (ex2_encoder_B.Saturation > ex2_encoder_P.Saturation_UpperSat) {
      /* Sum: '<S3>/Subtract1' incorporates:
       *  Saturate: '<Root>/Saturation'
       */
      ex2_encoder_B.Saturation = ex2_encoder_P.Saturation_UpperSat;
    } else if (ex2_encoder_B.Saturation < ex2_encoder_P.Saturation_LowerSat) {
      /* Sum: '<S3>/Subtract1' incorporates:
       *  Saturate: '<Root>/Saturation'
       */
      ex2_encoder_B.Saturation = ex2_encoder_P.Saturation_LowerSat;
    }

    /* End of Saturate: '<Root>/Saturation' */
    if (rtmIsMajorTimeStep(ex2_encoder_M)) {
    }

    /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
     *  Gain: '<S2>/Gain1'
     */
    rtb_Gain1 = floor(ex2_encoder_P.Gain1_Gain * ex2_encoder_B.Saturation);
    if (rtIsNaN(rtb_Gain1) || rtIsInf(rtb_Gain1)) {
      rtb_Gain1 = 0.0;
    } else {
      rtb_Gain1 = fmod(rtb_Gain1, 256.0);
    }

    /* DataTypeConversion: '<S2>/Data Type Conversion' */
    ex2_encoder_B.DataTypeConversion = (uint8_T)(rtb_Gain1 < 0.0 ? (int16_T)
      (uint8_T)-(int8_T)(uint8_T)-rtb_Gain1 : (int16_T)(uint8_T)rtb_Gain1);

    /* MATLABSystem: '<S2>/PWM' */
    ex2_encoder_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
    MW_PWM_SetDutyCycle(ex2_encoder_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE, (real_T)
                        ex2_encoder_B.DataTypeConversion);
    if (rtmIsMajorTimeStep(ex2_encoder_M)) {
    }

    /* Gain: '<S3>/Gain4' */
    ex2_encoder_B.Gain4 = ex2_encoder_P.KI * rtb_Add1;
    if (rtmIsMajorTimeStep(ex2_encoder_M)) {
      /* Gain: '<S1>/Gain2' incorporates:
       *  Gain: '<S1>/Gain1'
       */
      sMultiWordMul(&ex2_encoder_P.Gain2_Gain.chunks[0U], 2,
                    &ex2_encoder_B.Gain1.chunks[0U], 2, &tmp_2.chunks[0U], 4);

      /* Gain: '<S1>/Gain2' incorporates:
       *  DataTypeConversion: '<S1>/Data Type Conversion1'
       */
      ex2_encoder_B.Gain2 = tmp_2;
    }
  }

  if (rtmIsMajorTimeStep(ex2_encoder_M)) {
    real_T *lastU;
    if (rtmIsMajorTimeStep(ex2_encoder_M)) {
      /* Update for UnitDelay: '<S4>/UD' incorporates:
       *  SampleTimeMath: '<S4>/TSamp'
       *
       * About '<S4>/TSamp':
       *  y = u * K where K = 1 / ( w * Ts )
       *  Multiplication by K = weightedTsampQuantized is being
       *  done implicitly by changing the scaling of the input signal.
       *  No work needs to be done here.  Downstream blocks may need
       *  to do work to handle the scaling of the output; this happens
       *  automatically.
       *
       * Block description for '<S4>/UD':
       *
       *  Store in Global RAM
       */
      ex2_encoder_DW.UD_DSTATE = rtb_TSamp;
    }

    /* Update for Derivative: '<S3>/Derivative1' */
    if (ex2_encoder_DW.TimeStampA == (rtInf)) {
      ex2_encoder_DW.TimeStampA = ex2_encoder_M->Timing.t[0];
      lastU = &ex2_encoder_DW.LastUAtTimeA;
    } else if (ex2_encoder_DW.TimeStampB == (rtInf)) {
      ex2_encoder_DW.TimeStampB = ex2_encoder_M->Timing.t[0];
      lastU = &ex2_encoder_DW.LastUAtTimeB;
    } else if (ex2_encoder_DW.TimeStampA < ex2_encoder_DW.TimeStampB) {
      ex2_encoder_DW.TimeStampA = ex2_encoder_M->Timing.t[0];
      lastU = &ex2_encoder_DW.LastUAtTimeA;
    } else {
      ex2_encoder_DW.TimeStampB = ex2_encoder_M->Timing.t[0];
      lastU = &ex2_encoder_DW.LastUAtTimeB;
    }

    *lastU = ex2_encoder_B.Gain6;

    /* End of Update for Derivative: '<S3>/Derivative1' */
    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((ex2_encoder_M->Timing.clockTick0 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(ex2_encoder_M)) {/* Sample time: [0.01s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((ex2_encoder_M->Timing.clockTick1 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(ex2_encoder_M)) {
    rt_ertODEUpdateContinuousStates(&ex2_encoder_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++ex2_encoder_M->Timing.clockTick0;
    ex2_encoder_M->Timing.t[0] = rtsiGetSolverStopTime
      (&ex2_encoder_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      ex2_encoder_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void ex2_encoder_derivatives(void)
{
  XDot_ex2_encoder_T *_rtXdot;
  _rtXdot = ((XDot_ex2_encoder_T *) ex2_encoder_M->derivs);

  /* Derivatives for Integrator: '<S3>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = ex2_encoder_B.Gain4;
}

/* Model initialize function */
void ex2_encoder_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ex2_encoder_M->solverInfo,
                          &ex2_encoder_M->Timing.simTimeStep);
    rtsiSetTPtr(&ex2_encoder_M->solverInfo, &rtmGetTPtr(ex2_encoder_M));
    rtsiSetStepSizePtr(&ex2_encoder_M->solverInfo,
                       &ex2_encoder_M->Timing.stepSize0);
    rtsiSetdXPtr(&ex2_encoder_M->solverInfo, &ex2_encoder_M->derivs);
    rtsiSetContStatesPtr(&ex2_encoder_M->solverInfo, (real_T **)
                         &ex2_encoder_M->contStates);
    rtsiSetNumContStatesPtr(&ex2_encoder_M->solverInfo,
      &ex2_encoder_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ex2_encoder_M->solverInfo,
      &ex2_encoder_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ex2_encoder_M->solverInfo,
      &ex2_encoder_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ex2_encoder_M->solverInfo,
      &ex2_encoder_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&ex2_encoder_M->solverInfo, (boolean_T**)
      &ex2_encoder_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&ex2_encoder_M->solverInfo, (&rtmGetErrorStatus
      (ex2_encoder_M)));
    rtsiSetRTModelPtr(&ex2_encoder_M->solverInfo, ex2_encoder_M);
  }

  rtsiSetSimTimeStep(&ex2_encoder_M->solverInfo, MAJOR_TIME_STEP);
  ex2_encoder_M->intgData.y = ex2_encoder_M->odeY;
  ex2_encoder_M->intgData.f[0] = ex2_encoder_M->odeF[0];
  ex2_encoder_M->intgData.f[1] = ex2_encoder_M->odeF[1];
  ex2_encoder_M->intgData.f[2] = ex2_encoder_M->odeF[2];
  ex2_encoder_M->contStates = ((X_ex2_encoder_T *) &ex2_encoder_X);
  ex2_encoder_M->contStateDisabled = ((XDis_ex2_encoder_T *) &ex2_encoder_XDis);
  ex2_encoder_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&ex2_encoder_M->solverInfo, (void *)&ex2_encoder_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&ex2_encoder_M->solverInfo, false);
  rtsiSetSolverName(&ex2_encoder_M->solverInfo,"ode3");
  rtmSetTPtr(ex2_encoder_M, &ex2_encoder_M->Timing.tArray[0]);
  rtmSetTFinal(ex2_encoder_M, -1);
  ex2_encoder_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  ex2_encoder_M->Sizes.checksums[0] = (798076383U);
  ex2_encoder_M->Sizes.checksums[1] = (2585667782U);
  ex2_encoder_M->Sizes.checksums[2] = (202362020U);
  ex2_encoder_M->Sizes.checksums[3] = (434709873U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    ex2_encoder_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ex2_encoder_M->extModeInfo,
      &ex2_encoder_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ex2_encoder_M->extModeInfo,
                        ex2_encoder_M->Sizes.checksums);
    rteiSetTPtr(ex2_encoder_M->extModeInfo, rtmGetTPtr(ex2_encoder_M));
  }

  /* InitializeConditions for UnitDelay: '<S4>/UD'
   *
   * Block description for '<S4>/UD':
   *
   *  Store in Global RAM
   */
  ex2_encoder_DW.UD_DSTATE = ex2_encoder_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for Integrator: '<S3>/Integrator1' */
  ex2_encoder_X.Integrator1_CSTATE = ex2_encoder_P.Integrator1_IC;

  /* InitializeConditions for Derivative: '<S3>/Derivative1' */
  ex2_encoder_DW.TimeStampA = (rtInf);
  ex2_encoder_DW.TimeStampB = (rtInf);

  /* Start for MATLABSystem: '<S1>/Encoder' */
  ex2_encoder_DW.obj.Index = 0U;
  ex2_encoder_DW.obj.matlabCodegenIsDeleted = false;
  ex2_encoder_DW.obj.SampleTime = ex2_encoder_P.Encoder_SampleTime;
  ex2_encoder_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &ex2_encoder_DW.obj.Index);
  ex2_encoder_DW.obj.isSetupComplete = true;
  ex2_encoder_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S1>/Encoder' */
  MW_EncoderReset(ex2_encoder_DW.obj.Index);

  /* Start for MATLABSystem: '<S2>/PWM' */
  ex2_encoder_DW.obj_p.matlabCodegenIsDeleted = false;
  ex2_encoder_DW.obj_p.isInitialized = 1L;
  ex2_encoder_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
  ex2_encoder_DW.obj_p.isSetupComplete = true;
}

/* Model terminate function */
void ex2_encoder_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Encoder' */
  if (!ex2_encoder_DW.obj.matlabCodegenIsDeleted) {
    ex2_encoder_DW.obj.matlabCodegenIsDeleted = true;
    if ((ex2_encoder_DW.obj.isInitialized == 1L) &&
        ex2_encoder_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Encoder' */
  /* Terminate for MATLABSystem: '<S2>/PWM' */
  if (!ex2_encoder_DW.obj_p.matlabCodegenIsDeleted) {
    ex2_encoder_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((ex2_encoder_DW.obj_p.isInitialized == 1L) &&
        ex2_encoder_DW.obj_p.isSetupComplete) {
      ex2_encoder_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(ex2_encoder_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      ex2_encoder_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(ex2_encoder_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
