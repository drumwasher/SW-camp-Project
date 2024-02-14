/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: integration_2_data.c
 *
 * Code generated for Simulink model 'integration_2'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Feb 14 09:58:12 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "integration_2.h"

/* Block parameters (default storage) */
P_integration_2_T integration_2_P = {
  /* Variable: KD
   * Referenced by:
   *   '<S36>/Gain3'
   *   '<S40>/Gain3'
   */
  0.0,

  /* Variable: KI
   * Referenced by:
   *   '<S36>/Gain1'
   *   '<S40>/Gain1'
   */
  0.2,

  /* Variable: KP
   * Referenced by:
   *   '<S36>/Gain2'
   *   '<S40>/Gain2'
   */
  0.05,

  /* Variable: Vlim
   * Referenced by:
   *   '<S35>/Gain1'
   *   '<S39>/Gain1'
   */
  12.0,

  /* Variable: b
   * Referenced by: '<Root>/Constant3'
   */
  100.0,

  /* Variable: default1
   * Referenced by:
   *   '<S30>/Constant'
   *   '<S30>/Constant3'
   *   '<S31>/Constant'
   *   '<S32>/Constant'
   */
  360.0,

  /* Variable: l
   * Referenced by: '<Root>/Constant2'
   */
  100.0,

  /* Variable: r
   * Referenced by: '<Root>/Constant6'
   */
  100.0,

  /* Variable: steering
   * Referenced by:
   *   '<S30>/Constant1'
   *   '<S31>/Constant1'
   *   '<S32>/Constant1'
   */
  0.02,

  /* Variable: den_Gd
   * Referenced by:
   *   '<S34>/Discrete Transfer Fcn'
   *   '<S38>/Discrete Transfer Fcn'
   */
  { 1073741824, -879105452 },

  /* Variable: encoder_scale
   * Referenced by:
   *   '<S34>/Gain1'
   *   '<S38>/Gain1'
   */
  1124419809,

  /* Variable: num_Gd
   * Referenced by:
   *   '<S34>/Discrete Transfer Fcn'
   *   '<S38>/Discrete Transfer Fcn'
   */
  { 0, 1557090975 },

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S37>/UD'
   */
  0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_g
   * Referenced by: '<S41>/UD'
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
   * Referenced by: '<S20>/Output'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S20>/Constant'
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: '<S20>/Delay'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S20>/Constant1'
   */
  2.0,

  /* Computed Parameter: sw2_Y0
   * Referenced by: '<S17>/sw2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S17>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S17>/Delay'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S17>/Constant1'
   */
  2.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S22>/Out1'
   */
  0.0,

  /* Expression: 360
   * Referenced by: '<S24>/Constant'
   */
  360.0,

  /* Expression: 1
   * Referenced by: '<S24>/Constant4'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<S24>/Constant1'
   */
  100.0,

  /* Expression: 6.4
   * Referenced by: '<S24>/Constant5'
   */
  6.4,

  /* Expression: 128
   * Referenced by: '<S24>/Constant2'
   */
  128.0,

  /* Expression: 360
   * Referenced by: '<S24>/Constant3'
   */
  360.0,

  /* Expression: 1
   * Referenced by: '<S24>/Constant8'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<S24>/Constant6'
   */
  100.0,

  /* Expression: 6.4
   * Referenced by: '<S24>/Constant9'
   */
  6.4,

  /* Expression: 128
   * Referenced by: '<S24>/Constant7'
   */
  128.0,

  /* Expression: 1
   * Referenced by: '<S30>/Constant2'
   */
  1.0,

  /* Expression: 10
   * Referenced by: '<S31>/Constant4'
   */
  10.0,

  /* Expression: 1
   * Referenced by: '<S31>/Constant2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S32>/Constant2'
   */
  1.0,

  /* Expression: 10
   * Referenced by: '<S32>/Constant4'
   */
  10.0,

  /* Expression: 360
   * Referenced by: '<S33>/Constant'
   */
  360.0,

  /* Expression: 360
   * Referenced by: '<S33>/Constant1'
   */
  360.0,

  /* Expression: 1.2
   * Referenced by: '<S29>/Gain'
   */
  1.2,

  /* Expression: 1.2
   * Referenced by: '<S29>/Gain1'
   */
  1.2,

  /* Expression: -1
   * Referenced by: '<S34>/Encoder'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S38>/Encoder'
   */
  -1.0,

  /* Computed Parameter: Out1_Y0_c
   * Referenced by: '<S42>/Out1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S42>/Constant'
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: '<S42>/Delay'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<S42>/Constant1'
   */
  3.0,

  /* Expression: 1
   * Referenced by: '<S47>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S47>/Constant1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/가변저항'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S36>/Integrator2'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S5>/Delay'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<Root>/Gain2'
   */
  100.0,

  /* Expression: 30
   * Referenced by: '<Root>/Saturation'
   */
  30.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay1'
   */
  0.0,

  /* Computed Parameter: Merge1_InitialOutput
   * Referenced by: '<S21>/Merge1'
   */
  0.0,

  /* Expression: 12
   * Referenced by: '<S7>/Saturation2'
   */
  12.0,

  /* Expression: 0
   * Referenced by: '<S7>/Saturation2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S40>/Integrator2'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S21>/Merge'
   */
  0.0,

  /* Expression: 12
   * Referenced by: '<S8>/Saturation1'
   */
  12.0,

  /* Expression: 0
   * Referenced by: '<S8>/Saturation1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S3>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<S3>/Pulse Generator'
   */
  200.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<S3>/Pulse Generator'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S3>/Pulse Generator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S3>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S45>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S45>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period_p
   * Referenced by: '<S45>/Pulse Generator'
   */
  20.0,

  /* Computed Parameter: PulseGenerator_Duty_n
   * Referenced by: '<S45>/Pulse Generator'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S45>/Pulse Generator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S45>/Constant1'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_m
   * Referenced by: '<S45>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge1_InitialOutput_g
   * Referenced by: '<S45>/Merge1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Constant'
   */
  0.0,

  /* Computed Parameter: Gain2_Gain_n
   * Referenced by: '<S34>/Gain2'
   */
  { { 0xB4AFEC00UL, 0x4C64F59BUL } },

  /* Computed Parameter: Gain2_Gain_d
   * Referenced by: '<S38>/Gain2'
   */
  { { 0xB4AFEC00UL, 0x4C64F59BUL } },

  /* Computed Parameter: DiscreteTransferFcn_InitialStat
   * Referenced by: '<S34>/Discrete Transfer Fcn'
   */
  0,

  /* Computed Parameter: DiscreteTransferFcn_InitialSt_i
   * Referenced by: '<S38>/Discrete Transfer Fcn'
   */
  0,

  /* Computed Parameter: Gain4_Gain
   * Referenced by: '<S6>/Gain4'
   */
  32768U,

  /* Computed Parameter: Gain_Gain_e
   * Referenced by: '<S45>/Gain'
   */
  32768U,

  /* Start of '<S25>/If Action Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S26>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S26>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S25>/If Action Subsystem' */

  /* Start of '<S21>/If Action Subsystem1' */
  {
    /* Expression: 0
     * Referenced by: '<S23>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S23>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S21>/If Action Subsystem1' */

  /* Start of '<S4>/If Action Subsystem3' */
  {
    /* Expression: 0
     * Referenced by: '<S13>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S4>/If Action Subsystem3' */

  /* Start of '<S4>/If Action Subsystem1' */
  {
    /* Expression: 1
     * Referenced by: '<S12>/Constant'
     */
    1.0
  }
  /* End of '<S4>/If Action Subsystem1' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
