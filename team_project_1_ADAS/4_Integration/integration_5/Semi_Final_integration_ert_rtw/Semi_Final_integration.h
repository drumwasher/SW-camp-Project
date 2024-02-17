/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Semi_Final_integration.h
 *
 * Code generated for Simulink model 'Semi_Final_integration'.
 *
 * Model version                  : 1.47
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Feb 15 09:25:14 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Semi_Final_integration_h_
#define RTW_HEADER_Semi_Final_integration_h_
#ifndef Semi_Final_integration_COMMON_INCLUDES_
#define Semi_Final_integration_COMMON_INCLUDES_
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
#endif                             /* Semi_Final_integration_COMMON_INCLUDES_ */

#include "Semi_Final_integration_types.h"
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

/* Block states (default storage) for system '<S2>/If Action Subsystem1' */
typedef struct {
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S2>/If Action Subsystem1' */
} DW_IfActionSubsystem1_Semi_Fi_T;

/* Block states (default storage) for system '<S46>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S46>/If Action Subsystem' */
} DW_IfActionSubsystem_Semi_Fin_T;

/* Block signals (default storage) */
typedef struct {
  int128m_T Gain2;                     /* '<S9>/Gain2' */
  int128m_T Gain2_j;                   /* '<S4>/Gain2' */
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
  uint64m_T Gain;                      /* '<S46>/Gain' */
  int64m_T Gain1;                      /* '<S9>/Gain1' */
  int64m_T Gain1_h;                    /* '<S4>/Gain1' */
  int64m_T DiscreteTransferFcn;        /* '<S9>/Discrete Transfer Fcn' */
  int64m_T DiscreteTransferFcn_l;      /* '<S4>/Discrete Transfer Fcn' */
  real_T RateTransition;               /* '<S18>/Rate Transition' */
  real_T Constant7;                    /* '<Root>/Constant7' */
  real_T Constant8;                    /* '<Root>/Constant8' */
  real_T Constant6;                    /* '<Root>/Constant6' */
  real_T Constant4;                    /* '<Root>/Constant4' */
  real_T Delay;                        /* '<Root>/Delay' */
  real_T Delay_f;                      /* '<S3>/Delay' */
  real_T Merge7;                       /* '<S29>/Merge7' */
  real_T Gain2_k;                      /* '<S11>/Gain2' */
  real_T Gain3;                        /* '<S11>/Gain3' */
  real_T Subtract2;                    /* '<S11>/Subtract2' */
  real_T Saturation1;                  /* '<Root>/Saturation1' */
  real_T DataTypeConversion1;          /* '<S10>/Data Type Conversion1' */
  real_T Gain1_e;                      /* '<S11>/Gain1' */
  real_T Merge8;                       /* '<S29>/Merge8' */
  real_T Gain2_n;                      /* '<S6>/Gain2' */
  real_T Gain3_g;                      /* '<S6>/Gain3' */
  real_T Subtract2_c;                  /* '<S6>/Subtract2' */
  real_T Saturation2;                  /* '<Root>/Saturation2' */
  real_T DataTypeConversion1_n;        /* '<S5>/Data Type Conversion1' */
  real_T Gain1_j;                      /* '<S6>/Gain1' */
  real_T RateTransition_l;             /* '<S12>/Rate Transition' */
  real_T Merge;                        /* '<S46>/Merge' */
  real_T Merge1;                       /* '<S46>/Merge1' */
  real_T Mod;                          /* '<S42>/Mod' */
  real_T Subtract;                     /* '<S38>/Subtract' */
  real_T Product;                      /* '<S38>/Product' */
  real_T Subtract1;                    /* '<S38>/Subtract1' */
  real_T Product1;                     /* '<S38>/Product1' */
  real_T sw2;                          /* '<S19>/sw2' */
  real_T Mod1;                         /* '<S20>/Mod1' */
  real_T Merge_e;                      /* '<S21>/Merge' */
  real_T Add5;                         /* '<Root>/Add5' */
  real_T Product_m;                    /* '<S1>/Product' */
  real_T Product1_c;                   /* '<S1>/Product1' */
  real_T Plus;                         /* '<S42>/Plus' */
  int64m_T denAccum;
  int64m_T r10;
  int64m_T r11;
  int64m_T r12;
  int32_T DataTypeConversion1_m;       /* '<S9>/Data Type Conversion1' */
  int32_T DataTypeConversion1_l;       /* '<S4>/Data Type Conversion1' */
  uint8_T DataTypeConversion;          /* '<S10>/Data Type Conversion' */
  uint8_T DataTypeConversion_g;        /* '<S5>/Data Type Conversion' */
  boolean_T RateTransition2;           /* '<S3>/Rate Transition2' */
  boolean_T DigitalInput2;             /* '<Root>/Digital Input2' */
  boolean_T DigitalInput1;             /* '<Root>/Digital Input1' */
} B_Semi_Final_integration_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_m_T obj; /* '<S9>/Encoder' */
  codertarget_arduinobase_int_m_T obj_d;/* '<S4>/Encoder' */
  codertarget_arduinobase_inter_T obj_h;/* '<Root>/가변저항' */
  codertarget_arduinobase_inter_T obj_j;/* '<Root>/Analog Input1' */
  codertarget_arduinobase_block_T obj_p;/* '<Root>/Digital Input2' */
  codertarget_arduinobase_block_T obj_c;/* '<Root>/Digital Input1' */
  codertarget_arduinobase_blo_m_T obj_a;/* '<S46>/Digital Output1' */
  codertarget_arduinobase_blo_m_T obj_cz;/* '<S46>/Digital Output' */
  codertarget_arduinobase_blo_m_T obj_e;/* '<S2>/Digital Output' */
  codertarget_arduinobase_blo_m_T obj_k;/* '<S1>/Digital Output' */
  codertarget_arduinobase_blo_m_T obj_j4;/* '<Root>/Digital Output' */
  codertarget_arduinobase_in_mm_T obj_pk;/* '<S10>/PWM' */
  codertarget_arduinobase_in_mm_T obj_a5;/* '<S7>/PWM' */
  codertarget_arduinobase_in_mm_T obj_ey;/* '<S5>/PWM' */
  real_T Delay_DSTATE;                 /* '<Root>/Delay' */
  real_T Delay_DSTATE_e;               /* '<S3>/Delay' */
  real_T Delay_DSTATE_g;               /* '<S42>/Delay' */
  real_T Delay1_DSTATE;                /* '<S20>/Delay1' */
  real_T Delay_DSTATE_p;               /* '<S21>/Delay' */
  real_T TimeStampA;                   /* '<S11>/Derivative2' */
  real_T LastUAtTimeA;                 /* '<S11>/Derivative2' */
  real_T TimeStampB;                   /* '<S11>/Derivative2' */
  real_T LastUAtTimeB;                 /* '<S11>/Derivative2' */
  real_T TimeStampA_c;                 /* '<S6>/Derivative2' */
  real_T LastUAtTimeA_b;               /* '<S6>/Derivative2' */
  real_T TimeStampB_g;                 /* '<S6>/Derivative2' */
  real_T LastUAtTimeB_p;               /* '<S6>/Derivative2' */
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

  struct {
    void *LoggedData;
  } Scope10_PWORK;                     /* '<Root>/Scope10' */

  struct {
    void *LoggedData;
  } Scope9_PWORK;                      /* '<Root>/Scope9' */

  int32_T DiscreteTransferFcn_states;  /* '<S9>/Discrete Transfer Fcn' */
  int32_T DiscreteTransferFcn_states_g;/* '<S4>/Discrete Transfer Fcn' */
  int32_T UD_DSTATE;                   /* '<S41>/UD' */
  int32_T UD_DSTATE_f;                 /* '<S26>/UD' */
  int32_T clockTickCounter;            /* '<S1>/Pulse Generator' */
  int32_T clockTickCounter_m;          /* '<S46>/Pulse Generator' */
  int32_T clockTickCounter_h;          /* '<S27>/Pulse Generator' */
  int8_T If_ActiveSubsystem;           /* '<S12>/If' */
  int8_T If_ActiveSubsystem_c;         /* '<S17>/If' */
  int8_T If_ActiveSubsystem_d;         /* '<S3>/If' */
  int8_T If1_ActiveSubsystem;          /* '<S1>/If1' */
  int8_T If3_ActiveSubsystem;          /* '<S29>/If3' */
  int8_T If_ActiveSubsystem_p;         /* '<S46>/If' */
  int8_T If_ActiveSubsystem_b;         /* '<S7>/If' */
  int8_T If1_ActiveSubsystem_i;        /* '<S2>/If1' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S46>/If Action Subsystem1' */
  int8_T IfActionSubsystem1_SubsysRanB_e;/* '<S48>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S48>/If Action Subsystem' */
  int8_T IfActionSubsystem_SubsysRanBC_m;/* '<S12>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanB_k;/* '<S42>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC_o;/* '<S42>/If Action Subsystem' */
  int8_T IfActionSubsystem11_SubsysRanBC;/* '<S29>/If Action Subsystem11' */
  int8_T IfActionSubsystem3_SubsysRanBC;/* '<S31>/If Action Subsystem3' */
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<S31>/If Action Subsystem2' */
  int8_T IfActionSubsystem_SubsysRanBC_k;/* '<S31>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRan_ef;/* '<S31>/If Action Subsystem1' */
  int8_T IfActionSubsystem3_SubsysRanB_a;/* '<S34>/If Action Subsystem3' */
  int8_T IfActionSubsystem2_SubsysRanB_g;/* '<S34>/If Action Subsystem2' */
  int8_T IfActionSubsystem1_SubsysRanB_f;/* '<S34>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC_f;/* '<S34>/If Action Subsystem' */
  int8_T IfActionSubsystem10_SubsysRanBC;/* '<S29>/If Action Subsystem10' */
  int8_T IfActionSubsystem9_SubsysRanBC;/* '<S29>/If Action Subsystem9' */
  int8_T IfActionSubsystem_SubsysRanBC_e;/* '<S7>/If Action Subsystem' */
  int8_T IfActionSubsystem_SubsysRanBC_p;/* '<S17>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanB_j;/* '<S17>/If Action Subsystem1' */
  int8_T IfActionSubsystem3_SubsysRanB_o;/* '<S1>/If Action Subsystem3' */
  int8_T IfActionSubsystem1_SubsysRan_kd;/* '<S1>/If Action Subsystem1' */
  int8_T SW1_SubsysRanBC;              /* '<S18>/SW1' */
  int8_T IfActionSubsystem1_SubsysRanB_c;/* '<S21>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC_c;/* '<S23>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRan_fq;/* '<S23>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC_a;/* '<S21>/If Action Subsystem' */
  DW_IfActionSubsystem_Semi_Fin_T IfActionSubsystem2;/* '<S46>/If Action Subsystem2' */
  DW_IfActionSubsystem_Semi_Fin_T IfActionSubsystem_p;/* '<S46>/If Action Subsystem' */
  DW_IfActionSubsystem1_Semi_Fi_T IfActionSubsystem1_a;/* '<S7>/If Action Subsystem1' */
  DW_IfActionSubsystem1_Semi_Fi_T IfActionSubsystem3_m;/* '<S2>/If Action Subsystem3' */
  DW_IfActionSubsystem1_Semi_Fi_T IfActionSubsystem1_m;/* '<S2>/If Action Subsystem1' */
} DW_Semi_Final_integration_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S11>/Integrator2' */
  real_T Integrator2_CSTATE_i;         /* '<S6>/Integrator2' */
} X_Semi_Final_integration_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S11>/Integrator2' */
  real_T Integrator2_CSTATE_i;         /* '<S6>/Integrator2' */
} XDot_Semi_Final_integration_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator2_CSTATE;        /* '<S11>/Integrator2' */
  boolean_T Integrator2_CSTATE_i;      /* '<S6>/Integrator2' */
} XDis_Semi_Final_integration_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters for system: '<S2>/If Action Subsystem1' */
struct P_IfActionSubsystem1_Semi_Fin_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S15>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_Semi_Final_integration_T_ {
  real_T KD;                           /* Variable: KD
                                        * Referenced by:
                                        *   '<S6>/Gain3'
                                        *   '<S11>/Gain3'
                                        */
  real_T KI;                           /* Variable: KI
                                        * Referenced by:
                                        *   '<S6>/Gain1'
                                        *   '<S11>/Gain1'
                                        */
  real_T KP;                           /* Variable: KP
                                        * Referenced by:
                                        *   '<S6>/Gain2'
                                        *   '<S11>/Gain2'
                                        */
  real_T Vlim;                         /* Variable: Vlim
                                        * Referenced by:
                                        *   '<S5>/Gain1'
                                        *   '<S10>/Gain1'
                                        */
  real_T b;                            /* Variable: b
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T default1;                     /* Variable: default1
                                        * Referenced by:
                                        *   '<S30>/Constant'
                                        *   '<S30>/Constant3'
                                        *   '<S37>/Constant'
                                        *   '<S37>/Constant3'
                                        *   '<S38>/Constant'
                                        *   '<S39>/Constant'
                                        *   '<S40>/Constant'
                                        *   '<S40>/Constant1'
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
  real_T steering;                     /* Variable: steering
                                        * Referenced by:
                                        *   '<S37>/Constant1'
                                        *   '<S38>/Constant1'
                                        *   '<S39>/Constant1'
                                        */
  int32_T den_Gd[2];                   /* Variable: den_Gd
                                        * Referenced by:
                                        *   '<S4>/Discrete Transfer Fcn'
                                        *   '<S9>/Discrete Transfer Fcn'
                                        */
  int32_T encoder_scale;               /* Variable: encoder_scale
                                        * Referenced by:
                                        *   '<S4>/Gain1'
                                        *   '<S9>/Gain1'
                                        */
  int32_T num_Gd[2];                   /* Variable: num_Gd
                                        * Referenced by:
                                        *   '<S4>/Discrete Transfer Fcn'
                                        *   '<S9>/Discrete Transfer Fcn'
                                        */
  int32_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S41>/UD'
                               */
  int32_T DiscreteDerivative_ICPrevScal_m;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_m
                               * Referenced by: '<S26>/UD'
                               */
  real_T AnalogInput1_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  real_T DigitalInput1_SampleTime;     /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input1'
                                        */
  real_T DigitalInput2_SampleTime;     /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input2'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S23>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S21>/Constant2'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S21>/Delay'
                                        */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S21>/Merge'
                                       */
  real_T sw2_Y0;                       /* Computed Parameter: sw2_Y0
                                        * Referenced by: '<S20>/sw2'
                                        */
  real_T Constant2_Value_i;            /* Expression: 1
                                        * Referenced by: '<S20>/Constant2'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S20>/Delay1'
                                        */
  real_T Constant3_Value;              /* Expression: 2
                                        * Referenced by: '<S20>/Constant3'
                                        */
  real_T ADAS_state_Y0;                /* Computed Parameter: ADAS_state_Y0
                                        * Referenced by: '<S19>/ADAS_state'
                                        */
  real_T Encoder_SampleTime;           /* Expression: 0.01
                                        * Referenced by: '<S4>/Encoder'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S27>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<S27>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<S27>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S27>/Pulse Generator'
                                        */
  real_T Constant_Value_h;             /* Expression: 0
                                        * Referenced by: '<S32>/Constant'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S30>/Constant4'
                                        */
  real_T Constant1_Value_e;            /* Expression: 100
                                        * Referenced by: '<S30>/Constant1'
                                        */
  real_T Constant5_Value;              /* Expression: 6.4
                                        * Referenced by: '<S30>/Constant5'
                                        */
  real_T Constant2_Value_p;            /* Expression: 128
                                        * Referenced by: '<S30>/Constant2'
                                        */
  real_T Constant8_Value;              /* Expression: 1
                                        * Referenced by: '<S30>/Constant8'
                                        */
  real_T Constant6_Value;              /* Expression: 100
                                        * Referenced by: '<S30>/Constant6'
                                        */
  real_T Constant9_Value;              /* Expression: 6.4
                                        * Referenced by: '<S30>/Constant9'
                                        */
  real_T Constant7_Value;              /* Expression: 128
                                        * Referenced by: '<S30>/Constant7'
                                        */
  real_T Constant10_Value;             /* Expression: 0
                                        * Referenced by: '<S30>/Constant10'
                                        */
  real_T Constant2_Value_a;            /* Expression: 1
                                        * Referenced by: '<S37>/Constant2'
                                        */
  real_T Constant4_Value_b;            /* Expression: 10
                                        * Referenced by: '<S38>/Constant4'
                                        */
  real_T Constant2_Value_o;            /* Expression: 1
                                        * Referenced by: '<S38>/Constant2'
                                        */
  real_T Constant2_Value_pl;           /* Expression: 1
                                        * Referenced by: '<S39>/Constant2'
                                        */
  real_T Constant4_Value_k;            /* Expression: 10
                                        * Referenced by: '<S39>/Constant4'
                                        */
  real_T Constant_Value_n;             /* Expression: 0
                                        * Referenced by: '<S34>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: 0
                                        * Referenced by: '<S33>/Constant'
                                        */
  real_T Constant1_Value_f;            /* Expression: 0
                                        * Referenced by: '<S33>/Constant1'
                                        */
  real_T Constant2_Value_k;            /* Expression: 1
                                        * Referenced by: '<S33>/Constant2'
                                        */
  real_T Gain_Gain;                    /* Expression: 1.2
                                        * Referenced by: '<S36>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1.2
                                        * Referenced by: '<S36>/Gain1'
                                        */
  real_T Encoder_SampleTime_a;         /* Expression: 0.01
                                        * Referenced by: '<S9>/Encoder'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S42>/Out1'
                                        */
  real_T Constant_Value_a;             /* Expression: 1
                                        * Referenced by: '<S42>/Constant'
                                        */
  real_T Constant2_Value_f;            /* Expression: 0
                                        * Referenced by: '<S42>/Constant2'
                                        */
  real_T Constant1_Value_c;            /* Expression: 3
                                        * Referenced by: '<S42>/Constant1'
                                        */
  real_T Delay_InitialCondition_o;     /* Expression: 0.0
                                        * Referenced by: '<S42>/Delay'
                                        */
  real_T Constant_Value_g;             /* Expression: 1
                                        * Referenced by: '<S48>/Constant'
                                        */
  real_T Constant1_Value_ei;           /* Expression: 0
                                        * Referenced by: '<S48>/Constant1'
                                        */
  real_T _SampleTime;                  /* Expression: -1
                                        * Referenced by: '<Root>/가변저항'
                                        */
  real_T PulseGenerator_Amp_j;         /* Expression: 1
                                        * Referenced by: '<S1>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_c; /* Computed Parameter: PulseGenerator_Period_c
                                   * Referenced by: '<S1>/Pulse Generator'
                                   */
  real_T PulseGenerator_Duty_f;     /* Computed Parameter: PulseGenerator_Duty_f
                                     * Referenced by: '<S1>/Pulse Generator'
                                     */
  real_T PulseGenerator_PhaseDelay_l;  /* Expression: 0
                                        * Referenced by: '<S1>/Pulse Generator'
                                        */
  real_T Constant_Value_hz;            /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Delay_InitialCondition_k;     /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T Delay_InitialCondition_f;     /* Expression: 0.0
                                        * Referenced by: '<S3>/Delay'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S11>/Integrator2'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 12
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 2
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Constant16_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant16'
                                        */
  real_T Switch1_Threshold;            /* Expression: 1.6
                                        * Referenced by: '<Root>/Switch1'
                                        */
  real_T Integrator2_IC_g;             /* Expression: 0
                                        * Referenced by: '<S6>/Integrator2'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 12
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  real_T Constant9_Value_i;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant9'
                                        */
  real_T Switch_Threshold;             /* Expression: 1.6
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Constant_Value_pa;            /* Expression: 1
                                        * Referenced by: '<S46>/Constant'
                                        */
  real_T PulseGenerator_Amp_g;         /* Expression: 1
                                        * Referenced by: '<S46>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_d; /* Computed Parameter: PulseGenerator_Period_d
                                   * Referenced by: '<S46>/Pulse Generator'
                                   */
  real_T PulseGenerator_Duty_p;     /* Computed Parameter: PulseGenerator_Duty_p
                                     * Referenced by: '<S46>/Pulse Generator'
                                     */
  real_T PulseGenerator_PhaseDelay_g;  /* Expression: 0
                                        * Referenced by: '<S46>/Pulse Generator'
                                        */
  real_T Constant1_Value_k;            /* Expression: 0
                                        * Referenced by: '<S46>/Constant1'
                                        */
  real_T Merge_InitialOutput_b;     /* Computed Parameter: Merge_InitialOutput_b
                                     * Referenced by: '<S46>/Merge'
                                     */
  real_T Merge1_InitialOutput;       /* Computed Parameter: Merge1_InitialOutput
                                      * Referenced by: '<S46>/Merge1'
                                      */
  real_T Constant13_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant13'
                                        */
  int64m_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S9>/Gain2'
                                        */
  int64m_T Gain2_Gain_g;               /* Computed Parameter: Gain2_Gain_g
                                        * Referenced by: '<S4>/Gain2'
                                        */
  int32_T DiscreteTransferFcn_InitialStat;
                          /* Computed Parameter: DiscreteTransferFcn_InitialStat
                           * Referenced by: '<S9>/Discrete Transfer Fcn'
                           */
  int32_T DiscreteTransferFcn_InitialSt_p;
                          /* Computed Parameter: DiscreteTransferFcn_InitialSt_p
                           * Referenced by: '<S4>/Discrete Transfer Fcn'
                           */
  uint32_T Gain_Gain_l;                /* Computed Parameter: Gain_Gain_l
                                        * Referenced by: '<S46>/Gain'
                                        */
  uint16_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S8>/Gain4'
                                        */
  uint16_T Gain12_Gain;                /* Computed Parameter: Gain12_Gain
                                        * Referenced by: '<Root>/Gain12'
                                        */
  P_IfActionSubsystem1_Semi_Fin_T IfActionSubsystem1_a;/* '<S7>/If Action Subsystem1' */
  P_IfActionSubsystem1_Semi_Fin_T IfActionSubsystem3_m;/* '<S2>/If Action Subsystem3' */
  P_IfActionSubsystem1_Semi_Fin_T IfActionSubsystem1_m;/* '<S2>/If Action Subsystem1' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Semi_Final_integratio_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_Semi_Final_integration_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_Semi_Final_integration_T *contStateDisabled;
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
    uint32_T clockTick4;
    uint8_T rtmDbBufReadBuf4;
    uint8_T rtmDbBufWriteBuf4;
    boolean_T rtmDbBufLastBufWr4;
    uint32_T rtmDbBufClockTick4[2];
    struct {
      uint8_T TID[4];
    } TaskCounters;

    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[5];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Semi_Final_integration_T Semi_Final_integration_P;

/* Block signals (default storage) */
extern B_Semi_Final_integration_T Semi_Final_integration_B;

/* Continuous states (default storage) */
extern X_Semi_Final_integration_T Semi_Final_integration_X;

/* Disabled states (default storage) */
extern XDis_Semi_Final_integration_T Semi_Final_integration_XDis;

/* Block states (default storage) */
extern DW_Semi_Final_integration_T Semi_Final_integration_DW;

/* Model entry point functions */
extern void Semi_Final_integration_initialize(void);
extern void Semi_Final_integration_step(void);
extern void Semi_Final_integration_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Semi_Final_integrati_T *const Semi_Final_integration_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S41>/Data Type Duplicate' : Unused code path elimination
 * Block '<Root>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S17>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S17>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S18>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S18>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S12>/Rate Transition1' : Eliminated since input and output rates are identical
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
 * '<Root>' : 'Semi_Final_integration'
 * '<S1>'   : 'Semi_Final_integration/LED_B Ctrl'
 * '<S2>'   : 'Semi_Final_integration/LED_R Ctrl'
 * '<S3>'   : 'Semi_Final_integration/State_Ctrl'
 * '<S4>'   : 'Semi_Final_integration/Subsystem13'
 * '<S5>'   : 'Semi_Final_integration/Subsystem14'
 * '<S6>'   : 'Semi_Final_integration/Subsystem15'
 * '<S7>'   : 'Semi_Final_integration/Subsystem3'
 * '<S8>'   : 'Semi_Final_integration/Subsystem4'
 * '<S9>'   : 'Semi_Final_integration/Subsystem7'
 * '<S10>'  : 'Semi_Final_integration/Subsystem8'
 * '<S11>'  : 'Semi_Final_integration/Subsystem9'
 * '<S12>'  : 'Semi_Final_integration/light_Ctrl'
 * '<S13>'  : 'Semi_Final_integration/LED_B Ctrl/If Action Subsystem1'
 * '<S14>'  : 'Semi_Final_integration/LED_B Ctrl/If Action Subsystem3'
 * '<S15>'  : 'Semi_Final_integration/LED_R Ctrl/If Action Subsystem1'
 * '<S16>'  : 'Semi_Final_integration/LED_R Ctrl/If Action Subsystem3'
 * '<S17>'  : 'Semi_Final_integration/State_Ctrl/ADAS_state'
 * '<S18>'  : 'Semi_Final_integration/State_Ctrl/drive_mode'
 * '<S19>'  : 'Semi_Final_integration/State_Ctrl/ADAS_state/If Action Subsystem'
 * '<S20>'  : 'Semi_Final_integration/State_Ctrl/ADAS_state/If Action Subsystem1'
 * '<S21>'  : 'Semi_Final_integration/State_Ctrl/drive_mode/SW1'
 * '<S22>'  : 'Semi_Final_integration/State_Ctrl/drive_mode/SW1/If Action Subsystem'
 * '<S23>'  : 'Semi_Final_integration/State_Ctrl/drive_mode/SW1/If Action Subsystem1'
 * '<S24>'  : 'Semi_Final_integration/State_Ctrl/drive_mode/SW1/If Action Subsystem1/If Action Subsystem'
 * '<S25>'  : 'Semi_Final_integration/State_Ctrl/drive_mode/SW1/If Action Subsystem1/If Action Subsystem1'
 * '<S26>'  : 'Semi_Final_integration/Subsystem13/Discrete Derivative'
 * '<S27>'  : 'Semi_Final_integration/Subsystem3/If Action Subsystem'
 * '<S28>'  : 'Semi_Final_integration/Subsystem3/If Action Subsystem1'
 * '<S29>'  : 'Semi_Final_integration/Subsystem4/Subsystem'
 * '<S30>'  : 'Semi_Final_integration/Subsystem4/Subsystem/If Action Subsystem10'
 * '<S31>'  : 'Semi_Final_integration/Subsystem4/Subsystem/If Action Subsystem11'
 * '<S32>'  : 'Semi_Final_integration/Subsystem4/Subsystem/If Action Subsystem9'
 * '<S33>'  : 'Semi_Final_integration/Subsystem4/Subsystem/If Action Subsystem11/If Action Subsystem'
 * '<S34>'  : 'Semi_Final_integration/Subsystem4/Subsystem/If Action Subsystem11/If Action Subsystem1'
 * '<S35>'  : 'Semi_Final_integration/Subsystem4/Subsystem/If Action Subsystem11/If Action Subsystem2'
 * '<S36>'  : 'Semi_Final_integration/Subsystem4/Subsystem/If Action Subsystem11/If Action Subsystem3'
 * '<S37>'  : 'Semi_Final_integration/Subsystem4/Subsystem/If Action Subsystem11/If Action Subsystem1/If Action Subsystem'
 * '<S38>'  : 'Semi_Final_integration/Subsystem4/Subsystem/If Action Subsystem11/If Action Subsystem1/If Action Subsystem1'
 * '<S39>'  : 'Semi_Final_integration/Subsystem4/Subsystem/If Action Subsystem11/If Action Subsystem1/If Action Subsystem2'
 * '<S40>'  : 'Semi_Final_integration/Subsystem4/Subsystem/If Action Subsystem11/If Action Subsystem1/If Action Subsystem3'
 * '<S41>'  : 'Semi_Final_integration/Subsystem7/Discrete Derivative'
 * '<S42>'  : 'Semi_Final_integration/light_Ctrl/If Action Subsystem'
 * '<S43>'  : 'Semi_Final_integration/light_Ctrl/Subsystem'
 * '<S44>'  : 'Semi_Final_integration/light_Ctrl/If Action Subsystem/If Action Subsystem'
 * '<S45>'  : 'Semi_Final_integration/light_Ctrl/If Action Subsystem/If Action Subsystem1'
 * '<S46>'  : 'Semi_Final_integration/light_Ctrl/Subsystem/Subsystem'
 * '<S47>'  : 'Semi_Final_integration/light_Ctrl/Subsystem/Subsystem/If Action Subsystem'
 * '<S48>'  : 'Semi_Final_integration/light_Ctrl/Subsystem/Subsystem/If Action Subsystem1'
 * '<S49>'  : 'Semi_Final_integration/light_Ctrl/Subsystem/Subsystem/If Action Subsystem2'
 * '<S50>'  : 'Semi_Final_integration/light_Ctrl/Subsystem/Subsystem/If Action Subsystem1/If Action Subsystem'
 * '<S51>'  : 'Semi_Final_integration/light_Ctrl/Subsystem/Subsystem/If Action Subsystem1/If Action Subsystem1'
 */
#endif                                /* RTW_HEADER_Semi_Final_integration_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
