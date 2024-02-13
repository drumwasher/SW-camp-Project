/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: team_project_state_and_cds_data.c
 *
 * Code generated for Simulink model 'team_project_state_and_cds'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Feb 12 16:58:36 2024
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
   * Referenced by:
   *   '<S23>/Gain3'
   *   '<S27>/Gain3'
   */
  0.01,

  /* Variable: KI
   * Referenced by:
   *   '<S23>/Gain1'
   *   '<S27>/Gain1'
   */
  0.2,

  /* Variable: KP
   * Referenced by:
   *   '<S23>/Gain2'
   *   '<S27>/Gain2'
   */
  0.05,

  /* Variable: Vlim
   * Referenced by:
   *   '<S22>/Gain1'
   *   '<S26>/Gain1'
   */
  12.0,

  /* Variable: den_Gd
   * Referenced by:
   *   '<S21>/Discrete Transfer Fcn'
   *   '<S25>/Discrete Transfer Fcn'
   */
  { 1073741824, -879105452 },

  /* Variable: encoder_scale
   * Referenced by:
   *   '<S21>/Gain1'
   *   '<S25>/Gain1'
   */
  1124419809,

  /* Variable: num_Gd
   * Referenced by:
   *   '<S21>/Discrete Transfer Fcn'
   *   '<S25>/Discrete Transfer Fcn'
   */
  { 0, 1557090975 },

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S24>/UD'
   */
  0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_g
   * Referenced by: '<S28>/UD'
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
   * Referenced by: '<S18>/Output'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S18>/Constant'
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: '<S18>/Delay'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S18>/Constant1'
   */
  2.0,

  /* Computed Parameter: SW2_Y0
   * Referenced by: '<S15>/SW2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S15>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S15>/Delay'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S15>/Constant1'
   */
  2.0,

  /* Expression: -1
   * Referenced by: '<S21>/Encoder'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S25>/Encoder'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S34>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S34>/Constant1'
   */
  0.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S29>/Out1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/가변저항'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S23>/Integrator2'
   */
  0.0,

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

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<Root>/Constant'
   */
  100.0,

  /* Expression: 100
   * Referenced by: '<Root>/Constant1'
   */
  100.0,

  /* Expression: 12
   * Referenced by: '<S5>/Saturation2'
   */
  12.0,

  /* Expression: 0
   * Referenced by: '<S5>/Saturation2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S27>/Integrator2'
   */
  0.0,

  /* Expression: 12
   * Referenced by: '<S6>/Saturation1'
   */
  12.0,

  /* Expression: 0
   * Referenced by: '<S6>/Saturation1'
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

  /* Expression: 1
   * Referenced by: '<S32>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S32>/Constant1'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S32>/Merge'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<Root>/Gain2'
   */
  100.0,

  /* Expression: 100
   * Referenced by: '<Root>/Gain1'
   */
  100.0,

  /* Computed Parameter: Gain2_Gain_n
   * Referenced by: '<S21>/Gain2'
   */
  { { 0xB4AFEC00UL, 0x4C64F59BUL } },

  /* Computed Parameter: Gain2_Gain_d
   * Referenced by: '<S25>/Gain2'
   */
  { { 0xB4AFEC00UL, 0x4C64F59BUL } },

  /* Computed Parameter: DiscreteTransferFcn_InitialStat
   * Referenced by: '<S21>/Discrete Transfer Fcn'
   */
  0,

  /* Computed Parameter: DiscreteTransferFcn_InitialSt_i
   * Referenced by: '<S25>/Discrete Transfer Fcn'
   */
  0,

  /* Computed Parameter: Gain4_Gain
   * Referenced by: '<S4>/Gain4'
   */
  32768U,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S32>/Gain'
   */
  32768U,

  /* Start of '<S2>/If Action Subsystem3' */
  {
    /* Expression: 0
     * Referenced by: '<S11>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S2>/If Action Subsystem3' */

  /* Start of '<S2>/If Action Subsystem1' */
  {
    /* Expression: 1
     * Referenced by: '<S10>/Constant'
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
