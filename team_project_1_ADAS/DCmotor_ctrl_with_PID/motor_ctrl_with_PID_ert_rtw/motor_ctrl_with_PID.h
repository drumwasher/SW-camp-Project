/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motor_ctrl_with_PID.h
 *
 * Code generated for Simulink model 'motor_ctrl_with_PID'.
 *
 * Model version                  : 1.38
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Feb 13 21:22:30 2024
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
#include "MW_Ultrasonic.h"
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

/* Block states (default storage) for system '<S9>/If Action Subsystem1' */
typedef struct {
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S9>/If Action Subsystem1' */
} DW_IfActionSubsystem1_motor_c_T;

/* Block signals (default storage) */
typedef struct {
  int128m_T Gain2;                     /* '<S12>/Gain2' */
  int128m_T Gain2_p;                   /* '<S16>/Gain2' */
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
  int64m_T Gain1;                      /* '<S12>/Gain1' */
  int64m_T Gain1_o;                    /* '<S16>/Gain1' */
  int64m_T DiscreteTransferFcn;        /* '<S12>/Discrete Transfer Fcn' */
  int64m_T DiscreteTransferFcn_g;      /* '<S16>/Discrete Transfer Fcn' */
  real_T Gain1_m;                      /* '<Root>/Gain1' */
  real_T Merge;                        /* '<S3>/Merge' */
  real_T Gain3;                        /* '<S14>/Gain3' */
  real_T Subtract2;                    /* '<S14>/Subtract2' */
  real_T Saturation2;                  /* '<S4>/Saturation2' */
  real_T DataTypeConversion1;          /* '<S13>/Data Type Conversion1' */
  real_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<S4>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux1_at_outport_0Inport1' */
  real_T Merge1;                       /* '<S3>/Merge1' */
  real_T Gain3_h;                      /* '<S18>/Gain3' */
  real_T Subtract2_g;                  /* '<S18>/Subtract2' */
  real_T Saturation2_g;                /* '<S5>/Saturation2' */
  real_T DataTypeConversion1_i;        /* '<S17>/Data Type Conversion1' */
  real_T TmpSignalConversionAtTAQSigLo_e[2];
  /* '<S5>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux1_at_outport_0Inport1' */
  real_T Gain1_b;                      /* '<S18>/Gain1' */
  real_T Gain1_g;                      /* '<S14>/Gain1' */
  real_T In1;                          /* '<S6>/In1' */
  real_T lastTime;
  int64m_T denAccum;
  int64m_T r10;
  int64m_T r11;
  int64m_T r12;
  int32_T DataTypeConversion1_j;       /* '<S12>/Data Type Conversion1' */
  int32_T DataTypeConversion1_jv;      /* '<S16>/Data Type Conversion1' */
  uint8_T DataTypeConversion;          /* '<S13>/Data Type Conversion' */
  uint8_T DataTypeConversion_m;        /* '<S17>/Data Type Conversion' */
} B_motor_ctrl_with_PID_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S16>/Encoder' */
  codertarget_arduinobase_inter_T obj_l;/* '<S12>/Encoder' */
  codertarget_arduinobase_in_ix_T obj_lq;/* '<Root>/가변저항' */
  codertarget_arduinobase_int_i_T obj_d;/* '<S17>/PWM' */
  codertarget_arduinobase_int_i_T obj_k;/* '<S13>/PWM' */
  real_T TimeStampA;                   /* '<S14>/Derivative2' */
  real_T LastUAtTimeA;                 /* '<S14>/Derivative2' */
  real_T TimeStampB;                   /* '<S14>/Derivative2' */
  real_T LastUAtTimeB;                 /* '<S14>/Derivative2' */
  real_T TimeStampA_m;                 /* '<S18>/Derivative2' */
  real_T LastUAtTimeA_i;               /* '<S18>/Derivative2' */
  real_T TimeStampB_j;                 /* '<S18>/Derivative2' */
  real_T LastUAtTimeB_i;               /* '<S18>/Derivative2' */
  codertarget_arduinobase_i_ix1_T obj_m;/* '<Root>/전방 초음파' */
  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<S4>/Scope4' */

  struct {
    void *LoggedData;
  } Scope4_PWORK_a;                    /* '<S5>/Scope4' */

  struct {
    void *LoggedData[2];
  } Scope3_PWORK;                      /* '<S5>/Scope3' */

  struct {
    void *LoggedData[2];
  } Scope3_PWORK_n;                    /* '<S4>/Scope3' */

  int32_T DiscreteTransferFcn_states;  /* '<S12>/Discrete Transfer Fcn' */
  int32_T DiscreteTransferFcn_states_i;/* '<S16>/Discrete Transfer Fcn' */
  int32_T UD_DSTATE;                   /* '<S15>/UD' */
  int32_T UD_DSTATE_c;                 /* '<S19>/UD' */
  int8_T If_ActiveSubsystem;           /* '<S3>/If' */
  int8_T If1_ActiveSubsystem;          /* '<Root>/If1' */
  int8_T If1_ActiveSubsystem_o;        /* '<S3>/If1' */
  int8_T IfActionSubsystem3_SubsysRanBC;/* '<S3>/If Action Subsystem3' */
  int8_T If_ActiveSubsystem_p;         /* '<S9>/If' */
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<S3>/If Action Subsystem2' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S3>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S3>/If Action Subsystem1' */
  int8_T IfActionSubsystem2_SubsysRanB_c;/* '<Root>/If Action Subsystem2' */
  int8_T IfActionSubsystem1_SubsysRanB_p;/* '<Root>/If Action Subsystem1' */
  DW_IfActionSubsystem1_motor_c_T IfActionSubsystem_i;/* '<S9>/If Action Subsystem' */
  DW_IfActionSubsystem1_motor_c_T IfActionSubsystem1_l;/* '<S9>/If Action Subsystem1' */
} DW_motor_ctrl_with_PID_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S14>/Integrator2' */
  real_T Integrator2_CSTATE_e;         /* '<S18>/Integrator2' */
} X_motor_ctrl_with_PID_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S14>/Integrator2' */
  real_T Integrator2_CSTATE_e;         /* '<S18>/Integrator2' */
} XDot_motor_ctrl_with_PID_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator2_CSTATE;        /* '<S14>/Integrator2' */
  boolean_T Integrator2_CSTATE_e;      /* '<S18>/Integrator2' */
} XDis_motor_ctrl_with_PID_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters for system: '<S9>/If Action Subsystem1' */
struct P_IfActionSubsystem1_motor_ct_T_ {
  real_T Constant_Value;               /* Expression: 360
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 360
                                        * Referenced by: '<S11>/Constant1'
                                        */
};

/* Parameters (default storage) */
struct P_motor_ctrl_with_PID_T_ {
  real_T KD;                           /* Variable: KD
                                        * Referenced by:
                                        *   '<S14>/Gain3'
                                        *   '<S18>/Gain3'
                                        */
  real_T KI;                           /* Variable: KI
                                        * Referenced by:
                                        *   '<S14>/Gain1'
                                        *   '<S18>/Gain1'
                                        */
  real_T KP;                           /* Variable: KP
                                        * Referenced by:
                                        *   '<S14>/Gain2'
                                        *   '<S18>/Gain2'
                                        */
  real_T Vlim;                         /* Variable: Vlim
                                        * Referenced by:
                                        *   '<S13>/Gain1'
                                        *   '<S17>/Gain1'
                                        */
  real_T b;                            /* Variable: b
                                        * Referenced by: '<Root>/Constant7'
                                        */
  int32_T den_Gd[2];                   /* Variable: den_Gd
                                        * Referenced by:
                                        *   '<S12>/Discrete Transfer Fcn'
                                        *   '<S16>/Discrete Transfer Fcn'
                                        */
  int32_T encoder_scale;               /* Variable: encoder_scale
                                        * Referenced by:
                                        *   '<S12>/Gain1'
                                        *   '<S16>/Gain1'
                                        */
  int32_T num_Gd[2];                   /* Variable: num_Gd
                                        * Referenced by:
                                        *   '<S12>/Discrete Transfer Fcn'
                                        *   '<S16>/Discrete Transfer Fcn'
                                        */
  int32_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S15>/UD'
                               */
  int32_T DiscreteDerivative_ICPrevScal_n;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_n
                               * Referenced by: '<S19>/UD'
                               */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S6>/Out1'
                                        */
  real_T Constant_Value_a;             /* Expression: 360
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S8>/Constant4'
                                        */
  real_T Constant1_Value_d;            /* Expression: 100
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T Constant5_Value;              /* Expression: 6.4
                                        * Referenced by: '<S8>/Constant5'
                                        */
  real_T Constant2_Value;              /* Expression: 128
                                        * Referenced by: '<S8>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 360
                                        * Referenced by: '<S8>/Constant3'
                                        */
  real_T Constant8_Value;              /* Expression: 1
                                        * Referenced by: '<S8>/Constant8'
                                        */
  real_T Constant6_Value;              /* Expression: 100
                                        * Referenced by: '<S8>/Constant6'
                                        */
  real_T Constant9_Value;              /* Expression: 6.4
                                        * Referenced by: '<S8>/Constant9'
                                        */
  real_T Constant7_Value;              /* Expression: 128
                                        * Referenced by: '<S8>/Constant7'
                                        */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S12>/Encoder'
                                        */
  real_T Encoder_SampleTime_e;         /* Expression: -1
                                        * Referenced by: '<S16>/Encoder'
                                        */
  real_T _SampleTime;                  /* Expression: -1
                                        * Referenced by: '<Root>/가변저항'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S14>/Integrator2'
                                        */
  real_T Constant11_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant11'
                                        */
  real_T Constant12_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant12'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S3>/Merge'
                                       */
  real_T Saturation2_UpperSat;         /* Expression: 12
                                        * Referenced by: '<S4>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S4>/Saturation2'
                                        */
  real_T Integrator2_IC_k;             /* Expression: 0
                                        * Referenced by: '<S18>/Integrator2'
                                        */
  real_T Merge1_InitialOutput;       /* Computed Parameter: Merge1_InitialOutput
                                      * Referenced by: '<S3>/Merge1'
                                      */
  real_T Saturation2_UpperSat_p;       /* Expression: 12
                                        * Referenced by: '<S5>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_h;       /* Expression: 0
                                        * Referenced by: '<S5>/Saturation2'
                                        */
  int64m_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S12>/Gain2'
                                        */
  int64m_T Gain2_Gain_g;               /* Computed Parameter: Gain2_Gain_g
                                        * Referenced by: '<S16>/Gain2'
                                        */
  int32_T DiscreteTransferFcn_InitialStat;
                          /* Computed Parameter: DiscreteTransferFcn_InitialStat
                           * Referenced by: '<S12>/Discrete Transfer Fcn'
                           */
  int32_T DiscreteTransferFcn_InitialSt_b;
                          /* Computed Parameter: DiscreteTransferFcn_InitialSt_b
                           * Referenced by: '<S16>/Discrete Transfer Fcn'
                           */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S3>/Gain'
                                        */
  P_IfActionSubsystem1_motor_ct_T IfActionSubsystem_i;/* '<S9>/If Action Subsystem' */
  P_IfActionSubsystem1_motor_ct_T IfActionSubsystem1_l;/* '<S9>/If Action Subsystem1' */
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
 * Block '<Root>/Constant4' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
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
 * '<S1>'   : 'motor_ctrl_with_PID/If Action Subsystem1'
 * '<S2>'   : 'motor_ctrl_with_PID/If Action Subsystem2'
 * '<S3>'   : 'motor_ctrl_with_PID/Subsystem14'
 * '<S4>'   : 'motor_ctrl_with_PID/Subsystem15'
 * '<S5>'   : 'motor_ctrl_with_PID/Subsystem16'
 * '<S6>'   : 'motor_ctrl_with_PID/Subsystem14/If Action Subsystem'
 * '<S7>'   : 'motor_ctrl_with_PID/Subsystem14/If Action Subsystem1'
 * '<S8>'   : 'motor_ctrl_with_PID/Subsystem14/If Action Subsystem2'
 * '<S9>'   : 'motor_ctrl_with_PID/Subsystem14/If Action Subsystem3'
 * '<S10>'  : 'motor_ctrl_with_PID/Subsystem14/If Action Subsystem3/If Action Subsystem'
 * '<S11>'  : 'motor_ctrl_with_PID/Subsystem14/If Action Subsystem3/If Action Subsystem1'
 * '<S12>'  : 'motor_ctrl_with_PID/Subsystem15/Subsystem1'
 * '<S13>'  : 'motor_ctrl_with_PID/Subsystem15/Subsystem2'
 * '<S14>'  : 'motor_ctrl_with_PID/Subsystem15/Subsystem6'
 * '<S15>'  : 'motor_ctrl_with_PID/Subsystem15/Subsystem1/Discrete Derivative'
 * '<S16>'  : 'motor_ctrl_with_PID/Subsystem16/Subsystem1'
 * '<S17>'  : 'motor_ctrl_with_PID/Subsystem16/Subsystem2'
 * '<S18>'  : 'motor_ctrl_with_PID/Subsystem16/Subsystem6'
 * '<S19>'  : 'motor_ctrl_with_PID/Subsystem16/Subsystem1/Discrete Derivative'
 */
#endif                                 /* RTW_HEADER_motor_ctrl_with_PID_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
