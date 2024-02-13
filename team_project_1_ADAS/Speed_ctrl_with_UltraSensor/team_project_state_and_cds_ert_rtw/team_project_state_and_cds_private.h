/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: team_project_state_and_cds_private.h
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

#ifndef RTW_HEADER_team_project_state_and_cds_private_h_
#define RTW_HEADER_team_project_state_and_cds_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "team_project_state_and_cds_types.h"
#include "team_project_state_and_cds.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFU) ) || ( INT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFUL) ) || ( LONG_MAX != (0x7FFFFFFFL) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

extern real_T rt_modd_snf(real_T u0, real_T u1);
void MW_ISR_20(void);
void MW_ISR_21(void);
extern void sMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[],
  int16_T n2, uint32_T y[], int16_T n);
extern real_T sMultiWord2Double(const uint32_T u1[], int16_T n1, int16_T e1);
extern int32_T MultiWord2sLong(const uint32_T u[]);
extern void sMultiWordShr(const uint32_T u1[], int16_T n1, uint16_T n2, uint32_T
  y[], int16_T n);
extern void sMultiWordShl(const uint32_T u1[], int16_T n1, uint16_T n2, uint32_T
  y[], int16_T n);
extern void sLong2MultiWord(int32_T u, uint32_T y[], int16_T n);
extern void MultiWordSub(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
  int16_T n);
extern void sMultiWord2MultiWord(const uint32_T u1[], int16_T n1, uint32_T y[],
  int16_T n);
extern void sMultiWordDivFloor(const uint32_T u1[], int16_T n1, const uint32_T
  u2[], int16_T n2, uint32_T y1[], int16_T m1, uint32_T y2[], int16_T m2,
  uint32_T t1[], int16_T l1, uint32_T t2[], int16_T l2);
extern void MultiWordNeg(const uint32_T u1[], uint32_T y[], int16_T n);
extern void MultiWordSetSignedMin(uint32_T y[], int16_T n);
extern void MultiWordSetSignedMax(uint32_T y[], int16_T n);
extern void uMultiWordInc(uint32_T y[], int16_T n);
extern boolean_T MultiWord2Bool(const uint32_T u[], int16_T n);
extern int16_T uMultiWordDiv(uint32_T a[], int16_T na, uint32_T b[], int16_T nb,
  uint32_T q[], int16_T nq, uint32_T r[], int16_T nr);
extern boolean_T sMultiWordGe(const uint32_T u1[], const uint32_T u2[], int16_T
  n);
extern int16_T sMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int16_T n);

/* private model entry point functions */
extern void team_project_state_and_cds_derivatives(void);

#endif                    /* RTW_HEADER_team_project_state_and_cds_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
