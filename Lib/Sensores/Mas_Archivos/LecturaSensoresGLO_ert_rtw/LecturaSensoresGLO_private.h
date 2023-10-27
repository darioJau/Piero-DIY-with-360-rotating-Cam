

    /*
  * LecturaSensoresGLO_private.h
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


  #ifndef RTW_HEADER_LecturaSensoresGLO_private_h_
  #define RTW_HEADER_LecturaSensoresGLO_private_h_
  

    

      #include "rtwtypes.h"
  #include "multiword_types.h"

  
  


  

  

  

        /* Private macros used by the generated code to access rtModel */
          

    #ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val) ((rtm)->Timing.tFinal = (val))
#endif


  




  

  

  

  

  

  

  

  
    

    extern void Sensores5_VL53L0X_VL53L1X_I2C_Start_wrapper(real_T *xD);

    extern void Sensores5_VL53L0X_VL53L1X_I2C_Outputs_wrapper(real_T *Sensor,
			real_T *Status,
			const real_T *xD);
    extern void Sensores5_VL53L0X_VL53L1X_I2C_Update_wrapper(real_T *Sensor,
			real_T *Status,
			real_T *xD);

    extern void Sensores5_VL53L0X_VL53L1X_I2C_Terminate_wrapper(real_T *xD);

  

  

  

  

  

  

  

  

  

    #endif /* RTW_HEADER_LecturaSensoresGLO_private_h_ */
