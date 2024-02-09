/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.h
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Feb  5 09:34:41 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_untitled_h_
#define RTW_HEADER_untitled_h_
#ifndef untitled_COMMON_INCLUDES_
#define untitled_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduinoextint.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#include "MW_Ultrasonic.h"
#endif                                 /* untitled_COMMON_INCLUDES_ */

#include "untitled_types.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T PulseGenerator;               /* '<S4>/Pulse Generator' */
  real_T Merge;                        /* '<S4>/Merge' */
  real_T PulseGenerator6;              /* '<S2>/Pulse Generator6' */
  real_T PulseGenerator7;              /* '<S2>/Pulse Generator7' */
} B_untitled_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input' */
  codertarget_arduinobase_block_T obj_h;/* '<Root>/Digital Output4' */
  codertarget_arduinobase_block_T obj_g;/* '<Root>/Digital Output' */
  codertarget_arduinobase_int_b_T obj_b;/* '<Root>/PWM' */
  real_T Delay_DSTATE;                 /* '<S10>/Delay' */
  real_T Delay_DSTATE_m;               /* '<S9>/Delay' */
  volatile real_T TmpRTBAtFunctionCallSubsystem4O;/* synthesized block */
  volatile real_T TmpRTBAtFunctionCallSubsystem_e;/* synthesized block */
  volatile real_T TmpRTBAtFunctionCallSubsystem6O;/* synthesized block */
  volatile real_T TmpRTBAtFunctionCallSubsystem_a;/* synthesized block */
  real_T a;                            /* '<S3>/Chart' */
  real_T v1;                           /* '<S2>/Chart' */
  real_T v2;                           /* '<S2>/Chart' */
  codertarget_arduinobase_in_b5_T obj_m;/* '<Root>/Ultrasonic Sensor' */
  int32_T clockTickCounter;            /* '<S4>/Pulse Generator' */
  int32_T clockTickCounter_g;          /* '<S2>/Pulse Generator6' */
  int32_T clockTickCounter_k;          /* '<S2>/Pulse Generator7' */
  volatile int8_T TmpRTBAtFunctionCallSubsystem_f;/* synthesized block */
  volatile int8_T TmpRTBAtFunctionCallSubsystem_o;/* synthesized block */
  volatile int8_T TmpRTBAtFunctionCallSubsystem_c;/* synthesized block */
  volatile int8_T TmpRTBAtFunctionCallSubsystem_n;/* synthesized block */
  volatile int8_T TmpRTBAtFunctionCallSubsyste_ff;/* synthesized block */
  volatile int8_T TmpRTBAtFunctionCallSubsystem_k;/* synthesized block */
  uint8_T is_active_c1_untitled;       /* '<S3>/Chart' */
  uint8_T is_c1_untitled;              /* '<S3>/Chart' */
  uint8_T is_active_c3_untitled;       /* '<S2>/Chart' */
  uint8_T is_c3_untitled;              /* '<S2>/Chart' */
} DW_untitled_T;

/* Parameters (default storage) */
struct P_untitled_T_ {
  real_T AnalogInput_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T sw1_Y0;                       /* Computed Parameter: sw1_Y0
                                        * Referenced by: '<S9>/sw1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S9>/Delay'
                                        */
  real_T sw2_Y0;                       /* Computed Parameter: sw2_Y0
                                        * Referenced by: '<S10>/sw2'
                                        */
  real_T Constant_Value_m;             /* Expression: 1
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Delay_InitialCondition_f;     /* Expression: 0.0
                                        * Referenced by: '<S10>/Delay'
                                        */
  real_T Constant_Value_e;             /* Expression: 1
                                        * Referenced by: '<S6>/Constant'
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
  real_T Constant_Value_mh;            /* Expression: 1
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
  real_T Constant1_Value_f;            /* Expression: 2
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Constant_Value_b;             /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  uint16_T Gain_Gain_j;                /* Computed Parameter: Gain_Gain_j
                                        * Referenced by: '<S3>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_untitled_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[4];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_untitled_T untitled_P;

/* Block signals (default storage) */
extern B_untitled_T untitled_B;

/* Block states (default storage) */
extern DW_untitled_T untitled_DW;

/* Model entry point functions */
extern void untitled_initialize(void);
extern void untitled_step(void);
extern void untitled_terminate(void);

/* Real-time Model object */
extern RT_MODEL_untitled_T *const untitled_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Display' : Unused code path elimination
 * Block '<S2>/Rate Transition' : Eliminated since input and output rates are identical
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
 * '<Root>' : 'untitled'
 * '<S1>'   : 'untitled/Subsystem'
 * '<S2>'   : 'untitled/Subsystem/Subsystem'
 * '<S3>'   : 'untitled/Subsystem/Subsystem1'
 * '<S4>'   : 'untitled/Subsystem/Subsystem2'
 * '<S5>'   : 'untitled/Subsystem/Subsystem/ACC off5'
 * '<S6>'   : 'untitled/Subsystem/Subsystem/ACC on2'
 * '<S7>'   : 'untitled/Subsystem/Subsystem/ACC standby2'
 * '<S8>'   : 'untitled/Subsystem/Subsystem/Chart'
 * '<S9>'   : 'untitled/Subsystem/Subsystem/Function-Call Subsystem4'
 * '<S10>'  : 'untitled/Subsystem/Subsystem/Function-Call Subsystem6'
 * '<S11>'  : 'untitled/Subsystem/Subsystem1/Chart'
 * '<S12>'  : 'untitled/Subsystem/Subsystem1/If Action Subsystem'
 * '<S13>'  : 'untitled/Subsystem/Subsystem1/If Action Subsystem1'
 * '<S14>'  : 'untitled/Subsystem/Subsystem1/If Action Subsystem2'
 * '<S15>'  : 'untitled/Subsystem/Subsystem2/If Action Subsystem'
 * '<S16>'  : 'untitled/Subsystem/Subsystem2/If Action Subsystem1'
 * '<S17>'  : 'untitled/Subsystem/Subsystem2/If Action Subsystem2'
 */
#endif                                 /* RTW_HEADER_untitled_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
