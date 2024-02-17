/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Final_integration_1_data.c
 *
 * Code generated for Simulink model 'Final_integration_1'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Feb 15 09:21:38 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Final_integration_1.h"

/* Block parameters (default storage) */
P_Final_integration_1_T Final_integration_1_P = {
  /* Variable: b
   * Referenced by: '<Root>/후방 장애물 거리'
   */
  100.0,

  /* Variable: default1
   * Referenced by:
   *   '<S23>/Constant'
   *   '<S23>/Constant3'
   *   '<S30>/Constant'
   *   '<S30>/Constant3'
   *   '<S31>/Constant'
   *   '<S32>/Constant'
   *   '<S33>/Constant'
   *   '<S33>/Constant1'
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
   *   '<S30>/Constant1'
   *   '<S31>/Constant1'
   *   '<S32>/Constant1'
   */
  0.02,

  /* Expression: 0.01
   * Referenced by: '<Root>/Adas Mode Switch'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S19>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S19>/Constant1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S17>/Constant2'
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: '<S17>/Delay'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S17>/Merge'
   */
  0.0,

  /* Computed Parameter: sw2_Y0
   * Referenced by: '<S16>/sw2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S16>/Constant2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S16>/Delay1'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S16>/Constant3'
   */
  2.0,

  /* Computed Parameter: ADAS_state_Y0
   * Referenced by: '<S15>/ADAS_state'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S25>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S23>/Constant4'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<S23>/Constant1'
   */
  100.0,

  /* Expression: 6.4
   * Referenced by: '<S23>/Constant5'
   */
  6.4,

  /* Expression: 128
   * Referenced by: '<S23>/Constant2'
   */
  128.0,

  /* Expression: 1
   * Referenced by: '<S23>/Constant8'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<S23>/Constant6'
   */
  100.0,

  /* Expression: 6.4
   * Referenced by: '<S23>/Constant9'
   */
  6.4,

  /* Expression: 128
   * Referenced by: '<S23>/Constant7'
   */
  128.0,

  /* Expression: 0
   * Referenced by: '<S23>/Constant10'
   */
  0.0,

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

  /* Expression: 0
   * Referenced by: '<S27>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S26>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S26>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S26>/Constant2'
   */
  1.0,

  /* Expression: 1.2
   * Referenced by: '<S29>/Gain'
   */
  1.2,

  /* Expression: 1.2
   * Referenced by: '<S29>/Gain1'
   */
  1.2,

  /* Expression: 1
   * Referenced by: '<S34>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<S34>/Pulse Generator'
   */
  20.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<S34>/Pulse Generator'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S34>/Pulse Generator'
   */
  0.0,

  /* Computed Parameter: light_mode_Y0
   * Referenced by: '<S36>/light_mode'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S36>/Constant'
   */
  1.0,

  /* Expression: 3
   * Referenced by: '<S36>/Constant1'
   */
  3.0,

  /* Expression: 0
   * Referenced by: '<S36>/Constant2'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S36>/Delay'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S42>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S42>/Constant1'
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
   * Referenced by: '<S7>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period_h
   * Referenced by: '<S7>/Pulse Generator'
   */
  200.0,

  /* Computed Parameter: PulseGenerator_Duty_m
   * Referenced by: '<S7>/Pulse Generator'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S7>/Pulse Generator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S7>/Constant'
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

  /* Expression: 1
   * Referenced by: '<S40>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S40>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period_k
   * Referenced by: '<S40>/Pulse Generator'
   */
  20.0,

  /* Computed Parameter: PulseGenerator_Duty_b
   * Referenced by: '<S40>/Pulse Generator'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S40>/Pulse Generator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S40>/Constant1'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_b
   * Referenced by: '<S40>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge1_InitialOutput
   * Referenced by: '<S40>/Merge1'
   */
  0.0,

  /* Computed Parameter: Gain_Gain_a
   * Referenced by: '<S40>/Gain'
   */
  2147483648U,

  /* Computed Parameter: Gain4_Gain
   * Referenced by: '<S4>/Gain4'
   */
  32768U,

  /* Computed Parameter: Gain_Gain_i
   * Referenced by: '<S1>/Gain'
   */
  35840U,

  /* Start of '<S5>/If Action Subsystem1' */
  {
    /* Expression: 0
     * Referenced by: '<S35>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S5>/If Action Subsystem1' */

  /* Start of '<S8>/If Action Subsystem3' */
  {
    /* Expression: 0
     * Referenced by: '<S12>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S8>/If Action Subsystem3' */

  /* Start of '<S8>/If Action Subsystem1' */
  {
    /* Expression: 1
     * Referenced by: '<S11>/Constant'
     */
    1.0
  }
  /* End of '<S8>/If Action Subsystem1' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
