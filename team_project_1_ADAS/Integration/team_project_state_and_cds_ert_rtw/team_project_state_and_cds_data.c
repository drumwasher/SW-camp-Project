/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: team_project_state_and_cds_data.c
 *
 * Code generated for Simulink model 'team_project_state_and_cds'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Feb 12 20:23:15 2024
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
   * Referenced by: '<S22>/Gain3'
   */
  0.01,

  /* Variable: KI
   * Referenced by: '<S22>/Gain1'
   */
  0.2,

  /* Variable: KP
   * Referenced by: '<S22>/Gain2'
   */
  0.05,

  /* Variable: Vlim
   * Referenced by: '<S21>/Gain1'
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
   * Referenced by: '<S20>/Discrete Transfer Fcn'
   */
  { 1073741824, -879105452 },

  /* Variable: encoder_scale
   * Referenced by: '<S20>/Gain1'
   */
  1124419809,

  /* Variable: num_Gd
   * Referenced by: '<S20>/Discrete Transfer Fcn'
   */
  { 0, 1557090975 },

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S23>/UD'
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
   * Referenced by: '<S17>/Output'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S17>/Constant'
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: '<S17>/Delay'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S17>/Constant1'
   */
  2.0,

  /* Computed Parameter: sw2_Y0
   * Referenced by: '<S14>/sw2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S14>/Constant2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S14>/Delay1'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S14>/Constant3'
   */
  2.0,

  /* Expression: -1
   * Referenced by: '<S20>/Encoder'
   */
  -1.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S24>/Out1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S24>/Constant'
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: '<S24>/Delay'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<S24>/Constant1'
   */
  3.0,

  /* Expression: 1
   * Referenced by: '<S29>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S29>/Constant1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/가변저항'
   */
  -1.0,

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S3>/Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<S1>/Pulse Generator'
   */
  200.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<S1>/Pulse Generator'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S1>/Pulse Generator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S22>/Integrator2'
   */
  0.0,

  /* Expression: 12
   * Referenced by: '<S5>/Saturation1'
   */
  12.0,

  /* Expression: 0
   * Referenced by: '<S5>/Saturation1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S27>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S27>/Constant1'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S27>/Merge'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant4'
   */
  1.0,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S20>/Gain2'
   */
  { { 0xB4AFEC00UL, 0x4C64F59BUL } },

  /* Computed Parameter: DiscreteTransferFcn_InitialStat
   * Referenced by: '<S20>/Discrete Transfer Fcn'
   */
  0,

  /* Computed Parameter: Gain4_Gain
   * Referenced by: '<S4>/Gain4'
   */
  32768U,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S27>/Gain'
   */
  32768U,

  /* Start of '<S2>/If Action Subsystem3' */
  {
    /* Expression: 0
     * Referenced by: '<S10>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S2>/If Action Subsystem3' */

  /* Start of '<S2>/If Action Subsystem1' */
  {
    /* Expression: 1
     * Referenced by: '<S9>/Constant'
     */
    1.0
  }
  /* End of '<S2>/If Action Subsystem1' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
