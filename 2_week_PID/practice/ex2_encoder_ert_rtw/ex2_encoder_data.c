/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ex2_encoder_data.c
 *
 * Code generated for Simulink model 'ex2_encoder'.
 *
 * Model version                  : 1.31
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Feb 11 15:59:07 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ex2_encoder.h"

/* Block parameters (default storage) */
P_ex2_encoder_T ex2_encoder_P = {
  /* Variable: KD
   * Referenced by: '<S3>/Gain6'
   */
  0.5,

  /* Variable: KI
   * Referenced by: '<S3>/Gain4'
   */
  0.1,

  /* Variable: KP
   * Referenced by: '<S3>/Gain5'
   */
  0.7,

  /* Variable: Vlim
   * Referenced by: '<S2>/Gain1'
   */
  12.0,

  /* Variable: den_Gd
   * Referenced by: '<S1>/Discrete Transfer Fcn'
   */
  { 1073741824, -879105452 },

  /* Variable: encoder_scale
   * Referenced by: '<S1>/Gain1'
   */
  1124419809,

  /* Variable: num_Gd
   * Referenced by: '<S1>/Discrete Transfer Fcn'
   */
  { 0, 1557090975 },

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S4>/UD'
   */
  0,

  /* Expression: -1
   * Referenced by: '<Root>/Analog Input'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Encoder'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S3>/Integrator1'
   */
  0.0,

  /* Expression: 12
   * Referenced by: '<Root>/Saturation'
   */
  12.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation'
   */
  0.0,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S1>/Gain2'
   */
  { { 0xB4AFEC00UL, 0x4C64F59BUL } },

  /* Computed Parameter: DiscreteTransferFcn_InitialStat
   * Referenced by: '<S1>/Discrete Transfer Fcn'
   */
  0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<Root>/Gain'
   */
  32768U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
