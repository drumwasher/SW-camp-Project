/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: integration_2.h
 *
 * Code generated for Simulink model 'integration_2'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Feb 14 09:46:13 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_integration_2_h_
#define RTW_HEADER_integration_2_h_
#ifndef integration_2_COMMON_INCLUDES_
#define integration_2_COMMON_INCLUDES_
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
#endif                                 /* integration_2_COMMON_INCLUDES_ */

#include "integration_2_types.h"
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
} DW_IfActionSubsystem1_integra_T;

/* Block states (default storage) for system '<S25>/If Action Subsystem3' */
typedef struct {
  int8_T IfActionSubsystem3_SubsysRanBC;/* '<S25>/If Action Subsystem3' */
} DW_IfActionSubsystem3_integra_T;

/* Block states (default storage) for system '<S43>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S43>/If Action Subsystem' */
} DW_IfActionSubsystem_integrat_T;

/* Block signals (default storage) */
typedef struct {
  int128m_T Gain2;                     /* '<S32>/Gain2' */
  int128m_T Gain2_g;                   /* '<S36>/Gain2' */
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
  int64m_T Gain1;                      /* '<S32>/Gain1' */
  int64m_T Gain1_a;                    /* '<S36>/Gain1' */
  int64m_T DiscreteTransferFcn;        /* '<S32>/Discrete Transfer Fcn' */
  int64m_T DiscreteTransferFcn_c;      /* '<S36>/Discrete Transfer Fcn' */
  real_T RateTransition;               /* '<S13>/Rate Transition' */
  real_T Delay;                        /* '<Root>/Delay' */
  real_T Delay_h;                      /* '<S3>/Delay' */
  real_T Constant;                     /* '<Root>/Constant' */
  real_T Constant2;                    /* '<Root>/Constant2' */
  real_T Constant6;                    /* '<Root>/Constant6' */
  real_T Constant3;                    /* '<Root>/Constant3' */
  real_T Merge;                        /* '<S19>/Merge' */
  real_T Merge1;                       /* '<S19>/Merge1' */
  real_T RateTransition_p;             /* '<S7>/Rate Transition' */
  real_T Gain2_gz;                     /* '<S34>/Gain2' */
  real_T Gain3;                        /* '<S34>/Gain3' */
  real_T Subtract2;                    /* '<S34>/Subtract2' */
  real_T Saturation2;                  /* '<S5>/Saturation2' */
  real_T DataTypeConversion1;          /* '<S33>/Data Type Conversion1' */
  real_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<S5>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux3_at_outport_0Inport1' */
  real_T Gain1_p;                      /* '<S34>/Gain1' */
  real_T Gain2_f;                      /* '<S38>/Gain2' */
  real_T Gain3_k;                      /* '<S38>/Gain3' */
  real_T Subtract2_p;                  /* '<S38>/Subtract2' */
  real_T Saturation1;                  /* '<S6>/Saturation1' */
  real_T DataTypeConversion1_e;        /* '<S37>/Data Type Conversion1' */
  real_T TmpSignalConversionAtTAQSigLo_j[2];
  /* '<S6>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux2_at_outport_0Inport1' */
  real_T Gain1_g;                      /* '<S38>/Gain1' */
  real_T Merge_a;                      /* '<S43>/Merge' */
  real_T Merge1_k;                     /* '<S43>/Merge1' */
  real_T light_mode;                   /* '<S41>/Chart1' */
  real_T Mod;                          /* '<S40>/Mod' */
  real_T Subtract;                     /* '<S29>/Subtract' */
  real_T Product;                      /* '<S29>/Product' */
  real_T Subtract1;                    /* '<S29>/Subtract1' */
  real_T Product1;                     /* '<S29>/Product1' */
  real_T In1;                          /* '<S20>/In1' */
  real_T drive_mode;                   /* '<S13>/Chart' */
  real_T ADAS_state;                   /* '<S14>/Chart' */
  real_T Mod_a;                        /* '<S15>/Mod' */
  real_T Mod_b;                        /* '<S18>/Mod' */
  real_T Product_p;                    /* '<S30>/Product' */
  real_T Gain1_m;                      /* '<S37>/Gain1' */
  int64m_T denAccum;
  int64m_T r10;
  int64m_T r11;
  int64m_T r12;
  int32_T DataTypeConversion1_d;       /* '<S32>/Data Type Conversion1' */
  int32_T DataTypeConversion1_a;       /* '<S36>/Data Type Conversion1' */
  uint8_T DataTypeConversion;          /* '<S33>/Data Type Conversion' */
  uint8_T DataTypeConversion_g;        /* '<S37>/Data Type Conversion' */
  boolean_T RateTransition2;           /* '<S12>/Rate Transition2' */
  boolean_T DigitalInput1;             /* '<Root>/Digital Input1' */
  boolean_T DigitalInput;              /* '<Root>/Digital Input' */
} B_integration_2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_in_e1_T obj; /* '<S36>/Encoder' */
  codertarget_arduinobase_in_e1_T obj_p;/* '<S32>/Encoder' */
  codertarget_arduinobase_inter_T obj_k;/* '<Root>/가변저항' */
  codertarget_arduinobase_inter_T obj_d;/* '<Root>/Analog Input1' */
  codertarget_arduinobase_block_T obj_i;/* '<Root>/Digital Input1' */
  codertarget_arduinobase_block_T obj_h;/* '<Root>/Digital Input' */
  codertarget_arduinobase_blo_e_T obj_a;/* '<S43>/Digital Output1' */
  codertarget_arduinobase_blo_e_T obj_b;/* '<S43>/Digital Output' */
  codertarget_arduinobase_blo_e_T obj_e;/* '<S2>/Digital Output' */
  codertarget_arduinobase_blo_e_T obj_bz;/* '<S1>/Digital Output' */
  codertarget_arduinobase_int_e_T obj_dm;/* '<S37>/PWM' */
  codertarget_arduinobase_int_e_T obj_ar;/* '<S33>/PWM' */
  codertarget_arduinobase_int_e_T obj_av;/* '<S4>/PWM2' */
  codertarget_arduinobase_int_e_T obj_l;/* '<S4>/PWM1' */
  codertarget_arduinobase_int_e_T obj_j;/* '<S4>/PWM' */
  codertarget_arduinobase_int_e_T obj_i2;/* '<Root>/PWM1' */
  real_T Delay_DSTATE;                 /* '<Root>/Delay' */
  real_T Delay_DSTATE_e;               /* '<S3>/Delay' */
  real_T Delay_DSTATE_j;               /* '<S40>/Delay' */
  real_T Delay_DSTATE_d;               /* '<S15>/Delay' */
  real_T Delay_DSTATE_p;               /* '<S18>/Delay' */
  real_T TimeStampA;                   /* '<S34>/Derivative2' */
  real_T LastUAtTimeA;                 /* '<S34>/Derivative2' */
  real_T TimeStampB;                   /* '<S34>/Derivative2' */
  real_T LastUAtTimeB;                 /* '<S34>/Derivative2' */
  real_T TimeStampA_g;                 /* '<S38>/Derivative2' */
  real_T LastUAtTimeA_p;               /* '<S38>/Derivative2' */
  real_T TimeStampB_c;                 /* '<S38>/Derivative2' */
  real_T LastUAtTimeB_n;               /* '<S38>/Derivative2' */
  real_T state_1;                      /* '<S41>/Chart1' */
  real_T state_1_e;                    /* '<S13>/Chart' */
  real_T ADAS_state;                   /* '<S13>/Chart' */
  real_T Light_state;                  /* '<S13>/Chart' */
  real_T state_2;                      /* '<S14>/Chart' */
  struct {
    void *LoggedData[2];
  } Scope4_PWORK;                      /* '<S5>/Scope4' */

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<S5>/Scope5' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<S6>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S6>/Scope2' */

  int32_T DiscreteTransferFcn_states;  /* '<S32>/Discrete Transfer Fcn' */
  int32_T DiscreteTransferFcn_states_m;/* '<S36>/Discrete Transfer Fcn' */
  int32_T UD_DSTATE;                   /* '<S35>/UD' */
  int32_T UD_DSTATE_m;                 /* '<S39>/UD' */
  int32_T clockTickCounter;            /* '<S1>/Pulse Generator' */
  int32_T clockTickCounter_l;          /* '<S43>/Pulse Generator' */
  uint32_T is_c4_integration_2;        /* '<S41>/Chart1' */
  uint32_T is_c3_integration_2;        /* '<S13>/Chart' */
  uint32_T is_c1_integration_2;        /* '<S14>/Chart' */
  int8_T If_ActiveSubsystem;           /* '<S12>/If' */
  int8_T If_ActiveSubsystem_p;         /* '<S3>/If' */
  int8_T If_ActiveSubsystem_h;         /* '<S19>/If' */
  int8_T If1_ActiveSubsystem;          /* '<S19>/If1' */
  int8_T If1_ActiveSubsystem_b;        /* '<S1>/If1' */
  int8_T If1_ActiveSubsystem_d;        /* '<S2>/If1' */
  int8_T If_ActiveSubsystem_ho;        /* '<S43>/If' */
  int8_T If_ActiveSubsystem_l;         /* '<S7>/If' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S43>/If Action Subsystem1' */
  int8_T IfActionSubsystem1_SubsysRanB_g;/* '<S45>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S45>/If Action Subsystem' */
  int8_T IfActionSubsystem_SubsysRanBC_i;/* '<S7>/If Action Subsystem' */
  int8_T IfActionSubsystem3_SubsysRanBC;/* '<S19>/If Action Subsystem3' */
  int8_T IfActionSubsystem3_SubsysRanB_g;/* '<S23>/If Action Subsystem3' */
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<S23>/If Action Subsystem2' */
  int8_T IfActionSubsystem1_SubsysRanB_e;/* '<S23>/If Action Subsystem1' */
  int8_T IfActionSubsystem2_SubsysRanB_f;/* '<S25>/If Action Subsystem2' */
  int8_T IfActionSubsystem1_SubsysRanB_i;/* '<S25>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC_n;/* '<S25>/If Action Subsystem' */
  int8_T IfActionSubsystem2_SubsysRanB_p;/* '<S19>/If Action Subsystem2' */
  int8_T IfActionSubsystem_SubsysRanBC_l;/* '<S19>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanB_c;/* '<S19>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanB_ng;/* '<S12>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanB_k;/* '<S12>/If Action Subsystem1' */
  int8_T IfActionSubsystem3_SubsysRanB_d;/* '<S1>/If Action Subsystem3' */
  int8_T IfActionSubsystem1_SubsysRanB_h;/* '<S1>/If Action Subsystem1' */
  int8_T SW1_SubsysRanBC;              /* '<S13>/SW1' */
  uint8_T is_active_c4_integration_2;  /* '<S41>/Chart1' */
  uint8_T is_active_c3_integration_2;  /* '<S13>/Chart' */
  uint8_T is_active_c1_integration_2;  /* '<S14>/Chart' */
  DW_IfActionSubsystem_integrat_T IfActionSubsystem2_p;/* '<S43>/If Action Subsystem2' */
  DW_IfActionSubsystem_integrat_T IfActionSubsystem_c;/* '<S43>/If Action Subsystem' */
  DW_IfActionSubsystem3_integra_T IfActionSubsystem_n;/* '<S23>/If Action Subsystem' */
  DW_IfActionSubsystem3_integra_T IfActionSubsystem3_i;/* '<S25>/If Action Subsystem3' */
  DW_IfActionSubsystem1_integra_T IfActionSubsystem3_c;/* '<S2>/If Action Subsystem3' */
  DW_IfActionSubsystem1_integra_T IfActionSubsystem1_e;/* '<S2>/If Action Subsystem1' */
} DW_integration_2_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S34>/Integrator2' */
  real_T Integrator2_CSTATE_f;         /* '<S38>/Integrator2' */
} X_integration_2_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S34>/Integrator2' */
  real_T Integrator2_CSTATE_f;         /* '<S38>/Integrator2' */
} XDot_integration_2_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator2_CSTATE;        /* '<S34>/Integrator2' */
  boolean_T Integrator2_CSTATE_f;      /* '<S38>/Integrator2' */
} XDis_integration_2_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters for system: '<S2>/If Action Subsystem1' */
struct P_IfActionSubsystem1_integrat_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S10>/Constant'
                                        */
};

/* Parameters for system: '<S25>/If Action Subsystem3' */
struct P_IfActionSubsystem3_integrat_T_ {
  real_T Constant_Value;               /* Expression: 360
                                        * Referenced by: '<S31>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 360
                                        * Referenced by: '<S31>/Constant1'
                                        */
};

/* Parameters (default storage) */
struct P_integration_2_T_ {
  real_T KD;                           /* Variable: KD
                                        * Referenced by:
                                        *   '<S34>/Gain3'
                                        *   '<S38>/Gain3'
                                        */
  real_T KI;                           /* Variable: KI
                                        * Referenced by:
                                        *   '<S34>/Gain1'
                                        *   '<S38>/Gain1'
                                        */
  real_T KP;                           /* Variable: KP
                                        * Referenced by:
                                        *   '<S34>/Gain2'
                                        *   '<S38>/Gain2'
                                        */
  real_T Vlim;                         /* Variable: Vlim
                                        * Referenced by:
                                        *   '<S33>/Gain1'
                                        *   '<S37>/Gain1'
                                        */
  real_T b;                            /* Variable: b
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T default1;                     /* Variable: default1
                                        * Referenced by:
                                        *   '<S28>/Constant'
                                        *   '<S28>/Constant3'
                                        *   '<S29>/Constant'
                                        *   '<S30>/Constant'
                                        */
  real_T f;                            /* Variable: f
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T l;                            /* Variable: l
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T r;                            /* Variable: r
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T steering;                     /* Variable: steering
                                        * Referenced by:
                                        *   '<S28>/Constant1'
                                        *   '<S29>/Constant1'
                                        *   '<S30>/Constant1'
                                        */
  int32_T den_Gd[2];                   /* Variable: den_Gd
                                        * Referenced by:
                                        *   '<S32>/Discrete Transfer Fcn'
                                        *   '<S36>/Discrete Transfer Fcn'
                                        */
  int32_T encoder_scale;               /* Variable: encoder_scale
                                        * Referenced by:
                                        *   '<S32>/Gain1'
                                        *   '<S36>/Gain1'
                                        */
  int32_T num_Gd[2];                   /* Variable: num_Gd
                                        * Referenced by:
                                        *   '<S32>/Discrete Transfer Fcn'
                                        *   '<S36>/Discrete Transfer Fcn'
                                        */
  int32_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S35>/UD'
                               */
  int32_T DiscreteDerivative_ICPrevScal_g;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_g
                               * Referenced by: '<S39>/UD'
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
  real_T sw2_Y0;                       /* Computed Parameter: sw2_Y0
                                        * Referenced by: '<S15>/sw2'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Delay_InitialCondition_f;     /* Expression: 0
                                        * Referenced by: '<S15>/Delay'
                                        */
  real_T Constant1_Value_g;            /* Expression: 2
                                        * Referenced by: '<S15>/Constant1'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T Constant1_Value_n;            /* Expression: 0
                                        * Referenced by: '<S21>/Constant1'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S20>/Out1'
                                        */
  real_T Constant_Value_l;             /* Expression: 360
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S22>/Constant4'
                                        */
  real_T Constant1_Value_o;            /* Expression: 100
                                        * Referenced by: '<S22>/Constant1'
                                        */
  real_T Constant5_Value;              /* Expression: 6.4
                                        * Referenced by: '<S22>/Constant5'
                                        */
  real_T Constant2_Value;              /* Expression: 128
                                        * Referenced by: '<S22>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 360
                                        * Referenced by: '<S22>/Constant3'
                                        */
  real_T Constant8_Value;              /* Expression: 1
                                        * Referenced by: '<S22>/Constant8'
                                        */
  real_T Constant6_Value;              /* Expression: 100
                                        * Referenced by: '<S22>/Constant6'
                                        */
  real_T Constant9_Value;              /* Expression: 6.4
                                        * Referenced by: '<S22>/Constant9'
                                        */
  real_T Constant7_Value;              /* Expression: 128
                                        * Referenced by: '<S22>/Constant7'
                                        */
  real_T Constant2_Value_i;            /* Expression: 1
                                        * Referenced by: '<S28>/Constant2'
                                        */
  real_T Constant4_Value_f;            /* Expression: 10
                                        * Referenced by: '<S29>/Constant4'
                                        */
  real_T Constant2_Value_b;            /* Expression: 1
                                        * Referenced by: '<S29>/Constant2'
                                        */
  real_T Constant2_Value_im;           /* Expression: 1
                                        * Referenced by: '<S30>/Constant2'
                                        */
  real_T Constant4_Value_p;            /* Expression: 10
                                        * Referenced by: '<S30>/Constant4'
                                        */
  real_T Gain_Gain;                    /* Expression: 1.2
                                        * Referenced by: '<S27>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1.2
                                        * Referenced by: '<S27>/Gain1'
                                        */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S32>/Encoder'
                                        */
  real_T Encoder_SampleTime_e;         /* Expression: -1
                                        * Referenced by: '<S36>/Encoder'
                                        */
  real_T Out1_Y0_c;                    /* Computed Parameter: Out1_Y0_c
                                        * Referenced by: '<S40>/Out1'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S40>/Constant'
                                        */
  real_T Delay_InitialCondition_p;     /* Expression: 0.0
                                        * Referenced by: '<S40>/Delay'
                                        */
  real_T Constant1_Value_c;            /* Expression: 3
                                        * Referenced by: '<S40>/Constant1'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S45>/Constant'
                                        */
  real_T Constant1_Value_f;            /* Expression: 0
                                        * Referenced by: '<S45>/Constant1'
                                        */
  real_T _SampleTime;                  /* Expression: -1
                                        * Referenced by: '<Root>/가변저항'
                                        */
  real_T Delay_InitialCondition_fz;    /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T Delay_InitialCondition_h;     /* Expression: 0.0
                                        * Referenced by: '<S3>/Delay'
                                        */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S19>/Merge'
                                       */
  real_T Merge1_InitialOutput;       /* Computed Parameter: Merge1_InitialOutput
                                      * Referenced by: '<S19>/Merge1'
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
  real_T Constant_Value_hx;            /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant_Value_kp;            /* Expression: 0
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S34>/Integrator2'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 12
                                        * Referenced by: '<S5>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S5>/Saturation2'
                                        */
  real_T Integrator2_IC_f;             /* Expression: 0
                                        * Referenced by: '<S38>/Integrator2'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 12
                                        * Referenced by: '<S6>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S6>/Saturation1'
                                        */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S43>/Constant'
                                        */
  real_T PulseGenerator_Amp_a;         /* Expression: 1
                                        * Referenced by: '<S43>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_p; /* Computed Parameter: PulseGenerator_Period_p
                                   * Referenced by: '<S43>/Pulse Generator'
                                   */
  real_T PulseGenerator_Duty_n;     /* Computed Parameter: PulseGenerator_Duty_n
                                     * Referenced by: '<S43>/Pulse Generator'
                                     */
  real_T PulseGenerator_PhaseDelay_f;  /* Expression: 0
                                        * Referenced by: '<S43>/Pulse Generator'
                                        */
  real_T Constant1_Value_m;            /* Expression: 0
                                        * Referenced by: '<S43>/Constant1'
                                        */
  real_T Merge_InitialOutput_m;     /* Computed Parameter: Merge_InitialOutput_m
                                     * Referenced by: '<S43>/Merge'
                                     */
  real_T Merge1_InitialOutput_g;   /* Computed Parameter: Merge1_InitialOutput_g
                                    * Referenced by: '<S43>/Merge1'
                                    */
  int64m_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S32>/Gain2'
                                        */
  int64m_T Gain2_Gain_d;               /* Computed Parameter: Gain2_Gain_d
                                        * Referenced by: '<S36>/Gain2'
                                        */
  int32_T DiscreteTransferFcn_InitialStat;
                          /* Computed Parameter: DiscreteTransferFcn_InitialStat
                           * Referenced by: '<S32>/Discrete Transfer Fcn'
                           */
  int32_T DiscreteTransferFcn_InitialSt_i;
                          /* Computed Parameter: DiscreteTransferFcn_InitialSt_i
                           * Referenced by: '<S36>/Discrete Transfer Fcn'
                           */
  uint16_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S4>/Gain4'
                                        */
  uint16_T Gain_Gain_e;                /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S43>/Gain'
                                        */
  P_IfActionSubsystem3_integrat_T IfActionSubsystem_n;/* '<S23>/If Action Subsystem' */
  P_IfActionSubsystem3_integrat_T IfActionSubsystem3_i;/* '<S25>/If Action Subsystem3' */
  P_IfActionSubsystem1_integrat_T IfActionSubsystem3_c;/* '<S2>/If Action Subsystem3' */
  P_IfActionSubsystem1_integrat_T IfActionSubsystem1_e;/* '<S2>/If Action Subsystem1' */
};

/* Real-time Model Data Structure */
struct tag_RTM_integration_2_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_integration_2_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_integration_2_T *contStateDisabled;
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
extern P_integration_2_T integration_2_P;

/* Block signals (default storage) */
extern B_integration_2_T integration_2_B;

/* Continuous states (default storage) */
extern X_integration_2_T integration_2_X;

/* Disabled states (default storage) */
extern XDis_integration_2_T integration_2_XDis;

/* Block states (default storage) */
extern DW_integration_2_T integration_2_DW;

/* External function called from main */
extern void integration_2_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void integration_2_initialize(void);
extern void integration_2_step0(void);
extern void integration_2_step2(void);
extern void integration_2_step3(void);
extern void integration_2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_integration_2_T *const integration_2_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S35>/Data Type Duplicate' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/Rate Transition1' : Eliminated since input and output rates are identical
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
 * '<Root>' : 'integration_2'
 * '<S1>'   : 'integration_2/LED_B Ctrl'
 * '<S2>'   : 'integration_2/LED_R Ctrl'
 * '<S3>'   : 'integration_2/State_Ctrl'
 * '<S4>'   : 'integration_2/Subsystem'
 * '<S5>'   : 'integration_2/Subsystem1'
 * '<S6>'   : 'integration_2/Subsystem2'
 * '<S7>'   : 'integration_2/light_Ctrl'
 * '<S8>'   : 'integration_2/LED_B Ctrl/If Action Subsystem1'
 * '<S9>'   : 'integration_2/LED_B Ctrl/If Action Subsystem3'
 * '<S10>'  : 'integration_2/LED_R Ctrl/If Action Subsystem1'
 * '<S11>'  : 'integration_2/LED_R Ctrl/If Action Subsystem3'
 * '<S12>'  : 'integration_2/State_Ctrl/ADAS_state'
 * '<S13>'  : 'integration_2/State_Ctrl/drive_mode'
 * '<S14>'  : 'integration_2/State_Ctrl/ADAS_state/If Action Subsystem'
 * '<S15>'  : 'integration_2/State_Ctrl/ADAS_state/If Action Subsystem1'
 * '<S16>'  : 'integration_2/State_Ctrl/ADAS_state/If Action Subsystem/Chart'
 * '<S17>'  : 'integration_2/State_Ctrl/drive_mode/Chart'
 * '<S18>'  : 'integration_2/State_Ctrl/drive_mode/SW1'
 * '<S19>'  : 'integration_2/Subsystem/Subsystem'
 * '<S20>'  : 'integration_2/Subsystem/Subsystem/If Action Subsystem'
 * '<S21>'  : 'integration_2/Subsystem/Subsystem/If Action Subsystem1'
 * '<S22>'  : 'integration_2/Subsystem/Subsystem/If Action Subsystem2'
 * '<S23>'  : 'integration_2/Subsystem/Subsystem/If Action Subsystem3'
 * '<S24>'  : 'integration_2/Subsystem/Subsystem/If Action Subsystem3/If Action Subsystem'
 * '<S25>'  : 'integration_2/Subsystem/Subsystem/If Action Subsystem3/If Action Subsystem1'
 * '<S26>'  : 'integration_2/Subsystem/Subsystem/If Action Subsystem3/If Action Subsystem2'
 * '<S27>'  : 'integration_2/Subsystem/Subsystem/If Action Subsystem3/If Action Subsystem3'
 * '<S28>'  : 'integration_2/Subsystem/Subsystem/If Action Subsystem3/If Action Subsystem1/If Action Subsystem'
 * '<S29>'  : 'integration_2/Subsystem/Subsystem/If Action Subsystem3/If Action Subsystem1/If Action Subsystem1'
 * '<S30>'  : 'integration_2/Subsystem/Subsystem/If Action Subsystem3/If Action Subsystem1/If Action Subsystem2'
 * '<S31>'  : 'integration_2/Subsystem/Subsystem/If Action Subsystem3/If Action Subsystem1/If Action Subsystem3'
 * '<S32>'  : 'integration_2/Subsystem1/Subsystem7'
 * '<S33>'  : 'integration_2/Subsystem1/Subsystem8'
 * '<S34>'  : 'integration_2/Subsystem1/Subsystem9'
 * '<S35>'  : 'integration_2/Subsystem1/Subsystem7/Discrete Derivative'
 * '<S36>'  : 'integration_2/Subsystem2/Subsystem3'
 * '<S37>'  : 'integration_2/Subsystem2/Subsystem4'
 * '<S38>'  : 'integration_2/Subsystem2/Subsystem5'
 * '<S39>'  : 'integration_2/Subsystem2/Subsystem3/Discrete Derivative'
 * '<S40>'  : 'integration_2/light_Ctrl/If Action Subsystem'
 * '<S41>'  : 'integration_2/light_Ctrl/Subsystem'
 * '<S42>'  : 'integration_2/light_Ctrl/Subsystem/Chart1'
 * '<S43>'  : 'integration_2/light_Ctrl/Subsystem/Subsystem'
 * '<S44>'  : 'integration_2/light_Ctrl/Subsystem/Subsystem/If Action Subsystem'
 * '<S45>'  : 'integration_2/light_Ctrl/Subsystem/Subsystem/If Action Subsystem1'
 * '<S46>'  : 'integration_2/light_Ctrl/Subsystem/Subsystem/If Action Subsystem2'
 * '<S47>'  : 'integration_2/light_Ctrl/Subsystem/Subsystem/If Action Subsystem1/If Action Subsystem'
 * '<S48>'  : 'integration_2/light_Ctrl/Subsystem/Subsystem/If Action Subsystem1/If Action Subsystem1'
 */
#endif                                 /* RTW_HEADER_integration_2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
