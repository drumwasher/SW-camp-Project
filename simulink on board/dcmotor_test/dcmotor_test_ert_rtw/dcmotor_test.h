/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: dcmotor_test.h
 *
 * Code generated for Simulink model 'dcmotor_test'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Feb  1 15:47:36 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_dcmotor_test_h_
#define RTW_HEADER_dcmotor_test_h_
#ifndef dcmotor_test_COMMON_INCLUDES_
#define dcmotor_test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduinoextint.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                                 /* dcmotor_test_COMMON_INCLUDES_ */

#include "dcmotor_test_types.h"
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

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input' */
  codertarget_arduinobase_block_T obj_m;/* '<Root>/Digital Output' */
  codertarget_arduinobase_int_f_T obj_b;/* '<Root>/PWM' */
  boolean_T Delay_DSTATE;              /* '<S2>/Delay' */
} DW_dcmotor_test_T;

/* Parameters (default storage) */
struct P_dcmotor_test_T_ {
  real_T AnalogInput_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
  boolean_T Out1_Y0;                   /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S2>/Out1'
                                        */
  boolean_T Delay_InitialCondition;/* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S2>/Delay'
                                    */
};

/* Real-time Model Data Structure */
struct tag_RTM_dcmotor_test_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_dcmotor_test_T dcmotor_test_P;

/* Block states (default storage) */
extern DW_dcmotor_test_T dcmotor_test_DW;

/* Model entry point functions */
extern void dcmotor_test_initialize(void);
extern void dcmotor_test_step(void);
extern void dcmotor_test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_dcmotor_test_T *const dcmotor_test_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
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
 * '<Root>' : 'dcmotor_test'
 * '<S1>'   : 'dcmotor_test/Chart'
 * '<S2>'   : 'dcmotor_test/Function-Call Subsystem'
 */
#endif                                 /* RTW_HEADER_dcmotor_test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
