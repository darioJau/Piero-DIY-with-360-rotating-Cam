
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE

#include<Arduino.h>
#include<math.h>
#include<twi.h>
#include<twi.c>
#include<Wire.h>
#include<Wire.cpp>
#include<VL53L1X.h>
#include<VL53L1X.cpp>
#include<VL53L0X.h>
#include<VL53L0X.cpp>

VL53L0X sensorL0[3];
VL53L1X sensorL1[2];
unsigned char pin_sensor[5]={37,41,35,29,33};
int nueva_direccion[5]={30,31,32,33,34};
int caso[5]={0,0,1,1,2};

#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 5

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
extern "C" void Sensores5_VL53L0X_VL53L1X_I2C_Outputs_wrapper(real_T *Sensor,
			real_T *Status,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]==1)
{
    #ifndef MATLAB_MEX_FILE

    Sensor[0] = sensorL0[0].readRangeContinuousMillimeters();
    Sensor[1] = sensorL1[0].read();
    Sensor[2] = sensorL0[1].readRangeContinuousMillimeters();
    Sensor[3] = sensorL1[1].read();
    Sensor[4] = sensorL0[2].readRangeContinuousMillimeters();
    
  
    /*
    for(unsigned char i=0;i<5;i++)
    {
        if(i%2==0)
        {   
            Sensor[i]=sensorL0[i].readRangeContinuousMillimeters();
        }
  
        else
        {
            Sensor[i] = sensorL1[i].read();
        }
    }
    */
    #endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
extern "C" void Sensores5_VL53L0X_VL53L1X_I2C_Update_wrapper(real_T *Sensor,
			real_T *Status,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]!=1)
{
    #ifndef MATLAB_MEX_FILE
    
    for(int i=0;i<5;i++)    Status[i]=0;
    
    for(int i=29;i<=41;i++)    pinMode(i,OUTPUT);
    for(int i=29;i<=41;i++)   digitalWrite(i,LOW);
    
    Wire.begin();
    
    for(int i=0;i<5;i++)
    {
        digitalWrite(pin_sensor[i],HIGH);
        delay(10);
        if(i%2==0)                                 
    {
      Wire.beginTransmission(0x29);                  
      sensorL0[caso[i]].setAddress(nueva_direccion[i]);   
      if(!sensorL0[caso[i]].init())                       
      {
        Status[i]=1;
      }
      sensorL0[caso[i]].setTimeout(500);                 
      sensorL0[caso[i]].startContinuous();               
      Wire.endTransmission();                    
    }
    
    else                                       
    {
      sensorL1[caso[i]].setTimeout(500);                
      if(!sensorL1[caso[i]].init())                       
      {
        Status[i]=1;
      }
      sensorL1[caso[i]].setAddress(nueva_direccion[i]);     
      sensorL1[caso[i]].setDistanceMode(VL53L1X::Long);
      sensorL1[caso[i]].setMeasurementTimingBudget(50000);
      sensorL1[caso[i]].startContinuous(50);
    }
    }
   
  
    #endif
    
    xD[0]=1;  
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

