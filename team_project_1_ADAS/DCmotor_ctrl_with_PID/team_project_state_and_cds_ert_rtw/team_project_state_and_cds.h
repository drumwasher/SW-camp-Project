/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: team_project_state_and_cds.h
 *
 * Code generated for Simulink model 'team_project_state_and_cds'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Feb 12 16:58:36 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_team_project_state_and_cds_h_
#define RTW_HEADER_team_project_state_and_cds_h_
#ifndef team_project_state_and_cds_COMMON_INCLUDES_
#define team_project_state_and_cds_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_arduinoextint.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#include "MW_Ultrasonic.h"
#endif                         /* team_project_state_and_cds_COMMON_INCLUDES_ */

#include "team_project_state_and_cds_types.h"
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

/* Block states (default storage) for system '<S2>/If Action Subsystem1' */
typedef struct {
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S2>/If Action Subsystem1' */
} DW_IfActionSubsystem1_team_pr_T;

/* Block signals (default storage) */
typedef struct {
  int128m_T Gain2;                     /* '<S21>/Gain2' */
  int128m_T Gain2_g;                   /* '<S25>/Gain2' */
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
  int64m_T Gain1;                      /* '<S21>/Gain1' */
  int64m_T Gain1_a;                    /* '<S25>/Gain1' */
  int64m_T DiscreteTransferFcn;        /* '<S21>/Discrete Transfer Fcn' */
  int64m_T DiscreteTransferFcn_c;      /* '<S25>/Discrete Transfer Fcn' */
  real_T RateTransition;               /* '<S13>/Rate Transition' */
  real_T Delay;                        /* '<Root>/Delay' */
  real_T Delay_h;                      /* '<S3>/Delay' */
  real_T RateTransition2;              /* '<S12>/Rate Transition2' */
  real_T TmpRTBAtChart1Inport4;
  real_T TmpRTBAtChartInport4;
  real_T Constant;                     /* '<Root>/Constant' */
  real_T Constant1;                    /* '<Root>/Constant1' */
  real_T DataTypeConversion;           /* '<S4>/Data Type Conversion' */
  real_T Gain2_gz;                     /* '<S23>/Gain2' */
  real_T Gain3;                        /* '<S23>/Gain3' */
  real_T Subtract2;                    /* '<S23>/Subtract2' */
  real_T Saturation2;                  /* '<S5>/Saturation2' */
  real_T DataTypeConversion1;          /* '<S22>/Data Type Conversion1' */
  real_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<S5>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux3_at_outport_0Inport1' */
  real_T Gain2_f;                      /* '<S27>/Gain2' */
  real_T Gain3_k;                      /* '<S27>/Gain3' */
  real_T Subtract2_p;                  /* '<S27>/Subtract2' */
  real_T Saturation1;                  /* '<S6>/Saturation1' */
  real_T DataTypeConversion1_e;        /* '<S26>/Data Type Conversion1' */
  real_T TmpSignalConversionAtTAQSigLo_j[2];
  /* '<S6>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux2_at_outport_0Inport1' */
  real_T Gain1_g;                      /* '<S27>/Gain1' */
  real_T Gain1_p;                      /* '<S23>/Gain1' */
  real_T RateTransition_p;             /* '<S7>/Rate Transition' */
  real_T Merge;                        /* '<S32>/Merge' */
  real_T Gain2_i;                      /* '<Root>/Gain2' */
  real_T Gain1_k;                      /* '<Root>/Gain1' */
  real_T light_mode;                   /* '<S30>/Chart1' */
  real_T rout1;                        /* '<S4>/Chart1' */
  real_T rout2;                        /* '<S4>/Chart1' */
  real_T out1;                         /* '<S4>/Chart' */
  real_T out2;                         /* '<S4>/Chart' */
  real_T buzzer;                       /* '<S4>/Chart' */
  real_T drive_mode;                   /* '<S13>/Chart' */
  real_T ADAS_state;                   /* '<S14>/Chart' */
  real_T Mod;                          /* '<S15>/Mod' */
  real_T Mod_b;                        /* '<S18>/Mod' */
  real_T Derivative2;                  /* '<S27>/Derivative2' */
  real_T Gain1_m;                      /* '<S26>/Gain1' */
  int64m_T denAccum;
  int64m_T r10;
  int64m_T r11;
  int64m_T r12;
  int32_T DataTypeConversion1_d;       /* '<S21>/Data Type Conversion1' */
  int32_T DataTypeConversion1_a;       /* '<S25>/Data Type Conversion1' */
  uint8_T DataTypeConversion_h;        /* '<S22>/Data Type Conversion' */
  uint8_T DataTypeConversion_g;        /* '<S26>/Data Type Conversion' */
} B_team_project_state_and_cds_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_e_T obj; /* '<S25>/Encoder' */
  codertarget_arduinobase_int_e_T obj_p;/* '<S21>/Encoder' */
  codertarget_arduinobase_inter_T obj_k;/* '<Root>/가변저항' */
  codertarget_arduinobase_inter_T obj_d;/* '<Root>/Analog Input1' */
  codertarget_arduinobase_block_T obj_h;/* '<Root>/Digital Input' */
  codertarget_arduinobase_blo_e_T obj_e;/* '<S2>/Digital Output' */
  codertarget_arduinobase_blo_e_T obj_b;/* '<S1>/Digital Output' */
  codertarget_arduinobase_in_er_T obj_ky;/* '<S32>/PWM' */
  codertarget_arduinobase_in_er_T obj_dm;/* '<S26>/PWM' */
  codertarget_arduinobase_in_er_T obj_a;/* '<S22>/PWM' */
  real_T Delay_DSTATE;                 /* '<Root>/Delay' */
  real_T Delay_DSTATE_e;               /* '<S3>/Delay' */
  real_T Delay_DSTATE_j;               /* '<S15>/Delay' */
  real_T Delay_DSTATE_p;               /* '<S18>/Delay' */
  real_T TmpRTBAtChart1Inport4_Buffer0;/* synthesized block */
  real_T TmpRTBAtChartInport4_Buffer0; /* synthesized block */
  real_T TimeStampA;                   /* '<S23>/Derivative2' */
  real_T LastUAtTimeA;                 /* '<S23>/Derivative2' */
  real_T TimeStampB;                   /* '<S23>/Derivative2' */
  real_T LastUAtTimeB;                 /* '<S23>/Derivative2' */
  real_T TimeStampA_g;                 /* '<S27>/Derivative2' */
  real_T LastUAtTimeA_p;               /* '<S27>/Derivative2' */
  real_T TimeStampB_c;                 /* '<S27>/Derivative2' */
  real_T LastUAtTimeB_n;               /* '<S27>/Derivative2' */
  real_T state_1;                      /* '<S30>/Chart1' */
  real_T steering;                     /* '<S4>/Chart' */
  real_T default_o;                    /* '<S4>/Chart' */
  real_T state_1_e;                    /* '<S13>/Chart' */
  real_T ADAS_state;                   /* '<S13>/Chart' */
  real_T Light_state;                  /* '<S13>/Chart' */
  real_T state_2;                      /* '<S14>/Chart' */
  codertarget_arduinobase_i_erv_T obj_g;/* '<Root>/후방 초음파' */
  codertarget_arduinobase_i_erv_T obj_an;/* '<Root>/좌측 초음파' */
  codertarget_arduinobase_i_erv_T obj_km;/* '<Root>/전방 초음파' */
  codertarget_arduinobase_i_erv_T obj_av;/* '<Root>/우측 초음파' */
  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<S5>/Scope5' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S6>/Scope2' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<S6>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope4_PWORK;                      /* '<S5>/Scope4' */

  int32_T DiscreteTransferFcn_states;  /* '<S21>/Discrete Transfer Fcn' */
  int32_T DiscreteTransferFcn_states_m;/* '<S25>/Discrete Transfer Fcn' */
  int32_T UD_DSTATE;                   /* '<S24>/UD' */
  int32_T UD_DSTATE_m;                 /* '<S28>/UD' */
  int32_T clockTickCounter;            /* '<S1>/Pulse Generator' */
  uint32_T is_c4_team_project_state_and_cd;/* '<S30>/Chart1' */
  uint32_T is_c5_team_project_state_and_cd;/* '<S4>/Chart1' */
  uint32_T is_c2_team_project_state_and_cd;/* '<S4>/Chart' */
  uint32_T is_c3_team_project_state_and_cd;/* '<S13>/Chart' */
  uint32_T is_c1_team_project_state_and_cd;/* '<S14>/Chart' */
  int8_T If_ActiveSubsystem;           /* '<S3>/If' */
  int8_T If1_ActiveSubsystem;          /* '<S1>/If1' */
  int8_T If1_ActiveSubsystem_d;        /* '<S2>/If1' */
  int8_T If_ActiveSubsystem_h;         /* '<S32>/If' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S7>/If Action Subsystem' */
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<S32>/If Action Subsystem2' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S32>/If Action Subsystem1' */
  int8_T IfActionSubsystem1_SubsysRanB_g;/* '<S34>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC_e;/* '<S34>/If Action Subsystem' */
  int8_T IfActionSubsystem_SubsysRanBC_a;/* '<S32>/If Action Subsystem' */
  int8_T IfActionSubsystem_SubsysRanBC_n;/* '<S12>/If Action Subsystem' */
  int8_T IfActionSubsystem3_SubsysRanBC;/* '<S1>/If Action Subsystem3' */
  int8_T IfActionSubsystem1_SubsysRanB_h;/* '<S1>/If Action Subsystem1' */
  int8_T SW2_SubsysRanBC;              /* '<S12>/SW2' */
  int8_T SW1_SubsysRanBC;              /* '<S13>/SW1' */
  uint8_T is_active_c4_team_project_state;/* '<S30>/Chart1' */
  uint8_T is_active_c5_team_project_state;/* '<S4>/Chart1' */
  uint8_T is_active_c2_team_project_state;/* '<S4>/Chart' */
  uint8_T is_active_c3_team_project_state;/* '<S13>/Chart' */
  uint8_T is_active_c1_team_project_state;/* '<S14>/Chart' */
  DW_IfActionSubsystem1_team_pr_T IfActionSubsystem3_c;/* '<S2>/If Action Subsystem3' */
  DW_IfActionSubsystem1_team_pr_T IfActionSubsystem1_e;/* '<S2>/If Action Subsystem1' */
} DW_team_project_state_and_cds_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S23>/Integrator2' */
  real_T Integrator2_CSTATE_f;         /* '<S27>/Integrator2' */
} X_team_project_state_and_cds_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S23>/Integrator2' */
  real_T Integrator2_CSTATE_f;         /* '<S27>/Integrator2' */
} XDot_team_project_state_and_c_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator2_CSTATE;        /* '<S23>/Integrator2' */
  boolean_T Integrator2_CSTATE_f;      /* '<S27>/Integrator2' */
} XDis_team_project_state_and_c_T;

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
} ExtY_team_project_state_and_c_T;

/* Parameters for system: '<S2>/If Action Subsystem1' */
struct P_IfActionSubsystem1_team_pro_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S10>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_team_project_state_and_cds_T_ {
  real_T KD;                           /* Variable: KD
                                        * Referenced by:
                                        *   '<S23>/Gain3'
                                        *   '<S27>/Gain3'
                                        */
  real_T KI;                           /* Variable: KI
                                        * Referenced by:
                                        *   '<S23>/Gain1'
                                        *   '<S27>/Gain1'
                                        */
  real_T KP;                           /* Variable: KP
                                        * Referenced by:
                                        *   '<S23>/Gain2'
                                        *   '<S27>/Gain2'
                                        */
  real_T Vlim;                         /* Variable: Vlim
                                        * Referenced by:
                                        *   '<S22>/Gain1'
                                        *   '<S26>/Gain1'
                                        */
  int32_T den_Gd[2];                   /* Variable: den_Gd
                                        * Referenced by:
                                        *   '<S21>/Discrete Transfer Fcn'
                                        *   '<S25>/Discrete Transfer Fcn'
                                        */
  int32_T encoder_scale;               /* Variable: encoder_scale
                                        * Referenced by:
                                        *   '<S21>/Gain1'
                                        *   '<S25>/Gain1'
                                        */
  int32_T num_Gd[2];                   /* Variable: num_Gd
                                        * Referenced by:
                                        *   '<S21>/Discrete Transfer Fcn'
                                        *   '<S25>/Discrete Transfer Fcn'
                                        */
  int32_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S24>/UD'
                               */
  int32_T DiscreteDerivative_ICPrevScal_g;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_g
                               * Referenced by: '<S28>/UD'
                               */
  real_T AnalogInput1_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input'
                                        */
  real_T Output_Y0;                    /* Computed Parameter: Output_Y0
                                        * Referenced by: '<S18>/Output'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S18>/Delay'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S18>/Constant1'
                                        */
  real_T SW2_Y0;                       /* Computed Parameter: SW2_Y0
                                        * Referenced by: '<S15>/SW2'
                                        */
  real_T Constant_Value_m;             /* Expression: 1
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Delay_InitialCondition_n;     /* Expression: 0
                                        * Referenced by: '<S15>/Delay'
                                        */
  real_T Constant1_Value_d;            /* Expression: 2
                                        * Referenced by: '<S15>/Constant1'
                                        */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S21>/Encoder'
                                        */
  real_T Encoder_SampleTime_e;         /* Expression: -1
                                        * Referenced by: '<S25>/Encoder'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S34>/Constant'
                                        */
  real_T Constant1_Value_f;            /* Expression: 0
                                        * Referenced by: '<S34>/Constant1'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S29>/Out1'
                                        */
  real_T _SampleTime;                  /* Expression: -1
                                        * Referenced by: '<Root>/가변저항'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S23>/Integrator2'
                                        */
  real_T Delay_InitialCondition_f;     /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T Delay_InitialCondition_h;     /* Expression: 0.0
                                        * Referenced by: '<S3>/Delay'
                                        */
  real_T TmpRTBAtChart1Inport4_InitialCo;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpRTBAtChartInport4_InitialCon;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Constant_Value_g;             /* Expression: 100
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value_i;            /* Expression: 100
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 12
                                        * Referenced by: '<S5>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S5>/Saturation2'
                                        */
  real_T Integrator2_IC_f;             /* Expression: 0
                                        * Referenced by: '<S27>/Integrator2'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 12
                                        * Referenced by: '<S6>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S6>/Saturation1'
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
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S32>/Constant'
                                        */
  real_T Constant1_Value_m;            /* Expression: 0
                                        * Referenced by: '<S32>/Constant1'
                                        */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S32>/Merge'
                                       */
  real_T Gain2_Gain;                   /* Expression: 100
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<Root>/Gain1'
                                        */
  int64m_T Gain2_Gain_n;               /* Computed Parameter: Gain2_Gain_n
                                        * Referenced by: '<S21>/Gain2'
                                        */
  int64m_T Gain2_Gain_d;               /* Computed Parameter: Gain2_Gain_d
                                        * Referenced by: '<S25>/Gain2'
                                        */
  int32_T DiscreteTransferFcn_InitialStat;
                          /* Computed Parameter: DiscreteTransferFcn_InitialStat
                           * Referenced by: '<S21>/Discrete Transfer Fcn'
                           */
  int32_T DiscreteTransferFcn_InitialSt_i;
                          /* Computed Parameter: DiscreteTransferFcn_InitialSt_i
                           * Referenced by: '<S25>/Discrete Transfer Fcn'
                           */
  uint16_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S4>/Gain4'
                                        */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S32>/Gain'
                                        */
  P_IfActionSubsystem1_team_pro_T IfActionSubsystem3_c;/* '<S2>/If Action Subsystem3' */
  P_IfActionSubsystem1_team_pro_T IfActionSubsystem1_e;/* '<S2>/If Action Subsystem1' */
};

/* Real-time Model Data Structure */
struct tag_RTM_team_project_state_an_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_team_project_state_and_cds_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_team_project_state_and_c_T *contStateDisabled;
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
    uint32_T clockTick3;
    uint8_T rtmDbBufReadBuf3;
    uint8_T rtmDbBufWriteBuf3;
    boolean_T rtmDbBufLastBufWr3;
    uint32_T rtmDbBufClockTick3[2];
    uint32_T clockTick4;
    uint8_T rtmDbBufReadBuf4;
    uint8_T rtmDbBufWriteBuf4;
    boolean_T rtmDbBufLastBufWr4;
    uint32_T rtmDbBufClockTick4[2];
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
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
extern P_team_project_state_and_cds_T team_project_state_and_cds_P;

/* Block signals (default storage) */
extern B_team_project_state_and_cds_T team_project_state_and_cds_B;

/* Continuous states (default storage) */
extern X_team_project_state_and_cds_T team_project_state_and_cds_X;

/* Disabled states (default storage) */
extern XDis_team_project_state_and_c_T team_project_state_and_cds_XDis;

/* Block states (default storage) */
extern DW_team_project_state_and_cds_T team_project_state_and_cds_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_team_project_state_and_c_T team_project_state_and_cds_Y;

/* External function called from main */
extern void team_project_state_and_cds_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void team_project_state_and_cds_initialize(void);
extern void team_project_state_and_cds_step0(void);
extern void team_project_state_and_cds_step2(void);
extern void team_project_state_and_cds_terminate(void);

/* Real-time Model object */
extern RT_MODEL_team_project_state_a_T *const team_project_state_and_cds_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Gain' : Unused code path elimination
 * Block '<Root>/Gain3' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/If' : Unused code path elimination
 * Block '<S29>/Constant' : Unused code path elimination
 * Block '<S29>/Constant1' : Unused code path elimination
 * Block '<S29>/Delay' : Unused code path elimination
 * Block '<S29>/Mod' : Unused code path elimination
 * Block '<S29>/Plus' : Unused code path elimination
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
 * '<Root>' : 'team_project_state_and_cds'
 * '<S1>'   : 'team_project_state_and_cds/LED_B Ctrl'
 * '<S2>'   : 'team_project_state_and_cds/LED_R Ctrl'
 * '<S3>'   : 'team_project_state_and_cds/State_Ctrl'
 * '<S4>'   : 'team_project_state_and_cds/Subsystem'
 * '<S5>'   : 'team_project_state_and_cds/Subsystem1'
 * '<S6>'   : 'team_project_state_and_cds/Subsystem2'
 * '<S7>'   : 'team_project_state_and_cds/light_Ctrl'
 * '<S8>'   : 'team_project_state_and_cds/LED_B Ctrl/If Action Subsystem1'
 * '<S9>'   : 'team_project_state_and_cds/LED_B Ctrl/If Action Subsystem3'
 * '<S10>'  : 'team_project_state_and_cds/LED_R Ctrl/If Action Subsystem1'
 * '<S11>'  : 'team_project_state_and_cds/LED_R Ctrl/If Action Subsystem3'
 * '<S12>'  : 'team_project_state_and_cds/State_Ctrl/ADAS_state'
 * '<S13>'  : 'team_project_state_and_cds/State_Ctrl/drive_mode'
 * '<S14>'  : 'team_project_state_and_cds/State_Ctrl/ADAS_state/If Action Subsystem'
 * '<S15>'  : 'team_project_state_and_cds/State_Ctrl/ADAS_state/SW2'
 * '<S16>'  : 'team_project_state_and_cds/State_Ctrl/ADAS_state/If Action Subsystem/Chart'
 * '<S17>'  : 'team_project_state_and_cds/State_Ctrl/drive_mode/Chart'
 * '<S18>'  : 'team_project_state_and_cds/State_Ctrl/drive_mode/SW1'
 * '<S19>'  : 'team_project_state_and_cds/Subsystem/Chart'
 * '<S20>'  : 'team_project_state_and_cds/Subsystem/Chart1'
 * '<S21>'  : 'team_project_state_and_cds/Subsystem1/Subsystem7'
 * '<S22>'  : 'team_project_state_and_cds/Subsystem1/Subsystem8'
 * '<S23>'  : 'team_project_state_and_cds/Subsystem1/Subsystem9'
 * '<S24>'  : 'team_project_state_and_cds/Subsystem1/Subsystem7/Discrete Derivative'
 * '<S25>'  : 'team_project_state_and_cds/Subsystem2/Subsystem3'
 * '<S26>'  : 'team_project_state_and_cds/Subsystem2/Subsystem4'
 * '<S27>'  : 'team_project_state_and_cds/Subsystem2/Subsystem5'
 * '<S28>'  : 'team_project_state_and_cds/Subsystem2/Subsystem3/Discrete Derivative'
 * '<S29>'  : 'team_project_state_and_cds/light_Ctrl/If Action Subsystem'
 * '<S30>'  : 'team_project_state_and_cds/light_Ctrl/Subsystem'
 * '<S31>'  : 'team_project_state_and_cds/light_Ctrl/Subsystem/Chart1'
 * '<S32>'  : 'team_project_state_and_cds/light_Ctrl/Subsystem/Subsystem'
 * '<S33>'  : 'team_project_state_and_cds/light_Ctrl/Subsystem/Subsystem/If Action Subsystem'
 * '<S34>'  : 'team_project_state_and_cds/light_Ctrl/Subsystem/Subsystem/If Action Subsystem1'
 * '<S35>'  : 'team_project_state_and_cds/light_Ctrl/Subsystem/Subsystem/If Action Subsystem2'
 * '<S36>'  : 'team_project_state_and_cds/light_Ctrl/Subsystem/Subsystem/If Action Subsystem1/If Action Subsystem'
 * '<S37>'  : 'team_project_state_and_cds/light_Ctrl/Subsystem/Subsystem/If Action Subsystem1/If Action Subsystem1'
 */
#endif                            /* RTW_HEADER_team_project_state_and_cds_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
