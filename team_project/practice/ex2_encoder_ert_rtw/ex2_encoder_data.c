/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ex2_encoder_data.c
 *
 * Code generated for Simulink model 'ex2_encoder'.
 *
 * Model version                  : 1.20
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Feb  7 17:17:19 2024
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

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S4>/UD'
   */
  0,

  /* Expression: -1
   * Referenced by: '<S1>/Encoder'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Step'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<Root>/Step'
   */
  100.0,

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

  /* Expression: 255/12
   * Referenced by: '<S2>/Gain1'
   */
  21.25,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S1>/Gain2'
   */
  { { 0xB4AFEC00UL, 0x4C64F59BUL } },

  /* Computed Parameter: Gain1_Gain_n
   * Referenced by: '<S1>/Gain1'
   */
  1124419809
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
