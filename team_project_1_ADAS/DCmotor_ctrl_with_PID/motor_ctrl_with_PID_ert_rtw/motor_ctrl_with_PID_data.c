/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motor_ctrl_with_PID_data.c
 *
 * Code generated for Simulink model 'motor_ctrl_with_PID'.
 *
 * Model version                  : 1.38
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Feb 13 21:22:30 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "motor_ctrl_with_PID.h"

/* Block parameters (default storage) */
P_motor_ctrl_with_PID_T motor_ctrl_with_PID_P = {
  /* Variable: KD
   * Referenced by:
   *   '<S14>/Gain3'
   *   '<S18>/Gain3'
   */
  0.0,

  /* Variable: KI
   * Referenced by:
   *   '<S14>/Gain1'
   *   '<S18>/Gain1'
   */
  0.2,

  /* Variable: KP
   * Referenced by:
   *   '<S14>/Gain2'
   *   '<S18>/Gain2'
   */
  0.05,

  /* Variable: Vlim
   * Referenced by:
   *   '<S13>/Gain1'
   *   '<S17>/Gain1'
   */
  12.0,

  /* Variable: b
   * Referenced by: '<Root>/Constant7'
   */
  100.0,

  /* Variable: den_Gd
   * Referenced by:
   *   '<S12>/Discrete Transfer Fcn'
   *   '<S16>/Discrete Transfer Fcn'
   */
  { 1073741824, -879105452 },

  /* Variable: encoder_scale
   * Referenced by:
   *   '<S12>/Gain1'
   *   '<S16>/Gain1'
   */
  1124419809,

  /* Variable: num_Gd
   * Referenced by:
   *   '<S12>/Discrete Transfer Fcn'
   *   '<S16>/Discrete Transfer Fcn'
   */
  { 0, 1557090975 },

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S15>/UD'
   */
  0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_n
   * Referenced by: '<S19>/UD'
   */
  0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S7>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Constant1'
   */
  0.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S6>/Out1'
   */
  0.0,

  /* Expression: 360
   * Referenced by: '<S8>/Constant'
   */
  360.0,

  /* Expression: 1
   * Referenced by: '<S8>/Constant4'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<S8>/Constant1'
   */
  100.0,

  /* Expression: 6.4
   * Referenced by: '<S8>/Constant5'
   */
  6.4,

  /* Expression: 128
   * Referenced by: '<S8>/Constant2'
   */
  128.0,

  /* Expression: 360
   * Referenced by: '<S8>/Constant3'
   */
  360.0,

  /* Expression: 1
   * Referenced by: '<S8>/Constant8'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<S8>/Constant6'
   */
  100.0,

  /* Expression: 6.4
   * Referenced by: '<S8>/Constant9'
   */
  6.4,

  /* Expression: 128
   * Referenced by: '<S8>/Constant7'
   */
  128.0,

  /* Expression: -1
   * Referenced by: '<S12>/Encoder'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S16>/Encoder'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/가변저항'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S14>/Integrator2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant11'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant12'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<Root>/Gain1'
   */
  100.0,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S3>/Merge'
   */
  0.0,

  /* Expression: 12
   * Referenced by: '<S4>/Saturation2'
   */
  12.0,

  /* Expression: 0
   * Referenced by: '<S4>/Saturation2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S18>/Integrator2'
   */
  0.0,

  /* Computed Parameter: Merge1_InitialOutput
   * Referenced by: '<S3>/Merge1'
   */
  0.0,

  /* Expression: 12
   * Referenced by: '<S5>/Saturation2'
   */
  12.0,

  /* Expression: 0
   * Referenced by: '<S5>/Saturation2'
   */
  0.0,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S12>/Gain2'
   */
  { { 0xB4AFEC00UL, 0x4C64F59BUL } },

  /* Computed Parameter: Gain2_Gain_g
   * Referenced by: '<S16>/Gain2'
   */
  { { 0xB4AFEC00UL, 0x4C64F59BUL } },

  /* Computed Parameter: DiscreteTransferFcn_InitialStat
   * Referenced by: '<S12>/Discrete Transfer Fcn'
   */
  0,

  /* Computed Parameter: DiscreteTransferFcn_InitialSt_b
   * Referenced by: '<S16>/Discrete Transfer Fcn'
   */
  0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S3>/Gain'
   */
  32768U,

  /* Start of '<S9>/If Action Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S10>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S10>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S9>/If Action Subsystem' */

  /* Start of '<S9>/If Action Subsystem1' */
  {
    /* Expression: 360
     * Referenced by: '<S11>/Constant'
     */
    360.0,

    /* Expression: 360
     * Referenced by: '<S11>/Constant1'
     */
    360.0
  }
  /* End of '<S9>/If Action Subsystem1' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
