/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motor_ctrl_with_PID.h
 *
 * Code generated for Simulink model 'motor_ctrl_with_PID'.
 *
 * Model version                  : 1.32
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Feb 10 22:03:59 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_motor_ctrl_with_PID_h_
#define RTW_HEADER_motor_ctrl_with_PID_h_
#ifndef motor_ctrl_with_PID_COMMON_INCLUDES_
#define motor_ctrl_with_PID_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_PWM.h"
#include "MW_ArduinoEncoder.h"
#endif                                /* motor_ctrl_with_PID_COMMON_INCLUDES_ */

#include "motor_ctrl_with_PID_types.h"
#include "multiword_types.h"
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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  int128m_T Gain2;                     /* '<S2>/Gain2' */
  int128m_T r;
  int96m_T r1;
  int96m_T r2;
  int96m_T r3;
  int96m_T r4;
  int64m_T Gain1;                      /* '<S2>/Gain1' */
  int64m_T DiscreteTransferFcn;        /* '<S2>/Discrete Transfer Fcn' */
  int32_T DataTypeConversion1;         /* '<S2>/Data Type Conversion1' */
  uint8_T DataTypeConversion;          /* '<S1>/Data Type Conversion' */
} B_motor_ctrl_with_PID_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_i_T obj; /* '<S2>/Encoder' */
  codertarget_arduinobase_inter_T obj_o;/* '<S1>/PWM' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S1>/Scope1' */

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<S1>/Scope5' */

  int32_T DiscreteTransferFcn_states;  /* '<S2>/Discrete Transfer Fcn' */
  int32_T UD_DSTATE;                   /* '<S3>/UD' */
} DW_motor_ctrl_with_PID_T;

/* Parameters (default storage) */
struct P_motor_ctrl_with_PID_T_ {
  real_T Wref;                         /* Variable: Wref
                                        * Referenced by: '<S1>/Step2'
                                        */
  int32_T den_Gd[2];                   /* Variable: den_Gd
                                        * Referenced by: '<S2>/Discrete Transfer Fcn'
                                        */
  int32_T encoder_scale;               /* Variable: encoder_scale
                                        * Referenced by: '<S2>/Gain1'
                                        */
  int32_T num_Gd[2];                   /* Variable: num_Gd
                                        * Referenced by: '<S2>/Discrete Transfer Fcn'
                                        */
  int32_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S3>/UD'
                               */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S2>/Encoder'
                                        */
  real_T Step2_Time;                   /* Expression: 1
                                        * Referenced by: '<S1>/Step2'
                                        */
  real_T Step2_Y0;                     /* Expression: 0
                                        * Referenced by: '<S1>/Step2'
                                        */
  int64m_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S2>/Gain2'
                                        */
  int32_T DiscreteTransferFcn_InitialStat;
                          /* Computed Parameter: DiscreteTransferFcn_InitialStat
                           * Referenced by: '<S2>/Discrete Transfer Fcn'
                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_motor_ctrl_with_PID_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

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
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_motor_ctrl_with_PID_T motor_ctrl_with_PID_P;

/* Block signals (default storage) */
extern B_motor_ctrl_with_PID_T motor_ctrl_with_PID_B;

/* Block states (default storage) */
extern DW_motor_ctrl_with_PID_T motor_ctrl_with_PID_DW;

/* Model entry point functions */
extern void motor_ctrl_with_PID_initialize(void);
extern void motor_ctrl_with_PID_step(void);
extern void motor_ctrl_with_PID_terminate(void);

/* Real-time Model object */
extern RT_MODEL_motor_ctrl_with_PID_T *const motor_ctrl_with_PID_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Data Type Duplicate' : Unused code path elimination
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
 * '<Root>' : 'motor_ctrl_with_PID'
 * '<S1>'   : 'motor_ctrl_with_PID/Subsystem2'
 * '<S2>'   : 'motor_ctrl_with_PID/Subsystem2/Subsystem2'
 * '<S3>'   : 'motor_ctrl_with_PID/Subsystem2/Subsystem2/Discrete Derivative'
 */
#endif                                 /* RTW_HEADER_motor_ctrl_with_PID_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
