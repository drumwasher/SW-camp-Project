/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pr2_US_hap.h
 *
 * Code generated for Simulink model 'pr2_US_hap'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Feb 12 19:19:53 2024
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
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#include "MW_AnalogIn.h"
#endif                                 /* pr2_US_hap_COMMON_INCLUDES_ */

#include "pr2_US_hap_types.h"
#include "multiword_types.h"
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"
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
  int128m_T Gain2;                     /* '<S4>/Gain2' */
  int128m_T r;
  int128m_T r1;
  int128m_T r2;
  int96m_T r3;
  int96m_T r4;
  int96m_T r5;
  int96m_T r6;
  int64m_T Gain1;                      /* '<S4>/Gain1' */
  int64m_T DiscreteTransferFcn;        /* '<S4>/Discrete Transfer Fcn' */
  real_T TmpRTBAtChart1Inport1;
  real_T TmpRTBAtChartInport1;
  real_T TmpRTBAtChartInport2;
  real_T Constant3;                    /* '<Root>/Constant3' */
  real_T Constant1;                    /* '<Root>/Constant1' */
  real_T DataTypeConversion;           /* '<S3>/Data Type Conversion' */
  real_T Constant2;                    /* '<Root>/Constant2' */
  real_T Divide1;                      /* '<S6>/Divide1' */
  real_T Divide3;                      /* '<S6>/Divide3' */
  real_T Add4;                         /* '<S6>/Add4' */
  real_T Subtract1;                    /* '<S7>/Subtract1' */
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T DataTypeConversion1;          /* '<S5>/Data Type Conversion1' */
  real_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux1_at_outport_0Inport1' */
  real_T Gain4;                        /* '<S7>/Gain4' */
  real_T Divide3_d;                    /* '<S8>/Divide3' */
  real_T Divide2;                      /* '<S8>/Divide2' */
  real_T TmpRTBAtDisplay3Inport1;      /* '<Root>/SW1 PUSH1' */
  real_T TmpRTBAtDisplay2Inport1;      /* '<Root>/SW1 PUSH' */
  real_T Constant;                     /* '<Root>/Constant' */
  real_T rout1;                        /* '<S3>/Chart1' */
  real_T rout2;                        /* '<S3>/Chart1' */
  real_T out1;                         /* '<S3>/Chart' */
  real_T out2;                         /* '<S3>/Chart' */
  real_T buzzer;                       /* '<S3>/Chart' */
  real_T Add;                          /* '<S2>/Add' */
  real_T Add_h;                        /* '<S1>/Add' */
  int32_T DataTypeConversion1_c;       /* '<S4>/Data Type Conversion1' */
  uint8_T DataTypeConversion_e;        /* '<S5>/Data Type Conversion' */
} B_pr2_US_hap_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S4>/Encoder' */
  codertarget_arduinobase_in_p4_T obj_n;/* '<Root>/가변저항' */
  codertarget_arduinobase_int_p_T obj_b;/* '<S5>/PWM' */
  real_T Delay_DSTATE;                 /* '<S2>/Delay' */
  real_T Delay_DSTATE_a;               /* '<S1>/Delay' */
  volatile real_T TmpRTBAtChart1Inport1_Buffer0;/* synthesized block */
  volatile real_T TmpRTBAtChart1Inport1_Buffer1;/* synthesized block */
  volatile real_T TmpRTBAtChartInport1_Buffer0;/* synthesized block */
  volatile real_T TmpRTBAtChartInport1_Buffer1;/* synthesized block */
  volatile real_T TmpRTBAtChartInport2_Buffer0;/* synthesized block */
  volatile real_T TmpRTBAtChartInport2_Buffer1;/* synthesized block */
  volatile real_T TmpRTBAtDisplay3Inport1_Buffer0;/* synthesized block */
  volatile real_T TmpRTBAtDisplay3Inport1_Buffer1;/* synthesized block */
  volatile real_T TmpRTBAtDisplay2Inport1_Buffer0;/* synthesized block */
  volatile real_T TmpRTBAtDisplay2Inport1_Buffer1;/* synthesized block */
  real_T steering;                     /* '<S3>/Chart' */
  real_T default_k;                    /* '<S3>/Chart' */
  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  int32_T DiscreteTransferFcn_states;  /* '<S4>/Discrete Transfer Fcn' */
  int32_T UD_DSTATE;                   /* '<S11>/UD' */
  uint32_T is_c1_pr2_US_hap;           /* '<S3>/Chart1' */
  uint32_T is_c3_pr2_US_hap;           /* '<S3>/Chart' */
  volatile int8_T TmpRTBAtChart1Inport1_write_buf;/* synthesized block */
  volatile int8_T TmpRTBAtChart1Inport1_read_buf;/* synthesized block */
  volatile int8_T TmpRTBAtChart1Inport1_last_buf_;/* synthesized block */
  volatile int8_T TmpRTBAtChartInport1_write_buf;/* synthesized block */
  volatile int8_T TmpRTBAtChartInport1_read_buf;/* synthesized block */
  volatile int8_T TmpRTBAtChartInport1_last_buf_w;/* synthesized block */
  volatile int8_T TmpRTBAtChartInport2_write_buf;/* synthesized block */
  volatile int8_T TmpRTBAtChartInport2_read_buf;/* synthesized block */
  volatile int8_T TmpRTBAtChartInport2_last_buf_w;/* synthesized block */
  volatile int8_T TmpRTBAtDisplay3Inport1_write_b;/* synthesized block */
  volatile int8_T TmpRTBAtDisplay3Inport1_read_bu;/* synthesized block */
  volatile int8_T TmpRTBAtDisplay3Inport1_last_bu;/* synthesized block */
  volatile int8_T TmpRTBAtDisplay2Inport1_write_b;/* synthesized block */
  volatile int8_T TmpRTBAtDisplay2Inport1_read_bu;/* synthesized block */
  volatile int8_T TmpRTBAtDisplay2Inport1_last_bu;/* synthesized block */
  int8_T SW1PUSH1_SubsysRanBC;         /* '<Root>/SW1 PUSH1' */
  int8_T SW1PUSH_SubsysRanBC;          /* '<Root>/SW1 PUSH' */
  uint8_T is_active_c1_pr2_US_hap;     /* '<S3>/Chart1' */
  uint8_T is_active_c3_pr2_US_hap;     /* '<S3>/Chart' */
} DW_pr2_US_hap_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S7>/Integrator1' */
} X_pr2_US_hap_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S7>/Integrator1' */
} XDot_pr2_US_hap_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<S7>/Integrator1' */
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
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY_pr2_US_hap_T;

/* Parameters (default storage) */
struct P_pr2_US_hap_T_ {
  real_T KI;                           /* Variable: KI
                                        * Referenced by: '<S7>/Gain4'
                                        */
  real_T KP;                           /* Variable: KP
                                        * Referenced by: '<S7>/Gain5'
                                        */
  real_T Vlim;                         /* Variable: Vlim
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T Wref;                         /* Variable: Wref
                                        * Referenced by:
                                        *   '<S6>/Step1'
                                        *   '<S8>/Step1'
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
                                        * Referenced by: '<S4>/Discrete Transfer Fcn'
                                        */
  int32_T encoder_scale;               /* Variable: encoder_scale
                                        * Referenced by: '<S4>/Gain1'
                                        */
  int32_T num_Gd[2];                   /* Variable: num_Gd
                                        * Referenced by: '<S4>/Discrete Transfer Fcn'
                                        */
  int32_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S11>/UD'
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
  real_T sw1_Y0_e;                     /* Computed Parameter: sw1_Y0_e
                                        * Referenced by: '<S2>/sw1'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Delay_InitialCondition_e;     /* Expression: 0.0
                                        * Referenced by: '<S2>/Delay'
                                        */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S4>/Encoder'
                                        */
  real_T _SampleTime;                  /* Expression: -1
                                        * Referenced by: '<Root>/가변저항'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S7>/Integrator1'
                                        */
  real_T Step1_Time;                   /* Expression: 1
                                        * Referenced by: '<S6>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<S6>/Step1'
                                        */
  real_T TmpRTBAtChart1Inport1_InitialCo;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpRTBAtChartInport1_InitialCon;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpRTBAtChartInport2_InitialCon;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Constant_Value_o;             /* Expression: 128
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 6.4
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 100
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 12
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Constant_Value_d;             /* Expression: 128
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Constant1_Value_p;            /* Expression: 6.4
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T Constant2_Value_e;            /* Expression: 100
                                        * Referenced by: '<S8>/Constant2'
                                        */
  real_T Step1_Time_p;                 /* Expression: 1
                                        * Referenced by: '<S8>/Step1'
                                        */
  real_T Step1_Y0_c;                   /* Expression: 0
                                        * Referenced by: '<S8>/Step1'
                                        */
  real_T TmpRTBAtDisplay3Inport1_Initial;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpRTBAtDisplay2Inport1_Initial;/* Expression: 0
                                          * Referenced by:
                                          */
  int64m_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S4>/Gain2'
                                        */
  int32_T DiscreteTransferFcn_InitialStat;
                          /* Computed Parameter: DiscreteTransferFcn_InitialStat
                           * Referenced by: '<S4>/Discrete Transfer Fcn'
                           */
  uint16_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S3>/Gain4'
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
    uint32_T clockTick2;
    uint8_T rtmDbBufReadBuf2;
    uint8_T rtmDbBufWriteBuf2;
    boolean_T rtmDbBufLastBufWr2;
    uint32_T rtmDbBufClockTick2[2];
    uint32_T clockTick3;
    uint8_T rtmDbBufReadBuf3;
    uint8_T rtmDbBufWriteBuf3;
    boolean_T rtmDbBufLastBufWr3;
    uint32_T rtmDbBufClockTick3[2];
    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[4];
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
 * Block '<S7>/Derivative1' : Unused code path elimination
 * Block '<S7>/Gain6' : Unused code path elimination
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
 * '<S4>'   : 'pr2_US_hap/Subsystem3'
 * '<S5>'   : 'pr2_US_hap/Subsystem4'
 * '<S6>'   : 'pr2_US_hap/Subsystem5'
 * '<S7>'   : 'pr2_US_hap/Subsystem6'
 * '<S8>'   : 'pr2_US_hap/Subsystem7'
 * '<S9>'   : 'pr2_US_hap/Subsystem/Chart'
 * '<S10>'  : 'pr2_US_hap/Subsystem/Chart1'
 * '<S11>'  : 'pr2_US_hap/Subsystem3/Discrete Derivative'
 */
#endif                                 /* RTW_HEADER_pr2_US_hap_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
