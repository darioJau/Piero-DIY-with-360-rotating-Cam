/*
 * LecturaSensoresGLO.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "LecturaSensoresGLO".
 *
 * Model version              : 1.6
 * Simulink Coder version : 9.1 (R2019a) 23-Nov-2018
 * C source code generated on : Thu May 16 18:55:23 2019
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "LecturaSensoresGLO.h"
#include "LecturaSensoresGLO_private.h"
#include "LecturaSensoresGLO_dt.h"

/* Block signals (default storage) */
B_LecturaSensoresGLO_T LecturaSensoresGLO_B;

/* Block states (default storage) */
DW_LecturaSensoresGLO_T LecturaSensoresGLO_DW;

/* Real-time model */
RT_MODEL_LecturaSensoresGLO_T LecturaSensoresGLO_M_;
RT_MODEL_LecturaSensoresGLO_T *const LecturaSensoresGLO_M =
  &LecturaSensoresGLO_M_;

/* Model step function */
void LecturaSensoresGLO_step(void)
{
  /* S-Function (Sensores5_VL53L0X_VL53L1X_I2C): '<Root>/S-Function Builder' */
  Sensores5_VL53L0X_VL53L1X_I2C_Outputs_wrapper
    (&LecturaSensoresGLO_B.SFunctionBuilder_o1[0],
     &LecturaSensoresGLO_B.SFunctionBuilder_o2[0],
     &LecturaSensoresGLO_DW.SFunctionBuilder_DSTATE);

  /* Update for S-Function (Sensores5_VL53L0X_VL53L1X_I2C): '<Root>/S-Function Builder' */

  /* S-Function "Sensores5_VL53L0X_VL53L1X_I2C_wrapper" Block: <Root>/S-Function Builder */
  Sensores5_VL53L0X_VL53L1X_I2C_Update_wrapper
    (&LecturaSensoresGLO_B.SFunctionBuilder_o1[0],
     &LecturaSensoresGLO_B.SFunctionBuilder_o2[0],
     &LecturaSensoresGLO_DW.SFunctionBuilder_DSTATE);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.05s, 0.0s] */
    rtExtModeUpload(0, (real_T)LecturaSensoresGLO_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.05s, 0.0s] */
    if ((rtmGetTFinal(LecturaSensoresGLO_M)!=-1) &&
        !((rtmGetTFinal(LecturaSensoresGLO_M)-
           LecturaSensoresGLO_M->Timing.taskTime0) >
          LecturaSensoresGLO_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(LecturaSensoresGLO_M, "Simulation finished");
    }

    if (rtmGetStopRequested(LecturaSensoresGLO_M)) {
      rtmSetErrorStatus(LecturaSensoresGLO_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++LecturaSensoresGLO_M->Timing.clockTick0)) {
    ++LecturaSensoresGLO_M->Timing.clockTickH0;
  }

  LecturaSensoresGLO_M->Timing.taskTime0 =
    LecturaSensoresGLO_M->Timing.clockTick0 *
    LecturaSensoresGLO_M->Timing.stepSize0 +
    LecturaSensoresGLO_M->Timing.clockTickH0 *
    LecturaSensoresGLO_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void LecturaSensoresGLO_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)LecturaSensoresGLO_M, 0,
                sizeof(RT_MODEL_LecturaSensoresGLO_T));
  rtmSetTFinal(LecturaSensoresGLO_M, -1);
  LecturaSensoresGLO_M->Timing.stepSize0 = 0.05;

  /* External mode info */
  LecturaSensoresGLO_M->Sizes.checksums[0] = (3402880550U);
  LecturaSensoresGLO_M->Sizes.checksums[1] = (1605654016U);
  LecturaSensoresGLO_M->Sizes.checksums[2] = (3882840303U);
  LecturaSensoresGLO_M->Sizes.checksums[3] = (2195130727U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    LecturaSensoresGLO_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(LecturaSensoresGLO_M->extModeInfo,
      &LecturaSensoresGLO_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(LecturaSensoresGLO_M->extModeInfo,
                        LecturaSensoresGLO_M->Sizes.checksums);
    rteiSetTPtr(LecturaSensoresGLO_M->extModeInfo, rtmGetTPtr
                (LecturaSensoresGLO_M));
  }

  /* block I/O */
  (void) memset(((void *) &LecturaSensoresGLO_B), 0,
                sizeof(B_LecturaSensoresGLO_T));

  /* states (dwork) */
  (void) memset((void *)&LecturaSensoresGLO_DW, 0,
                sizeof(DW_LecturaSensoresGLO_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    LecturaSensoresGLO_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;
  }

  /* InitializeConditions for S-Function (Sensores5_VL53L0X_VL53L1X_I2C): '<Root>/S-Function Builder' */

  /* S-Function Block: <Root>/S-Function Builder */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        LecturaSensoresGLO_DW.SFunctionBuilder_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void LecturaSensoresGLO_terminate(void)
{
  /* (no terminate code required) */
}
