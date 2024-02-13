/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pr2_US_hap.h
 *
 * Code generated for Simulink model 'pr2_US_hap'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Feb 13 17:45:30 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_pr2_US_hap_h_
#define RTW_HEADER_pr2_US_hap_h_
#ifndef pr2_US_hap_COMMON_INCLUDES_
#define pr2_US_hap_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_arduinoextint.h"
#include "MW_PWM.h"
#include "MW_ArduinoEncoder.h"
#include "MW_AnalogIn.h"
#endif                                 /* pr2_US_hap_COMMON_INCLUDES_ */

#include "pr2_US_hap_types.h"
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
  int128m_T Gain2;                     /* '<S8>/Gain2' */
  int128m_T Gain2_g;                   /* '<S12>/Gain2' */
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
  int64m_T Gain1;                      /* '<S8>/Gain1' */
  int64m_T Gain1_a;                    /* '<S12>/Gain1' */
  int64m_T DiscreteTransferFcn;        /* '<S8>/Discrete Transfer Fcn' */
  int64m_T DiscreteTransferFcn_c;      /* '<S12>/Discrete Transfer Fcn' */
  real_T TmpRTBAtChartInport1;
  real_T Constant3;                    /* '<Root>/Constant3' */
  real_T Constant1;                    /* '<Root>/Constant1' */
  real_T DataTypeConversion;           /* '<S3>/Data Type Conversion' */
  real_T Constant2;                    /* '<Root>/Constant2' */
  real_T Gain2_gz;                     /* '<S10>/Gain2' */
  real_T Gain3;                        /* '<S10>/Gain3' */
  real_T Subtract2;                    /* '<S10>/Subtract2' */
  real_T Saturation2;                  /* '<S4>/Saturation2' */
  real_T DataTypeConversion1;          /* '<S9>/Data Type Conversion1' */
  real_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<S4>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux1_at_outport_0Inport1' */
  real_T Gain2_f;                      /* '<S14>/Gain2' */
  real_T Gain3_k;                      /* '<S14>/Gain3' */
  real_T Subtract2_p;                  /* '<S14>/Subtract2' */
  real_T Saturation2_j;                /* '<S5>/Saturation2' */
  real_T DataTypeConversion1_e;        /* '<S13>/Data Type Conversion1' */
  real_T TmpSignalConversionAtTAQSigLo_e[2];
  /* '<S5>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux1_at_outport_0Inport1' */
  real_T Gain1_g;                      /* '<S14>/Gain1' */
  real_T Gain1_p;                      /* '<S10>/Gain1' */
  real_T TmpRTBAtDisplay2Inport1;      /* '<Root>/SW1 PUSH' */
  real_T TmpRTBAtDisplayInport1;
  real_T Constant;                     /* '<Root>/Constant' */
  real_T Add;                          /* '<S2>/Add' */
  real_T rout1;                        /* '<S3>/Chart1' */
  real_T rout2;                        /* '<S3>/Chart1' */
  real_T out1;                         /* '<S3>/Chart' */
  real_T out2;                         /* '<S3>/Chart' */
  real_T buzzer;                       /* '<S3>/Chart' */
  real_T Add_h;                        /* '<S1>/Add' */
  real_T Derivative2;                  /* '<S14>/Derivative2' */
  real_T Gain1_m;                      /* '<S13>/Gain1' */
  int64m_T denAccum;
  int64m_T r10;
  int64m_T r11;
  int64m_T r12;
  int32_T DataTypeConversion1_d;       /* '<S8>/Data Type Conversion1' */
  int32_T DataTypeConversion1_a;       /* '<S12>/Data Type Conversion1' */
  uint8_T DataTypeConversion_h;        /* '<S9>/Data Type Conversion' */
  uint8_T DataTypeConversion_g;        /* '<S13>/Data Type Conversion' */
} B_pr2_US_hap_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_p_T obj; /* '<S12>/Encoder' */
  codertarget_arduinobase_int_p_T obj_p;/* '<S8>/Encoder' */
  codertarget_arduinobase_in_p4_T obj_n;/* '<Root>/가변저항' */
  codertarget_arduinobase_inter_T obj_d;/* '<S13>/PWM' */
  codertarget_arduinobase_inter_T obj_a;/* '<S9>/PWM' */
  codertarget_arduinobase_inter_T obj_e;/* '<S3>/PWM2' */
  codertarget_arduinobase_inter_T obj_g;/* '<S3>/PWM1' */
  codertarget_arduinobase_inter_T obj_l;/* '<S3>/PWM' */
  real_T Delay_DSTATE_a;               /* '<S1>/Delay' */
  volatile real_T TmpRTBAtChartInport1_Buffer0;/* synthesized block */
  volatile real_T TmpRTBAtChartInport1_Buffer1;/* synthesized block */
  real_T TimeStampA;                   /* '<S10>/Derivative2' */
  real_T LastUAtTimeA;                 /* '<S10>/Derivative2' */
  real_T TimeStampB;                   /* '<S10>/Derivative2' */
  real_T LastUAtTimeB;                 /* '<S10>/Derivative2' */
  real_T TimeStampA_g;                 /* '<S14>/Derivative2' */
  real_T LastUAtTimeA_p;               /* '<S14>/Derivative2' */
  real_T TimeStampB_c;                 /* '<S14>/Derivative2' */
  real_T LastUAtTimeB_n;               /* '<S14>/Derivative2' */
  volatile real_T TmpRTBAtDisplay2Inport1_Buffer0;/* synthesized block */
  volatile real_T TmpRTBAtDisplay2Inport1_Buffer1;/* synthesized block */
  volatile real_T TmpRTBAtDisplayInport1_Buffer0;/* synthesized block */
  volatile real_T TmpRTBAtDisplayInport1_Buffer1;/* synthesized block */
  real_T steering;                     /* '<S3>/Chart' */
  real_T default_i;                    /* '<S3>/Chart' */
  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<S4>/Scope4' */

  struct {
    void *LoggedData;
  } Scope4_PWORK_n;                    /* '<S5>/Scope4' */

  struct {
    void *LoggedData[2];
  } Scope3_PWORK;                      /* '<S5>/Scope3' */

  struct {
    void *LoggedData[2];
  } Scope3_PWORK_g;                    /* '<S4>/Scope3' */

  int32_T DiscreteTransferFcn_states;  /* '<S8>/Discrete Transfer Fcn' */
  int32_T DiscreteTransferFcn_states_m;/* '<S12>/Discrete Transfer Fcn' */
  int32_T UD_DSTATE;                   /* '<S11>/UD' */
  int32_T UD_DSTATE_m;                 /* '<S15>/UD' */
  uint32_T is_c5_pr2_US_hap;           /* '<S3>/Chart1' */
  uint32_T is_c2_pr2_US_hap;           /* '<S3>/Chart' */
  volatile int8_T TmpRTBAtChartInport1_write_buf;/* synthesized block */
  volatile int8_T TmpRTBAtChartInport1_read_buf;/* synthesized block */
  volatile int8_T TmpRTBAtChartInport1_last_buf_w;/* synthesized block */
  volatile int8_T TmpRTBAtDisplay2Inport1_write_b;/* synthesized block */
  volatile int8_T TmpRTBAtDisplay2Inport1_read_bu;/* synthesized block */
  volatile int8_T TmpRTBAtDisplay2Inport1_last_bu;/* synthesized block */
  volatile int8_T TmpRTBAtDisplayInport1_write_bu;/* synthesized block */
  volatile int8_T TmpRTBAtDisplayInport1_read_buf;/* synthesized block */
  volatile int8_T TmpRTBAtDisplayInport1_last_buf;/* synthesized block */
  int8_T SW1PUSH1_SubsysRanBC;         /* '<Root>/SW1 PUSH1' */
  int8_T SW1PUSH_SubsysRanBC;          /* '<Root>/SW1 PUSH' */
  uint8_T is_active_c5_pr2_US_hap;     /* '<S3>/Chart1' */
  uint8_T is_active_c2_pr2_US_hap;     /* '<S3>/Chart' */
} DW_pr2_US_hap_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S10>/Integrator2' */
  real_T Integrator2_CSTATE_f;         /* '<S14>/Integrator2' */
} X_pr2_US_hap_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S10>/Integrator2' */
  real_T Integrator2_CSTATE_f;         /* '<S14>/Integrator2' */
} XDot_pr2_US_hap_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator2_CSTATE;        /* '<S10>/Integrator2' */
  boolean_T Integrator2_CSTATE_f;      /* '<S14>/Integrator2' */
} XDis_pr2_US_hap_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T buzzer;                       /* '<Root>/buzzer' */
} ExtY_pr2_US_hap_T;

/* Parameters (default storage) */
struct P_pr2_US_hap_T_ {
  real_T KD;                           /* Variable: KD
                                        * Referenced by:
                                        *   '<S10>/Gain3'
                                        *   '<S14>/Gain3'
                                        */
  real_T KI;                           /* Variable: KI
                                        * Referenced by:
                                        *   '<S10>/Gain1'
                                        *   '<S14>/Gain1'
                                        */
  real_T KP;                           /* Variable: KP
                                        * Referenced by:
                                        *   '<S10>/Gain2'
                                        *   '<S14>/Gain2'
                                        */
  real_T Vlim;                         /* Variable: Vlim
                                        * Referenced by:
                                        *   '<S9>/Gain1'
                                        *   '<S13>/Gain1'
                                        */
  real_T b;                            /* Variable: b
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T f;                            /* Variable: f
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T l;                            /* Variable: l
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T r;                            /* Variable: r
                                        * Referenced by: '<Root>/Constant1'
                                        */
  int32_T den_Gd[2];                   /* Variable: den_Gd
                                        * Referenced by:
                                        *   '<S8>/Discrete Transfer Fcn'
                                        *   '<S12>/Discrete Transfer Fcn'
                                        */
  int32_T encoder_scale;               /* Variable: encoder_scale
                                        * Referenced by:
                                        *   '<S8>/Gain1'
                                        *   '<S12>/Gain1'
                                        */
  int32_T num_Gd[2];                   /* Variable: num_Gd
                                        * Referenced by:
                                        *   '<S8>/Discrete Transfer Fcn'
                                        *   '<S12>/Discrete Transfer Fcn'
                                        */
  int32_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S11>/UD'
                               */
  int32_T DiscreteDerivative_ICPrevScal_g;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_g
                               * Referenced by: '<S15>/UD'
                               */
  real_T sw1_Y0;                       /* Computed Parameter: sw1_Y0
                                        * Referenced by: '<S1>/sw1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S1>/Delay'
                                        */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S8>/Encoder'
                                        */
  real_T Encoder_SampleTime_e;         /* Expression: -1
                                        * Referenced by: '<S12>/Encoder'
                                        */
  real_T sw1_Y0_e;                     /* Computed Parameter: sw1_Y0_e
                                        * Referenced by: '<S2>/sw1'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Delay_InitialCondition_e;     /* Expression: 0.0
                                        * Referenced by: '<S2>/Delay'
                                        */
  real_T _SampleTime;                  /* Expression: -1
                                        * Referenced by: '<Root>/가변저항'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S10>/Integrator2'
                                        */
  real_T TmpRTBAtChartInport1_InitialCon;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Saturation2_UpperSat;         /* Expression: 12
                                        * Referenced by: '<S4>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S4>/Saturation2'
                                        */
  real_T Integrator2_IC_f;             /* Expression: 0
                                        * Referenced by: '<S14>/Integrator2'
                                        */
  real_T Saturation2_UpperSat_d;       /* Expression: 12
                                        * Referenced by: '<S5>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_i;       /* Expression: 0
                                        * Referenced by: '<S5>/Saturation2'
                                        */
  real_T TmpRTBAtDisplay2Inport1_Initial;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpRTBAtDisplayInport1_InitialC;/* Expression: 0
                                          * Referenced by:
                                          */
  int64m_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S8>/Gain2'
                                        */
  int64m_T Gain2_Gain_d;               /* Computed Parameter: Gain2_Gain_d
                                        * Referenced by: '<S12>/Gain2'
                                        */
  int32_T DiscreteTransferFcn_InitialStat;
                          /* Computed Parameter: DiscreteTransferFcn_InitialStat
                           * Referenced by: '<S8>/Discrete Transfer Fcn'
                           */
  int32_T DiscreteTransferFcn_InitialSt_i;
                          /* Computed Parameter: DiscreteTransferFcn_InitialSt_i
                           * Referenced by: '<S12>/Discrete Transfer Fcn'
                           */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S3>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_pr2_US_hap_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_pr2_US_hap_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_pr2_US_hap_T *contStateDisabled;
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
    uint32_T clockTick2;
    uint8_T rtmDbBufReadBuf2;
    uint8_T rtmDbBufWriteBuf2;
    boolean_T rtmDbBufLastBufWr2;
    uint32_T rtmDbBufClockTick2[2];
    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_pr2_US_hap_T pr2_US_hap_P;

/* Block signals (default storage) */
extern B_pr2_US_hap_T pr2_US_hap_B;

/* Continuous states (default storage) */
extern X_pr2_US_hap_T pr2_US_hap_X;

/* Disabled states (default storage) */
extern XDis_pr2_US_hap_T pr2_US_hap_XDis;

/* Block states (default storage) */
extern DW_pr2_US_hap_T pr2_US_hap_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_pr2_US_hap_T pr2_US_hap_Y;

/* Model entry point functions */
extern void pr2_US_hap_initialize(void);
extern void pr2_US_hap_step(void);
extern void pr2_US_hap_terminate(void);

/* Real-time Model object */
extern RT_MODEL_pr2_US_hap_T *const pr2_US_hap_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S11>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
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
 * '<Root>' : 'pr2_US_hap'
 * '<S1>'   : 'pr2_US_hap/SW1 PUSH'
 * '<S2>'   : 'pr2_US_hap/SW1 PUSH1'
 * '<S3>'   : 'pr2_US_hap/Subsystem'
 * '<S4>'   : 'pr2_US_hap/Subsystem15'
 * '<S5>'   : 'pr2_US_hap/Subsystem16'
 * '<S6>'   : 'pr2_US_hap/Subsystem/Chart'
 * '<S7>'   : 'pr2_US_hap/Subsystem/Chart1'
 * '<S8>'   : 'pr2_US_hap/Subsystem15/Subsystem1'
 * '<S9>'   : 'pr2_US_hap/Subsystem15/Subsystem2'
 * '<S10>'  : 'pr2_US_hap/Subsystem15/Subsystem6'
 * '<S11>'  : 'pr2_US_hap/Subsystem15/Subsystem1/Discrete Derivative'
 * '<S12>'  : 'pr2_US_hap/Subsystem16/Subsystem1'
 * '<S13>'  : 'pr2_US_hap/Subsystem16/Subsystem2'
 * '<S14>'  : 'pr2_US_hap/Subsystem16/Subsystem6'
 * '<S15>'  : 'pr2_US_hap/Subsystem16/Subsystem1/Discrete Derivative'
 */
#endif                                 /* RTW_HEADER_pr2_US_hap_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
