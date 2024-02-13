/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled_data.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Feb 11 16:25:09 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"

/* Block parameters (default storage) */
P_untitled_T untitled_P = {
  /* Variable: KI
   * Referenced by: '<S3>/Gain4'
   */
  0.1,

  /* Variable: Wref
   * Referenced by: '<Root>/Step'
   */
  128.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S4>/UD'
   */
  0,

  /* Expression: -1
   * Referenced by: '<S1>/Encoder'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Step'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Integrator1'
   */
  0.0,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S1>/Gain2'
   */
  1281684892
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
