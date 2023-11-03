#include "LecturaSensoresGLO.h"
#include "rtwtypes.h"
#include <ext_work.h>
#include <ext_svr.h>
#include <ext_share.h>
#include <updown.h>

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  LecturaSensoresGLO_step();

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  cli();

#endif;

  OverrunFlag--;
  rtExtModeCheckEndTrigger();
}

volatile boolean_T stopRequested = false;
int main(void)
{
  volatile boolean_T runModel = true;
  float modelBaseRate = 0.05;
  float systemClock = 0;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(LecturaSensoresGLO_M, 0);

  /* initialize external mode */
  rtParseArgsForExtMode(0, NULL);
  LecturaSensoresGLO_initialize();
  sei();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(LecturaSensoresGLO_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(LecturaSensoresGLO_M->extModeInfo, 1, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(LecturaSensoresGLO_M, true);
    }
  }

  rtERTExtModeStartMsg();
  cli();
  configureArduinoAVRTimer();
  runModel =
    (rtmGetErrorStatus(LecturaSensoresGLO_M) == (NULL)) && !rtmGetStopRequested
    (LecturaSensoresGLO_M);

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  sei();
  while (runModel) {
    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(LecturaSensoresGLO_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(LecturaSensoresGLO_M, true);
      }
    }

    stopRequested = !(
                      (rtmGetErrorStatus(LecturaSensoresGLO_M) == (NULL)) &&
                      !rtmGetStopRequested(LecturaSensoresGLO_M));
    runModel = !(stopRequested);
    runModel = runModel && MW_Arduino_Loop();
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  LecturaSensoresGLO_terminate();
  rtExtModeShutdown(1);
  cli();
  return 0;
}
