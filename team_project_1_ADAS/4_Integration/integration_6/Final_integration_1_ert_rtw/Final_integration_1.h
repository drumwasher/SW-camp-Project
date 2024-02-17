/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Final_integration_1.h
 *
 * Code generated for Simulink model 'Final_integration_1'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Feb 15 09:21:38 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Final_integration_1_h_
#define RTW_HEADER_Final_integration_1_h_
#ifndef Final_integration_1_COMMON_INCLUDES_
#define Final_integration_1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduinoextint.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#include "MW_AnalogIn.h"
#endif                                /* Final_integration_1_COMMON_INCLUDES_ */

#include "Final_integration_1_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
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
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block states (default storage) for system '<S8>/If Action Subsystem1' */
typedef struct {
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S8>/If Action Subsystem1' */
} DW_IfActionSubsystem1_Final_i_T;

/* Block states (default storage) for system '<S40>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S40>/If Action Subsystem' */
} DW_IfActionSubsystem_Final_in_T;

/* Block signals (default storage) */
typedef struct {
  real_T RateTransition;               /* '<S14>/Rate Transition' */
  real_T u;                            /* '<Root>/전방 장애물 거리' */
  real_T u_e;                          /* '<Root>/좌측 장애물 거리' */
  real_T u_f;                          /* '<Root>/우측 장애물 거리' */
  real_T u_k;                          /* '<Root>/후방 장애물 거리' */
  real_T Merge9;                       /* '<S22>/Merge9' */
  real_T Merge7;                       /* '<S22>/Merge7' */
  real_T RateTransition_b;             /* '<S6>/Rate Transition' */
  real_T Merge8;                       /* '<S22>/Merge8' */
  real_T Delay;                        /* '<S1>/Delay' */
  real_T Delay_n;                      /* '<S3>/Delay' */
  real_T Merge;                        /* '<S40>/Merge' */
  real_T Merge1;                       /* '<S40>/Merge1' */
  real_T Subtract;                     /* '<S31>/Subtract' */
  real_T Product;                      /* '<S31>/Product' */
  real_T Subtract1;                    /* '<S31>/Subtract1' */
  real_T Product1;                     /* '<S31>/Product1' */
  real_T sw2;                          /* '<S15>/sw2' */
  real_T Mod1;                         /* '<S16>/Mod1' */
  real_T Merge_o;                      /* '<S17>/Merge' */
  boolean_T Switch;                    /* '<Root>/조도센서 Switch' */
  boolean_T AdasModeSwitch;            /* '<Root>/Adas Mode Switch' */
} B_Final_integration_1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/조도센서 Switch' */
  codertarget_arduinobase_block_T obj_g;/* '<Root>/Adas Mode Switch' */
  codertarget_arduinobase_int_n_T obj_a;/* '<Root>/조도센서 Input' */
  codertarget_arduinobase_int_n_T obj_l;/* '<Root>/가변저항' */
  codertarget_arduinobase_blo_n_T obj_i;/* '<S40>/Digital Output1' */
  codertarget_arduinobase_blo_n_T obj_e;/* '<S40>/Digital Output' */
  codertarget_arduinobase_blo_n_T obj_gm;/* '<S8>/Digital Output' */
  codertarget_arduinobase_blo_n_T obj_b;/* '<S7>/Digital Output' */
  codertarget_arduinobase_inter_T obj_ge;/* '<S5>/PWM' */
  real_T Delay_DSTATE;                 /* '<S1>/Delay' */
  real_T Delay_DSTATE_m;               /* '<S3>/Delay' */
  real_T Delay_DSTATE_d;               /* '<S36>/Delay' */
  real_T Delay1_DSTATE;                /* '<S16>/Delay1' */
  real_T Delay_DSTATE_f;               /* '<S17>/Delay' */
  real_T TmpRTBAtIfActionSubsystemInport;/* synthesized block */
  int32_T clockTickCounter;            /* '<S7>/Pulse Generator' */
  int32_T clockTickCounter_p;          /* '<S40>/Pulse Generator' */
  int32_T clockTickCounter_p5;         /* '<S34>/Pulse Generator' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S40>/If Action Subsystem1' */
  int8_T IfActionSubsystem1_SubsysRanB_g;/* '<S42>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S42>/If Action Subsystem' */
  int8_T IfActionSubsystem_SubsysRanBC_e;/* '<S6>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRan_gf;/* '<S36>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC_n;/* '<S36>/If Action Subsystem' */
  int8_T IfActionSubsystem_SubsysRanB_eh;/* '<S5>/If Action Subsystem' */
  int8_T IfActionSubsystem11_SubsysRanBC;/* '<S22>/If Action Subsystem11' */
  int8_T IfActionSubsystem3_SubsysRanBC;/* '<S24>/If Action Subsystem3' */
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<S24>/If Action Subsystem2' */
  int8_T IfActionSubsystem_SubsysRanBC_f;/* '<S24>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanB_m;/* '<S24>/If Action Subsystem1' */
  int8_T IfActionSubsystem3_SubsysRanB_j;/* '<S27>/If Action Subsystem3' */
  int8_T IfActionSubsystem2_SubsysRanB_j;/* '<S27>/If Action Subsystem2' */
  int8_T IfActionSubsystem1_SubsysRanB_e;/* '<S27>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC_i;/* '<S27>/If Action Subsystem' */
  int8_T IfActionSubsystem10_SubsysRanBC;/* '<S22>/If Action Subsystem10' */
  int8_T IfActionSubsystem9_SubsysRanBC;/* '<S22>/If Action Subsystem9' */
  int8_T IfActionSubsystem_SubsysRanBC_j;/* '<S13>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanB_j;/* '<S13>/If Action Subsystem1' */
  int8_T IfActionSubsystem3_SubsysRanB_m;/* '<S7>/If Action Subsystem3' */
  int8_T IfActionSubsystem1_SubsysRan_jo;/* '<S7>/If Action Subsystem1' */
  int8_T SW1_SubsysRanBC;              /* '<S14>/SW1' */
  int8_T IfActionSubsystem1_SubsysRanB_d;/* '<S17>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC_g;/* '<S19>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRan_da;/* '<S19>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC_o;/* '<S17>/If Action Subsystem' */
  DW_IfActionSubsystem_Final_in_T IfActionSubsystem2;/* '<S40>/If Action Subsystem2' */
  DW_IfActionSubsystem_Final_in_T IfActionSubsystem_k;/* '<S40>/If Action Subsystem' */
  DW_IfActionSubsystem1_Final_i_T IfActionSubsystem1_f;/* '<S5>/If Action Subsystem1' */
  DW_IfActionSubsystem1_Final_i_T IfActionSubsystem3_f;/* '<S8>/If Action Subsystem3' */
  DW_IfActionSubsystem1_Final_i_T IfActionSubsystem1_i;/* '<S8>/If Action Subsystem1' */
} DW_Final_integration_1_T;

/* Parameters for system: '<S8>/If Action Subsystem1' */
struct P_IfActionSubsystem1_Final_in_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S11>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_Final_integration_1_T_ {
  real_T b;                            /* Variable: b
                                        * Referenced by: '<Root>/후방 장애물 거리'
                                        */
  real_T default1;                     /* Variable: default1
                                        * Referenced by:
                                        *   '<S23>/Constant'
                                        *   '<S23>/Constant3'
                                        *   '<S30>/Constant'
                                        *   '<S30>/Constant3'
                                        *   '<S31>/Constant'
                                        *   '<S32>/Constant'
                                        *   '<S33>/Constant'
                                        *   '<S33>/Constant1'
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
                                        *   '<S30>/Constant1'
                                        *   '<S31>/Constant1'
                                        *   '<S32>/Constant1'
                                        */
  real_T AdasModeSwitch_SampleTime;    /* Expression: 0.01
                                        * Referenced by: '<Root>/Adas Mode Switch'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S19>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S17>/Constant2'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S17>/Delay'
                                        */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S17>/Merge'
                                       */
  real_T sw2_Y0;                       /* Computed Parameter: sw2_Y0
                                        * Referenced by: '<S16>/sw2'
                                        */
  real_T Constant2_Value_m;            /* Expression: 1
                                        * Referenced by: '<S16>/Constant2'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S16>/Delay1'
                                        */
  real_T Constant3_Value;              /* Expression: 2
                                        * Referenced by: '<S16>/Constant3'
                                        */
  real_T ADAS_state_Y0;                /* Computed Parameter: ADAS_state_Y0
                                        * Referenced by: '<S15>/ADAS_state'
                                        */
  real_T Constant_Value_m;             /* Expression: 0
                                        * Referenced by: '<S25>/Constant'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S23>/Constant4'
                                        */
  real_T Constant1_Value_l;            /* Expression: 100
                                        * Referenced by: '<S23>/Constant1'
                                        */
  real_T Constant5_Value;              /* Expression: 6.4
                                        * Referenced by: '<S23>/Constant5'
                                        */
  real_T Constant2_Value_n;            /* Expression: 128
                                        * Referenced by: '<S23>/Constant2'
                                        */
  real_T Constant8_Value;              /* Expression: 1
                                        * Referenced by: '<S23>/Constant8'
                                        */
  real_T Constant6_Value;              /* Expression: 100
                                        * Referenced by: '<S23>/Constant6'
                                        */
  real_T Constant9_Value;              /* Expression: 6.4
                                        * Referenced by: '<S23>/Constant9'
                                        */
  real_T Constant7_Value;              /* Expression: 128
                                        * Referenced by: '<S23>/Constant7'
                                        */
  real_T Constant10_Value;             /* Expression: 0
                                        * Referenced by: '<S23>/Constant10'
                                        */
  real_T Constant2_Value_k;            /* Expression: 1
                                        * Referenced by: '<S30>/Constant2'
                                        */
  real_T Constant4_Value_d;            /* Expression: 10
                                        * Referenced by: '<S31>/Constant4'
                                        */
  real_T Constant2_Value_l;            /* Expression: 1
                                        * Referenced by: '<S31>/Constant2'
                                        */
  real_T Constant2_Value_lo;           /* Expression: 1
                                        * Referenced by: '<S32>/Constant2'
                                        */
  real_T Constant4_Value_o;            /* Expression: 10
                                        * Referenced by: '<S32>/Constant4'
                                        */
  real_T Constant_Value_k;             /* Expression: 0
                                        * Referenced by: '<S27>/Constant'
                                        */
  real_T Constant_Value_e;             /* Expression: 0
                                        * Referenced by: '<S26>/Constant'
                                        */
  real_T Constant1_Value_j;            /* Expression: 0
                                        * Referenced by: '<S26>/Constant1'
                                        */
  real_T Constant2_Value_lk;           /* Expression: 1
                                        * Referenced by: '<S26>/Constant2'
                                        */
  real_T Gain_Gain;                    /* Expression: 1.2
                                        * Referenced by: '<S29>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1.2
                                        * Referenced by: '<S29>/Gain1'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S34>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<S34>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<S34>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S34>/Pulse Generator'
                                        */
  real_T light_mode_Y0;                /* Computed Parameter: light_mode_Y0
                                        * Referenced by: '<S36>/light_mode'
                                        */
  real_T Constant_Value_mf;            /* Expression: 1
                                        * Referenced by: '<S36>/Constant'
                                        */
  real_T Constant1_Value_g;            /* Expression: 3
                                        * Referenced by: '<S36>/Constant1'
                                        */
  real_T Constant2_Value_f;            /* Expression: 0
                                        * Referenced by: '<S36>/Constant2'
                                        */
  real_T Delay_InitialCondition_l;     /* Expression: 0.0
                                        * Referenced by: '<S36>/Delay'
                                        */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<S42>/Constant'
                                        */
  real_T Constant1_Value_p;            /* Expression: 0
                                        * Referenced by: '<S42>/Constant1'
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
  real_T PulseGenerator_Amp_g;         /* Expression: 1
                                        * Referenced by: '<S7>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_h; /* Computed Parameter: PulseGenerator_Period_h
                                   * Referenced by: '<S7>/Pulse Generator'
                                   */
  real_T PulseGenerator_Duty_m;     /* Computed Parameter: PulseGenerator_Duty_m
                                     * Referenced by: '<S7>/Pulse Generator'
                                     */
  real_T PulseGenerator_PhaseDelay_m;  /* Expression: 0
                                        * Referenced by: '<S7>/Pulse Generator'
                                        */
  real_T Constant_Value_c0;            /* Expression: 1
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Delay_InitialCondition_d;     /* Expression: 0.0
                                        * Referenced by: '<S1>/Delay'
                                        */
  real_T Delay_InitialCondition_n;     /* Expression: 0.0
                                        * Referenced by: '<S3>/Delay'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S40>/Constant'
                                        */
  real_T PulseGenerator_Amp_k;         /* Expression: 1
                                        * Referenced by: '<S40>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_k; /* Computed Parameter: PulseGenerator_Period_k
                                   * Referenced by: '<S40>/Pulse Generator'
                                   */
  real_T PulseGenerator_Duty_b;     /* Computed Parameter: PulseGenerator_Duty_b
                                     * Referenced by: '<S40>/Pulse Generator'
                                     */
  real_T PulseGenerator_PhaseDelay_j;  /* Expression: 0
                                        * Referenced by: '<S40>/Pulse Generator'
                                        */
  real_T Constant1_Value_m;            /* Expression: 0
                                        * Referenced by: '<S40>/Constant1'
                                        */
  real_T Merge_InitialOutput_b;     /* Computed Parameter: Merge_InitialOutput_b
                                     * Referenced by: '<S40>/Merge'
                                     */
  real_T Merge1_InitialOutput;       /* Computed Parameter: Merge1_InitialOutput
                                      * Referenced by: '<S40>/Merge1'
                                      */
  uint32_T Gain_Gain_a;                /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S40>/Gain'
                                        */
  uint16_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S4>/Gain4'
                                        */
  uint16_T Gain_Gain_i;                /* Computed Parameter: Gain_Gain_i
                                        * Referenced by: '<S1>/Gain'
                                        */
  P_IfActionSubsystem1_Final_in_T IfActionSubsystem1_f;/* '<S5>/If Action Subsystem1' */
  P_IfActionSubsystem1_Final_in_T IfActionSubsystem3_f;/* '<S8>/If Action Subsystem3' */
  P_IfActionSubsystem1_Final_in_T IfActionSubsystem1_i;/* '<S8>/If Action Subsystem1' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Final_integration_1_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
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
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTick2;
    uint8_T rtmDbBufReadBuf2;
    uint8_T rtmDbBufWriteBuf2;
    boolean_T rtmDbBufLastBufWr2;
    uint32_T rtmDbBufClockTick2[2];
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Final_integration_1_T Final_integration_1_P;

/* Block signals (default storage) */
extern B_Final_integration_1_T Final_integration_1_B;

/* Block states (default storage) */
extern DW_Final_integration_1_T Final_integration_1_DW;

/* External function called from main */
extern void Final_integration_1_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Final_integration_1_initialize(void);
extern void Final_integration_1_step0(void);
extern void Final_integration_1_step1(void);
extern void Final_integration_1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Final_integration_1_T *const Final_integration_1_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S13>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S13>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S3>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S14>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S14>/Rate Transition2' : Eliminated since input and output rates are identical
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
 * '<Root>' : 'Final_integration_1'
 * '<S1>'   : 'Final_integration_1/Subsystem2'
 * '<S2>'   : 'Final_integration_1/Subsystem2/LED Control'
 * '<S3>'   : 'Final_integration_1/Subsystem2/State_Ctrl'
 * '<S4>'   : 'Final_integration_1/Subsystem2/Subsystem4'
 * '<S5>'   : 'Final_integration_1/Subsystem2/buzzer system'
 * '<S6>'   : 'Final_integration_1/Subsystem2/light_Ctrl'
 * '<S7>'   : 'Final_integration_1/Subsystem2/LED Control/LED_B Ctrl'
 * '<S8>'   : 'Final_integration_1/Subsystem2/LED Control/LED_R Ctrl'
 * '<S9>'   : 'Final_integration_1/Subsystem2/LED Control/LED_B Ctrl/If Action Subsystem1'
 * '<S10>'  : 'Final_integration_1/Subsystem2/LED Control/LED_B Ctrl/If Action Subsystem3'
 * '<S11>'  : 'Final_integration_1/Subsystem2/LED Control/LED_R Ctrl/If Action Subsystem1'
 * '<S12>'  : 'Final_integration_1/Subsystem2/LED Control/LED_R Ctrl/If Action Subsystem3'
 * '<S13>'  : 'Final_integration_1/Subsystem2/State_Ctrl/ADAS_state'
 * '<S14>'  : 'Final_integration_1/Subsystem2/State_Ctrl/drive_mode'
 * '<S15>'  : 'Final_integration_1/Subsystem2/State_Ctrl/ADAS_state/If Action Subsystem'
 * '<S16>'  : 'Final_integration_1/Subsystem2/State_Ctrl/ADAS_state/If Action Subsystem1'
 * '<S17>'  : 'Final_integration_1/Subsystem2/State_Ctrl/drive_mode/SW1'
 * '<S18>'  : 'Final_integration_1/Subsystem2/State_Ctrl/drive_mode/SW1/If Action Subsystem'
 * '<S19>'  : 'Final_integration_1/Subsystem2/State_Ctrl/drive_mode/SW1/If Action Subsystem1'
 * '<S20>'  : 'Final_integration_1/Subsystem2/State_Ctrl/drive_mode/SW1/If Action Subsystem1/If Action Subsystem'
 * '<S21>'  : 'Final_integration_1/Subsystem2/State_Ctrl/drive_mode/SW1/If Action Subsystem1/If Action Subsystem1'
 * '<S22>'  : 'Final_integration_1/Subsystem2/Subsystem4/Subsystem'
 * '<S23>'  : 'Final_integration_1/Subsystem2/Subsystem4/Subsystem/If Action Subsystem10'
 * '<S24>'  : 'Final_integration_1/Subsystem2/Subsystem4/Subsystem/If Action Subsystem11'
 * '<S25>'  : 'Final_integration_1/Subsystem2/Subsystem4/Subsystem/If Action Subsystem9'
 * '<S26>'  : 'Final_integration_1/Subsystem2/Subsystem4/Subsystem/If Action Subsystem11/If Action Subsystem'
 * '<S27>'  : 'Final_integration_1/Subsystem2/Subsystem4/Subsystem/If Action Subsystem11/If Action Subsystem1'
 * '<S28>'  : 'Final_integration_1/Subsystem2/Subsystem4/Subsystem/If Action Subsystem11/If Action Subsystem2'
 * '<S29>'  : 'Final_integration_1/Subsystem2/Subsystem4/Subsystem/If Action Subsystem11/If Action Subsystem3'
 * '<S30>'  : 'Final_integration_1/Subsystem2/Subsystem4/Subsystem/If Action Subsystem11/If Action Subsystem1/If Action Subsystem'
 * '<S31>'  : 'Final_integration_1/Subsystem2/Subsystem4/Subsystem/If Action Subsystem11/If Action Subsystem1/If Action Subsystem1'
 * '<S32>'  : 'Final_integration_1/Subsystem2/Subsystem4/Subsystem/If Action Subsystem11/If Action Subsystem1/If Action Subsystem2'
 * '<S33>'  : 'Final_integration_1/Subsystem2/Subsystem4/Subsystem/If Action Subsystem11/If Action Subsystem1/If Action Subsystem3'
 * '<S34>'  : 'Final_integration_1/Subsystem2/buzzer system/If Action Subsystem'
 * '<S35>'  : 'Final_integration_1/Subsystem2/buzzer system/If Action Subsystem1'
 * '<S36>'  : 'Final_integration_1/Subsystem2/light_Ctrl/If Action Subsystem'
 * '<S37>'  : 'Final_integration_1/Subsystem2/light_Ctrl/Subsystem'
 * '<S38>'  : 'Final_integration_1/Subsystem2/light_Ctrl/If Action Subsystem/If Action Subsystem'
 * '<S39>'  : 'Final_integration_1/Subsystem2/light_Ctrl/If Action Subsystem/If Action Subsystem1'
 * '<S40>'  : 'Final_integration_1/Subsystem2/light_Ctrl/Subsystem/Subsystem'
 * '<S41>'  : 'Final_integration_1/Subsystem2/light_Ctrl/Subsystem/Subsystem/If Action Subsystem'
 * '<S42>'  : 'Final_integration_1/Subsystem2/light_Ctrl/Subsystem/Subsystem/If Action Subsystem1'
 * '<S43>'  : 'Final_integration_1/Subsystem2/light_Ctrl/Subsystem/Subsystem/If Action Subsystem2'
 * '<S44>'  : 'Final_integration_1/Subsystem2/light_Ctrl/Subsystem/Subsystem/If Action Subsystem1/If Action Subsystem'
 * '<S45>'  : 'Final_integration_1/Subsystem2/light_Ctrl/Subsystem/Subsystem/If Action Subsystem1/If Action Subsystem1'
 */
#endif                                 /* RTW_HEADER_Final_integration_1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
