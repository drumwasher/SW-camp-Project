/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ACC.h
 *
 * Code generated for Simulink model 'ACC'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Feb  5 10:17:43 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ACC_h_
#define RTW_HEADER_ACC_h_
#ifndef ACC_COMMON_INCLUDES_
#define ACC_COMMON_INCLUDES_
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
#include "MW_Ultrasonic.h"
#endif                                 /* ACC_COMMON_INCLUDES_ */

#include "ACC_types.h"
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

/* Block states (default storage) for system '<S4>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S4>/If Action Subsystem' */
} DW_IfActionSubsystem_ACC_T;

/* Block signals (default storage) */
typedef struct {
  real_T Gain;                         /* '<S4>/Gain' */
  real_T PulseGenerator;               /* '<S4>/Pulse Generator' */
  real_T Merge;                        /* '<S4>/Merge' */
  real_T TmpRTBAtFunctionCallSubsystem4O;/* '<S2>/Function-Call Subsystem4' */
  real_T TmpRTBAtFunctionCallSubsystem6O;/* '<S2>/Function-Call Subsystem6' */
  real_T RateTransition;               /* '<S2>/Rate Transition' */
  real_T PulseGenerator6;              /* '<S2>/Pulse Generator6' */
  real_T PulseGenerator7;              /* '<S2>/Pulse Generator7' */
  real_T DataTypeConversion2;          /* '<S3>/Data Type Conversion2' */
  real_T PulseGenerator_i;             /* '<S5>/Pulse Generator' */
  real_T PulseGenerator1;              /* '<S5>/Pulse Generator1' */
  real_T Add;                          /* '<S11>/Add' */
  real_T Add_j;                        /* '<S10>/Add' */
} B_ACC_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input' */
  codertarget_arduinobase_block_T obj_h;/* '<Root>/Digital Output4' */
  codertarget_arduinobase_block_T obj_g;/* '<Root>/Digital Output1' */
  codertarget_arduinobase_block_T obj_n;/* '<Root>/Digital Output' */
  codertarget_arduinobase_int_e_T obj_f;/* '<Root>/PWM' */
  volatile real_T TmpRTBAtFunctionCallSubsystem4O;/* synthesized block */
  volatile real_T TmpRTBAtFunctionCallSubsystem_e;/* synthesized block */
  volatile real_T TmpRTBAtFunctionCallSubsystem6O;/* synthesized block */
  volatile real_T TmpRTBAtFunctionCallSubsystem_a;/* synthesized block */
  real_T a;                            /* '<S3>/Chart' */
  real_T v1;                           /* '<S2>/Chart' */
  real_T v2;                           /* '<S2>/Chart' */
  codertarget_arduinobase_in_e3_T obj_i;/* '<Root>/Ultrasonic Sensor' */
  int32_T clockTickCounter;            /* '<S4>/Pulse Generator' */
  int32_T clockTickCounter_g;          /* '<S2>/Pulse Generator6' */
  int32_T clockTickCounter_n;          /* '<S2>/Pulse Generator7' */
  int32_T clockTickCounter_f;          /* '<S5>/Pulse Generator' */
  int32_T clockTickCounter_p;          /* '<S5>/Pulse Generator1' */
  uint32_T is_c1_ACC;                  /* '<S3>/Chart' */
  uint32_T is_c3_ACC;                  /* '<S2>/Chart' */
  volatile int8_T TmpRTBAtFunctionCallSubsystem_f;/* synthesized block */
  volatile int8_T TmpRTBAtFunctionCallSubsystem_o;/* synthesized block */
  volatile int8_T TmpRTBAtFunctionCallSubsystem_c;/* synthesized block */
  volatile int8_T TmpRTBAtFunctionCallSubsystem_n;/* synthesized block */
  volatile int8_T TmpRTBAtFunctionCallSubsyste_ff;/* synthesized block */
  volatile int8_T TmpRTBAtFunctionCallSubsystem_k;/* synthesized block */
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<S5>/If Action Subsystem2' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S5>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S5>/If Action Subsystem' */
  int8_T IfActionSubsystem2_SubsysRanB_b;/* '<S3>/If Action Subsystem2' */
  int8_T IfActionSubsystem1_SubsysRanB_g;/* '<S3>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC_m;/* '<S3>/If Action Subsystem' */
  int8_T ACCoff5_SubsysRanBC;          /* '<S2>/ACC off5' */
  int8_T ACCon2_SubsysRanBC;           /* '<S2>/ACC on2' */
  int8_T ACCstandby2_SubsysRanBC;      /* '<S2>/ACC standby2' */
  int8_T FunctionCallSubsystem6_SubsysRa;/* '<S2>/Function-Call Subsystem6' */
  int8_T FunctionCallSubsystem4_SubsysRa;/* '<S2>/Function-Call Subsystem4' */
  uint8_T is_active_c1_ACC;            /* '<S3>/Chart' */
  uint8_T is_active_c3_ACC;            /* '<S2>/Chart' */
  DW_IfActionSubsystem_ACC_T IfActionSubsystem2_j;/* '<S4>/If Action Subsystem2' */
  DW_IfActionSubsystem_ACC_T IfActionSubsystem1_m;/* '<S4>/If Action Subsystem1' */
  DW_IfActionSubsystem_ACC_T IfActionSubsystem_i;/* '<S4>/If Action Subsystem' */
} DW_ACC_T;

/* Parameters (default storage) */
struct P_ACC_T_ {
  real_T AnalogInput_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T sw1_Y0;                       /* Computed Parameter: sw1_Y0
                                        * Referenced by: '<S10>/sw1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S10>/Delay'
                                        */
  real_T sw2_Y0;                       /* Computed Parameter: sw2_Y0
                                        * Referenced by: '<S11>/sw2'
                                        */
  real_T Constant_Value_e;             /* Expression: 1
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Delay_InitialCondition_d;     /* Expression: 0.0
                                        * Referenced by: '<S11>/Delay'
                                        */
  real_T Constant_Value_b;             /* Expression: 1
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S4>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<S4>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<S4>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S4>/Pulse Generator'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S4>/Constant3'
                                        */
  real_T Constant_Value_ei;            /* Expression: 1
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 2
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T TmpRTBAtFunctionCallSubsystem4O;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpRTBAtFunctionCallSubsystem6O;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T PulseGenerator6_Amp;          /* Expression: 1
                                        * Referenced by: '<S2>/Pulse Generator6'
                                        */
  real_T PulseGenerator6_Period;   /* Computed Parameter: PulseGenerator6_Period
                                    * Referenced by: '<S2>/Pulse Generator6'
                                    */
  real_T PulseGenerator6_Duty;       /* Computed Parameter: PulseGenerator6_Duty
                                      * Referenced by: '<S2>/Pulse Generator6'
                                      */
  real_T PulseGenerator6_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<S2>/Pulse Generator6'
                                        */
  real_T PulseGenerator7_Amp;          /* Expression: 1
                                        * Referenced by: '<S2>/Pulse Generator7'
                                        */
  real_T PulseGenerator7_Period;   /* Computed Parameter: PulseGenerator7_Period
                                    * Referenced by: '<S2>/Pulse Generator7'
                                    */
  real_T PulseGenerator7_Duty;       /* Computed Parameter: PulseGenerator7_Duty
                                      * Referenced by: '<S2>/Pulse Generator7'
                                      */
  real_T PulseGenerator7_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<S2>/Pulse Generator7'
                                        */
  real_T Constant1_Value_j;            /* Expression: 2
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T PulseGenerator_Amp_l;         /* Expression: 1
                                        * Referenced by: '<S5>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_p; /* Computed Parameter: PulseGenerator_Period_p
                                   * Referenced by: '<S5>/Pulse Generator'
                                   */
  real_T PulseGenerator_Duty_n;     /* Computed Parameter: PulseGenerator_Duty_n
                                     * Referenced by: '<S5>/Pulse Generator'
                                     */
  real_T PulseGenerator_PhaseDelay_p;  /* Expression: 0
                                        * Referenced by: '<S5>/Pulse Generator'
                                        */
  real_T PulseGenerator1_Amp;          /* Expression: 1
                                        * Referenced by: '<S5>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period;   /* Computed Parameter: PulseGenerator1_Period
                                    * Referenced by: '<S5>/Pulse Generator1'
                                    */
  real_T PulseGenerator1_Duty;       /* Computed Parameter: PulseGenerator1_Duty
                                      * Referenced by: '<S5>/Pulse Generator1'
                                      */
  real_T PulseGenerator1_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<S5>/Pulse Generator1'
                                        */
  uint16_T Gain_Gain_f;                /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S3>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ACC_T {
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
    uint32_T clockTick3;
    uint32_T clockTick4;
    uint8_T rtmDbBufReadBuf4;
    uint8_T rtmDbBufWriteBuf4;
    boolean_T rtmDbBufLastBufWr4;
    uint32_T rtmDbBufClockTick4[2];
    uint32_T clockTick5;
    uint8_T rtmDbBufReadBuf5;
    uint8_T rtmDbBufWriteBuf5;
    boolean_T rtmDbBufLastBufWr5;
    uint32_T rtmDbBufClockTick5[2];
    struct {
      uint8_T TID[4];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_ACC_T ACC_P;

/* Block signals (default storage) */
extern B_ACC_T ACC_B;

/* Block states (default storage) */
extern DW_ACC_T ACC_DW;

/* Model entry point functions */
extern void ACC_initialize(void);
extern void ACC_step(void);
extern void ACC_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ACC_T *const ACC_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'ACC'
 * '<S1>'   : 'ACC/Subsystem'
 * '<S2>'   : 'ACC/Subsystem/Subsystem'
 * '<S3>'   : 'ACC/Subsystem/Subsystem1'
 * '<S4>'   : 'ACC/Subsystem/Subsystem2'
 * '<S5>'   : 'ACC/Subsystem/Subsystem3'
 * '<S6>'   : 'ACC/Subsystem/Subsystem/ACC off5'
 * '<S7>'   : 'ACC/Subsystem/Subsystem/ACC on2'
 * '<S8>'   : 'ACC/Subsystem/Subsystem/ACC standby2'
 * '<S9>'   : 'ACC/Subsystem/Subsystem/Chart'
 * '<S10>'  : 'ACC/Subsystem/Subsystem/Function-Call Subsystem4'
 * '<S11>'  : 'ACC/Subsystem/Subsystem/Function-Call Subsystem6'
 * '<S12>'  : 'ACC/Subsystem/Subsystem1/Chart'
 * '<S13>'  : 'ACC/Subsystem/Subsystem1/If Action Subsystem'
 * '<S14>'  : 'ACC/Subsystem/Subsystem1/If Action Subsystem1'
 * '<S15>'  : 'ACC/Subsystem/Subsystem1/If Action Subsystem2'
 * '<S16>'  : 'ACC/Subsystem/Subsystem2/If Action Subsystem'
 * '<S17>'  : 'ACC/Subsystem/Subsystem2/If Action Subsystem1'
 * '<S18>'  : 'ACC/Subsystem/Subsystem2/If Action Subsystem2'
 * '<S19>'  : 'ACC/Subsystem/Subsystem3/If Action Subsystem'
 * '<S20>'  : 'ACC/Subsystem/Subsystem3/If Action Subsystem1'
 * '<S21>'  : 'ACC/Subsystem/Subsystem3/If Action Subsystem2'
 */
#endif                                 /* RTW_HEADER_ACC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
