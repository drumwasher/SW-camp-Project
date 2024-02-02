/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ACC.h
 *
 * Code generated for Simulink model 'ACC'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Feb  2 17:20:40 2024
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
#include "MW_arduino_digitalio.h"
#endif                                 /* ACC_COMMON_INCLUDES_ */

#include "ACC_types.h"
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

/* Block signals (default storage) */
typedef struct {
  real_T PulseGenerator1;              /* '<Root>/Pulse Generator1' */
  real_T PulseGenerator2;              /* '<Root>/Pulse Generator2' */
  real_T PulseGenerator;               /* '<Root>/Pulse Generator' */
  real_T Merge1;                       /* '<Root>/Merge1' */
  real_T OutportBufferForOut1;         /* '<S6>/Constant' */
  real_T OutportBufferForOut1_b;       /* '<S5>/Constant2' */
} B_ACC_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/Digital Output2' */
  real_T Delay_DSTATE;                 /* '<S5>/Delay' */
  volatile real_T RateTransition1_Buffer0;/* '<Root>/Rate Transition1' */
  volatile real_T RateTransition1_Buffer1;/* '<Root>/Rate Transition1' */
  volatile real_T TmpRTBAtFunctionCallSubsystemOu;/* synthesized block */
  volatile real_T TmpRTBAtFunctionCallSubsystem_h;/* synthesized block */
  volatile real_T TmpRTBAtFunctionCallSubsystem5O;/* synthesized block */
  volatile real_T TmpRTBAtFunctionCallSubsystem_c;/* synthesized block */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  int32_T clockTickCounter;            /* '<Root>/Pulse Generator1' */
  int32_T clockTickCounter_h;          /* '<Root>/Pulse Generator2' */
  int32_T clockTickCounter_o;          /* '<Root>/Pulse Generator' */
  volatile int8_T RateTransition1_write_buf;/* '<Root>/Rate Transition1' */
  volatile int8_T RateTransition1_read_buf;/* '<Root>/Rate Transition1' */
  volatile int8_T RateTransition1_last_buf_wr;/* '<Root>/Rate Transition1' */
  volatile int8_T TmpRTBAtFunctionCallSubsystem_i;/* synthesized block */
  volatile int8_T TmpRTBAtFunctionCallSubsystem_a;/* synthesized block */
  volatile int8_T TmpRTBAtFunctionCallSubsystem_e;/* synthesized block */
  volatile int8_T TmpRTBAtFunctionCallSubsyste_ag;/* synthesized block */
  volatile int8_T TmpRTBAtFunctionCallSubsyste_h4;/* synthesized block */
  volatile int8_T TmpRTBAtFunctionCallSubsystem_f;/* synthesized block */
  int8_T ACCoff2_SubsysRanBC;          /* '<Root>/ACC off2' */
  int8_T ACCon_SubsysRanBC;            /* '<Root>/ACC on' */
  int8_T ACCstandby_SubsysRanBC;       /* '<Root>/ACC standby' */
  int8_T ACCoff1_SubsysRanBC;          /* '<Root>/ACC off1' */
  int8_T FunctionCallSubsystem5_SubsysRa;/* '<Root>/Function-Call Subsystem5' */
  int8_T FunctionCallSubsystem_SubsysRan;/* '<Root>/Function-Call Subsystem' */
} DW_ACC_T;

/* Parameters (default storage) */
struct P_ACC_T_ {
  real_T Out2_Y0;                      /* Computed Parameter: Out2_Y0
                                        * Referenced by: '<S5>/Out2'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S5>/Delay'
                                        */
  real_T Constant_Value;               /* Expression: 3
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Constant_Value_j;             /* Expression: 1
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant_Value_o3;            /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value_n;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T DataStoreMemory_InitialValue; /* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory'
                                        */
  real_T RateTransition1_InitialConditio;/* Expression: 0
                                          * Referenced by: '<Root>/Rate Transition1'
                                          */
  real_T TmpRTBAtFunctionCallSubsystemOu;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpRTBAtFunctionCallSubsystem5O;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Constant2_Value_m;            /* Expression: 2
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T PulseGenerator1_Amp;          /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period;   /* Computed Parameter: PulseGenerator1_Period
                                    * Referenced by: '<Root>/Pulse Generator1'
                                    */
  real_T PulseGenerator1_Duty;       /* Computed Parameter: PulseGenerator1_Duty
                                      * Referenced by: '<Root>/Pulse Generator1'
                                      */
  real_T PulseGenerator1_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator1'
                                        */
  real_T PulseGenerator2_Amp;          /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_Period;   /* Computed Parameter: PulseGenerator2_Period
                                    * Referenced by: '<Root>/Pulse Generator2'
                                    */
  real_T PulseGenerator2_Duty;       /* Computed Parameter: PulseGenerator2_Duty
                                      * Referenced by: '<Root>/Pulse Generator2'
                                      */
  real_T PulseGenerator2_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator2'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<Root>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<Root>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
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
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/If1' : Unused code path elimination
 * Block '<Root>/Rate Transition2' : Eliminated since input and output rates are identical
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
 * '<Root>' : 'ACC'
 * '<S1>'   : 'ACC/ACC off1'
 * '<S2>'   : 'ACC/ACC off2'
 * '<S3>'   : 'ACC/ACC on'
 * '<S4>'   : 'ACC/ACC standby'
 * '<S5>'   : 'ACC/Function-Call Subsystem'
 * '<S6>'   : 'ACC/Function-Call Subsystem5'
 */
#endif                                 /* RTW_HEADER_ACC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
