/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pr2_US_hap_data.c
 *
 * Code generated for Simulink model 'pr2_US_hap'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Feb 12 19:19:53 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pr2_US_hap.h"

/* Block parameters (default storage) */
P_pr2_US_hap_T pr2_US_hap_P = {
  /* Variable: KI
   * Referenced by: '<S7>/Gain4'
   */
  0.2,

  /* Variable: KP
   * Referenced by: '<S7>/Gain5'
   */
  0.05,

  /* Variable: Vlim
   * Referenced by: '<S5>/Gain1'
   */
  12.0,

  /* Variable: Wref
   * Referenced by:
   *   '<S6>/Step1'
   *   '<S8>/Step1'
   */
  435.0,

  /* Variable: b
   * Referenced by: '<Root>/Constant2'
   */
  100.0,

  /* Variable: f
   * Referenced by: '<Root>/Constant3'
   */
  100.0,

  /* Variable: l
   * Referenced by: '<Root>/Constant'
   */
  100.0,

  /* Variable: r
   * Referenced by: '<Root>/Constant1'
   */
  100.0,

  /* Variable: den_Gd
   * Referenced by: '<S4>/Discrete Transfer Fcn'
   */
  { 1073741824, -879105452 },

  /* Variable: encoder_scale
   * Referenced by: '<S4>/Gain1'
   */
  1124419809,

  /* Variable: num_Gd
   * Referenced by: '<S4>/Discrete Transfer Fcn'
   */
  { 0, 1557090975 },

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S11>/UD'
   */
  0,

  /* Computed Parameter: sw1_Y0
   * Referenced by: '<S1>/sw1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: '<S1>/Delay'
   */
  0.0,

  /* Computed Parameter: sw1_Y0_e
   * Referenced by: '<S2>/sw1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/Constant'
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: '<S2>/Delay'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S4>/Encoder'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/가변저항'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S7>/Integrator1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S6>/Step1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S6>/Step1'
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 128
   * Referenced by: '<S6>/Constant'
   */
  128.0,

  /* Expression: 6.4
   * Referenced by: '<S6>/Constant1'
   */
  6.4,

  /* Expression: 100
   * Referenced by: '<S6>/Constant2'
   */
  100.0,

  /* Expression: 12
   * Referenced by: '<Root>/Saturation'
   */
  12.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation'
   */
  0.0,

  /* Expression: 128
   * Referenced by: '<S8>/Constant'
   */
  128.0,

  /* Expression: 6.4
   * Referenced by: '<S8>/Constant1'
   */
  6.4,

  /* Expression: 100
   * Referenced by: '<S8>/Constant2'
   */
  100.0,

  /* Expression: 1
   * Referenced by: '<S8>/Step1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S8>/Step1'
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S4>/Gain2'
   */
  { { 0xB4AFEC00UL, 0x4C64F59BUL } },

  /* Computed Parameter: DiscreteTransferFcn_InitialStat
   * Referenced by: '<S4>/Discrete Transfer Fcn'
   */
  0,

  /* Computed Parameter: Gain4_Gain
   * Referenced by: '<S3>/Gain4'
   */
  32768U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
