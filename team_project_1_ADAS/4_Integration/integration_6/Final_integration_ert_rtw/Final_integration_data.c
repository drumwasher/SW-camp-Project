/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Final_integration_data.c
 *
 * Code generated for Simulink model 'Final_integration'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Feb 15 09:43:46 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Final_integration.h"

/* Block parameters (default storage) */
P_Final_integration_T Final_integration_P = {
  /* Variable: KP
   * Referenced by:
   *   '<S26>/Gain4'
   *   '<S30>/Gain4'
   */
  0.009,

  /* Variable: Vlim
   * Referenced by:
   *   '<S25>/Gain1'
   *   '<S29>/Gain1'
   */
  12.0,

  /* Variable: b
   * Referenced by: '<Root>/후방 장애물 거리'
   */
  100.0,

  /* Variable: default1
   * Referenced by:
   *   '<S33>/Constant'
   *   '<S33>/Constant3'
   *   '<S40>/Constant'
   *   '<S40>/Constant3'
   *   '<S41>/Constant'
   *   '<S42>/Constant'
   *   '<S43>/Constant'
   *   '<S43>/Constant1'
   */
  360.0,

  /* Variable: f
   * Referenced by: '<Root>/전방 장애물 거리'
   */
  100.0,

  /* Variable: l
   * Referenced by: '<Root>/좌측 장애물 거리'
   */
  100.0,

  /* Variable: r
   * Referenced by: '<Root>/우측 장애물 거리'
   */
  100.0,

  /* Variable: steering
   * Referenced by:
   *   '<S40>/Constant1'
   *   '<S41>/Constant1'
   *   '<S42>/Constant1'
   */
  0.02,

  /* Variable: den_Gd
   * Referenced by:
   *   '<S24>/Discrete Transfer Fcn'
   *   '<S28>/Discrete Transfer Fcn'
   */
  { 1073741824, -879105452 },

  /* Variable: encoder_scale
   * Referenced by:
   *   '<S24>/Gain1'
   *   '<S28>/Gain1'
   */
  1124419809,

  /* Variable: num_Gd
   * Referenced by:
   *   '<S24>/Discrete Transfer Fcn'
   *   '<S28>/Discrete Transfer Fcn'
   */
  { 0, 1557090975 },

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S27>/UD'
   */
  0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_j
   * Referenced by: '<S31>/UD'
   */
  0,

  /* Expression: 0.01
   * Referenced by: '<Root>/Adas Mode Switch'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S21>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S21>/Constant1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S19>/Constant2'
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: '<S19>/Delay'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S19>/Merge'
   */
  0.0,

  /* Computed Parameter: sw2_Y0
   * Referenced by: '<S18>/sw2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S18>/Constant2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S18>/Delay1'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S18>/Constant3'
   */
  2.0,

  /* Computed Parameter: ADAS_state_Y0
   * Referenced by: '<S17>/ADAS_state'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<S24>/Encoder'
   */
  0.01,

  /* Expression: 0.01
   * Referenced by: '<S28>/Encoder'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S35>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S33>/Constant4'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<S33>/Constant1'
   */
  100.0,

  /* Expression: 6.4
   * Referenced by: '<S33>/Constant5'
   */
  6.4,

  /* Expression: 128
   * Referenced by: '<S33>/Constant2'
   */
  128.0,

  /* Expression: 1
   * Referenced by: '<S33>/Constant8'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<S33>/Constant6'
   */
  100.0,

  /* Expression: 6.4
   * Referenced by: '<S33>/Constant9'
   */
  6.4,

  /* Expression: 128
   * Referenced by: '<S33>/Constant7'
   */
  128.0,

  /* Expression: 0
   * Referenced by: '<S33>/Constant10'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S40>/Constant2'
   */
  1.0,

  /* Expression: 10
   * Referenced by: '<S41>/Constant4'
   */
  10.0,

  /* Expression: 1
   * Referenced by: '<S41>/Constant2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S42>/Constant2'
   */
  1.0,

  /* Expression: 10
   * Referenced by: '<S42>/Constant4'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S37>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S36>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S36>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S36>/Constant2'
   */
  1.0,

  /* Expression: 1.2
   * Referenced by: '<S39>/Gain'
   */
  1.2,

  /* Expression: 1.2
   * Referenced by: '<S39>/Gain1'
   */
  1.2,

  /* Expression: 1
   * Referenced by: '<S44>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<S44>/Pulse Generator'
   */
  20.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<S44>/Pulse Generator'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S44>/Pulse Generator'
   */
  0.0,

  /* Computed Parameter: light_mode_Y0
   * Referenced by: '<S46>/light_mode'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S46>/Constant'
   */
  1.0,

  /* Expression: 3
   * Referenced by: '<S46>/Constant1'
   */
  3.0,

  /* Expression: 0
   * Referenced by: '<S46>/Constant2'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S46>/Delay'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S52>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S52>/Constant1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/가변저항'
   */
  -1.0,

  /* Expression: 0.01
   * Referenced by: '<Root>/조도센서 Input'
   */
  0.01,

  /* Expression: 0.01
   * Referenced by: '<Root>/조도센서 Switch'
   */
  0.01,

  /* Expression: 1
   * Referenced by: '<S9>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period_l
   * Referenced by: '<S9>/Pulse Generator'
   */
  200.0,

  /* Computed Parameter: PulseGenerator_Duty_p
   * Referenced by: '<S9>/Pulse Generator'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S9>/Pulse Generator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S9>/Constant'
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: '<S1>/Delay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S3>/Delay'
   */
  0.0,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<S26>/Transfer Fcn1'
   */
  -0.0,

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<S26>/Transfer Fcn1'
   */
  0.03,

  /* Expression: 12
   * Referenced by: '<S4>/Saturation1'
   */
  12.0,

  /* Expression: 2
   * Referenced by: '<S4>/Saturation1'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant9'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S4>/Switch'
   */
  2.0,

  /* Expression: 1
   * Referenced by: '<S4>/Constant'
   */
  1.0,

  /* Computed Parameter: TransferFcn1_A_o
   * Referenced by: '<S30>/Transfer Fcn1'
   */
  -0.0,

  /* Computed Parameter: TransferFcn1_C_o
   * Referenced by: '<S30>/Transfer Fcn1'
   */
  0.03,

  /* Expression: 12
   * Referenced by: '<S5>/Saturation2'
   */
  12.0,

  /* Expression: 0
   * Referenced by: '<S5>/Saturation2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Constant16'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S5>/Switch1'
   */
  2.0,

  /* Expression: 1
   * Referenced by: '<S50>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S50>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period_e
   * Referenced by: '<S50>/Pulse Generator'
   */
  20.0,

  /* Computed Parameter: PulseGenerator_Duty_l
   * Referenced by: '<S50>/Pulse Generator'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S50>/Pulse Generator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S50>/Constant1'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_f
   * Referenced by: '<S50>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge1_InitialOutput
   * Referenced by: '<S50>/Merge1'
   */
  0.0,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S24>/Gain2'
   */
  { { 0xB4AFEC00UL, 0x4C64F59BUL } },

  /* Computed Parameter: Gain2_Gain_c
   * Referenced by: '<S28>/Gain2'
   */
  { { 0xB4AFEC00UL, 0x4C64F59BUL } },

  /* Computed Parameter: DiscreteTransferFcn_InitialStat
   * Referenced by: '<S24>/Discrete Transfer Fcn'
   */
  0,

  /* Computed Parameter: DiscreteTransferFcn_InitialSt_b
   * Referenced by: '<S28>/Discrete Transfer Fcn'
   */
  0,

  /* Computed Parameter: Gain_Gain_c
   * Referenced by: '<S50>/Gain'
   */
  2147483648U,

  /* Computed Parameter: Gain4_Gain
   * Referenced by: '<S6>/Gain4'
   */
  32768U,

  /* Computed Parameter: Gain_Gain_o
   * Referenced by: '<S1>/Gain'
   */
  35840U,

  /* Start of '<S7>/If Action Subsystem1' */
  {
    /* Expression: 0
     * Referenced by: '<S45>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S7>/If Action Subsystem1' */

  /* Start of '<S10>/If Action Subsystem3' */
  {
    /* Expression: 0
     * Referenced by: '<S14>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S10>/If Action Subsystem3' */

  /* Start of '<S10>/If Action Subsystem1' */
  {
    /* Expression: 1
     * Referenced by: '<S13>/Constant'
     */
    1.0
  }
  /* End of '<S10>/If Action Subsystem1' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
