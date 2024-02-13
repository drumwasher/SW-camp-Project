/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled_data.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Feb 10 23:01:19 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"

/* Block parameters (default storage) */
P_untitled_T untitled_P = {
  /* Variable: Kp
   * Referenced by: '<Root>/Gain2'
   */
  100.0,

  /* Variable: Ts
   * Referenced by: '<S2>/Encoder1'
   */
  0.01,

  /* Variable: Vlim
   * Referenced by:
   *   '<S1>/Gain'
   *   '<S1>/Saturation1'
   */
  12.0,

  /* Variable: Wref
   * Referenced by: '<Root>/Wref1'
   */
  100.0,

  /* Variable: den_Gd
   * Referenced by: '<S2>/Discrete Transfer Fcn'
   */
  { 1073741824, -879105452 },

  /* Variable: encoder_scale
   * Referenced by: '<S2>/mtr_rad//s'
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

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<Root>/Transfer Fcn1'
   */
  -0.0,

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<Root>/Transfer Fcn1'
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<Root>/Wref1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Wref1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Saturation1'
   */
  0.0,

  /* Computed Parameter: RPM_Gain
   * Referenced by: '<S2>/RPM'
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
