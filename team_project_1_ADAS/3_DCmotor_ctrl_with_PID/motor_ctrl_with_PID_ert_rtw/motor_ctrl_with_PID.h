/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motor_ctrl_with_PID.h
 *
 * Code generated for Simulink model 'motor_ctrl_with_PID'.
 *
 * Model version                  : 1.42
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Feb 14 11:57:36 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_motor_ctrl_with_PID_h_
#define RTW_HEADER_motor_ctrl_with_PID_h_
#ifndef motor_ctrl_with_PID_COMMON_INCLUDES_
#define motor_ctrl_with_PID_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#include "MW_AnalogIn.h"
#endif                                /* motor_ctrl_with_PID_COMMON_INCLUDES_ */

#include "motor_ctrl_with_PID_types.h"
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include <math.h>
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals (default storage) */
typedef struct {
  int128m_T Gain2;                     /* '<S5>/Gain2' */
  int128m_T Gain2_j;                   /* '<S1>/Gain2' */
  int128m_T r;
  int128m_T r1;
  int128m_T r2;
  int128m_T r3;
  int128m_T r4;
  int96m_T r5;
  int96m_T r6;
  int96m_T r7;
  int96m_T r8;
  int96m_T r9;
  int64m_T Gain1;                      /* '<S5>/Gain1' */
  int64m_T Gain1_h;                    /* '<S1>/Gain1' */
  int64m_T DiscreteTransferFcn;        /* '<S5>/Discrete Transfer Fcn' */
  int64m_T DiscreteTransferFcn_l;      /* '<S1>/Discrete Transfer Fcn' */
  real_T Constant7;                    /* '<Root>/Constant7' */
  real_T Constant8;                    /* '<Root>/Constant8' */
  real_T Constant4;                    /* '<Root>/Constant4' */
  real_T Constant10;                   /* '<Root>/Constant10' */
  real_T Constant9;                    /* '<Root>/Constant9' */
  real_T DataTypeConversion;           /* '<S4>/Data Type Conversion' */
  real_T Constant6;                    /* '<Root>/Constant6' */
  real_T Gain2_k;                      /* '<S7>/Gain2' */
  real_T Gain3;                        /* '<S7>/Gain3' */
  real_T Subtract2;                    /* '<S7>/Subtract2' */
  real_T Saturation1;                  /* '<Root>/Saturation1' */
  real_T DataTypeConversion1;          /* '<S6>/Data Type Conversion1' */
  real_T Gain1_e;                      /* '<S7>/Gain1' */
  real_T Gain2_n;                      /* '<S3>/Gain2' */
  real_T Gain3_g;                      /* '<S3>/Gain3' */
  real_T Subtract2_c;                  /* '<S3>/Subtract2' */
  real_T Saturation2;                  /* '<Root>/Saturation2' */
  real_T DataTypeConversion1_n;        /* '<S2>/Data Type Conversion1' */
  real_T Gain1_j;                      /* '<S3>/Gain1' */
  real_T rout1;                        /* '<S4>/Chart1' */
  real_T rout2;                        /* '<S4>/Chart1' */
  real_T out1;                         /* '<S4>/Chart' */
  real_T out2;                         /* '<S4>/Chart' */
  int64m_T denAccum;
  int64m_T r10;
  int64m_T r11;
  int64m_T r12;
  int32_T DataTypeConversion1_m;       /* '<S5>/Data Type Conversion1' */
  int32_T DataTypeConversion1_l;       /* '<S1>/Data Type Conversion1' */
  uint8_T DataTypeConversion_h;        /* '<S6>/Data Type Conversion' */
  uint8_T DataTypeConversion_g;        /* '<S2>/Data Type Conversion' */
} B_motor_ctrl_with_PID_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S5>/Encoder' */
  codertarget_arduinobase_inter_T obj_d;/* '<S1>/Encoder' */
  codertarget_arduinobase_in_ix_T obj_h;/* '<Root>/가변저항' */
  codertarget_arduinobase_int_i_T obj_p;/* '<S6>/PWM' */
  codertarget_arduinobase_int_i_T obj_e;/* '<S2>/PWM' */
  real_T TimeStampA;                   /* '<S7>/Derivative2' */
  real_T LastUAtTimeA;                 /* '<S7>/Derivative2' */
  real_T TimeStampB;                   /* '<S7>/Derivative2' */
  real_T LastUAtTimeB;                 /* '<S7>/Derivative2' */
  real_T TimeStampA_c;                 /* '<S3>/Derivative2' */
  real_T LastUAtTimeA_b;               /* '<S3>/Derivative2' */
  real_T TimeStampB_g;                 /* '<S3>/Derivative2' */
  real_T LastUAtTimeB_p;               /* '<S3>/Derivative2' */
  real_T steering;                     /* '<S4>/Chart' */
  real_T default_n;                    /* '<S4>/Chart' */
  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<Root>/Scope5' */

  struct {
    void *LoggedData[2];
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  int32_T DiscreteTransferFcn_states;  /* '<S5>/Discrete Transfer Fcn' */
  int32_T DiscreteTransferFcn_states_g;/* '<S1>/Discrete Transfer Fcn' */
  int32_T UD_DSTATE;                   /* '<S11>/UD' */
  int32_T UD_DSTATE_f;                 /* '<S8>/UD' */
  uint32_T is_c5_motor_ctrl_with_PID;  /* '<S4>/Chart1' */
  uint32_T is_c2_motor_ctrl_with_PID;  /* '<S4>/Chart' */
  uint8_T is_active_c5_motor_ctrl_with_PI;/* '<S4>/Chart1' */
  uint8_T is_active_c2_motor_ctrl_with_PI;/* '<S4>/Chart' */
} DW_motor_ctrl_with_PID_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S7>/Integrator2' */
  real_T Integrator2_CSTATE_i;         /* '<S3>/Integrator2' */
} X_motor_ctrl_with_PID_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S7>/Integrator2' */
  real_T Integrator2_CSTATE_i;         /* '<S3>/Integrator2' */
} XDot_motor_ctrl_with_PID_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator2_CSTATE;        /* '<S7>/Integrator2' */
  boolean_T Integrator2_CSTATE_i;      /* '<S3>/Integrator2' */
} XDis_motor_ctrl_with_PID_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_motor_ctrl_with_PID_T_ {
  real_T KD;                           /* Variable: KD
                                        * Referenced by:
                                        *   '<S3>/Gain3'
                                        *   '<S7>/Gain3'
                                        */
  real_T KI;                           /* Variable: KI
                                        * Referenced by:
                                        *   '<S3>/Gain1'
                                        *   '<S7>/Gain1'
                                        */
  real_T KP;                           /* Variable: KP
                                        * Referenced by:
                                        *   '<S3>/Gain2'
                                        *   '<S7>/Gain2'
                                        */
  real_T Vlim;                         /* Variable: Vlim
                                        * Referenced by:
                                        *   '<S2>/Gain1'
                                        *   '<S6>/Gain1'
                                        */
  real_T b;                            /* Variable: b
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T f;                            /* Variable: f
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T l;                            /* Variable: l
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T r;                            /* Variable: r
                                        * Referenced by: '<Root>/Constant8'
                                        */
  int32_T den_Gd[2];                   /* Variable: den_Gd
                                        * Referenced by:
                                        *   '<S1>/Discrete Transfer Fcn'
                                        *   '<S5>/Discrete Transfer Fcn'
                                        */
  int32_T encoder_scale;               /* Variable: encoder_scale
                                        * Referenced by:
                                        *   '<S1>/Gain1'
                                        *   '<S5>/Gain1'
                                        */
  int32_T num_Gd[2];                   /* Variable: num_Gd
                                        * Referenced by:
                                        *   '<S1>/Discrete Transfer Fcn'
                                        *   '<S5>/Discrete Transfer Fcn'
                                        */
  int32_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S11>/UD'
                               */
  int32_T DiscreteDerivative_ICPrevScal_m;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_m
                               * Referenced by: '<S8>/UD'
                               */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S1>/Encoder'
                                        */
  real_T Encoder_SampleTime_a;         /* Expression: -1
                                        * Referenced by: '<S5>/Encoder'
                                        */
  real_T _SampleTime;                  /* Expression: -1
                                        * Referenced by: '<Root>/가변저항'
                                        */
  real_T Constant10_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant10'
                                        */
  real_T Constant9_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant9'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S7>/Integrator2'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 12
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Integrator2_IC_g;             /* Expression: 0
                                        * Referenced by: '<S3>/Integrator2'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 12
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  int64m_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S5>/Gain2'
                                        */
  int64m_T Gain2_Gain_g;               /* Computed Parameter: Gain2_Gain_g
                                        * Referenced by: '<S1>/Gain2'
                                        */
  int32_T DiscreteTransferFcn_InitialStat;
                          /* Computed Parameter: DiscreteTransferFcn_InitialStat
                           * Referenced by: '<S5>/Discrete Transfer Fcn'
                           */
  int32_T DiscreteTransferFcn_InitialSt_p;
                          /* Computed Parameter: DiscreteTransferFcn_InitialSt_p
                           * Referenced by: '<S1>/Discrete Transfer Fcn'
                           */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S4>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_motor_ctrl_with_PID_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_motor_ctrl_with_PID_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_motor_ctrl_with_PID_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_motor_ctrl_with_PID_T motor_ctrl_with_PID_P;

/* Block signals (default storage) */
extern B_motor_ctrl_with_PID_T motor_ctrl_with_PID_B;

/* Continuous states (default storage) */
extern X_motor_ctrl_with_PID_T motor_ctrl_with_PID_X;

/* Disabled states (default storage) */
extern XDis_motor_ctrl_with_PID_T motor_ctrl_with_PID_XDis;

/* Block states (default storage) */
extern DW_motor_ctrl_with_PID_T motor_ctrl_with_PID_DW;

/* Model entry point functions */
extern void motor_ctrl_with_PID_initialize(void);
extern void motor_ctrl_with_PID_step(void);
extern void motor_ctrl_with_PID_terminate(void);

/* Real-time Model object */
extern RT_MODEL_motor_ctrl_with_PID_T *const motor_ctrl_with_PID_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/Data Type Duplicate' : Unused code path elimination
 * Block '<S11>/Data Type Duplicate' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'motor_ctrl_with_PID'
 * '<S1>'   : 'motor_ctrl_with_PID/Subsystem13'
 * '<S2>'   : 'motor_ctrl_with_PID/Subsystem14'
 * '<S3>'   : 'motor_ctrl_with_PID/Subsystem15'
 * '<S4>'   : 'motor_ctrl_with_PID/Subsystem5'
 * '<S5>'   : 'motor_ctrl_with_PID/Subsystem7'
 * '<S6>'   : 'motor_ctrl_with_PID/Subsystem8'
 * '<S7>'   : 'motor_ctrl_with_PID/Subsystem9'
 * '<S8>'   : 'motor_ctrl_with_PID/Subsystem13/Discrete Derivative'
 * '<S9>'   : 'motor_ctrl_with_PID/Subsystem5/Chart'
 * '<S10>'  : 'motor_ctrl_with_PID/Subsystem5/Chart1'
 * '<S11>'  : 'motor_ctrl_with_PID/Subsystem7/Discrete Derivative'
 */
#endif                                 /* RTW_HEADER_motor_ctrl_with_PID_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
