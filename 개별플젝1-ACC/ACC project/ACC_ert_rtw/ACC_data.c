/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ACC_data.c
 *
 * Code generated for Simulink model 'ACC'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Feb  3 22:36:17 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ACC.h"

/* Block parameters (default storage) */
P_ACC_T ACC_P = {
  /* Expression: -1
   * Referenced by: '<Root>/Analog Input'
   */
  -1.0,

  /* Computed Parameter: sw1_Y0
   * Referenced by: '<S9>/sw1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S9>/Constant'
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: '<S9>/Delay'
   */
  0.0,

  /* Computed Parameter: sw2_Y0
   * Referenced by: '<S10>/sw2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S10>/Constant'
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: '<S10>/Delay'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S6>/Constant'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<S4>/Gain'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S4>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<S4>/Pulse Generator'
   */
  2.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<S4>/Pulse Generator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Pulse Generator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S4>/Constant3'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S4>/Constant'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S4>/Constant2'
   */
  2.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/Pulse Generator6'
   */
  1.0,

  /* Computed Parameter: PulseGenerator6_Period
   * Referenced by: '<S2>/Pulse Generator6'
   */
  2.0,

  /* Computed Parameter: PulseGenerator6_Duty
   * Referenced by: '<S2>/Pulse Generator6'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Pulse Generator6'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/Pulse Generator7'
   */
  1.0,

  /* Computed Parameter: PulseGenerator7_Period
   * Referenced by: '<S2>/Pulse Generator7'
   */
  2.0,

  /* Computed Parameter: PulseGenerator7_Duty
   * Referenced by: '<S2>/Pulse Generator7'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Pulse Generator7'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S3>/Constant1'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S3>/Constant'
   */
  0.0,

  /* Computed Parameter: Gain_Gain_f
   * Referenced by: '<S3>/Gain'
   */
  32768U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
