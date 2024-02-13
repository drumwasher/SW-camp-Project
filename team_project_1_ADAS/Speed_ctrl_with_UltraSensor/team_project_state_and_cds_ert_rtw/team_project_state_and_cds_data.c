/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: team_project_state_and_cds_data.c
 *
 * Code generated for Simulink model 'team_project_state_and_cds'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Feb 12 18:27:06 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "team_project_state_and_cds.h"

/* Block parameters (default storage) */
P_team_project_state_and_cds_T team_project_state_and_cds_P = {
  /* Variable: KD
   * Referenced by: '<S16>/Gain3'
   */
  0.01,

  /* Variable: KI
   * Referenced by: '<S16>/Gain1'
   */
  0.2,

  /* Variable: KP
   * Referenced by: '<S16>/Gain2'
   */
  0.05,

  /* Variable: Vlim
   * Referenced by: '<S15>/Gain1'
   */
  12.0,

  /* Variable: den_Gd
   * Referenced by: '<S14>/Discrete Transfer Fcn'
   */
  { 1073741824, -879105452 },

  /* Variable: encoder_scale
   * Referenced by: '<S14>/Gain1'
   */
  1124419809,

  /* Variable: num_Gd
   * Referenced by: '<S14>/Discrete Transfer Fcn'
   */
  { 0, 1557090975 },

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S17>/UD'
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

  /* Computed Parameter: Output_Y0
   * Referenced by: '<S11>/Output'
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

  /* Expression: 2
   * Referenced by: '<S11>/Constant1'
   */
  2.0,

  /* Computed Parameter: SW2_Y0
   * Referenced by: '<S8>/SW2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S8>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S8>/Delay'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S8>/Constant1'
   */
  2.0,

  /* Expression: -1
   * Referenced by: '<S14>/Encoder'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S23>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S23>/Constant1'
   */
  0.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S18>/Out1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/가변저항'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S16>/Integrator2'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S1>/Delay'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<Root>/Constant'
   */
  100.0,

  /* Expression: 5
   * Referenced by: '<Root>/Constant3'
   */
  5.0,

  /* Expression: 100
   * Referenced by: '<Root>/Constant1'
   */
  100.0,

  /* Expression: 100
   * Referenced by: '<Root>/Constant2'
   */
  100.0,

  /* Expression: 12
   * Referenced by: '<S3>/Saturation1'
   */
  12.0,

  /* Expression: 0
   * Referenced by: '<S3>/Saturation1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S21>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S21>/Constant1'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S21>/Merge'
   */
  0.0,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S14>/Gain2'
   */
  { { 0xB4AFEC00UL, 0x4C64F59BUL } },

  /* Computed Parameter: DiscreteTransferFcn_InitialStat
   * Referenced by: '<S14>/Discrete Transfer Fcn'
   */
  0,

  /* Computed Parameter: Gain4_Gain
   * Referenced by: '<S2>/Gain4'
   */
  32768U,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S21>/Gain'
   */
  32768U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
