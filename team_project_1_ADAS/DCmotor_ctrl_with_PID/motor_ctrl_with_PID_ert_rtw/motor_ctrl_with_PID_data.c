/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motor_ctrl_with_PID_data.c
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

#include "motor_ctrl_with_PID.h"

/* Block parameters (default storage) */
P_motor_ctrl_with_PID_T motor_ctrl_with_PID_P = {
  /* Variable: Wref
   * Referenced by: '<S1>/Step2'
   */
  128.0,

  /* Variable: den_Gd
   * Referenced by: '<S2>/Discrete Transfer Fcn'
   */
  { 1073741824, -879105452 },

  /* Variable: encoder_scale
   * Referenced by: '<S2>/Gain1'
   */
  1124419809,

  /* Variable: num_Gd
   * Referenced by: '<S2>/Discrete Transfer Fcn'
   */
  { 0, 1557090975 },

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S3>/UD'
   */
  0,

  /* Expression: -1
   * Referenced by: '<S2>/Encoder'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Step2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Step2'
   */
  0.0,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S2>/Gain2'
   */
  { { 0xB4AFEC00UL, 0x4C64F59BUL } },

  /* Computed Parameter: DiscreteTransferFcn_InitialStat
   * Referenced by: '<S2>/Discrete Transfer Fcn'
   */
  0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
