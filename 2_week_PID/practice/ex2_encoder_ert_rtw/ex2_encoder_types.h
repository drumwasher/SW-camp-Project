/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ex2_encoder_types.h
 *
 * Code generated for Simulink model 'ex2_encoder'.
 *
 * Model version                  : 1.31
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Feb 11 15:59:07 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ex2_encoder_types_h_
#define RTW_HEADER_ex2_encoder_types_h_
#include "MW_SVD.h"
#include "rtwtypes.h"

/* Custom Type definition for MATLABSystem: '<S2>/PWM' */
#include "MW_SVD.h"
#ifndef struct_tag_UTG5XI0vJCsmjbgura8BP
#define struct_tag_UTG5XI0vJCsmjbgura8BP

struct tag_UTG5XI0vJCsmjbgura8BP
{
  MW_Handle_Type MW_ANALOGIN_HANDLE;
};

#endif                                 /* struct_tag_UTG5XI0vJCsmjbgura8BP */

#ifndef typedef_g_arduinodriver_ArduinoAnalog_T
#define typedef_g_arduinodriver_ArduinoAnalog_T

typedef struct tag_UTG5XI0vJCsmjbgura8BP g_arduinodriver_ArduinoAnalog_T;

#endif                             /* typedef_g_arduinodriver_ArduinoAnalog_T */

#ifndef struct_tag_8ohiN1FAOgR98njPNu14NC
#define struct_tag_8ohiN1FAOgR98njPNu14NC

struct tag_8ohiN1FAOgR98njPNu14NC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  g_arduinodriver_ArduinoAnalog_T AnalogInDriverObj;
  real_T SampleTime;
};

#endif                                 /* struct_tag_8ohiN1FAOgR98njPNu14NC */

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_8ohiN1FAOgR98njPNu14NC codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

#ifndef struct_tag_hiATgaifu8RfrjZ2yifYbH
#define struct_tag_hiATgaifu8RfrjZ2yifYbH

struct tag_hiATgaifu8RfrjZ2yifYbH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  real_T SampleTime;
  uint8_T Index;
};

#endif                                 /* struct_tag_hiATgaifu8RfrjZ2yifYbH */

#ifndef typedef_codertarget_arduinobase_int_n_T
#define typedef_codertarget_arduinobase_int_n_T

typedef struct tag_hiATgaifu8RfrjZ2yifYbH codertarget_arduinobase_int_n_T;

#endif                             /* typedef_codertarget_arduinobase_int_n_T */

#ifndef struct_tag_g1WX34VPn8QzVKQriB4HN
#define struct_tag_g1WX34VPn8QzVKQriB4HN

struct tag_g1WX34VPn8QzVKQriB4HN
{
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /* struct_tag_g1WX34VPn8QzVKQriB4HN */

#ifndef typedef_h_matlabshared_ioclient_perip_T
#define typedef_h_matlabshared_ioclient_perip_T

typedef struct tag_g1WX34VPn8QzVKQriB4HN h_matlabshared_ioclient_perip_T;

#endif                             /* typedef_h_matlabshared_ioclient_perip_T */

#ifndef struct_tag_4eDVzK5FiryyCjvjjvrZGB
#define struct_tag_4eDVzK5FiryyCjvjjvrZGB

struct tag_4eDVzK5FiryyCjvjjvrZGB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  h_matlabshared_ioclient_perip_T PWMDriverObj;
};

#endif                                 /* struct_tag_4eDVzK5FiryyCjvjjvrZGB */

#ifndef typedef_codertarget_arduinobase_in_nq_T
#define typedef_codertarget_arduinobase_in_nq_T

typedef struct tag_4eDVzK5FiryyCjvjjvrZGB codertarget_arduinobase_in_nq_T;

#endif                             /* typedef_codertarget_arduinobase_in_nq_T */

/* Parameters (default storage) */
typedef struct P_ex2_encoder_T_ P_ex2_encoder_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_ex2_encoder_T RT_MODEL_ex2_encoder_T;

#endif                                 /* RTW_HEADER_ex2_encoder_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
