/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: integration_2.h
 *
 * Code generated for Simulink model 'integration_2'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Feb 14 09:58:12 2024
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
#include "MW_Ultrasonic.h"
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

/* Block states (default storage) for system '<S4>/If Action Subsystem1' */
typedef struct {
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S4>/If Action Subsystem1' */
} DW_IfActionSubsystem1_integra_T;

/* Block states (default storage) for system '<S21>/If Action Subsystem1' */
typedef struct {
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S21>/If Action Subsystem1' */
} DW_IfActionSubsystem1_integ_e_T;

/* Block states (default storage) for system '<S45>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S45>/If Action Subsystem' */
} DW_IfActionSubsystem_integrat_T;

/* Block signals (default storage) */
typedef struct {
  int128m_T Gain2;                     /* '<S34>/Gain2' */
  int128m_T Gain2_g;                   /* '<S38>/Gain2' */
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
  int64m_T Gain1;                      /* '<S34>/Gain1' */
  int64m_T Gain1_a;                    /* '<S38>/Gain1' */
  int64m_T DiscreteTransferFcn;        /* '<S34>/Discrete Transfer Fcn' */
  int64m_T DiscreteTransferFcn_c;      /* '<S38>/Discrete Transfer Fcn' */
  real_T RateTransition;               /* '<S15>/Rate Transition' */
  real_T Delay;                        /* '<Root>/Delay' */
  real_T Delay_h;                      /* '<S5>/Delay' */
  real_T Constant2;                    /* '<Root>/Constant2' */
  real_T Constant6;                    /* '<Root>/Constant6' */
  real_T Constant3;                    /* '<Root>/Constant3' */
  real_T Merge3;                       /* '<Root>/Merge3' */
  real_T Merge1;                       /* '<S21>/Merge1' */
  real_T Gain2_gz;                     /* '<S36>/Gain2' */
  real_T Gain3;                        /* '<S36>/Gain3' */
  real_T Subtract2;                    /* '<S36>/Subtract2' */
  real_T Saturation2;                  /* '<S7>/Saturation2' */
  real_T DataTypeConversion1;          /* '<S35>/Data Type Conversion1' */
  real_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<S7>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux3_at_outport_0Inport1' */
  real_T Merge;                        /* '<S21>/Merge' */
  real_T Gain2_f;                      /* '<S40>/Gain2' */
  real_T Gain3_k;                      /* '<S40>/Gain3' */
  real_T Subtract2_p;                  /* '<S40>/Subtract2' */
  real_T Saturation1;                  /* '<S8>/Saturation1' */
  real_T DataTypeConversion1_e;        /* '<S39>/Data Type Conversion1' */
  real_T TmpSignalConversionAtTAQSigLo_j[2];
  /* '<S8>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux2_at_outport_0Inport1' */
  real_T Gain1_g;                      /* '<S40>/Gain1' */
  real_T Gain1_p;                      /* '<S36>/Gain1' */
  real_T RateTransition_p;             /* '<S9>/Rate Transition' */
  real_T Merge_a;                      /* '<S45>/Merge' */
  real_T Merge1_k;                     /* '<S45>/Merge1' */
  real_T light_mode;                   /* '<S43>/Chart1' */
  real_T Mod;                          /* '<S42>/Mod' */
  real_T Merge_b;                      /* '<S25>/Merge' */
  real_T Merge1_m;                     /* '<S25>/Merge1' */
  real_T Subtract;                     /* '<S31>/Subtract' */
  real_T Product;                      /* '<S31>/Product' */
  real_T Subtract1;                    /* '<S31>/Subtract1' */
  real_T Product1;                     /* '<S31>/Product1' */
  real_T In1;                          /* '<S22>/In1' */
  real_T drive_mode;                   /* '<S15>/Chart' */
  real_T ADAS_state;                   /* '<S16>/Chart' */
  real_T Mod_a;                        /* '<S17>/Mod' */
  real_T Mod_b;                        /* '<S20>/Mod' */
  real_T Derivative2;                  /* '<S40>/Derivative2' */
  real_T Add5;                         /* '<S7>/Add5' */
  real_T Product_p;                    /* '<S32>/Product' */
  real_T Gain1_m;                      /* '<S39>/Gain1' */
  real_T PulseGenerator_e;             /* '<S3>/Pulse Generator' */
  int64m_T denAccum;
  int64m_T r10;
  int64m_T r11;
  int64m_T r12;
  int32_T DataTypeConversion1_d;       /* '<S34>/Data Type Conversion1' */
  int32_T DataTypeConversion1_a;       /* '<S38>/Data Type Conversion1' */
  uint8_T DataTypeConversion;          /* '<S35>/Data Type Conversion' */
  uint8_T DataTypeConversion_g;        /* '<S39>/Data Type Conversion' */
  boolean_T RateTransition2;           /* '<S14>/Rate Transition2' */
  boolean_T DigitalInput1;             /* '<Root>/Digital Input1' */
  boolean_T DigitalInput;              /* '<Root>/Digital Input' */
} B_integration_2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_in_e1_T obj; /* '<S38>/Encoder' */
  codertarget_arduinobase_in_e1_T obj_p;/* '<S34>/Encoder' */
  codertarget_arduinobase_inter_T obj_k;/* '<Root>/가변저항' */
  codertarget_arduinobase_inter_T obj_d;/* '<Root>/Analog Input1' */
  codertarget_arduinobase_block_T obj_i;/* '<Root>/Digital Input1' */
  codertarget_arduinobase_block_T obj_h;/* '<Root>/Digital Input' */
  codertarget_arduinobase_blo_e_T obj_a;/* '<S45>/Digital Output1' */
  codertarget_arduinobase_blo_e_T obj_b;/* '<S45>/Digital Output' */
  codertarget_arduinobase_blo_e_T obj_e;/* '<S4>/Digital Output' */
  codertarget_arduinobase_blo_e_T obj_bz;/* '<S3>/Digital Output' */
  codertarget_arduinobase_int_e_T obj_dm;/* '<S39>/PWM' */
  codertarget_arduinobase_int_e_T obj_ar;/* '<S35>/PWM' */
  codertarget_arduinobase_int_e_T obj_av;/* '<S6>/PWM2' */
  codertarget_arduinobase_int_e_T obj_l;/* '<S6>/PWM1' */
  codertarget_arduinobase_int_e_T obj_j;/* '<S6>/PWM' */
  codertarget_arduinobase_int_e_T obj_i2;/* '<Root>/PWM1' */
  real_T Delay_DSTATE;                 /* '<Root>/Delay' */
  real_T Delay_DSTATE_e;               /* '<S5>/Delay' */
  real_T Delay1_DSTATE;                /* '<Root>/Delay1' */
  real_T Delay_DSTATE_j;               /* '<S42>/Delay' */
  real_T Delay_DSTATE_d;               /* '<S17>/Delay' */
  real_T Delay_DSTATE_p;               /* '<S20>/Delay' */
  real_T TimeStampA;                   /* '<S36>/Derivative2' */
  real_T LastUAtTimeA;                 /* '<S36>/Derivative2' */
  real_T TimeStampB;                   /* '<S36>/Derivative2' */
  real_T LastUAtTimeB;                 /* '<S36>/Derivative2' */
  real_T TimeStampA_g;                 /* '<S40>/Derivative2' */
  real_T LastUAtTimeA_p;               /* '<S40>/Derivative2' */
  real_T TimeStampB_c;                 /* '<S40>/Derivative2' */
  real_T LastUAtTimeB_n;               /* '<S40>/Derivative2' */
  real_T state_1;                      /* '<S43>/Chart1' */
  real_T state_1_e;                    /* '<S15>/Chart' */
  real_T ADAS_state;                   /* '<S15>/Chart' */
  real_T Light_state;                  /* '<S15>/Chart' */
  real_T state_2;                      /* '<S16>/Chart' */
  codertarget_arduinobase_i_e1m_T obj_lf;/* '<Root>/전방 초음파1' */
  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<S7>/Scope5' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S8>/Scope2' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<S8>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope4_PWORK;                      /* '<S7>/Scope4' */

  int32_T DiscreteTransferFcn_states;  /* '<S34>/Discrete Transfer Fcn' */
  int32_T DiscreteTransferFcn_states_m;/* '<S38>/Discrete Transfer Fcn' */
  int32_T UD_DSTATE;                   /* '<S37>/UD' */
  int32_T UD_DSTATE_m;                 /* '<S41>/UD' */
  int32_T clockTickCounter;            /* '<S3>/Pulse Generator' */
  int32_T clockTickCounter_l;          /* '<S45>/Pulse Generator' */
  uint32_T is_c4_integration_2;        /* '<S43>/Chart1' */
  uint32_T is_c3_integration_2;        /* '<S15>/Chart' */
  uint32_T is_c1_integration_2;        /* '<S16>/Chart' */
  int8_T If_ActiveSubsystem;           /* '<S14>/If' */
  int8_T If_ActiveSubsystem_p;         /* '<S5>/If' */
  int8_T If_ActiveSubsystem_h;         /* '<S21>/If' */
  int8_T If3_ActiveSubsystem;          /* '<Root>/If3' */
  int8_T If1_ActiveSubsystem;          /* '<S21>/If1' */
  int8_T If1_ActiveSubsystem_b;        /* '<S3>/If1' */
  int8_T If_ActiveSubsystem_l;         /* '<S9>/If' */
  int8_T If_ActiveSubsystem_ho;        /* '<S45>/If' */
  int8_T If1_ActiveSubsystem_d;        /* '<S4>/If1' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S45>/If Action Subsystem1' */
  int8_T IfActionSubsystem1_SubsysRanB_g;/* '<S47>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S47>/If Action Subsystem' */
  int8_T IfActionSubsystem_SubsysRanBC_i;/* '<S9>/If Action Subsystem' */
  int8_T IfActionSubsystem3_SubsysRanBC;/* '<S21>/If Action Subsystem3' */
  int8_T If_ActiveSubsystem_f;         /* '<S25>/If' */
  int8_T IfActionSubsystem3_SubsysRanB_g;/* '<S25>/If Action Subsystem3' */
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<S25>/If Action Subsystem2' */
  int8_T IfActionSubsystem1_SubsysRanB_e;/* '<S25>/If Action Subsystem1' */
  int8_T IfActionSubsystem3_SubsysRanB_d;/* '<S27>/If Action Subsystem3' */
  int8_T IfActionSubsystem2_SubsysRanB_f;/* '<S27>/If Action Subsystem2' */
  int8_T IfActionSubsystem1_SubsysRanB_i;/* '<S27>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC_n;/* '<S27>/If Action Subsystem' */
  int8_T IfActionSubsystem2_SubsysRanB_p;/* '<S21>/If Action Subsystem2' */
  int8_T IfActionSubsystem_SubsysRanBC_l;/* '<S21>/If Action Subsystem' */
  int8_T IfActionSubsystem_SubsysRanB_ng;/* '<S14>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanB_k;/* '<S14>/If Action Subsystem1' */
  int8_T IfActionSubsystem3_SubsysRan_df;/* '<S3>/If Action Subsystem3' */
  int8_T IfActionSubsystem1_SubsysRanB_h;/* '<S3>/If Action Subsystem1' */
  int8_T IfActionSubsystem7_SubsysRanBC;/* '<Root>/If Action Subsystem7' */
  int8_T IfActionSubsystem6_SubsysRanBC;/* '<Root>/If Action Subsystem6' */
  int8_T SW1_SubsysRanBC;              /* '<S15>/SW1' */
  uint8_T is_active_c4_integration_2;  /* '<S43>/Chart1' */
  uint8_T is_active_c3_integration_2;  /* '<S15>/Chart' */
  uint8_T is_active_c1_integration_2;  /* '<S16>/Chart' */
  DW_IfActionSubsystem_integrat_T IfActionSubsystem2_p;/* '<S45>/If Action Subsystem2' */
  DW_IfActionSubsystem_integrat_T IfActionSubsystem_c;/* '<S45>/If Action Subsystem' */
  DW_IfActionSubsystem1_integ_e_T IfActionSubsystem_n;/* '<S25>/If Action Subsystem' */
  DW_IfActionSubsystem1_integ_e_T IfActionSubsystem1_l;/* '<S21>/If Action Subsystem1' */
  DW_IfActionSubsystem1_integra_T IfActionSubsystem3_c;/* '<S4>/If Action Subsystem3' */
  DW_IfActionSubsystem1_integra_T IfActionSubsystem1_e;/* '<S4>/If Action Subsystem1' */
} DW_integration_2_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S36>/Integrator2' */
  real_T Integrator2_CSTATE_f;         /* '<S40>/Integrator2' */
} X_integration_2_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S36>/Integrator2' */
  real_T Integrator2_CSTATE_f;         /* '<S40>/Integrator2' */
} XDot_integration_2_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator2_CSTATE;        /* '<S36>/Integrator2' */
  boolean_T Integrator2_CSTATE_f;      /* '<S40>/Integrator2' */
} XDis_integration_2_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters for system: '<S4>/If Action Subsystem1' */
struct P_IfActionSubsystem1_integrat_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S12>/Constant'
                                        */
};

/* Parameters for system: '<S21>/If Action Subsystem1' */
struct P_IfActionSubsystem1_integr_d_T_ {
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S23>/Constant1'
                                        */
};

/* Parameters (default storage) */
struct P_integration_2_T_ {
  real_T KD;                           /* Variable: KD
                                        * Referenced by:
                                        *   '<S36>/Gain3'
                                        *   '<S40>/Gain3'
                                        */
  real_T KI;                           /* Variable: KI
                                        * Referenced by:
                                        *   '<S36>/Gain1'
                                        *   '<S40>/Gain1'
                                        */
  real_T KP;                           /* Variable: KP
                                        * Referenced by:
                                        *   '<S36>/Gain2'
                                        *   '<S40>/Gain2'
                                        */
  real_T Vlim;                         /* Variable: Vlim
                                        * Referenced by:
                                        *   '<S35>/Gain1'
                                        *   '<S39>/Gain1'
                                        */
  real_T b;                            /* Variable: b
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T default1;                     /* Variable: default1
                                        * Referenced by:
                                        *   '<S30>/Constant'
                                        *   '<S30>/Constant3'
                                        *   '<S31>/Constant'
                                        *   '<S32>/Constant'
                                        */
  real_T l;                            /* Variable: l
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T r;                            /* Variable: r
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T steering;                     /* Variable: steering
                                        * Referenced by:
                                        *   '<S30>/Constant1'
                                        *   '<S31>/Constant1'
                                        *   '<S32>/Constant1'
                                        */
  int32_T den_Gd[2];                   /* Variable: den_Gd
                                        * Referenced by:
                                        *   '<S34>/Discrete Transfer Fcn'
                                        *   '<S38>/Discrete Transfer Fcn'
                                        */
  int32_T encoder_scale;               /* Variable: encoder_scale
                                        * Referenced by:
                                        *   '<S34>/Gain1'
                                        *   '<S38>/Gain1'
                                        */
  int32_T num_Gd[2];                   /* Variable: num_Gd
                                        * Referenced by:
                                        *   '<S34>/Discrete Transfer Fcn'
                                        *   '<S38>/Discrete Transfer Fcn'
                                        */
  int32_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S37>/UD'
                               */
  int32_T DiscreteDerivative_ICPrevScal_g;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_g
                               * Referenced by: '<S41>/UD'
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
                                        * Referenced by: '<S20>/Output'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S20>/Delay'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S20>/Constant1'
                                        */
  real_T sw2_Y0;                       /* Computed Parameter: sw2_Y0
                                        * Referenced by: '<S17>/sw2'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T Delay_InitialCondition_f;     /* Expression: 0
                                        * Referenced by: '<S17>/Delay'
                                        */
  real_T Constant1_Value_g;            /* Expression: 2
                                        * Referenced by: '<S17>/Constant1'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S22>/Out1'
                                        */
  real_T Constant_Value_l;             /* Expression: 360
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S24>/Constant4'
                                        */
  real_T Constant1_Value_o;            /* Expression: 100
                                        * Referenced by: '<S24>/Constant1'
                                        */
  real_T Constant5_Value;              /* Expression: 6.4
                                        * Referenced by: '<S24>/Constant5'
                                        */
  real_T Constant2_Value;              /* Expression: 128
                                        * Referenced by: '<S24>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 360
                                        * Referenced by: '<S24>/Constant3'
                                        */
  real_T Constant8_Value;              /* Expression: 1
                                        * Referenced by: '<S24>/Constant8'
                                        */
  real_T Constant6_Value;              /* Expression: 100
                                        * Referenced by: '<S24>/Constant6'
                                        */
  real_T Constant9_Value;              /* Expression: 6.4
                                        * Referenced by: '<S24>/Constant9'
                                        */
  real_T Constant7_Value;              /* Expression: 128
                                        * Referenced by: '<S24>/Constant7'
                                        */
  real_T Constant2_Value_i;            /* Expression: 1
                                        * Referenced by: '<S30>/Constant2'
                                        */
  real_T Constant4_Value_f;            /* Expression: 10
                                        * Referenced by: '<S31>/Constant4'
                                        */
  real_T Constant2_Value_b;            /* Expression: 1
                                        * Referenced by: '<S31>/Constant2'
                                        */
  real_T Constant2_Value_im;           /* Expression: 1
                                        * Referenced by: '<S32>/Constant2'
                                        */
  real_T Constant4_Value_p;            /* Expression: 10
                                        * Referenced by: '<S32>/Constant4'
                                        */
  real_T Constant_Value_f;             /* Expression: 360
                                        * Referenced by: '<S33>/Constant'
                                        */
  real_T Constant1_Value_j;            /* Expression: 360
                                        * Referenced by: '<S33>/Constant1'
                                        */
  real_T Gain_Gain;                    /* Expression: 1.2
                                        * Referenced by: '<S29>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1.2
                                        * Referenced by: '<S29>/Gain1'
                                        */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S34>/Encoder'
                                        */
  real_T Encoder_SampleTime_e;         /* Expression: -1
                                        * Referenced by: '<S38>/Encoder'
                                        */
  real_T Out1_Y0_c;                    /* Computed Parameter: Out1_Y0_c
                                        * Referenced by: '<S42>/Out1'
                                        */
  real_T Constant_Value_fm;            /* Expression: 1
                                        * Referenced by: '<S42>/Constant'
                                        */
  real_T Delay_InitialCondition_p;     /* Expression: 0.0
                                        * Referenced by: '<S42>/Delay'
                                        */
  real_T Constant1_Value_c;            /* Expression: 3
                                        * Referenced by: '<S42>/Constant1'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S47>/Constant'
                                        */
  real_T Constant1_Value_f;            /* Expression: 0
                                        * Referenced by: '<S47>/Constant1'
                                        */
  real_T _SampleTime;                  /* Expression: -1
                                        * Referenced by: '<Root>/가변저항'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S36>/Integrator2'
                                        */
  real_T Delay_InitialCondition_fz;    /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T Delay_InitialCondition_h;     /* Expression: 0.0
                                        * Referenced by: '<S5>/Delay'
                                        */
  real_T Gain2_Gain;                   /* Expression: 100
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 30
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay1'
                                        */
  real_T Merge1_InitialOutput;       /* Computed Parameter: Merge1_InitialOutput
                                      * Referenced by: '<S21>/Merge1'
                                      */
  real_T Saturation2_UpperSat;         /* Expression: 12
                                        * Referenced by: '<S7>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S7>/Saturation2'
                                        */
  real_T Integrator2_IC_f;             /* Expression: 0
                                        * Referenced by: '<S40>/Integrator2'
                                        */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S21>/Merge'
                                       */
  real_T Saturation1_UpperSat;         /* Expression: 12
                                        * Referenced by: '<S8>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S8>/Saturation1'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S3>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<S3>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<S3>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S3>/Pulse Generator'
                                        */
  real_T Constant_Value_hx;            /* Expression: 1
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S45>/Constant'
                                        */
  real_T PulseGenerator_Amp_a;         /* Expression: 1
                                        * Referenced by: '<S45>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_p; /* Computed Parameter: PulseGenerator_Period_p
                                   * Referenced by: '<S45>/Pulse Generator'
                                   */
  real_T PulseGenerator_Duty_n;     /* Computed Parameter: PulseGenerator_Duty_n
                                     * Referenced by: '<S45>/Pulse Generator'
                                     */
  real_T PulseGenerator_PhaseDelay_f;  /* Expression: 0
                                        * Referenced by: '<S45>/Pulse Generator'
                                        */
  real_T Constant1_Value_m;            /* Expression: 0
                                        * Referenced by: '<S45>/Constant1'
                                        */
  real_T Merge_InitialOutput_m;     /* Computed Parameter: Merge_InitialOutput_m
                                     * Referenced by: '<S45>/Merge'
                                     */
  real_T Merge1_InitialOutput_g;   /* Computed Parameter: Merge1_InitialOutput_g
                                    * Referenced by: '<S45>/Merge1'
                                    */
  real_T Constant_Value_kp;            /* Expression: 0
                                        * Referenced by: '<S6>/Constant'
                                        */
  int64m_T Gain2_Gain_n;               /* Computed Parameter: Gain2_Gain_n
                                        * Referenced by: '<S34>/Gain2'
                                        */
  int64m_T Gain2_Gain_d;               /* Computed Parameter: Gain2_Gain_d
                                        * Referenced by: '<S38>/Gain2'
                                        */
  int32_T DiscreteTransferFcn_InitialStat;
                          /* Computed Parameter: DiscreteTransferFcn_InitialStat
                           * Referenced by: '<S34>/Discrete Transfer Fcn'
                           */
  int32_T DiscreteTransferFcn_InitialSt_i;
                          /* Computed Parameter: DiscreteTransferFcn_InitialSt_i
                           * Referenced by: '<S38>/Discrete Transfer Fcn'
                           */
  uint16_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S6>/Gain4'
                                        */
  uint16_T Gain_Gain_e;                /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S45>/Gain'
                                        */
  P_IfActionSubsystem1_integr_d_T IfActionSubsystem_n;/* '<S25>/If Action Subsystem' */
  P_IfActionSubsystem1_integr_d_T IfActionSubsystem1_l;/* '<S21>/If Action Subsystem1' */
  P_IfActionSubsystem1_integrat_T IfActionSubsystem3_c;/* '<S4>/If Action Subsystem3' */
  P_IfActionSubsystem1_integrat_T IfActionSubsystem1_e;/* '<S4>/If Action Subsystem1' */
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

/* Model entry point functions */
extern void integration_2_initialize(void);
extern void integration_2_step(void);
extern void integration_2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_integration_2_T *const integration_2_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate' : Unused code path elimination
 * Block '<S41>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Rate Transition1' : Eliminated since input and output rates are identical
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
 * '<S1>'   : 'integration_2/If Action Subsystem6'
 * '<S2>'   : 'integration_2/If Action Subsystem7'
 * '<S3>'   : 'integration_2/LED_B Ctrl'
 * '<S4>'   : 'integration_2/LED_R Ctrl'
 * '<S5>'   : 'integration_2/State_Ctrl'
 * '<S6>'   : 'integration_2/Subsystem'
 * '<S7>'   : 'integration_2/Subsystem1'
 * '<S8>'   : 'integration_2/Subsystem2'
 * '<S9>'   : 'integration_2/light_Ctrl'
 * '<S10>'  : 'integration_2/LED_B Ctrl/If Action Subsystem1'
 * '<S11>'  : 'integration_2/LED_B Ctrl/If Action Subsystem3'
 * '<S12>'  : 'integration_2/LED_R Ctrl/If Action Subsystem1'
 * '<S13>'  : 'integration_2/LED_R Ctrl/If Action Subsystem3'
 * '<S14>'  : 'integration_2/State_Ctrl/ADAS_state'
 * '<S15>'  : 'integration_2/State_Ctrl/drive_mode'
 * '<S16>'  : 'integration_2/State_Ctrl/ADAS_state/If Action Subsystem'
 * '<S17>'  : 'integration_2/State_Ctrl/ADAS_state/If Action Subsystem1'
 * '<S18>'  : 'integration_2/State_Ctrl/ADAS_state/If Action Subsystem/Chart'
 * '<S19>'  : 'integration_2/State_Ctrl/drive_mode/Chart'
 * '<S20>'  : 'integration_2/State_Ctrl/drive_mode/SW1'
 * '<S21>'  : 'integration_2/Subsystem/Subsystem'
 * '<S22>'  : 'integration_2/Subsystem/Subsystem/If Action Subsystem'
 * '<S23>'  : 'integration_2/Subsystem/Subsystem/If Action Subsystem1'
 * '<S24>'  : 'integration_2/Subsystem/Subsystem/If Action Subsystem2'
 * '<S25>'  : 'integration_2/Subsystem/Subsystem/If Action Subsystem3'
 * '<S26>'  : 'integration_2/Subsystem/Subsystem/If Action Subsystem3/If Action Subsystem'
 * '<S27>'  : 'integration_2/Subsystem/Subsystem/If Action Subsystem3/If Action Subsystem1'
 * '<S28>'  : 'integration_2/Subsystem/Subsystem/If Action Subsystem3/If Action Subsystem2'
 * '<S29>'  : 'integration_2/Subsystem/Subsystem/If Action Subsystem3/If Action Subsystem3'
 * '<S30>'  : 'integration_2/Subsystem/Subsystem/If Action Subsystem3/If Action Subsystem1/If Action Subsystem'
 * '<S31>'  : 'integration_2/Subsystem/Subsystem/If Action Subsystem3/If Action Subsystem1/If Action Subsystem1'
 * '<S32>'  : 'integration_2/Subsystem/Subsystem/If Action Subsystem3/If Action Subsystem1/If Action Subsystem2'
 * '<S33>'  : 'integration_2/Subsystem/Subsystem/If Action Subsystem3/If Action Subsystem1/If Action Subsystem3'
 * '<S34>'  : 'integration_2/Subsystem1/Subsystem7'
 * '<S35>'  : 'integration_2/Subsystem1/Subsystem8'
 * '<S36>'  : 'integration_2/Subsystem1/Subsystem9'
 * '<S37>'  : 'integration_2/Subsystem1/Subsystem7/Discrete Derivative'
 * '<S38>'  : 'integration_2/Subsystem2/Subsystem3'
 * '<S39>'  : 'integration_2/Subsystem2/Subsystem4'
 * '<S40>'  : 'integration_2/Subsystem2/Subsystem5'
 * '<S41>'  : 'integration_2/Subsystem2/Subsystem3/Discrete Derivative'
 * '<S42>'  : 'integration_2/light_Ctrl/If Action Subsystem'
 * '<S43>'  : 'integration_2/light_Ctrl/Subsystem'
 * '<S44>'  : 'integration_2/light_Ctrl/Subsystem/Chart1'
 * '<S45>'  : 'integration_2/light_Ctrl/Subsystem/Subsystem'
 * '<S46>'  : 'integration_2/light_Ctrl/Subsystem/Subsystem/If Action Subsystem'
 * '<S47>'  : 'integration_2/light_Ctrl/Subsystem/Subsystem/If Action Subsystem1'
 * '<S48>'  : 'integration_2/light_Ctrl/Subsystem/Subsystem/If Action Subsystem2'
 * '<S49>'  : 'integration_2/light_Ctrl/Subsystem/Subsystem/If Action Subsystem1/If Action Subsystem'
 * '<S50>'  : 'integration_2/light_Ctrl/Subsystem/Subsystem/If Action Subsystem1/If Action Subsystem1'
 */
#endif                                 /* RTW_HEADER_integration_2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
