/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: team_project_state_and_cds_adj_sw.h
 *
 * Code generated for Simulink model 'team_project_state_and_cds_adj_sw'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Feb 12 22:22:30 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_team_project_state_and_cds_adj_sw_h_
#define RTW_HEADER_team_project_state_and_cds_adj_sw_h_
#ifndef team_project_state_and_cds_adj_sw_COMMON_INCLUDES_
#define team_project_state_and_cds_adj_sw_COMMON_INCLUDES_
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
#endif                  /* team_project_state_and_cds_adj_sw_COMMON_INCLUDES_ */

#include "team_project_state_and_cds_adj_sw_types.h"
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
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

#define team_project_state_and_cds_adj_sw_M (team_project_state_and_cds_a_M)

/* Block states (default storage) for system '<S2>/If Action Subsystem1' */
typedef struct {
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S2>/If Action Subsystem1' */
} DW_IfActionSubsystem1_team_pr_T;

/* Block states (default storage) for system '<S27>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S27>/If Action Subsystem' */
} DW_IfActionSubsystem_team_pro_T;

/* Block signals (default storage) */
typedef struct {
  int128m_T Gain2;                     /* '<S20>/Gain2' */
  int128m_T r;
  int128m_T r1;
  int128m_T r2;
  int96m_T r3;
  int96m_T r4;
  int96m_T r5;
  int96m_T r6;
  int96m_T r7;
  int64m_T Gain1;                      /* '<S20>/Gain1' */
  int64m_T DiscreteTransferFcn;        /* '<S20>/Discrete Transfer Fcn' */
  real_T RateTransition;               /* '<S12>/Rate Transition' */
  real_T Delay;                        /* '<Root>/Delay' */
  real_T Delay_h;                      /* '<S3>/Delay' */
  real_T TmpRTBAtIfActionSubsystem1Outpo;/* '<S11>/If Action Subsystem1' */
  real_T Constant;                     /* '<Root>/Constant' */
  real_T Constant3;                    /* '<Root>/Constant3' */
  real_T Constant1;                    /* '<Root>/Constant1' */
  real_T DataTypeConversion;           /* '<S4>/Data Type Conversion' */
  real_T Constant2;                    /* '<Root>/Constant2' */
  real_T RateTransition_p;             /* '<S6>/Rate Transition' */
  real_T Gain2_f;                      /* '<S22>/Gain2' */
  real_T Gain3;                        /* '<S22>/Gain3' */
  real_T Subtract2;                    /* '<S22>/Subtract2' */
  real_T Saturation1;                  /* '<S5>/Saturation1' */
  real_T DataTypeConversion1;          /* '<S21>/Data Type Conversion1' */
  real_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<S5>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux2_at_outport_0Inport1' */
  real_T Gain1_g;                      /* '<S22>/Gain1' */
  real_T Merge;                        /* '<S27>/Merge' */
  real_T Merge1;                       /* '<S27>/Merge1' */
  real_T light_mode;                   /* '<S25>/Chart1' */
  real_T Mod;                          /* '<S24>/Mod' */
  real_T rout1;                        /* '<S4>/Chart1' */
  real_T rout2;                        /* '<S4>/Chart1' */
  real_T out1;                         /* '<S4>/Chart' */
  real_T out2;                         /* '<S4>/Chart' */
  real_T buzzer;                       /* '<S4>/Chart' */
  real_T drive_mode;                   /* '<S12>/Chart' */
  real_T ADAS_state;                   /* '<S13>/Chart' */
  real_T Mod1;                         /* '<S14>/Mod1' */
  real_T Mod_b;                        /* '<S17>/Mod' */
  int32_T DataTypeConversion1_a;       /* '<S20>/Data Type Conversion1' */
  uint8_T DataTypeConversion_g;        /* '<S21>/Data Type Conversion' */
  boolean_T DigitalInput1;             /* '<Root>/Digital Input1' */
  boolean_T DigitalInput;              /* '<Root>/Digital Input' */
} B_team_project_state_and_cds__T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_in_ac_T obj; /* '<S20>/Encoder' */
  codertarget_arduinobase_inter_T obj_k;/* '<Root>/가변저항' */
  codertarget_arduinobase_inter_T obj_d;/* '<Root>/Analog Input1' */
  codertarget_arduinobase_block_T obj_i;/* '<Root>/Digital Input1' */
  codertarget_arduinobase_block_T obj_h;/* '<Root>/Digital Input' */
  codertarget_arduinobase_blo_a_T obj_a;/* '<S27>/Digital Output1' */
  codertarget_arduinobase_blo_a_T obj_b;/* '<S27>/Digital Output' */
  codertarget_arduinobase_blo_a_T obj_e;/* '<Root>/L_Motor(시계)' */
  codertarget_arduinobase_blo_a_T obj_e5;/* '<S2>/Digital Output' */
  codertarget_arduinobase_blo_a_T obj_bz;/* '<S1>/Digital Output' */
  codertarget_arduinobase_int_a_T obj_dm;/* '<S21>/PWM' */
  codertarget_arduinobase_int_a_T obj_av;/* '<S4>/PWM2' */
  codertarget_arduinobase_int_a_T obj_l;/* '<S4>/PWM1' */
  codertarget_arduinobase_int_a_T obj_j;/* '<S4>/PWM' */
  codertarget_arduinobase_int_a_T obj_i2;/* '<Root>/PWM1' */
  real_T Delay_DSTATE;                 /* '<Root>/Delay' */
  real_T Delay_DSTATE_e;               /* '<S3>/Delay' */
  real_T Delay_DSTATE_j;               /* '<S24>/Delay' */
  real_T Delay1_DSTATE;                /* '<S14>/Delay1' */
  real_T Delay_DSTATE_p;               /* '<S17>/Delay' */
  real_T TmpRTBAtIfActionSubsystem1Outpo;/* synthesized block */
  real_T TimeStampA;                   /* '<S22>/Derivative2' */
  real_T LastUAtTimeA;                 /* '<S22>/Derivative2' */
  real_T TimeStampB;                   /* '<S22>/Derivative2' */
  real_T LastUAtTimeB;                 /* '<S22>/Derivative2' */
  real_T state_1;                      /* '<S25>/Chart1' */
  real_T steering;                     /* '<S4>/Chart' */
  real_T default_g;                    /* '<S4>/Chart' */
  real_T state_1_e;                    /* '<S12>/Chart' */
  real_T ADAS_state;                   /* '<S12>/Chart' */
  real_T Light_state;                  /* '<S12>/Chart' */
  real_T state_2;                      /* '<S13>/Chart' */
  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<S5>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S5>/Scope2' */

  int32_T DiscreteTransferFcn_states;  /* '<S20>/Discrete Transfer Fcn' */
  int32_T UD_DSTATE;                   /* '<S23>/UD' */
  int32_T clockTickCounter;            /* '<S1>/Pulse Generator' */
  int32_T clockTickCounter_l;          /* '<S27>/Pulse Generator' */
  uint32_T is_c4_team_project_state_and_cd;/* '<S25>/Chart1' */
  uint32_T is_c5_team_project_state_and_cd;/* '<S4>/Chart1' */
  uint32_T is_c2_team_project_state_and_cd;/* '<S4>/Chart' */
  uint32_T is_c3_team_project_state_and_cd;/* '<S12>/Chart' */
  uint32_T is_c1_team_project_state_and_cd;/* '<S13>/Chart' */
  int8_T If_ActiveSubsystem;           /* '<S3>/If' */
  int8_T If1_ActiveSubsystem;          /* '<S1>/If1' */
  int8_T If1_ActiveSubsystem_d;        /* '<S2>/If1' */
  int8_T If_ActiveSubsystem_h;         /* '<S27>/If' */
  int8_T If_ActiveSubsystem_n;         /* '<S11>/If' */
  int8_T If_ActiveSubsystem_l;         /* '<S6>/If' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S27>/If Action Subsystem1' */
  int8_T IfActionSubsystem1_SubsysRanB_g;/* '<S29>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S29>/If Action Subsystem' */
  int8_T IfActionSubsystem_SubsysRanBC_i;/* '<S6>/If Action Subsystem' */
  int8_T IfActionSubsystem_SubsysRanBC_n;/* '<S11>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanB_o;/* '<S11>/If Action Subsystem1' */
  int8_T IfActionSubsystem3_SubsysRanBC;/* '<S1>/If Action Subsystem3' */
  int8_T IfActionSubsystem1_SubsysRanB_h;/* '<S1>/If Action Subsystem1' */
  int8_T SW1_SubsysRanBC;              /* '<S12>/SW1' */
  uint8_T is_active_c4_team_project_state;/* '<S25>/Chart1' */
  uint8_T is_active_c5_team_project_state;/* '<S4>/Chart1' */
  uint8_T is_active_c2_team_project_state;/* '<S4>/Chart' */
  uint8_T is_active_c3_team_project_state;/* '<S12>/Chart' */
  uint8_T is_active_c1_team_project_state;/* '<S13>/Chart' */
  DW_IfActionSubsystem_team_pro_T IfActionSubsystem2;/* '<S27>/If Action Subsystem2' */
  DW_IfActionSubsystem_team_pro_T IfActionSubsystem_c;/* '<S27>/If Action Subsystem' */
  DW_IfActionSubsystem1_team_pr_T IfActionSubsystem3_c;/* '<S2>/If Action Subsystem3' */
  DW_IfActionSubsystem1_team_pr_T IfActionSubsystem1_e;/* '<S2>/If Action Subsystem1' */
} DW_team_project_state_and_cds_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S22>/Integrator2' */
} X_team_project_state_and_cds__T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S22>/Integrator2' */
} XDot_team_project_state_and_c_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator2_CSTATE;        /* '<S22>/Integrator2' */
} XDis_team_project_state_and_c_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters for system: '<S2>/If Action Subsystem1' */
struct P_IfActionSubsystem1_team_pro_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S9>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_team_project_state_and_cds__T_ {
  real_T KD;                           /* Variable: KD
                                        * Referenced by: '<S22>/Gain3'
                                        */
  real_T KI;                           /* Variable: KI
                                        * Referenced by: '<S22>/Gain1'
                                        */
  real_T KP;                           /* Variable: KP
                                        * Referenced by: '<S22>/Gain2'
                                        */
  real_T Vlim;                         /* Variable: Vlim
                                        * Referenced by: '<S21>/Gain1'
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
                                        * Referenced by: '<S20>/Discrete Transfer Fcn'
                                        */
  int32_T encoder_scale;               /* Variable: encoder_scale
                                        * Referenced by: '<S20>/Gain1'
                                        */
  int32_T num_Gd[2];                   /* Variable: num_Gd
                                        * Referenced by: '<S20>/Discrete Transfer Fcn'
                                        */
  int32_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S23>/UD'
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
                                        * Referenced by: '<S17>/Output'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S17>/Delay'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S17>/Constant1'
                                        */
  real_T sw2_Y0;                       /* Computed Parameter: sw2_Y0
                                        * Referenced by: '<S14>/sw2'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S14>/Constant2'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S14>/Delay1'
                                        */
  real_T Constant3_Value;              /* Expression: 2
                                        * Referenced by: '<S14>/Constant3'
                                        */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S20>/Encoder'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S24>/Out1'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T Delay_InitialCondition_p;     /* Expression: 0.0
                                        * Referenced by: '<S24>/Delay'
                                        */
  real_T Constant1_Value_c;            /* Expression: 3
                                        * Referenced by: '<S24>/Constant1'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S29>/Constant'
                                        */
  real_T Constant1_Value_f;            /* Expression: 0
                                        * Referenced by: '<S29>/Constant1'
                                        */
  real_T _SampleTime;                  /* Expression: -1
                                        * Referenced by: '<Root>/가변저항'
                                        */
  real_T Delay_InitialCondition_f;     /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T Delay_InitialCondition_h;     /* Expression: 0.0
                                        * Referenced by: '<S3>/Delay'
                                        */
  real_T TmpRTBAtIfActionSubsystem1Outpo;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S1>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<S1>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<S1>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S1>/Pulse Generator'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S22>/Integrator2'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 12
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S27>/Constant'
                                        */
  real_T PulseGenerator_Amp_a;         /* Expression: 1
                                        * Referenced by: '<S27>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_p; /* Computed Parameter: PulseGenerator_Period_p
                                   * Referenced by: '<S27>/Pulse Generator'
                                   */
  real_T PulseGenerator_Duty_n;     /* Computed Parameter: PulseGenerator_Duty_n
                                     * Referenced by: '<S27>/Pulse Generator'
                                     */
  real_T PulseGenerator_PhaseDelay_f;  /* Expression: 0
                                        * Referenced by: '<S27>/Pulse Generator'
                                        */
  real_T Constant1_Value_m;            /* Expression: 0
                                        * Referenced by: '<S27>/Constant1'
                                        */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S27>/Merge'
                                       */
  real_T Merge1_InitialOutput;       /* Computed Parameter: Merge1_InitialOutput
                                      * Referenced by: '<S27>/Merge1'
                                      */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant4'
                                        */
  int64m_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S20>/Gain2'
                                        */
  int32_T DiscreteTransferFcn_InitialStat;
                          /* Computed Parameter: DiscreteTransferFcn_InitialStat
                           * Referenced by: '<S20>/Discrete Transfer Fcn'
                           */
  uint16_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S4>/Gain4'
                                        */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S27>/Gain'
                                        */
  P_IfActionSubsystem1_team_pro_T IfActionSubsystem3_c;/* '<S2>/If Action Subsystem3' */
  P_IfActionSubsystem1_team_pro_T IfActionSubsystem1_e;/* '<S2>/If Action Subsystem1' */
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
extern void team_project_state_and_cds_adj_sw_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void team_project_state_and_cds_adj_sw_initialize(void);
extern void team_project_state_and_cds_adj_sw_step0(void);
extern void team_project_state_and_cds_adj_sw_step2(void);
extern void team_project_state_and_cds_adj_sw_step3(void);
extern void team_project_state_and_cds_adj_sw_terminate(void);

/* Real-time Model object */
extern RT_MODEL_team_project_state_a_T *const team_project_state_and_cds_a_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S11>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S3>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S6>/Rate Transition1' : Eliminated since input and output rates are identical
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
 * '<Root>' : 'team_project_state_and_cds_adj_sw'
 * '<S1>'   : 'team_project_state_and_cds_adj_sw/LED_B Ctrl'
 * '<S2>'   : 'team_project_state_and_cds_adj_sw/LED_R Ctrl'
 * '<S3>'   : 'team_project_state_and_cds_adj_sw/State_Ctrl'
 * '<S4>'   : 'team_project_state_and_cds_adj_sw/Subsystem'
 * '<S5>'   : 'team_project_state_and_cds_adj_sw/Subsystem2'
 * '<S6>'   : 'team_project_state_and_cds_adj_sw/light_Ctrl'
 * '<S7>'   : 'team_project_state_and_cds_adj_sw/LED_B Ctrl/If Action Subsystem1'
 * '<S8>'   : 'team_project_state_and_cds_adj_sw/LED_B Ctrl/If Action Subsystem3'
 * '<S9>'   : 'team_project_state_and_cds_adj_sw/LED_R Ctrl/If Action Subsystem1'
 * '<S10>'  : 'team_project_state_and_cds_adj_sw/LED_R Ctrl/If Action Subsystem3'
 * '<S11>'  : 'team_project_state_and_cds_adj_sw/State_Ctrl/ADAS_state'
 * '<S12>'  : 'team_project_state_and_cds_adj_sw/State_Ctrl/drive_mode'
 * '<S13>'  : 'team_project_state_and_cds_adj_sw/State_Ctrl/ADAS_state/If Action Subsystem'
 * '<S14>'  : 'team_project_state_and_cds_adj_sw/State_Ctrl/ADAS_state/If Action Subsystem1'
 * '<S15>'  : 'team_project_state_and_cds_adj_sw/State_Ctrl/ADAS_state/If Action Subsystem/Chart'
 * '<S16>'  : 'team_project_state_and_cds_adj_sw/State_Ctrl/drive_mode/Chart'
 * '<S17>'  : 'team_project_state_and_cds_adj_sw/State_Ctrl/drive_mode/SW1'
 * '<S18>'  : 'team_project_state_and_cds_adj_sw/Subsystem/Chart'
 * '<S19>'  : 'team_project_state_and_cds_adj_sw/Subsystem/Chart1'
 * '<S20>'  : 'team_project_state_and_cds_adj_sw/Subsystem2/Subsystem3'
 * '<S21>'  : 'team_project_state_and_cds_adj_sw/Subsystem2/Subsystem4'
 * '<S22>'  : 'team_project_state_and_cds_adj_sw/Subsystem2/Subsystem5'
 * '<S23>'  : 'team_project_state_and_cds_adj_sw/Subsystem2/Subsystem3/Discrete Derivative'
 * '<S24>'  : 'team_project_state_and_cds_adj_sw/light_Ctrl/If Action Subsystem'
 * '<S25>'  : 'team_project_state_and_cds_adj_sw/light_Ctrl/Subsystem'
 * '<S26>'  : 'team_project_state_and_cds_adj_sw/light_Ctrl/Subsystem/Chart1'
 * '<S27>'  : 'team_project_state_and_cds_adj_sw/light_Ctrl/Subsystem/Subsystem'
 * '<S28>'  : 'team_project_state_and_cds_adj_sw/light_Ctrl/Subsystem/Subsystem/If Action Subsystem'
 * '<S29>'  : 'team_project_state_and_cds_adj_sw/light_Ctrl/Subsystem/Subsystem/If Action Subsystem1'
 * '<S30>'  : 'team_project_state_and_cds_adj_sw/light_Ctrl/Subsystem/Subsystem/If Action Subsystem2'
 * '<S31>'  : 'team_project_state_and_cds_adj_sw/light_Ctrl/Subsystem/Subsystem/If Action Subsystem1/If Action Subsystem'
 * '<S32>'  : 'team_project_state_and_cds_adj_sw/light_Ctrl/Subsystem/Subsystem/If Action Subsystem1/If Action Subsystem1'
 */
#endif                     /* RTW_HEADER_team_project_state_and_cds_adj_sw_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
