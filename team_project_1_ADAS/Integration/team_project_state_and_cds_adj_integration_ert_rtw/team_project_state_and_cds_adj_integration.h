/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: team_project_state_and_cds_adj_integration.h
 *
 * Code generated for Simulink model 'team_project_state_and_cds_adj_integration'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Feb 13 17:19:22 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_team_project_state_and_cds_adj_integration_h_
#define RTW_HEADER_team_project_state_and_cds_adj_integration_h_
#ifndef team_project_state_and_cds_adj_integration_COMMON_INCLUDES_
#define team_project_state_and_cds_adj_integration_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_arduinoextint.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#include "MW_ArduinoEncoder.h"
#endif         /* team_project_state_and_cds_adj_integration_COMMON_INCLUDES_ */

#include "team_project_state_and_cds_adj_integration_types.h"
#include "multiword_types.h"
#include "rtGetNaN.h"
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

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#define team_project_state_and_cds_adj_integration_M (team_project_state_and_cds_a_M)

/* Block signals (default storage) */
typedef struct {
  int128m_T Gain2;                     /* '<S13>/Gain2' */
  int128m_T r;
  int128m_T r1;
  int96m_T r2;
  int96m_T r3;
  int96m_T r4;
  int96m_T r5;
  int64m_T Gain1;                      /* '<S13>/Gain1' */
  int64m_T DiscreteTransferFcn;        /* '<S13>/Discrete Transfer Fcn' */
  real_T RateTransition;               /* '<S5>/Rate Transition' */
  real_T Delay;                        /* '<Root>/Delay' */
  real_T Delay_h;                      /* '<S1>/Delay' */
  real_T TmpRTBAtIfActionSubsystem1Outpo;/* '<S4>/If Action Subsystem1' */
  real_T Constant;                     /* '<Root>/Constant' */
  real_T Constant3;                    /* '<Root>/Constant3' */
  real_T Constant1;                    /* '<Root>/Constant1' */
  real_T DataTypeConversion;           /* '<S2>/Data Type Conversion' */
  real_T Constant2;                    /* '<Root>/Constant2' */
  real_T Gain2_i;                      /* '<S15>/Gain2' */
  real_T Subtract2;                    /* '<S15>/Subtract2' */
  real_T Saturation1;                  /* '<S3>/Saturation1' */
  real_T DataTypeConversion1;          /* '<S14>/Data Type Conversion1' */
  real_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<S3>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux1_at_outport_0Inport1' */
  real_T Gain1_c;                      /* '<S15>/Gain1' */
  real_T rout1;                        /* '<S2>/Chart1' */
  real_T out1;                         /* '<S2>/Chart' */
  real_T out2;                         /* '<S2>/Chart' */
  real_T buzzer;                       /* '<S2>/Chart' */
  real_T drive_mode;                   /* '<S5>/Chart' */
  real_T ADAS_state;                   /* '<S6>/Chart' */
  real_T Mod1;                         /* '<S7>/Mod1' */
  real_T Mod;                          /* '<S10>/Mod' */
  int32_T DataTypeConversion1_l;       /* '<S13>/Data Type Conversion1' */
  uint8_T DataTypeConversion_i;        /* '<S14>/Data Type Conversion' */
  boolean_T DigitalInput1;             /* '<Root>/Digital Input1' */
} B_team_project_state_and_cds__T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_in_ml_T obj; /* '<S13>/Encoder' */
  codertarget_arduinobase_inter_T obj_k;/* '<Root>/가변저항' */
  codertarget_arduinobase_inter_T obj_d;/* '<Root>/Analog Input1' */
  codertarget_arduinobase_block_T obj_i;/* '<Root>/Digital Input1' */
  codertarget_arduinobase_block_T obj_h;/* '<Root>/Digital Input' */
  codertarget_arduinobase_int_m_T obj_f;/* '<S14>/PWM' */
  codertarget_arduinobase_int_m_T obj_a;/* '<S2>/PWM2' */
  codertarget_arduinobase_int_m_T obj_l;/* '<S2>/PWM1' */
  codertarget_arduinobase_int_m_T obj_j;/* '<S2>/PWM' */
  codertarget_arduinobase_int_m_T obj_i2;/* '<Root>/PWM1' */
  real_T Delay_DSTATE;                 /* '<Root>/Delay' */
  real_T Delay_DSTATE_e;               /* '<S1>/Delay' */
  real_T Delay1_DSTATE;                /* '<S7>/Delay1' */
  real_T Delay_DSTATE_p;               /* '<S10>/Delay' */
  real_T TmpRTBAtIfActionSubsystem1Outpo;/* synthesized block */
  real_T steering;                     /* '<S2>/Chart' */
  real_T default_g;                    /* '<S2>/Chart' */
  real_T state_1;                      /* '<S5>/Chart' */
  real_T ADAS_state;                   /* '<S5>/Chart' */
  real_T Light_state;                  /* '<S5>/Chart' */
  real_T state_2;                      /* '<S6>/Chart' */
  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<S3>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S3>/Scope2' */

  int32_T DiscreteTransferFcn_states;  /* '<S13>/Discrete Transfer Fcn' */
  int32_T UD_DSTATE;                   /* '<S16>/UD' */
  uint32_T is_c5_team_project_state_and_cd;/* '<S2>/Chart1' */
  uint32_T is_c2_team_project_state_and_cd;/* '<S2>/Chart' */
  uint32_T is_c3_team_project_state_and_cd;/* '<S5>/Chart' */
  uint32_T is_c1_team_project_state_and_cd;/* '<S6>/Chart' */
  int8_T If_ActiveSubsystem;           /* '<S1>/If' */
  int8_T If_ActiveSubsystem_n;         /* '<S4>/If' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S4>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S4>/If Action Subsystem1' */
  int8_T SW1_SubsysRanBC;              /* '<S5>/SW1' */
  uint8_T is_active_c5_team_project_state;/* '<S2>/Chart1' */
  uint8_T is_active_c2_team_project_state;/* '<S2>/Chart' */
  uint8_T is_active_c3_team_project_state;/* '<S5>/Chart' */
  uint8_T is_active_c1_team_project_state;/* '<S6>/Chart' */
} DW_team_project_state_and_cds_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S15>/Integrator2' */
} X_team_project_state_and_cds__T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S15>/Integrator2' */
} XDot_team_project_state_and_c_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator2_CSTATE;        /* '<S15>/Integrator2' */
} XDis_team_project_state_and_c_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_team_project_state_and_cds__T_ {
  real_T KI;                           /* Variable: KI
                                        * Referenced by: '<S15>/Gain1'
                                        */
  real_T KP;                           /* Variable: KP
                                        * Referenced by: '<S15>/Gain2'
                                        */
  real_T Vlim;                         /* Variable: Vlim
                                        * Referenced by: '<S14>/Gain1'
                                        */
  real_T b;                            /* Variable: b
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T f;                            /* Variable: f
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T l;                            /* Variable: l
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T r;                            /* Variable: r
                                        * Referenced by: '<Root>/Constant1'
                                        */
  int32_T den_Gd[2];                   /* Variable: den_Gd
                                        * Referenced by: '<S13>/Discrete Transfer Fcn'
                                        */
  int32_T encoder_scale;               /* Variable: encoder_scale
                                        * Referenced by: '<S13>/Gain1'
                                        */
  int32_T num_Gd[2];                   /* Variable: num_Gd
                                        * Referenced by: '<S13>/Discrete Transfer Fcn'
                                        */
  int32_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S16>/UD'
                               */
  real_T AnalogInput1_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input'
                                        */
  real_T DigitalInput1_SampleTime;     /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input1'
                                        */
  real_T Output_Y0;                    /* Computed Parameter: Output_Y0
                                        * Referenced by: '<S10>/Output'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S10>/Delay'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T sw2_Y0;                       /* Computed Parameter: sw2_Y0
                                        * Referenced by: '<S7>/sw2'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S7>/Constant2'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S7>/Delay1'
                                        */
  real_T Constant3_Value;              /* Expression: 2
                                        * Referenced by: '<S7>/Constant3'
                                        */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S13>/Encoder'
                                        */
  real_T _SampleTime;                  /* Expression: -1
                                        * Referenced by: '<Root>/가변저항'
                                        */
  real_T Delay_InitialCondition_f;     /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T Delay_InitialCondition_h;     /* Expression: 0.0
                                        * Referenced by: '<S1>/Delay'
                                        */
  real_T TmpRTBAtIfActionSubsystem1Outpo;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S15>/Integrator2'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 12
                                        * Referenced by: '<S3>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S3>/Saturation1'
                                        */
  int64m_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S13>/Gain2'
                                        */
  int32_T DiscreteTransferFcn_InitialStat;
                          /* Computed Parameter: DiscreteTransferFcn_InitialStat
                           * Referenced by: '<S13>/Discrete Transfer Fcn'
                           */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S2>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_team_project_state_an_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_team_project_state_and_cds__T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_team_project_state_and_c_T *contStateDisabled;
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
    uint32_T clockTick3;
    uint32_T clockTick4;
    uint8_T rtmDbBufReadBuf4;
    uint8_T rtmDbBufWriteBuf4;
    boolean_T rtmDbBufLastBufWr4;
    uint32_T rtmDbBufClockTick4[2];
    struct {
      uint8_T TID[4];
    } TaskCounters;

    struct {
      boolean_T TID1_3;
    } RateInteraction;

    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[5];
  } Timing;
};

/* Block parameters (default storage) */
extern P_team_project_state_and_cds__T team_project_state_and_cds_ad_P;

/* Block signals (default storage) */
extern B_team_project_state_and_cds__T team_project_state_and_cds_ad_B;

/* Continuous states (default storage) */
extern X_team_project_state_and_cds__T team_project_state_and_cds_ad_X;

/* Disabled states (default storage) */
extern XDis_team_project_state_and_c_T team_project_state_and_cds_XDis;

/* Block states (default storage) */
extern DW_team_project_state_and_cds_T team_project_state_and_cds_a_DW;

/* External function called from main */
extern void team_project_state_and_cds_adj_integration_SetEventsForThisBaseStep
  (boolean_T *eventFlags);

/* Model entry point functions */
extern void team_project_state_and_cds_adj_integration_initialize(void);
extern void team_project_state_and_cds_adj_integration_step0(void);
extern void team_project_state_and_cds_adj_integration_step2(void);
extern void team_project_state_and_cds_adj_integration_step3(void);
extern void team_project_state_and_cds_adj_integration_terminate(void);

/* Real-time Model object */
extern RT_MODEL_team_project_state_a_T *const team_project_state_and_cds_a_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Data Type Conversion' : Unused code path elimination
 * Block '<Root>/Gain4' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition2' : Eliminated since input and output rates are identical
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
 * '<Root>' : 'team_project_state_and_cds_adj_integration'
 * '<S1>'   : 'team_project_state_and_cds_adj_integration/State_Ctrl'
 * '<S2>'   : 'team_project_state_and_cds_adj_integration/Subsystem'
 * '<S3>'   : 'team_project_state_and_cds_adj_integration/Subsystem1'
 * '<S4>'   : 'team_project_state_and_cds_adj_integration/State_Ctrl/ADAS_state'
 * '<S5>'   : 'team_project_state_and_cds_adj_integration/State_Ctrl/drive_mode'
 * '<S6>'   : 'team_project_state_and_cds_adj_integration/State_Ctrl/ADAS_state/If Action Subsystem'
 * '<S7>'   : 'team_project_state_and_cds_adj_integration/State_Ctrl/ADAS_state/If Action Subsystem1'
 * '<S8>'   : 'team_project_state_and_cds_adj_integration/State_Ctrl/ADAS_state/If Action Subsystem/Chart'
 * '<S9>'   : 'team_project_state_and_cds_adj_integration/State_Ctrl/drive_mode/Chart'
 * '<S10>'  : 'team_project_state_and_cds_adj_integration/State_Ctrl/drive_mode/SW1'
 * '<S11>'  : 'team_project_state_and_cds_adj_integration/Subsystem/Chart'
 * '<S12>'  : 'team_project_state_and_cds_adj_integration/Subsystem/Chart1'
 * '<S13>'  : 'team_project_state_and_cds_adj_integration/Subsystem1/Subsystem1'
 * '<S14>'  : 'team_project_state_and_cds_adj_integration/Subsystem1/Subsystem2'
 * '<S15>'  : 'team_project_state_and_cds_adj_integration/Subsystem1/Subsystem3'
 * '<S16>'  : 'team_project_state_and_cds_adj_integration/Subsystem1/Subsystem1/Discrete Derivative'
 */
#endif            /* RTW_HEADER_team_project_state_and_cds_adj_integration_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
