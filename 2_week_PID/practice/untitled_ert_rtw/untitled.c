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
 * C/C++ source code generated on : Sun Feb 11 16:25:09 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "untitled_private.h"

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Continuous states */
X_untitled_T untitled_X;

/* Disabled State Vector */
XDis_untitled_T untitled_XDis;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;
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
  untitled_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  untitled_step();
  untitled_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  untitled_step();
  untitled_derivatives();

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
void untitled_step(void)
{
  /* local block i/o variables */
  int32_T rtb_TSamp;
  real_T tmp_0;
  int32_T tmp;
  uint32_T tmp_1;
  uint32_T tmp_2;
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&untitled_M->solverInfo,
                          ((untitled_M->Timing.clockTick0+1)*
      untitled_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(untitled_M)) {
    untitled_M->Timing.t[0] = rtsiGetT(&untitled_M->solverInfo);
  }

  /* Step: '<Root>/Step' */
  if (untitled_M->Timing.t[0] < untitled_P.Step_Time) {
    /* Step: '<Root>/Step' */
    untitled_B.Step = untitled_P.Step_Y0;
  } else {
    /* Step: '<Root>/Step' */
    untitled_B.Step = untitled_P.Wref;
  }

  /* End of Step: '<Root>/Step' */

  /* MATLABSystem: '<S1>/Encoder' */
  if (untitled_DW.obj.SampleTime != untitled_P.Encoder_SampleTime) {
    untitled_DW.obj.SampleTime = untitled_P.Encoder_SampleTime;
  }

  if (untitled_DW.obj.TunablePropsChanged) {
    untitled_DW.obj.TunablePropsChanged = false;
  }

  MW_EncoderRead(untitled_DW.obj.Index, &tmp);
  if (rtmIsMajorTimeStep(untitled_M)) {
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

    /* Sum: '<S4>/Diff' incorporates:
     *  SampleTimeMath: '<S4>/TSamp'
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
    untitled_B.Diff = rtb_TSamp - untitled_DW.UD_DSTATE;

    /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
     *  Sum: '<S4>/Diff'
     *
     * Block description for '<S4>/Diff':
     *
     *  Add in CPU
     */
    untitled_B.DataTypeConversion1 = (real_T)untitled_B.Diff * 100.0;
  }

  /* Sum: '<Root>/Add1' */
  untitled_B.Add1 = untitled_B.Step - untitled_B.DataTypeConversion1;

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  tmp_0 = floor(untitled_B.Add1);
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 256.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  untitled_B.DataTypeConversion = (uint8_T)(tmp_0 < 0.0 ? (int16_T)(uint8_T)
    -(int8_T)(uint8_T)-tmp_0 : (int16_T)(uint8_T)tmp_0);

  /* DataTypeConversion: '<S2>/Data Type Conversion1' */
  untitled_B.DataTypeConversion1_a = untitled_B.DataTypeConversion;
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* SignalConversion generated from: '<Root>/Mux1' */
    untitled_B.TmpSignalConversionAtTAQSigLogg[0] = 0.0;
    untitled_B.TmpSignalConversionAtTAQSigLogg[1] =
      untitled_B.DataTypeConversion1_a;
  }

  /* MATLABSystem: '<S2>/PWM' */
  untitled_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
  MW_PWM_SetDutyCycle(untitled_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, (real_T)
                      untitled_B.DataTypeConversion);
  if (rtmIsMajorTimeStep(untitled_M)) {
    /* Gain: '<S1>/Gain2' incorporates:
     *  Sum: '<S4>/Diff'
     *
     * Block description for '<S4>/Diff':
     *
     *  Add in CPU
     */
    tmp_1 = (uint32_T)untitled_P.Gain2_Gain;
    tmp_2 = (uint32_T)untitled_B.Diff;
    sMultiWordMul(&tmp_1, 1, &tmp_2, 1, &untitled_B.Gain2.chunks[0U], 2);

    /* Gain: '<S3>/Gain4' */
    untitled_B.Gain4 = untitled_P.KI * 0.0;
  }

  if (rtmIsMajorTimeStep(untitled_M)) {
    if (rtmIsMajorTimeStep(untitled_M)) {
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
      untitled_DW.UD_DSTATE = rtb_TSamp;
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((untitled_M->Timing.clockTick0 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(untitled_M)) {/* Sample time: [0.01s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((untitled_M->Timing.clockTick1 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(untitled_M)) {
    rt_ertODEUpdateContinuousStates(&untitled_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++untitled_M->Timing.clockTick0;
    untitled_M->Timing.t[0] = rtsiGetSolverStopTime(&untitled_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      untitled_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void untitled_derivatives(void)
{
  XDot_untitled_T *_rtXdot;
  _rtXdot = ((XDot_untitled_T *) untitled_M->derivs);

  /* Derivatives for Integrator: '<S3>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = untitled_B.Gain4;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&untitled_M->solverInfo,
                          &untitled_M->Timing.simTimeStep);
    rtsiSetTPtr(&untitled_M->solverInfo, &rtmGetTPtr(untitled_M));
    rtsiSetStepSizePtr(&untitled_M->solverInfo, &untitled_M->Timing.stepSize0);
    rtsiSetdXPtr(&untitled_M->solverInfo, &untitled_M->derivs);
    rtsiSetContStatesPtr(&untitled_M->solverInfo, (real_T **)
                         &untitled_M->contStates);
    rtsiSetNumContStatesPtr(&untitled_M->solverInfo,
      &untitled_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&untitled_M->solverInfo,
      &untitled_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&untitled_M->solverInfo,
      &untitled_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&untitled_M->solverInfo,
      &untitled_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&untitled_M->solverInfo, (boolean_T**)
      &untitled_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&untitled_M->solverInfo, (&rtmGetErrorStatus
      (untitled_M)));
    rtsiSetRTModelPtr(&untitled_M->solverInfo, untitled_M);
  }

  rtsiSetSimTimeStep(&untitled_M->solverInfo, MAJOR_TIME_STEP);
  untitled_M->intgData.y = untitled_M->odeY;
  untitled_M->intgData.f[0] = untitled_M->odeF[0];
  untitled_M->intgData.f[1] = untitled_M->odeF[1];
  untitled_M->intgData.f[2] = untitled_M->odeF[2];
  untitled_M->contStates = ((X_untitled_T *) &untitled_X);
  untitled_M->contStateDisabled = ((XDis_untitled_T *) &untitled_XDis);
  untitled_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&untitled_M->solverInfo, (void *)&untitled_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&untitled_M->solverInfo, false);
  rtsiSetSolverName(&untitled_M->solverInfo,"ode3");
  rtmSetTPtr(untitled_M, &untitled_M->Timing.tArray[0]);
  rtmSetTFinal(untitled_M, -1);
  untitled_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (390055828U);
  untitled_M->Sizes.checksums[1] = (3542914731U);
  untitled_M->Sizes.checksums[2] = (660089596U);
  untitled_M->Sizes.checksums[3] = (1962486872U);

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

  /* InitializeConditions for UnitDelay: '<S4>/UD'
   *
   * Block description for '<S4>/UD':
   *
   *  Store in Global RAM
   */
  untitled_DW.UD_DSTATE = untitled_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for Integrator: '<S3>/Integrator1' */
  untitled_X.Integrator1_CSTATE = untitled_P.Integrator1_IC;

  /* Start for MATLABSystem: '<S1>/Encoder' */
  untitled_DW.obj.Index = 0U;
  untitled_DW.obj.matlabCodegenIsDeleted = false;
  untitled_DW.obj.SampleTime = untitled_P.Encoder_SampleTime;
  untitled_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &untitled_DW.obj.Index);
  untitled_DW.obj.isSetupComplete = true;
  untitled_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S1>/Encoder' */
  MW_EncoderReset(untitled_DW.obj.Index);

  /* Start for MATLABSystem: '<S2>/PWM' */
  untitled_DW.obj_b.matlabCodegenIsDeleted = false;
  untitled_DW.obj_b.isInitialized = 1L;
  untitled_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
  untitled_DW.obj_b.isSetupComplete = true;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Encoder' */
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj.isInitialized == 1L) && untitled_DW.obj.isSetupComplete)
    {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Encoder' */
  /* Terminate for MATLABSystem: '<S2>/PWM' */
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

  /* End of Terminate for MATLABSystem: '<S2>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
