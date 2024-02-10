/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: dcmotor_test.c
 *
 * Code generated for Simulink model 'dcmotor_test'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Feb  1 15:47:36 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "dcmotor_test.h"
#include "dcmotor_test_private.h"
#include "rtwtypes.h"
#include "rt_nonfinite.h"

/* Block states (default storage) */
DW_dcmotor_test_T dcmotor_test_DW;

/* Real-time model */
static RT_MODEL_dcmotor_test_T dcmotor_test_M_;
RT_MODEL_dcmotor_test_T *const dcmotor_test_M = &dcmotor_test_M_;

/* Callback for Hardware Interrupt Block: '<Root>/External Interrupt' */
void MW_ISR_2(void)
{
  /* Call the system: <Root>/Function-Call Subsystem */
  {
    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

    /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */

    /* Logic: '<S2>/NOT' incorporates:
     *  Delay: '<S2>/Delay'
     */
    dcmotor_test_DW.Delay_DSTATE = !dcmotor_test_DW.Delay_DSTATE;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */
  }
}

/* Model step function */
void dcmotor_test_step(void)
{
  uint16_T b_varargout_1;

  /* MATLABSystem: '<Root>/Analog Input' */
  if (dcmotor_test_DW.obj.SampleTime != dcmotor_test_P.AnalogInput_SampleTime) {
    dcmotor_test_DW.obj.SampleTime = dcmotor_test_P.AnalogInput_SampleTime;
  }

  dcmotor_test_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(54UL);
  MW_AnalogInSingle_ReadResult
    (dcmotor_test_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     MW_ANALOGIN_UINT16);

  /* MATLABSystem: '<Root>/PWM' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  Gain: '<Root>/Gain'
   *  MATLABSystem: '<Root>/Analog Input'
   * */
  dcmotor_test_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
  MW_PWM_SetDutyCycle(dcmotor_test_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, (real_T)
                      (uint8_T)(((uint32_T)dcmotor_test_P.Gain_Gain *
    b_varargout_1) >> 17));

  /* MATLABSystem: '<Root>/Digital Output' */
  writeDigitalPin(13, (uint8_T)dcmotor_test_DW.Delay_DSTATE);
}

/* Model initialize function */
void dcmotor_test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */

  /* SystemInitialize for Outport: '<S2>/Out1' incorporates:
   *  Delay: '<S2>/Delay'
   *  Logic: '<S2>/NOT'
   */
  dcmotor_test_DW.Delay_DSTATE = dcmotor_test_P.Out1_Y0;

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(2), &MW_ISR_2, FALLING);

  /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  dcmotor_test_DW.obj.matlabCodegenIsDeleted = false;
  dcmotor_test_DW.obj.SampleTime = dcmotor_test_P.AnalogInput_SampleTime;
  dcmotor_test_DW.obj.isInitialized = 1L;
  dcmotor_test_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(54UL);
  dcmotor_test_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM' */
  dcmotor_test_DW.obj_b.matlabCodegenIsDeleted = false;
  dcmotor_test_DW.obj_b.isInitialized = 1L;
  dcmotor_test_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
  dcmotor_test_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  dcmotor_test_DW.obj_m.matlabCodegenIsDeleted = false;
  dcmotor_test_DW.obj_m.isInitialized = 1L;
  digitalIOSetup(13, 1);
  dcmotor_test_DW.obj_m.isSetupComplete = true;
}

/* Model terminate function */
void dcmotor_test_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!dcmotor_test_DW.obj.matlabCodegenIsDeleted) {
    dcmotor_test_DW.obj.matlabCodegenIsDeleted = true;
    if ((dcmotor_test_DW.obj.isInitialized == 1L) &&
        dcmotor_test_DW.obj.isSetupComplete) {
      dcmotor_test_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(54UL);
      MW_AnalogIn_Close(dcmotor_test_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!dcmotor_test_DW.obj_b.matlabCodegenIsDeleted) {
    dcmotor_test_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((dcmotor_test_DW.obj_b.isInitialized == 1L) &&
        dcmotor_test_DW.obj_b.isSetupComplete) {
      dcmotor_test_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(dcmotor_test_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      dcmotor_test_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(dcmotor_test_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!dcmotor_test_DW.obj_m.matlabCodegenIsDeleted) {
    dcmotor_test_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
