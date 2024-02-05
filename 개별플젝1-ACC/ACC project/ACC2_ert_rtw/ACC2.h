/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ACC2.h
 *
 * Code generated for Simulink model 'ACC2'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Feb  5 15:38:00 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ACC2_h_
#define RTW_HEADER_ACC2_h_
#ifndef ACC2_COMMON_INCLUDES_
#define ACC2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduinoextint.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#include "MW_Ultrasonic.h"
#endif                                 /* ACC2_COMMON_INCLUDES_ */

#include "ACC2_types.h"
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
  real_T Merge;                        /* '<S4>/Merge' */
  real_T Merge_e;                      /* '<S5>/Merge' */
} B_ACC2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input1' */
  codertarget_arduinobase_inter_T obj_p;/* '<Root>/Analog Input' */
  codertarget_arduinobase_block_T obj_h;/* '<Root>/Digital Output4' */
  codertarget_arduinobase_block_T obj_g;/* '<Root>/Digital Output' */
  codertarget_arduinobase_int_e_T obj_e;/* '<Root>/PWM2' */
  codertarget_arduinobase_int_e_T obj_eu;/* '<Root>/PWM1' */
  codertarget_arduinobase_int_e_T obj_l;/* '<Root>/PWM' */
  real_T Delay_DSTATE;                 /* '<S12>/Delay' */
  real_T Delay_DSTATE_l;               /* '<S11>/Delay' */
  volatile real_T TmpRTBAtFunctionCallSubsystem4O;/* synthesized block */
  volatile real_T TmpRTBAtFunctionCallSubsystem_e;/* synthesized block */
  volatile real_T TmpRTBAtFunctionCallSubsystem6O;/* synthesized block */
  volatile real_T TmpRTBAtFunctionCallSubsystem_a;/* synthesized block */
  real_T a;                            /* '<S3>/Chart' */
  real_T v1;                           /* '<S2>/Chart' */
  real_T v2;                           /* '<S2>/Chart' */
  codertarget_arduinobase_in_ee_T obj_lm;/* '<Root>/Ultrasonic Sensor' */
  int32_T clockTickCounter;            /* '<S4>/Pulse Generator' */
  int32_T clockTickCounter_k;          /* '<S2>/Pulse Generator6' */
  int32_T clockTickCounter_b;          /* '<S2>/Pulse Generator7' */
  int32_T clockTickCounter_j;          /* '<S5>/Pulse Generator' */
  int32_T clockTickCounter_o;          /* '<S5>/Pulse Generator1' */
  volatile int8_T TmpRTBAtFunctionCallSubsystem_f;/* synthesized block */
  volatile int8_T TmpRTBAtFunctionCallSubsystem_o;/* synthesized block */
  volatile int8_T TmpRTBAtFunctionCallSubsystem_c;/* synthesized block */
  volatile int8_T TmpRTBAtFunctionCallSubsystem_n;/* synthesized block */
  volatile int8_T TmpRTBAtFunctionCallSubsyste_ff;/* synthesized block */
  volatile int8_T TmpRTBAtFunctionCallSubsystem_k;/* synthesized block */
  uint8_T is_active_c1_ACC2;           /* '<S3>/Chart' */
  uint8_T is_c1_ACC2;                  /* '<S3>/Chart' */
  uint8_T is_active_c3_ACC2;           /* '<S2>/Chart' */
  uint8_T is_c3_ACC2;                  /* '<S2>/Chart' */
} DW_ACC2_T;

/* Parameters (default storage) */
struct P_ACC2_T_ {
  real_T AnalogInput_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  real_T sw1_Y0;                       /* Computed Parameter: sw1_Y0
                                        * Referenced by: '<S11>/sw1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S11>/Delay'
                                        */
  real_T sw2_Y0;                       /* Computed Parameter: sw2_Y0
                                        * Referenced by: '<S12>/sw2'
                                        */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T Delay_InitialCondition_n;     /* Expression: 0.0
                                        * Referenced by: '<S12>/Delay'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Constant1_Value_f;            /* Expression: 0
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Constant1_Value_e;            /* Expression: 0
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
  real_T Constant_Value_oi;            /* Expression: 1
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
  real_T Constant1_Value_c;            /* Expression: 2
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Constant_Value_f;             /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant_Value_fw;            /* Expression: 0
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T PulseGenerator_Amp_l;         /* Expression: 1
                                        * Referenced by: '<S5>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period_l; /* Computed Parameter: PulseGenerator_Period_l
                                   * Referenced by: '<S5>/Pulse Generator'
                                   */
  real_T PulseGenerator_Duty_k;     /* Computed Parameter: PulseGenerator_Duty_k
                                     * Referenced by: '<S5>/Pulse Generator'
                                     */
  real_T PulseGenerator_PhaseDelay_b;  /* Expression: 0
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
  real_T Constant_Value_kz;            /* Expression: 0
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Constant2_Value_f;            /* Expression: 500
                                        * Referenced by: '<S6>/Constant2'
                                        */
  uint16_T Gain_Gain_o;                /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<S3>/Gain'
                                        */
  uint8_T Gain_Gain_f;                 /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S6>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ACC2_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_ACC2_T ACC2_P;

/* Block signals (default storage) */
extern B_ACC2_T ACC2_B;

/* Block states (default storage) */
extern DW_ACC2_T ACC2_DW;

/* Model entry point functions */
extern void ACC2_initialize(void);
extern void ACC2_step(void);
extern void ACC2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ACC2_T *const ACC2_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Display' : Unused code path elimination
 * Block '<S2>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S6>/Abs' : Eliminated since data is unsigned
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
 * '<Root>' : 'ACC2'
 * '<S1>'   : 'ACC2/Subsystem'
 * '<S2>'   : 'ACC2/Subsystem/Subsystem'
 * '<S3>'   : 'ACC2/Subsystem/Subsystem1'
 * '<S4>'   : 'ACC2/Subsystem/Subsystem2'
 * '<S5>'   : 'ACC2/Subsystem/Subsystem3'
 * '<S6>'   : 'ACC2/Subsystem/Subsystem4'
 * '<S7>'   : 'ACC2/Subsystem/Subsystem/ACC off5'
 * '<S8>'   : 'ACC2/Subsystem/Subsystem/ACC on2'
 * '<S9>'   : 'ACC2/Subsystem/Subsystem/ACC standby2'
 * '<S10>'  : 'ACC2/Subsystem/Subsystem/Chart'
 * '<S11>'  : 'ACC2/Subsystem/Subsystem/Function-Call Subsystem4'
 * '<S12>'  : 'ACC2/Subsystem/Subsystem/Function-Call Subsystem6'
 * '<S13>'  : 'ACC2/Subsystem/Subsystem1/Chart'
 * '<S14>'  : 'ACC2/Subsystem/Subsystem1/If Action Subsystem'
 * '<S15>'  : 'ACC2/Subsystem/Subsystem1/If Action Subsystem1'
 * '<S16>'  : 'ACC2/Subsystem/Subsystem1/If Action Subsystem2'
 * '<S17>'  : 'ACC2/Subsystem/Subsystem2/If Action Subsystem'
 * '<S18>'  : 'ACC2/Subsystem/Subsystem2/If Action Subsystem1'
 * '<S19>'  : 'ACC2/Subsystem/Subsystem2/If Action Subsystem2'
 * '<S20>'  : 'ACC2/Subsystem/Subsystem3/If Action Subsystem'
 * '<S21>'  : 'ACC2/Subsystem/Subsystem3/If Action Subsystem1'
 * '<S22>'  : 'ACC2/Subsystem/Subsystem3/If Action Subsystem2'
 * '<S23>'  : 'ACC2/Subsystem/Subsystem4/If Action Subsystem'
 * '<S24>'  : 'ACC2/Subsystem/Subsystem4/If Action Subsystem1'
 */
#endif                                 /* RTW_HEADER_ACC2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
