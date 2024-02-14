/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motor_ctrl_with_PID_data.c
 *
 * Code generated for Simulink model 'motor_ctrl_with_PID'.
 *
 * Model version                  : 1.42
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Feb 14 11:57:36 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "motor_ctrl_with_PID.h"

/* Block parameters (default storage) */
P_motor_ctrl_with_PID_T motor_ctrl_with_PID_P = {
  /* Variable: KD
   * Referenced by:
   *   '<S3>/Gain3'
   *   '<S7>/Gain3'
   */
  0.0,

  /* Variable: KI
   * Referenced by:
   *   '<S3>/Gain1'
   *   '<S7>/Gain1'
   */
  0.2,

  /* Variable: KP
   * Referenced by:
   *   '<S3>/Gain2'
   *   '<S7>/Gain2'
   */
  0.05,

  /* Variable: Vlim
   * Referenced by:
   *   '<S2>/Gain1'
   *   '<S6>/Gain1'
   */
  12.0,

  /* Variable: b
   * Referenced by: '<Root>/Constant7'
   */
  100.0,

  /* Variable: f
   * Referenced by: '<Root>/Constant4'
   */
  100.0,

  /* Variable: l
   * Referenced by: '<Root>/Constant6'
   */
  100.0,

  /* Variable: r
   * Referenced by: '<Root>/Constant8'
   */
  100.0,

  /* Variable: den_Gd
   * Referenced by:
   *   '<S1>/Discrete Transfer Fcn'
   *   '<S5>/Discrete Transfer Fcn'
   */
  { 1073741824, -879105452 },

  /* Variable: encoder_scale
   * Referenced by:
   *   '<S1>/Gain1'
   *   '<S5>/Gain1'
   */
  1124419809,

  /* Variable: num_Gd
   * Referenced by:
   *   '<S1>/Discrete Transfer Fcn'
   *   '<S5>/Discrete Transfer Fcn'
   */
  { 0, 1557090975 },

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S11>/UD'
   */
  0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_m
   * Referenced by: '<S8>/UD'
   */
  0,

  /* Expression: -1
   * Referenced by: '<S1>/Encoder'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S5>/Encoder'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/가변저항'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant10'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant9'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S7>/Integrator2'
   */
  0.0,

  /* Expression: 12
   * Referenced by: '<Root>/Saturation1'
   */
  12.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Integrator2'
   */
  0.0,

  /* Expression: 12
   * Referenced by: '<Root>/Saturation2'
   */
  12.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation2'
   */
  0.0,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S5>/Gain2'
   */
  { { 0xB4AFEC00UL, 0x4C64F59BUL } },

  /* Computed Parameter: Gain2_Gain_g
   * Referenced by: '<S1>/Gain2'
   */
  { { 0xB4AFEC00UL, 0x4C64F59BUL } },

  /* Computed Parameter: DiscreteTransferFcn_InitialStat
   * Referenced by: '<S5>/Discrete Transfer Fcn'
   */
  0,

  /* Computed Parameter: DiscreteTransferFcn_InitialSt_p
   * Referenced by: '<S1>/Discrete Transfer Fcn'
   */
  0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S4>/Gain'
   */
  32768U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
