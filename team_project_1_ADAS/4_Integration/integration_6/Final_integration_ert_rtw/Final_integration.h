/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Final_integration.h
 *
 * Code generated for Simulink model 'Final_integration'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Feb 15 09:43:46 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Final_integration_h_
#define RTW_HEADER_Final_integration_h_
#ifndef Final_integration_COMMON_INCLUDES_
#define Final_integration_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_arduinoextint.h"
#include "MW_arduino_digitalio.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#include "MW_AnalogIn.h"
#endif                                 /* Final_integration_COMMON_INCLUDES_ */

#include "Final_integration_types.h"
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

/* Block states (default storage) for system '<S10>/If Action Subsystem1' */
typedef struct {
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S10>/If Action Subsystem1' */
} DW_IfActionSubsystem1_Final_i_T;

/* Block states (default storage) for system '<S50>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S50>/If Action Subsystem' */
} DW_IfActionSubsystem_Final_in_T;

/* Block signals (default storage) */
typedef struct {
  int128m_T Gain2;                     /* '<S24>/Gain2' */
  int128m_T Gain2_k;                   /* '<S28>/Gain2' */
  int128m_T r;
  int128m_T r1;
  int128m_T r2;
  int96m_T r3;
  int96m_T r4;
  int96m_T r5;
  int96m_T r6;
  int96m_T r7;
  int64m_T Gain1;                      /* '<S24>/Gain1' */
  int64m_T Gain1_f;                    /* '<S28>/Gain1' */
  int64m_T DiscreteTransferFcn;        /* '<S24>/Discrete Transfer Fcn' */
  int64m_T DiscreteTransferFcn_d;      /* '<S28>/Discrete Transfer Fcn' */
  real_T RateTransition;               /* '<S16>/Rate Transition' */
  real_T u;                            /* '<Root>/전방 장애물 거리' */
  real_T u_f;                          /* '<Root>/좌측 장애물 거리' */
  real_T u_d;                          /* '<Root>/우측 장애물 거리' */
  real_T u_i;                          /* '<Root>/후방 장애물 거리' */
  real_T Merge9;                       /* '<S32>/Merge9' */
  real_T Merge7;                       /* '<S32>/Merge7' */
  real_T RateTransition_d;             /* '<S8>/Rate Transition' */
  real_T Merge8;                       /* '<S32>/Merge8' */
  real_T Delay;                        /* '<S1>/Delay' */
  real_T Delay_j;                      /* '<S3>/Delay' */
  real_T Add3;                         /* '<S4>/Add3' */
  real_T Gain4;                        /* '<S26>/Gain4' */
  real_T Add4;                         /* '<S26>/Add4' */
  real_T Saturation1;                  /* '<S4>/Saturation1' */
  real_T DataTypeConversion1;          /* '<S25>/Data Type Conversion1' */
  real_T Add5;                         /* '<S5>/Add5' */
  real_T Gain4_n;                      /* '<S30>/Gain4' */
  real_T Add4_g;                       /* '<S30>/Add4' */
  real_T Saturation2;                  /* '<S5>/Saturation2' */
  real_T DataTypeConversion1_c;        /* '<S29>/Data Type Conversion1' */
  real_T Merge;                        /* '<S50>/Merge' */
  real_T Merge1;                       /* '<S50>/Merge1' */
  real_T Subtract;                     /* '<S41>/Subtract' */
  real_T Product;                      /* '<S41>/Product' */
  real_T Subtract1;                    /* '<S41>/Subtract1' */
  real_T Product1;                     /* '<S41>/Product1' */
  real_T sw2;                          /* '<S17>/sw2' */
  real_T Mod1;                         /* '<S18>/Mod1' */
  real_T Merge_h;                      /* '<S19>/Merge' */
  int64m_T denAccum;
  int64m_T r8;
  int64m_T r9;
  int32_T DataTypeConversion1_i;       /* '<S24>/Data Type Conversion1' */
  int32_T DataTypeConversion1_e;       /* '<S28>/Data Type Conversion1' */
  uint8_T DataTypeConversion;          /* '<S25>/Data Type Conversion' */
  uint8_T DataTypeConversion_c;        /* '<S29>/Data Type Conversion' */
  boolean_T Switch;                    /* '<Root>/조도센서 Switch' */
  boolean_T AdasModeSwitch;            /* '<Root>/Adas Mode Switch' */
} B_Final_integration_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S28>/Encoder' */
  codertarget_arduinobase_inter_T obj_a;/* '<S24>/Encoder' */
  codertarget_arduinobase_block_T obj_l;/* '<Root>/조도센서 Switch' */
  codertarget_arduinobase_block_T obj_m;/* '<Root>/Adas Mode Switch' */
  codertarget_arduinobase_in_he_T obj_ld;/* '<Root>/조도센서 Input' */
  codertarget_arduinobase_in_he_T obj_f;/* '<Root>/가변저항' */
  codertarget_arduinobase_blo_h_T obj_c;/* '<S50>/Digital Output1' */
  codertarget_arduinobase_blo_h_T obj_cq;/* '<S50>/Digital Output' */
  codertarget_arduinobase_blo_h_T obj_k;/* '<S4>/Digital Output' */
  codertarget_arduinobase_blo_h_T obj_n;/* '<S10>/Digital Output' */
  codertarget_arduinobase_blo_h_T obj_g;/* '<S9>/Digital Output' */
  codertarget_arduinobase_int_h_T obj_o;/* '<S7>/PWM' */
  codertarget_arduinobase_int_h_T obj_i;/* '<S29>/PWM' */
  codertarget_arduinobase_int_h_T obj_ma;/* '<S25>/PWM' */
  real_T Delay_DSTATE;                 /* '<S1>/Delay' */
  real_T Delay_DSTATE_m;               /* '<S3>/Delay' */
  real_T Delay_DSTATE_e;               /* '<S46>/Delay' */
  real_T Delay1_DSTATE;                /* '<S18>/Delay1' */
  real_T Delay_DSTATE_p;               /* '<S19>/Delay' */
  real_T TmpRTBAtIfActionSubsystemInport;/* synthesized block */
  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<S4>/Scope1' */

  struct {
    void *LoggedData;
  } Scope10_PWORK;                     /* '<S4>/Scope10' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S4>/Scope2' */

  struct {
    void *LoggedData[2];
  } Scope4_PWORK;                      /* '<S5>/Scope4' */

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<S5>/Scope5' */

  struct {
    void *LoggedData;
  } Scope9_PWORK;                      /* '<S5>/Scope9' */

  int32_T DiscreteTransferFcn_states;  /* '<S24>/Discrete Transfer Fcn' */
  int32_T DiscreteTransferFcn_states_l;/* '<S28>/Discrete Transfer Fcn' */
  int32_T UD_DSTATE;                   /* '<S27>/UD' */
  int32_T UD_DSTATE_k;                 /* '<S31>/UD' */
  int32_T clockTickCounter;            /* '<S9>/Pulse Generator' */
  int32_T clockTickCounter_k;          /* '<S50>/Pulse Generator' */
  int32_T clockTickCounter_j;          /* '<S44>/Pulse Generator' */
  int8_T If_ActiveSubsystem;           /* '<S3>/If' */
  int8_T If3_ActiveSubsystem;          /* '<S32>/If3' */
  int8_T If1_ActiveSubsystem;          /* '<S9>/If1' */
  int8_T If1_ActiveSubsystem_c;        /* '<S10>/If1' */
  int8_T If_ActiveSubsystem_g;         /* '<S7>/If' */
  int8_T If_ActiveSubsystem_b;         /* '<S50>/If' */
  int8_T If_ActiveSubsystem_a;         /* '<S15>/If' */
  int8_T If_ActiveSubsystem_p;         /* '<S8>/If' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S50>/If Action Subsystem1' */
  int8_T IfActionSubsystem1_SubsysRanB_l;/* '<S52>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S52>/If Action Subsystem' */
  int8_T IfActionSubsystem_SubsysRanBC_m;/* '<S8>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanB_m;/* '<S46>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC_a;/* '<S46>/If Action Subsystem' */
  int8_T IfActionSubsystem_SubsysRanBC_j;/* '<S7>/If Action Subsystem' */
  int8_T IfActionSubsystem11_SubsysRanBC;/* '<S32>/If Action Subsystem11' */
  int8_T IfActionSubsystem3_SubsysRanBC;/* '<S34>/If Action Subsystem3' */
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<S34>/If Action Subsystem2' */
  int8_T IfActionSubsystem_SubsysRanBC_c;/* '<S34>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanB_p;/* '<S34>/If Action Subsystem1' */
  int8_T IfActionSubsystem3_SubsysRanB_p;/* '<S37>/If Action Subsystem3' */
  int8_T IfActionSubsystem2_SubsysRanB_l;/* '<S37>/If Action Subsystem2' */
  int8_T IfActionSubsystem1_SubsysRanB_d;/* '<S37>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC_f;/* '<S37>/If Action Subsystem' */
  int8_T IfActionSubsystem10_SubsysRanBC;/* '<S32>/If Action Subsystem10' */
  int8_T IfActionSubsystem9_SubsysRanBC;/* '<S32>/If Action Subsystem9' */
  int8_T IfActionSubsystem_SubsysRanBC_n;/* '<S15>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRan_dx;/* '<S15>/If Action Subsystem1' */
  int8_T IfActionSubsystem3_SubsysRanB_n;/* '<S9>/If Action Subsystem3' */
  int8_T IfActionSubsystem1_SubsysRanB_e;/* '<S9>/If Action Subsystem1' */
  int8_T SW1_SubsysRanBC;              /* '<S16>/SW1' */
  int8_T IfActionSubsystem1_SubsysRanB_a;/* '<S19>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC_g;/* '<S21>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRan_l2;/* '<S21>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanB_al;/* '<S19>/If Action Subsystem' */
  DW_IfActionSubsystem_Final_in_T IfActionSubsystem2;/* '<S50>/If Action Subsystem2' */
  DW_IfActionSubsystem_Final_in_T IfActionSubsystem_a;/* '<S50>/If Action Subsystem' */
  DW_IfActionSubsystem1_Final_i_T IfActionSubsystem1_g;/* '<S7>/If Action Subsystem1' */
  DW_IfActionSubsystem1_Final_i_T IfActionSubsystem3_h;/* '<S10>/If Action Subsystem3' */
  DW_IfActionSubsystem1_Final_i_T IfActionSubsystem1_k;/* '<S10>/If Action Subsystem1' */
} DW_Final_integration_T;

/* Continuous states (default storage) */
typedef struct {
  real_T TransferFcn1_CSTATE;          /* '<S26>/Transfer Fcn1' */
  real_T TransferFcn1_CSTATE_j;        /* '<S30>/Transfer Fcn1' */
} X_Final_integration_T;

/* State derivatives (default storage) */
typedef struct {
  real_T TransferFcn1_CSTATE;          /* '<S26>/Transfer Fcn1' */
  real_T TransferFcn1_CSTATE_j;        /* '<S30>/Transfer Fcn1' */
} XDot_Final_integration_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn1_CSTATE;       /* '<S26>/Transfer Fcn1' */
  boolean_T TransferFcn1_CSTATE_j;     /* '<S30>/Transfer Fcn1' */
} XDis_Final_integration_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters for system: '<S10>/If Action Subsystem1' */
struct P_IfActionSubsystem1_Final_in_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S13>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_Final_integration_T_ {
  real_T KP;                           /* Variable: KP
                                        * Referenced by:
                                        *   '<S26>/Gain4'
                                        *   '<S30>/Gain4'
                                        */
  real_T Vlim;                         /* Variable: Vlim
                                        * Referenced by:
                                        *   '<S25>/Gain1'
                                        *   '<S29>/Gain1'
                                        */
  real_T b;                            /* Variable: b
                                        * Referenced by: '<Root>/후방 장애물 거리'
                                        */
  real_T default1;                     /* Variable: default1
                                        * Referenced by:
                                        *   '<S33>/Constant'
                                        *   '<S33>/Constant3'
                                        *   '<S40>/Constant'
                                        *   '<S40>/Constant3'
                                        *   '<S41>/Constant'
                                        *   '<S42>/Constant'
                                        *   '<S43>/Constant'
                                        *   '<S43>/Constant1'
                                        */
  real_T f;                            /* Variable: f
                                        * Referenced by: '<Root>/전방 장애물 거리'
                                        */
  real_T l;                            /* Variable: l
                                        * Referenced by: '<Root>/좌측 장애물 거리'
                                        */
  real_T r;                            /* Variable: r
                                        * Referenced by: '<Root>/우측 장애물 거리'
                                        */
  real_T steering;                     /* Variable: steering
                                        * Referenced by:
                                        *   '<S40>/Constant1'
                                        *   '<S41>/Constant1'
                                        *   '<S42>/Constant1'
                                        */
  int32_T den_Gd[2];                   /* Variable: den_Gd
                                        * Referenced by:
                                        *   '<S24>/Discrete Transfer Fcn'
                                        *   '<S28>/Discrete Transfer Fcn'
                                        */
  int32_T encoder_scale;               /* Variable: encoder_scale
                                        * Referenced by:
                                        *   '<S24>/Gain1'
                                        *   '<S28>/Gain1'
                                        */
  int32_T num_Gd[2];                   /* Variable: num_Gd
                                        * Referenced by:
                                        *   '<S24>/Discrete Transfer Fcn'
                                        *   '<S28>/Discrete Transfer Fcn'
                                        */
  int32_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S27>/UD'
                               */
  int32_T DiscreteDerivative_ICPrevScal_j;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_j
                               * Referenced by: '<S31>/UD'
                               */
  real_T AdasModeSwitch_SampleTime;    /* Expression: 0.01
                                        * Referenced by: '<Root>/Adas Mode Switch'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S21>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S19>/Constant2'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S19>/Delay'
                                        */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S19>/Merge'
                                       */
  real_T sw2_Y0;                       /* Computed Parameter: sw2_Y0
                                        * Referenced by: '<S18>/sw2'
                                        */
  real_T Constant2_Value_g;            /* Expression: 1
                                        * Referenced by: '<S18>/Constant2'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S18>/Delay1'
                                        */
  real_T Constant3_Value;              /* Expression: 2
                                        * Referenced by: '<S18>/Constant3'
                                        */
  real_T ADAS_state_Y0;                /* Computed Parameter: ADAS_state_Y0
                                        * Referenced by: '<S17>/ADAS_state'
                                        */
  real_T Encoder_SampleTime;           /* Expression: 0.01
                                        * Referenced by: '<S24>/Encoder'
                                        */
  real_T Encoder_SampleTime_f;         /* Expression: 0.01
                                        * Referenced by: '<S28>/Encoder'
                                        */
  real_T Constant_Value_m;             /* Expression: 0
                                        * Referenced by: '<S35>/Constant'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S33>/Constant4'
                                        */
  real_T Constant1_Value_f;            /* Expression: 100
                                        * Referenced by: '<S33>/Constant1'
                                        */
  real_T Constant5_Value;              /* Expression: 6.4
                                        * Referenced by: '<S33>/Constant5'
                                        */
  real_T Constant2_Value_go;           /* Expression: 128
                                        * Referenced by: '<S33>/Constant2'
                                        */
  real_T Constant8_Value;              /* Expression: 1
                                        * Referenced by: '<S33>/Constant8'
                                        */
  real_T Constant6_Value;              /* Expression: 100
                                        * Referenced by: '<S33>/Constant6'
                                        */
  real_T Constant9_Value;              /* Expression: 6.4
                                        * Referenced by: '<S33>/Constant9'
                                        */
  real_T Constant7_Value;              /* Expression: 128
                                        * Referenced by: '<S33>/Constant7'
                                        */
  real_T Constant10_Value;             /* Expression: 0
                                        * Referenced by: '<S33>/Constant10'
                                        */
  real_T Constant2_Value_j;            /* Expression: 1
                                        * Referenced by: '<S40>/Constant2'
                                        */
  real_T Constant4_Value_d;            /* Expression: 10
                                        * Referenced by: '<S41>/Constant4'
                                        */
  real_T Constant2_Value_n;            /* Expression: 1
                                        * Referenced by: '<S41>/Constant2'
                                        */
  real_T Constant2_Value_gd;           /* Expression: 1
                                        * Referenced by: '<S42>/Constant2'
                                        */
  real_T Constant4_Value_m;            /* Expression: 10
                                        * Referenced by: '<S42>/Constant4'
                                        */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<S37>/Constant'
                                        */
  real_T Constant_Value_mr;            /* Expression: 0
                                        * Referenced by: '<S36>/Constant'
                                        */
  real_T Constant1_Value_f5;           /* Expression: 0
                                        * Referenced by: '<S36>/Constant1'
                                        */
  real_T Constant2_Value_p;            /* Expression: 1
                                        * Referenced by: '<S36>/Constant2'
                                        */
  real_T Gain_Gain;                    /* Expression: 1.2
                                        * Referenced by: '<S39>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1.2
                                        * Referenced by: '<S39>/Gain1'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S44>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<S44>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<S44>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S44>/Pulse Generator'
                                        */
  real_T light_mode_Y0;                /* Computed Parameter: light_mode_Y0
                                        * Referenced by: '<S46>/light_mode'
                                        */
  real_T Constant_Value_ou;            /* Expression: 1
                                        * Referenced by: '<S46>/Constant'
                                        */
  real_T Constant1_Value_c;            /* Expression: 3
                                        * Referenced by: '<S46>/Constant1'
                                        */
  real_T Constant2_Value_i;            /* Expression: 0
                                        * Referenced by: '<S46>/Constant2'
                                        */
  real_T Delay_InitialCondition_h;     /* Expression: 0.0
                                        * Referenced by: '<S46>/Delay'
                                        */
  real_T Constant_Value_e;             /* Expression: 1
                                        * Referenced by: '<S52>/Constant'
                                        */
  real_T Constant1_Value_l;            /* Expression: 0
                                        * Referenced by: '<S52>/Constant1'
                                        */
  real_T _SampleTime;                  /* Expression: -1
                                        * Referenced by: '<Root>/가변저항'
                                        */
  real_T Input_SampleTime;             /* Expression: 0.01
                                        * Referenced by: '<Root>/조도센서 Input'
                                        */
  real_T Switch_SampleTime;            /* Expression: 0.01
                                        * Referenced by: '<Root>/조도센서 Switch'
                                        */
  real_T PulseGenerator_Amp_k;         /* Expression: 1
                                        * Referenced by: '<S9>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_l; /* Computed Parameter: PulseGenerator_Period_l
                                   * Referenced by: '<S9>/Pulse Generator'
                                   */
  real_T PulseGenerator_Duty_p;     /* Computed Parameter: PulseGenerator_Duty_p
                                     * Referenced by: '<S9>/Pulse Generator'
                                     */
  real_T PulseGenerator_PhaseDelay_p;  /* Expression: 0
                                        * Referenced by: '<S9>/Pulse Generator'
                                        */
  real_T Constant_Value_b;             /* Expression: 1
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Delay_InitialCondition_k;     /* Expression: 0.0
                                        * Referenced by: '<S1>/Delay'
                                        */
  real_T Delay_InitialCondition_g;     /* Expression: 0.0
                                        * Referenced by: '<S3>/Delay'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S26>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S26>/Transfer Fcn1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 12
                                        * Referenced by: '<S4>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 2
                                        * Referenced by: '<S4>/Saturation1'
                                        */
  real_T Constant9_Value_g;            /* Expression: 0
                                        * Referenced by: '<S4>/Constant9'
                                        */
  real_T Switch_Threshold;             /* Expression: 2
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T Constant_Value_oh;            /* Expression: 1
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T TransferFcn1_A_o;             /* Computed Parameter: TransferFcn1_A_o
                                        * Referenced by: '<S30>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C_o;             /* Computed Parameter: TransferFcn1_C_o
                                        * Referenced by: '<S30>/Transfer Fcn1'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 12
                                        * Referenced by: '<S5>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S5>/Saturation2'
                                        */
  real_T Constant16_Value;             /* Expression: 0
                                        * Referenced by: '<S5>/Constant16'
                                        */
  real_T Switch1_Threshold;            /* Expression: 2
                                        * Referenced by: '<S5>/Switch1'
                                        */
  real_T Constant_Value_m4;            /* Expression: 1
                                        * Referenced by: '<S50>/Constant'
                                        */
  real_T PulseGenerator_Amp_f;         /* Expression: 1
                                        * Referenced by: '<S50>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_e; /* Computed Parameter: PulseGenerator_Period_e
                                   * Referenced by: '<S50>/Pulse Generator'
                                   */
  real_T PulseGenerator_Duty_l;     /* Computed Parameter: PulseGenerator_Duty_l
                                     * Referenced by: '<S50>/Pulse Generator'
                                     */
  real_T PulseGenerator_PhaseDelay_j;  /* Expression: 0
                                        * Referenced by: '<S50>/Pulse Generator'
                                        */
  real_T Constant1_Value_m;            /* Expression: 0
                                        * Referenced by: '<S50>/Constant1'
                                        */
  real_T Merge_InitialOutput_f;     /* Computed Parameter: Merge_InitialOutput_f
                                     * Referenced by: '<S50>/Merge'
                                     */
  real_T Merge1_InitialOutput;       /* Computed Parameter: Merge1_InitialOutput
                                      * Referenced by: '<S50>/Merge1'
                                      */
  int64m_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S24>/Gain2'
                                        */
  int64m_T Gain2_Gain_c;               /* Computed Parameter: Gain2_Gain_c
                                        * Referenced by: '<S28>/Gain2'
                                        */
  int32_T DiscreteTransferFcn_InitialStat;
                          /* Computed Parameter: DiscreteTransferFcn_InitialStat
                           * Referenced by: '<S24>/Discrete Transfer Fcn'
                           */
  int32_T DiscreteTransferFcn_InitialSt_b;
                          /* Computed Parameter: DiscreteTransferFcn_InitialSt_b
                           * Referenced by: '<S28>/Discrete Transfer Fcn'
                           */
  uint32_T Gain_Gain_c;                /* Computed Parameter: Gain_Gain_c
                                        * Referenced by: '<S50>/Gain'
                                        */
  uint16_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S6>/Gain4'
                                        */
  uint16_T Gain_Gain_o;                /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<S1>/Gain'
                                        */
  P_IfActionSubsystem1_Final_in_T IfActionSubsystem1_g;/* '<S7>/If Action Subsystem1' */
  P_IfActionSubsystem1_Final_in_T IfActionSubsystem3_h;/* '<S10>/If Action Subsystem3' */
  P_IfActionSubsystem1_Final_in_T IfActionSubsystem1_k;/* '<S10>/If Action Subsystem1' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Final_integration_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_Final_integration_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_Final_integration_T *contStateDisabled;
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
    time_T tArray[4];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Final_integration_T Final_integration_P;

/* Block signals (default storage) */
extern B_Final_integration_T Final_integration_B;

/* Continuous states (default storage) */
extern X_Final_integration_T Final_integration_X;

/* Disabled states (default storage) */
extern XDis_Final_integration_T Final_integration_XDis;

/* Block states (default storage) */
extern DW_Final_integration_T Final_integration_DW;

/* External function called from main */
extern void Final_integration_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Final_integration_initialize(void);
extern void Final_integration_step0(void);
extern void Final_integration_step2(void);
extern void Final_integration_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Final_integration_T *const Final_integration_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S1>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S15>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S15>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S3>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S16>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S16>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S8>/Rate Transition1' : Eliminated since input and output rates are identical
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
 * '<Root>' : 'Final_integration'
 * '<S1>'   : 'Final_integration/Subsystem2'
 * '<S2>'   : 'Final_integration/Subsystem2/LED Control'
 * '<S3>'   : 'Final_integration/Subsystem2/State_Ctrl'
 * '<S4>'   : 'Final_integration/Subsystem2/Subsystem'
 * '<S5>'   : 'Final_integration/Subsystem2/Subsystem1'
 * '<S6>'   : 'Final_integration/Subsystem2/Subsystem4'
 * '<S7>'   : 'Final_integration/Subsystem2/buzzer system'
 * '<S8>'   : 'Final_integration/Subsystem2/light_Ctrl'
 * '<S9>'   : 'Final_integration/Subsystem2/LED Control/LED_B Ctrl'
 * '<S10>'  : 'Final_integration/Subsystem2/LED Control/LED_R Ctrl'
 * '<S11>'  : 'Final_integration/Subsystem2/LED Control/LED_B Ctrl/If Action Subsystem1'
 * '<S12>'  : 'Final_integration/Subsystem2/LED Control/LED_B Ctrl/If Action Subsystem3'
 * '<S13>'  : 'Final_integration/Subsystem2/LED Control/LED_R Ctrl/If Action Subsystem1'
 * '<S14>'  : 'Final_integration/Subsystem2/LED Control/LED_R Ctrl/If Action Subsystem3'
 * '<S15>'  : 'Final_integration/Subsystem2/State_Ctrl/ADAS_state'
 * '<S16>'  : 'Final_integration/Subsystem2/State_Ctrl/drive_mode'
 * '<S17>'  : 'Final_integration/Subsystem2/State_Ctrl/ADAS_state/If Action Subsystem'
 * '<S18>'  : 'Final_integration/Subsystem2/State_Ctrl/ADAS_state/If Action Subsystem1'
 * '<S19>'  : 'Final_integration/Subsystem2/State_Ctrl/drive_mode/SW1'
 * '<S20>'  : 'Final_integration/Subsystem2/State_Ctrl/drive_mode/SW1/If Action Subsystem'
 * '<S21>'  : 'Final_integration/Subsystem2/State_Ctrl/drive_mode/SW1/If Action Subsystem1'
 * '<S22>'  : 'Final_integration/Subsystem2/State_Ctrl/drive_mode/SW1/If Action Subsystem1/If Action Subsystem'
 * '<S23>'  : 'Final_integration/Subsystem2/State_Ctrl/drive_mode/SW1/If Action Subsystem1/If Action Subsystem1'
 * '<S24>'  : 'Final_integration/Subsystem2/Subsystem/Encoder Motor'
 * '<S25>'  : 'Final_integration/Subsystem2/Subsystem/Motor control'
 * '<S26>'  : 'Final_integration/Subsystem2/Subsystem/PID control'
 * '<S27>'  : 'Final_integration/Subsystem2/Subsystem/Encoder Motor/Discrete Derivative'
 * '<S28>'  : 'Final_integration/Subsystem2/Subsystem1/Encoder Motor'
 * '<S29>'  : 'Final_integration/Subsystem2/Subsystem1/Motor Control'
 * '<S30>'  : 'Final_integration/Subsystem2/Subsystem1/PID Control'
 * '<S31>'  : 'Final_integration/Subsystem2/Subsystem1/Encoder Motor/Discrete Derivative'
 * '<S32>'  : 'Final_integration/Subsystem2/Subsystem4/Subsystem'
 * '<S33>'  : 'Final_integration/Subsystem2/Subsystem4/Subsystem/If Action Subsystem10'
 * '<S34>'  : 'Final_integration/Subsystem2/Subsystem4/Subsystem/If Action Subsystem11'
 * '<S35>'  : 'Final_integration/Subsystem2/Subsystem4/Subsystem/If Action Subsystem9'
 * '<S36>'  : 'Final_integration/Subsystem2/Subsystem4/Subsystem/If Action Subsystem11/If Action Subsystem'
 * '<S37>'  : 'Final_integration/Subsystem2/Subsystem4/Subsystem/If Action Subsystem11/If Action Subsystem1'
 * '<S38>'  : 'Final_integration/Subsystem2/Subsystem4/Subsystem/If Action Subsystem11/If Action Subsystem2'
 * '<S39>'  : 'Final_integration/Subsystem2/Subsystem4/Subsystem/If Action Subsystem11/If Action Subsystem3'
 * '<S40>'  : 'Final_integration/Subsystem2/Subsystem4/Subsystem/If Action Subsystem11/If Action Subsystem1/If Action Subsystem'
 * '<S41>'  : 'Final_integration/Subsystem2/Subsystem4/Subsystem/If Action Subsystem11/If Action Subsystem1/If Action Subsystem1'
 * '<S42>'  : 'Final_integration/Subsystem2/Subsystem4/Subsystem/If Action Subsystem11/If Action Subsystem1/If Action Subsystem2'
 * '<S43>'  : 'Final_integration/Subsystem2/Subsystem4/Subsystem/If Action Subsystem11/If Action Subsystem1/If Action Subsystem3'
 * '<S44>'  : 'Final_integration/Subsystem2/buzzer system/If Action Subsystem'
 * '<S45>'  : 'Final_integration/Subsystem2/buzzer system/If Action Subsystem1'
 * '<S46>'  : 'Final_integration/Subsystem2/light_Ctrl/If Action Subsystem'
 * '<S47>'  : 'Final_integration/Subsystem2/light_Ctrl/Subsystem'
 * '<S48>'  : 'Final_integration/Subsystem2/light_Ctrl/If Action Subsystem/If Action Subsystem'
 * '<S49>'  : 'Final_integration/Subsystem2/light_Ctrl/If Action Subsystem/If Action Subsystem1'
 * '<S50>'  : 'Final_integration/Subsystem2/light_Ctrl/Subsystem/Subsystem'
 * '<S51>'  : 'Final_integration/Subsystem2/light_Ctrl/Subsystem/Subsystem/If Action Subsystem'
 * '<S52>'  : 'Final_integration/Subsystem2/light_Ctrl/Subsystem/Subsystem/If Action Subsystem1'
 * '<S53>'  : 'Final_integration/Subsystem2/light_Ctrl/Subsystem/Subsystem/If Action Subsystem2'
 * '<S54>'  : 'Final_integration/Subsystem2/light_Ctrl/Subsystem/Subsystem/If Action Subsystem1/If Action Subsystem'
 * '<S55>'  : 'Final_integration/Subsystem2/light_Ctrl/Subsystem/Subsystem/If Action Subsystem1/If Action Subsystem1'
 */
#endif                                 /* RTW_HEADER_Final_integration_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
