/*
 * APPSCHEDULING.c
 *
 *  Created on: 2024. 2. 20.
 *      Author: JINKYU
 */
#include "APPSCHEDULING.h"
#include "DRIVER_STM.h"
#include "Blink_LED2.h"
#include "MIDADC.h"
#include "GTM_PWM.h"
#include "Encoder.h"
#include <math.h>


static void AppTask1ms(void);
static void AppTask10ms(void);
static void AppTask1s(void);

float error_cnt = 0;
float error_rate = 0;

uint32 t = 0;
uint32 pulseCount = 0;
uint32 rpm = 0;

float w =0;
float w_ref=0;
float w_old=0;
float theta=0;
float theta_old=0;
float Ts = 0.001;
float W_RPM=0;
float Vin=0;

float error_w=0;
float error_w_int=0;
float error_w_int_old=0;

float kp=0.5;
float ki=0.3;

uint32 Wd=1;

boolean prevEncoderA = 0;
boolean prevEncoderB = 0;

float prev_location=0;

static float LPF(float w_old,float w,float Ts,float cf){
    float filtered_value = (1 - Ts * cf) * w_old + Ts * cf * w;
    return filtered_value;
}

static float getCurrentspeed(void)
{
    float location = (pulseCount)*((2*3.14)/48);
    float speed =(location-prev_location)/Ts;
    prev_location=location;
    return speed;
}

void PI_Ctrl(){
    error_w=w_ref-w;
    error_w_int=error_w_int_old+(error_w)*Ts;
    error_w_int_old=error_w_int;

    if(error_w_int>10){
        error_w_int=10;
    }

    Vin = (kp*error_w+ki*error_w_int);
}

static void Duty_Setting(){

    if(t<=4){
        Vin=0;
    }
    else if (t>4&&t<41){
        PI_Ctrl();
        if(Vin>11){
            Vin=11;
        }
        else if (Vin<0){
            Vin=0;
        }
    }
    else if (t>41){
        Vin=0;
    }
    g_GtmTomPwmHl.tOn[0]=Vin/12.0;
}

static void Wref_Setting(){
    if(t<=4){
            w_ref=0;
        }
        else if(t>4 && t<19){
            w_ref = 0.06667*Wd*(2*3.14)*(t-4);
        }
        else if(t>19 && t<26){
            w_ref=Wd*(3.14*2);
            error_cnt += error_w;
        }
        else if(t>26&&t<41){
            w_ref=Wd*(3.14*2)-0.06667*Wd*(2*3.14)*(t-26);
        }
        else if(t == 41) error_rate = sqrt(pow(error_cnt,2));
        else if(t>41){
            w_ref=0;
        }
}

static void AppTask1ms(void)
{
    DrvAdc_GetAdcRawGroup0();

    w = getCurrentspeed();
    w = LPF(w_old,w,Ts,60);
    w_old = w;

    Wref_Setting();
    Duty_Setting();
}
static void AppTask10ms(void)
{
    GtmTomPwmHl_run();
}

static void AppTask1s(void)
{
    t++;
}

void Tick_Count(void)
{
    boolean EncoderA = getEncoderAValue();
   boolean EncoderB = getEncoderBValue();

   if(EncoderA==TRUE && EncoderB==FALSE){
       if(prevEncoderA == FALSE && prevEncoderB == FALSE)
       {
           pulseCount++;
       }
       else if(prevEncoderA == TRUE&& prevEncoderB == TRUE)
       {
           pulseCount--;
       }
   }

   else if(EncoderA==TRUE && EncoderB==TRUE){
       if(prevEncoderA == TRUE && prevEncoderB == FALSE)
       {
           pulseCount++;
       }
       else if(prevEncoderA == FALSE && prevEncoderB == TRUE)
       {
           pulseCount--;
       }
   }
   else if(EncoderA==FALSE && EncoderB==TRUE){
       if(prevEncoderA == TRUE && prevEncoderB == TRUE)
       {
           pulseCount++;
       }
       else if(prevEncoderA == FALSE && prevEncoderB == FALSE)
       {
           pulseCount--;
       }
   }
   else if(EncoderA==FALSE && EncoderB==FALSE){
       if(prevEncoderA == FALSE && prevEncoderB == TRUE)
       {
           pulseCount++;
       }
       else if(prevEncoderA == TRUE && prevEncoderB == FALSE)
       {
           pulseCount--;
       }
   }

   prevEncoderA = EncoderA;
   prevEncoderB = EncoderB;
}

void AppScheduling(void)
{
    Tick_Count();

    if(stSchedulingInfo.u8nuSchduling1msFlag == 1u)
    {
        stSchedulingInfo.u8nuSchduling1msFlag = 0u;
        AppTask1ms();
    }
    if(stSchedulingInfo.u8nuSchduling10msFlag == 1u)
    {
        stSchedulingInfo.u8nuSchduling10msFlag = 0u;
        AppTask10ms();
    }
    if(stSchedulingInfo.u8nuSchduling1sFlag == 1u)
    {
        stSchedulingInfo.u8nuSchduling1sFlag = 0u;
        AppTask1s();
    }
}
