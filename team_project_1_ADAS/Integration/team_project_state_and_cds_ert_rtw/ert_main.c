/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'team_project_state_and_cds'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Feb 12 20:23:15 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "team_project_state_and_cds.h"
#include "rtwtypes.h"
#include "xcp.h"
#include "ext_mode.h"
#include "MW_target_hardware_resources.h"

volatile int IsrOverrun = 0;
boolean_T isRateRunning[4] = { 0, 0, 0, 0 };

boolean_T need2runFlags[4] = { 0, 0, 0, 0 };

void rt_OneStep(void)
{
  extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;
  boolean_T eventFlags[4];
  int_T i;

  /* Check base rate for overrun */
  if (isRateRunning[0]++) {
    IsrOverrun = 1;
    isRateRunning[0]--;                /* allow future iterations to succeed*/
    return;
  }

  /*
   * For a bare-board target (i.e., no operating system), the rates
   * that execute this base step are buffered locally to allow for
   * overlapping preemption.
   */
  team_project_state_and_cds_SetEventsForThisBaseStep(eventFlags);

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  team_project_state_and_cds_step0();

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  cli();

#endif;

  isRateRunning[0]--;
  for (i = 1; i < 4; i++) {
    if (eventFlags[i]) {
      if (need2runFlags[i]++) {
        IsrOverrun = 1;
        need2runFlags[i]--;            /* allow future iterations to succeed*/
        break;
      }
    }
  }

  for (i = 2; i < 4; i++) {
    if (isRateRunning[i]) {
      /* Yield to higher priority*/
      return;
    }

    if (need2runFlags[i]) {
      isRateRunning[i]++;

#ifndef _MW_ARDUINO_LOOP_

      sei();

#endif;

      /* Step the model for subrate "i" */
      switch (i)
      {
       case 2 :
        currentTime = (extmodeSimulationTime_T)
          ((team_project_state_and_cds_M->Timing.clockTick2 * 10) + 0)
          ;
        team_project_state_and_cds_step2();

        /* Get model outputs here */

        /* Trigger External Mode event */
        extmodeEvent(2, currentTime);
        break;

       case 3 :
        currentTime = (extmodeSimulationTime_T)
          ((team_project_state_and_cds_M->Timing.clockTick3 * 20) + 0)
          ;
        team_project_state_and_cds_step3();

        /* Get model outputs here */

        /* Trigger External Mode event */
        extmodeEvent(3, currentTime);
        break;

       default :
        break;
      }

#ifndef _MW_ARDUINO_LOOP_

      cli();

#endif;

      need2runFlags[i]--;
      isRateRunning[i]--;
    }
  }
}

extern void rtIOStreamResync();
volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.01;
  float systemClock = 0;
  extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(team_project_state_and_cds_M, 0);

  /* Set Final Simulation Time in Ticks */
  errorCode = extmodeSetFinalSimulationTime((extmodeSimulationTime_T) -1);

  /* Parse External Mode command line arguments */
  errorCode = extmodeParseArgs(0, NULL);
  if (errorCode != EXTMODE_SUCCESS) {
    return (errorCode);
  }

  team_project_state_and_cds_initialize();
  cli();
  sei();

  /* External Mode initialization */
  errorCode = extmodeInit(team_project_state_and_cds_M->extModeInfo,
    &rtmGetTFinal(team_project_state_and_cds_M));
  if (errorCode != EXTMODE_SUCCESS) {
    /* Code to handle External Mode initialization errors
       may be added here */
  }

  if (errorCode == EXTMODE_SUCCESS) {
    /* Wait until a Start or Stop Request has been received from the Host */
    extmodeWaitForHostRequest(EXTMODE_WAIT_FOREVER);
    if (extmodeStopRequested()) {
      rtmSetStopRequested(team_project_state_and_cds_M, true);
    }
  }

  cli();
  configureArduinoAVRTimer();
  runModel = !extmodeSimulationComplete() && !extmodeStopRequested() &&
    !rtmGetStopRequested(team_project_state_and_cds_M);

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  XcpStatus lastXcpState = xcpStatusGet();
  sei();
  while (runModel) {
    /* Run External Mode background activities */
    errorCode = extmodeBackgroundRun();
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode background task errors
         may be added here */
    }

    stopRequested = !(!extmodeSimulationComplete() && !extmodeStopRequested() &&
                      !rtmGetStopRequested(team_project_state_and_cds_M));
    runModel = !(stopRequested);
    if (stopRequested)
      disable_rt_OneStep();
    if (lastXcpState==XCP_CONNECTED && xcpStatusGet()==XCP_DISCONNECTED)
      rtIOStreamResync();
    lastXcpState = xcpStatusGet();
    MW_Arduino_Loop();
  }

  /* Terminate model */
  team_project_state_and_cds_terminate();

  /* External Mode reset */
  extmodeReset();
  cli();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
