/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Semi_Final_integration_data.c
 *
 * Code generated for Simulink model 'Semi_Final_integration'.
 *
 * Model version                  : 1.47
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Feb 15 09:25:14 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Semi_Final_integration.h"

/* Block parameters (default storage) */
P_Semi_Final_integration_T Semi_Final_integration_P = {
  /* Variable: KD
   * Referenced by:
   *   '<S6>/Gain3'
   *   '<S11>/Gain3'
   */
  0.0,

  /* Variable: KI
   * Referenced by:
   *   '<S6>/Gain1'
   *   '<S11>/Gain1'
   */
  0.03,

  /* Variable: KP
   * Referenced by:
   *   '<S6>/Gain2'
   *   '<S11>/Gain2'
   */
  0.009,

  /* Variable: Vlim
   * Referenced by:
   *   '<S5>/Gain1'
   *   '<S10>/Gain1'
   */
  12.0,

  /* Variable: b
   * Referenced by: '<Root>/Constant7'
   */
  100.0,

  /* Variable: default1
   * Referenced by:
   *   '<S30>/Constant'
   *   '<S30>/Constant3'
   *   '<S37>/Constant'
   *   '<S37>/Constant3'
   *   '<S38>/Constant'
   *   '<S39>/Constant'
   *   '<S40>/Constant'
   *   '<S40>/Constant1'
   */
  360.0,

  /* Variable: f
   * Referenced by: '<Root>/Constant4'
   */
  100.0,

  /* Variable: l
   * Referenced by: '<Root>/Constant6'
   */
  100.0,

  /* Variable: r
   * Referenced by: '<Root>/Constant8'
   */
  100.0,

  /* Variable: steering
   * Referenced by:
   *   '<S37>/Constant1'
   *   '<S38>/Constant1'
   *   '<S39>/Constant1'
   */
  0.02,

  /* Variable: den_Gd
   * Referenced by:
   *   '<S4>/Discrete Transfer Fcn'
   *   '<S9>/Discrete Transfer Fcn'
   */
  { 1073741824, -879105452 },

  /* Variable: encoder_scale
   * Referenced by:
   *   '<S4>/Gain1'
   *   '<S9>/Gain1'
   */
  1124419809,

  /* Variable: num_Gd
   * Referenced by:
   *   '<S4>/Discrete Transfer Fcn'
   *   '<S9>/Discrete Transfer Fcn'
   */
  { 0, 1557090975 },

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S41>/UD'
   */
  0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_m
   * Referenced by: '<S26>/UD'
   */
  0,

  /* Expression: -1
   * Referenced by: '<Root>/Analog Input1'
   */
  -1.0,

  /* Expression: 0.1
   * Referenced by: '<Root>/Digital Input1'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<Root>/Digital Input2'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S23>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S23>/Constant1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S21>/Constant2'
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: '<S21>/Delay'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S21>/Merge'
   */
  0.0,

  /* Computed Parameter: sw2_Y0
   * Referenced by: '<S20>/sw2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S20>/Constant2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S20>/Delay1'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S20>/Constant3'
   */
  2.0,

  /* Computed Parameter: ADAS_state_Y0
   * Referenced by: '<S19>/ADAS_state'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<S4>/Encoder'
   */
  0.01,

  /* Expression: 1
   * Referenced by: '<S27>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<S27>/Pulse Generator'
   */
  20.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<S27>/Pulse Generator'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S27>/Pulse Generator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S32>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S30>/Constant4'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<S30>/Constant1'
   */
  100.0,

  /* Expression: 6.4
   * Referenced by: '<S30>/Constant5'
   */
  6.4,

  /* Expression: 128
   * Referenced by: '<S30>/Constant2'
   */
  128.0,

  /* Expression: 1
   * Referenced by: '<S30>/Constant8'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<S30>/Constant6'
   */
  100.0,

  /* Expression: 6.4
   * Referenced by: '<S30>/Constant9'
   */
  6.4,

  /* Expression: 128
   * Referenced by: '<S30>/Constant7'
   */
  128.0,

  /* Expression: 0
   * Referenced by: '<S30>/Constant10'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S37>/Constant2'
   */
  1.0,

  /* Expression: 10
   * Referenced by: '<S38>/Constant4'
   */
  10.0,

  /* Expression: 1
   * Referenced by: '<S38>/Constant2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S39>/Constant2'
   */
  1.0,

  /* Expression: 10
   * Referenced by: '<S39>/Constant4'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S34>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S33>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S33>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S33>/Constant2'
   */
  1.0,

  /* Expression: 1.2
   * Referenced by: '<S36>/Gain'
   */
  1.2,

  /* Expression: 1.2
   * Referenced by: '<S36>/Gain1'
   */
  1.2,

  /* Expression: 0.01
   * Referenced by: '<S9>/Encoder'
   */
  0.01,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S42>/Out1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S42>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S42>/Constant2'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<S42>/Constant1'
   */
  3.0,

  /* Expression: 0.0
   * Referenced by: '<S42>/Delay'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S48>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S48>/Constant1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/가변저항'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period_c
   * Referenced by: '<S1>/Pulse Generator'
   */
  200.0,

  /* Computed Parameter: PulseGenerator_Duty_f
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

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S3>/Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S11>/Integrator2'
   */
  0.0,

  /* Expression: 12
   * Referenced by: '<Root>/Saturation1'
   */
  12.0,

  /* Expression: 2
   * Referenced by: '<Root>/Saturation1'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant16'
   */
  0.0,

  /* Expression: 1.6
   * Referenced by: '<Root>/Switch1'
   */
  1.6,

  /* Expression: 0
   * Referenced by: '<S6>/Integrator2'
   */
  0.0,

  /* Expression: 12
   * Referenced by: '<Root>/Saturation2'
   */
  12.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant9'
   */
  0.0,

  /* Expression: 1.6
   * Referenced by: '<Root>/Switch'
   */
  1.6,

  /* Expression: 1
   * Referenced by: '<S46>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S46>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period_d
   * Referenced by: '<S46>/Pulse Generator'
   */
  20.0,

  /* Computed Parameter: PulseGenerator_Duty_p
   * Referenced by: '<S46>/Pulse Generator'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S46>/Pulse Generator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S46>/Constant1'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_b
   * Referenced by: '<S46>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge1_InitialOutput
   * Referenced by: '<S46>/Merge1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant13'
   */
  1.0,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S9>/Gain2'
   */
  { { 0xB4AFEC00UL, 0x4C64F59BUL } },

  /* Computed Parameter: Gain2_Gain_g
   * Referenced by: '<S4>/Gain2'
   */
  { { 0xB4AFEC00UL, 0x4C64F59BUL } },

  /* Computed Parameter: DiscreteTransferFcn_InitialStat
   * Referenced by: '<S9>/Discrete Transfer Fcn'
   */
  0,

  /* Computed Parameter: DiscreteTransferFcn_InitialSt_p
   * Referenced by: '<S4>/Discrete Transfer Fcn'
   */
  0,

  /* Computed Parameter: Gain_Gain_l
   * Referenced by: '<S46>/Gain'
   */
  2147483648U,

  /* Computed Parameter: Gain4_Gain
   * Referenced by: '<S8>/Gain4'
   */
  32768U,

  /* Computed Parameter: Gain12_Gain
   * Referenced by: '<Root>/Gain12'
   */
  35840U,

  /* Start of '<S7>/If Action Subsystem1' */
  {
    /* Expression: 0
     * Referenced by: '<S28>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S7>/If Action Subsystem1' */

  /* Start of '<S2>/If Action Subsystem3' */
  {
    /* Expression: 0
     * Referenced by: '<S16>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S2>/If Action Subsystem3' */

  /* Start of '<S2>/If Action Subsystem1' */
  {
    /* Expression: 1
     * Referenced by: '<S15>/Constant'
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
