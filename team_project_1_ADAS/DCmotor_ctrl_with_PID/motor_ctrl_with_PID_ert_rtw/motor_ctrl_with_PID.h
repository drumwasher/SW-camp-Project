/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motor_ctrl_with_PID.h
 *
 * Code generated for Simulink model 'motor_ctrl_with_PID'.
 *
 * Model version                  : 1.37
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Feb 12 21:58:13 2024
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
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
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
  int128m_T Gain2;                     /* '<S1>/Gain2' */
  int128m_T r;
  int128m_T r1;
  int128m_T r2;
  int96m_T r3;
  int96m_T r4;
  int96m_T r5;
  int96m_T r6;
  int96m_T r7;
  int64m_T Gain1;                      /* '<S1>/Gain1' */
  int64m_T DiscreteTransferFcn;        /* '<S1>/Discrete Transfer Fcn' */
  real_T Step1;                        /* '<Root>/Step1' */
  real_T Divide1;                      /* '<Root>/Divide1' */
  real_T Add4;                         /* '<Root>/Add4' */
  real_T Gain3;                        /* '<S3>/Gain3' */
  real_T Subtract2;                    /* '<S3>/Subtract2' */
  real_T Saturation1;                  /* '<Root>/Saturation1' */
  real_T DataTypeConversion1;          /* '<S2>/Data Type Conversion1' */
  real_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux2_at_outport_0Inport1' */
  real_T Gain1_e;                      /* '<S3>/Gain1' */
  int32_T DataTypeConversion1_m;       /* '<S1>/Data Type Conversion1' */
  uint8_T DataTypeConversion;          /* '<S2>/Data Type Conversion' */
} B_motor_ctrl_with_PID_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_i_T obj; /* '<S1>/Encoder' */
  codertarget_arduinobase_inter_T obj_j;/* '<Root>/Analog Input' */
  codertarget_arduinobase_block_T obj_a;/* '<Root>/L_Motor(½Ã°è)' */
  codertarget_arduinobase_in_ix_T obj_p;/* '<S2>/PWM' */
  real_T TimeStampA;                   /* '<S3>/Derivative2' */
  real_T LastUAtTimeA;                 /* '<S3>/Derivative2' */
  real_T TimeStampB;                   /* '<S3>/Derivative2' */
  real_T LastUAtTimeB;                 /* '<S3>/Derivative2' */
  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  int32_T DiscreteTransferFcn_states;  /* '<S1>/Discrete Transfer Fcn' */
  int32_T UD_DSTATE;                   /* '<S4>/UD' */
} DW_motor_ctrl_with_PID_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S3>/Integrator2' */
} X_motor_ctrl_with_PID_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S3>/Integrator2' */
} XDot_motor_ctrl_with_PID_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator2_CSTATE;        /* '<S3>/Integrator2' */
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
                                        * Referenced by: '<S3>/Gain3'
                                        */
  real_T KI;                           /* Variable: KI
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T KP;                           /* Variable: KP
                                        * Referenced by: '<S3>/Gain2'
                                        */
  real_T Vlim;                         /* Variable: Vlim
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T Wref;                         /* Variable: Wref
                                        * Referenced by: '<Root>/Step1'
                                        */
  int32_T den_Gd[2];                   /* Variable: den_Gd
                                        * Referenced by: '<S1>/Discrete Transfer Fcn'
                                        */
  int32_T encoder_scale;               /* Variable: encoder_scale
                                        * Referenced by: '<S1>/Gain1'
                                        */
  int32_T num_Gd[2];                   /* Variable: num_Gd
                                        * Referenced by: '<S1>/Discrete Transfer Fcn'
                                        */
  int32_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S4>/UD'
                               */
  real_T AnalogInput_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S1>/Encoder'
                                        */
  real_T Step1_Time;                   /* Expression: 1
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S3>/Integrator2'
                                        */
  real_T Constant_Value;               /* Expression: 128
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 6.4
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 100
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 12
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant4'
                                        */
  int64m_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S1>/Gain2'
                                        */
  int32_T DiscreteTransferFcn_InitialStat;
                          /* Computed Parameter: DiscreteTransferFcn_InitialStat
                           * Referenced by: '<S1>/Discrete Transfer Fcn'
                           */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
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
  real_T odeY[1];
  real_T odeF[3][1];
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
 * Block '<S4>/Data Type Duplicate' : Unused code path elimination
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
 * '<S1>'   : 'motor_ctrl_with_PID/Subsystem3'
 * '<S2>'   : 'motor_ctrl_with_PID/Subsystem4'
 * '<S3>'   : 'motor_ctrl_with_PID/Subsystem5'
 * '<S4>'   : 'motor_ctrl_with_PID/Subsystem3/Discrete Derivative'
 */
#endif                                 /* RTW_HEADER_motor_ctrl_with_PID_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
