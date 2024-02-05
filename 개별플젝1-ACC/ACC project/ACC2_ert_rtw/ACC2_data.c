/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ACC2_data.c
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

#include "ACC2.h"

/* Block parameters (default storage) */
P_ACC2_T ACC2_P = {
  /* Expression: -1
   * Referenced by: '<Root>/Analog Input'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Analog Input1'
   */
  -1.0,

  /* Computed Parameter: sw1_Y0
   * Referenced by: '<S11>/sw1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S11>/Constant'
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: '<S11>/Delay'
   */
  0.0,

  /* Computed Parameter: sw2_Y0
   * Referenced by: '<S12>/sw2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S12>/Constant'
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: '<S12>/Delay'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S8>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S5>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Constant1'
   */
  0.0,

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
  40.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<S4>/Pulse Generator'
   */
  20.0,

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
  40.0,

  /* Computed Parameter: PulseGenerator6_Duty
   * Referenced by: '<S2>/Pulse Generator6'
   */
  20.0,

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
  200.0,

  /* Computed Parameter: PulseGenerator7_Duty
   * Referenced by: '<S2>/Pulse Generator7'
   */
  100.0,

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

  /* Expression: 0
   * Referenced by: '<S5>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S5>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period_l
   * Referenced by: '<S5>/Pulse Generator'
   */
  200.0,

  /* Computed Parameter: PulseGenerator_Duty_k
   * Referenced by: '<S5>/Pulse Generator'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S5>/Pulse Generator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S5>/Pulse Generator1'
   */
  1.0,

  /* Computed Parameter: PulseGenerator1_Period
   * Referenced by: '<S5>/Pulse Generator1'
   */
  40.0,

  /* Computed Parameter: PulseGenerator1_Duty
   * Referenced by: '<S5>/Pulse Generator1'
   */
  20.0,

  /* Expression: 0
   * Referenced by: '<S5>/Pulse Generator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Constant'
   */
  0.0,

  /* Expression: 500
   * Referenced by: '<S6>/Constant2'
   */
  500.0,

  /* Computed Parameter: Gain_Gain_o
   * Referenced by: '<S3>/Gain'
   */
  32768U,

  /* Computed Parameter: Gain_Gain_f
   * Referenced by: '<S6>/Gain'
   */
  128U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
