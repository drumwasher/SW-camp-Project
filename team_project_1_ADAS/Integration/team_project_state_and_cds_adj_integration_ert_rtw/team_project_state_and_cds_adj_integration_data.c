/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: team_project_state_and_cds_adj_integration_data.c
 *
 * Code generated for Simulink model 'team_project_state_and_cds_adj_integration'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Feb 13 17:19:22 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "team_project_state_and_cds_adj_integration.h"

/* Block parameters (default storage) */
P_team_project_state_and_cds__T team_project_state_and_cds_ad_P = {
  /* Variable: KI
   * Referenced by: '<S15>/Gain1'
   */
  0.2,

  /* Variable: KP
   * Referenced by: '<S15>/Gain2'
   */
  0.05,

  /* Variable: Vlim
   * Referenced by: '<S14>/Gain1'
   */
  12.0,

  /* Variable: b
   * Referenced by: '<Root>/Constant2'
   */
  100.0,

  /* Variable: f
   * Referenced by: '<Root>/Constant'
   */
  100.0,

  /* Variable: l
   * Referenced by: '<Root>/Constant3'
   */
  100.0,

  /* Variable: r
   * Referenced by: '<Root>/Constant1'
   */
  100.0,

  /* Variable: den_Gd
   * Referenced by: '<S13>/Discrete Transfer Fcn'
   */
  { 1073741824, -879105452 },

  /* Variable: encoder_scale
   * Referenced by: '<S13>/Gain1'
   */
  1124419809,

  /* Variable: num_Gd
   * Referenced by: '<S13>/Discrete Transfer Fcn'
   */
  { 0, 1557090975 },

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S16>/UD'
   */
  0,

  /* Expression: -1
   * Referenced by: '<Root>/Analog Input1'
   */
  -1.0,

  /* Expression: 0.1
   * Referenced by: '<Root>/Digital Input'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<Root>/Digital Input1'
   */
  0.1,

  /* Computed Parameter: Output_Y0
   * Referenced by: '<S10>/Output'
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

  /* Expression: 2
   * Referenced by: '<S10>/Constant1'
   */
  2.0,

  /* Computed Parameter: sw2_Y0
   * Referenced by: '<S7>/sw2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S7>/Constant2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S7>/Delay1'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S7>/Constant3'
   */
  2.0,

  /* Expression: -1
   * Referenced by: '<S13>/Encoder'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/가변저항'
   */
  -1.0,

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S1>/Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S15>/Integrator2'
   */
  0.0,

  /* Expression: 12
   * Referenced by: '<S3>/Saturation1'
   */
  12.0,

  /* Expression: 0
   * Referenced by: '<S3>/Saturation1'
   */
  0.0,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S13>/Gain2'
   */
  { { 0xB4AFEC00UL, 0x4C64F59BUL } },

  /* Computed Parameter: DiscreteTransferFcn_InitialStat
   * Referenced by: '<S13>/Discrete Transfer Fcn'
   */
  0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S2>/Gain'
   */
  32768U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
